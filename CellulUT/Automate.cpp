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
    libererAutomate();
}
/*
void AUTOMATE_NP::Automate::appliquerConfiguration(QXmlStreamReader xmlReader){

    xmlReader.readNext();
    std::string automateName; // ou QString ???

    if(xmlReader.readNextStartElement()){
        if(xmlReader.name() == "automate"){
            while(xmlReader.readNextStartElement()){
                if(xmlReader.name() == "name"){
                    QString name = xmlReader.readElementText();
                    automateName = name.toStdString();
                } else if(xmlReader.name() == "etats"){
                    xmlReader.readNextStartElement();
                    // creer classe exception

                } else if(xmlReader.name() == "voisinage"){

                } else if(xmlReader.name() == "regles"){

                }

                else{
                    xmlReader.skipCurrentElement();
                }
            }
        }
    }
}
*/

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
            std::vector<CELLULE_NP::Cellule*> voisines(voisinage->getNbCellulesVoisines());
            voisines = voisinage->calculerVoisinage(voisines, reseauCopie, i, j, reseau->getLargeur(), reseau->getLongueur());
            ETAT_NP::Etat& e = regleTransition->creerTransition(getEtats(), etmp, voisines, voisinage->getNbCellulesVoisines());
            //delete voisines;
            reseau->getCellule(i,j).setEtat(e);
        }
    }

    for(unsigned int i = 0; i < reseau->getLargeur() ; i++)
    {
        for(unsigned int j = 0; j < reseau->getLongueur(); j++){
            delete reseauCopie[i][j];
        }
    }

}

