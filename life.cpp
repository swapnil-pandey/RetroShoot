#include "life.h"
#include <QFont>

Life::Life(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    life=1;

    setPlainText("Life: "+ QString::number(life));
    setDefaultTextColor(Qt::white);
    setFont(QFont("times",16));
}

void Life::dec()
{
    life--;
    setPlainText("Life: "+ QString::number(life));
    if(life==0)
        exit(0);
}

int Life::getLife()
{
    return life;
}
