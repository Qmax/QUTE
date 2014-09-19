

#ifndef TESTSPI_H
#define TESTSPI_H

#include "ApplicationCardInterface.h"
#include "BackPlaneInterface.h"
#include "InterfacePTLibrary.h"
#include <QPluginLoader>
#include <QMap>
#include <qdir.h>
#include <QtGui/QWidget>
#include "ui_testspi.h"
#include "display.h"
#include "hy3131calibration.h"
#include "HY3131Macro.h"

#define HY3131 1

#define HY3131_GAIN		120.6188
#define HY3131_OFFSET		-97.24

#define RMS_ZERO_AC500mV		3000
#define RMS_GAIN_AC500mV		37.4594

class testSPI : public QWidget
{
    Q_OBJECT

public:
    testSPI(QWidget *parent = 0);
    ~testSPI();
protected:
    DISPLAY *dis;
    HY3131Calibration *calibPanel;
    SPI_SELECT m_mapSPISelect;
    IApplicationCardInterface *IAppCard;
    IntefaceBackPlane *IBackPlane;			//BackPlaneInterfacePlugin
    u_int16_t m_nSPIAppendBit;

    u_int16_t m_nMSWData,m_nLSWData,m_nMaskData,m_nMode,m_nSPIClock;
    u_int16_t m_nAppAddress,m_nAppData,m_nDMMAddr;

    IQmaxLineEdit *ILineEdit;
    IQmaxNumberPanel *INumberPanel;

    QLineEdit *objAddress,*objData,*objMaskData,*objSPIClock;
    QLineEdit *objAppAddress,*objAppData,*objDMMAddr,*objLeAvg;

    short int m_nLineEditIndex,m_nLeAvg,m_nLeAvgInc;
    unsigned int m_nAvgSum;

    void openNumKBPanel(short int);
    void openNumKBPanel(short int,double,char,double,double,QWidget*);

    unsigned int readDMMSPI(unsigned short _Address);
    void writeDMMSPI(unsigned short _Address,unsigned  short _MSWData,unsigned short _LSWData);

    u_int32_t readADC1(u_int8_t r0,u_int8_t r1,u_int8_t r2);
    u_int32_t readADC2();
    u_int32_t readLPF();
    u_int32_t readRMS();
    u_int32_t readPKHMIN();
    u_int32_t readPKHMAX();
    void writeDMMSPI2(u_int16_t _Address, u_int16_t _Data);
    u_int32_t readDMMSPI2(u_int16_t _Address);
    int m_nSampleCount;
    bool busyState;
    bool selAppCard;


    QTimer *ADCTimer;
    u_int8_t reg0,reg1,reg2,reg3,reg4;
    u_int32_t ADCDigital;
    u_int32_t RMSData;
    double ADCAnalog;
    long double RMSAnalog;

    QString FileName;
    QStringList RegvalFiles;
    QDir path;
private:
    Ui::testSPIClass ui;

private slots:


private slots:
    void on_radioButton_clicked(bool checked);
    void on_radioButton_2_clicked(bool checked);
    void on_pushButton_clicked();
    void on_SelectADC_currentIndexChanged(int index);
    void on_testFileLoad_currentIndexChanged(int index);
    void on_testFile_clicked();
    void on_horizontalSlider_valueChanged(int value);
    void on_DCVolt_currentIndexChanged(int index);
    void on_ReadAll_clicked();
    void on_Reset_clicked();
    void on_SelectApp_currentIndexChanged(int index);
    void on_AppWrite_clicked();
    void on_AppRead_clicked();
    void on_SelectPart_currentIndexChanged(int index);
    void on_SelectMode_currentIndexChanged(int index);
    void on_Exit_clicked();
    void on_SelectSPI_currentIndexChanged(int index);
    void on_SelectOperation_currentIndexChanged(int index);
    void on_Execute_clicked();

    void receiveValue(unsigned int);
    void receiveValue(double);
    void receiveValue(QString);

    void callAddressEdit();
    void callDataEdit();
    void callAppAddressEdit();
    void callAppDataEdit();
    void callMaskDataEdit();
    void callSPIClockEdit();
    void callDMMAddrEdit();
    void callAvgEdit();

     void ADCRead();
};

#endif // TESTSPI_H
