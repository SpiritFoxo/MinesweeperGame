#ifndef LOGICHANDLER_H
#define LOGICHANDLER_H
#include <QGraphicsScene>

class LogicHandler
{
public:
    LogicHandler();
    void BuildScene(QGraphicsScene* scene, int width, int height);

private:
    int map;
};

#endif // LOGICHANDLER_H
