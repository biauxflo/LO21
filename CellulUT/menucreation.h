#ifndef MENUCREATION_H
#define MENUCREATION_H

#include <QMainWindow>

namespace Ui {
class MenuCreation;
}

class MenuCreation : public QMainWindow
{
    Q_OBJECT

public:
    explicit MenuCreation(QWidget *parent = nullptr);
    ~MenuCreation();

private:
    Ui::MenuCreation *ui;

private slots:
    void loadSim();

    void createSim();

    void loadModele();
};

#endif // MENUCREATION_H
