#ifndef PUNKTESTAND_H
#define PUNKTESTAND_H
#include <QGraphicsTextItem>

class Punkte: public QGraphicsTextItem{
public:
    Punkte(QGraphicsItem * parent=0);
    void increase();
    int getPunkte();
private:
    int punkte;
};

#endif // PUNKTESTAND_H
