//
// Created by Anne Pelle on 08/06/2021.
//
#include "GriffeathTransition.h"

ETAT_NP::Etat& GriffeathTransition::creerTransition(ETAT_NP::Etat** etats, ETAT_NP::Etat& etat, const CELLULE_NP::Cellule* voisines, unsigned int nbVoisines){
    unsigned int zero = 0;
    unsigned int one = 0;
    unsigned int two = 0;
    unsigned int three = 0;

    for(unsigned int i = 0; i < nbVoisines; i++){
        if(voisines[i].getEtat().getLabel() == "zero"){
            zero++;
        } else if(voisines[i].getEtat().getLabel() == "one"){
            one++;
        } else if(voisines[i].getEtat().getLabel() == "two"){
            two++;
        } else if(voisines[i].getEtat().getLabel() == "three"){
            three++;
        }
    }

    if(etat.getLabel() == "zero"){
        if(one == 3) return *etats[1]; // on retourne l etat i+1 des que 3 voisines sont dans l etat i+1
        else return etat;
    }
    else if(etat.getLabel() == "one"){
        if(two == 3) return *etats[2];
        else return etat;
    }
    else if(etat.getLabel() == "two"){
        if(three == 3) return *etats[3];
        else return etat;
    }
    else if(etat.getLabel() == "three"){
        if(zero == 3) return *etats[0];
        else return etat;
    }
    else return etat;
}
