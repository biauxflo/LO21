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
        unsigned int taille;
        AUTOMATE_NP::Automate& automate;
        CELLULE_NP::Cellule** cellules;
        /*void allocArray() Erreur au niveau de "Cellule ** que j'ai pas réussi à régler"
        {
            cellules = CELLULE_NP::Cellule** (new *int[taille]);
            for(int i = 0; i < taille; i++)
            {
                cellules[i] = CELLULE_NP::Cellule* (new int[taille]);
            }
        }
        */
    public:
        Reseau(int la, int lo, int hor, int t);
        ~Reseau()
        {
            for(unsigned int i = 0; i < taille ; i++)
            {
                delete [] cellules[i];
            }
            delete [] cellules;
        }

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
