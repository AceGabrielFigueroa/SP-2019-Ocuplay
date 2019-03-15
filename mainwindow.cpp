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
    // TODO: error check to see if line_box is an actually interger
    //
    CheckerBoard checker1 = CheckerBoard(ui->image_w->text().toInt(), ui->image_h->text().toInt(),
                                         ui->lr1c1->text().toInt(), ui->lr1c2->text().toInt(), true);

    CheckerBoard checker2 = CheckerBoard(ui->image_w->text().toInt(), ui->image_h->text().toInt(),
                                         ui->lr2c1->text().toInt(), ui->lr2c2->text().toInt());

    checker1.Show();
}
