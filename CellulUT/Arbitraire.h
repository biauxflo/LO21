//
// Created by Amelie Pelle on 29/05/2021.
//

#ifndef CELLULUT_ARBITRAIRE_H
#define CELLULUT_ARBITRAIRE_H

#include "Voisinage.h"

class Arbitraire : public Voisinage {
public:
    /**
    * \brief surcharge de la methode calculerVoisinage
     */
    CELLULE_NP::Cellule * calculerVoisinage(CELLULE_NP::Cellule tab[], CELLULE_NP::Cellule** reseau, unsigned int x, unsigned int y, unsigned int largeur, unsigned int longueur) const override;
};

#endif //CELLULUT_ARBITRAIRE_H

