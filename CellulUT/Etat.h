//
// Created by Reda on 25/05/2021.
//

#ifndef LO21_ETAT_H
#define LO21_ETAT_H

#include <string>

namespace ETAT_NP{
    class Etat
    {
    private:
        unsigned int indice;
        std::string label;
        // QColor couleur;

    public:
        int getIndice () {return indice;}
        std::string getLabel () {return label;}
        //int getColor () {return couleur;}

        void setIndice (int ind);
        void setLabel (int lab);
        //void setColor (int couleur);
        // operator==
    };
}



#endif //LO21_ETAT_H
