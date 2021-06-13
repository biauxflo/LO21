#ifndef MENUCREATION_H
#define MENUCREATION_H

#include <QMainWindow>
#include "fenetrejeu.h"


namespace Ui {
class MenuCreation;
}

class MenuCreation : public QMainWindow
{
    Q_OBJECT

public:
    explicit MenuCreation(QWidget *parent = nullptr);
    ~MenuCreation();
    int getChoixMenu(){return choixMenu;};
    QString getFilename(){return filename;};
    int getChoixModele(){return choixModele;};
private:
    Ui::MenuCreation *ui;
    int choixMenu;
    QString filename;
    int choixModele;
private slots:
    void loadSim();

    void creerSim();

    void loadModele();
};

#endif // MENUCREATION_H
