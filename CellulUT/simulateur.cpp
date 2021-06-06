#include "simulateur.h"

    const Automate& automate=nullptr;
    Etat** etats;
    const Etat* depart;
    size_t nbMaxEtats;
    size_t rang;
    boolean modeAutomatique=false;
    size_t pasDeTemps=0;
    string titre;
    string description;
    size_t annee;
    string auteur;

    Simulateur(const Automate& a,size_t buffer=2){
        automate(a);
        nbMaxEtats(buffer);
        etats(nullptr);
        depart(nullptr);
        rang(0);
        etats=new Etat*[nbMaxEtats];
        for(size_t i =0; i<nbMaxEtats; i++) {
            etats[i] = nullptr;
        }
    }

    Simulateur(const Automate& a, const Etat& start, size_t buffer=2){
        automate(a);
        nbMaxEtats(buffer);
        etats(nullptr);
        depart(&start);
        rang(0);
        etats=new Etat*[nbMaxEtats];
        for(size_t i =0; i<nbMaxEtats; i++) {
            etats[i] = nullptr;
        }
        etats[0]=new Etat(depart);
    }

    void build(size_t c) {
        if (c>=nbMaxEtats) throw AutomateException("Erreur taille");
        if (etats[c] == nullptr) {
            etats[c] = new Etat();
        }
    }

    void setEtatDepart(const Etat& e){
        depart = &e;
        reset();
    }

    void reset() {
        if (depart==nullptr) throw AutomateException("Erreur état départ");
        build(0);
        *etats[0]=depart;
        rang=0;
    }

    void next(){
        if (depart==nullptr) throw AutomateException("Erreur état départ");
        Etat *e = new Etat();
        automate.appliquerTransition(*etats[rang%nbMaxEtats],*e);
        rang++;
        etats[rang%nbMaxEtats]= e;
    }

    void run(size_t nbSteps){
        for(size_t j=0; j<nbSteps; j++) {
            next();
        }
    }

    Simulateur::const Etat& last() const{
        return etats[rang%nbMaxEtats];
    }

    size_t getRangDernier() const { return rang; }

    ~Simulateur(){
        for (unsigned int i = 0; i < nbMaxEtats; i++) {
            delete etats[i];
        }
    delete[] etats;
    }

    void play(){
        if (modeAutomatique){
            if (pasDeTemps!=0){
                run(pasDeTemps);
            }else{
                while (modeAutomatique){
                    next();
                }
            }
        }else{
            next();
        }
    }
void setStepByStep(){
        modeAutomatique=false;
    }
void setAuto(){
        modeAutomatique=true;
    }

void setAuto(size_t temps){
        modeAutomatique=true;
        pasDeTemps=temps;
    }

void pause(){
        if (modeAutomatique){
            setStepByStep();
            setAuto();
        }
    }

void stop(){
    if (modeAutomatique){
        setStepByStep();
        setAuto();
        pasDeTemps=0;
    }
}

void chargerConfiguration(string save);
void parametrer();
