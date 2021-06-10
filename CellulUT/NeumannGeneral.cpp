//
// Created by Amelie Pelle on 29/05/2021.
//

#include "NewmannGeneral.h"


NeumannGeneral::~NeumannGeneral() = default;

using namespace std;

const std::vector<CELLULE_NP::Cellule*> NeumannGeneral::calculerVoisinage(std::vector<CELLULE_NP::Cellule*> tab, std::vector<std::vector<CELLULE_NP::Cellule*>> reseau, unsigned int x, unsigned int y, unsigned int largeur, unsigned int longueur) const {
    int k, l, i = 0;

    if(x == 0){
        tab[0] = reseau[longueur-1][y];
    } else {
        tab[0] = reseau[x-1][y];
    }

    if(y == 0){
        tab[1] = reseau[x][largeur-1];
    } else {
        tab[1] = reseau[x][y-1];
    }

    if(x == (longueur-1)){
        tab[2] = reseau[0][y];
    } else {
        tab[2] = reseau[x+1][y];
    }

    if(y == (largeur-1)){
        tab[3] = reseau[x][0];
    } else {
        tab[3] = reseau[x][y+1];
    }

    /*
    for(k=0; k < largeur; k++) {
        for(l=0; l < longueur; l++){


            if(abs(int(k-x)) + abs(int(l-y)) <= rayon){
                tab[i] = reseau[k][l];
                i++;
            }
        }

    }*/
    return tab;
}

