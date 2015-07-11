#ifndef BULLET
#define BULLET
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QObject>

class Bullet:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Bullet(QGraphicsItem *parent=0);
public slots:
    void move();
};

#endif // BULLET

