//
// Created by Anne Pelle on 07/06/2021.
//
/**
* \file BrianBrainTransition.cpp
* \author Amelie Pelle
*/

#include "BrianBrainTransition.h"

ETAT_NP::Etat& BrianBrainTransition::creerTransition(std::vector<ETAT_NP::Etat*> etats, ETAT_NP::Etat& etat, std::vector<CELLULE_NP::Cellule*> voisines, unsigned int nbVoisines) {
    unsigned int resting = 0;
    unsigned int excited = 0;
    unsigned int refractory = 0;

    for(unsigned int i = 0; i < nbVoisines; i++){
        if(voisines[i]->getEtat().getIndice() == 0){
            resting++;
        } else if(voisines[i]->getEtat().getIndice() == 1){
            excited++;
        } else if(voisines[i]->getEtat().getIndice() == 2){
            refractory++;
        }
    }

    if(etat.getIndice() == 0){
        if(excited == 2) return *etats[1]; // on retourne l'etat excite si il y a 2 des 8 voisines dans l etat excite
        else return *etats[0];
    }
    else if(etat.getIndice() == 1){
        return *etats[2]; // les cellules excitees deviennent toujours refractaires au pas de temps suivant
    }
    else if(etat.getIndice() == 2){
        return *etats[0]; // Les cellules réfractaires sont toujours au repos au pas de temps suivant
    }
    else return etat;
}


