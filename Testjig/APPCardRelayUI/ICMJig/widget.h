#ifndef WIDGET_H
#define WIDGET_H

#include <QtCore>
#include <QObject>
#include <QWidget>
#include <qpluginloader.h>
#include <qlineedit.h>
#include "InterfacePTLibrary.h"
#include "WaveformTestjigInterface.h"
#include "ad7190component.h"
#include "ad5318components.h"
#include "ApplicationCardInterface.h"
#include "PTSPIMemoryInterface.h"
#include <qtimer.h>
#include <unistd.h>

//#include "ICMTestJigInterface.h"

namespace Ui {
    class Widget;
}

class Widget : public QWidget{//,public IICMTestJigInterface {
    Q_OBJECT
//    Q_INTERFACES(IICMTestJigInterface)	//for interface
public:
    Widget(QWidget *parent = 0);
    ~Widget();
    void GenerateWaveform();
    stWaveData* showICMTrace(int pWaveTrace);
//    void setICM(QWidget* parent){
//     	Widget* obj=new Widget(parent);
//     	qDebug()<<"ICM GUI INIT";
//     	obj->show();
//     }
//
//    void HardwareInitializtaion();

    void enableRichGUI();

    void Initialization();
	short int m_nLineEditIndex;

    QLineEdit *objAddress,*objData,*objVoltage,*objResistance,*objCapacitance,*objInductance;
    QLineEdit *objForceVoltage,*objFrequency,*objAverageSamples;


protected:
    void changeEvent(QEvent *e);
    IQmaxLineEdit *ILineEdit;
    IQmaxNumberPanel *INumberPanel;
    IQmaxWaveProduct *objWaveProduct;
    IApplicationCardInterface *IAppCard;
    AD7190Component *m_objAD7190Component;
    AD5318Components *m_objAD5318Component;
    ISPIMemoryInterface *ISPIMemory;
    stWaveData *l_objReceive1Data,*m_objWaveData;
    unsigned int m_nADC1Voltage,m_nADC2Voltage;
    unsigned short int m_nAddress,m_nData,m_nSamples;
    double m_nResistance,m_nCapacitance,m_nInductance;
    double m_nFrequency,m_nForceVoltage;
    unsigned short m_nICMMGR;
    QTimer *ADCtimer;
    QVector<QPointF> m_nData1;
    unsigned short int *mValues;
    double m_nImpedanceValue;
    double m_nAVGSamples;
    AD5318_DACSELECT m_eSelect;
    void openNumKBPanel(short int);
    void openNumKBPanel(short int,double,char,double,double,QWidget*);
    void initialiseHWLibraries();
    void initialiseFeedBackResistance();
    void GenerateSINEPattern(double);
    void GenerateHexPattern();
    void calculateFrequency();
    void resetDAC();
    void updateDAC(double);
    void GetRange(double,short int);
    void GetDisplayResistance(double pValue,double);
    void GetDisplayCapcitance(double pValue,short int);
    void GetDisplayInductance(double pValue,short int);
    void calculateDDSFrequency();
    double validateFrequency(double);
    QList<unsigned int>m_lstReistance;
    QList<double>m_lstRFResistance;
    QList<double>m_lstRFCapcitance;
    QList<double>m_lstRFInductance;


private:
    Ui::Widget *ui;
private slots:
	void receiveValue(unsigned int);
	void receiveValue(double);
	void receiveValue(QString);

	void callAddressEdit();
	void callDataEdit();
	void callForceVoltageEdit();
	void callFrequencyEdit();
	void callAverageSamplesEdit();

	void on_butRead_clicked();
	void on_butWrite_clicked();
	void on_chkCapSet_clicked();
	void on_chkPOTSel_clicked();
	void on_chkDivSel_clicked();
	void on_chkReceiver1_clicked();
	void on_chkReceiver2_clicked();
	void on_optDifferential_clicked();
	void on_optPseudo_clicked();


	void on_butMeasure_clicked();
	void on_butStop_clicked();
	void on_butDCDrive_clicked();
	void readADC();
	void on_chkP1V_clicked();
	void on_chkP2V_clicked();

	void on_cmbResistance_currentIndexChanged(int index);
	void on_cmbCapcitance_currentIndexChanged(int index);
	void on_cmbInductance_currentIndexChanged(int index);
	void on_cmbICMRange_currentIndexChanged(int index);

	void on_optResistance_clicked();
	void on_optCapacitance_clicked();
	void on_optInductance_clicked();

	void on_chkDDSFreq_clicked();


};

#endif // WIDGET_H
