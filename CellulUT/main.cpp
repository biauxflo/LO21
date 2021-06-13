#include <QApplication>
#include <iostream>
#include "Automate.h"
#include "GameLifeTransition.h"
#include "Newmann.h"
#include "Arbitraire.h"
#include "fenetrejeu.h"
#include "menucreation.h"

int main(int argc, char *argv[])
{
    /* AUTOMATE PAR DEFAUT */

    RESEAU_NP::Reseau* r = new RESEAU_NP::Reseau(4,4,0);
    GameLifeTransition* rt = new GameLifeTransition;
    Moore* v = new Moore;
    AUTOMATE_NP::Automate::setAutomate(r,2,v,rt);

    ETAT_NP::Etat* e1 = new ETAT_NP::Etat(0, "dead", QColor("black").rgb());
    ETAT_NP::Etat* e2 = new ETAT_NP::Etat(1, "alive", QColor("white").rgb());
    std::vector<ETAT_NP::Etat*> es;
    es.push_back(e1);
    es.push_back(e2);
    AUTOMATE_NP::Automate& automate = AUTOMATE_NP::Automate::getAutomate();
    automate.setEtats(2, es);

    //QApplication a(argc, argv);

    //MenuCreation menu;
    //menu.show();

    for (unsigned int i = 0; i < r->getLongueur(); i++) {
        for (unsigned int j = 0; j < r->getLargeur(); j++) {
            int randomnb = rand()%2;
            r->getCellule(i,j).getEtat().setIndice(randomnb);
            if(randomnb == 0) r->getCellule(i,j).getEtat().setLabel("dead");
            else r->getCellule(i,j).getEtat().setLabel("alive");
        }
    }

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
            //sleep(300);
            std::cout << "\n\n\n\n\n\n";
    }

    return 0;
   //return a.exec();
}
