#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "somewidget.h"
#include "scaledpixmap.h"
#include <QSplitter>
#include <QLabel>
#include <QListWidget>


MainWindow::MainWindow(QWidget *parent) :  QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    // Стиль списка
    ui->listWidget->setStyleSheet("color: black;"
                                  "background-color: grey;"
                                  "selection-color: grey;"
                                  "selection-background-color: grey;"
                                  "border-style: outset;"
                                  "background-image: url(ferrow2.jpg);"
                                  "background-attachment: fixed;"
                                  );
    //Стиль прокрутки
    ui->ViewFild->setStyleSheet("background-image: url(ferrow2.jpg);"
                                "background-attachment: fixed;");




    //Table
    /*QPalette pal;
    pal.setBrush(ui->PreviewFild->backgroundRole(), QBrush(QPixmap ("paper1.jpg").scaled(ui->PreviewFild->width(),ui->PreviewFild->height(),Qt::IgnoreAspectRatio)));
    ui->PreviewFild->setPalette(pal);
    ui->PreviewFild->setAutoFillBackground(true);
    */
    /*QPixmap myPixmap2( "cat.gif" );
    ScaledPixmap *label2 = new ScaledPixmap[50];

    for(int i = 0; i < 50; i++){
        label2[i].setScaledPixmap(myPixmap2);
    }
    int k = 0;
    for(int i = 0; i < 7; i++)
         for(int j = 0; j < 7; j++)
             ui->gridLayout->addWidget(&label2[k++], i, j);
             */


    ListOfPictures();





 }

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ListOfPictures()
{
    QPixmap myPixmap( "paper.jpg" );

    QListWidgetItem* item = 0;
    //ui->listWidget->setIconSize(QSize(200,200));

    for(int i = 0; i < 10; i++){
        QString str;
        str.setNum(i+1);
        item = new QListWidgetItem(str,ui->listWidget);
        item->setData(Qt::DisplayRole, str);
        item->setData(Qt::CheckStateRole, Qt::Checked);
        //item->setData(Qt::DecorationRole ,icon);
        item->setData(Qt::DecorationRole ,myPixmap.scaled(100,100,Qt::KeepAspectRatio));
        ui->listWidget->addItem(item);
        //item->setIcon(as);
    }
}

void MainWindow::Connections(ScaledPixmap pic)
{

    QObject::connect(ui->horizontalSlider, SIGNAL(valueChanged(int)),
                     &pic, SLOT(ScaledPixmap::Repaint(int value)));

}

ScaledPixmap MainWindow::func()
{
    ScaledPixmap pic;;
    pic.setScaledPixmap(QPixmap("paper.jpg"));
    ui->gridLayout_2->addWidget(&pic);
    return pic;
}
