//
// Created by Amelie Pelle on 29/05/2021.
//

#include "MooreGeneral.h"


MooreGeneral::~MooreGeneral() = default;

using namespace std;

const CELLULE_NP::Cellule * MooreGeneral::calculerVoisinage(CELLULE_NP::Cellule tab[], CELLULE_NP::Cellule** reseau, unsigned int x, unsigned int y, unsigned int largeur, unsigned int longueur) const {
    unsigned int k, l, i = 0;
    for(k=0; k <= largeur; k++) {
        for(l=0; l <= longueur; l++){
            if(abs(int(k-x)) <= rayon && abs(int(l-y)) <= rayon){
                tab[i] = reseau[k][l];
                i++;
            }
        }

    }
    return tab;
}
