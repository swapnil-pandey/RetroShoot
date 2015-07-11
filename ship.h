#ifndef SHIP
#define SHIP

#include <QGraphicsPixmapItem>
#include <QObject>
class ship : public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    void keyPressEvent(QKeyEvent *event);
    ship();
    ~ship();
public slots:
    void spawn();
};

#endif // SHIP_H
