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
class Simulateur {
    const Automate& automate; /*!< Automate de la simulation*/
    Etat** etats; /*!< Ensemble des états du simulateur*/
    const Etat* depart; /*!< Etat de départ du simulateur*/
    const size_t nbMaxEtats; /*!< Taille du buffer*/
    size_t rang; /*!< Rang du dernier état généré*/
    boolean modeAutomatique;/*!< Booleen de selection (mode automatique ou pas à pas)*/
    size_t pasDeTemps;/*!< Pas pour l'execution du mode automatique*/
    string titre;/*!< Titre de la simulation*/
    string description;/*!< Description de la simulation*/
    size_t annee;/*!< Année de la simulation*/
    string auteur;/*!< Auteur de la simulation*/
    /**
    * \brief Création d'un état à l'indice indiqué
    * \param c Indice considéré
    */
    void build(size_t c);
    /**
    * \brief Constructeur par recopie de la classe simulateur
    * \param s Simulateur à recopier
    */
    Simulateur(const Simulateur& s);
    /**
    * \brief Surcharge de l'opérateur d'affectation
     * \param s Simulateur à affecter
     * \return Simulateur
     */
    Simulateur& operator=(const Simulateur& s)=false;
public:
    /**
    * \brief Constructeur de la classe Simulateur
    * \param a Automate
    * \param buffer Buffer
    */
    Simulateur(const Automate& a,size_t buffer=2);
    /**
    * \brief Constructeur de la classe Simulateur avec état de départ
    * \param a Automate
    * \param start Etat de départ
    * \param buffer Buffer
    */
    Simulateur(const Automate& a, const Etat& start, size_t buffer=2);
    /**
    * \brief Initialisation de l'état de départ du simulateur
    */
    void setEtatDepart(const Etat& e);
    /**
    * \brief Génère un certain nombre d'états.
    */
    void run(size_t nbSteps);
    /**
    * \brief Génère le prochain état
    */
    void next();
    /**
    * \brief Retourne le dernier état généré
    * \return Dernier état généré
    */
    const Etat& last() const;
    /**
    * \brief Retourne le rang du dernier état généré
    * \return rang du dernier état généré
    */
    size_t getRangDernier() const { return rang; }
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
    * \brief Lance la simulation
    */
    void play();
    /**
    * \brief Met la simulation en pause
    */
    void pause();
    /**
    * \brief Arrête la simulation
    */
    void stop();
    /**
    * \brief Met la simulation en mode automatique sans limite de temps
    */
     void setAuto();
    /**
    * \brief Met la simulation en mode automatique
    * \param temps Temps d'execution
    */
    void setAuto(size_t temps);
    /**
    * \brief Met la simulation en mode pas à pas
    */
    void setStepByStep();
private:
    /**
    * \brief Charge une simulation placée en mémoire
    * \param save Sauvegarde a charger
    */
    void chargerConfiguration(string save);
};

#endif
#endif //CELLULUT_SIMULATEUR_H
