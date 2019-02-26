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
        UINT_32_LITTLE_ENDIAN(_DATA, 2, 0x46);

        // Data reserved
        UINT_32_LITTLE_ENDIAN(_DATA, 6, 0);

        // Offset
        UINT_32_LITTLE_ENDIAN(_DATA, 10, 0x36);

        // Size of header
        UINT_32_LITTLE_ENDIAN(_DATA, 14, 0x28);

        // Bitmap width in pixels
        UINT_32_LITTLE_ENDIAN(_DATA, 18, 0x02);

        // Bitmap height in pixels
        UINT_32_LITTLE_ENDIAN(_DATA, 22, 0x02);

        // Color plane
        UINT_16_LITTLE_ENDIAN(_DATA, 26, 0x05);

        // Number of bits per pixel
        UINT_16_LITTLE_ENDIAN(_DATA, 28, 0x18);

        // Compression method
        UINT_32_LITTLE_ENDIAN(_DATA, 30, 0x00);

        // Image size
        UINT_32_LITTLE_ENDIAN(_DATA, 34, 0x10);

        // Horizontal Resolution
        UINT_32_LITTLE_ENDIAN(_DATA, 38, 2835);

        // Vertical Resolution
        UINT_32_LITTLE_ENDIAN(_DATA, 42, 2835);

        // Number of colors in palettes
        UINT_32_LITTLE_ENDIAN(_DATA, 46, 0x00);

        // Number of important colors
        UINT_32_LITTLE_ENDIAN(_DATA, 50, 0x00);

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
