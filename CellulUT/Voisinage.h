//
// Created by Anne Pelle on 29/05/2021.
//

#ifndef CELLULUT_VOISINAGE_H
#define CELLULUT_VOISINAGE_H

#include <iostream>
#include <cmath>

/**
* \class Voisinage
* \brief Classe mere abstraite
*/

class Voisinage{
private :
    /**
    * \brief Constructeur de recopie de la classe Voisinage
    * \param v Voisinage à recopier
    */
    Voisinage(const Voisinage& v)=false;

    /**
    * \brief Surcharge de l'opérateur d'affectation
     * \param v Voisinage à affecter
     * \return Voisinage
     */
    Voisinage& operator=(const Visinage& v)=false;
public:
    /**
    * \brief Constructeur (par defaut) de la classe Voisinage
     */
    Voisinage() = default;

    /**
    * \brief Destructeur (par defaut) de la classe Voisinage
     */
    virtual ~Voisinage() = default;
    /**
    * \brief Methode virtual qui calcule le voisinage d'une cellue (surchargee dans les classes filles)
     */
    virtual Cellule * calculerVoisinage(Cellule tab[], Automate * a, unsigned int x, unsigned int y) const {}
};


#endif //CELLULUT_VOISINAGE_H
