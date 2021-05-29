//
// Created by Reda on 25/05/2021.
//

#ifndef LO21_RESEAU_H
#define LO21_RESEAU_H
#include "Cellule.h"
class Etat;

int const MAXCELL = 200;

class Reseau {
private:
    unsigned int largeur;
    unsigned int longueur;
    unsigned int horloge;
    unsigned int taille;
    Cellule** cellule;
    void allocArray()
    {
        cellule = reinterpret_cast<Cellule **>(new int *[taille]);
        for(int i = 0; i < taille; i++)
        {
            cellule[i] = reinterpret_cast<Cellule *>(new int[taille]);
        }
    }

public:
    Reseau(int la, int lo, int hor, int t);
    ~Reseau()
    {
        for(int i = 0; i < taille ; i++)
        {
            delete [] cellule[i];
        }
        delete [] cellule;
    }

    int getLargeur () {return largeur;}
    int getLongueur () {return longueur;}
    int getHorloge () {return horloge;}

    void setLargeur (int lar);
    void setLongeur (int lon);
    void setHorloge (int hor);
};


#endif //LO21_RESEAU_H
