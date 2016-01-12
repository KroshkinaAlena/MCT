#include "somewidget.h"

SomeWidget::SomeWidget(QWidget *parent) : QWidget(parent)
{
    QDeclarativeView* pv = new QDeclarativeView;
    pv->setSource(QUrl("re.qml"));
    QVBoxLayout* pvbx = new QVBoxLayout;
    pvbx->addWidget(pv);
    setLayout(pvbx);

}

