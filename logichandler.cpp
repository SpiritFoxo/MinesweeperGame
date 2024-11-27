#include "logichandler.h"
#include "tile.h"
#include <QDebug>
#include <QFile>

LogicHandler::LogicHandler()
{

}

void LogicHandler::BuildScene(QGraphicsScene* scene, int width, int height){
    for (int row = 0; row < width; ++row) {
        for (int col = 0; col < height; ++col) {
           // Tile* tileobj = new Tile(QPixmap(":/Sprites/tilebase.png"));
            QGraphicsPixmapItem* item = new Tile(QPixmap(":/Sprites/tilebase.png"));
            item->setPos(col * 50, row * 50);
            scene->addItem(item);
            //delete tileobj;
        }
    }
}
