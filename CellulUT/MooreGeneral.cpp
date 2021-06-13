//
// Created by Amelie Pelle on 29/05/2021.
//

#include "MooreGeneral.h"

using namespace std;

const std::vector<CELLULE_NP::Cellule*> MooreGeneral::calculerVoisinage(std::vector<CELLULE_NP::Cellule*> tab, std::vector<std::vector<CELLULE_NP::Cellule*>> reseau, unsigned int x, unsigned int y, unsigned int largeur, unsigned int longueur) const {
   // int k, l, i = 0;
/*
    for(k=0; k <= largeur; k++) {
        for(l=0; l <= longueur; l++){
            if(abs(int(k-x)) <= rayon && abs(int(l-y)) <= rayon){
                tab[i] = reseau[k][l];
                i++;
            }
        }
    ne fonctionne pas... :'(
    }*/

    /*
    unsigned int k, l;
    unsigned int i = 0;
    for(k=0; k < largeur; k++) {
        for(l=0; l < longueur; l++){


            if(abs((int)(k-x)) <= (int)rayon && abs((int)(l-y)) <= (int)rayon){
                if(k != x && l != y) {
                    tab[i] = reseau[k][l];
                }

            }
            else if(abs((int)(k-(largeur-1)+rayon)) (int)rayon && abs((int)(l-y)) <= (int)rayon) {
                if(k != x && l != y) {
                    tab[i] = reseau[k][l];
                }
            }

            else if(abs((int)(k-x)) <= (int)rayon && abs((int)(k-(longueur-1)+rayon)) <= (int)rayon) {
                if(k != x && l != y) {
                    tab[i] = reseau[k][l];
                }
            }

            else if(abs((int)(k-(largeur-1)+rayon)) <= (int)rayon && abs((int)(k-(longueur-1)+rayon)) <= (int)rayon) {
                if(k != x && l != y) {
                    tab[i] = reseau[k][l];
                }
            }

            i++;
        }

    }*/


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
    }

    return tab;
}
