//
// Created by Amelie Pelle on 29/05/2021.
//

#ifndef CELLULUT_VOISINAGEARAYON_H
#define CELLULUT_VOISINAGEARAYON_H

#include "Voisinage.h"

/**
* \class VoisinageARayon
* \brief Classe mere abstraite heritant de la classe Voisinage
*/

class VoisinageARayon : public Voisinage {
protected :
    unsigned int rayon; /*!< rayon permettant de calculer le voisinage autour d'une cellule*/
public:
    /**
    * \brief Constructeur de la classe Voisinage
     * \param r rayon à affecter
     */
    explicit VoisinageARayon(unsigned int r) : rayon(r) {};

    /**
    * \brief Destructeur de la classe VoisinageARayon
    */

    ~VoisinageARayon() override = default;

    /**
    * \brief getter
    */

    unsigned int getRayon() const {return rayon;}

    /**
    * \brief setter
    */

    virtual void setRayon(unsigned int r) {rayon = r;}

};


#endif //CELLULUT_VOISINAGEARAYON_H
