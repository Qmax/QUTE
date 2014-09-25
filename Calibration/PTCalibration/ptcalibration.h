/***********************************************************
***************Created by Ravivarman.R,Qmax*****************
***********************************************************/
#ifndef PTCALIBRATION_H
#define PTCALIBRATION_H

#include <QDialog>

namespace Ui {
    class PTCalibration;
}

class PTCalibration : public QDialog {
    Q_OBJECT
public:
    PTCalibration(QWidget *parent = 0);
    ~PTCalibration();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::PTCalibration *ui;

private slots:
    void on_exitBut_2_clicked();
    void on_comboBox_5_currentIndexChanged(int index);
    void on_pushButton_clicked();
};

#endif // PTCALIBRATION_H
