#ifndef MEINWIDGET_H
#define MEINWIDGET_H
// Qt5 add:
#include "zeichenFeld.h"
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "Spieler.h"
#include "Punktestand.h"
#include "Lebensstand.h"

class Game: public QGraphicsView{
     Q_OBJECT  // notwendig, da Slots enthalten sind
public:
    Game(QWidget * parent=0);

    QGraphicsScene * scene;
    Player * player;
    Punkte * punkte;
    Leben * leben;
    QTimer * timer;

private:
    zeichenFeld *meinZeichenFeld;
    int lastX;
    int lastY;
    int increment;
    int phase;

private slots:
    void start(void);
    void stop(void);
    void saveFile(void);
    void loadFile(void);

};

#endif // MEINWIDGET_H
