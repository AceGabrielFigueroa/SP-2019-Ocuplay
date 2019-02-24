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

    void createBitMap();

    void UINT_32_LITTLE_ENDIAN(char* _DATA, unsigned int _BEGIN,unsigned int num);
    void UINT_16_LITTLE_ENDIAN(char* _DATA, unsigned int _BEGIN,unsigned int num);

    unsigned int img_width;
    unsigned int img_height;


private slots:
    void on_checkBox_toggled(bool checked);

    void on_pushButton_clicked();

    void on_test_button_clicked();

    void on_array_clicked();

private:
    Ui::MainWindow *ui;
    QString colorPath;
};

#endif // MAINWINDOW_H
