#ifndef FG_H
#define FG_H

#include <QMainWindow>
#include <qpluginloader.h>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <qdebug.h>
#include <qmessagebox.h>
#include <qclipboard.h>

#include "InterfacePTLibrary.h"
#include "Waveformclass.h"
#include "fgmodel.h"
#include "plotter.h"
#include "FGMacros.h"

#include "hardwareinterface.h"
#include "BackPlaneInterface.h"
#include "IPSOCCommunication.h"
#include "PTEventInterfaces.h"
#include "GPIOInterfaces.h"
#include "PTGPIOEventInterfaces.h"
#include "PTAppBckPsocInterface.h"
#include "RefCALIBTestJigInterface.h"
#include "serialdevice.h"

#include "AWGUIInterface.h"
#include "AWGUIInterface2.h"

const unsigned int guid = 0x46474D;

const QEvent::Type GpioEvent = (QEvent::Type) 1234;//embedded probe
const QEvent::Type KnobEvent = (QEvent::Type) 3456;//magnetic knob
const QEvent::Type PTKeyEvent =(QEvent::Type) 5678;//pykey event

namespace Ui {
    class FG;
}
class QmaxLineEdit:public QLineEdit{
    Q_OBJECT
public:
    QmaxLineEdit(int pIndex,QWidget *p=0):QLineEdit(p){
        m_nIndex=pIndex;
        setStyleSheet("color: rgb(255, 255, 255);""background-color: black;border:1px solid rgba(100,100,100,255);border-radius:5px;");
        setFrame(false);
        setFont(QFont("DejaVu Sans",14,50,false));
    }

protected:
    virtual void focusInEvent(QFocusEvent *e){
        QLineEdit::focusInEvent(e);
        emit(focussed(true));
//       	emit(focussed(m_nIndex));
    }

    virtual void focusOutEvent(QFocusEvent *e){
        QLineEdit::focusOutEvent(e);
        emit(focussed(false));
    }
    void mousePressEvent(QMouseEvent *event){
    	QLineEdit::mousePressEvent(event);
        emit(focussed(m_nIndex));
    }


    int m_nIndex;

signals:
    void focussed(bool hasFocus);
    void focussed(int no);
};
class QmaxLabel:public QLabel{
    Q_OBJECT
public:
    QmaxLabel(int pIndex,QWidget *p=0):QLabel(p){
        m_nIndex=pIndex;
        setAlignment(Qt::AlignCenter);
        setStyleSheet("color: rgba(255,255,255,255);""border: rgba(0,0,0,0);""border-radius: 3px;""background-color: rgba(0, 0, 0,0);""qproperty-wordWrap: true;");
        setFont(QFont("DejaVu Sans",14,75,false));
        setFrameStyle(3);
    }

public slots:
    void setlabelFocus(bool state){
        if(state)
            setStyleSheet("color: rgba(0,0,0,255);""border: 1px solid black;""border-radius: 3px;""background-color: rgba(170, 255, 127,255);""qproperty-wordWrap: true;");
        else
            setStyleSheet("color: rgba(255,255,255,255);""border: rgba(0,0,0,0);""border-radius: 3px;""background-color: rgba(0, 0, 0,0);""qproperty-wordWrap: true;");
    }

protected:
    int m_nIndex;

};

class FG : public QMainWindow {
    Q_OBJECT
public:
    FG(QWidget *parent = 0);
    unsigned int getFGID() const{
        return guid;
    }
    ~FG();

protected:
    //Functions
    void changeEvent(QEvent *e);
    void PluginsInitialisation();
    void InitialiseWaveData();
    void InitialiseUIData();
    void InitialiseLineEdit();
    void HighlightButtons(int but);
    void ConnectSignalsnSlots();
    void GenerateWave();

    void Frequency2Period(QString);
    void Period2Frequency(QString);
    void VppOffset2HighLow(QString,QString);
    void HighLow2VppOffset(QString,QString);
    void SetFrequency(double);

    double convertToValues(QString input);
    QString convertToUnits(double l_nvalue);

    void openNumKBPanel(short int,double,char,double,double);
    bool showMessageBox(bool,bool,QString,QString,QString);
    void customEvent(QEvent *eve);
    void doPTKeyFunction();
    double maxMinCheck(double max, double min, double value);

    void clickedPRSCR();

    //Encoder Members~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    void readEncoderData();
    unsigned short int spiData,m_nEncoder,m_nSwitch;
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    //Widgets
    QmaxLineEdit *lineEdit[8],*burstCountEdit,*burstRateEdit;
    QmaxLabel *label[8],*burstCountLabel,*burstRateLabel;

    //Object Variables
    IQmaxNumberPanel *INumberPanel;
    WaveFormFactory *m_objWaveFactory;
    IWaveProduct *FGProduct;
    stWaveData* m_objWaveData;

    HardwareInterface *hwInterface;
   	IntefaceBackPlane *IBackPlane;
   	IPSOCCOMMUNICATION *IPsoc;
   	PTEventInterface	*IPTKeyEvent;
   	PTGPIOEventInterface *IGPIOEvent;
   	InterfaceGPIOPins *IGPIOPin;
   	IPTAppBckPsocInterface *test;
    IRefCALIBTestJigInterface *REFCalib;
    AWGUIInterface *AWGGUI;
    AWGUIInterface2 *AWGGUI2;
    QWidget *AWGWidget;

    //Variables
    QString m_strWaveType;
    QStringList lineEditLabels,lineEditInitials;

    QList<double> minList;
    QList<double> maxList;
    QList<char>   callType;
    QMessageBox *msgBox;
    QAbstractButton *connectButton,*abortButton;
    QPixmap Pix;
    struct data{
    	double Amplitude,offset,period,frequency,Hlevel,Llevel;
    }Data;

    int m_nLineEditIndex,m_nPTKeyCode;
    double m_nAmplitude,m_nBurstCount,m_nBurstRate;
    double m_nOffset;

	double n_vpp,n_offset,n_high,n_low;
	QString str_vpp,str_offset,str_high,str_low;

    double h_level,l_level,m_level,hl_offset;
    QString h_lvl,l_lvl;

	double n_period,n_frequency;
	QString str_period,str_frequency;



    bool msgBoxLive;

    bool ok,fineCoarse;
    bool m_bSingle,m_bContinuous,m_bBurst,m_bGate;
    bool m_bManual,m_bInternal,m_bExternal;
    bool m_bHiZ,m_bRunMode;

    bool m_bNumberPanel;

private:
    Ui::FG *ui;
public slots:
    void receiveValue(double pValue);
    void receiveValue(QString pValue);
    void receiveValue(uint pValue);
    void callLineEditInput(int leFocussed);
    void Beep();
    void Mute();
private slots:
    void on_AWGBox_clicked();
    void on_modeBox_currentIndexChanged(int index);
    void on_calibrate_clicked();
    void on_appBckPSoC_clicked();
    void on_fineCoarse_clicked();
    void on_leftBut_clicked();
    void on_rightBut_clicked();
    void on_exit_clicked();
    void on_upBut_clicked();
    void on_downBut_clicked();
    void on_GateBut_clicked();
    void on_EXTBut_clicked();
    void on_INTBut_clicked();
    void on_MANBut_clicked();
    void on_RUNBut_clicked();
    void on_hiZBut_clicked();
    void on_triangleBut_clicked();
    void on_rampBut_clicked();
    void on_squareBut_clicked();
    void on_sineBut_clicked();
    void on_singleBut_clicked();
    void on_burstBut_clicked();
    void on_continuousBut_clicked();
};

#endif // FG_H
