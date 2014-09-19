#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPluginLoader>

#include "BackPlaneInterface.h"

#define         BP_BVCPR                    0x0004
#define         BP_BVCDCR                   0x0006
#define         BP_BVCER                    0x0008
#define         BP_BVCER_ENABLE_PERIOD      0x0001
#define         BP_BVCER_ENABLE_PWM         0x0002
#define         BP_BTCPR                    0x000A
#define         BP_BTCDCR                   0x000C
#define         BP_BTCER                    0x000E
#define         BP_BTCER_ENABLE_PERIOD      0x0001
#define         BP_BTCER_ENABLE_PWM         0x0002

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    void Beep(bool state);
    void BuzzerTone(unsigned int pFrequency,unsigned short pPWMFlag, unsigned int pPercentage);
    void BuzzerVolume(unsigned int pFrequency,unsigned short pPWMFlag, unsigned int pPercentage);
    ~MainWindow();

protected:
    bool buzzerFlag;
    int t1,t2,t3,v1,v2,v3,volume;
    IntefaceBackPlane *IBackPlane;
    void changeEvent(QEvent *e);

private:
    Ui::MainWindow *ui;

private slots:
    void on_doubleSpinBox_valueChanged(double );
    void on_pushButton_clicked();
    void on_spinBox_5_valueChanged(int );
    void on_spinBox_3_valueChanged(int );
    void on_spinBox_6_valueChanged(int );
    void on_spinBox_7_valueChanged(int );
    void on_spinBox_4_valueChanged(int );
    void on_spinBox_2_valueChanged(int );
};

#endif // MAINWINDOW_H
