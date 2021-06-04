#include "Cellule.h"
#include "Etat.h"
#include <string>
#include "Automate.h"

void AUTOMATE_NP::Automate::setEtats(size_t n, ETAT_NP::Etat** e){
    setNbEtats(n);
    for(unsigned int i = 0; i < MAX_ETATS; i++){
        if(i > n) etats[i] = nullptr;
        else etats[i] = e[i];
    }

}
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

void AUTOMATE_NP::Automate::calculerTransition(){
    CELLULE_NP::Cellule** reseauCopie;
    for(unsigned int i = 0; i < reseau->getLargeur(); i++){ // à revoir ?
        for(unsigned int j = 0; j < reseau->getLongueur(); j++){
            reseauCopie[i][j] = reseau->getCellule(i,j);
        }
    }

    for(unsigned int i = 0; i < reseau->getLargeur(); i++){
        for(unsigned int j = 0; j < reseau->getLongueur(); j++){
            CELLULE_NP::Cellule& c = reseauCopie[i][j];
            CELLULE_NP::Cellule* voisines = new CELLULE_NP::Cellule[voisinage->getNbCellulesVoisines()];
            ETAT_NP::Etat& e = regleTransition->creerTransition(getEtats(), c.getEtat(), voisinage->calculerVoisinage(voisines, reseauCopie, i, j, reseau->getLargeur(), reseau->getLongueur()), voisinage->getNbCellulesVoisines());
            delete[] voisines;
            reseau->getCellule(i,j).setEtat(e);
        }
    }

    for(unsigned int i = 0; i < reseau->getLargeur(); i++){
        delete[] reseauCopie[i];
    }
    delete[] reseauCopie;

}
