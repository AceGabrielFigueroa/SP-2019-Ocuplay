#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>

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

    void on_le_r1_textChanged(const QString &arg1);
    void on_le_r2_textChanged(const QString &arg1);
    void on_le_r3_textChanged(const QString &arg1);
    void on_le_r4_textChanged(const QString &arg1);
    void on_le_r5_textChanged(const QString &arg1);
    void on_le_r6_textChanged(const QString &arg1);
    void on_le_r7_textChanged(const QString &arg1);
    void on_le_r8_textChanged(const QString &arg1);

    void on_le_c1_textChanged(const QString &arg1);
    void on_le_c2_textChanged(const QString &arg1);
    void on_le_c3_textChanged(const QString &arg1);
    void on_le_c4_textChanged(const QString &arg1);
    void on_le_c5_textChanged(const QString &arg1);
    void on_le_c6_textChanged(const QString &arg1);
    void on_le_c7_textChanged(const QString &arg1);
    void on_le_c8_textChanged(const QString &arg1);

    void on_btn_random_clicked();

    void on_btn_reset_clicked();

    void on_btn_save_img_clicked();

    void on_btn_create_img_clicked();

private:
    Ui::MainWindow *ui;


    QImage myImage;
    bool checkNum(int a, int b);
    void textChanged_notify(QLineEdit* q1, QLineEdit* q2, const QString &arg1);

    void createImage();
    void saveImage();
    void colorImage(int array[], int height, int width);
    void displayImage(QImage img);
};

#endif // MAINWINDOW_H
