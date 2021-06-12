//
// Created by Amelie Pelle on 29/05/2021.
//

#include "Arbitraire.h"

const std::vector<CELLULE_NP::Cellule*> Arbitraire::calculerVoisinage(std::vector<CELLULE_NP::Cellule*> tab, std::vector<std::vector<CELLULE_NP::Cellule*>> reseau, unsigned int x, unsigned int y, unsigned int largeur, unsigned int longueur) const {
    std::vector<int> distAbs = calculerDistanceAbscisse();
    std::vector<int> distOrd = calculerDistanceOrdonnee();
    for(unsigned int i = 0; i < nbvoisins; i++){
        int absCalcule = x + distAbs[i];
        int ordCalcule = y + distOrd[i];
        int larg = largeur - 1;
        int longu = longueur - 1;
        if(absCalcule > larg) absCalcule = absCalcule - (larg+1);
        else if(absCalcule < 0) absCalcule = absCalcule + larg;
        if(ordCalcule < 0) ordCalcule = ordCalcule + longu;
        else if(ordCalcule > longu) ordCalcule = ordCalcule - (longu+1);
        tab[i] = reseau[absCalcule][ordCalcule];
    }

    return tab;
}
