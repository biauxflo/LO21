#include "popuploadmodele.h"
#include "ui_popuploadmodele.h"

popUpLoadModele::popUpLoadModele(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::popUpLoadModele)
{
    ui->setupUi(this);
    connect(ui->buttonBox,SIGNAL(accepted()),this,SLOT(on_buttonBox_accepted()));
}

popUpLoadModele::~popUpLoadModele()
{
    delete ui;
}

void popUpLoadModele::golChecked(){
    if(ui->golChecked->isChecked()){
            choixModele = 1;
    }
}
void popUpLoadModele::langstonChecked(){
    if(ui->langstonChecked->isChecked()){
            choixModele = 2;
    }
}
void popUpLoadModele::brianChecked(){
    if(ui->brainChecked->isChecked()){
            choixModele = 3;
    }
}
void popUpLoadModele::griffeathChecked(){
    if(ui->griffithChecked->isChecked()){
            choixModele = 4;
    }
}

void popUpLoadModele::on_buttonBox_accepted()
{
    this->close();
}

