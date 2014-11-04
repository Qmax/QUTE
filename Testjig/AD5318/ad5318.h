#ifndef AD5318_H
#define AD5318_H

#include <QWidget>
#include <QLineEdit>
#include <PTLibraryInterfaces.h>
#include <ApplicationCardInterface.h>
#include <BackPlaneInterface.h>
#include "ad5293.h"
#include <ad5318components.h>
#include <ad7190component.h>
#include <QMessageBox>
#include <QDebug>
#include <QPluginLoader>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "PTLMH6518Interface.h"
#include "ICALIBTestJigInterface.h"
#include "VCALIBTestJigInterface.h"
#include "RXCALIBTestJigInterface.h"
#include "RefCALIBTestJigInterface.h"
#include "PTAppBckPsocInterface.h"
#include "DMMSPITestJigInterface.h"


#define PI  3.14

namespace Ui {
    class AD5318;
}

class AD5318 : public QWidget {
    Q_OBJECT
public:
    AD5318(QWidget *parent = 0);
    ~AD5318();
    void enableRichGUI();
protected:
        IICALIBTestJigInterface *ICalib;
        IVCALIBTestJigInterface *VCalib;
        IRXCALIBTestJigInterface *RXCalib;
        IRefCALIBTestJigInterface *REFCalib;
        IPTAppBckPsocInterface *test;
        DMMSPITestJigInterface *DMMTestjig;

        IPTLMH6518Interface *LMH6518;

    void openNumKBPanel(short int pValue) ;
    void openNumKBPanelminmax(short int pValue,double pMax,double pMin);

    IQmaxLineEdit *ILineEdit;
    IQmaxPTLibrary *IPTLibrary;
    IQmaxNumberPanel *INumberPanel;
    IApplicationCardInterface *IAppCard;
    IntefaceBackPlane *IBackPlane;
    AD5318Components *m_objAD5318Component;
    AD7190Component *m_objAD7190Component;
    AD5293 *m_objAD5293Component;
    AD5318_DACSELECT m_eSelect;

    unsigned short int m_nLineEditIndex,m_nAddress,m_nData,m_nADCIndex;
    double m_nDACVoltage;
    unsigned int m_nADC1Voltage,m_nADC2Voltage;
    double m_nGainFactor;

    double m_nDCVoltage,m_nAD5293Voltage;

    QString dPanelData;

    void initialiseLineEdits();
    void initialiseHWLibraries();
    void initialiseValues();
    void GenerateSINEPattern(double);
    void GenerateHexPattern();
    QLineEdit *m_objLE_ADDR;
    QLineEdit *m_objLE_DATA;
    QLineEdit *m_objLE_DACVoltage;
    QLineEdit *m_objLE_DCVoltage;
    QLineEdit *m_objLE_AD5293Voltage;
    QTimer *ADCtimer,*RLYTimer,*DriveDoneTimer,*testTimer;
    QVector<QPointF> m_nData1;


    void changeEvent(QEvent *e);
private slots:
    void on_butHY3131_clicked();
    void on_appBck_clicked();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_butLMH6518_clicked();
    void on_Reference_clicked();
    void on_Receiver_clicked();
    void on_DriveVoltage_clicked();
    void on_DriveCurrent_clicked();
    void on_butFileManager_clicked();
    void on_chkDACH_clicked();
    void on_chkDACG_clicked();
    void on_chkDACF_clicked();
    void on_chkDACE_clicked();
    void on_chkDACD_clicked();
    void on_chkDACC_clicked();
    void on_chkDACB_clicked();
    void on_chkDACA_clicked();
    void on_butUpdateDAC_clicked();
    void on_butRstDAC_clicked();
    void on_butWrite_clicked();
    void on_butRead_clicked();
    void on_butDriveDC_clicked();
    void on_butStartADC_clicked();
    void on_butStopADC_clicked();
    void on_chkADC1_clicked();
    void on_chkADC2_clicked();
    void callAddressEdit();
    void callDataEdit();
    void callDACVoltageEdit();
    void callDCVoltageEdit();
    void callAD5293VoltageEdit();
    void readADC();
    void switchRLY(unsigned short);
    void on_chkP1V_clicked();
    void on_chkP2V_clicked();
    void on_chkPseudo_clicked();
    void on_butGain1_clicked();
    void on_butGain8_clicked();
    void on_butGain16_clicked();
    void on_butGain32_clicked();
    void on_butGain64_clicked();
    void on_butGain128_clicked();
    void on_butSwitchRly_clicked();
    void on_butCheckDriveDone_clicked();
    void on_butStart_clicked();

    void on_butAD5293Drive_clicked();

    void receiveValue(unsigned int pValue);
    void receiveValue(double);
    void receiveValue(QString);
    void switchDACVoltages();
    void switchRelays();

private:
    Ui::AD5318 *ui;
};

#endif // AD5318_H
