#-------------------------------------------------
#
# Project created by QtCreator 2015-11-22T20:43:09
#
#-------------------------------------------------

QT       += core gui
QT += declarative
QT += qml quick
QT += gui
QT += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = WidgetProject
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    scaledpixmap.cpp \
    qml.cpp

HEADERS  += mainwindow.h \
    scaledpixmap.h \
    qml.h

FORMS    += mainwindow.ui

DISTFILES += \
    QML.qml \
    Qml1.qml
CONFIG+=qml_debug
