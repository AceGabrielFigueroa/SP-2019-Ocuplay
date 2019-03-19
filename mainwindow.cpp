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

// Logic for creating an image
void MainWindow::on_btn_create_img_clicked()
{
    // TODO: error check to see if line_box is an actually integer
    //

    int width=ui->le_img_wd->text().toInt();
    int height=ui->le_img_h->text().toInt();
    qDebug() << width;
    qDebug() << height;

    CheckerBoard checker1 = CheckerBoard(width, height,
                                         ui->le_c1->text().toInt(), ui->le_r1->text().toInt(), true);

    CheckerBoard checker2 = CheckerBoard(width, height,
                                         ui->le_c2->text().toInt(), ui->le_r2->text().toInt(), true);

    CheckerBoard checker3 = CheckerBoard(width, height,
                                         ui->le_c3->text().toInt(), ui->le_r3->text().toInt(), true);

    CheckerBoard checker4 = CheckerBoard(width, height,
                                         ui->le_c4->text().toInt(), ui->le_r4->text().toInt(), true);

    CheckerBoard checker5 = CheckerBoard(width, height,
                                         ui->le_c5->text().toInt(), ui->le_r5->text().toInt(), true);

    CheckerBoard checker6 = CheckerBoard(width, height,
                                         ui->le_c6->text().toInt(), ui->le_r6->text().toInt(), true);

    CheckerBoard checker7 = CheckerBoard(width, height,
                                         ui->le_c7->text().toInt(), ui->le_r7->text().toInt(), true);

    CheckerBoard checker8 = CheckerBoard(width, height,
                                         ui->le_c8->text().toInt(), ui->le_r8->text().toInt(), true);

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

// This display an image onto the QLabel
void MainWindow::displayImage(QImage img) {
    ui->lbl_display->setPixmap(QPixmap::fromImage(img).scaled(ui->lbl_display->width(),
                                                              ui->lbl_display->height(),
                                                              Qt::KeepAspectRatio,
                                                              Qt::SmoothTransformation));
}

// This creates an image in memory. Can save if wanted.
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

    /*
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save Image File"),
                                                        QString(),
                                                        tr("Images (*.bmp)"));
    image.save(fileName);
    */

    displayImage(image);
}

// Notifies the user if the input is accepted or not
void MainWindow::on_le_r1_textChanged(const QString &arg1)
{   bool* check = new bool(false);

    arg1.toInt(check);

    if(*check) {
        if(checkNum(ui->le_img_h->text().toInt(),
                    ui->le_r1->text().toInt())) {
            ui->le_r1->setStyleSheet("background-color: lightgreen");
        } else {
         ui->le_r1->setStyleSheet("background-color: lightred");
        }
    } else {
        ui->le_r1->setStyleSheet("background-color: lightgray");
    }

    delete check;
}

// Checks if the num is a factor of it
// Mainly used to check if the user inputs a width/height
// is divisible by the col/row
bool MainWindow::checkNum(int a, int b) {
    if(a % b) {
        return false;
    }
    else {
        return true;
    }
}
