//
// Created by Reda on 25/05/2021.
//

#ifndef LO21_CELLULE_H
#define LO21_CELLULE_H

#include "Etat.h"
//#include "Reseau.h"
/**
* \class Cellule
* \brief Classe possèdant trois attributs, abscisse, ordonnée et un pointeur vers un état
*/
namespace CELLULE_NP{
    class Cellule
    {
    private:
        unsigned int abs;
        unsigned int ord;
        ETAT_NP::Etat* etat;

    public:
        Cellule(unsigned int abscisse, unsigned int ordonnee, ETAT_NP::Etat* e = nullptr): abs(abscisse), ord(ordonnee), etat(e) {};

        Cellule& operator=(const Cellule& c);
        int getAbscisse () const {return abs;}
        int getOrdonnee () const {return ord;}
        ETAT_NP::Etat& getEtat() {return *etat;}
        void setAbscisse (int x);
        void setOrdonnee (int y);
        void setEtat (ETAT_NP::Etat& e);
    };
}



#endif //LO21_CELLULE_H
