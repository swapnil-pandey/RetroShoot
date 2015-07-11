#ifndef SCORE
#define SCORE
#include <QGraphicsTextItem>

class Score: public QGraphicsTextItem
{
public:
    Score(QGraphicsItem *parent=0);
    void inc();
    int getScore();
private:
    int score;
};

#endif // SCORE

