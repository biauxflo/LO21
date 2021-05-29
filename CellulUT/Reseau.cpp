//
// Created by Reda on 25/05/2021.
//

#include "Cellule.h"
#include "Reseau.h"

RESEAU_NP::Reseau::Reseau(int la, int lo, int hor, int t) {
    largeur = la;
    longueur = lo;
    horloge = hor;
    taille = t;

   // allocArray();
    for(unsigned int i = 0; i < taille; i++)
    {/*
        for(unsigned int j = 0; j < taille; j++)
        {
            cellule[i][j] = CELLULE_NP::Cellule(i,j, automate.getEtat(0), this);     //Cellule(i,j, automate.getEtat(0),this);
        }*/
    }
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
