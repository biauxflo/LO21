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

    AUTOMATE_NP::Automate* automate = new AUTOMATE_NP::Automate(r, 2, v, rt);
   // return a.exec();
    return 0;
}
