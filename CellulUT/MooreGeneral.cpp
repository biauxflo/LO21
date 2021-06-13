//
// Created by Amelie Pelle on 29/05/2021.
//

/**
* \file MooreGeneral.cpp
* \author {Amelie Pelle, Lucas Clusman}
*/

#include "MooreGeneral.h"

using namespace std;

const std::vector<CELLULE_NP::Cellule*> MooreGeneral::calculerVoisinage(std::vector<CELLULE_NP::Cellule*> tab, std::vector<std::vector<CELLULE_NP::Cellule*>> reseau, unsigned int x, unsigned int y, unsigned int largeur, unsigned int longueur) const {
   //int k, l, i = 0;

   /* for(k=0; k <= (int)largeur; k++) {
        for(l=0; l <= (int)longueur; l++){
            int abscisseDelta = std::abs(k-(int)x);
            int ordonneeDelta = std::abs(l-(int)y);
            if(abscisseDelta <= (int)rayon && ordonneeDelta <= (int)rayon && !((k == (int)x) && (l == (int)y))){
                tab[i] = reseau[k][l];
                i++;
            }
        }
    //ne fonctionne pas... :'(
    }*/

    // abs(k−i)≤1 et abs(l−j)≤1

    int k, l;
    for(k=0; k < (int)largeur; k++) {
        for(l=0; l < (int)longueur; l++){
        int positionK = k+1;
        int positionL = l+1;

        if(!(k == (int)x && l == (int)y)) {
            if(abs((int)(positionK-x)) <= (int)rayon && abs((int)(positionL-y)) <= (int)rayon)
                tab.push_back(reseau[k][l]);

            else if(abs((int)(positionK-(largeur-1)+rayon)) <= (int)rayon && abs((int)(positionL-y)) <= (int)rayon)
                tab.push_back(reseau[k][l]);

            else if(abs((int)(positionK-x)) <= (int)rayon && abs((int)(positionL-(longueur-1)+rayon)) <= (int)rayon)
                tab.push_back(reseau[k][l]);

            else if(abs((int)(positionK-(largeur-1)+rayon)) <= (int)rayon && abs((int)(positionL-(longueur-1)+rayon)) <= (int)rayon)
                tab.push_back(reseau[k][l]);

        }
        }

    }
/*
    if(x == 0){ // fonctionne
        tab[0] = reseau[longueur-1][y];
        if(y == 0){
            tab[4] = reseau[longueur-1][largeur-1];
        } else {
            tab[4] = reseau[longueur-1][y-1];
        }
    } else {
        tab[0] = reseau[x-1][y];
        if(y == 0){
            tab[4] = reseau[x-1][largeur-1];
        } else {
            tab[4] = reseau[x-1][y-1];
        }
    }

    if(y == 0){
        tab[1] = reseau[x][largeur-1];
        if(x == 0){
            tab[5] = reseau[longueur-1][largeur-1];
        } else {
            tab[5] = reseau[x-1][largeur-1];
        }
    } else {
        tab[1] = reseau[x][y-1];
        if(x == 0){
            tab[5] = reseau[longueur-1][y-1];
        } else {
            tab[5] = reseau[x-1][y-1];
        }
    }

    if(x == (longueur-1)){
        tab[2] = reseau[0][y];
        if(y == (largeur-1)){
            tab[6] = reseau[0][0];
        } else {
            tab[6] = reseau[0][y+1];
        }
    } else {
        tab[2] = reseau[x+1][y];
        if(y == (largeur-1)){
            tab[6] = reseau[x+1][0];
        } else {
            tab[6] = reseau[x+1][y+1];
        }
    }

    if(y == (largeur-1)){
        tab[3] = reseau[x][0];
        if(x == (longueur-1)){
            tab[7] = reseau[0][0];
        } else {
            tab[7] = reseau[x+1][0];
        }
    } else {
        tab[3] = reseau[x][y+1];
        if(x == (longueur-1)){
            tab[7] = reseau[0][y+1];
        } else {
            tab[7] = reseau[x+1][y+1];
        }
    }*/

    return tab;
}
