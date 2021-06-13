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
