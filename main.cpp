#include "mainwindow.h"
#include <QApplication>
#include <QImage>
#include <QPainter>
#include <QGraphicsScene>

int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    QGraphicsScene* scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 2, 2);

    QImage img(scene->sceneRect().size().toSize(), QImage::Format_RGB32);

    QPainter painter(&img);
    scene->render(&painter);

    bool b = img.save("test.bmp");

    Q_ASSERT(b);

    return 0;
}
