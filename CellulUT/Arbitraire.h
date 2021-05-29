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
    Cellule * calculerVoisinage(Cellule tab[], Automate * a, unsigned int x, unsigned int y) const override;
};

#endif //CELLULUT_ARBITRAIRE_H
