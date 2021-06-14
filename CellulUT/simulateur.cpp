#include "simulateur.h"
#include "Automate.h"
#include "Reseau.h"
#include <QtDebug>

/*SIMULATEUR_NP::Simulateur(AUTOMATE_NP::Automate *a, RESEAU_NP::Reseau &start, std::string nom){
    automate(&a);
    depart(&r);
    nom(titre);
};*/

void SIMULATEUR_NP::Simulateur::setEtatDepart(RESEAU_NP::Reseau* r) {
    depart = new RESEAU_NP::Reseau(r->getLargeur(), r->getLongueur(), r->getHorloge());
    for(unsigned int i = 0; i < r->getLargeur(); i++){
        for(unsigned j = 0; j < r->getLongueur(); j++){
            depart->getCellule(i,j).setEtat(r->getCellule(i,j).getEtat());
        }
    }
}

void SIMULATEUR_NP::Simulateur::reset() {
    automate.setReseau(depart);
}

void SIMULATEUR_NP::Simulateur::next(){
    saveReseau();
    automate.calculerTransition();
}

void SIMULATEUR_NP::Simulateur::back(){
    if (indexMem>0){
        indexMem=indexMem-1;
    }else if (indexMem==0){
        indexMem=memoire-1;
    }
    automate.setReseau(save[indexMem]);
}

void SIMULATEUR_NP::Simulateur::setMemoire(size_t mem){
    memoire=mem;
}

size_t SIMULATEUR_NP::Simulateur::getMemoire(){
    return memoire;
}

void SIMULATEUR_NP::Simulateur::saveReseau(){
    if (indexMem >= memoire) indexMem = 0;
    RESEAU_NP::Reseau* r = new RESEAU_NP::Reseau(automate.getReseau()->getLargeur(),automate.getReseau()->getLongueur(),automate.getReseau()->getHorloge());
    for (int i = 0; i < automate.getReseau()->getLargeur(); i++) {
        for (int j = 0; j < automate.getReseau()->getLongueur(); j++) {
            r->getCellule(i,j).setEtat(automate.getReseau()->getCellule(i,j).getEtat());
            r->getCellule(i,j).setAbscisse(automate.getReseau()->getCellule(i,j).getAbscisse());
            r->getCellule(i,j).setOrdonnee(automate.getReseau()->getCellule(i,j).getOrdonnee());
        }
    }
    save[indexMem] = r;
    indexMem++;
}

AUTOMATE_NP::Automate *SIMULATEUR_NP::Simulateur::getAutomate()
{
    return &AUTOMATE_NP::Automate::getAutomate();
}

