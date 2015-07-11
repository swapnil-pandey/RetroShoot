#include "ship.h"
#include "bullet.h"
#include "enemy.h"
#include <QGraphicsItem>
#include <QDebug>
#include <QApplication>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QDesktopWidget>
#include <QMediaPlayer>

ship::ship():  QObject(), QGraphicsPixmapItem()
{
    setPixmap(QPixmap("://img/ship.png"));
}

void ship::keyPressEvent(QKeyEvent *event)
{
    QRect rec = QApplication::desktop()->screenGeometry();
    int height = rec.height();
    int width = rec.width();

    QMediaPlayer * shoot = new QMediaPlayer();
    shoot->setMedia(QUrl("qrc:/sounds/shoot.mp3"));
    shoot->setVolume(50);

    if (event->key()==Qt::Key_Left && x()>0)
        moveBy(-25,0);

    else if (event->key()==Qt::Key_Right && x()<width-70)
        moveBy(25,0);

    else if (event->key()==Qt::Key_Up && y()>0)
        moveBy(0,-20);

    else if(event->key()==Qt::Key_Down && y()<height-70)
        moveBy(0,20);

    else if(event->key()==Qt::Key_Space)
    {
        Bullet * bullet=new Bullet();
        //qDebug()<<"yo";
        bullet->setPos(x()+26,y()-45);
        scene()->addItem(bullet);
        shoot->play();

    }
}

ship::~ship()
{}

void ship::spawn()
{
    Enemy *enemy = new Enemy();
    scene()->addItem(enemy);
}
