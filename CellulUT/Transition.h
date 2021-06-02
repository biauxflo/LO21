#ifndef CELLULUT_TRANSITION_H
#define CELLULUT_TRANSITION_H
#include "Cellule.h"
#include "Etat.h"

class Transition{

public:
    virtual ETAT_NP::Etat& creerTransition(ETAT_NP::Etat* etats, ETAT_NP::Etat& etat, CELLULE_NP::Cellule* voisines, unsigned int nbVoisines) {};
};

#endif //CELLULUT_TRANSITION_H


