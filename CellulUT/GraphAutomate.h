#ifndef GRAPH_AUTOMATE_H
#define GRAPH_AUTOMATE_H

#include <QGraphicsScene>
#include <QMainWindow>
using namespace std;
#include "Reseau.h"

class GraphAutomate : public QGraphicsScene
{
    Q_OBJECT

public:
    GraphAutomate(QMainWindow * parent = 0);
    GraphAutomate(QGraphicsItem * parent = 0);
    void mouseClick(QGraphicsSceneMouseEvent *event);
    void printAutomate(RESEAU_NP::Reseau* r);
};

#endif // MYGRAPHICSCENE_H
