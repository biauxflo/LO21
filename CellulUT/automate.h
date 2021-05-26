#ifndef AUTOMATE_H
#define AUTOMATE_H

#include <QtXml>

namespace AUTOMATE{
    class Automate{
        Reseau reseau;
        Etat[] etats;
        Voisinage voisinage;
        unsigned int nbEtatsMax;
        Transition regleTransition;

    public:
        Automate();
        ~Automate();

        // GETTERS
        Reseau getReseau(){ return reseau; }
        Etat[] getEtats() { return etats; }
        Etat getEtat(unsigned int i) { return etats[i]; }
        Voisinage getVoisinage() { return voisinage; }
        unsigned int getNbEtatsMax() { return nbEtatsMax; }
        Transition getRegleTransition() { return regleTransition; }

        void appliquerConfiguration(QDomElement config);
        void calculerTransition();

    };
}


#endif // AUTOMATE_H
