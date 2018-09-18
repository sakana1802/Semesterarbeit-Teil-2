#ifndef LEBENSSTAND_H
#define LEBENSSTAND_H
#include <QGraphicsTextItem>

class Leben: public QGraphicsTextItem{
public:
    Leben(QGraphicsItem * parent=0);
    void decrease();
    int getLeben();
private:
    int leben;
};

#endif // LEBENSSTAND_H
