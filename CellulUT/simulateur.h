#ifndef CELLULUT_SIMULATEUR_H
#define CELLULUT_SIMULATEUR_H

#include <string>
#include <iostream>
#include <QtCore>
#include "Etat.h"
#include "Automate.h"
#include "Reseau.h"
#include "Voisinage.h"
#include "Transition.h"
/**
* \class Simulateur
* \brief Gestion de la simulation globale (etats, transitions)
*/
namespace SIMULATEUR_NP {
    class Simulateur{

        AUTOMATE_NP::Automate &automate; /*!< Automate de la simulation*/
        RESEAU_NP::Reseau depart; /*!< Reseau de départ de la simulation*/
        RESEAU_NP::Reseau* save= nullptr;/*!< Sauvegarde des x derniers etats*/
        Voisinage &voisinage;/*!< Voisinage de la simulation*/
        Transition &transition;/*!< Fonction de transition de la simulation*/

        size_t indexMem;/*!< Index actuel de la mise en mémoire du reseau*/
        size_t memoire;/*!< Nombre d'étape de la simulation à garder en mémoire*/
        std::string nom;/*!< Titre de la simulation*/

    public :
        Simulateur(AUTOMATE_NP::Automate& a, Voisinage& v, Transition& t): automate(a), voisinage(v), transition(t) {}
        void next();
        void back();
        void reset();

        /**
        * \brief Parametre les Etats de la simulation
        */
        void parametrerEtat();

        /**
        * \brief Parametre les Etats de la simulation
        */
        void parametrerDimensions();

        /**
        * \brief Parametre les Etats de la simulation
        */
        void parametrerVoisinage();

        /**
        * \brief Parametre les Etats de la simulation
        */
        void parametrerTransition();


        void creerSimulation();

        AUTOMATE_NP::Automate *getAutomate();

        size_t getMemoire();

        void setMemoire(size_t i);

        Simulateur(AUTOMATE_NP::Automate &a, RESEAU_NP::Reseau &start, std::string nom);
        /**
        * \brief Initialisation de l'état de départ du simulateur
        */
        void setEtatDepart(RESEAU_NP::Reseau e);

        /**
        * \brief Destructeur de la classe Simulateur
        */
        ~Simulateur() = default;

        void saveReseau();

    private:
        /**
        * \brief Charge une simulation placée en mémoire
        * \param save Sauvegarde a charger
        */
        void chargerConfiguration(std::string save);

        /**
        * \brief Charge une simulation placée en mémoire
        * \param nom nom de la sauvegarde
        */
        void saveConfig(std::string nom);
    };

}
#endif //CELLULUT_SIMULATEUR_H
