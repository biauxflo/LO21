#include <QApplication>
#include <iostream>
#include "Automate.h"
#include "GameLifeTransition.h"
#include "Newmann.h"



int main(int argc, char *argv[])
{
    //QApplication a(argc, argv);
    RESEAU_NP::Reseau* r = new RESEAU_NP::Reseau(10,10,0);

    for (unsigned int i = 0; i < r->getLongueur(); i++) {
        std::cout<<"|";
        for (unsigned int j = 0; j < r->getLargeur(); j++) {
            int randomnb = rand()%2;
            r->getCellule(i,j).getEtat().setIndice(randomnb);
            if(randomnb == 0) r->getCellule(i,j).getEtat().setLabel("dead");
            else r->getCellule(i,j).getEtat().setLabel("alive");
            std::cout<<r->getCellule(i,j).getEtat().getIndice()<<"|";
        }
        std::cout<<"\n";
    }

    GameLifeTransition* rt = new GameLifeTransition;
    Neumann* v = new Neumann;
    // DEBUG, ON NE DEVRA PAS FAIRE COMME CA =>
    AUTOMATE_NP::Automate::setAutomate(r,2,v,rt);

    ETAT_NP::Etat* e1 = new ETAT_NP::Etat(0, "dead");
    ETAT_NP::Etat* e2 = new ETAT_NP::Etat(1, "alive");
    std::vector<ETAT_NP::Etat*> es;
    es.push_back(e1);
    es.push_back(e2);
    AUTOMATE_NP::Automate& automate = AUTOMATE_NP::Automate::getAutomate();
    automate.setEtats(2, es);

    //Boucle qui print le label de l'etat de chaque cellule dans une matrice sous la forme "|0|1|1|0|0|..."
    for(int k = 0; k < 10; k++){
        for (unsigned int i = 0; i <automate.getReseau().getLongueur(); i++) {
            std::cout<<"|";
            for (unsigned int j = 0; j <automate.getReseau().getLargeur(); j++) {
                std::cout << automate.getReseau().getCellule(i,j).getEtat().getIndice() << "|";
            }
            std::cout<<"\n";
        }
    }

    for(int cpt = 0; cpt < 10; cpt++){
        std::cout << "\nITERATION " << cpt << "\n\n";
        automate.calculerTransition();
        //Boucle qui print le label de l'etat de chaque cellule dans une matrice sous la forme "|0|1|1|0|0|..."
            for (unsigned int i = 0; i <automate.getReseau().getLongueur(); i++) {
                std::cout<<"|";
                for (unsigned int j = 0; j <automate.getReseau().getLargeur(); j++) {
                    std::cout << automate.getReseau().getCellule(i,j).getEtat().getIndice() << "|";
                }
                std::cout<<"\n";
            }
        std::cout << "\n\n\n\n";
    }

   // return a.exec();
    return 0;
}
