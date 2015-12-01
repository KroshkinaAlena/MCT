#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <scaledpixmap.h>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void ListOfPictures();
    void Connections(ScaledPixmap pic);
    ScaledPixmap func();

public:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
