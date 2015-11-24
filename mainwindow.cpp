#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "somewidget.h"
#include <QSplitter>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent) :  QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //int y = ui->PreviewFild->width()*595/842;
    //ui->PreviewFild->resize(ui->PreviewFild->width(),y);

    QPalette pal1;
    pal1.setBrush(ui->centralWidget->backgroundRole(), QBrush(QPixmap ("grass.jpg")));
    ui->centralWidget->setPalette(pal1);
    ui->centralWidget->setAutoFillBackground(true);

    QPalette pal;
    pal.setBrush(ui->PreviewFild->backgroundRole(), QBrush(QPixmap ("paper1.jpg").scaled(ui->PreviewFild->width(),ui->PreviewFild->height(),Qt::IgnoreAspectRatio)));
    ui->PreviewFild->setPalette(pal);
    ui->PreviewFild->setAutoFillBackground(true);


    QPixmap myPixmap( "paper.jpg" );
    QLabel *label = new QLabel[10];

    for(int i = 0; i < 10; i++){
        label[i].setPixmap( myPixmap );
    }

    for(int i = 0; i < 10; i++){
        ui->verticalLayout_2->addWidget(&label[i], 5, Qt::AlignCenter);
    }
    QPalette palette;
    palette.setColor(ui->scrollAreaWidgetContents_2->backgroundRole(), Qt::transparent);
    ui->scrollAreaWidgetContents_2->setPalette(palette);

    //Table
    int n = 6;
    QPixmap myPixmap2( "cat.gif" );
    QLabel *label2 = new QLabel[50];

    for(int i = 0; i < 50; i++){
        label2[i].setPixmap( myPixmap2 );
    }
    int k = 0;
    for(int i = 0; i < 7; i++)
         for(int j = 0; j < 7; j++)
             ui->gridLayout_2->addWidget(&label2[k++], i, j, Qt::AlignCenter);

 }

MainWindow::~MainWindow()
{
    delete ui;
}
