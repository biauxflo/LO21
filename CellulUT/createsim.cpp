#include "createsim.h"
#include "ui_createsim.h"
#include <QColor>

createSim::createSim(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::createSim)
{
    ui->setupUi(this);
    connect(ui->buttonBox,SIGNAL(clicked()),this,SLOT(ok_clicked));
}

createSim::~createSim()
{
    delete ui;
}
void createSim::golChecked(){
    if(ui->golChecked->isChecked()){
        choixEtat = 1;
    }
}
void createSim::langstonChecked(){
    if(ui->langstonChecked->isChecked()){
        choixEtat = 2;
    }
}
void createSim::brianChecked(){
    if(ui->brainChecked->isChecked()){
        choixEtat = 3;
    }
}
void createSim::griffeathChecked(){
    if(ui->griffithChecked->isChecked()){
        choixEtat = 4;
    }
}
void createSim::manuelEtat(){
    if(ui->manuelChecked->isChecked()){
        choixEtat = 5;
        if(ui->valeur1!=NULL&&ui->color1!=NULL){
            std::string valeurS1(ui->valeur1->toPlainText().toStdString());
            QString couleurS1(ui->color1->toPlainText());
            QColor *couleur1 = new QColor(couleurS1);
            ETAT_NP::Etat first(0,valeurS1, couleur1->rgb());
            createEtat[0]=first;
        }
        if(ui->valeur2!=NULL&&ui->color2!=NULL){
            std::string valeurS2(ui->valeur2->toPlainText().toStdString());
            QString couleurS2(ui->color2->toPlainText());
            QColor *couleur2 = new QColor(couleurS2);
            ETAT_NP::Etat second(1,valeurS2, couleur2->rgb());
            createEtat[1]=second;        }
        if(ui->valeur3!=NULL&&ui->color3!=NULL){
            std::string valeurS3(ui->valeur3->toPlainText().toStdString());
            QString couleurS3(ui->color3->toPlainText());
            QColor *couleur3 = new QColor(couleurS3);
            ETAT_NP::Etat third(2,valeurS3, couleur3->rgb());
            createEtat[2]=third;        }
        if(ui->valeur4!=NULL&&ui->color4!=NULL){
            std::string valeurS4(ui->valeur4->toPlainText().toStdString());
            QString couleurS4(ui->color4->toPlainText());
            QColor *couleur4 = new QColor(couleurS4);
            ETAT_NP::Etat forth(3,valeurS4, couleur4->rgb());
            createEtat[3]=forth;        }
        if(ui->valeur5!=NULL&&ui->color5!=NULL){
            std::string valeurS5(ui->valeur5->toPlainText().toStdString());
            QString couleurS5(ui->color5->toPlainText());
            QColor *couleur5 = new QColor(couleurS5);
            ETAT_NP::Etat fifth(4,valeurS5, couleur5->rgb());
            createEtat[4]=fifth;        }
        if(ui->valeur6!=NULL&&ui->color6!=NULL){
            std::string valeurS6(ui->valeur6->toPlainText().toStdString());
            QString couleurS6(ui->color6->toPlainText());
            QColor *couleur6 = new QColor(couleurS6);
            ETAT_NP::Etat sixth(5,valeurS6, couleur6->rgb());
            createEtat[5]=sixth;        }
        if(ui->valeur7!=NULL&&ui->color7!=NULL){
            std::string valeurS7(ui->valeur7->toPlainText().toStdString());
            QString couleurS7(ui->color7->toPlainText());
            QColor *couleur7 = new QColor(couleurS7);
            ETAT_NP::Etat seventh(6,valeurS7, couleur7->rgb());
            createEtat[6]=seventh;        }
        if(ui->valeur8!=NULL&&ui->color8!=NULL){
            std::string valeurS8(ui->valeur8->toPlainText().toStdString());
            QString couleurS8(ui->color8->toPlainText());
            QColor *couleur8 = new QColor(couleurS8);
            ETAT_NP::Etat eigth(7,valeurS8, couleur8->rgb());
            createEtat[7]=eigth;
        }
    }
}

void createSim::ok_clicked(){
    dimReseau=ui->dimBox->value();
}
