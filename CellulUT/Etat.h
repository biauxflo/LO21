//
// Created by Reda on 25/05/2021.
//

#ifndef LO21_ETAT_H
#define LO21_ETAT_H

#include <string>
#include <QColor>



namespace ETAT_NP{
	/**
* \class Etat
* \brief Les attributs de cette classe sont un indice, un label et une couleur. C'est grâce à cette classe que nous allons pouvoir afficher les différents états des cellules de notre réseau.
*/
    class Etat
    {
    private:
        unsigned int indice;
        std::string label;
        QRgb couleur;

    public:
        Etat() = default;
        Etat(int ind, std::string lab, QRgb c): indice(ind), label(lab), couleur(c) {}
        int getIndice () {return indice;}
        std::string getLabel () {return label;}
        QRgb getColor () {return couleur;}

        void setIndice (int ind);
        void setLabel (std::string lab);
        void setColor (int couleur);
        void augmenterIndice();
    };
}



#endif //LO21_ETAT_H
