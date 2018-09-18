#include <QtGui>
#include <QMessageBox>
#include "zeichenFeld.h"
#include "meinWidget.h"


zeichenFeld::zeichenFeld(QWidget *parent){
    setMouseTracking(false);
}
zeichenFeld::~zeichenFeld()
{
}
void zeichenFeld::serialize(QFile &file)
{
    QTextStream out(&file);

    out << "p " <<lastX;


}

void zeichenFeld::deserialize(QFile &file)
{
    char c;

    QTextStream in(&file);

    while (in.status() == QTextStream::Ok)
    {
        in >> c;
        if (in.status() == QTextStream::ReadPastEnd) break;

        if (c!='p')
        {
            QMessageBox::warning(this, tr("Objektfehler"),
                                 tr("Folgender Objekttyp ist unbekannt: ") + c,QMessageBox::Ok);
            return;
        }

        in >> lastX;

        in >> c;
    }


}
