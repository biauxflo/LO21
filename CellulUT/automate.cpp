#include "automate.h"
#include <string>

using namespace AUTOMATE;

/* A CONTINUER AVEC LES METHODES DES AUTRES CLASSES */
void appliquerConfiguration(QXmlStreamReader xmlReader){

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

void calculerTransition(){
    for(unsigned int i = 0; i < reseau.getHauteur(); i++){
        for(unsigned int j = 0; j < reseau.getLargeur(); j++){
            Cellule& c = reseau.getCellule(i,j);
            Etat& e = regleTransition.creerTransition(c.getVoisinage());
            c.setEtat(e);
        }
    }
}
