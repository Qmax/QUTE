/***********************************************************
***************Created by Ravivarman.R,Qmax*****************
***********************************************************/
#ifndef DACCALIBRATION_H
#define DACCALIBRATION_H

#include <QtGui/QWidget>
#include "ui_daccalibration.h"
#include <QDebug>
#include <QDesktopWidget>
#include <QLineEdit>
#include <QPluginLoader>
#include "PTLibraryInterfaces.h"
#include "ApplicationCardInterface.h"
#include "AppdeviceRegisterDetails.h"
#include "ad5318components.h"
#include "ad5293.h"
#include <QFile>
#include <QTimer>
#include <QXmlStreamWriter>
class DACCalibration : public QWidget
{
    Q_OBJECT

public:

    DACCalibration(QWidget *parent = 0);
    ~DACCalibration();
    void makeScreenCenter();
    void InitializeCalibration();
    void InitializeLineEditControls();
    void loadQmaxPlugins();
    void readParallelDACCalibrationFile();
    void readRefCalibrationFile();
    QTimer *timer;


protected:
    IQmaxLineEdit *ILineEdit;
    IQmaxNumberPanel *INumberPanel;
    IApplicationCardInterface *IAppCard;


    AD5318_DACSELECT m_eSelect;
    AD5318Components *m_objAD5318Component;
    AD5318_dataTemplate l_nAD5318DW;
    AD5293 *m_objAD5293Component;

    QLineEdit *m_objLE_NoOfPoints;
    QLineEdit *m_objLE_DriveVoltage;
    QLineEdit *m_objLE_RxedVoltage;
    QLineEdit *m_objLE_TestVoltage;

    unsigned int m_nLineEditIndex;

    int m_nNoOfPoints,m_nNoOfSamples;
    unsigned int m_nHexCode;
    double m_nRangeSlope[5],m_nRangeConstant[5],m_nXVoltage[5],m_nYVoltage[5];
    double m_nRefRangeSlope[5],m_nRefRangeConstant[5],m_nRefYValue;
    double XVoltage[5][5],YVoltage[5][5];
    double m_nGain,m_nDACOutput,m_nDesiredDACOutput;
    double m_nDriveVoltage,m_nRxedVoltage,m_nDriveRange,m_nSlope,m_nConstant,m_nTestVoltage;

    void openNumKBPanel(short int pValue) ;
    void openNumKBPanelminmax(short int pValue,char type,double pMax,double pMin);



private:
    Ui::DACCalibrationClass ui;
private slots:
    void on_CalibratedRef_clicked(bool checked);
    void on_Calibrated_clicked(bool checked);
    void on_driveBut_2_clicked();
    void on_comboBox_currentIndexChanged(int index);
    void on_nextBut_clicked();
    void on_driveBut_clicked();
    void on_saveBut_clicked();
    void on_exitBut_clicked();
    void callNoOfPointsEdit();
    void callDriveVoltageEdit();
    void callRxedVoltageEdit();
    void callTestVoltageEdit();


    void receiveValue(unsigned int pValue);
    void receiveValue(double);
    void receiveValue(QString);
    void LoopDrive();
};

#endif // DACCALIBRATION_H
