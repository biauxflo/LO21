#ifndef CELLULUT_TRANSITION_H
#define CELLULUT_TRANSITION_H
#include "Cellule.h"
#include "Etat.h"

class Transition{

public:
    virtual ETAT_NP::Etat& creerTransition(ETAT_NP::Etat** etats, ETAT_NP::Etat& etat, const CELLULE_NP::Cellule* voisines, const unsigned int nbVoisines) = 0;
    virtual ~Transition() = default;
};

#endif //CELLULUT_TRANSITION_H


