#include "game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include "enemy.h"
#include <QDesktopWidget>
#include <QApplication>
#include <QMediaPlayer>


Game::Game(QWidget *parent)
{
    QRect rec = QApplication::desktop()->screenGeometry();
    int height = rec.height();
    int width = rec.width();

    QGraphicsScene *scene = new QGraphicsScene();
    scene->setSceneRect(0,0,width,height);

    QGraphicsView *view = new QGraphicsView(scene);

    scene->setBackgroundBrush(QImage("://img/bg.png"));

    //player
    ship *player=new ship();
    scene->addItem(player);
    player->setPos(width/2, height-70);

    //scoring
    score = new Score();
    scene->addItem(score);

    //life
    life = new Life();
    life->setPos(life->x(),life->y()+25);
    scene->addItem(life);

    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    //enemies
    QTimer*timer=new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(2000);

    //music
    QMediaPlayer * music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sounds/bgmusic.mp3"));
    music->play();

    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->showFullScreen();
}
