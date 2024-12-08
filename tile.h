#ifndef TILE_H
#define TILE_H
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>

class Tile: public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Tile(const QPixmap &pixmap, int row, int col) : QGraphicsPixmapItem(pixmap) { this->row = row; this->col = col;}
   public:
    int row;
    int col;
    bool isOpened = false;
    bool isEmpty = false;
    bool isFlagged = false;
    void RevealTile();
    void SetImage(QPixmap pixmap, bool isLandmine, bool isEmpty);
    void RemoveFlagImage();
private:
    QPixmap image = QPixmap(":/Sprites/tilebase.png");
    bool isLandmine = false;



public:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override {
        if (event->button() == Qt::LeftButton) {
            setPixmap(image);
            isOpened = true;
            if(isLandmine){emit mineClicked();}
            if(isEmpty){emit emptyTileRevealed(row, col);}
            if(isFlagged){emit flagPlaced(2, row, col); isFlagged = false;}
            if(isFlagged && isLandmine){emit flagPlaced(3, row, col); isFlagged = false;}

        } else if (event->button() == Qt::RightButton) {
            if(isOpened == false){
                setPixmap(QPixmap(":/Sprites/tileflag.png"));
                if(isLandmine && isFlagged == false){emit flagPlaced(1, row, col);}
                else if(isFlagged == false && !isLandmine){
                    emit flagPlaced(0, row, col);
                }
                isFlagged = true;
            }
        }
        QGraphicsPixmapItem::mousePressEvent(event);
    }


signals:
    void mineClicked();
    void emptyTileRevealed(int row, int col);
    void correctFlag();
    void flagPlaced(int type, int row, int col); //0 - placed; 1 - correctly placed; 2 - removed; 3 - removed correct one
    void correctFlagRemoved();
    void flagRemoved();
};


#endif // TILE_H
