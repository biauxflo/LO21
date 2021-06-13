#include "GraphAutomate.h"
#include <QGraphicsSceneMouseEvent>
#include <QtDebug>
#include "fenetrejeu.h"

using namespace std;
#include <vector>

FenetreJeu * gameWin;

GraphAutomate::GraphAutomate(QMainWindow *parent){
}

GraphAutomate::GraphAutomate(QGraphicsItem *parent){}

void GraphAutomate::mousePressEvent(QGraphicsSceneMouseEvent *event){
    gameWin->activerCellule(size_t(event->scenePos().x()),size_t(event->scenePos().y()));
}

void GraphAutomate::printAutomate(RESEAU_NP::Reseau* r)
{
    // the border stays right bottom
    // if you change it, remember to change the function to toggle cells to account for it!

    // dimension in pixel of the View
    size_t viewLargeur = 900; //
    size_t viewLongueur = 600;
    //calculate the biggest area

    size_t cellLarg = viewLargeur/r->getLargeur();
    size_t cellLong = viewLongueur/r->getLongueur();

    QImage image(viewLargeur, viewLongueur, QImage::Format_RGB32);
    QRgb value;

    for(size_t i = 0; i < r->getLargeur(); i++){
        for(size_t e = 0; e < r->getLongueur(); e++){
            value=r->getCellule(i,e).getEtat().getColor();
            for(size_t x = 0; x < cellLarg; x++){
                for(size_t y = 0; y < cellLong; y++){
                    image.setPixel(i*cellLarg + x, e*cellLong + y, value);
                }
            }
        }
    }

    // Print it
    setSceneRect(0,0,viewLargeur,viewLongueur);
    addPixmap(QPixmap::fromImage(image));
}
