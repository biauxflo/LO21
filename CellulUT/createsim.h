#ifndef CREATESIM_H
#define CREATESIM_H

#include <QAbstractButton>
#include <QDialog>
#include "Etat.h"

namespace Ui {
class createSim;
}

class createSim : public QDialog
{
    Q_OBJECT

public:
    explicit createSim(QWidget *parent = nullptr);
    ~createSim();
    int getChoixEtat(){return choixEtat;};
    ETAT_NP::Etat * getCreateEtat(){return createEtat;};
    size_t getDimReseau(){return dimReseau;};
    int getChoixVoisinage(){return choixVoisinage;};
    size_t getRayonVoisinage(){return rayonVoisinage;};
    int getChoixTransition(){return choixTransition;};
    int *getTransitionGoL(){return transitionGoL;};

private slots:
    void accept();
private:
    int choixEtat;
    ETAT_NP::Etat *createEtat;
    Ui::createSim *ui;
    size_t dimReseau;
    int choixVoisinage;
    size_t rayonVoisinage;
    int choixTransition;
    int* transitionGoL;

    void on_buttonBox_clicked(QAbstractButton *button);


    void manuelEtat();
    void autoEtat();
    void autoVoisinage();
    void autoTransition();
};

#endif // CREATESIM_H
