//
// Created by Anne Pelle on 07/06/2021.
//

#include "BrianBrainTransition.h"

ETAT_NP::Etat& creerTransition(ETAT_NP::Etat** etats, ETAT_NP::Etat& etat, CELLULE_NP::Cellule* voisines, unsigned int nbVoisines) {
    unsigned int resting = 0;
    unsigned int excited = 0;
    unsigned int refractory = 0;

    for(unsigned int i = 0; i < nbVoisines; i++){
        if(voisines[i].getEtat().getLabel() == "resting"){
            resting++;
        } else if(voisines[i].getEtat().getLabel() == "excited"){
            excited++;
        } else if(voisines[i].getEtat().getLabel() == "refractory"){
            refractory++;
        }
    }

    if(etat.getLabel() == "resting"){
        if(excited == 2) return *etats[1]; // on retourne l'etat excite si il y a 2 des 8 voisines dans l etat excite
        else return etat;
    }
    else if(etat.getLabel() == "excited"){
        return *etats[2]; // les cellules excitees deviennent toujours refractaires au pas de temps suivant
    }
    else if(etat.getLabel() == "refractory"){
        return *etats[0]; // Les cellules réfractaires sont toujours au repos au pas de temps suivant
    }
    else return etat;
}


