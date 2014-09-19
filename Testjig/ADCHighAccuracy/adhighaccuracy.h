#ifndef ADHIGHACCURACY_H
#define ADHIGHACCURACY_H

#include <QWidget>
#include <QDebug>
#include <ApplicationCardInterface.h>
#include <ad7190component.h>
#include <QPluginLoader>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <qsettings.h>
#include "PTAppBckPsocInterface.h"

namespace Ui {
    class ADHighAccuracy;
}

class ADHighAccuracy : public QWidget {
    Q_OBJECT
public:
    ADHighAccuracy(QWidget *parent = 0);
    ~ADHighAccuracy();
    void enableRichGUI();
    void loadSPIBIT();

protected:
    IPTAppBckPsocInterface *test;
    IApplicationCardInterface *IAppCard;
    AD7190Component *m_objAD7190;
    void changeEvent(QEvent *e);
    unsigned int m_nADCIndex;

       unsigned int m_nModeRegister;
       unsigned int m_nConfigurationRegister;
       unsigned short m_nGPConRegister;
       unsigned short m_nStatusRegister;
       unsigned int m_nDataRegister;
       unsigned short m_nIDRegister;
       unsigned int m_nOffsetRegister;
       unsigned int m_nFullScaleRegister;
       QMap<short, short> m_GainValues;
       QMap<short, double> m_GainFactors;
       short m_nADC;
       bool m_nChop;
       double m_nCurrent;
       double m_nGainFactor;
       double m_nSerialDAC2Voltage;
       short m_nP0, m_nP1, m_nP2, m_nP3;

       void InitialiseRegisterMap();
       void InitialiseHWLibraries();
       QTimer *mTimer;

       //Settings
           void saveSettings();
           void loadSettings();
          // void LoadSettingsData();
           QString m_strADCSettingsFile;

private:
    Ui::ADHighAccuracy *ui;

private slots:


private slots:
    void on_settings_clicked();
    void on_comboBox_currentIndexChanged(int index);
    void on_doubleSpinBox_6_valueChanged(double );
    void on_spnFSBits_3_valueChanged(int );
    void on_butGP7_3_clicked();
    void on_butGP6_3_clicked();
    void on_butGP5_3_clicked();
    void on_butGP4_3_clicked();
    void on_butGP3_3_clicked();
    void on_butGP2_3_clicked();
    void on_butGP1_3_clicked();
    void on_butGP0_3_clicked();
    void on_butFullScale_3_clicked();
    void on_butOffset_3_clicked();
    void on_butGPCon_3_clicked();
    void on_butData_3_clicked();
    void on_butConfig_3_clicked();
    void on_butMode_3_clicked();
    void on_butChipID_3_clicked();
    void on_butStatus_3_clicked();
    void on_butReset_3_clicked();
    void on_butA4Com_3_clicked();
    void on_butA3Com_3_clicked();
    void on_butA2Com_3_clicked();
    void on_butAinCOm_3_clicked();
    void on_butA2A2_3_clicked();
    void on_butTempSensor_3_clicked();
    void on_butA3A4_3_clicked();
    void on_butA1A2_3_clicked();
    void on_cmdRWop_3_currentIndexChanged(int index);
    void on_cmbADCSel_3_currentIndexChanged(int index);
    void on_cmbOPParity_3_currentIndexChanged(int index);
    void on_cmbOPData_3_currentIndexChanged(int index);
    void on_cmbClock_3_currentIndexChanged(int index);
    void on_cmbZeroLatency_3_currentIndexChanged(int index);
    void on_cmbFilter_3_currentIndexChanged(int index);
    void on_cmbModes_3_currentIndexChanged(int index);
    void on_cmbRefDetect_3_currentIndexChanged(int index);
    void on_cmbRefSelect_3_currentIndexChanged(int index);
    void on_cmbHzReject_3_currentIndexChanged(int index);
    void on_cmbDiagnostic_3_currentIndexChanged(int index);
    void on_cmbChopping_3_currentIndexChanged(int index);
    void on_cmbBuffer_3_currentIndexChanged(int index);
    void on_cmbPolarity_3_currentIndexChanged(int index);
    void on_cmbGain_3_currentIndexChanged(int index);
    void on_butStTimer_clicked();
    void checkADC();
};

#endif // ADHIGHACCURACY_H
