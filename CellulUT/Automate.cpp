#include "Cellule.h"
#include "Etat.h"
#include <string>
#include "Automate.h"

AUTOMATE_NP::Automate* AUTOMATE_NP::Automate::automate_Instance = nullptr;

void AUTOMATE_NP::Automate::setEtats(size_t n, std::vector<ETAT_NP::Etat*> e){
    while(!etats.empty()){
        etats.pop_back();
    }
    for(unsigned int i = 0; i < n; i++){
        etats.push_back(e[i]);
    }
    setNbEtats(n);
}

AUTOMATE_NP::Automate& AUTOMATE_NP::Automate::getAutomate() {
    if (automate_Instance == nullptr) {
        throw AUTOMATE_EXCEPTION_NP::AutomateException("Tentative d'appeler un automate non instancié sans paramètres");
    }
    return *automate_Instance;
}

void AUTOMATE_NP::Automate::setAutomate(RESEAU_NP::Reseau* r, unsigned int n, Voisinage* v, Transition* t) {
    if (automate_Instance != nullptr) delete automate_Instance;
    automate_Instance = new Automate(r,n,v,t);
}

void AUTOMATE_NP::Automate::libererAutomate() {
    delete automate_Instance;
    automate_Instance = nullptr;
}

AUTOMATE_NP::Automate::~Automate() {
    delete reseau;
    for(unsigned int i = 0; i < nbEtats; i++){
        delete etats[i];
    }
    delete voisinage;
    delete regleTransition;
    libererAutomate();
}

void AUTOMATE_NP::Automate::appliquerConfiguration(QXmlStreamReader *xmlReader){

    xmlReader->readNext();
    std::string automateName; // ou QString ???
    unsigned int nombre = 0;
    std::vector<ETAT_NP::Etat*> _etats;
    Voisinage* _voisinage;
    Transition* transition;

    if(xmlReader->readNextStartElement()){
        if(xmlReader->name() == "automate"){
            while(xmlReader->readNextStartElement()){

                QString elementName = xmlReader->name().toString();
                if(elementName == "name"){
                    QString name = xmlReader->readElementText();
                    automateName = name.toStdString();
                } else if(elementName == "etats"){
                    xmlReader->readNextStartElement();
                    if(xmlReader->name() != "nombre")
                        throw AUTOMATE_EXCEPTION_NP::AutomateException("Modèle XML incorrect");
                    nombre = std::stoi(xmlReader->readElementText().toStdString());
                    while(xmlReader->readNextStartElement()){
                        //xmlReader->readNextStartElement();
                        QString test = xmlReader->name().toString(); // TEST
                        std::string label;
                        QColor couleur;
                        unsigned int indice;
                        if(xmlReader->name().toString() != "etat")
                            throw AUTOMATE_EXCEPTION_NP::AutomateException("Modèle XML incorrect");
                        while(xmlReader->readNextStartElement()){
                            if (xmlReader->name().toString() == "etat") xmlReader->readNextStartElement();
                            QString test2 = xmlReader->name().toString(); // TEST
                            if (xmlReader->name().toString() == "label"){
                                label = xmlReader->readElementText().toStdString();
                            } else if(xmlReader->name().toString() == "color"){
                                couleur = QColor(xmlReader->readElementText());
                            } else if(xmlReader->name().toString() == "indice") {
                                indice = std::stoi(xmlReader->readElementText().toStdString());
                            }
                        }
                        ETAT_NP::Etat* _etat = new ETAT_NP::Etat(indice, label, couleur.rgb());
                        _etats.push_back(_etat);
                    }

                } else if(elementName == "voisinage"){
                    if(xmlReader->readElementText() == "neumann") _voisinage = new Neumann();
                    else if(xmlReader->readElementText() == "moore") _voisinage = new Moore();
                } else if(elementName == "regle"){
                    if(xmlReader->readElementText() == "gamelife") transition = new GameLifeTransition();
                    else if(xmlReader->readElementText() == "brianbrain") transition = new BrianBrainTransition();
                    else if(xmlReader->readElementText() == "griffeath") transition = new GriffeathTransition();
                }

                else{
                    xmlReader->skipCurrentElement();
                }
            }
        }
    }

    RESEAU_NP::Reseau* r = new RESEAU_NP::Reseau(10,10,0);

    if(_voisinage == nullptr)
        throw AUTOMATE_EXCEPTION_NP::AutomateException("Voisinage non initialisé");
    if(transition == nullptr)
        throw AUTOMATE_EXCEPTION_NP::AutomateException("Transition non initialisée");
    if(_etats.size() == 0)
        throw AUTOMATE_EXCEPTION_NP::AutomateException("Aucun état dans l'automate");

    //setAutomate(r, nombre, _voisinage, transition);
    automate_Instance->setReseau(r);
    automate_Instance->setNbEtats(nombre);
    automate_Instance->setVoisinage(_voisinage);
    automate_Instance->setTransition(transition);
    setEtats(nombre, _etats);
}


void AUTOMATE_NP::Automate::calculerTransition(){
    std::vector<std::vector<CELLULE_NP::Cellule*>> reseauCopie;
    for(unsigned int i = 0; i < reseau->getLargeur(); i++){
        std::vector<CELLULE_NP::Cellule*> v;
        for(unsigned int j = 0; j < reseau->getLongueur(); j++){
            CELLULE_NP::Cellule& tmp = reseau->getCellule(i,j);
            CELLULE_NP::Cellule* c = new CELLULE_NP::Cellule(tmp.getAbscisse(), tmp.getOrdonnee(), &(tmp.getEtat()));
            v.push_back(c);
        }
        reseauCopie.push_back(v);
    }

    for(unsigned int i = 0; i < reseau->getLargeur(); i++){
        for(unsigned int j = 0; j < reseau->getLongueur(); j++){
            CELLULE_NP::Cellule& c = *reseauCopie[i][j];
            ETAT_NP::Etat etmp = c.getEtat();
            std::vector<CELLULE_NP::Cellule*> voisines; //voisinage->getNbCellulesVoisines()
            voisines = voisinage->calculerVoisinage(voisines, reseauCopie, i, j, reseau->getLargeur(), reseau->getLongueur());
            ETAT_NP::Etat& e = regleTransition->creerTransition(getEtats(), etmp, voisines, voisines.size());
            reseau->getCellule(i,j).setEtat(e);

            for(unsigned int i = 0; i < voisines.size(); i++){
                delete voisines[i];
            }
        }
    }

    for(unsigned int i = 0; i < reseau->getLargeur() ; i++)
    {
        for(unsigned int j = 0; j < reseau->getLongueur(); j++){
            delete reseauCopie[i][j];
        }
    }

}

