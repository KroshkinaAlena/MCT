#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "somewidget.h"

MainWindow::MainWindow(QWidget *parent) :  QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPalette pal1;
    pal1.setBrush(ui->centralWidget->backgroundRole(), QBrush(QPixmap ("table4.jpg")));
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
        w[i].setFixedSize(ui->scrollAreaWidgetContents->width()-50,100);
    }

    for(int i=0;i<10;i++){
        ui->verticalLayout->addWidget(&w[i],5,Qt::AlignCenter);
    }
    ui->scrollAreaWidgetContents->setLayout(ui->verticalLayout);
    QPalette palette;
    palette.setColor(ui->scrollAreaWidgetContents->backgroundRole(), Qt::transparent);
    ui->scrollAreaWidgetContents->setPalette(palette);

    //Table


}

MainWindow::~MainWindow()
{
    delete ui;
}
