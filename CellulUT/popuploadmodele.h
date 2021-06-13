#ifndef POPUPLOADMODELE_H
#define POPUPLOADMODELE_H

#include <QDialog>
#include <QStringList>
#include <QAbstractButton>

namespace Ui {
class popUpLoadModele;
}

class popUpLoadModele : public QDialog
{
    Q_OBJECT


public:
    explicit popUpLoadModele(QWidget *parent = nullptr);
    ~popUpLoadModele();
    int getchoixModele(){return choixModele;};


private slots:
    void golChecked();
    void langstonChecked();
    void brianChecked();
    void griffeathChecked();

<<<<<<< HEAD
    void on_buttonBox_accepted();
=======
    void on_buttonBox_clicked(QAbstractButton *button);
>>>>>>> abdda4e1396e030cc87e3d4d128cc444a1af91cf

private:
    int choixModele = 0;
    Ui::popUpLoadModele *ui;
};

#endif // POPUPLOADMODELE_H
