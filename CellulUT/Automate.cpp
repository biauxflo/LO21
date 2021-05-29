#include "Cellule.h"
#include "Etat.h"
#include <string>
#include "Automate.h"

/* A CONTINUER AVEC LES METHODES DES AUTRES CLASSES */
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
    CELLULE_NP::Cellule** reseauCopie;  // faire operateur de recopie
    //= reseau;
    for(int i = 0; i < reseau.getLongueur(); i++){
        for(int j = 0; j < reseau.getLargeur(); j++){
            CELLULE_NP::Cellule& c = reseauCopie[i][j];
            ETAT_NP::Etat& e = regleTransition.creerTransition(c.getVoisinage());
            c.setEtat(e);
        }
    }
}
