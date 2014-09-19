#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <dsographicsitems.h>
#include <channelwidget.h>
#include <QDomDocument>
#include <QDomNodeList>

#include <qpluginloader.h>
#include <QtGui>

#include <ApplicationCardInterface.h>
#include "lmh6518.h"
#include "BackPlaneInterface.h"
#include "hardwareinterface.h"
#include "IPSOCCommunication.h"
#include "DSOWaveSettings.h"
#include "PTAppBckPsocInterface.h"
#include "PTGPIOEventInterfaces.h"
#include "PTEventInterfaces.h"
//#include "dialwidget.h"
#include "dsodatasettings.h"
#include "dial.h"
#include "DSOCommon.h"



namespace Ui {
    class MainWindow;
}

struct DisplayElement
{

};



class ChannelItemWidget;


class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
signals:
     void clicked(int);
protected:
    void changeEvent(QEvent *e);
    //DSO attributes
    QGraphicsView *m_objDSOview;
    QGraphicsScene *m_objDSOscene;
    DSOXYPlane *m_objDSOXYGridItem;
    HCursorItem *m_objDSOH1Cursor;
    HCursorItem *m_objDSOH2Cursor;

    HCursorItem *m_objMaxPeakPointer;
    HCursorItem *m_objMinPeakPointer;

    LineItem *m_objTR10Pointer;
    offsetItem *m_objCH1OffsetPointer,*m_objCH2OffsetPointer;

    VCursorItem *m_objDSOV1Cursor;
    VCursorItem *m_objDSOV2Cursor;

    VTriggerItem *m_objVerticalTrigger;
    HTriggerItem *m_objHorizontalTrigger;

    channelItem *m_objch1Item,*m_objch2Item;
    QRectF m_objBoundaryRect;

    QList<unsigned char> mLstEven,mLstOdd;

    void initConfiguration();
    void InitializeHardwareLibs();
    IApplicationCardInterface *IAppCard;
    PTEventInterface *IPTKeyEvent;
    HardwareInterface *hwInterface;
    IntefaceBackPlane *IBackPlane;
    IPSOCCOMMUNICATION *IPsoc;
    IPTAppBckPsocInterface *test;
    PTGPIOEventInterface *IGPIOEvent;
    LMH6518 *m_objLMH6518Component;
    LMH6518_DataTemplate m_eDataTemplate,m_eDataTemplate2,m_eDataTemplateCH2;
    VOLTAGEPERDIVISION m_eVoltage,m_eCH2Voltage;
    LMH6518Data Data,DataCH2;
    PlotXYSettings *m_objCh1PlotSettings,*m_objCh2PlotSettings;

    DSOWaveSettings *m_objDSOWaveSettings;
    DSODataSettings *m_objDSODataSettings;
    int m_nKeyCode;
    short int m_nPrecount,m_nPostCount;
    int m_nPTKeyCode;
    unsigned int m_nSamples;


    unsigned int m_nFTW,m_nFTW_LSB,m_nFTW_MSB;
    double m_nSystemFrequency,m_nOutputFrequency;

    unsigned int m_nLeftMove,m_nRightMove;
    unsigned int m_nUpCounter,m_nDownCounter,m_nComboCounter;
    double m_nTimePerSample;
    double m_nTimebaseTriggerPoint,m_nVoltageTriggerPoint,m_nVoltPerDivision ;
    double m_nAcutalTriggertimeBase;
    QString m_strTimeUnit;
    short int m_nTimeUnitIndex;
    unsigned int m_nMaxRecordLength;
    double m_nSampleRate[10];
    unsigned short m_nSampleIndex,m_nSampleUnit;
    double m_nCH1dxOffsetPosition,m_nCH2dxOffsetPosition;


    RECEIVER_CONF m_eReceConf;
    DSO_TRIGGER m_eTrigger;

    bool m_bTimeSelected,m_bAmpSelected,m_bH1Cursor,m_bH2Cursor,m_bV1Cursor,m_bV2Cursor;

    bool m_bModeSelected,m_bMaxMemorySelected;
    bool m_bShowH1,m_bShowV1;
    bool m_bCH1TriggerSource,m_bCH2TriggerSource;
    bool m_bCH1Offset,m_bCH2Offset;

    //------------
    // DSO Functional Item Modules
    void doFunction(BASEWIDGET,QString);
    void initialiseDSOGraphicsItems();
    void initialiseDSODataSet();
    void initChannelWidget();
    void defaultSidePane(BASEWIDGET,QString,QString);
    void createDynamicSubItems();
    void clearCommandButtons();
    void initializeTimeBaseList();
    void initializeMemoryList();
    void initializeVoltageList();
    void updateValues();
    unsigned int validateSampleRate();
    void InitializeTriggers();
    void on_cmbLMHVoltage_currentIndexChanged(int);

    //void openFile();
    QList<QString> parseXML(QString,QString);
    ChannelItemWidget *channel1Widget,*channel2Widget,*triggerWidget,*timeBaseWidget,*cursorsWidget;
    ChannelWidget *ch1UIWidget;
    unsigned short m_nCH1VoltIndex,m_nCH2VoltIndex;
    //DSONavigationItems *m_objDSONavigationItems;
    QList<QString> m_lstNavigationItems;
    QString m_strChildItem;
    QList<double> m_lstTimebaseValues;
    QList<QString>m_lstTimebaseUnit;
    QList<double> m_lstMemoryValues;
    QList<QString> m_lstMemoryUnit;
    QList<double> m_lstVoltageValues;
    QList<QString> m_lstVoltageUnit;

    //dialWidget *m_objDialWidget;

    double m_nV1CursorPosition,m_nV1dxFactor,m_nV2CursorPosition,m_nV2dxFactor;
    double m_nH1CursorPosition,m_nH1dxFactor,m_nH2CursorPosition,m_nH2dxFactor;

    double m_nV1TimebasePostion,m_nV2TimebasePostion;
    double m_nH1VoltagePostion,m_nH2VoltagePostion;
     PotentioMeter *m_objVoltageDial;
     PotentioMeter *m_objTimeDial;
    unsigned int m_nChannel1Value,m_nChannel2Value;
    DSO_CHANNEL m_SelectedChannel;
    BASEWIDGET m_eChannelSelected;
    bool m_bRUNFlag;
private:
    Ui::MainWindow *ui;
    QPushButton *m_objSubItems[6];
    bool isCH1tblChecked;
    QSignalMapper *signalMapper;

private slots:
    void on_butRIGHT_clicked();
    void on_butDOWN_clicked();
    void on_butUP_clicked();
    void on_butLEFT_clicked();

    void on_butOffset_plus_clicked();
    void on_butOffset_minus_clicked();
    void on_butOffset_zero_clicked();
    //void on_optVerticalTrigger_clicked();
    //void on_optHorTrigger_clicked();
    void on_pushButton_clicked();
    void on_butRUNSTOP_clicked();
    void changeChannel1Widget(BASEWIDGET);
    void changeChannel2Widget(BASEWIDGET);
    void changeTriggerWidget(BASEWIDGET);
    void changeTimeBaseWidget(BASEWIDGET);
    void changeCursorsWidget(BASEWIDGET);
    void doNavigation(int);
    void doIntPlot(QList<unsigned char> pLstOdd,QList<unsigned char> pLstEven);
    void on_timebaseDialWheel_sliderMoved(int position);
    void on_VoltageDialWheel_sliderMoved(int position);
    void on_triggerWheel_sliderMoved(int position);
    void on_dblHorizontalTrigger_valueChanged(double pValue);
    void on_dblVerticalTrigger_valueChanged(double pValue);
    //void on_memoryDial_sliderMoved(int position);

    void incrementTimeDial();
    void decrementTimeDial();

    void incrementVoltageDial();
    void decrementVoltageDial();

    void checkTimeDial();
};



class ChannelItemWidget:public QWidget
{
    Q_OBJECT
public:
    ChannelItemWidget(QString pStyleSheet,BASEWIDGET pWidget,QWidget *pObj=0):QWidget(pObj,Qt::FramelessWindowHint)
    {
        setStyleSheet(pStyleSheet);
        isChecked = false;
        m_eBaseWidget = pWidget;
    }
    ~ChannelItemWidget()
    {
    }
    void modifyStyleSheet(bool pFlag,BASEWIDGET pbaseWidget)
    {
    	QString lstrStyleSheet;
      //  qDebug()<<"StyleSheed Modify"<<pFlag<<pbaseWidget;
    	switch(pbaseWidget)
    	{
        case 0:
            {
    		if(pFlag )
    			lstrStyleSheet = gStrEnCH1Widget;
    		else
    			lstrStyleSheet = gStrDnCH1Widget;
    		break;
    	}
        case 1:
    	{
    		if(pFlag )
    			lstrStyleSheet = gStrEnCH2Widget;
    		else
    			lstrStyleSheet = gStrDnCH2Widget;
                break;
    	}
    	case TIMEBASE:
    	{
            if(pFlag )
                    lstrStyleSheet = gStrEnTriggerWidget;
            else
                    lstrStyleSheet = gStrDnTriggerWidget;
            break;

    		break;
    	}
    	case TRIGGER:
    	{
                if(pFlag )
                        lstrStyleSheet = gStrEnTriggerWidget;
                else
                        lstrStyleSheet = gStrDnTriggerWidget;
                break;
    	}
    	case CURSORS:
    	{
            if(pFlag )
                    lstrStyleSheet = gStrEnTriggerWidget;
            else
                    lstrStyleSheet = gStrDnTriggerWidget;
            break;
    	}
    	}
        isChecked = pFlag;
    	setStyleSheet(lstrStyleSheet);
    }
    BASEWIDGET returnBASEUI()const
    {
    	return m_eBaseWidget;
    }
    bool isPressed() const
    {
        return isChecked;
    }
signals:
    void clicked(BASEWIDGET);
protected:
    void mousePressEvent(QMouseEvent *e)
    {
        if(isChecked == true)
            isChecked = false;
        else if(isChecked == false)
            isChecked = true;
      //  qDebug()<<"Item Checked:"<<isChecked<<m_eBaseWidget;
        //modifyStyleSheet(isChecked,m_eBaseWidget);
        emit clicked(m_eBaseWidget);
    }

//    void mouseReleaseEvent(QMouseEvent *e)
//    {
//        emit clicked(false);
//    }
    void paintEvent(QPaintEvent *)
    {
        QStyleOption opt;
        opt.init(this);
        QPainter p(this);
        style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    }
    bool isChecked;
    BASEWIDGET m_eBaseWidget;
};


#endif // MAINWINDOW_H
