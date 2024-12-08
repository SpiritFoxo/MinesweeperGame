#ifndef TILE_H
#define TILE_H
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>

class LogicHandler;

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
    bool isLandmine = false;
    void RevealTile();
    void SetImage(QPixmap pixmap, bool isLandmine, bool isEmpty);
    void RemoveFlagImage();
private:
    QPixmap image = QPixmap(":/Sprites/tilebase.png");

public:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

signals:
    void mineClicked();
    void emptyTileRevealed(int row, int col);
    void correctFlag();
    void flagPlaced(int type, int row, int col); //0 - placed; 1 - correctly placed; 2 - removed; 3 - removed correct one
    void correctFlagRemoved();
    void flagRemoved();
};


#endif // TILE_H
