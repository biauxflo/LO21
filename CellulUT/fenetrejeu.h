#ifndef FENETREJEU_H
#define FENETREJEU_H

#include <QMainWindow>
#include "ui_fenetrejeu.h"
#include "Automate.h"
#include "simulateur.h"
#include "Reseau.h"
#include "GraphAutomate.h"

namespace Ui {
class FenetreJeu;
}

class FenetreJeu : public QMainWindow
{
    Q_OBJECT

public:
    explicit FenetreJeu(QWidget *parent = nullptr);
    ~FenetreJeu();
    void activerCellule(size_t x, size_t y);
    size_t get_celluleParLigne();
    size_t get_Resolution();
    void commencerBoucle();
    void updateGUI();

    SIMULATEUR_NP::Simulateur *simulation;

private slots:

    void playButton_clicked();

    void pauseButton_clicked();

    void resetButton_clicked();

    void backButton_clicked();

    void nextButton_clicked();

    void stopButton_clicked();

    void spinbox_textchanged();

    bool auto_checked();

    void execute();


private:
    Ui::FenetreJeu *ui;
    GraphAutomate *scene;
    QPixmap image;
    QTimer *timer;
    size_t viewResolutionLargeur;
    size_t viewResolutionLongueur;
    bool loopActive = false;
    bool loopPause = false;
};

#endif // FENETREJEU_H
