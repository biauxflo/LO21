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
    scene->printAutomate(simulation->getAutomate()->getReseau());
    connect(ui->playButton,SIGNAL(clicked()),this,SLOT(playButton_clicked()));
    connect(ui->pauseButton,SIGNAL(clicked()),this,SLOT(pauseButton_clicked()));
    connect(ui->stopButton,SIGNAL(clicked()),this,SLOT(stopButton_clicked()));
    connect(ui->nextButton,SIGNAL(clicked()),this,SLOT(nextButton_clicked()));
    //connect(ui->backButton,SIGNAL(clicked()),this,SLOT(backButton_clicked()));
    connect(ui->resetButton,SIGNAL(clicked()),this,SLOT(resetButton_clicked()));
    connect(timer,SIGNAL(timeout()),this,SLOT(execute()));
    connect(ui->randomButton,SIGNAL(clicked()),this,SLOT(randomize()));
    connect(ui->config,SIGNAL(clicked()),this,SLOT(config()));
    connect(ui->pasbox, QOverload<int>::of(&QSpinBox::valueChanged),
        [=](int i){ timer->stop();timer->start(i);});

}

FenetreJeu::~FenetreJeu()
{
    delete ui;
}

void FenetreJeu::activerCellule(size_t x, size_t y)
{
    if(x > automate.getReseau()->getLargeur() * (viewResolutionLargeur /automate.getReseau()->getLargeur())
            || y > automate.getReseau()->getLargeur() * (viewResolutionLongueur / automate.getReseau()->getLargeur())) return;

    size_t cellLargeur = viewResolutionLargeur / automate.getReseau()->getLargeur();
    size_t cellLongueur = viewResolutionLongueur /  automate.getReseau()->getLongueur();
    size_t index = (y/cellLargeur) * automate.getReseau()->getLargeur() + (x/cellLongueur);
    if(index < automate.getReseau()->getLargeur() * automate.getReseau()->getLargeur()){
        size_t indice=automate.getReseau()->getCellule(x/cellLargeur,y/cellLongueur).getEtat().getIndice();
        if (indice==automate.getNbEtats())
        {indice=0;}
        automate.getReseau()->getCellule(x/cellLargeur,y/cellLongueur).setEtat(*automate.getEtat(indice));//augmente l'indice au click
        scene->printAutomate(automate.getReseau());
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
    scene->printAutomate(simulation->getAutomate()->getReseau());
}

void FenetreJeu::stopButton_clicked(){
    loopPause=false;
    loopActive=false;
    timer->stop();
    resetButton_clicked();
}
void FenetreJeu::backButton_clicked()
{
    //simulation->back();
    scene->printAutomate(simulation->getAutomate()->getReseau());
}

void FenetreJeu::nextButton_clicked()
{
    execute();
    simulation->next();
    scene->printAutomate(simulation->getAutomate()->getReseau());
}

void FenetreJeu::spinbox_textchanged(){
    timer->stop();
    timer->start(ui->pasbox->value());
}

void FenetreJeu::execute(){
    if (loopActive && !loopPause){
        simulation->next();
        scene->printAutomate(simulation->getAutomate()->getReseau());
    }
}

void FenetreJeu::randomize(){
    RESEAU_NP::Reseau* r = automate.getReseau();
    for (unsigned int i = 0; i < r->getLongueur(); i++) {
        for (unsigned int j = 0; j < r->getLargeur(); j++) {
            int randomnb = rand()%automate.getNbEtats();
            r->getCellule(i,j).setEtat(*AUTOMATE_NP::Automate::getAutomate().getEtat(randomnb));
        }
    }
    simulation->setEtatDepart(AUTOMATE_NP::Automate::getAutomate().getReseau());
    scene->printAutomate(AUTOMATE_NP::Automate::getAutomate().getReseau());
}

void FenetreJeu::config(){
        MenuCreation *menu = new MenuCreation();
        menu->show();
        if (menu->getChoixMenu()==1){
            QString file = menu->getFilename();
            //Lecture de la sauvegarde
        }else if (menu->getChoixMenu()==2){
            QString filename;
            if (menu->getChoixModele()==1){
<<<<<<< HEAD
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
            }else if(menu->getChoixModele()==2){
                //Pas encore implémenté
            }else if(menu->getChoixModele()==3){
                RESEAU_NP::Reseau* r = new RESEAU_NP::Reseau(10,10,0);
                BrianBrainTransition* bt = new BrianBrainTransition;
                Moore* v = new Moore;
                AUTOMATE_NP::Automate::setAutomate(r,3,v,bt);
                ETAT_NP::Etat* e1 = new ETAT_NP::Etat(0, "resting", QColor("green").rgb());
                ETAT_NP::Etat* e2 = new ETAT_NP::Etat(1, "excited", QColor("red").rgb());
                ETAT_NP::Etat* e3 = new ETAT_NP::Etat(2, "refractory", QColor("jaune").rgb());
                std::vector<ETAT_NP::Etat*> es;
                es.push_back(e1);
                es.push_back(e2);
                es.push_back(e3);
                AUTOMATE_NP::Automate& automate = AUTOMATE_NP::Automate::getAutomate();
                automate.setEtats(3,es);
=======
                filename = "modeles\\gamelife.xml";
            }else if(menu->getChoixModele()==2){
                //filename("modeles\\griffeath.xml";
            }else if(menu->getChoixModele()==3){
                filename = "modeles\\brianbrain.xml";
>>>>>>> abdda4e1396e030cc87e3d4d128cc444a1af91cf
            }else if(menu->getChoixModele()==4){
                filename = "modeles\\griffeath.xml";
            }
            QFile file(filename);
            QXmlStreamReader * xml = new QXmlStreamReader(&file);
            automate.appliquerConfiguration(xml);
            file.close();
        }else if (menu->getChoixMenu()==3){

        }
}
