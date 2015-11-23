#include "mainwindow.h"
#include <QApplication>
#include "somewidget.h"
#include <QtGui>
#include <QPixmap>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.show();
    return a.exec();
}
