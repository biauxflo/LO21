#ifndef AUTOMATE_H
#define AUTOMATE_H

#include <QtXml>
#include "Cellule.h"
#include "Reseau.h"
#include "Etat.h"
#include "Voisinage.h"

#define MAX_ETATS 8

namespace AUTOMATE_NP{
    class Automate{
        RESEAU_NP::Reseau reseau;
        ETAT_NP::Etat etats[MAX_ETATS];
        Voisinage voisinage;
        unsigned int nbEtatsMax;
        //Transition regleTransition;

    public:
        Automate(RESEAU_NP::Reseau r, unsigned int n): reseau(r), nbEtatsMax(n) {} //, Etat[] e): reseau(r), etats(e) {}//, voisinage(v), regleTransition(rt) {} Voisinage v, Transition rt
        ~Automate();

        // GETTERS
        const RESEAU_NP::Reseau getReseau() const { return reseau; }
        const ETAT_NP::Etat* getEtats() const { return etats; }
        const ETAT_NP::Etat& getEtat(unsigned int i) const { return etats[i]; }
        Voisinage getVoisinage() { return voisinage; }
        unsigned int getNbEtatsMax() { return nbEtatsMax; }
        //Transition getRegleTransition() { return regleTransition; }

        void appliquerConfiguration(QXmlStreamReader xmlReader);
        void calculerTransition();

    };
}

#endif // AUTOMATE_H
