//
// Created by Amelie Pelle on 29/05/2021.
//

#ifndef CELLULUT_MOORE_H
#define CELLULUT_MOORE_H

#include "MooreGeneral.h"

/**
* \class Moore
* \brief Herite de la classe MooreGeneral, gere les voisinages de Moore de rayon 1
*/
class Moore : public MooreGeneral {
public:
    /**
    * \brief Constructeur de la classe Moore
     * sans parametre, on utilise le constructeur de la classe mere en fixant le rayon a 1
     */
    explicit Moore() : MooreGeneral(1) {};
    /**
    * \brief surcharge du setter de la classe Moore
     * \param r rayon à affecter non utilisé : la methode fixe le rayon à 1
     */
    void setRayon(unsigned int r) override {rayon = 1;}
    /**
    * \brief Destructeur de la classe Moore
     */
    ~Moore() override;
    /**
     * \brief setter
     * @param nb inutilise (le nombre de voisins est de 8)
     */
    void setNbCellulesVoisines(unsigned int nb) override {nbCellulesVoisines = 8;}
};

#endif //CELLULUT_MOORE_H
