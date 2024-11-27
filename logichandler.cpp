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
            Tile *tile = new Tile(QPixmap(":/Sprites/tilebase.png"));
//            QGraphicsPixmapItem* item = new Tile(QPixmap(":/Sprites/tilebase.png"));
            tile->setPos(col * 50, row * 50);
            scene->addItem(tile);
            tiles.append(tile);

           // tile->SetImage();

            tiles[0]->SetImage();
        }
    }
}
