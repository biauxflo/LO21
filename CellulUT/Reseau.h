
#ifndef LO21_RESEAU_H
#define LO21_RESEAU_H

#include "Cellule.h"
#include <vector>


namespace RESEAU_NP{
	
/**
* \class Reseau
* \brief Classe ayant quatres attributs, largeur, longueur, horloge et une matrice de cellules. C'est grâce à cette classe que nous allons gérer le reseau de cellule de l'automate.
*/
    class Reseau {
    private:
        unsigned int largeur;
        unsigned int longueur;
        unsigned int horloge;
        std::vector<std::vector<CELLULE_NP::Cellule*>> cellules;

    public:
        Reseau(int la, int lo, int hor);
        Reseau();
        ~Reseau();

        unsigned int getLargeur () const {return largeur;}
        unsigned int getLongueur () const {return longueur;}
        unsigned int getHorloge () const {return horloge;}
        std::vector<std::vector<CELLULE_NP::Cellule*>> getCellules() const {return cellules;}
        CELLULE_NP::Cellule& getCellule(unsigned int i, unsigned int j) const {return *cellules[i][j];}

        void setLargeur (int lar);
        void setLongeur (int lon);
        void setHorloge (int hor);

    };


}

#endif //LO21_RESEAU_H
