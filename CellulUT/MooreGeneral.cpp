//
// Created by Amelie Pelle on 29/05/2021.
//

#include "MooreGeneral.h"


MooreGeneral::~MooreGeneral() = default;

using namespace std;

CELLULE_NP::Cellule * MooreGeneral::calculerVoisinage(CELLULE_NP::Cellule tab[], AUTOMATE_NP::Automate * a, unsigned int x, unsigned int y) const {
    unsigned int k, l, i = 0;
    for(k=0; k <= a->reseau.getLargeur(); k++) {
        for(l=0; l <= a->reseau.getLongueur(); l++){
            if(abs(k-x) <= rayon && abs(l-y) <= rayon){
                tab[i] = a->reseau.cellules[k][l];
                i++;
            }
        }

    }
    return tab;
}
