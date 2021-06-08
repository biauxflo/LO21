//
// Created by Amelie Pelle on 07/06/2021.
//

#ifndef CELLULUT_BRIAN_TRANSITION_H
#define CELLULUT_BRIAN_TRANSITION_H
#include <iostream>
#include "Transition.h"

class BrianBrainTransition : public  Transition { // A REFAIRE
public:
    ETAT_NP::Etat& creerTransition(ETAT_NP::Etat** etats, ETAT_NP::Etat& etat, const CELLULE_NP::Cellule* voisines, unsigned int nbVoisines) override;
    BrianBrainTransition() = default;
   // countNeighbours(int i, int j) {

//int resting = 0;
//int exciting = 0;
//int refractory = 0;

};

#endif