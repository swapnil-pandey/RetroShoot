#ifndef GAME
#define GAME

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "ship.h"
#include "score.h"
#include "life.h"

class Game: public QGraphicsView
{
public:
    Game(QWidget *parent=0);
    QGraphicsScene *scene;
    ship *player;
    Score *score;
    Life *life;

};

#endif // GAME

