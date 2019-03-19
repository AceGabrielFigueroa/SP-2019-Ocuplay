#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btn_create_img_clicked();

    void on_le_r1_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    bool checkNum(int a, int b);
    void createImage(int array[], int height, int width);
    void displayImage(QImage img);
};

#endif // MAINWINDOW_H
