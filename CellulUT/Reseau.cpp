//
// Created by Reda on 25/05/2021.
//

#include "Reseau.h"
#include "Automate.h"

Reseau::Reseau(int la, int lo, int hor, int t) {
{
    allocArray();
    for(int i = 0; i < taille; i++)
    {
        for(int j = 0; j < taille; j++)
        {
            cellule[i][j] = new Cellule(i,j, automate.getEtat(0),this);
        }
    }
    largeur = la;
    longueur = lo;
    horloge = hor;
    taille = t;
}
void Reseau::setHorloge(int hor)
{
    horloge = hor;
}
void Reseau::setLargeur(int lar)
{
    largeur = lar;
}
void Reseau::setLongeur(int lon)
{
    longueur = lon;
}
