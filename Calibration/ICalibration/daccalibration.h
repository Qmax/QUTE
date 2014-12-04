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
#include <QFile>
#include <QTimer>
#include <QXmlStreamWriter>
#include <qmessagebox.h>
#include "PTLibraryInterfaces.h"
#include "AppdeviceRegisterDetails.h"
#include "InterfaceFunctionalComponents.h"
#include "ad5318components.h"

#define RANGE50MA   1
#define RANGE500UA  2
#define RANGE5UA	4

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
    void readCurrentCalibrationFile();

    QTimer *timer;
    QString micro;


protected:
    AD5318_DACSELECT m_eSelect;
    AD5318Components *m_objAD5318Component;
    AD5318_dataTemplate l_nAD5318DW;
    double m_nDACVoltage;

    IQmaxLineEdit *ILineEdit;
    IQmaxNumberPanel *INumberPanel;
    IApplicationCardInterface *IAppCard;

    QLineEdit *m_objLE_NoOfPoints;
    QLineEdit *m_objLE_DriveCurrent;
    QLineEdit *m_objLE_RxedCurrent;
    QLineEdit *m_objLE_TestCurrent;

    QLineEdit *m_objLE_RxedCurrent2,*m_objLE_RxedCurrent3;

    unsigned int m_nLineEditIndex;

    int m_nNoOfPoints,m_nNoOfSamples;
    unsigned int m_nHexCode;
    double m_nRangeSlope[5],m_nRangeConstant[5],m_nXCurrent[5],m_nYCurrent[5];
    double XCurrent[5][5],YCurrent[5][5];
    double m_nGain,m_nDACOutput,m_nDesiredDACOutput;
    double m_nDriveCurrent,m_nRxedCurrent,m_nDriveRange,m_nSlope,m_nConstant,m_nTestCurrent;
    double m_nRxedCurrent2,m_nRxedCurrent3;
	QMap<short, unsigned int> m_mapResistance;

    void openNumKBPanel(short int pValue) ;
    void openNumKBPanelminmax(short int pValue,char type,double pMax,double pMin);

    double DACDriveVoltage[7];
    QMap<short,QString>DACDriveRange;
    QString m_strDriveCurrent;

private:
    Ui::DACCalibrationClass ui;
private slots:
    void on_drive1mA_clicked();
    void on_drive10mA_clicked();
    void on_saveSl_clicked();
    void on_Calibrated_clicked(bool checked);
    void on_driveBut_2_clicked();
    void on_comboBox_currentIndexChanged(int index);
    void on_nextBut_clicked();
    void on_driveBut_clicked();
    void on_saveBut_clicked();
    void on_exitBut_clicked();
    void callNoOfPointsEdit();
    void callDriveCurrentEdit();
    void callRxedCurrentEdit();
    void callRxedCurrentEdit2();
    void callRxedCurrentEdit3();
    void callTestCurrentEdit();


    void receiveValue(unsigned int pValue);
    void receiveValue(double);
    void receiveValue(QString);
    void LoopDrive();
};

#endif // DACCALIBRATION_H
