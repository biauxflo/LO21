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
    simulation->creerSimulation();
    scene->printAutomate(&simulation->getAutomate()->getReseau());
    connect(ui->playButton,SIGNAL(on_click()),this,SLOT(playButton_clicked()));
    connect(ui->pauseButton,SIGNAL(on_click()),this,SLOT(pauseButton_clicked()));
    connect(ui->stopButton,SIGNAL(on_click()),this,SLOT(stopButton_clicked()));
    connect(ui->nextButton,SIGNAL(on_click()),this,SLOT(nextButton_clicked()));
    connect(ui->backButton,SIGNAL(on_click()),this,SLOT(backButton_clicked()));
    connect(ui->resetButton,SIGNAL(on_click()),this,SLOT(resetButton_clicked()));
    connect(ui->pasbox,SIGNAL(valueChanged()),this,SLOT(spinbox_textchanged()));
    connect(timer,SIGNAL(timeout()),this,SLOT(execute()));
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
void FenetreJeu::playButton_clicked()
{
    if (auto_checked()){
        loopActive = true;
        if (loopPause){loopPause=false;}
        else{
            execute();
            timer->start(ui->pasbox->value());
        }
    }else{
            execute();
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
}
void FenetreJeu::backButton_clicked()
{
    simulation->back();
    scene->printAutomate(&simulation->getAutomate()->getReseau());
}

void FenetreJeu::nextButton_clicked()
{
    execute();
}
bool FenetreJeu::auto_checked(){
    return ui->autoRadio->isChecked();
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
