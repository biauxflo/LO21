#ifndef POPUPLOADMODELE_H
#define POPUPLOADMODELE_H

#include <QDialog>
#include <QStringList>

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

private:
    int choixModele = 0;
    Ui::popUpLoadModele *ui;
};

#endif // POPUPLOADMODELE_H
