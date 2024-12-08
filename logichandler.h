#ifndef LOGICHANDLER_H
#define LOGICHANDLER_H
#include <cstdlib>
#include <ctime>
#include "math.h"
#include <QTimer>
#include <QGraphicsScene>
#include "tile.h"
#include "QMessageBox"

class LogicHandler : public QObject
{
    Q_OBJECT
public:
    LogicHandler();
    void BuildScene(QGraphicsScene* scene, int width, int height);
    bool isGameActive = true;


private:
    QVector<QVector<Tile*>> tiles;
    QVector<QVector<int>> map;
    QTimer *gameTimer;
    int elapsedSeconds;
    int rows;
    int cols;
    int landminesCount;
    int correctFlags = 0;
    int totalFlags = 0;

    void GameLost();
    void GameWon();

    void GenerateMap(int n, int rows, int cols);
    void UpdateTiles(int width, int height);
    void RevealCloseTiles(int row, int col);
    void FlagHandlerLogic(int type, int row, int col);

private slots:
    void updateTimer();

signals:
    void gameEnded(bool won);
    void timeUpdated(int seconds);
};

#endif // LOGICHANDLER_H
