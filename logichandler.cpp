#include "logichandler.h"
#include "tile.h"
#include <QDebug>
#include <QFile>

LogicHandler::LogicHandler()
{

}

void LogicHandler::BuildScene(QGraphicsScene* scene, int width, int height){
        // Добавляем изображения в виде сетки
    for (int row = 0; row < width; ++row) {
        for (int col = 0; col < height; ++col) {
            Tile* tileobj = new Tile();
            QGraphicsPixmapItem* item = new QGraphicsPixmapItem(tileobj->tileImage);
            item->setPos(col * (tileobj->tileImage.width()), row * (tileobj->tileImage.height()));
            scene->addItem(item);
            delete tileobj;
           //qDebug() << QFile("://Sprites/tilebase.png").exists();
        }
    }
}
