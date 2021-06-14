#include "createsim.h"
#include "ui_createsim.h"
#include "GameLifeTransition.h"
#include "BrianBrainTransition.h"
#include "GriffeathTransition.h"
#include <QColor>
#include "Automate.h"

createSim::createSim(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::createSim)
{
    ui->setupUi(this);
}

createSim::~createSim()
{
    delete ui;
}

void createSim::accept()
{
    if(ui->golChecked->isChecked()){
        ETAT_NP::Etat* e1 = new ETAT_NP::Etat(0, "dead", QColor("black").rgb());
        ETAT_NP::Etat* e2 = new ETAT_NP::Etat(1, "alive", QColor("white").rgb());
        std::vector<ETAT_NP::Etat*> es;
        es.push_back(e1);
        es.push_back(e2);
        AUTOMATE_NP::Automate& automate = AUTOMATE_NP::Automate::getAutomate();
        automate.setEtats(2, es);

    }
    if(ui->brainChecked->isChecked()){
        ETAT_NP::Etat* e1 = new ETAT_NP::Etat(0, "resting", QColor("green").rgb());
        ETAT_NP::Etat* e2 = new ETAT_NP::Etat(1, "excited", QColor("red").rgb());
        ETAT_NP::Etat* e3 = new ETAT_NP::Etat(2, "refractory", QColor("jaune").rgb());
        std::vector<ETAT_NP::Etat*> es;
        es.push_back(e1);
        es.push_back(e2);
        es.push_back(e3);
        AUTOMATE_NP::Automate& automate = AUTOMATE_NP::Automate::getAutomate();
        automate.setEtats(3,es);
    }
    if(ui->griffithChecked->isChecked()){
        ETAT_NP::Etat* e1 = new ETAT_NP::Etat(0, "zero", QColor("yellow").rgb());
        ETAT_NP::Etat* e2 = new ETAT_NP::Etat(1, "one", QColor("orange").rgb());
        ETAT_NP::Etat* e3 = new ETAT_NP::Etat(2, "two", QColor("brown").rgb());
        ETAT_NP::Etat* e4 = new ETAT_NP::Etat(3, "three", QColor("red").rgb());
        std::vector<ETAT_NP::Etat*> es;
        es.push_back(e1);
        es.push_back(e2);
        es.push_back(e3);
        es.push_back(e4);
        AUTOMATE_NP::Automate& automate = AUTOMATE_NP::Automate::getAutomate();
        automate.setEtats(4,es);
   }if(ui->manuelChecked->isChecked()){
        std::vector<ETAT_NP::Etat*> es;
        int nbEtats = 0;
        if(ui->valeur1->toPlainText().toStdString()!=""&&ui->color1!=NULL){
            std::string valeurS1(ui->valeur1->toPlainText().toStdString());
            QString couleurS1(ui->color1->toPlainText());
            QColor *couleur1 = new QColor(couleurS1);
            ETAT_NP::Etat* first = new ETAT_NP::Etat(0,valeurS1, couleur1->rgb());
            nbEtats++;
            es.push_back(first);
        }
        if(ui->valeur2->toPlainText().toStdString()!=""&&ui->color2!=NULL){
            std::string valeurS2(ui->valeur2->toPlainText().toStdString());
            QString couleurS2(ui->color2->toPlainText());
            QColor *couleur2 = new QColor(couleurS2);
            ETAT_NP::Etat* second = new ETAT_NP::Etat(1,valeurS2, couleur2->rgb());
            nbEtats++;
            es.push_back(second);

        }
        if(ui->valeur3->toPlainText().toStdString()!=""&&ui->color3!=NULL){
            std::string valeurS3(ui->valeur3->toPlainText().toStdString());
            QString couleurS3(ui->color3->toPlainText());
            QColor *couleur3 = new QColor(couleurS3);
            ETAT_NP::Etat* third = new ETAT_NP::Etat(2,valeurS3, couleur3->rgb());
            nbEtats++;
            es.push_back(third);

        }
        if(ui->valeur4->toPlainText().toStdString()!=""&&ui->color4!=NULL){
            std::string valeurS4(ui->valeur4->toPlainText().toStdString());
            QString couleurS4(ui->color4->toPlainText());
            QColor *couleur4 = new QColor(couleurS4);
            ETAT_NP::Etat* forth = new ETAT_NP::Etat(3,valeurS4, couleur4->rgb());
            nbEtats++;
            es.push_back(forth);

        }
        if(ui->valeur5->toPlainText().toStdString()!=""&&ui->color5!=NULL){
            std::string valeurS5(ui->valeur5->toPlainText().toStdString());
            QString couleurS5(ui->color5->toPlainText());
            QColor *couleur5 = new QColor(couleurS5);
            ETAT_NP::Etat* fifth = new ETAT_NP::Etat(4,valeurS5, couleur5->rgb());
            nbEtats++;
            es.push_back(fifth);

        }
        if(ui->valeur6->toPlainText().toStdString()!=""&&ui->color6!=NULL){
            std::string valeurS6(ui->valeur6->toPlainText().toStdString());
            QString couleurS6(ui->color6->toPlainText());
            QColor *couleur6 = new QColor(couleurS6);
            ETAT_NP::Etat* sixth = new ETAT_NP::Etat(5,valeurS6, couleur6->rgb());
            nbEtats++;
            es.push_back(sixth);

        }
        if(ui->valeur7->toPlainText().toStdString()!=""&&ui->color7!=NULL){
            std::string valeurS7(ui->valeur7->toPlainText().toStdString());
            QString couleurS7(ui->color7->toPlainText());
            QColor *couleur7 = new QColor(couleurS7);
            ETAT_NP::Etat* seventh = new ETAT_NP::Etat(6,valeurS7, couleur7->rgb());
            nbEtats++;
            es.push_back(seventh);

        }
        if(ui->valeur8->toPlainText().toStdString()!=""&&ui->color8!=NULL){
            std::string valeurS8(ui->valeur8->toPlainText().toStdString());
            QString couleurS8(ui->color8->toPlainText());
            QColor *couleur8 = new QColor(couleurS8);
            ETAT_NP::Etat* eigth = new ETAT_NP::Etat(7,valeurS8, couleur8->rgb());
            nbEtats++;
            es.push_back(eigth);

        }
        AUTOMATE_NP::Automate& automate = AUTOMATE_NP::Automate::getAutomate();
        automate.setEtats(nbEtats,es);
    }if (ui->moore->isChecked()){
        Moore* v = new Moore;
        AUTOMATE_NP::Automate& automate = AUTOMATE_NP::Automate::getAutomate();
        automate.setVoisinage(v);
    }if (ui->moore2->isChecked()){
        MooreGeneral* v = new MooreGeneral(ui->rayonBox->value());
        AUTOMATE_NP::Automate& automate = AUTOMATE_NP::Automate::getAutomate();
        automate.setVoisinage(v);
    }if (ui->vonNeumann->isChecked()){
        Neumann* v = new Neumann;
        AUTOMATE_NP::Automate& automate = AUTOMATE_NP::Automate::getAutomate();
        automate.setVoisinage(v);
    }if (ui->moore2->isChecked()){
        NeumannGeneral* v = new NeumannGeneral(ui->rayonBox->value());
        AUTOMATE_NP::Automate& automate = AUTOMATE_NP::Automate::getAutomate();
        automate.setVoisinage(v);
    }if (ui->gol3->isChecked()){
        GameLifeTransition* gt = new GameLifeTransition;
        AUTOMATE_NP::Automate& automate = AUTOMATE_NP::Automate::getAutomate();
        automate.setTransition(gt);
    }if (ui->brain3->isChecked()){
        BrianBrainTransition* bt = new BrianBrainTransition;
        AUTOMATE_NP::Automate& automate = AUTOMATE_NP::Automate::getAutomate();
        automate.setTransition(bt);
    }if (ui->griffeath3->isChecked()){
        GriffeathTransition* gt = new GriffeathTransition;
        AUTOMATE_NP::Automate& automate = AUTOMATE_NP::Automate::getAutomate();
        automate.setTransition(gt);
    }

    /* :'(
    QFile * file = new QFile(filename);
    QXmlStreamReader * xml = new QXmlStreamReader(file);
    AUTOMATE_NP::Automate::getAutomate().appliquerConfiguration(xml);
    file->close();*/
    this->close();
}


