#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QLabel>
#include <QCursor>
#include <QPicture>
#include <QImage>
#include <QTouchEvent>
#include <QEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    //bool event(QEvent *event);
    void touchEvent(QTouchEvent *event);
    void showEvent(QShowEvent * event);

private:
    void save_field(QPixmap *pixmap, int x1, int y1, int x2, int y2);

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QPixmap pixmap;
    QPicture picture;
    QImage image;
};

#endif // MAINWINDOW_H
