#include "simulateur.h"
#include "Automate.h"
#include "Reseau.h"
#include <QtDebug>

/*SIMULATEUR_NP::Simulateur(AUTOMATE_NP::Automate *a, RESEAU_NP::Reseau &start, std::string nom){
    automate(&a);
    depart(&r);
    nom(titre);
};*/

void SIMULATEUR_NP::Simulateur::setEtatDepart(RESEAU_NP::Reseau &r) {
    depart = &r;
    reset();
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
        indexMem-=1;
    }else if (indexMem==0){
        indexMem=memoire-1;
    }
    automate.setReseau(&save[indexMem]);
}

void SIMULATEUR_NP::Simulateur::setPasDeTemps(size_t t) {
    pasDeTemps = t;
}

void SIMULATEUR_NP::Simulateur::setMemoire(size_t mem){
    memoire=mem;
}

size_t SIMULATEUR_NP::Simulateur::getPasDeTemps(){
    return pasDeTemps;
}

size_t SIMULATEUR_NP::Simulateur::getMemoire(){
    return memoire;
}

void SIMULATEUR_NP::Simulateur::setAuto() {
    modeAutomatique=true;
}

void SIMULATEUR_NP::Simulateur::setStepByStep() {
    modeAutomatique=false;
}

void SIMULATEUR_NP::Simulateur::saveReseau(){
    if (!save){
        save=new RESEAU_NP::Reseau[getMemoire()];
    }
    indexMem++;
    if (indexMem==memoire){
        indexMem=0;
    }
    save[indexMem]=automate.getReseau();
}

void SIMULATEUR_NP::Simulateur::run() {
    if (modeAutomatique){
        boucleActive=true;
        while (boucleActive){
            if (pasDeTemps!=0){
                timer->start();
                automate.calculerTransition();
                //sleep(pasDeTemps);
            }else{
                timer->start();
                automate.calculerTransition();
            }
        }
    }else{
        next();
    }
}

void SIMULATEUR_NP::Simulateur::pause(){
    boucleActive=!boucleActive;
}

void SIMULATEUR_NP::Simulateur::stop(){
    timer->stop();
    boucleActive=false;
}

AUTOMATE_NP::Automate *SIMULATEUR_NP::Simulateur::getAutomate()
{
    return &automate;
}

void SIMULATEUR_NP::Simulateur::creerSimulation(){

}

SIMULATEUR_NP::Simulateur::~Simulateur(){

}
