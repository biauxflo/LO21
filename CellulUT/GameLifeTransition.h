#ifndef CELLULUT_GAMELIFE_TRANSITION_H
#define CELLULUT_GAMELIFE_TRANSITION_H
#include <iostream>
#include "Transition.h"

class GameLifeTransition : public Transition {

public:
    ETAT_NP::Etat& creerTransition(ETAT_NP::Etat** etats, ETAT_NP::Etat& etat, const CELLULE_NP::Cellule* voisines, unsigned int nbVoisines) override;
    GameLifeTransition() = default;
};

#endif
