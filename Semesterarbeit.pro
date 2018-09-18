#-------------------------------------------------
#
# Project created by QtCreator 2018-07-30T17:41:32
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


TARGET = Tutorial
TEMPLATE = app


SOURCES += main.cpp \
    zeichenfeld.cpp \
    Gegenstand.cpp \
    Angriff.cpp \
    meinWidget.cpp \
    Lebensstand.cpp \
    Spieler.cpp \
    Punktestand.cpp

HEADERS  += \
    zeichenfeld.h \
    Angriff.h \
    Gegenstand.h \
    meinWidget.h \
    Lebensstand.h \
    Spieler.h \
    Punktestand.h

RESOURCES += \
    gegner.qrc
