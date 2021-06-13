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

    /**
    * \file Automate.h
    * \author Lucas Clusman
    */

    /**
    * \class Automate
    * \brief Représente un automate.
    */
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

        /**
        * \brief Récupérer l'instance de l'automate.
         */
        static Automate& getAutomate (); // Fonction get instance d'automate dans le cas où l'instance existe

        /**
        * \brief Initialise ou modifie l'instance de l'automate.
         * \param r réseau de cellules
         * \param n nombre d'états
         * \param v voisinage
         * \param t transition
         */
        static void setAutomate (RESEAU_NP::Reseau* r, unsigned int n, Voisinage* v, Transition* t); // Fonction get instance d'automate avec arguments dans le cas où l'instance aura besoin d'être créée

        /**
        * \brief Libère l'instance de l'automate.
         */
        static void libererAutomate();

        // GETTERS
        /**
        * \brief Récupérer une référence au réseau de cellules.
         */
        RESEAU_NP::Reseau* getReseau() { return reseau; }

        /**
        * \brief Récupérer la liste totale des états de l'automate.
         */
        std::vector<ETAT_NP::Etat*> getEtats() const { return etats; }

        /**
        * \brief Récupérer un état de la liste des états
        * \param i indice de l'état.
         */
        ETAT_NP::Etat* getEtat(unsigned int i) const { return etats[i]; }

        /**
        * \brief Récupérer le voisinage de l'automate.
         */
        Voisinage* getVoisinage() const {return voisinage;}

        /**
        * \brief Récupérer la règle de transition utilisée par l'automate.
         */
        Transition* getTransition() const {return regleTransition;}

        /**
        * \brief Récupérer le nombre d'états.
         */
        size_t getNbEtats() { return nbEtats; }

        // SETTERS

        /**
        * \brief Modifie le nombre d'états
        * \param n nombre d'états
         */
        void setNbEtats(size_t n) {nbEtats = n;}

        /**
        * \brief Modifie le réseau de cellules
        * \param r pointeur vers le réseau de cellules à utiliser
         */
        void setReseau(RESEAU_NP::Reseau* r){ reseau = r;}

        /**
        * \brief Modifie la liste des états
        * \param n nombre d'états
        * \param e vecteur d'états
         */
        void setEtats(size_t n, std::vector<ETAT_NP::Etat*> e);

        /**
        * \brief Modifie le voisinage
        * \param v voisinage à utiliser
         */
        void setVoisinage(Voisinage* v) {voisinage = v;}

        /**
        * \brief Modifie la règle de transition
        * \param t règle de transition à utiliser
         */
        void setTransition(Transition* t) {regleTransition = t;}

        /**
        * \brief Applique une configuration en fonction d'un fichier XML.
        * \param xmlReader
         */
        void appliquerConfiguration(QXmlStreamReader * xmlReader);

        /**
        * \brief Applique la transition sur le réseau de cellules, qui passe à l'état suivant.
         */
        void calculerTransition();

    };
}

#endif // AUTOMATE_H
