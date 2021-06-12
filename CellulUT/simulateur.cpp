#include "simulateur.h"
#include <QtDebug>

time_t tmm = time(0);
char* dt = ctime(&tmm);
tm *g = gmtime(&tmm);

SIMULATEUR_NP::Simulateur(const AUTOMATE_NP::Automate &a, const RESEAU_NP::Reseau &start, std::string auteur, std::string titre, std::string desc){
    automate(&a);
    date(asctime(g));
    depart(&r);
    auteur(auteur);
    titre(titre);
    description(desc);
}

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
