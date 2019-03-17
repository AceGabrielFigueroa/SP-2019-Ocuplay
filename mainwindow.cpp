#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "CheckerBoard.h"
#include <fstream>
#include <QDebug>
#include <QFileDialog>
#include <QImage>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    // TODO: error check to see if line_box is an actually integer
    //

    int width=ui->image_w->text().toInt();
    int height=ui->image_h->text().toInt();
    qDebug() << width;
    qDebug() << height;

    CheckerBoard checker1 = CheckerBoard(width, height,
                                         ui->lr1c1->text().toInt(), ui->lr1c2->text().toInt(), true);

    CheckerBoard checker2 = CheckerBoard(width, height,
                                         ui->lr2c1->text().toInt(), ui->lr2c2->text().toInt(), true);

    CheckerBoard checker3 = CheckerBoard(width, height,
                                         ui->lr2c1->text().toInt(), ui->lr2c2->text().toInt(), true);

    CheckerBoard checker4 = CheckerBoard(width, height,
                                         ui->lr2c1->text().toInt(), ui->lr2c2->text().toInt(), true);

    CheckerBoard checker5 = CheckerBoard(width, height,
                                         ui->lr2c1->text().toInt(), ui->lr2c2->text().toInt(), true);

    CheckerBoard checker6 = CheckerBoard(width, height,
                                         ui->lr2c1->text().toInt(), ui->lr2c2->text().toInt(), true);

    CheckerBoard checker7 = CheckerBoard(width, height,
                                         ui->lr2c1->text().toInt(), ui->lr2c2->text().toInt(), true);

    CheckerBoard checker8 = CheckerBoard(width, height,
                                         ui->lr2c1->text().toInt(), ui->lr2c2->text().toInt(), true);

    int *result = new int[width * height];
    QString s;

    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            result[(i * height) + j] = (checker1.GetAt(i,j) ? 0x01 : 0x00) +
                                       (checker2.GetAt(i,j) ? 0x02 : 0x00) +
                                       (checker3.GetAt(i,j) ? 0x04 : 0x00) +
                                       (checker4.GetAt(i,j) ? 0x08 : 0x00) +
                                       (checker5.GetAt(i,j) ? 0x10 : 0x00) +
                                       (checker6.GetAt(i,j) ? 0x20 : 0x00) +
                                       (checker7.GetAt(i,j) ? 0x40 : 0x00) +
                                       (checker8.GetAt(i,j) ? 0x80 : 0x00);

        }
    }

    MainWindow::createImage(result, height, width);
}

void MainWindow::createImage(int *array, int height, int width) {

    std::ifstream _COLOR_TABLE_FILE("C:\\Users\\acegf\\Documents\\QT\\Visual\\resources\\color.txt");
    QColor _COLOR_TABLE[256];
    QImage image = QImage(width, height, QImage::Format_RGB888);
    int _TEMP_C;

    if(_COLOR_TABLE_FILE)
        for (QColor &c : _COLOR_TABLE)
        {
            _COLOR_TABLE_FILE >> _TEMP_C;
            c.setRed(_TEMP_C);

            _COLOR_TABLE_FILE >> _TEMP_C;
            c.setGreen(_TEMP_C);

            _COLOR_TABLE_FILE >> _TEMP_C;
            c.setBlue(_TEMP_C);
        }

    for (int i = 0; i < height; i++)
            for (int j = 0; j < width; j++)
                image.setPixelColor(i, j, _COLOR_TABLE[array[(i * height) + j]]);

    QString fileName = QFileDialog::getSaveFileName(this, tr("Save Image File"),
                                                        QString(),
                                                        tr("Images (*.bmp)"));
    image.save(fileName);
}
