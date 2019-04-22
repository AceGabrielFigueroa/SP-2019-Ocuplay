#include "include/gui/mainwindow.h"
#include "ui_mainwindow.h"
#include "include/CheckerBoard.h"
#include "include/EllipseBoard.h"
#include "include/SquareWithHole.h"
#include "include/BrokenSqr.h"
#include "include/Quadrilateral.h"
#include "include/TriangleBoard.h"
#include <fstream>
#include <QDebug>
#include <QFileDialog>
#include <QImage>
#include <QtMath>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->buttonGroup->setId(ui->rb_rect, 0);
    ui->buttonGroup->setId(ui->rb_triangle, 1);
    ui->buttonGroup->setId(ui->rb_ellipse, 2);
    ui->buttonGroup->setId(ui->rb_brokensqr, 3);
    ui->buttonGroup->setId(ui->rb_sqr_w_hole, 4);
    ui->buttonGroup->setId(ui->rb_quad, 5);

    ui->comboBox->addItem("Select a shape");
    ui->comboBox->addItem("Rectangle");
    ui->comboBox->addItem("Triangle");
    ui->comboBox->addItem("Ellipse");
    ui->comboBox->addItem("Broken Square");
    ui->comboBox->addItem("Square with Hole");
    ui->comboBox->addItem("Quadrilateral");

    ui->comboBox_2->addItem("Select a shape");
    ui->comboBox_2->addItem("Rectangle");
    ui->comboBox_2->addItem("Triangle");
    ui->comboBox_2->addItem("Ellipse");
    ui->comboBox_2->addItem("Broken Square");
    ui->comboBox_2->addItem("Square with Hole");
    ui->comboBox_2->addItem("Quadrilateral");

    ui->comboBox_3->addItem("Select a shape");
    ui->comboBox_3->addItem("Rectangle");
    ui->comboBox_3->addItem("Triangle");
    ui->comboBox_3->addItem("Ellipse");
    ui->comboBox_3->addItem("Broken Square");
    ui->comboBox_3->addItem("Square with Hole");
    ui->comboBox_3->addItem("Quadrilateral");

    ui->comboBox_4->addItem("Select a shape");
    ui->comboBox_4->addItem("Rectangle");
    ui->comboBox_4->addItem("Triangle");
    ui->comboBox_4->addItem("Ellipse");
    ui->comboBox_4->addItem("Broken Square");
    ui->comboBox_4->addItem("Square with Hole");
    ui->comboBox_4->addItem("Quadrilateral");

    ui->comboBox_5->addItem("Select a shape");
    ui->comboBox_5->addItem("Rectangle");
    ui->comboBox_5->addItem("Triangle");
    ui->comboBox_5->addItem("Ellipse");
    ui->comboBox_5->addItem("Broken Square");
    ui->comboBox_5->addItem("Square with Hole");
    ui->comboBox_5->addItem("Quadrilateral");

    ui->comboBox_6->addItem("Select a shape");
    ui->comboBox_6->addItem("Rectangle");
    ui->comboBox_6->addItem("Triangle");
    ui->comboBox_6->addItem("Ellipse");
    ui->comboBox_6->addItem("Broken Square");
    ui->comboBox_6->addItem("Square with Hole");
    ui->comboBox_6->addItem("Quadrilateral");

    ui->comboBox_7->addItem("Select a shape");
    ui->comboBox_7->addItem("Rectangle");
    ui->comboBox_7->addItem("Triangle");
    ui->comboBox_7->addItem("Ellipse");
    ui->comboBox_7->addItem("Broken Square");
    ui->comboBox_7->addItem("Square with Hole");
    ui->comboBox_7->addItem("Quadrilateral");

    ui->comboBox_8->addItem("Select a shape");
    ui->comboBox_8->addItem("Rectangle");
    ui->comboBox_8->addItem("Triangle");
    ui->comboBox_8->addItem("Ellipse");
    ui->comboBox_8->addItem("Broken Square");
    ui->comboBox_8->addItem("Square with Hole");
    ui->comboBox_8->addItem("Quadrilateral");

    //ui->le_img_h->setObjectName("height");
    //ui->le_img_wd->setObjectName("width");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ComboBoxSelections()
{
    QString text;

    text = ui->comboBox->currentText();

    ConvertTexttoInt(text);

    text = ui->comboBox_2->currentText();

    ConvertTexttoInt(text);

    text = ui->comboBox_3->currentText();

    ConvertTexttoInt(text);

    text = ui->comboBox_4->currentText();

    ConvertTexttoInt(text);

    text = ui->comboBox_5->currentText();

    ConvertTexttoInt(text);

    text = ui->comboBox_6->currentText();

    ConvertTexttoInt(text);

    text = ui->comboBox_7->currentText();

    ConvertTexttoInt(text);

    text = ui->comboBox_8->currentText();

    ConvertTexttoInt(text);
}

int MainWindow::ConvertTexttoInt(QString text) //selection is the text from ComboBoxSelections functions
{
    if (text == "Rectangle")

        return 1;

    else if (text == "Triangle")

        return 2;

    else if (text == "Ellipse")

        return 3;

    else if (text == "Broken Square")

        return 4;

    else if (text == "Square with Hole")

        return 5;

    else if (text == "Quadrilateral")

        return 6;
}

CheckerBoard MainWindow::pickShape(int choice)
{
    switch (choice)
    {
    case 1:

        return CheckerBoard(ui->Width->text().toInt(), ui->Height->text().toInt(), ui->le_c1->text().toInt(), ui->le_r1->text().toInt(), true);

        break;

    case 2:

        return TriangleBoard(ui->Width->text().toInt(), ui->Height->text().toInt(), ui->le_c1->text().toInt(), ui->le_r1->text().toInt(), true);

        break;

    case 3:

        return EllipseBoard(ui->Width->text().toInt(), ui->Height->text().toInt(), ui->le_c1->text().toInt(), ui->le_r1->text().toInt(), true);

        break;

    case 4:

        return BrokenSqr(ui->Width->text().toInt(), ui->Height->text().toInt(), ui->le_c1->text().toInt(), ui->le_r1->text().toInt(), true);

        break;

    case 5:

        return SquareWithHole(ui->Width->text().toInt(), ui->Height->text().toInt(), ui->le_c1->text().toInt(), ui->le_r1->text().toInt());

        break;
    case 6:

        return Quadrilateral(ui->Width->text().toInt(), ui->Height->text().toInt(), ui->le_c1->text().toInt(), ui->le_r1->text().toInt(), true);

        break;

    default:
        qDebug() << "Must select a shape";

    }
}

// Logic for creating an image
void MainWindow::on_btn_save_img_clicked()
{

   // TODO: error check to see if line_box is an actually integer
   //

   qDebug()<< ui->buttonGroup->checkedId();
   saveImage();
}

void MainWindow::createImage()
{
   qDebug()<< ui->buttonGroup->checkedId();

   int width=ui->Width->text().toInt();
   int height=ui->Height->text().toInt();

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

   colorImage(result, height, width);
}

// This display an image onto the QLabel
void MainWindow::displayImage(QImage img) {
   ui->lbl_display->setPixmap(QPixmap::fromImage(img).scaled(ui->lbl_display->width(),
                                                             ui->lbl_display->height(),
                                                             Qt::KeepAspectRatio,
                                                             Qt::SmoothTransformation));
}

void MainWindow::saveImage()
{
   QString fileName = QFileDialog::getSaveFileName(this, tr("Save Image File"),
                                                       QString(),
                                                       tr("Images (*.bmp)"));
   myImage.save(fileName);


   //displayImage(image);
}

// This creates an image in memory. Can save if wanted.

void MainWindow::colorImage(int *array, int height, int width) {

   std::ifstream _COLOR_TABLE_FILE("res/");

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

   displayImage(image);
*/
   myImage = image;
}

// Notifies the user if the input is accepted or not
void MainWindow::on_le_r1_textChanged(const QString &arg1) { textChanged_notify(ui->Height, ui->le_r1, arg1); }
void MainWindow::on_le_r2_textChanged(const QString &arg1) { textChanged_notify(ui->Height, ui->le_r2, arg1); }
void MainWindow::on_le_r3_textChanged(const QString &arg1) { textChanged_notify(ui->Height, ui->le_r3, arg1); }
void MainWindow::on_le_r4_textChanged(const QString &arg1) { textChanged_notify(ui->Height, ui->le_r4, arg1); }
void MainWindow::on_le_r5_textChanged(const QString &arg1) { textChanged_notify(ui->Height, ui->le_r5, arg1); }
void MainWindow::on_le_r6_textChanged(const QString &arg1) { textChanged_notify(ui->Height, ui->le_r6, arg1); }
void MainWindow::on_le_r7_textChanged(const QString &arg1) { textChanged_notify(ui->Height, ui->le_r7, arg1); }
void MainWindow::on_le_r8_textChanged(const QString &arg1) { textChanged_notify(ui->Height, ui->le_r8, arg1); }

void MainWindow::on_le_c1_textChanged(const QString &arg1) { textChanged_notify(ui->Width, ui->le_c1, arg1); }
void MainWindow::on_le_c2_textChanged(const QString &arg1) { textChanged_notify(ui->Width, ui->le_c2, arg1); }
void MainWindow::on_le_c3_textChanged(const QString &arg1) { textChanged_notify(ui->Width, ui->le_c3, arg1); }
void MainWindow::on_le_c4_textChanged(const QString &arg1) { textChanged_notify(ui->Width, ui->le_c4, arg1); }
void MainWindow::on_le_c5_textChanged(const QString &arg1) { textChanged_notify(ui->Width, ui->le_c5, arg1); }
void MainWindow::on_le_c6_textChanged(const QString &arg1) { textChanged_notify(ui->Width, ui->le_c6, arg1); }
void MainWindow::on_le_c7_textChanged(const QString &arg1) { textChanged_notify(ui->Width, ui->le_c7, arg1); }
void MainWindow::on_le_c8_textChanged(const QString &arg1) { textChanged_notify(ui->Width, ui->le_c8, arg1); }


// Logic to notify user if input is accepted or not
// determines if inputs can be convert from Qstring -> int
// if not, display a color
// then determine if int is a factor
// CRASHES IF 0 % 0
void MainWindow::textChanged_notify(QLineEdit* q1, QLineEdit *q2, const QString &arg1) {
   bool* check = new bool(false);
   arg1.toInt(check);

   if(*check) {
       if(checkNum(q1->text().toInt(), q2->text().toInt())) {
           q2->setStyleSheet("background-color: lightgreen");
        } else {
           q2->setStyleSheet("background-color: pink");
        }
   } else {
       q2->setStyleSheet("background-color: lightgrey");
   }

   delete check;
}


// Checks if the num is a factor of it
// Mainly used to check if the user inputs a width/height
// is divisible by the col/row
bool MainWindow::checkNum(int a, int b) {

   if(a % (b ? b : 1)) {
       return false;
   }
   else {
       return true;
   }
}

//make string array
void MainWindow::on_btn_random_clicked()
{
    QString s;
    foreach(QLineEdit* le, findChildren<QLineEdit*>())
    {
        if(!((le->objectName() == "Width") || (le->objectName() == "Height")))
        {
          s = QString::number(int(qPow(2, rand() % 5 + 1)));
          le->setText(s);

          qDebug() << le->accessibleName() ;
        }
    }
}

void MainWindow::on_btn_reset_clicked()
{
    foreach(QLineEdit* le, findChildren<QLineEdit*>())
    {
        le->clear();
    }
}

void MainWindow::on_btn_create_img_clicked()
{
    createImage();
    displayImage(myImage);
}
