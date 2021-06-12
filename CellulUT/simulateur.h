#ifndef CELLULUT_SIMULATEUR_H
#define CELLULUT_SIMULATEUR_H

#include <string>
#include <iostream>
#include <QtCore>
#include "Etat.h"
#include "Automate.h"
/**
* \class Simulateur
* \brief Gestion de la simulation globale (etats, transitions)
*/
namespace SIMULATEUR_NP {
    class Simulateur : public QObject {
        Q_OBJECT;
        AUTOMATE_NP::Automate &automate; /*!< Automate de la simulation*/
        RESEAU_NP::Reseau *depart; /*!< Reseau de départ de la simulation*/
        RESEAU_NP::Reseau* save= nullptr;/*!< Sauvegarde des x derniers etats*/
        Voisinage &voisinage;/*!< Voisinage de la simulation*/
        Transition &transition;/*!Fonction de transition de la simulation*/

        bool modeAutomatique=false;/*!< Booleen de selection (mode automatique ou pas à pas)*/
        bool boucleActive=false;
        size_t indexMem;
        size_t memoire;/*!< Nombre d'étape de la simulation à garder en mémoire*/
        size_t pasDeTemps;/*!< Pas pour l'execution du mode automatique*/
        std::string titre;/*!< Titre de la simulation*/

        QTimer *timer;

    public slots :
        void mySlots();


    public:

        Simulateur(AUTOMATE_NP::Automate &a, RESEAU_NP::Reseau &start, std::string titre);
        /**
        * \brief Initialisation de l'état de départ du simulateur
        */
        void setEtatDepart(RESEAU_NP::Reseau &e);

        /**
        * \brief Lance la simulation.
        */
        void run();

        void next();

        void back();

        /**
        * \brief Revenir à l'état de départ
        */
        void reset();

        /**
        * \brief Destructeur de la classe Simulateur
        */
        ~Simulateur();

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

        /**
        * \brief Arrête la simulation
        */
        void stop();

        /**
        * \brief Met la simulation en mode automatique sans limite de temps
        */
        void setAuto();
        /**
        * \brief Met la simulation en pause
        */
        void pause();

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
