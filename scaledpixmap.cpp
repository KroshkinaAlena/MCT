#include "scaledpixmap.h"
#include <QPainter>
#include "mainwindow.h"

ScaledPixmap::ScaledPixmap(QWidget *parent):QLabel(parent)
{}

ScaledPixmap::ScaledPixmap(const ScaledPixmap &copy)
{
    this->m_pixmap=copy.m_pixmap;
    this->m_value=copy.m_value;
}


void ScaledPixmap::setScaledPixmap(const QPixmap &pixmap)
{
    m_pixmap = pixmap;
    flag=true;
    update();
}

void ScaledPixmap::Repaint(int value)
{
    flag=false;
    m_value = value;
    repaint();
}


void ScaledPixmap::paintEvent(QPaintEvent *const event)
{
    QPainter painter(this);
    if(!m_pixmap.isNull())
    {
        QPoint centerPoint(0,0);

        int newH = size().height()-10;
        int newW = size().width()-10;
        QSize scaledSize = QSize(newW,newH);

        QPixmap scaledPixmap;
        if(flag) scaledPixmap = m_pixmap.scaled(scaledSize,Qt::KeepAspectRatio);
        else scaledPixmap = m_pixmap.scaled(m_pixmap.width()*m_value,m_pixmap.height()*m_value,Qt::IgnoreAspectRatio);
        centerPoint.setX((scaledSize.width() - scaledPixmap.width())/2+5);
        centerPoint.setY((scaledSize.height() - scaledPixmap.height())/2+5);
        painter.drawPixmap(centerPoint, scaledPixmap);
    }
    QLabel::paintEvent(event);
}


