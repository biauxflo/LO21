/**
* \file GameLifeTransition.cpp
* \author Lucas Clusman
*/

#include "GameLifeTransition.h"

ETAT_NP::Etat& GameLifeTransition::creerTransition(std::vector<ETAT_NP::Etat*> etats, ETAT_NP::Etat& etat, std::vector<CELLULE_NP::Cellule*> voisines, unsigned int nbVoisines){
    unsigned int vivantes = 0;
    unsigned int mortes = 0;

    for(unsigned int i = 0; i < nbVoisines; i++){
        if(voisines[i]->getEtat().getIndice() == 1){ // A MODIFIER avec operator== et fabrique etat
            vivantes++;
        } else if(voisines[i]->getEtat().getIndice() == 0){
            mortes++;
        }
    }

    if(etat.getIndice() == 1){
        if(vivantes == 2) return *etats[1]; // on retourne l'etat alive
        else if(vivantes == 3) return *etats[1];
        else return *etats[0]; // elle meurt dans tous les autres cas
    }
    else if(etat.getIndice() == 0){
        if(vivantes == 3) return *etats[1]; // elle naît
        else return *etats[0];
    } else return *etats[0];
}
