#include "Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <QList>
#include <stdlib.h>
#include <QDesktopWidget>
#include <QApplication>
#include "game.h"

extern Game *game;

Enemy::Enemy():QObject(),QGraphicsPixmapItem()
{
    QRect rec = QApplication::desktop()->screenGeometry();
    int width = rec.width();

    setPixmap(QPixmap("://img/enemy.png"));

    int rand_n=rand()%(width-100);
    setPos(rand_n,0);


    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);
}


void Enemy::move()
{
    moveBy(0,+10);
    if(pos().y()>750)
    {
        scene()->removeItem(this);
        delete this;
        game->life->dec();
        //qDebug()<<"enemy deleted";
    }
}


