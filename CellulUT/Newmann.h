//
// Created by Amelie Pelle on 29/05/2021.
//

#ifndef CELLULUT_NEWMANN_H
#define CELLULUT_NEWMANN_H

#include "NewmannGeneral.h"

/**
* \class Neumann
* \brief Herite de la classe NeumannGeneral, gere les voisinages de von Neumann de rayon 1
*/

class Neumann : public NeumannGeneral {
public:
    /**
    * \brief Constructeur de la classe Neumann
     * sans parametre, on utilise le constructeur de la classe mere en fixant le rayon a 1
     */
    explicit Neumann() : NeumannGeneral(1) {};
    /**
    * \brief surcharge du setter de la classe Neumann
     * \param r rayon à affecter non utilisé : la methode fixe le rayon à 1
     */
    void setRayon(unsigned int r) override {rayon = 1;}
    /**
    * \brief Destructeur de la classe Neumann
     */
    ~Neumann() override;
    /**
     * \brief setter
     * @param nb inutilise (le nombre de voisins est de 4)
     */
    void setNbCellulesVoisines(unsigned int nb) override {nbCellulesVoisines = 4;}
};

#endif //CELLULUT_NEWMANN_H
