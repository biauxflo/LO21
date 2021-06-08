//
// Created by Amelie Pelle on 07/06/2021.
//

#ifndef CELLULUT_BRIAN_TRANSITION_H
#define CELLULUT_BRIAN_TRANSITION_H
#include <iostream>
#include "Transition.h"

/**
* \class BrianBrainTransition
* \brief Herite de la classe Transition, gere les transitions pour l automate Brian s Brain
*/
class BrianBrainTransition : public  Transition { // A REFAIRE
public:
    /**
    * \brief surcharge de la fonction creerTransition pour le transition de Brian s Brain
     * \param etats tableau d'etats possibles pour l automate
     * \param etat : etat de la cellule sur laquelle on effectue la transition
     * \param voisines tableau contenant les cellules voisines
     * \param nbVoisines nombre de voisines de la cellule (taille du tableau voisines)
     * \return nouvel etat de la cellule
     */
    ETAT_NP::Etat& creerTransition(ETAT_NP::Etat** etats, ETAT_NP::Etat& etat, CELLULE_NP::Cellule* voisines, unsigned int nbVoisines) override;
    /**
    * \brief Constructeur de la classe BrianBrainTransition
     * sans parametre
     */
    BrianBrainTransition() = default;

};

#endif