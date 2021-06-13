#include "fenetrejeu.h"
#include "ui_fenetrejeu.h"
#include <QMainWindow>
#include <QTimer>
#include <QtDebug>
#include <QGraphicsSceneMouseEvent>
#include "GraphAutomate.h"
#include "Automate.h"
#include "Simulateur.h"
#include "Reseau.h"

FenetreJeu::FenetreJeu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FenetreJeu)
{
    ui->setupUi(this);
    viewResolutionLargeur = 900; // resolution of the view - depends on GraphicScene!
    viewResolutionLongueur = 600;
    scene = new GraphAutomate(this);
    ui->graphicsView->setScene(scene);
    simulation->creerSimulation();
    scene->printAutomate(&simulation->getAutomate()->getReseau());
}

FenetreJeu::~FenetreJeu()
{
    delete ui;
}

void FenetreJeu::activerCellule(size_t x, size_t y)
{
    if(x > simulation->getAutomate()->getReseau().getLargeur() * (viewResolutionLargeur / simulation->getAutomate()->getReseau().getLargeur())
            || y > simulation->getAutomate()->getReseau().getLargeur() * (viewResolutionLongueur / simulation->getAutomate()->getReseau().getLargeur())) return;

    size_t cellLargeur = viewResolutionLargeur / simulation->getAutomate()->getReseau().getLargeur();
    size_t cellLongueur = viewResolutionLongueur /  simulation->getAutomate()->getReseau().getLongueur();
    size_t index = (y/cellLargeur) * simulation->getAutomate()->getReseau().getLargeur() + (x/cellLongueur);
    if(index < simulation->getAutomate()->getReseau().getLargeur() * simulation->getAutomate()->getReseau().getLargeur()){
        simulation->getAutomate()->getReseau().getCellule(x/cellLargeur,y/cellLongueur).getEtat().augmenterIndice();//augmente l'indice au click
        scene->printAutomate(&simulation->getAutomate()->getReseau());
    }
}

void FenetreJeu::loadButton_clicked()
{

}

void FenetreJeu::saveButton_clicked()
{

}

void FenetreJeu::playButton_clicked()
{
    qDebug() << "playLoop clicked";
    if(loopPause){
        loopPause = false;
    } else {
        if(!loopActive){
            qDebug() << "checked: loop not active";
        }
    }
}

void FenetreJeu::pauseButton_clicked()
{
    loopPause = !loopPause;
}

void FenetreJeu::resetButton_clicked(){

}

void FenetreJeu::stopButton_clicked(){

}
void FenetreJeu::backButton_clicked()
{
    simulation->back();
    scene->printAutomate(&simulation->getAutomate()->getReseau());
}

void FenetreJeu::nextButton_clicked()
{
    simulation->next();
    scene->printAutomate(&simulation->getAutomate()->getReseau());
}
