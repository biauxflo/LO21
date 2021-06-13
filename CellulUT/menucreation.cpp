#include "menucreation.h"
#include "ui_menucreation.h"
#include "popuploadmodele.h"

MenuCreation::MenuCreation(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MenuCreation)
{
    ui->setupUi(this);
    connect(ui->createSim,SIGNAL(clicked()),this,SLOT(createSim()));
    connect(ui->loadSim,SIGNAL(clicked()),this,SLOT(loadSim()));
    connect(ui->loadModele,SIGNAL(clicked()),this,SLOT(loadModele()));
}

MenuCreation::~MenuCreation()
{
    delete ui;
}

void MenuCreation::createSim(){

}

void MenuCreation::loadModele(){
    popUpLoadModele popup;
    popup.exec();
}

void MenuCreation::loadSim(){

}
