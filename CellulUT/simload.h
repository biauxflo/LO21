#ifndef SIMLOAD_H
#define SIMLOAD_H

#include <QDialog>
#include <QString>
#include <QFileDialog>

namespace Ui {
class simLoad;
}

class simLoad : public QDialog
{
    Q_OBJECT

public:
    explicit simLoad(QWidget *parent = nullptr);
    ~simLoad();
    QString getFilename(){return filename;}

private slots:
    void openfile();

private:
    QString filename;
    Ui::simLoad *ui;
};

#endif // SIMLOAD_H
