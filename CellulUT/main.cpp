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

    RESEAU_NP::Reseau* r = new RESEAU_NP::Reseau(10,10,0);
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

    QApplication a(argc, argv);

    FenetreJeu jeu;
    jeu.show();

    return a.exec();
}
