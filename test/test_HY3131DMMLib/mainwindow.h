#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "HY3131DMMLibInterface.h"
#include "display.h"
namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void changeEvent(QEvent *e);

    QTimer *ADCTimer;
    IHY3131DMMLibInterface *hy3131dmm;
    DISPLAY *dis;

private:
    Ui::MainWindow *ui;

private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
    void on_comboBox_currentIndexChanged(int index);

    void ADCRead();
};

#endif // MAINWINDOW_H
