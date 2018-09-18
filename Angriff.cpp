#include "Angriff.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "Gegenstand.h"
#include "meinWidget.h"
#include <typeinfo>
#include"zeichenfeld.h"




extern Game * game;

Angriff::Angriff(QGraphicsItem *parent): QObject(), QGraphicsRectItem(parent){
    setRect(10,10,20,20);
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);
}
void Angriff::move(){
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Gegenstand)){
            game->punkte->increase();
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            delete colliding_items[i];
            delete this;
            return;
        }
    }

    setPos(x(),y()-10);
    if (pos().y() + rect().height() < 0){
        scene()->removeItem(this);
        delete this;
    }
}
