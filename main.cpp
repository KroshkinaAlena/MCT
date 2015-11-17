#include <QApplication>
#include <QQmlApplicationEngine>
#include <QtGui>
#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    /*QScrollArea sa;
    QWidget* pwgt = new QWidget;
    QPixmap pix("c:/Projects/Images/el.png");
    QPalette pal;
    pal.setBrush(pwgt->backgroundRole(),QBrush(pix));
    pwgt->setPalette(pal);
    pwgt->setAutoFillBackground(true);
    pwgt->setFixedSize(pix.width(),pix.height());
    sa.setWidget(pwgt);
    sa.resize(350,150);
    sa.show();*/

    return app.exec();
}

