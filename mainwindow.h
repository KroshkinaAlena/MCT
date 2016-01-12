#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <scaledpixmap.h>
#include <QtSql/QSqlDatabase>
#include <QDebug>
#include <QtSql/QtSql>
#include <QLabel>
#include <QListWidget>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void ListOfPictures(QString path, QString comment);

    void Sql();

public:
    Ui::MainWindow *ui;
private slots:
    void setPhotos(QString);
    void ViewPhoto(QListWidgetItem*);
};

#endif // MAINWINDOW_H
