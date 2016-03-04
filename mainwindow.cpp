#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setAttribute(Qt::WA_AcceptTouchEvents, true);

    QString path = "c:/workspace/image_maker/1.jpg";
    pixmap.load(path);
    scene = new QGraphicsScene(this);
    scene->addPixmap(pixmap);
    //scene->setSceneRect(pixmap.rect());
    //save_field(&pixmap, 0, 0, 512, 512);


    ui->mainImage->setScene(scene);
}

void MainWindow::save_field(QPixmap *pixmap, int x1, int y1, int x2, int y2){
    QPixmap field;
    field = pixmap->copy(x1, y1, x2, y2);
    field.save("cropped_image4.jpg");

}

void MainWindow::showEvent(QShowEvent * event){
    qDebug() << "sjfj";
    //ui->mainImage->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
}

void MainWindow::touchEvent(QTouchEvent *event)
{
    qDebug()<< event->type();
    switch (event->type())
    {
    case QEvent::TouchBegin:
        qDebug() << "ok1";
        break;
    case QEvent::TouchEnd:
        qDebug() << "ok1";
        break;
    case QEvent::TouchUpdate:
    {
        qDebug() << "ok1";
        break;
    }
    }
}


MainWindow::~MainWindow()
{
    delete scene;
    delete ui;
}
