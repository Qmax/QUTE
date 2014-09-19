/*
 * icm.h
 *
 *      Author: Ravivarman.R
 */
#ifndef ICM_H
#define ICM_H

#include <QMainWindow>
#include <qpluginloader.h>
#include <qdebug.h>
#include <QPropertyAnimation>
#include "interfaceHeader.h"
#include "settings.h"
#include "ad7190component.h"
#include "ad5318components.h"
#include "ApplicationCardInterface.h"
#include "PTSPIMemoryInterface.h"
#include "IPSOCCommunication.h"
#include "hardwareinterface.h"
#include "GCALIBTestJigInterface.h"
#include "PTAppBckPsocInterface.h"
#include "BackPlaneInterface.h"
#include <qelapsedtimer.h>
#include <QMessageBox>
#include "InterfacePTLibrary.h"
#include "daccalibration.h"
#include "display.h"
#include "serialdevice.h"
#include "GPIOInterfaces.h"
#include "PTGPIOEventInterfaces.h"
#include "PTEventInterfaces.h"
#include "qcustomplot.h"

#define		GPIOINT		0x0100
#define		KNOBINT		0x0800
#define		GPIOKNOBINT	0x0900
#define		NOINT		0x0000

const QEvent::Type GpioEvent = (QEvent::Type) 1234;//embedded probe
const QEvent::Type KnobEvent = (QEvent::Type) 3456;//magnetic knob
const QEvent::Type PTKeyEvent = (QEvent::Type)5678;//pykey event

const unsigned int guid = 0x49434D;

namespace Ui {
    class ICM;
}
struct PANEL{
    bool dPanel,fPanel,sPanel,gPanel;
};

class ICM : public QMainWindow {
    Q_OBJECT
public:
    ICM(QWidget *parent = 0);
    ~ICM();
    void ToolBox(bool);
    Settings *obj;
    DACCalibration *objGCalib;

    void Intialize();
    QString micro,ohms,kiloOhms,picoFarad,nanoFarad,microFarad,milliFarad,microHenry,milliHenry,Henry;

    unsigned int getICMID() const{
        return guid;
    }

    double avgRValueSh[6],avgLValueSh[7],avgCValueSh[9];
    double avgRValueOpen[6],avgLValueOpen[7],avgCValueOpen[9];
    double Zdut;
    QLineEdit *leActual,*leMeasured;

    void openNumKBPanel(short int);
    void openNumKBPanel(short int,double,char,double,double,QWidget*);
    short int m_nLineEditIndex;
    double Actual,Measured;
    IQmaxLineEdit *ILineEdit;
    IQmaxNumberPanel *INumberPanel;
    IQmaxMessageBox *IPTMessageBox;
    DISPLAY *dis;
    PANEL panelStatus;
    double m_nActualGain;

    //graphing
    void setupSimpleDemo(QCustomPlot *customPlot);
    void plotSimpleDemo(QCustomPlot *customPlot);
    void graphSetup(QCustomPlot *customPlot);
    void graphPlotter(QCustomPlot *customPlot);
    int loopOut;
    QString m_strRLC;
    QVector<double> x, y;
    int m_nSweepStartFrequency,m_nSweepEndFrequency,m_nSweepInterval;
    int m_nSweepStartFrequency2,m_nSweepEndFrequency2,m_nSweepInterval2;
    int m_nSweepStartFrequencyUnit,m_nSweepEndFrequencyUnit,m_nSweepIntervalUnit;
    int xSize,ySize,yRangeMax;


protected:

    PTGPIOEventInterface *IGPIOEvent;
    PTEventInterface *IPTKeyEvent;
    InterfaceGPIOPins *IGPIOPin;

    IntefaceBackPlane *IBackPlane;
    IPTAppBckPsocInterface *test;
    IGCALIBTestJigInterface *GCALIB;
    HardwareInterface *hwInterface;
    IPSOCCOMMUNICATION *IPsoc;
    IApplicationCardInterface *IAppCard;
    AD7190Component *m_objAD7190Component;
    AD5318Components *m_objAD5318Component;
    ISPIMemoryInterface *ISPIMemory;
    AD5318_DACSELECT m_eSelect;
    QTimer *ADCtimer;

    int m_nGPIOCode,m_nPTKeyCode;

    double l_nAIN1,l_nAIN2;
    unsigned int m_nADC1Voltage,m_nADC2Voltage;
    int C_Index,R_Index,L_Index;
    double m_nResistance_2,m_nCapacitance_2,m_nInductance_2;
    double m_nResistance,m_nCapacitance,m_nInductance;
    double m_nImpedanceValue;
    double m_nFrequency;
    double m_nRange;bool loop;
    double cbdR,cbdL,cbdC;

    unsigned short m_nICMMGR;

    QMessageBox *msgBox;
    QAbstractButton *connectButton,*abortButton;
    bool msgBoxLive;
    bool showMessageBox(bool,bool,QString,QString,QString);

    void customEvent(QEvent *eve);
    void KeyFunction();
    void KnobFunction();
    void changeByKnob(double Angle,double totalSteps);
    void ProbeFunction();
    void changeByProbe(unsigned int);

    void initialiseHWLibraries();
    void initialiseFeedBackResistance();
    void AutoRange();

    double readADCR(QString);
    void AutoRangeR();
    void DisplayR();

    QString convertToUnits(double l_nvalue);
    double convertToValues(QString input);


//    void resetDAC(AD5318_DACSELECT DAC);
//    void updateDAC(double);

    QList<double>m_lstRFResistance;
    QList<double>m_lstRFCapcitance;
    QList<double>m_lstRFInductance;

    QMap<short,QString>m_mapResistance;
    QMap<short,QString>m_mapCapacitance;
    QMap<short,QString>m_mapInductance;

    void GetDisplayResistance(double pValue,double);
    void GetDisplayCapcitance(double pValue,short int);
    void GetDisplayInductance(double pValue,short int);

    double calibedSlope,calibedConstant;
    void CalibrateDisplay(QString);

    void changeEvent(QEvent *e);
    void on_printImage_clicked();

    QElapsedTimer timer;
    qint64 milliSec;
    int _100pF,_1nF,_10nF,_100nF,_1uF,_10uF,_100uF,_1mF,_10mF;

    double capSamples[10];
    int capInc;

    double m_dOffset,m_dRNull,m_dLNull,m_dCNull;
    bool m_bNull,m_bExternal;


        int avg,noOFsamples;
        double avgRetval[100];

        bool m_bToolboxFlag;
        bool m_bRacRdc;

        bool rFlag,lFlag,cFlag,autoFlag,runFlag;
        bool scanFlag;

private:
    Ui::ICM *ui;

signals:
        void ICM2GCalib(double,QString);

private  slots:

void on_butZoom_clicked();
void on_sweep_interval_unit_currentIndexChanged(int index);
void on_sweep_interval_valueChanged(int );
void on_sweep_endfreq_unit_currentIndexChanged(int index);
void on_sweep_endfreq_valueChanged(int );
void on_sweep_startfreq_unit_currentIndexChanged(int index);
void on_sweep_startfreq_valueChanged(int );
void on_sweep_capture_clicked();
void on_graphBut_clicked();
void on_ACDC_clicked();
void on_cBut_clicked();
void on_lBut_clicked();
void on_rBut_clicked();
void on_exit_clicked();
void on_RacRdc_clicked();
//void on_hideSettings_clicked();
void on_pushButton_3_clicked();
void GCalib2ICM(double,QString);


void on_chkLoad_clicked();
void receiveValue(unsigned int);
void receiveValue(double);
void receiveValue(QString);
void callActualEdit();
void callMeasuredEdit();

    void on_checkBox_clicked();
    void on_pushButton_2_clicked();
    void on_external_clicked(bool checked);
    void on_NULL_2_clicked();
    void callFrequencyChange(double);
    void callOffsetChange(double);
    void callFeedBackChange(int);

   void on_pushButton_clicked();
   void on_calibrate_clicked();
   void on_ExitBut_clicked();
   void on_AutoManual_clicked();
   void on_L30mH_clicked();
   void on_R100KE_clicked();
   void on_ONOFF_clicked();
   void readADC();
   void readADC2();

    void on_settings_clicked();
    void on_L3mH_clicked();
    void on_L3H_clicked();
    void on_L30uH_clicked();
    void on_L30H_clicked();
    void on_L300uH_clicked();
    void on_L300mH_clicked();
    void on_R1ME_clicked();
    void on_R1KE_clicked();
    void on_R10KE_clicked();
    void on_R10E_clicked();
    void on_R100E_clicked();
    void on_C1uF_clicked();
    void on_C10mF_clicked();
    void on_C1mF_clicked();
    void on_C100uF_clicked();
    void on_C10uF_clicked();
    void on_C100nF_clicked();
    void on_C10nF_clicked();
    void on_C1nF_clicked();
    void on_C100pF_clicked();
    void on_Exit_clicked();
//    void on_AutoManualSlider_valueChanged(int value);
    void on_OnOffSlider_valueChanged(int value);
    void on_C_clicked();
    void on_L_clicked();
    void on_R_clicked();

};

#endif // ICM_H
