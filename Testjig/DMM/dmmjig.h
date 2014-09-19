#ifndef DMMJIG_H
#define DMMJIG_H

#include <QWidget>
#include <QLineEdit>
#include <QPluginLoader>
#include <QtCore>
#include "InterfacePTLibrary.h"
#include "WaveformTestjigInterface.h"
#include "DMMTestJigInterface.h"
#include "plotter.h"

#include "IPSOCCommunication.h"
#include "AppdeviceRegisterDetails.h"
#include "InterfaceFunctionalComponents.h"
#include "ad5318components.h"
#include "ad7190component.h"

#include <qtimer.h>


namespace Ui {
    class DMMJig;
}

class DMMJig : public QWidget{//,public IDMMTestJigInterface {
    Q_OBJECT
//    Q_INTERFACES(IDMMTestJigInterface)	//for interface
public:
    DMMJig(QWidget *parent = 0);
    ~DMMJig();

    void GenerateWaveform();
    stWaveData* showDMMTrace(int pWaveTrace);

//    void setDMM(QWidget* parent){
//    	DMMJig* obj=new DMMJig(parent);
//    	qDebug()<<"DMM GUI INIT";
//    	obj->show();
//    }
//
//    void HardwareInitializtaion();
    void enableRichGUI();
    void Initialization();
    void InitializeHardwareLibraries();
    void InitializeHardwareValues();
    void readCurrentCalibrationFile();
    void readADC();

    unsigned int m_nADC1Voltage;

	short int m_nLineEditIndex;
	double m_nRangeSlope[5],m_nRangeConstant[5];

    QLineEdit *objAddress,*objData,*objVoltage,*objCurrent,*objResistance;
    QLineEdit *objAvgSamples,*objForceCurrent,*objDACVoltage;

    QTimer *timer;

protected:
    void changeEvent(QEvent *e);
    IQmaxLineEdit *ILineEdit;
    IQmaxNumberPanel *INumberPanel;

    unsigned short int m_nAddress,m_nData;

    IQmaxWaveProduct *objWaveProduct;
    stWaveData *l_objReceive1Data,*m_objWaveData;

    IApplicationCardInterface *IAppCard;
    IPSOCCOMMUNICATION *IPsoc;  //PSOC Interface Plugin

    AD5318_DACSELECT m_eSelect;
    AD5318Components *m_objAD5318Component;
    AD7190Component *m_objAD7190Component;
    AD5318_dataTemplate l_nAD5318DW;

    double m_nDACVoltage,m_nForceCurrent,m_nDACFVoltage,m_nDACFVoltage2;

    bool DACVoltage;
    double nullify;

    void openNumKBPanel(short int);

private:
    Ui::DMMJig *ui;

private slots:

 void on_checkBox_3_clicked(bool checked);
 void on_checkBox_2_clicked(bool checked);
 void on_cmbOffset_currentIndexChanged(int index);
 void on_butWrite_clicked();
 void on_butRead_clicked();
 void on_pushButton_2_clicked();
 void on_pushButton_clicked();

 void on_radioButton_6_clicked(bool checked);
 void on_radioButton_4_clicked(bool checked);
 void on_radioButton_5_clicked(bool checked);
 void on_radioButton_3_clicked(bool checked);
 void on_radioButton_2_clicked(bool checked);
 void on_radioButton_clicked(bool checked);

 void on_cmbImpedance_3_currentIndexChanged(int index);
 void on_cmbImpedance_2_currentIndexChanged(int index);
 void on_cmbImpedance_currentIndexChanged(int index);
 void on_cmbDrvVoltage_currentIndexChanged(int index);


 void receiveValue(unsigned int);
 void receiveValue(double);
 void receiveValue(QString);

	void callAddressEdit();
	void callDataEdit();
	void callSamplesEdit();
	void callForceCurrentEdit();
	void callDACVoltage();

    void LoopDrive();


};

#endif // DMMJIG_H
