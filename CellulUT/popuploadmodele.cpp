#include "popuploadmodele.h"
#include "ui_popuploadmodele.h"

popUpLoadModele::popUpLoadModele(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::popUpLoadModele)
{
    ui->setupUi(this);
}

popUpLoadModele::~popUpLoadModele()
{
    delete ui;
}

void popUpLoadModele::golChecked(){
    if(ui->golChecked->isChecked()){
        filename = "modeles\\gamelife.xml";
    }
}
void popUpLoadModele::langstonChecked(){
    if(ui->langstonChecked->isChecked()){
            choixModele = 2;
    }
}
void popUpLoadModele::brianChecked(){
    filename = "D:\\UTC\\GI04\\LO21\\lo21\\CellulUT\\modeles\\brianbrain.xml";
    if(ui->brainChecked->isChecked()){
        filename = "D:\\UTC\\GI04\\LO21\\lo21\\CellulUT\\modeles\\brianbrain.xml";
            //filename = "modeles\\brianbrain.xml";
    }
}
void popUpLoadModele::griffeathChecked(){
    if(ui->griffithChecked->isChecked()){
        filename = "modeles\\griffeath.xml";
    }
}

void popUpLoadModele::on_buttonBox_accepted(){
    this->close();
}

void popUpLoadModele::on_buttonBox_clicked(QAbstractButton *button)
{
    if(ui->golChecked->isChecked()){
        GameLifeTransition* rt = new GameLifeTransition;
        Moore* v = new Moore;
        ETAT_NP::Etat* e1 = new ETAT_NP::Etat(0, "dead", QColor("black").rgb());
        ETAT_NP::Etat* e2 = new ETAT_NP::Etat(1, "alive", QColor("white").rgb());
        std::vector<ETAT_NP::Etat*> es;
        es.push_back(e1);
        es.push_back(e2);
        AUTOMATE_NP::Automate& automate = AUTOMATE_NP::Automate::getAutomate();
        automate.setTransition(rt);
        automate.setVoisinage(v);
        automate.setEtats(2, es);

    }
    else if(ui->brainChecked->isChecked()){
        BrianBrainTransition* rt = new BrianBrainTransition;
        Moore* v = new Moore;
        ETAT_NP::Etat* e1 = new ETAT_NP::Etat(0, "resting", QColor("green").rgb());
        ETAT_NP::Etat* e2 = new ETAT_NP::Etat(1, "excited", QColor("red").rgb());
        ETAT_NP::Etat* e3 = new ETAT_NP::Etat(2, "refractory", QColor("jaune").rgb());
        std::vector<ETAT_NP::Etat*> es;
        es.push_back(e1);
        es.push_back(e2);
        es.push_back(e3);
        AUTOMATE_NP::Automate& automate = AUTOMATE_NP::Automate::getAutomate();
        automate.setTransition(rt);
        automate.setVoisinage(v);
        automate.setEtats(3,es);
    }
    else if(ui->griffithChecked->isChecked()){
        GriffeathTransition* rt = new GriffeathTransition;
        Moore* v = new Moore;
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
        automate.setTransition(rt);
        automate.setVoisinage(v);
        automate.setEtats(4,es);
    }
    /* :'(
    QFile * file = new QFile(filename);
    QXmlStreamReader * xml = new QXmlStreamReader(file);
    AUTOMATE_NP::Automate::getAutomate().appliquerConfiguration(xml);
    file->close();*/
    this->close();
}
