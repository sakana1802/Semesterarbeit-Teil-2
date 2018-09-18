#include "meinWidget.h"
#include"zeichenfeld.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include "Gegenstand.h"
// Qt5 add:
#include <QPushButton>
#include <QGridLayout>
#include <QFileDialog>
#include <QMessageBox>
#include <QtGui>

Game::Game(QWidget *parent){

    QPushButton *quit = new QPushButton(tr("Ende"));
    quit->setFont(QFont("Times", 12, QFont::Bold, QFont::Cursive));
    connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));

    QPushButton *start = new QPushButton(tr("Start"));
    start->setFont(QFont("Times", 12, QFont::Bold, QFont::Cursive));
    connect(start, SIGNAL(clicked()), this, SLOT(start()));

    QPushButton *stop = new QPushButton(tr("Stop"));
    stop->setFont(QFont("Times", 12, QFont::Bold, QFont::Cursive));
    connect(stop, SIGNAL(clicked()), this, SLOT(stop()));

    QPushButton *speichern = new QPushButton(tr("Speichern"));
    speichern->setFont(QFont("Times", 12, QFont::Bold, QFont::Cursive));
    connect(speichern, SIGNAL(clicked()), this, SLOT(saveFile()));

    QPushButton *laden = new QPushButton(tr("Laden"));
    laden->setFont(QFont("Times", 12, QFont::Bold, QFont::Cursive));
    connect(laden, SIGNAL(clicked()), this, SLOT(loadFile()));

    meinZeichenFeld = new zeichenFeld;

    QGridLayout *gridLayout = new QGridLayout;
    gridLayout->addWidget(quit, 0, 0);
    gridLayout->addWidget(start, 1, 0);
    gridLayout->addWidget(stop, 2, 0);
    gridLayout->addWidget(speichern, 3, 0);
    gridLayout->addWidget(laden, 4, 0);
    gridLayout->addWidget(meinZeichenFeld, 0, 1, 3, 1);
    gridLayout->setColumnStretch(1, 10);
    setLayout(gridLayout);


    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    player = new Player();
    player->setRect(0,0,100,100);
    player->setPos(400,500);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    scene->addItem(player);

    punkte = new Punkte();
    scene->addItem(punkte);
    leben = new Leben();
    leben->setPos(leben->x(),leben->y()+25);
    scene->addItem(leben);

    timer = new QTimer();
      QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
      lastX=100;
      lastY=100;
     show();
}




void Game::start(void)
{
       timer->start(2000);increment=1;
}

void Game::stop(void)
{
    timer->stop();increment=0;

}
void Game::saveFile(void)
{
    QFileDialog dialog(this);
    QString fileName;
    QFile file;

    dialog.setFileMode(QFileDialog::AnyFile);
    fileName = dialog.getSaveFileName(this,
                                      tr("Speichern als"), ".", tr("Zeichnungen (*.myz)"));

    if (fileName.isNull()==false)
    {
        file.setFileName(fileName);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QMessageBox::warning(this, tr("Dateifehler"),
                                 tr("Folgende Datei kann nicht verwendet werden: ") + fileName,QMessageBox::Ok);
        }

        meinZeichenFeld->serialize(file);
        file.close();
        return;
    }
}

void Game::loadFile(void)
{
    QFileDialog dialog(this);
    QString fileName;
    QFile file;

    dialog.setFileMode(QFileDialog::AnyFile);
    fileName = dialog.getOpenFileName(this,
                                      tr("Speichern als"), ".", tr("Zeichnungen (*.myz)"));

    if (!fileName.isNull())
    {
        file.setFileName(fileName);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QMessageBox::warning(this, tr("Dateifehler"),
                                 tr("Folgende Datei kann nicht geÃ¶ffnet werden: ") + fileName,QMessageBox::Ok);
        }

        meinZeichenFeld->deserialize(file);
        file.close();
        return;
    }
}
