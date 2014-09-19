/*
 * hy3131calibration.h
 *
 *  Created on: 06-Mar-2014
 *      Author: Ravivarman.R
 */
#ifndef HY3131CALIBRATION_H
#define HY3131CALIBRATION_H

#include <QFile>
#include <QTimer>
#include <QDialog>
#include <QLineEdit>
#include <QTextStream>
#include <QPluginLoader>

#include "ApplicationCardInterface.h"
#include "InterfacePTLibrary.h"
#include "HY3131DMMLibInterface.h"
#include "HY3131Macro.h"

namespace Ui {
    class HY3131Calibration;
}

class HY3131Calibration : public QDialog {
    Q_OBJECT
public:
    HY3131Calibration(QWidget *parent = 0);
    ~HY3131Calibration();

protected:
    IHY3131DMMLibInterface *hy3131dmm;
    IApplicationCardInterface *IAppCard;
    IQmaxLineEdit *ILineEdit;
    IQmaxNumberPanel *INumberPanel;

    QLineEdit *objOffsetValue,*objMaxValue;

    short int m_nLineEditIndex;

    void openNumKBPanel(short int);
    void openNumKBPanel(short int,double,char,double,double,QWidget*);

    void changeEvent(QEvent *e);

    void stopADC();
    void enableDisable(char,bool);

    QString m_strRange[31];
    double m_nGain[31],m_nOffset[31];

    double m_dCalculatedGain,m_dCalculatedOffset;
    double m_dOffsetInput,m_dOffsetMeasured,m_dMaxInput,m_dMaxMeasured,m_dCalibrated;
    int8_t m_nMacroValue;

    QTimer *ADCTimer;

private:
    Ui::HY3131Calibration *ui;

private slots:
    void on_pbStopMax_clicked();
    void on_pbStopMin_clicked();
    void on_saveBut_clicked();
    void on_pbMeasureCalibrated_clicked();
    void on_calibrateBut_clicked();
    void on_pbMeasureMax_clicked();
    void on_pbMeasureMin_clicked();
    void on_cmbRange_currentIndexChanged(int index);
    void on_cmbComponent_currentIndexChanged(int index);
    void on_exitBut_clicked();

    void ADCRead();

    void receiveValue(unsigned int);
    void receiveValue(double);
    void receiveValue(QString);

    void callOffsetEdit();
    void callMaxEdit();
};

#endif // HY3131CALIBRATION_H
