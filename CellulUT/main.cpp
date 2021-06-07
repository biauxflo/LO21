#include <QApplication>
#include <iostream>
#include "Automate.h"
#include "GameLifeTransition.h"
#include "Newmann.h"

int main(int argc, char *argv[])
{
    //QApplication a(argc, argv);
    std::cout << "test";
    RESEAU_NP::Reseau* r = new RESEAU_NP::Reseau(10,10,0);
    GameLifeTransition* rt = new GameLifeTransition;
    Neumann* v = new Neumann;
    // DEBUG, ON NE DEVRA PAS FAIRE COMME CA =>
    AUTOMATE_NP::Automate::setAutomate(r,2,v,rt);
    auto& automate = AUTOMATE_NP::Automate::getAutomate();
    //Boucle qui print le label de l'etat de chaque cellule dans une matrice sous la forme "|0|1|1|0|0|..."
    for (unsigned int i = 0; i <automate.getReseau().getLongueur(); i++) {
        std::cout<<"|";
        for (unsigned int j = 0; i<automate.getReseau().getLargeur(); j++) {
            std::cout << automate.getReseau().getCellule(i,j).getEtat().getIndice()<<"|";
        }
        std::cout<<"\n";
    }
   // return a.exec();
    return 0;
}
