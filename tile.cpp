#include "tile.h"
#include "logichandler.h"

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

void Tile::mousePressEvent(QGraphicsSceneMouseEvent *event){
    LogicHandler *logic = qobject_cast<LogicHandler *>(parent());

    if (!logic->isGameActive) {
        return;
    }
    else{
    if (event->button() == Qt::LeftButton) {
        setPixmap(image);
        isOpened = true;
        if(isLandmine){emit mineClicked();}
        if(isEmpty){emit emptyTileRevealed(row, col);}
        if(isFlagged){emit flagPlaced(2, row, col); isFlagged = false;}
        if(isFlagged && isLandmine){emit flagPlaced(3, row, col); isFlagged = false;}

    }
    else if (event->button() == Qt::RightButton) {
        if(isOpened == false){
            setPixmap(QPixmap(":/Sprites/tileflag.png"));
            if(isLandmine && isFlagged == false){
                isFlagged = true;
                emit flagPlaced(1, row, col);}
            else if(isFlagged == false && !isLandmine){
                isFlagged = true;
                emit flagPlaced(0, row, col);
            }

        }
    }
    }
    QGraphicsPixmapItem::mousePressEvent(event);
}

