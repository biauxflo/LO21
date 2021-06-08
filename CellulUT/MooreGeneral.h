//
// Created by Amelie Pelle on 29/05/2021.
//

#ifndef CELLULUT_MOOREGENERAL_H
#define CELLULUT_MOOREGENERAL_H

#include "VoisinageARayon.h"

/**
* \class MooreGeneral
* \brief Herite de la classe VoisinageARayon, gere les voisinages de Moore de rayon r entier positif
*/
class MooreGeneral : public VoisinageARayon {
private:
    const unsigned int nbCellulesVoisines = 8;
public:
    /**
    * \brief Constructeur de la classe MooreGeneral
     * \param r rayon à affecter
     */
    explicit MooreGeneral(unsigned int r) : VoisinageARayon(r) {};
    /**
    * \brief Destructeur de la classe MooreGeneral
     */
    ~MooreGeneral() override;
    /**
    * \brief surcharge de la fonction calculerVoisinage pour le voisinage de Moore
     * \param tab tableau de cellules faisant partie du voisinage
     * \param a Automate a partir duquel on calcule le voisinage
     * \param x et y coordonnees de la cellule dont on calcule le voisinage
     * \return tab
     */
    const CELLULE_NP::Cellule * calculerVoisinage(CELLULE_NP::Cellule tab[], CELLULE_NP::Cellule** reseau, unsigned int x, unsigned int y, unsigned int largeur, unsigned int longueur) const override;

    unsigned int getNbCellulesVoisines() const override { return nbCellulesVoisines; }
};

#endif //CELLULUT_MOOREGENERAL_H
