#include "GameLifeTransition.h"

ETAT_NP::Etat& GameLifeTransition::creerTransition(ETAT_NP::Etat** etats, ETAT_NP::Etat& etat, const CELLULE_NP::Cellule* voisines, const unsigned int nbVoisines){
    unsigned int vivantes = 0;
    unsigned int mortes = 0;

    for(unsigned int i = 0; i < nbVoisines; i++){
        if(voisines[i].getEtat().getLabel() == "alive"){ // A MODIFIER avec operator== et fabrique etat
            vivantes++;
        } else if(voisines[i].getEtat().getLabel() == "dead"){
            mortes++;
        }
    }

    if(etat.getLabel() == "alive"){
        if(vivantes == 2) return *etats[1]; // on retourne l'etat alive
        else if(vivantes == 3) return *etats[1];
        else return *etats[0]; // elle meurt dans tous les autres cas
    }
    else if(etat.getLabel() == "dead"){
        if(vivantes == 3) return *etats[1]; // elle naît
    }
}
