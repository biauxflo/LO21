#ifndef AUTOMATE_H
#define AUTOMATE_H

#include <QtXml>
#include "Cellule.h"
#include "Reseau.h"
#include "Etat.h"

namespace AUTOMATE{
    class Automate{
        Reseau reseau;
        Etat etats[];
        Voisinage voisinage;
        unsigned int nbEtatsMax;
        Transition regleTransition;

    public:
        Automate();
        Automate(Reseau r, Etat[] e, Voisinage v, Transition rt): reseau(r), etats(e), voisinage(v), regleTransition(rt) {}
        ~Automate();

        // GETTERS
        Reseau getReseau(){ return reseau; }
        Etat[] getEtats() { return etats; }
        Etat getEtat(unsigned int i) { return etats[i]; }
        Voisinage getVoisinage() { return voisinage; }
        unsigned int getNbEtatsMax() { return nbEtatsMax; }
        Transition getRegleTransition() { return regleTransition; }

        void appliquerConfiguration(QXmlStreamReader xmlReader);
        void calculerTransition();

    };
}


#endif // AUTOMATE_H
