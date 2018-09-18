#ifndef GEGENSTAND_H
#define GEGENSTAND_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>


class Gegenstand: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Gegenstand(QGraphicsItem * parent=0);
public slots:
    void move();
};

#endif // GEGENSTAND_H
