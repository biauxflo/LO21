#include "simulateur.h"

time_t tmm = time(0);
char* dt = ctime(&tmm);
tm *g = gmtime(&tmm);

SIMULATEUR_NP::Simulateur(const AUTOMATE_NP::Automate &a){
     automate(&a);
     date(asctime(g));
}

SIMULATEUR_NP::Simulateur(const AUTOMATE_NP::Automate &a, std::string auteur, std::string titre, std::string desc){
    automate(&a);
    date(asctime(g));
    auteur(auteur);
    titre(titre);
    description(desc);
}

SIMULATEUR_NP::Simulateur(const AUTOMATE_NP::Automate &a, RESEAU_NP::Reseau &r){
    automate(&a);
    date(asctime(g));
    depart(&r);
}

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

/*void SIMULATEUR_NP::Simulateur::saveReseau(){
    if (!save){
        save=new RESEAU_NP::Reseau[this->getMemoire()];
    }
    rangSave++
    if (rangSave==memoire){
        rangSave=0;
    }
    save[rang]=automate.getReseau();
}
*/
void SIMULATEUR_NP::Simulateur::run() {
    if (modeAutomatique){

    }else{
        saveReseau();
        automate.calculerTransition();
    }
}

void stop(){
    
}
