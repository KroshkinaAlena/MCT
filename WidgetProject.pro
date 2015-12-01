#-------------------------------------------------
#
# Project created by QtCreator 2015-11-22T20:43:09
#
#-------------------------------------------------

QT       += core gui
QT += declarative
QT += qml quick
QT += gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = WidgetProject
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    somewidget.cpp \
    scaledpixmap.cpp

HEADERS  += mainwindow.h \
    somewidget.h \
    scaledpixmap.h

FORMS    += mainwindow.ui

DISTFILES += \
    Qml.qml
CONFIG+=qml_debug
