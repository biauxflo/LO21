//
// Created by Anne Pelle on 08/06/2021.
//

#ifndef NEUMANN_CPP_GRIFFEATHTRANSITION_H
#define NEUMANN_CPP_GRIFFEATHTRANSITION_H

#include <iostream>
#include "Transition.h"

class GriffeathTransition : public Transition {

public:
    ETAT_NP::Etat& creerTransition(ETAT_NP::Etat** etats, ETAT_NP::Etat& etat, const CELLULE_NP::Cellule* voisines, unsigned int nbVoisines) override;
    GriffeathTransition() = default;
};


#endif //NEUMANN_CPP_GRIFFEATHTRANSITION_H
