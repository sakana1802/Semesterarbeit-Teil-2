#include "Spieler.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "Angriff.h"
#include "Gegenstand.h"
#include"zeichenfeld.h"
#include "meinWidget.h"



Player::Player(QGraphicsItem *parent): QGraphicsRectItem(parent){

}
void Player::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_Left){
        if (pos().x() > 0)
        setPos(x()-10,y());
    }
    else if (event->key() == Qt::Key_Right){
        if (pos().x() + 100 < 800)
        setPos(x()+10,y());
    }
    else if (event->key() == Qt::Key_Space){
        Angriff * angriff = new Angriff();
        angriff->setPos(x(),y());
        scene()->addItem(angriff);
    }
}

void Player::spawn(){
    Gegenstand * gegenstand = new Gegenstand();
    scene()->addItem(gegenstand);
}
