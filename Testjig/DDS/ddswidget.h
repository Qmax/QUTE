#ifndef DDSWIDGET_H
#define DDSWIDGET_H

#include <QWidget>
#include <QPluginLoader>
#include <PTLibraryInterfaces.h>
#include <ApplicationCardInterface.h>
#include <PTGPIOEventInterfaces.h>
#include "AppdeviceRegisterDetails.h"
#include "BackPlaneInterface.h"
#include "ad5293.h"
#include <QLineEdit>
#include <QDebug>
#include <QtCore>
#include <QObject>
#include <math.h>
#include <qsettings.h>
#include <QTimer>
#include <unistd.h>
#include "daccalibration.h"
namespace Ui {
    class DDSWidget;
}
const QEvent::Type GpioEvent = (QEvent::Type) 1234;//embedded probe
const QEvent::Type KnobEvent = (QEvent::Type) 3456;//magnetic knob
const QEvent::Type PTKeyEvent = (QEvent::Type)5678;//pykey event
const QEvent::Type APPCARDDRIVEEVENT = (QEvent::Type) 7892;//Appcard drive Event


class DDSWidget : public QWidget {
    Q_OBJECT
public:
    DDSWidget(QWidget *parent = 0);
    ~DDSWidget();
    void loadQmaxPlugins();
    void initialiseLineEditControls();
    void initializeValues();
    void enableRichGUI();
    void saveSettings();
    void loadSettings();
    void customEvent(QEvent *e);

protected:
    void openNumKBPanel(short int pValue) ;
    void openNumKBPanelminmax(short int pValue,double pMax,double pMin);
    double validateTime(double pTime);
    double validateFrequency(double pFrequency);

    unsigned int m_nLineEditIndex;
    void changeEvent(QEvent *e);
    IQmaxLineEdit *ILineEdit;
    IQmaxPTLibrary *IPTLibrary;
    IQmaxNumberPanel *INumberPanel;
    IApplicationCardInterface *IAppCard;
    IntefaceBackPlane *IBackPlane;
    PTGPIOEventInterface *IGPIOEvent;
    int m_nKeyCode;


    QString ddsSetFile;
    unsigned short int m_nWS,m_nWS1,m_nWS2,m_nWS3,m_nWS4;

    QTimer *timer;
	unsigned int ret;

    // DDS Line Edit
    QLineEdit *m_objLE_ADDR;
    QLineEdit *m_objLE_DATA;

    QLineEdit *m_objLE_BTU;
    QLineEdit *m_objLE_BD;
    QLineEdit *m_objLE_OPFreq;
    QLineEdit *m_objLE_OPPhase; //rravi
    QLineEdit *m_objLE_STDLY;
    QLineEdit *m_objLE_WDP;
    QLineEdit *m_objLE_STOPDLY;
    QLineEdit *m_objLE_DPC;
    QLineEdit *m_objLE_DDSCycle;
    QLineEdit *m_objLE_DDSVoltage;

    AD5293 *m_objAD5293Component;


private:

    double m_nBTURVALUE;
    double m_nTickTime;
    double m_nTickFrequency;

    double m_nSystemFrequency;
    double m_nOutputFrequency;
    double m_nOutputPhase;
    double m_nOutputTime;
    double m_nDDSVoltage;

    unsigned short m_nAddress;
    unsigned short m_nData;
    unsigned short m_nBTUR;
    unsigned short m_nBDR;

    unsigned short m_nSTOP;
    unsigned short m_nSTART;
    unsigned short m_nDPC;

    unsigned int m_nWDP;
    unsigned short m_nWDP_LSW;
    unsigned short m_nWDP_MSW;

    unsigned short m_nFTW_LSW;//rravi
    unsigned short m_nFTW_MSW;//rravi

    unsigned short m_nPTW_LSW;//rravi
    unsigned short m_nPTW_MSW;//rravi

    unsigned short temp;
    unsigned short m_nDDSCycle;


    QString m_strTimeUnit;
    QString m_strFreqUnit;
    QString m_strPhaseUnit;



private slots:
    void on_comboBox_4_currentIndexChanged(int index);
    void on_comboBox_3_currentIndexChanged(int index);
    void on_comboBox_2_currentIndexChanged(int index);
    void on_countLoop_clicked(bool checked);
    void on_countLoop_clicked();
    void on_pushButton_clicked();
    void on_checkBox_clicked(bool checked);
    void on_bkpanelSelection_clicked(bool checked);
    void on_appSelection_clicked(bool checked);
    void on_butUpdate_clicked();
    void on_chkLoop_clicked(bool checked);
    void on_comboBox_currentIndexChanged(int index);
    void on_cmbVoltRanges_currentIndexChanged(int index);
    void on_butDrive_clicked();
    void on_butStop_clicked();
    void on_butCalculate_clicked();
    void on_butWrite_clicked();
    void on_butRead_clicked();
    void callAddressEdit();
    void callDataEdit();
    void callBTUEdit();
    void callBDEdit();
    void callOPFrequencyEdit();
    void callOPPhaseEdit();//rravi
    void callSTARTDLYEdit();
    void callSTOPDLYEdit();
    void callWDPEdit();
    void callDPCEdit();
    void callDDSCycle();
    void callDDSVoltageEdit();


    void receiveValue(unsigned int pValue);
    void receiveValue(double);
    void receiveValue(QString);
    void LoopDrive();

private:
    Ui::DDSWidget *ui;
};

#endif // DDSWIDGET_H
