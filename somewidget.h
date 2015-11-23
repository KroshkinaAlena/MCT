#ifndef SOMEWIDGET_H
#define SOMEWIDGET_H

#include <QWidget>
#include <QObject>
#include <QDeclarativeView>
#include <QVBoxLayout>

class SomeWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SomeWidget(QWidget *parent = 0);

signals:

public slots:
};

#endif // SOMEWIDGET_H
