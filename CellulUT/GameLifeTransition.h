#ifndef CELLULUT_GAMELIFE_TRANSITION_H
#define CELLULUT_GAMELIFE_TRANSITION_H
#include <iostream>
#include "Transition.h"

/**
* \file GameLifeTransition.h
* \author {Lucas Clusman, Amelie Pelle}
*/

/**
* \class GameLifeTransition
* \brief Herite de la classe Transition, gere les transitions pour l automate du jeu de la vie
*/
class GameLifeTransition : public Transition {

public:
    /**
    * \brief surcharge de la fonction creerTransition pour le transition du jeu de la vie
     * \param etats vecteur d'etats possibles pour l automate
     * \param etat : etat de la cellule sur laquelle on effectue la transition
     * \param voisines vecteur contenant les cellules voisines
     * \param nbVoisines nombre de voisines de la cellule (taille du vecteur voisines)
     * \return nouvel etat de la cellule
     */
    ETAT_NP::Etat& creerTransition(std::vector<ETAT_NP::Etat*> etats, ETAT_NP::Etat& etat, std::vector<CELLULE_NP::Cellule*> voisines, unsigned int nbVoisines) override;
    /**
    * \brief Constructeur de la classe GameLifeTransition
     * sans parametre
     */
    GameLifeTransition() = default;
};

#endif
