#ifndef LOGICHANDLER_H
#define LOGICHANDLER_H
#include <cstdlib>
#include <ctime>
#include <QGraphicsScene>
#include "tile.h"

class LogicHandler
{
public:
    LogicHandler();
    void BuildScene(QGraphicsScene* scene, int width, int height);


private:
    QVector<QVector<Tile*>> tiles;
    QVector<QVector<int>> map;

    void GenerateMap(int n, int rows, int cols);
    void UpdateTiles(int width, int height);
};

#endif // LOGICHANDLER_H
