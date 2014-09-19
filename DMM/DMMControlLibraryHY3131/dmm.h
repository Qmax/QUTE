#ifndef DMM_H
#define DMM_H

#include <QWidget>
#include <QMainWindow>
#include <QLabel>
#include <QMessageBox>
#include <QTouchEvent>
#include <QGraphicsItem>
#include <QPushButton>
#include <stdio.h>
#include <QPalette>
#include <QString>
#include <QDebug>
#include <QColor>
#include <QMovie>
#include <QTimer>
#include <QFont>
#include <QPixmap>
#include <QIcon>
#include <unistd.h>
#include <QClipboard>
#include <QDoubleValidator>

#include "BackPlaneInterface.h"
#include "ApplicationCardInterface.h"
#include "AppdeviceRegisterDetails.h"
#include "appcardfunctiontemplate.h"
#include "PTEventInterfaces.h"
#include "PTGPIOEventInterfaces.h"
#include "InterfacePTLibrary.h"
#include "GPIOInterfaces.h"
#include "PTAppBckPsocInterface.h"
#include "daccalibration.h"
#include "interfaceHeader.h"
#include "display.h"

#include "HY3131DMMLibInterface.h"
#include "HY3131Macro.h"
#include "hy3131calibration.h"
#include "HY3131Calib.h"

#include "dmmaccuracy.h"

#include "DMMSPITestJigInterface.h"

#include "DIGrapherInterface.h"

const unsigned int guid = 0x444D4D;

//#define overRange	0xffffff


const QEvent::Type GpioEvent = (QEvent::Type) 1234;//embedded probe
const QEvent::Type KnobEvent = (QEvent::Type) 3456;//magnetic knob
const QEvent::Type PTKeyEvent = (QEvent::Type)5678;//pykey event


namespace Ui {
    class DMM;
}
class QmaxPushButton:public QPushButton{
        Q_OBJECT
public:
        QmaxPushButton(int pIndex,QWidget *p=0):QPushButton(p){
        m_nIndex=pIndex;
        setStyleSheet("QPushButton{background-color:rgba(0,0,0,0); border: 2px solid rgba(0,0,0,0);border-radius: 25px;}");
        setFocusPolicy(Qt::NoFocus);
        setIconSize(QSize(64,64));
        connect(this,SIGNAL(clicked()),this,SLOT(pass()));
        }

public slots:
        void pass(){
                emit CClicked(m_nIndex);
        }
protected:
        int m_nIndex;
        signals:
          void CClicked(int);

};
class DMM : public QMainWindow {
    Q_OBJECT
public:
    DMM(QWidget *parent = 0);
    unsigned int getDMMID() const{
        return guid;
    }
	void closeEvent ( QCloseEvent * event );

    void getState();
    void restoreState();
    void ToolBox(bool);
    bool toolboxFlag;

    QMessageBox *msgBox;
    QAbstractButton *connectButton,*abortButton;

    bool msgBoxLive;
    bool showMessageBox(bool,bool,QString,QString,QString);
    QString ohms,micro;
    void EnableRichGUI();
    QMovie *movie;
    void callMeasure();
    void AutoRange();
    void Null();
    void nullify_save();
    void nullify_load();
    void showSymbol(unsigned char);
    void setColor(unsigned char);
    void setHighlight(int);
    void Beep(bool state);
    void case_v();
    void case_i();
    void case_ac();
    void case_dc();
    double digitsLimiter(double);
    void InitialiseValues();//Value Mapping
    void InitialiseKnob();

    double initialKnobValue,changedKnobValue;
	int currentKnobValue,previousKnobValue,switchedValue;
	QString units;

    double calibedSlope,calibedConstant;
    void CalibrateDisplay(QString);

    bool m_bToolboxFlag;

    ~DMM();
    DISPLAY *dis;

	double avgRetval[500],retval;
	int noOfSamples,avg;

    int m_nGPIOCode;

    void customEvent(QEvent *eve);


protected:
    IPTAppBckPsocInterface *test;
    IntefaceBackPlane *IBackPlane;			//BackPlaneInterfacePlugin
    IApplicationCardInterface *IAppCard;	//ApplicationInterfacePlugin
    PTEventInterface	*IPTKeyEvent;
    PTGPIOEventInterface *IGPIOEvent;
    IQmaxPTLibrary *IPTLibrary;
    IQmaxMessageBox *QMsgBox;
    InterfaceGPIOPins *IGPIOPin;
    DACCalibration *screenCalib;

    HY3131Calibration *hy3131Calib;
    IHY3131DMMLibInterface *hy3131DMM;
    IHY3131CalibInterface *calib;

    DMMAccuracy *objDMMAcc;

    DMMSPITestJigInterface *DMMTestjig;

    DIGrapherInterface *DMMGraph;
    QWidget *graphWidget;

    void doKnobFunction();
    void changeByKnob(double Angle,int totalSteps);
    void doPTKeyFunction();
    int m_nKeyCode,m_nPTKeyCode;

    unsigned int initialCurrentDrive;
    //Value Mapping------------------------------------------
    QMap <short,QString> mapDCVoltage;QMap <short,QString> mapACVoltage;
    QMap <short,QString> mapCurrent;
    QMap <short,QString> mapResistance;
    short nVoltagePrev,nVoltageCur,nVoltageNext;
    short n2WResistancePrev,n2WResistanceCur,n2WResistanceNext;
    short n4WResistancePrev,n4WResistanceCur,n4WResistanceNext;
    short nCurrentPrev,nCurrentCur,nCurrentNext;
    QPixmap Pix;
    //-------------------------------------------------------
    void changeEvent(QEvent *e);
    QTimer *m_nADCtimer;
    void IntializeButtons();
    void clickedPRSCR();
    void CreateButtons(QWidget *pWidget, QString strPanel);
    void CreateButton();
    double convertToValues(QString input);


    private:
    Ui::DMM *ui;

public slots:

private slots:
        void on_pushButton_2_clicked();
        void on_ohmMeter_3_clicked();
        void on_ohmMeter_2_clicked();
        void on_Diode_clicked();
        void on_Continuity_clicked();
        void on_pushButton_15_clicked();
        void on_haadcClose_clicked();
        void on_pushButton_13_clicked();
        void on_pushButton_16_clicked();
        void on_pushButton_14_clicked();
        void on_pushButton_clicked();
        void on_Null_clicked();
        void on_ohmMeter_clicked();
        void on_ampMeter_clicked();
        void on_voltMeter_clicked();
        void on_exit_clicked();
        void on_leftArrow_clicked();
        void on_rightArrow_clicked();
        void on_r2w_clicked();
        void on_manual_clicked();
        void on_idc_clicked();
        void on_iac_clicked();
        void on_vac_clicked();
        void on_vdc_clicked();
        void on_hold_clicked();
        void on_Auto_clicked();
        void on_calibrateDisplay_clicked();
//        void on_printImage_clicked();
        void buttonPressed(int);
        void onMeasure(void);
        void GCalib2DMM(double,QString);

signals:
        void DMM2GCalib(double,QString);
        void DMM2AccuCalc(double,QString);
};

#endif // DMM_H
