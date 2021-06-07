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
        ETAT_NP::Etat etats[MAX_ETATS];
        Voisinage& voisinage;
        unsigned int nbEtatsMax;
        Transition& regleTransition;
        Automate(RESEAU_NP::Reseau r, unsigned int n): reseau(r), nbEtatsMax(n) {} //, Etat[] e): reseau(r), etats(e) {}//, voisinage(v), regleTransition(rt) {} Voisinage v, Transition rt
        virtual ~Automate();
        static Automate* automate_Instance; // Instance automate
    public:
        Automate(const Automate&) = delete; // Suppression du constructeur de recopie
        void operator=(const Singleton &) = delete; // Suppression de l'opérateur "="
        static Automate& getAutomate () {} // Fonction get instance d'automate dans le cas où l'instance existe
        static Automate& getAutomate (RESEAU_NP::Reseau r, unsigned int n) {} // Fonction get instance d'automate avec arguments dans le cas où l'instance aura besoin d'être créée
        static void libererAutomate();

        // GETTERS
        const RESEAU_NP::Reseau getReseau() const { return reseau; }
        const ETAT_NP::Etat* getEtats() const { return etats; }
        const ETAT_NP::Etat& getEtat(unsigned int i) const { return etats[i]; }
        unsigned int getNbEtatsMax() { return nbEtatsMax; }

        // SETTERS
        void setReseau(RESEAU_NP::Reseau& r){ reseau = r;}
        void setEtats(unsigned int n, ETAT_NP::Etat *e);
        //void setVoisinage(Voisinage& v) {voisinage = v;}
        void setTransition(Transition& t) {regleTransition = t;}

        void appliquerConfiguration(QXmlStreamReader xmlReader);
        void calculerTransition();

    };
}

#endif // AUTOMATE_H
