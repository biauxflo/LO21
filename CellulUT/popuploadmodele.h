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

    void on_buttonBox_clicked(QAbstractButton *button);

private:
    int choixModele = 0;
    Ui::popUpLoadModele *ui;
};

#endif // POPUPLOADMODELE_H
