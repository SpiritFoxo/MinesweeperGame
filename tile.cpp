#include "tile.h"

void Tile::RevealTile(){
    setPixmap(image);
}

void Tile::RemoveFlagImage(){
    setPixmap(QPixmap(":/Sprites/tilebase.png"));
    isFlagged = false;

}

void Tile::SetImage(QPixmap pixmap, bool isLandmine, bool isEmpty){
    //this->setPixmap(pixmap);
    this->image = pixmap;
    this->isLandmine = isLandmine;
    this->isEmpty = isEmpty;
}

