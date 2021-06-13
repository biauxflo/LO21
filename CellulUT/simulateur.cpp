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
    //saveReseau();
    automate.calculerTransition();
}
/*
void SIMULATEUR_NP::Simulateur::back(){
    if (indexMem>0){
        indexMem=indexMem-1;
    }else if (indexMem==0){
        indexMem=memoire-1;
    }
    automate.setReseau(&save[indexMem]);
}*/

void SIMULATEUR_NP::Simulateur::setMemoire(size_t mem){
    memoire=mem;
}

size_t SIMULATEUR_NP::Simulateur::getMemoire(){
    return memoire;
}
/*
void SIMULATEUR_NP::Simulateur::saveReseau(){
    if (!save){
        save = new RESEAU_NP::Reseau[getMemoire()];
        indexMem=0;
        save[indexMem]= *automate.getReseau();
    }else{
    indexMem++;
        if (indexMem==memoire-1){
            indexMem=0;
        }
    save[indexMem]= *automate.getReseau();
    }
}*/

AUTOMATE_NP::Automate *SIMULATEUR_NP::Simulateur::getAutomate()
{
    return &AUTOMATE_NP::Automate::getAutomate();
}

void SIMULATEUR_NP::Simulateur::creerSimulation(){
    memoire = 3;
}
