//
// Created by Anne Pelle on 29/05/2021.
//

#ifndef CELLULUT_VOISINAGE_H
#define CELLULUT_VOISINAGE_H

#include <iostream>
#include <cmath>
#include "Cellule.h"

/**
* \class Voisinage
* \brief Classe mere abstraite
*/

class Automate;

class Voisinage{
private :
    /**
    * \brief Constructeur de recopie de la classe Voisinage
    * \param v Voisinage à recopier
    */
    Voisinage(const Voisinage& v)= delete;

    /**
    * \brief Surcharge de l'opérateur d'affectation
     * \param v Voisinage à affecter
     * \return Voisinage
     */
    Voisinage& operator=(const Voisinage& v)= delete;
public:
    /**
    * \brief Constructeur (par defaut) de la classe Voisinage
     */
    Voisinage() = default;

    /**
    * \brief Destructeur (par defaut) de la classe Voisinage
     */
    virtual ~Voisinage() = default;
    /**
    * \brief Methode virtual qui calcule le voisinage d'une cellue (surchargee dans les classes filles)
     */
    virtual const CELLULE_NP::Cellule * calculerVoisinage(CELLULE_NP::Cellule tab[], CELLULE_NP::Cellule** reseau, unsigned int x, unsigned int y, unsigned int largeur, unsigned int longueur) const = 0;
    virtual const unsigned int getNbCellulesVoisines() const = 0;
};


#endif //CELLULUT_VOISINAGE_H
