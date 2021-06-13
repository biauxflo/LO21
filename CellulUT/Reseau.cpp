//
// Created by Reda on 25/05/2021.
//

#include "Cellule.h"
#include "Reseau.h"

RESEAU_NP::Reseau::Reseau(int la, int lo, int hor) {
    largeur = la;
    longueur = lo;
    horloge = hor;
    unsigned int abs, ord;
    /*
    for (unsigned int i = 0; i < longueur; ++i) {
        cellules[i] = new CELLULE_NP::Cellule();
    }*/
    for (abs = 0; abs < largeur; abs++){
        std::vector<CELLULE_NP::Cellule*> v;
        for(ord = 0; ord < longueur; ord++) {
            CELLULE_NP::Cellule* c = new CELLULE_NP::Cellule(abs, ord, new ETAT_NP::Etat);
            v.push_back(c);
        }
        cellules.push_back(v);
    }

}

RESEAU_NP::Reseau::~Reseau(){
    for(unsigned int i = 0; i < largeur ; i++)
    {
        for(unsigned int j = 0; j < longueur; j++){
            delete cellules[i][j];
        }
    }
}

RESEAU_NP::Reseau::Reseau(){

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
