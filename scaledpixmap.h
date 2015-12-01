#ifndef SCALEDPIXMAP_H
#define SCALEDPIXMAP_H

#include <QWidget>
#include <QLabel>
#include <QPixmap>

QT_FORWARD_DECLARE_CLASS(QPaintEvent)

class ScaledPixmap : public QLabel
{
public:
    explicit ScaledPixmap(QWidget *parent = Q_NULLPTR);
    ScaledPixmap(const ScaledPixmap& copy);


public slots:
    void setScaledPixmap(const QPixmap& pixmap);
    void Repaint(int value);

protected:
    void paintEvent(QPaintEvent*);


private:
    QPixmap m_pixmap;
    bool flag;
    int m_value;

};



#endif // SCALEDPIXMAP_H
