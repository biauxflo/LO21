#ifndef CELLULUT_GAMELIFE_TRANSITION_H
#define CELLULUT_GAMELIFE_TRANSITION_H
#include <iostream>
#include "Transition.h"

class TransitionGameLife : public Transition {

public:
    ETAT_NP::Etat& creerTransition(ETAT_NP::Etat* etats, ETAT_NP::Etat& etat, CELLULE_NP::Cellule* voisines, unsigned int nbVoisines) override;

};

#endif
