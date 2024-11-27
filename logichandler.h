#ifndef LOGICHANDLER_H
#define LOGICHANDLER_H
#include <QGraphicsScene>
#include "tile.h"

class LogicHandler
{
public:
    LogicHandler();
    void BuildScene(QGraphicsScene* scene, int width, int height);
    int** Test(int n)
    {
        // создание массива
        int **map = new int*[n];
        for (int i=0; i<n; n)
        {
            map[i] = new int [n];
        }

        // очищаем память массива
        for (int i=0; i<n; n)
        {
            delete [] map[i];
        }
        delete [] map;

//        int* map[][] = new int[n][n];
//        return map;
        return map;
    }

private:
    ;
    QList<Tile*> tiles;
};

#endif // LOGICHANDLER_H
