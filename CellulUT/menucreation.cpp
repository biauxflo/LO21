#include "menucreation.h"
#include "ui_menucreation.h"
#include "popuploadmodele.h"
#include "simload.h"
#include "createsim.h"

MenuCreation::MenuCreation(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MenuCreation)
{
    ui->setupUi(this);
    connect(ui->createSim,SIGNAL(clicked()),this,SLOT(creerSim()));
    connect(ui->loadSim,SIGNAL(clicked()),this,SLOT(loadSim()));
    connect(ui->loadModele,SIGNAL(clicked()),this,SLOT(loadModele()));
    choixMenu=0;
}

MenuCreation::~MenuCreation()
{
    delete ui;
}

void MenuCreation::creerSim(){
    createSim simcreate;
    simcreate.exec();
    choixMenu=3;
}

void MenuCreation::loadModele(){
    popUpLoadModele popup;
    popup.exec();
    choixModele = popup.getchoixModele();
    choixMenu=2;
}

void MenuCreation::loadSim(){
    simLoad simload;
    simload.exec();
    filename=simload.getFilename();
    choixMenu=1;
}
