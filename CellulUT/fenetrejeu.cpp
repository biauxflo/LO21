#include "fenetrejeu.h"
#include "ui_fenetrejeu.h"
#include <QMainWindow>
#include <QTimer>
#include <QtDebug>
#include <QGraphicsSceneMouseEvent>
#include "GraphAutomate.h"
#include "Automate.h"
#include "simulateur.h"
#include "Reseau.h"

FenetreJeu::FenetreJeu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FenetreJeu)
{
    ui->setupUi(this);
    timer=new QTimer();
    viewResolutionLargeur = 900; // resolution of the view - depends on GraphicScene!
    viewResolutionLongueur = 600;
    scene = new GraphAutomate(this);
    ui->graphicsView->setScene(scene);
    simulation = new SIMULATEUR_NP::Simulateur(automate, *automate.getVoisinage(), *automate.getTransition());
    simulation->creerSimulation();
    scene->printAutomate(&simulation->getAutomate()->getReseau());
    connect(ui->playButton,SIGNAL(clicked()),this,SLOT(playButton_clicked()));
    connect(ui->pauseButton,SIGNAL(clicked()),this,SLOT(pauseButton_clicked()));
    connect(ui->stopButton,SIGNAL(clicked()),this,SLOT(stopButton_clicked()));
    connect(ui->nextButton,SIGNAL(clicked()),this,SLOT(nextButton_clicked()));
    connect(ui->backButton,SIGNAL(clicked()),this,SLOT(backButton_clicked()));
    connect(ui->resetButton,SIGNAL(clicked()),this,SLOT(resetButton_clicked()));
    connect(ui->pasbox,SIGNAL(valueChanged(int i)),this,SLOT(spinbox_textchanged()));
    connect(timer,SIGNAL(timeout()),this,SLOT(execute()));
}

FenetreJeu::~FenetreJeu()
{
    delete ui;
}

void FenetreJeu::activerCellule(int x, int y)
{
    if(x > simulation->getAutomate()->getReseau().getLargeur() * (viewResolutionLargeur / simulation->getAutomate()->getReseau().getLargeur())
            || y > simulation->getAutomate()->getReseau().getLargeur() * (viewResolutionLongueur / simulation->getAutomate()->getReseau().getLargeur())) return;

    size_t cellLargeur = viewResolutionLargeur / simulation->getAutomate()->getReseau().getLargeur();
    size_t cellLongueur = viewResolutionLongueur /  simulation->getAutomate()->getReseau().getLongueur();
    size_t index = (y/cellLargeur) * simulation->getAutomate()->getReseau().getLargeur() + (x/cellLongueur);
    if(index < simulation->getAutomate()->getReseau().getLargeur() * simulation->getAutomate()->getReseau().getLargeur()){
        size_t indice=simulation->getAutomate()->getReseau().getCellule(x/cellLargeur,y/cellLongueur).getEtat().getIndice();
        if (indice==automate.getNbEtats())
        {indice=0;}
        simulation->getAutomate()->getReseau().getCellule(x/cellLargeur,y/cellLongueur).setEtat(*automate.getEtat(indice));//augmente l'indice au click
        scene->printAutomate(&simulation->getAutomate()->getReseau());
    }
}
void FenetreJeu::playButton_clicked()
{
        loopActive = true;
        if (loopPause){loopPause=false;}
        else{
            execute();
            timer->start(ui->pasbox->value());
        }
}

void FenetreJeu::pauseButton_clicked()
{
    loopPause = !loopPause;
}

void FenetreJeu::resetButton_clicked(){
    simulation->reset();
}

void FenetreJeu::stopButton_clicked(){
    loopPause=false;
    loopActive=false;
    timer->stop();
    resetButton_clicked();
}
void FenetreJeu::backButton_clicked()
{
    simulation->back();
    scene->printAutomate(&simulation->getAutomate()->getReseau());
}

void FenetreJeu::nextButton_clicked()
{
    execute();
    simulation->next();
    scene->printAutomate(&simulation->getAutomate()->getReseau());
}

void FenetreJeu::spinbox_textchanged(){
    timer->stop();
    timer->start(ui->pasbox->value());
}

void FenetreJeu::execute(){
    if (loopActive && !loopPause){
        printf("je me suis execute\n");
        simulation->next();
        scene->printAutomate(&simulation->getAutomate()->getReseau());
    }
}
