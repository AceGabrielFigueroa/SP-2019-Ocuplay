#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>

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
