#ifndef TILE_H
#define TILE_H
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>

class Tile: public QGraphicsPixmapItem {
public:
    Tile(const QPixmap &pixmap) : QGraphicsPixmapItem(pixmap) {}
   public:
    QPixmap GetImage();
    void SetImage(QPixmap pixmap);
private:
    QPixmap image = QPixmap(":/Sprites/tilebase.png");

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override {
        if (event->button() == Qt::LeftButton) {
            qDebug() << "Left button clicked on item!";
           // setPixmap(QPixmap(":/Sprites/tileused.png"));
            setPixmap(image);
        } else if (event->button() == Qt::RightButton) {
            qDebug() << "Right button clicked on item!";
            setPixmap(QPixmap(":/Sprites/tileflag.png"));
        }
        QGraphicsPixmapItem::mousePressEvent(event);
    }
};


#endif // TILE_H
