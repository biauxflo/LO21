#ifndef AUTOMATE_H
#define AUTOMATE_H

#include <QtXml>
#include "Cellule.h"
#include "Reseau.h"
#include "Etat.h"
#include "Voisinage.h"
#include "Transition.h"

#define MAX_ETATS 8

namespace AUTOMATE_NP{
    class Automate{
        RESEAU_NP::Reseau reseau;
        ETAT_NP::Etat** etats = new ETAT_NP::Etat *[MAX_ETATS];
        Voisinage* voisinage;
        size_t nbEtats;
        Transition* regleTransition;

    public:
        Automate(RESEAU_NP::Reseau r, unsigned int n, Voisinage* v, Transition* t): reseau(r), nbEtats(n), voisinage(v), regleTransition(t) {}
        ~Automate();

        // GETTERS
        const RESEAU_NP::Reseau getReseau() const { return reseau; }
        ETAT_NP::Etat** getEtats() const { return etats; }
        ETAT_NP::Etat* getEtat(unsigned int i) const { return etats[i]; }
        size_t getNbEtats() { return nbEtats; }

        // SETTERS
        void setNbEtats(size_t n) {nbEtats = n;}
        void setReseau(RESEAU_NP::Reseau& r){ reseau = r;}
        void setEtats(size_t n, ETAT_NP::Etat** e);
        void setVoisinage(Voisinage* v) {voisinage = v;}
        void setTransition(Transition* t) {regleTransition = t;}

        void appliquerConfiguration(QXmlStreamReader xmlReader);
        void calculerTransition();

    };
}

#endif // AUTOMATE_H
