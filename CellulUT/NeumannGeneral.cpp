//
// Created by Amelie Pelle on 29/05/2021.
//

#include "NewmannGeneral.h"


NeumannGeneral::~NeumannGeneral() = default;

using namespace std;

Cellule * NeumannGeneral::calculerVoisinage(Cellule tab[], Automate * a, unsigned int x, unsigned int y) const {
    unsigned int k, l, i = 0;
    for(k=0; k <= a->reseau.largeur; k++) {
        for(l=0; l <= a->reseau.hauteur; l++){
            if(abs(k-x) + abs(l-y) <= rayon){
                tab[i] = a->reseau.cellules[k][l];
                i++;
            }
        }

    }
    return tab;
}

