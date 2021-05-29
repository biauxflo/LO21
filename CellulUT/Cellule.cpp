//
// Created by Reda on 25/05/2021.
//

#include "Cellule.h"

void CELLULE_NP::Cellule::setAbscisse(int x)
{
    abs = x;
}
void CELLULE_NP::Cellule::setOrdonnee(int y)
{
    ord = y;
}

void CELLULE_NP::Cellule::setEtat(ETAT_NP::Etat &e){
    etat = e;
}
