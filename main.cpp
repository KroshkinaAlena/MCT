#include "mainwindow.h"
#include <QApplication>
#include "qml.h"
#include "scaledpixmap.h"
#include <QtGui>
#include <QHBoxLayout>
#include <QSpinBox>
#include <QSlider>

#include <QtSql/QSqlDatabase>
#include <QDebug>
#include <QtSql/QtSql>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.show();

    /*QHBoxLayout *hbox = new QHBoxLayout(0);
    //hbox->setCaption("Enter Your Age");
    hbox->setMargin(6);
    hbox->setSpacing(6);
    QSpinBox *spinBox = new QSpinBox(hbox);
    QSlider *slider = new QSlider(Qt::Horizontal, hbox);
    spinBox->setRange(0, 130);
    slider->setRange(0, 130);
    QObject::connect(spinBox, SIGNAL(valueChanged(int)),slider, SLOT(setValue(int)));
    QObject::connect(slider, SIGNAL(valueChanged(int)),
                     spinBox, SLOT(setValue(int)));
    spinBox->setValue(35);
    app.setMainWidget(hbox);
    hbox->show();
*/
    return a.exec();
}
