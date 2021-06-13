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
protected:
    unsigned int nbCellulesVoisines = 4; /*!< nombre de voisins*/
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
     * \param tab vecteur de cellules faisant partie du voisinage
     * \param reseau : reseau a partir duquel on accede aux cellules
     * \param x et y coordonnees de la cellule dont on calcule le voisinage
     * \param longueur et largeur : dimensions du reseau
     * \return tab
     */
    const std::vector<CELLULE_NP::Cellule*> calculerVoisinage(std::vector<CELLULE_NP::Cellule*> tab, std::vector<std::vector<CELLULE_NP::Cellule*>> reseau, unsigned int x, unsigned int y, unsigned int largeur, unsigned int longueur) const override;
    /**
     * \brief getter
     * @return nombre de cellules du voisinage
     */
    unsigned int getNbCellulesVoisines() const override{ return nbCellulesVoisines; }
    /**
     * \brief setter
     * \param nb nombre de cellules voisines
     * set l'attribut nbCellulesVoisines
     */
    virtual void setNbCellulesVoisines(unsigned int nb) {nbCellulesVoisines = nb;}
};

#endif //CELLULUT_NEWMANNGENERAL_H
