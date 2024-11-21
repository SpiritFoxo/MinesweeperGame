#ifndef TILE_H
#define TILE_H
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>

class Tile
{
public:
    Tile();
    QPixmap tileImage = QPixmap(":/Sprites/tilebase.png");
private:
    int status = 0;

};

#endif // TILE_H
