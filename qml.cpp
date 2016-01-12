#include "qml.h"

SomeWidget::SomeWidget(QWidget *parent) : QWidget(parent)
{
    QDeclarativeView* pv = new QDeclarativeView;
    pv->setSource(QUrl("Qml1.qml"));
    QVBoxLayout* pvbx = new QVBoxLayout;
    pvbx->addWidget(pv);
    setLayout(pvbx);

}

