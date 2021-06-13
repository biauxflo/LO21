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
    void printAutomate(RESEAU_NP::Reseau* r);

private slots:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // MYGRAPHICSCENE_H
