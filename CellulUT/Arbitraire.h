//
// Created by Amelie Pelle on 29/05/2021.
//

#ifndef CELLULUT_ARBITRAIRE_H
#define CELLULUT_ARBITRAIRE_H

#include "Voisinage.h"

/**
* \class Arbitraire
* \brief Classe heritant de Voisinage, gere les voisinages arbitraires
*/
class Arbitraire : public Voisinage {
private:
    unsigned int nbvoisins; /*!< nombre de voisins*/
    CELLULE_NP::Cellule& cell; /*!< cell : cellule choisie pour calculer le voisinage*/
    CELLULE_NP::Cellule * voisins; /*!< tableau de cellules contenant les voisins de cell*/
public:
    /**
    * \brief Constructeur de la classe Arbitraire
     * \param nbvois nombre de voisins de la cellule
     * \param cellule cellule dont on a choisit arbitrairement le voisinage
     * \param voisinage tableau contenant les cellules du voisinage
     */
    explicit Arbitraire(unsigned int nbvois, CELLULE_NP::Cellule& cellule, CELLULE_NP::Cellule * voisinage = nullptr) : nbvoisins(nbvois), cell(cellule) {
        voisins = voisinage;
    }
    /**
     * \brief methode qui calcule la distance a ajouter a l abscisse de la cellule pour obtenir celles des voisins
     * @return tableau contenant les distances a la cellule (pour l abscisse) de chaque voisin
     */
    unsigned int * calculerDistanceAbscisse() const {
        auto * abscisses = new unsigned int;
        for(unsigned int i = 0; i <= nbvoisins; i++){
            int distance_abscisse = cell.getAbscisse() - voisins[i].getAbscisse();
            abscisses[i] = distance_abscisse;
        }
        return abscisses;

    }
    /**
     * \brief methode qui calcule la distance a ajouter a l ordonee de la cellule pour obtenir celles des voisins
     * @return tableau contenant les distances a la cellule (pour l ordonnee) de chaque voisin
     */
    unsigned int* calculerDistanceOrdonnee() const{
        auto * ordonnees = new unsigned int;
        for(unsigned int i = 0; i <= nbvoisins; i++){
            int distance_ordonnee = cell.getOrdonnee() - voisins[i].getOrdonnee();
            ordonnees[i] = distance_ordonnee;
        }
        return ordonnees;
    }
    /**
    * \brief surcharge de la methode calculerVoisinage
     */
    CELLULE_NP::Cellule * calculerVoisinage(CELLULE_NP::Cellule tab[], CELLULE_NP::Cellule** reseau, unsigned int x, unsigned int y, unsigned int largeur, unsigned int longueur) const override;
    /**
    * \brief getter pour le nombre de voisins
    */
    unsigned int getNbCellulesVoisines() const override {return nbvoisins;}

    /**
    * \brief Destructeur de la classe VoisinageARayon
    */

    ~Arbitraire() override {
        delete [] voisins;
    }

};

#endif //CELLULUT_ARBITRAIRE_H

