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
        filename = "modeles\\gamelife.xml";
    }
    if(ui->brainChecked->isChecked()){
        filename = "D:\\UTC\\GI04\\LO21\\lo21\\CellulUT\\modeles\\brianbrain.xml";
            //filename = "modeles\\brianbrain.xml";
    }
    QFile * file = new QFile(filename);
    QXmlStreamReader * xml = new QXmlStreamReader(file);
    AUTOMATE_NP::Automate::getAutomate().appliquerConfiguration(xml);
    file->close();
    this->close();
}
