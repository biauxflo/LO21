#ifndef CHARGESIM_H
#define CHARGESIM_H

#include <QDialog>

namespace Ui {
class chargeSim;
}

class chargeSim : public QDialog
{
    Q_OBJECT

public:
    explicit chargeSim(QWidget *parent = nullptr);
    ~chargeSim();

private:
    Ui::chargeSim *ui;
};

#endif // CHARGESIM_H
