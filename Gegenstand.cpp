#include "Gegenstand.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h> // rand() -> really large int
#include "meinWidget.h"
#include"zeichenfeld.h"


extern Game * game;


void Gegenstand::move(){
    setPos(x(),y()+5);
    if (pos().y() > 600){
        game->leben->decrease();
        scene()->removeItem(this);
        delete this;
    }
}
Gegenstand::Gegenstand(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    int random_number = rand() % 700;
    setPos(random_number,0);
    setPixmap(QPixmap(":/bild/mini.png"));
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);
}
