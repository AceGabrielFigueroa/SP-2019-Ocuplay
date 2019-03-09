#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "CheckerBoard.h"

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
    qDebug() << "I am in the Checkerboard button";

    CheckerBoard checker(10, 10, 5, 5, true);
    checker.Show();
}
