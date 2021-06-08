//
// Created by Reda on 25/05/2021.
//

#include "Cellule.h"
#include "Reseau.h"

RESEAU_NP::Reseau::Reseau(int la, int lo, int hor) {
    largeur = la;
    longueur = lo;
    horloge = hor;
    cellules = new CELLULE_NP::Cellule*[largeur];
    unsigned int abs, ord;
    /*
    for (unsigned int i = 0; i < longueur; ++i) {
        cellules[i] = new CELLULE_NP::Cellule();
    }*/
    for (abs = 0; abs < largeur; abs++){
        for(ord = 0; ord < longueur; ord++) {
            cellules[abs] = new CELLULE_NP::Cellule(abs, ord, nullptr);
        }
    }

}

RESEAU_NP::Reseau::~Reseau(){
    for(unsigned int i = 0; i < largeur ; i++)
    {
        delete[] cellules[i];
    }
    delete [] cellules;
}

void RESEAU_NP::Reseau::setHorloge(int hor)
{
    horloge = hor;
}
void RESEAU_NP::Reseau::setLargeur(int lar)
{
    largeur = lar;
}
void RESEAU_NP::Reseau::setLongeur(int lon)
{
    longueur = lon;
}
