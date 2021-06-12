#ifndef AUTOMATE_H
#define AUTOMATE_H
#include <QtXml>
#include <QString>
#include "Cellule.h"
#include "Reseau.h"
#include "Etat.h"
#include "Voisinage.h"
#include "Transition.h"
#include "AutomateException.h"
#include <Newmann.h>
#include <Moore.h>
#include <BrianBrainTransition.h>
#include <GameLifeTransition.h>
#include <GriffeathTransition.h>

#define MAX_ETATS 8

namespace AUTOMATE_NP{
    class Automate{
        RESEAU_NP::Reseau* reseau;
        std::vector<ETAT_NP::Etat*> etats;
        Voisinage* voisinage;
        size_t nbEtats;
        Transition* regleTransition;
        Automate(RESEAU_NP::Reseau* r, unsigned int n, Voisinage* v, Transition* t): reseau(r), nbEtats(n), voisinage(v), regleTransition(t) {}
        virtual ~Automate();
        static Automate* automate_Instance; // Instance automate
    public:
        Automate(const Automate&) = delete; // Suppression du constructeur de recopie
        void operator=(const Automate &) = delete; // Suppression de l'opérateur "="
        static Automate& getAutomate (); // Fonction get instance d'automate dans le cas où l'instance existe
        static void setAutomate (RESEAU_NP::Reseau* r, unsigned int n, Voisinage* v, Transition* t); // Fonction get instance d'automate avec arguments dans le cas où l'instance aura besoin d'être créée
        static void libererAutomate();

        // GETTERS
        RESEAU_NP::Reseau& getReseau() const { return *reseau; }
        std::vector<ETAT_NP::Etat*> getEtats() const { return etats; }
        ETAT_NP::Etat* getEtat(unsigned int i) const { return etats[i]; }
        size_t getNbEtats() { return nbEtats; }

        // SETTERS
        void setNbEtats(size_t n) {nbEtats = n;}
        void setReseau(RESEAU_NP::Reseau* r){ reseau = r;}
        void setEtats(size_t n, std::vector<ETAT_NP::Etat*> e);
        void setVoisinage(Voisinage* v) {voisinage = v;}
        void setTransition(Transition* t) {regleTransition = t;}
        void appliquerConfiguration(QXmlStreamReader xmlReader);
        void calculerTransition();

    };
}

#endif // AUTOMATE_H
