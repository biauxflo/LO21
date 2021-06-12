#ifndef GRAPH_AUTOMATE_H
#define GRAPH_AUTOMATE_H

#include <QGraphicsScene>
#include <QMainWindow>

using namespace std;
#include "reseau.h"

/*!
 * Class inerithed from QGraphicsScene - contains functions "paintLife" and "mousePressEvent", which allow repainting and click tracking
 */
namespace GA_NP{
    class Graph_Automate : public QGraphicsScene
    {
        Q_OBJECT

    public:
        // constructors
        Graph_Automate(QMainWindow * parent = 0);
        Graph_Automate(QGraphicsItem * parent = 0);

        // variables
        size_t resolutionLong; //<! the pixel resolution of one side of this scene (it is a square)
        size_t resolutionLarg;

        // member fucntions
        void clickDeSouris(QGraphicsSceneMouseEvent *event);
        void peindreReseau(RESEAU_NP::Reseau &r);


    };
}

#endif // GRAPH_AUTOMATE_H
