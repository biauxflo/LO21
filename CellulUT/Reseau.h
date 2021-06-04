//
// Created by Reda on 25/05/2021.
//

#ifndef LO21_RESEAU_H
#define LO21_RESEAU_H

#include "Cellule.h"

namespace RESEAU_NP{
    class Reseau {
    private:
        unsigned int largeur;
        unsigned int longueur;
        unsigned int horloge;
        CELLULE_NP::Cellule** cellules;

    public:
        Reseau(int la, int lo, int hor);
        ~Reseau();

        unsigned int getLargeur () const {return largeur;}
        unsigned int getLongueur () const {return longueur;}
        unsigned int getHorloge () const {return horloge;}
        CELLULE_NP::Cellule** getCellules() const {return cellules;}
        CELLULE_NP::Cellule getCellule(unsigned int i, unsigned int j) const {return cellules[i][j];}

        void setLargeur (int lar);
        void setLongeur (int lon);
        void setHorloge (int hor);
    };

}

#endif //LO21_RESEAU_H
