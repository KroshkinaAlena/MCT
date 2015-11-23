#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "somewidget.h"
#include <QSplitter>

MainWindow::MainWindow(QWidget *parent) :  QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    int y = ui->PreviewFild->width()*595/842;
    ui->PreviewFild->resize(ui->PreviewFild->width(),y);

    QPalette pal1;
    pal1.setBrush(ui->centralWidget->backgroundRole(), QBrush(QPixmap ("grass.jpg")));
    ui->centralWidget->setPalette(pal1);
    ui->centralWidget->setAutoFillBackground(true);

    QPalette pal;
    pal.setBrush(ui->PreviewFild->backgroundRole(), QBrush(QPixmap ("paper1.jpg").scaled(ui->PreviewFild->width(),ui->PreviewFild->height(),Qt::IgnoreAspectRatio)));
    ui->PreviewFild->setPalette(pal);
    ui->PreviewFild->setAutoFillBackground(true);

    QWidget *w = new QWidget[10];
    for(int i=0;i<10;i++){
        QPalette pal2;
        pal2.setBrush(w[i].backgroundRole(),QBrush(QPixmap("paper1.jpg")));
        w[i].setPalette(pal2);
        w[i].setAutoFillBackground(true);
        w[i].setFixedSize(ui->scrollAreaWidgetContents_2->width(),100);
    }

    for(int i=0;i<10;i++){
        ui->verticalLayout_2->addWidget(&w[i],5,Qt::AlignCenter);
    }
    ui->scrollAreaWidgetContents_2->setLayout(ui->verticalLayout_2);
    QPalette palette;
    palette.setColor(ui->scrollAreaWidgetContents_2->backgroundRole(), Qt::transparent);
    ui->scrollAreaWidgetContents_2->setPalette(palette);

    //Table
    int n = 6;
    QWidget *ww = new QWidget[10];
    for(int i=0;i<10;i++){
        QPalette pal3;
        QPixmap pix("per1.jpg");
        pal3.setBrush(ww[i].backgroundRole(),QBrush(pix));
        ww[i].setPalette(pal3);
        ww[i].setAutoFillBackground(true);
        //ww[i].setFixedSize(pix.width(),pix.height());
    }
    ui->gridLayout_2->addWidget(&ww[0], 0, 0);
    ui->gridLayout_2->addWidget(&ww[1], 0, 1);
    //ui->gridLayout->addWidget(&ww[2], 1, 0);
    //ui->gridLayout->addWidget(&ww[3], 1, 1);
    //ui->gridLayout->addWidget(&ww[4], 0, 2);
    //ui->gridLayout->addWidget(&ww[5], 1, 2);
    ui->PreviewFild->setLayout(ui->gridLayout_2);


 }

MainWindow::~MainWindow()
{
    delete ui;
}
