#include "Bullet.h"
#include "Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <QList>
#include <typeinfo>
#include "game.h"

extern Game *game;

Bullet::Bullet(QGraphicsItem *parent):QObject(),QGraphicsPixmapItem(parent)
{
    //setRect(0,0,10,50);
    setPixmap(QPixmap("://img/bullet.png"));

    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(10);
}


void Bullet::move()
{
    //collision
    QList<QGraphicsItem *>colliding_items=collidingItems();

    for(int i=0,n=colliding_items.size();i<n;i++)
    {
        if(typeid(*(colliding_items[i])) == typeid(Enemy))
        {
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);

            //inc score
            game->score->inc();

            //delete
            delete colliding_items[i];
            delete this;
            return;
        }
    }


    moveBy(0,-5);
    if(y()<-10)
    {
        scene()->removeItem(this);
        delete this;
        //qDebug()<<"bullet deleted";
    }
}
