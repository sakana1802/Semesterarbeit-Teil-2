#ifndef ANGRIFF_H
#define ANGRIFF_H
#include <QGraphicsRectItem>
#include <QGraphicsItem>
#include <QObject>

class Angriff: public QObject,public QGraphicsRectItem{
    Q_OBJECT
public:
    Angriff(QGraphicsItem * parent=0);
public slots:
    void move();
};

#endif // ANGRIFF_H
