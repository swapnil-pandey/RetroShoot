#ifndef LIFE
#define LIFE
#include <QGraphicsTextItem>

class Life: public QGraphicsTextItem
{
public:
    Life(QGraphicsItem *parent=0);
    void dec();
    int getLife();
private:
    int life;
};


#endif // LIFE

