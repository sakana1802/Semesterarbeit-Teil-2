#include "Lebensstand.h"
#include <QFont>
#include "meinWidget.h"
#include"zeichenfeld.h"

Leben::Leben(QGraphicsItem *parent): QGraphicsTextItem(parent){
    leben = 3;
    setPlainText(QString("Leben: ") + QString::number(leben));
    setDefaultTextColor(Qt::black);
    setFont(QFont("Times",10));
}
void Leben::decrease(){
    leben--;
    setPlainText(QString("Leben: ") + QString::number(leben));
}
int Leben::getLeben(){
    return leben;
}
