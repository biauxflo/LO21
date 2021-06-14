//
// Created by Amelie Pelle on 29/05/2021.
//

/**
* \file NeumannGeneral.cpp
* \author {Amelie Pelle, Lucas Clusman}
*/

#include "NewmannGeneral.h"

using namespace std;

const std::vector<CELLULE_NP::Cellule*> NeumannGeneral::calculerVoisinage(std::vector<CELLULE_NP::Cellule*> tab, std::vector<std::vector<CELLULE_NP::Cellule>>& reseau, unsigned int x, unsigned int y, unsigned int largeur, unsigned int longueur) const {
    //int k, l, i = 0;
    int k, l;

     for(k=0; k < (int)largeur; k++) {
         for(l=0; l < (int)longueur; l++){
             int abscisseDelta = std::abs(k-(int)x);
             int ordonneeDelta = std::abs(l-(int)y);
             if(abscisseDelta + ordonneeDelta <= (int)rayon && !((k == (int)x) && (l == (int)y))){
                 tab.push_back(&reseau[k][l]);
             }
         }
     }

/*
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
    }*/

    /*
    for(k=0; k < largeur; k++) {
        for(l=0; l < longueur; l++){


            if(abs(int(k-x)) + abs(int(l-y)) <= rayon){
                tab[i] = reseau[k][l];
                i++;
            }
        }

    }*/
    
    /*
    unsigned int k, l;
    unsigned int i = 0;
    for(k=0; k < largeur; k++) {
        for(l=0; l < longueur; l++){
            
            
            if(abs((int)(k-x)) + abs((int)(l-y)) <= (int)rayon){
                if(k != x && l != y) {
                    tab[i] = reseau[k][l];
                }
                
            }
            else if(abs((int)(k-(largeur-1)+rayon)) + abs((int)(l-y)) <= (int)rayon) {
                if(k != x && l != y) {
                    tab[i] = reseau[k][l];
                }
            }
            
            else if(abs((int)(k-x)) + abs((int)(k-(longueur-1)+rayon)) <= (int)rayon) {
                if(k != x && l != y) {
                    tab[i] = reseau[k][l];
                }
            }
            
            else if(abs((int)(k-(largeur-1)+rayon)) + abs((int)(k-(longueur-1)+rayon)) <= (int)rayon) {
                if(k != x && l != y) {
                    tab[i] = reseau[k][l];
                }
            }
            
            i++;
        }
        
    }*/
    
    return tab;
}

