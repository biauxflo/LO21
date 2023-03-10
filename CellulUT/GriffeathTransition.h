//
// Created by Anne Pelle on 08/06/2021.
//

#ifndef NEUMANN_CPP_GRIFFEATHTRANSITION_H
#define NEUMANN_CPP_GRIFFEATHTRANSITION_H

#include <iostream>
#include "Transition.h"

/**
* \file GriffeathTransition.h
* \author Amelie Pelle
*/

/**
* \class GriffeathTransition
* \brief Herite de la classe Transition, gere les transitions pour l automate de Griffeath
*/
class GriffeathTransition : public Transition {

public:
    /**
    * \brief surcharge de la fonction creerTransition pour le transition de Griffeath
     * \param etats vecteur d'etats possibles pour l automate
     * \param etat : etat de la cellule sur laquelle on effectue la transition
     * \param voisines vecteur contenant les cellules voisines
     * \param nbVoisines nombre de voisines de la cellule (taille du tableau voisines)
     * \return nouvel etat de la cellule
     */
    ETAT_NP::Etat& creerTransition(std::vector<ETAT_NP::Etat*> etats, ETAT_NP::Etat& etat, std::vector<CELLULE_NP::Cellule*> voisines, unsigned int nbVoisines) override;
    /**
    * \brief Constructeur de la classe GriffeathTransition
     * sans parametre
     */
    GriffeathTransition() = default;
};


#endif //NEUMANN_CPP_GRIFFEATHTRANSITION_H
