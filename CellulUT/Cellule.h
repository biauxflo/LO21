//
// Created by Reda on 25/05/2021.
//

#ifndef LO21_CELLULE_H
#define LO21_CELLULE_H

#include "Etat.h"
//#include "Reseau.h"

namespace CELLULE_NP{
    class Cellule
    {
    private:
        unsigned int abs;
        unsigned int ord;
        ETAT_NP::Etat& etat;
        //RESEAU_NP::Reseau& reseau;

    public:
        Cellule(unsigned int abs, unsigned int ord, ETAT_NP::Etat& etat) : abs(abs), ord(ord), etat(etat) {}
        int getAbscisse () const {return abs;}
        int getOrdonnee () const {return ord;}
        void setAbscisse (int x);
        void setOrdonnee (int y);
        void setEtat (ETAT_NP::Etat& e);
        // void getVoisinnage(...)
    };
}



#endif //LO21_CELLULE_H
