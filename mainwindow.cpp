#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QFileDialog>
#include <fstream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->setFixedSize(540,425);

    ui->setupUi(this);
    ui->checkBox_2->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Could combine these two functions to make a loop
void MainWindow::UINT_32_LITTLE_ENDIAN(char* _DATA, unsigned int _BEGIN, unsigned int num) {
    _DATA[_BEGIN] = static_cast<char>(num & 0xFF);
    _DATA[_BEGIN + 1] = static_cast<char>((num >> 8) & 0XFF);
    _DATA[_BEGIN + 2] = static_cast<char>((num >> 16) & 0xFF);
    _DATA[_BEGIN + 3] = static_cast<char>((num >> 24) & 0XFF);
}

void MainWindow::UINT_16_LITTLE_ENDIAN(char* _DATA, unsigned int _BEGIN, unsigned int num) {

    _DATA[_BEGIN] = static_cast<char>(num & 0xFF);
    _DATA[_BEGIN + 1] = static_cast<char>((num >> 8) & 0xFF);
}

void MainWindow::createBitMap() {

    char* _DATA = new char[54 + (img_height * img_width)];

        // Header field
        _DATA[0] = 0x42;
        _DATA[1] = 0x4D;

        // File Size
        _DATA[2] = 0x46;
        _DATA[3] = 0;
        _DATA[4] = 0;
        _DATA[5] = 0;

        // Data reserved
        _DATA[6] = 0;
        _DATA[7] = 0;
        _DATA[8] = 0;
        _DATA[9] = 0;

        // Offset
        _DATA[10] = 0x36;
        _DATA[11] = 0;
        _DATA[12] = 0;
        _DATA[13] = 0;

        // Size of header
        _DATA[14] = 0x28;
        _DATA[15] = 0;
        _DATA[16] = 0;
        _DATA[17] = 0;

        // Bitmap width in pixels
        /*
        _DATA[18] = 0x02;
        _DATA[19] = 0;
        _DATA[20] = 0;
        _DATA[21] = 0;
        */
        UINT_32_LITTLE_ENDIAN(_DATA, 18, 0x02);

        // Bitmap height in pixels
        UINT_32_LITTLE_ENDIAN(_DATA, 22, 0x02);

        // Color plane
        /*
        _DATA[26] = 0x01;
        _DATA[27] = 0;
        */
        UINT_16_LITTLE_ENDIAN(_DATA, 26, 0x05);

        // Number of bits per pixel
        //_DATA[28] = 0x18;
        //_DATA[29] = 0;
        UINT_16_LITTLE_ENDIAN(_DATA, 28, 0x18);

        // Compression method
        _DATA[30] = 0;
        _DATA[31] = 0;
        _DATA[32] = 0;
        _DATA[33] = 0;

        // Image size
        _DATA[34] = 0x10;
        _DATA[35] = 0;
        _DATA[36] = 0;
        _DATA[37] = 0;

        // Horizontal Resolution
        _DATA[38] = 0x13;
        _DATA[39] = 0x0b;
        _DATA[40] = 0;
        _DATA[41] = 0;

        // Vertical Resolution
        _DATA[42] = 0x13;
        _DATA[43] = 0x0b;
        _DATA[44] = 0;
        _DATA[45] = 0;

        // Number of colors in palettes
        _DATA[46] = 0;
        _DATA[47] = 0;
        _DATA[48] = 0;
        _DATA[49] = 0;

        // Number of important colors
        _DATA[50] = 0;
        _DATA[51] = 0;
        _DATA[52] = 0;
        _DATA[53] = 0;

        // Color Table
        _DATA[54] = 0;
        _DATA[55] = 0;
        _DATA[56] = 0xff;

        _DATA[57] = 255;
        _DATA[58] = 255;
        _DATA[59] = 255;

        _DATA[60] = 0;
        _DATA[61] = 0;

        _DATA[62] = 255;
        _DATA[63] = 0;
        _DATA[64] = 0;

        _DATA[65] = 0;
        _DATA[66] = 255;
        _DATA[67] = 0;

        _DATA[68] = 0;
        _DATA[69] = 0;

        /*
        // Color table
        for(unsigned int i = 0; i < img_height; i++)
            for(unsigned int j = 0; j < img_width; j++)
            {
                _DATA[54 + (img_height * img_width) + j] = 0;
            }
*/
    std::ofstream fout;
    fout.open("C:\\Users\\acegf\\Desktop\\OLD COURSES\\img.bmp");

    for(unsigned int i = 0; i < 70; i++) {
        fout << _DATA[i];

        std::cout << "HERE" << std::endl;
    }

    if(_DATA)
        delete[] _DATA;

    fout.close();
}

// Random Button Check Box
void MainWindow::on_checkBox_toggled(bool checked)
{
    if(checked)
    {
        ui->checkBox_2->show();
    }
    else {
        ui->checkBox_2->hide();
    }
}

// Open Color Table File Finder
void MainWindow::on_pushButton_clicked()
{
    colorPath = QFileDialog::getOpenFileName(this, tr("Open Color Table"), "/desktop", tr("Image Files (*.png *.jpg *.bmp)"));

}

void MainWindow::on_test_button_clicked()
{
    /*
    // Testing parameters...
    CheckerBoard check_board(10, 10, 10, 10);
    CheckerBoard check_board1(10, 10, 10, 10, true);

    check_board.fill(10, 10, 10, 11);
    check_board.fill(10,10,10,10);

    check_board1.fill(10, 10, 10, 10);
    check_board1.fill(10, 10, 10, 11);
*/
}

void MainWindow::on_array_clicked()
{
    img_width = 4;
    img_height = 4;

    createBitMap();
}
