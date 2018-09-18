#ifndef ZEICHENFELD
#define ZEICHENFELD
#include <vector>
using namespace std;
#include <QWidget>
#include <QTimer>
#include <QFile>


class zeichenFeld : public QWidget
{
public:
    zeichenFeld(QWidget *parent = 0);
    ~zeichenFeld();
    void serialize(QFile &file);
    void deserialize(QFile &file);

private:
    int lastX;
    int lastY;

};


#endif // ZEICHENFELD

