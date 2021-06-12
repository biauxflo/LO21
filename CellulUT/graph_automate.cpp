#include "graph_automate.h"
#include <QGraphicsSceneMouseEvent>
#include <QtDebug>
#include "mainwindow.h"

using namespace std;

extern MainWindow * mainWin;


GA_NP::Graph_Automate(QMainWindow){
    resolutionLarg = 0;
    resolutionLong = 0;
};

GA_NP::Graph_Automate(QGraphicsItem)
{
    resolutionLarg = 0;
    resolutionLong = 0;
};

/*!
 * overrides a member function fo QGraphicsScene and uses it to inform main window and game window about clicks on the scenes
 */
void clickDeSouris(QGraphicsSceneMouseEvent *event){
    //mainWin->toggleCells(event->scenePos().x(), event->scenePos().y(), this);
}

/*!
 * \brief Paints a cellfield on the scene (colors defined inside the function)
 * \param cellField is the vector describing the cells status
 * \param len is the length of one side of the field, aka: how many cells per line
 */
void peindreReseau(RESEAU_NP::Reseau &r)
{
    // the cell is painted top left... therefore there could be an unused border bottom right...
    // if you change it, remember to change the function to toggle cells to account for it!

    // dimension in pixel of the View
    size_t viewDimLarg = 900; //A FIXER AVEC l'UI
    size_t viewDimLong = 600;
    // calculate the dimension of a cell
    size_t cellLarg = viewDimLarg/r.getLargeur();
    size_t cellLong = viewDimLong/r.getLongueur();

    // create a new image of the necessary dimension
    QImage image(viewDimLarg, viewDimLong, QImage::Format_RGB32);

    QRgb value;

    for(size_t i = 0; i < r.getLargeur(); i++){
        for(size_t e = 0; e < r.getLongueur(); e++){
            value=r.getCellule(i,e).getEtat().getColor(); // GET COLOR QRGB (pls)

             // paint a whole cell (a square of cellDim pixels)
            for(size_t x = 0; x < cellLarg; x++){
                for(size_t y = 0; y < cellLong; y++){
                    image.setPixel(e*cellLarg + x, i*cellLong + y, value);
                }
            }
        }
    }

    // set the dimension of the scene
    setSceneRect(0,0,viewDimLarg,viewDimLong);
    // add the generated image to the scene (after trasforming it in a Pixmap)
    addPixmap(QPixmap::fromImage(image));
}
