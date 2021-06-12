#include <QApplication>
#include <iostream>
#include "Automate.h"
#include "GameLifeTransition.h"
#include "Newmann.h"
#include "Arbitraire.h"
#include <windows.h>

    void sleep(unsigned milliseconds)
    {
        Sleep(milliseconds);
    }


int main(int argc, char *argv[])
{
    //QApplication a(argc, argv);
    RESEAU_NP::Reseau* r = new RESEAU_NP::Reseau(50,50,0);

    for (unsigned int i = 0; i < r->getLongueur(); i++) {
        std::cout<<"|";
        for (unsigned int j = 0; j < r->getLargeur(); j++) {
            int randomnb = rand()%2;
            r->getCellule(i,j).getEtat().setIndice(randomnb);
            if(randomnb == 0) r->getCellule(i,j).getEtat().setLabel("dead");
           // if(randomnb == 1) r->getCellule(i,j).getEtat().setLabel("excited");
            else r->getCellule(i,j).getEtat().setLabel("alive");
            std::cout<<r->getCellule(i,j).getEtat().getIndice()<<"|";
        }
        std::cout<<"\n";
    }

    GameLifeTransition* rt = new GameLifeTransition;
   // BrianBrainTransition* rt = new BrianBrainTransition;

    std::vector<CELLULE_NP::Cellule*> voisins;
    voisins.push_back(&r->getCellule(10,27));
    voisins.push_back(&r->getCellule(22,27));
    voisins.push_back(&r->getCellule(33,44));
    voisins.push_back(&r->getCellule(42,11));
    voisins.push_back(&r->getCellule(22,0));
    voisins.push_back(&r->getCellule(1,47));
    //Neumann* v= new Neumann;
    Arbitraire* v = new Arbitraire(6, r->getCellule(11,27), voisins);
    //Moore* v = new Moore;
    // DEBUG, ON NE DEVRA PAS FAIRE COMME CA =>
    AUTOMATE_NP::Automate::setAutomate(r,2,v,rt);

    ETAT_NP::Etat* e1 = new ETAT_NP::Etat(0, "dead", QColor("black"));
    ETAT_NP::Etat* e2 = new ETAT_NP::Etat(1, "alive", QColor("white"));
    /*ETAT_NP::Etat* e1 = new ETAT_NP::Etat(0, "resting", QColor("green"));
    ETAT_NP::Etat* e2 = new ETAT_NP::Etat(1, "excited", QColor("red"));
    ETAT_NP::Etat* e3 = new ETAT_NP::Etat(2, "refractory", QColor("yellow"));*/
    std::vector<ETAT_NP::Etat*> es;
    es.push_back(e1);
    es.push_back(e2);
   // es.push_back(e3);
    AUTOMATE_NP::Automate& automate = AUTOMATE_NP::Automate::getAutomate();
    automate.setEtats(2, es);

    //Boucle qui print le label de l'etat de chaque cellule dans une matrice sous la forme "|0|1|1|0|0|..."
   /* for(int k = 0; k < 10; k++){
        for (unsigned int i = 0; i <automate.getReseau().getLongueur(); i++) {
            std::cout<<"|";
            for (unsigned int j = 0; j <automate.getReseau().getLargeur(); j++) {
                std::cout << automate.getReseau().getCellule(i,j).getEtat().getIndice() << "|";
            }
            std::cout<<"\n";
        }
    }*/

    for(int cpt = 0; cpt < 100; cpt++){
       // std::cout << "\nITERATION " << cpt << "\n\n";
        automate.calculerTransition();
        //Boucle qui print le label de l'etat de chaque cellule dans une matrice sous la forme "|0|1|1|0|0|..."
            for (unsigned int i = 0; i <automate.getReseau().getLongueur(); i++) {
                std::cout<<"|";
                for (unsigned int j = 0; j <automate.getReseau().getLargeur(); j++) {
                    if(automate.getReseau().getCellule(i,j).getEtat().getIndice() == 1) std::cout << "*|";
                    else std::cout << " |";
                }
                std::cout<<"\n";
            }
        sleep(300);
        std::cout << "\n\n\n\n\n\n";
    }

   // return a.exec();
    return 0;
}
