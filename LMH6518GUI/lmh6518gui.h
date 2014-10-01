#ifndef LMH6518GUI_H
#define LMH6518GUI_H

#include <QMainWindow>
#include <QLineEdit>
#include <QMap>
#include <qobject.h>
#include <qpluginloader.h>
#include <QtGui>

#include <ApplicationCardInterface.h>
#include "lmh6518.h"
#include "DisplayWidgetInterface.h"
#include "BackPlaneInterface.h"
#include "hardwareinterface.h"
#include "IPSOCCommunication.h"
#include "InterfacePTLibrary.h"
#include "DSOWaveSettings.h"
#include "PTAppBckPsocInterface.h"
#include "PTGPIOEventInterfaces.h"
#include "PTEventInterfaces.h"
#include "offsetwindow.h"

#include "qwsevent_qws.h"
#include "checkitem.h"
//#include "AD9102TestJigInterface.h"

//class PointerListener : public QObject {
//    //Q_OBJECT
//    public:
//
//        PointerListener() {}
//        virtual void QCopReceived(int message) = 0;
//        virtual void PropertyReceived( ) = 0;
//        virtual void pointerPressed( int x, int y) = 0;
//        virtual void pointerReleased( int x, int y) = 0;
//        virtual void pointerDrag( int x, int y) = 0;
//        virtual void keyPressed(int keycode) = 0;
//        virtual void keyPresslong(int keycode) = 0;
//};
//class MyApp : public QApplication
//{
//	public:
//	MyApp(int &argc, char **argv ) : QApplication( argc, argv ) {};
//
//	bool qwsEventFilter(QWSEvent * event)
//	{
//		QApplication::qwsEventFilter(event);
//		//qDebug()<<event->type;
//	     QWSMouseEvent* mouse=0;
//	     int x,y,z;
//	    // press = true;
//	    if(event->type == QWSEvent::Mouse) {
//	    	mouse=event->asMouse();
//	    	if (mouse==0)
//	    	  return false;
//		  x=mouse->simpleData.x_root;
//		  y=mouse->simpleData.y_root;
//		  z=mouse->simpleData.state;
//		  //qDebug()<<" Mouse State:"<<z;
//	    	if ( pointerListener != 0 )
//			{
//			   switch( z )
//			   {
//				   case 0:
//					   if(press)
//						   pointerListener->pointerReleased( x, y );
//				   break;
//				   case 1:
//					   pointerListener->pointerReleased( x, y );
//					   pointerListener->pointerDrag( x, y );
//					   if ( not press ){
//					   pointerListener->pointerPressed( x, y );
//					   }
//				   break;
//			   }
//			   press = z;
//			}
//
//
//	    }
//	    else if(event->type == QWSEvent::WindowOperation)
//	    {
//	    	qDebug()<<"Window Operation";
//	    }
//	   // QCoreApplication::processEvents(QEventLoop::AllEvents, 10);
//
//	//	MyApp::qwsEventFilter(event);
//
//	    return false;
//	}
//	protected:
//	 PointerListener *pointerListener;
//	 bool press;
//};

const QEvent::Type PTKeyEvent = (QEvent::Type)5678;//pykey event
const QEvent::Type MouseEvent=  (QEvent::Type) 7894;//mouse

namespace Ui {
    class LMH6518GUI;
}

class LMH6518GUI : public QMainWindow {
    Q_OBJECT
public:
    LMH6518GUI(QWidget *parent = 0);
    ~LMH6518GUI();

    void InitializeHardwareLibs();
    void InitLineEditSIGSnSLOTS();
    void InitializeFGVariables();

protected:
   // PointerListener *pointerListener;
    bool press;
    /*
     * Dial Sequences
     *
     */

    QList<double> m_lstTimebaseValues;
    QList<QString>m_lstTimebaseUnit;
    QList<double> m_lstMemoryValues;
    QList<QString> m_lstMemoryUnit;
    void initializeTimeBaseList();
    void initializeMemoryList();
    void clickedPRSCR();

    IApplicationCardInterface *IAppCard;
    PTEventInterface *IPTKeyEvent;
    HardwareInterface *hwInterface;
    IntefaceBackPlane *IBackPlane;
    IPSOCCOMMUNICATION *IPsoc;
    IPTAppBckPsocInterface *test;
    PTGPIOEventInterface *IGPIOEvent;
    OffsetWindow *m_objOffsetWindow;
//    IAD9102TestJigInterface *AD9102;

    int m_nPTKeyCode;
    bool m_bRunStop;
    short int m_nChannelSelect,m_nTriggerSelect;

    double m_nAmplitude,m_nFrequency;
    short int m_nLineEditIndex;

    IQmaxLineEdit *ILineEdit;
    IQmaxNumberPanel *INumberPanel;

    double m_nSampleRate[10];
    unsigned short m_nSampleIndex,m_nSampleUnit;

    //Checking Purpose
    QGraphicsView *view;
    QGraphicsScene *scene;
    checkItem *item;
    channelItem *chItem;
    //------------


    DSOWaveSettings *m_objDSOWaveSettings;

    QLineEdit *LEfrequency,*LEamplitude,*LEoffset,*LEphase,*LEDACValue;
    QLineEdit *m_obBD,*m_obBTUR,*m_obPreTriggerCount;
    int m_nKeyCode;
    RECEIVER_CONF m_eReceConf;
    DSO_TRIGGER m_eTrigger;
    QTimer *m_objTimerInterrupt;

    void openNumKBPanel(short int,double,char,double,double);

    LMH6518 *m_objLMH6518Component;
    LMH6518_DataTemplate m_eDataTemplate,m_eDataTemplate2,m_eDataTemplateCH2;
    VOLTAGEPERDIVISION m_eVoltage,m_eCH2Voltage;
    LMH6518Data Data,DataCH2;
    bool m_nIntFlag;
    QMap<int,QString>m_mapAttenuation;
    DisplayWidgetInterface *IDSODisplay;
    void changeEvent(QEvent *e);
    void initializeWaveForm();

    void initializeWaveSettingsLineEdit();
    void openNumKBPanel(short int);
    void updateValues();
    unsigned int validateSampleRate();
    void InitializeTriggers();
    void customEvent(QEvent *e);
    void updatePrecount(unsigned short pValue);
    void KeyFunction();
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
    bool evenFilter(QObject *target,QEvent *e);

    static unsigned int m_nMouseMoveCouter;
 //   bool qwsEvent(QWSEvent *event);
    bool qwsEventFilter(QWSEvent *event);
signals:
	void alertPlot();
private:
    unsigned int m_nFTW,m_nFTW_LSB,m_nFTW_MSB;
    double m_nSystemFrequency,m_nOutputFrequency;

    unsigned int m_nLeftMove,m_nRightMove;
    unsigned int m_nUpCounter,m_nDownCounter,m_nComboCounter;
    double m_nTimePerSample;
    double m_nTimebaseTriggerPoint,m_nVoltageTriggerPoint,m_nVoltPerDivision ;
    double m_nAcutalTriggertimeBase;
    QString m_strTimeUnit;
    short int m_nTimeUnitIndex;
    unsigned int m_nMaxRecordLength,m_nSamples;

    short int m_nPrecount,m_nPostCount,m_nCmbampleIndex;
   // double m_nSampleRate;
    Ui::LMH6518GUI *ui;
    short int m_nChannel,m_nTriggerSource;
//    DSOXYGridView *m_objDSOGridView;
//    DSOChannelDataView *m_objChannelDataView;
    QList<unsigned char> m_LstOdd,m_LstEven;
private slots:
    void on_ChannelSel_currentIndexChanged(int index);
    void on_Calculate_clicked();
    void on_pushButton_clicked();
    void on_stopDrive_clicked();
    void on_startDrive_clicked();
    void on_burstWave_clicked();
    void on_butTest_clicked();
    void on_butSerialPanel_clicked();

    void on_continuousWave_clicked();
    void on_singleWave_clicked();
    void on_triangle_clicked();
    void on_ramp_clicked();
    void on_square_clicked();
    void on_sine_clicked();
    void on_Read_clicked();
    void on_Voltage_currentIndexChanged(int index);
    void on_chkInt_Ext_clicked();
    void on_cmbLMHVoltage_currentIndexChanged(int index);
    void on_cmbSamplingType_currentIndexChanged(int index);
    void on_Write_clicked();
    void on_Filter_currentIndexChanged(int index);
    void on_PreAmpGain_currentIndexChanged(int index);
    void on_PowerMode_currentIndexChanged(int index);
    void on_Attenuater_valueChanged(int value);
    void on_Exit_clicked();
    void on_optAuto_clicked();
    void on_butRUN_clicked();
    void on_butOffset_clicked();
    void on_butForceTrigger_clicked();
    void on_butSTOP_clicked();
    void on_dblHorizontalTrigger_clicked();
    void on_dblHorizontalTrigger_valueChanged(double value);
    void on_dblVerticalTrigger_valueChanged(double value);
    void callFrequencyedit(bool);
    void callAmplitudeedit(bool);
    void callOffsetedit(bool);
    void callPhaseedit(bool);
    void callBTUREdit();
    void callBDREdit();
    void callPreTriggerCount();
    void callDACValue(bool);
    void setDefaultColor();

    void receiveValue(uint pValue);
    void receiveValue(double pValue);
    void receiveValue(QString pValue);

    //DSO WaveSettings -- Tab
    void on_cmbTimeBase_currentIndexChanged(int index);
    void on_cmbTimeUnit_currentIndexChanged(int index);
    void on_cmbSamples_currentIndexChanged(int index);
    void on_cmbMemory_currentIndexChanged(int index);
    void on_cmbChannel_currentIndexChanged(int index);
    void on_cmbTriggerSoruce_currentIndexChanged(int index);
    void on_LMHFilter_currentIndexChanged(int index);
    void on_LMHPowerMode_currentIndexChanged(int index);


    void on_chkCH1Odd_clicked();
    void on_chkCH1Even_clicked();
    void on_chkCH2Odd_clicked();
    void on_chkCH2Even_clicked();

    /*
     * DAC Slot
     *
     */

    void doDACDrive(short int,double);
    /*
     * Dial Slots
     */
    void on_timebaseDial_sliderMoved(int position);
    void on_memoryDial_sliderMoved(int position);

    void on_setForceTrigger();

    void doIntPlot(QList<unsigned char>,QList<unsigned char>);
};

#endif // LMH6518GUI_H
