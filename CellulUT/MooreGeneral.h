//
// Created by Amelie Pelle on 29/05/2021.
//

#ifndef CELLULUT_MOOREGENERAL_H
#define CELLULUT_MOOREGENERAL_H

#include "VoisinageARayon.h"

/**
* \file MooreGeneral.h
* \author Amelie Pelle
*/

/**
* \class MooreGeneral
* \brief Herite de la classe VoisinageARayon, gere les voisinages de Moore de rayon r entier positif
*/
class MooreGeneral : public VoisinageARayon {
protected:
    unsigned int nbCellulesVoisines = 8; /*!< nombre de voisins*/
public:
    /**
    * \brief Constructeur de la classe MooreGeneral
     * \param r rayon à affecter
     */
    explicit MooreGeneral(unsigned int r) : VoisinageARayon(r) {};
    /**
    * \brief Destructeur de la classe MooreGeneral
     */
    ~MooreGeneral() override = default;
    /**
    * \brief surcharge de la fonction calculerVoisinage pour le voisinage de Moore
     * \param tab vecteur de cellules faisant partie du voisinage
     * \param reseau : reseau a partir duquel on accede aux cellules
     * \param x et y coordonnees de la cellule dont on calcule le voisinage
     * \param longueur et largeur : dimensions du reseau
     * \return tab
     */
    const std::vector<CELLULE_NP::Cellule*> calculerVoisinage(std::vector<CELLULE_NP::Cellule*> tab, std::vector<std::vector<CELLULE_NP::Cellule>>& reseau, unsigned int x, unsigned int y, unsigned int largeur, unsigned int longueur) const override;

    /**
     * \brief getter
     * @return nombre de cellules du voisinage
     */
    unsigned int getNbCellulesVoisines() const override { return nbCellulesVoisines; }
    /**
     * \brief setter
     * \param nb nombre de cellules voisines
     * set l'attribut nbCellulesVoisines
     */
     virtual void setNbCellulesVoisines(unsigned int nb) {nbCellulesVoisines = nb;}
};

#endif //CELLULUT_MOOREGENERAL_H
