#ifndef POPUPLOADMODELE_H
#define POPUPLOADMODELE_H

#include <QDialog>

namespace Ui {
class popUpLoadModele;
}

class popUpLoadModele : public QDialog
{
    Q_OBJECT

public:
    explicit popUpLoadModele(QWidget *parent = nullptr);
    ~popUpLoadModele();

private:
    Ui::popUpLoadModele *ui;
};

#endif // POPUPLOADMODELE_H
