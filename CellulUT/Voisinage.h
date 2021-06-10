//
// Created by Anne Pelle on 29/05/2021.
//

#ifndef CELLULUT_VOISINAGE_H
#define CELLULUT_VOISINAGE_H

#include <iostream>
#include <cmath>
#include "Cellule.h"
#include <vector>

/**
* \class Voisinage
* \brief Classe mere abstraite
*/

class Voisinage{
public:
    /**
    * \brief Surcharge de l'opérateur d'affectation
     * \param v Voisinage à affecter
     * \return Voisinage
     */
    Voisinage& operator=(const Voisinage& v) = delete;
    /**
    * \brief Constructeur de recopie de la classe Voisinage (delete)
    * \param v Voisinage à recopier
    */
    Voisinage(const Voisinage& v) = delete;
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
    virtual const std::vector<CELLULE_NP::Cellule*> calculerVoisinage(std::vector<CELLULE_NP::Cellule*> tab, std::vector<std::vector<CELLULE_NP::Cellule*>> reseau, unsigned int x, unsigned int y, unsigned int largeur, unsigned int longueur) const = 0;
    /**
     * \brief getter
     * @return nombre de cellules du voisinage
     */
    virtual unsigned int getNbCellulesVoisines() const = 0;
};


#endif //CELLULUT_VOISINAGE_H
