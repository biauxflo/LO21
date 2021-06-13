#include "chargesim.h"
#include "ui_chargesim.h"

chargeSim::chargeSim(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::chargeSim)
{
    ui->setupUi(this);
}

chargeSim::~chargeSim()
{
    delete ui;
}
