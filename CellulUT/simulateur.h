#ifndef CELLULUT_SIMULATEUR_H
#define CELLULUT_SIMULATEUR_H

#include <string>
#include <iostream>
#include "etat.h"
#include "automate.h"
/**
* \class Simulateur
* \brief Gestion de la simulation globale (etats, transitions)
*/
namespace SIMULATEUR_NP {
    class Simulateur {
        AUTOMATE_NP::Automate &automate; /*!< Automate de la simulation*/
        RESEAU_NP::Reseau *depart; /*!< Reseau de départ de la simulation*/
        Voisinage &voisinage;/*!< Voisinage de la simulation*/
        Transition &transition;/*!Fonction de transition de la simulation*/
        bool modeAutomatique=false;/*!< Booleen de selection (mode automatique ou pas à pas)*/
        size_t memoire;/*!< Nombre d'étape de la simulation à garder en mémoire*/
        size_t pasDeTemps;/*!< Pas pour l'execution du mode automatique*/
        std::string titre;/*!< Titre de la simulation*/
        std::string description;/*!< Description de la simulation*/
        size_t annee;/*!< Année de la simulation*/
        std::string auteur;/*!< Auteur de la simulation*/
        RESEAU_NP::Reseau* save= nullptr;/*!< Sauvegarde des x derniers etats*/

    public:
        /**
        * \brief Constructeur de la classe Simulateur
        * \param a Automate
        */
        Simulateur(AUTOMATE_NP::Automate &a);

        Simulateur(AUTOMATE_NP::Automate &a, std::string auteur, std::string titre, std::string desc);
        /**
        * \brief Constructeur de la classe Simulateur avec état de départ
        * \param a Automate
        * \param start Reseau de départ
        */
        Simulateur(AUTOMATE_NP::Automate &a, RESEAU_NP::Reseau &start);
        Simulateur(AUTOMATE_NP::Automate &a, RESEAU_NP::Reseau &start, std::string auteur, std::string titre, std::string desc);
        /**
        * \brief Initialisation de l'état de départ du simulateur
        */
        void setEtatDepart(RESEAU_NP::Reseau &e);

        /**
        * \brief Lance la simulation.
        */
        void run();

        /**
        * \brief Revenir à l'état de départ
        */
        void reset();

        /**
        * \brief Destructeur de la classe Simulateur
        */
        ~Simulateur();

        /**
        * \brief Parametre la simulation
        */
        void parametrer();

        /**
        * \brief Arrête la simulation
        */
        void stop();

        /**
        * \brief Met la simulation en mode automatique sans limite de temps
        */
        void setAuto();

        /**
        * \brief Met la simulation en mode pas à pas
        */
        void setStepByStep();

        void setPasDeTemps(size_t t);

        void setMemoire(size_t mem);

        size_t getMemoire();

        size_t getPasDeTemps();

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
