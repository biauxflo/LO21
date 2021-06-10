//
// Created by Amelie Pelle on 29/05/2021.
//

#include "Arbitraire.h"

const std::vector<CELLULE_NP::Cellule*> Arbitraire::calculerVoisinage(std::vector<CELLULE_NP::Cellule*> tab, std::vector<std::vector<CELLULE_NP::Cellule*>> reseau, unsigned int x, unsigned int y, unsigned int largeur, unsigned int longueur) const {
    unsigned int * distAbs = calculerDistanceAbscisse();
    unsigned int * distOrd = calculerDistanceOrdonnee();
    for(unsigned int i = 0; i <= nbvoisins; i++){
        if(x + distAbs[i] > largeur) distAbs[i] = x + distAbs[i] - largeur;
        if(y + distOrd[i] > longueur) distOrd[i] = y + distOrd[i] - longueur;
        *tab[i] = *reseau[x + distAbs[i]][y + distOrd[i]];
    }
    return tab;
}
