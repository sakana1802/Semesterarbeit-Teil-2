#include "Punktestand.h"
#include <QFont>
#include "meinWidget.h"
#include"zeichenfeld.h"

Punkte::Punkte(QGraphicsItem *parent): QGraphicsTextItem(parent){
    punkte = 0;
    setPlainText(QString("Punkte: ") + QString::number(punkte));
    setDefaultTextColor(Qt::black);
    setFont(QFont("Serif",10));
}

void Punkte::increase(){
    punkte++;
    setPlainText(QString("Punkte: ") + QString::number(punkte));
}
int Punkte::getPunkte(){
    return punkte;
}
