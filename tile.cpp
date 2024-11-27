#include "tile.h"

QPixmap Tile::GetImage(){
    return image;
}

void Tile::SetImage(QPixmap pixmap){
    this->setPixmap(pixmap);
}
