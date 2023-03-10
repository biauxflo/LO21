#include "graph_automate.h"
#include <QGraphicsSceneMouseEvent>
#include <QtDebug>
#include "mainwindow.h"

using namespace std;
#include <vector>

extern MainWindow * mainWin;

GraphAutomate::GraphAutomate(QMainWindow *parent){}

GraphAutomate::GraphAutomate(QGraphicsItem *parent){}



void GraphAutomate::mouseClick(QGraphicsSceneMouseEvent *event){
    // qDebug() << event->scenePos().x() << " " << event->scenePos().y();
    //mainWin->toggleCells(event->scenePos().x(), event->scenePos().y());

}

void GraphAutomate::printAutomate(RESEAU_NP::Reseau* r)
{
    // the border stays right bottom
    // if you change it, remember to change the function to toggle cells to account for it!

    // dimension in pixel of the View
    size_t viewLargeur = 900; // if I use "mainWin->get_ViewResolution()" then it crashes by the first setting... WHY?
    size_t viewLongueur = 600;
    //calculate the biggest area

    size_t cellLarg = viewLargeur/r->getLargeur();
    size_t cellLong = viewLongueur/r->getLongueur();

    // int bigDim = len * cellDim;
    //scene->setSceneRect(scene.)

    QImage image(viewLargeur, viewLongueur, QImage::Format_RGB32);
    QRgb value;

    value = qRgb(240, 100, 2); // THE COLOR OF LIVING CELLS

    for(size_t i = 0; i < r->getLargeur(); i++){
        for(size_t e = 0; e < r->getLongueur(); e++){
            value=r->getCellule(i,e).getEtat().getColor();
                for(size_t x = 0; x < cellLarg; x++){
                    for(size_t y = 0; y < cellLong; y++){
                        image.setPixel(e*cellLarg + x, i*cellLong + y, value);
                    }
                }
             }
        }

    // Print it
    setSceneRect(0,0,viewDim,viewDim);
    addPixmap(QPixmap::fromImage(image));
}
