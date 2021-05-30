//
// Created by Amelie Pelle on 29/05/2021.
//

#include "MooreGeneral.h"


MooreGeneral::~MooreGeneral() = default;

using namespace std;

const CELLULE_NP::Cellule * MooreGeneral::calculerVoisinage(CELLULE_NP::Cellule tab[], AUTOMATE_NP::Automate * a, unsigned int x, unsigned int y) const {
    unsigned int k, l, i = 0;
    for(k=0; k <= a->getReseau().getLargeur(); k++) {
        for(l=0; l <= a->getReseau().getLongueur(); l++){
            if(abs(int(k-x)) <= rayon && abs(int(l-y)) <= rayon){
                tab[i] = a->getReseau().getCellule(k,l);
                i++;
            }
        }

    }
    return tab;
}
