//
// Created by Reda on 25/05/2021.
//

#include "Cellule.h"
using namespace CELLULE_NP;

void Cellule::setAbscisse(int x)
{
    abs = x;
}
void Cellule::setOrdonnee(int y)
{
    ord = y;
}

void Cellule::setEtat(ETAT_NP::Etat &e){
    etat = &e;
}

Cellule& Cellule::operator=(const Cellule& c){
    return *this;
}
