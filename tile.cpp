#include "tile.h"
#include "logichandler.h"

void Tile::RevealTile(){
    setPixmap(image);
}

void Tile::RemoveFlagImage(){
    setPixmap(QPixmap(":/Sprites/tilebase.png"));
    isFlagged = false;

}

//setting reveal image and spme booleans to make my shitty code work
void Tile::SetImage(QPixmap pixmap, bool isLandmine, bool isEmpty){
    this->image = pixmap;
    this->isLandmine = isLandmine;
    this->isEmpty = isEmpty;
}

//logic to check mouse clicks
void Tile::mousePressEvent(QGraphicsSceneMouseEvent *event){

    LogicHandler *logic = qobject_cast<LogicHandler *>(parent());

    //if game is not active clicks are not processed
    if (!logic->isGameActive) {
        return;
    }
    else{
    if (event->button() == Qt::LeftButton) {
        setPixmap(image); //changing image on click
        isOpened = true;
        if(isLandmine){emit mineClicked();} //if tile has landmine sending a needed signal
        if(isEmpty){emit emptyTileRevealed(row, col);} //if tile empty sending a needed signal

        //logic for clearing flags using signals
        if(isFlagged){emit flagPlaced(2, row, col); isFlagged = false;}
        if(isFlagged && isLandmine){emit flagPlaced(3, row, col); isFlagged = false;}

    }

    //setting flag on rmb click
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

