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

    foreach (QComboBox *comboBox, findChildren<QComboBox*>())
    {
        comboBox->addItem("Select a shape");
        comboBox->addItem("Rectangle");
        comboBox->addItem("Triangle");
        comboBox->addItem("Ellipse");
        comboBox->addItem("Broken Square");
        comboBox->addItem("Square with Hole");
        comboBox->addItem("Quadrilateral");
    }
    int index = 1;
    foreach (QSpinBox *sb, findChildren<QSpinBox*>())
    {
        sb->setSingleStep(1);
        sb->setRange(1, 8);
        sb->setValue(index);
            index++;
    }
    index = 0;
    //ui->le_img_h->setObjectName("height");
    //ui->le_img_wd->setObjectName("width");

}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::convertTexttoInt(QString text) //selection is the text from ComboBoxSelections functions
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
    return 0;
}

BooleanBitmap* MainWindow::pickShape(int choice, int rowNum)
{
    int width = ui->Width->text().toInt();
    int height = ui->Height->text().toInt();
    switch (choice)
    {
    case 1:
        return new CheckerBoard(width, height, cols[rowNum] , rows[rowNum], true);

    case 2:
        return new TriangleBoard(width, height, cols[rowNum], rows[rowNum], true);

    case 3:
        return new EllipseBoard(width, height, cols[rowNum], rows[rowNum], true);


    case 4:
        return new BrokenSqr(width, height, cols[rowNum], rows[rowNum], true);

    case 5:

        return new SquareWithHole(width, height, cols[rowNum], rows[rowNum], true);

    case 6:
        return new Quadrilateral(width, height, cols[rowNum], rows[rowNum], true);

    default:
        qDebug() << "Must select a shape";
    }

    return new CheckerBoard(width, height, cols[rowNum], rows[rowNum], true);
}

void MainWindow::createImage()
{
   int width=ui->Width->text().toInt();
   int height=ui->Height->text().toInt();
   fillRC();

   int index = 0;
      foreach (QComboBox *comboBox, findChildren<QComboBox*>())
      {
          boards[index] = pickShape(convertTexttoInt(comboBox->currentText()), index);
          index++;
      }

      int *result = new int[width * height];

      for(int i = 0; i < height; i++)
      {
          for(int j = 0; j < width; j++)
          {
              result[(i * height) + j] = (boards[0]->GetAt(i,j) ? 0x01 : 0x00) +
                                           (boards[1]->GetAt(i,j) ? 0x02 : 0x00) +
                                           (boards[2]->GetAt(i,j) ? 0x04 : 0x00) +
                                           (boards[3]->GetAt(i,j) ? 0x08 : 0x00) +
                                           (boards[4]->GetAt(i,j) ? 0x10 : 0x00) +
                                           (boards[5]->GetAt(i,j) ? 0x20 : 0x00) +
                                           (boards[6]->GetAt(i,j) ? 0x40 : 0x00) +
                                           (boards[7]->GetAt(i,j) ? 0x80 : 0x00);

       }
   }

   colorImage(result, height, width);
}

// This display an image onto the QLabel
void MainWindow::displayImage(QImage img)
{
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

   std::ifstream _COLOR_TABLE_FILE("C:/Users/acegf/Documents/QT/Visual/res/color.txt");

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

void MainWindow::fillRC()
{
    rows[0] = ui->le_r1->text().toInt();
    rows[1] = ui->le_r2->text().toInt();
    rows[2] = ui->le_r3->text().toInt();
    rows[3] = ui->le_r4->text().toInt();
    rows[4] = ui->le_r5->text().toInt();
    rows[5] = ui->le_r6->text().toInt();
    rows[6] = ui->le_r7->text().toInt();
    rows[7] = ui->le_r8->text().toInt();
    cols[0] = ui->le_c1->text().toInt();
    cols[1] = ui->le_c2->text().toInt();
    cols[2] = ui->le_c3->text().toInt();
    cols[3] = ui->le_c4->text().toInt();
    cols[4] = ui->le_c5->text().toInt();
    cols[5] = ui->le_c6->text().toInt();
    cols[6] = ui->le_c7->text().toInt();
    cols[7] = ui->le_c8->text().toInt();
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

void MainWindow::on_btn_create_img_clicked()
{
    qDebug() << getLayerMode();
    switch (getLayerMode())
        {
        case 1://single
            createSingleLayerImage();
            break;
        case 2://xor
            TwoLayeredImages(false);
            break;
        case 3://or
            TwoLayeredImages(true);
            break;
        default:
            createSingleLayerImage();
        }
    displayImage(myImage);
}

int MainWindow::getLayerMode()
{

    if (ui->rb_lyr_1->isChecked())

        return 1;

    else if (ui->rb_ly_xor->isChecked())

        return 2;

    else if (ui->rb_ly_or->isChecked())

        return 3;
    return 1;
}

void MainWindow::createSingleLayerImage()
{
    createImage();
}

void MainWindow::TwoLayeredImages(bool truth)
{
    int index = 0;
    int selected;
    // Create OR'd or XOR'ed CheckerBoards
    foreach (QSpinBox *sb, findChildren<QSpinBox*>())
    {
        //qDebug() << "index: " << index << " value: " << sb->value() << " NewVal: " << ((sb->value()) - 1);
        selected = ((sb->value()) - 1);
        //BooleanBitmap* left = boards[index];//current board
        //BooleanBitmap* right = boards[(sb->value()) - 1];//selected board
        boards[index] = new BooleanBitmap(boards[index], boards[selected], truth);
        index++;
    }
    createImage();
}

// Logic for creating an image
void MainWindow::on_btn_save_img_clicked()
{
   saveImage();
}

//make string array
void MainWindow::on_btn_random_clicked()
{
    QString s;
    foreach(QLineEdit* le, findChildren<QLineEdit*>())
    {
        if(!(ifSpinBox(le->objectName())))
        {
          s = QString::number(int(qPow(2, rand() % 4 + 1)));
          le->setText(s);

          //qDebug() << le->objectName() ;
        }
    }
}

bool MainWindow::ifSpinBox(QString test)
{
    if((test == "Width") || (test == "Height") || (test == "qt_spinbox_lineedit"))
    {
        return true;
    }
    return false;
}

void MainWindow::on_btn_reset_clicked()
{
    foreach(QLineEdit* le, findChildren<QLineEdit*>())
    {
        le->clear();
    }
}
