#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "scaledpixmap.h"






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

    ui->label_3->setStyleSheet("background-color: WhiteSmoke;");
    ui->textBrowser->setStyleSheet("background-color: WhiteSmoke;");
    ui->label->setStyleSheet("background-color: WhiteSmoke;");
    ui->horizontalSlider->setStyleSheet("background-color: WhiteSmoke;");





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


    Sql();
    connect(ui->horizontalSlider, SIGNAL(valueChanged(int)),ui->label, SLOT(setNum(int)));
    connect(ui->SubjectsList, SIGNAL(currentIndexChanged (QString)), this, SLOT(setPhotos(QString)));
    connect(ui->listWidget, SIGNAL(itemClicked(QListWidgetItem*)),this,SLOT(ViewPhoto(QListWidgetItem*)));


 }

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::Sql()
{
    QSqlDatabase sdb = QSqlDatabase::addDatabase("QSQLITE");
    sdb.setDatabaseName("mydatabase.sqlite");

    if (!sdb.open()){ qDebug() << "error"; }

    QSqlQuery a_query;

      /* Insert
        QString str_insert = "INSERT INTO subject(ID_subj, name_subj) "
                             "VALUES (%1, '%2');";
        QString str = str_insert.arg("3").arg("Chemistry");

        bool b = a_query.exec(str);
        if (!b)
        {
            qDebug() << "Кажется данные не вставляются, проверьте дверь, может она закрыта?";
        }
        */


        //Select
        if (!a_query.exec("SELECT name_subj FROM subject"))
        {
            qDebug() << "Даже селект не получается, я пас.";
        }

        QSqlRecord rec = a_query.record();
        int id = 0;
        QString subj = "";

        while (a_query.next())
        {
            //id = a_query.value(rec.indexOf("ID_subj")).toInt();
            subj = a_query.value(rec.indexOf("name_subj")).toString();
            ui->SubjectsList->addItem(subj);
        }




}

void MainWindow::ViewPhoto(QListWidgetItem* item)
{
    if(!ui->verticalLayout->isEmpty())
    {
        delete ui->verticalLayout->takeAt(0);
        //ui->gridLayout_2->removeItem( ui->gridLayout->takeAt(0));

    }
    ScaledPixmap* pic = new ScaledPixmap;
    pic->setScaledPixmap(QPixmap(item->data(0).toString()));
    ui->verticalLayout->addWidget(pic);

    ui->textBrowser->setText(item->data(4).toString());

}

void MainWindow::setPhotos(QString name)
{
    ui->listWidget->clear();

    QSqlQuery a_query;
    QString str = "SELECT path, comments FROM photo c JOIN Bond a ON c.ID_photo=a.ID_photo JOIN subject b ON a.ID_subj=b.ID_subj WHERE b.name_subj='"+name+"'";
    if (a_query.exec(str))
    {
        QSqlRecord rec = a_query.record();
        QString path = "";
        QString comments = "";
        while (a_query.next())
        {
            path = a_query.value(rec.indexOf("path")).toString();
            comments = a_query.value(rec.indexOf("comments")).toString();
            //qDebug()<<path<<"  "<<comments;
            ListOfPictures(path, comments);
        }
    }
    else qDebug() << "Даже селект не получается, я пас.";
}

void MainWindow::ListOfPictures(QString path,QString comment)
{
    QPixmap myPixmap( path );

    QListWidgetItem* item = 0;
    ui->listWidget->setIconSize(QSize(200,200));

        QString str;
        item = new QListWidgetItem(str.setNum(ui->listWidget->count()),ui->listWidget);
        item->setData(Qt::DisplayRole, path);
        item->setData(Qt::StatusTipRole,comment);
        item->setData(Qt::CheckStateRole, Qt::Checked);
        item->setIcon(myPixmap.scaled(100,100,Qt::KeepAspectRatio));
        ui->listWidget->addItem(item);
}
