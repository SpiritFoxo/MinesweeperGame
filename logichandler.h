#ifndef LOGICHANDLER_H
#define LOGICHANDLER_H
#include <cstdlib>
#include <ctime>
#include <QGraphicsScene>
#include "tile.h"
#include "QMessageBox"

class LogicHandler : public QObject
{
public:
    LogicHandler();
    void BuildScene(QGraphicsScene* scene, int width, int height);


private:
    QVector<QVector<Tile*>> tiles;
    QVector<QVector<int>> map;
    int rows;
    int cols;
    int landminesCount;
    int correctFlags = 0;
    int totalFlags = 0;

    void gameLost();
    void checkVictory();
    void resetGame();

    void GenerateMap(int n, int rows, int cols);
    void UpdateTiles(int width, int height);
    void RevealCloseTiles(int row, int col);
    void FlagHandlerLogic(int type, int row, int col);

signals:
    void gameEnded(bool won);
};

#endif // LOGICHANDLER_H
