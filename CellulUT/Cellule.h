//
// Created by Reda on 25/05/2021.
//

#ifndef LO21_CELLULE_H
#define LO21_CELLULE_H
#include "Reseau.h"
#include "Etat.h"

class Cellule
{
private:
    unsigned int abs;
    unsigned int ord;
    Etat& etat;
    Reseau& reseau;

public:
    Cellule (unsigned int abs, unsigned int ord, Etat& etat, Reseau& reseau) : abs(abs), ord(ord), etat(etat), reseau(reseau) {}
    int getAbscisse () const {return abs;}
    int getOrdonnee () const {return ord;}
    void setAbscisse (int x);
    void setOrdonnee (int y);
    // void getVoisinnage(...)
};


#endif //LO21_CELLULE_H
