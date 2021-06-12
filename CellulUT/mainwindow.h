#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"
#include "graph_automate.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void activerCellule(int x, int y);

    size_t get_celluleParLigne();
    size_t get_Resolution();
    void commencerBoucle();
    void updateGUI();


private slots:

    void playButton_clicked();

    void pauseButton_clicked();

    void resetButton_clicked();

    void backButton_clicked();

    void nextButton_clicked();

private:
    Ui::MainWindow *ui;
    GA_NP::Graph_Automate *scene;
    QPixmap image;
    size_t timer;
    size_t times;
    size_t vieWresolution;
    bool loopActive = false;
    bool loopPause = false;
};
#endif // MAINWINDOW_H
