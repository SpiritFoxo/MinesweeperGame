#include "tile.h"

QPixmap Tile::GetImage(){
    return image;
}

void Tile::SetImage(){
    this->setPixmap(QPixmap(":/Sprites/tileused.png"));
}
