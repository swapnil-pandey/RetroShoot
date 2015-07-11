#ifndef ENEMY
#define ENEMY
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QObject>

class Enemy:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Enemy();
public slots:
    void move();
};

#endif // ENEMY

