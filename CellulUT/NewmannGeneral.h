//
// Created by Amelie Pelle on 29/05/2021.
//

#ifndef CELLULUT_NEWMANNGENERAL_H
#define CELLULUT_NEWMANNGENERAL_H

#include "VoisinageARayon.h"

/**
* \class NeumannGeneral
* \brief Herite de la classe VoisinageARayon, gere les voisinages de von Neumann de rayon r entier positif
*/
class NeumannGeneral : public VoisinageARayon {
public:
    /**
    * \brief Constructeur de la classe NeumannGeneral
     * \param r rayon à affecter
     */
    explicit NeumannGeneral(unsigned int r) : VoisinageARayon(r) {};
    /**
    * \brief Destructeur de la classe NeumannGeneral
     */
    ~NeumannGeneral() override;

    /**
    * \brief surcharge de la fonction calculerVoisinage pour le voisinage de von Neumann
     * \param tab tableau de cellules faisant partie du voisinage
     * \param a Automate a partir duquel on calcule le voisinage
     * \param x et y coordonnees de la cellule dont on calcule le voisinage
     * \return tab
     */
    Cellule * calculerVoisinage(Cellule tab[], Automate * a, unsigned int x, unsigned int y) const override;
};

#endif //CELLULUT_NEWMANNGENERAL_H
