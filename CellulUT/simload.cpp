#include "simload.h"
#include "ui_simload.h"
#include "fenetrejeu.h"

simLoad::simLoad(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::simLoad)
{
    ui->setupUi(this);
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(openfile()));
}

simLoad::~simLoad()
{
    delete ui;
}

void simLoad::openfile(){
    filename = QFileDialog::getOpenFileName(this, "Choisir une simulation","C://" );
    ui->textBrowser->setText(filename);
}

void simLoad::opensimu() {
    FENETREJEU_H::FenetreJeu gamewin;
    gamewin.show();
}
