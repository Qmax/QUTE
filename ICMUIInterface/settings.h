/*
 *      Author: Ravivarman.R,Qmax
 */
#ifndef SETTINGS_H
#define SETTINGS_H

#include <QWidget>
#include <qlineedit.h>
#include <qdebug.h>
#include <qpluginloader.h>
#include <QFile>
#include <QXmlStreamReader>
#include <QXmlStreamAttributes>
#include <QString>
#include "InterfacePTLibrary.h"
#include "ApplicationCardInterface.h"
#include "BackPlaneInterface.h"
#include "ad5293.h"
#include "ad7190component.h"
#include "IPSOCCommunication.h"
#include "hardwareinterface.h"


namespace Ui {
    class Settings;
}

class Settings : public QWidget {
    Q_OBJECT
public:
    Settings(IPSOCCOMMUNICATION*,HardwareInterface*,IApplicationCardInterface*,AD7190Component*,QWidget *);
    ~Settings();

protected:
   	IntefaceBackPlane *IBackPlane;	////BackPlaneInterfacePlugin
    HardwareInterface *hwInterface;
    IPSOCCOMMUNICATION *IPsoc;
    QLineEdit *objForceVoltage,*objFrequency;
    IApplicationCardInterface *IAppCard;
    IQmaxLineEdit *ILineEdit;
    IQmaxNumberPanel *INumberPanel;
    AD7190Component *m_objAD7190Component;
    AD5293 *m_objAD5293Component;

    void openNumKBPanel(short int);
    void openNumKBPanel(short int,double,char,double,double,QWidget*);

    void changeEvent(QEvent *e);

    double m_nFrequency,m_nForceVoltage;
    unsigned short m_nICMMGR;
    unsigned short m_nR1RMSCAVG,m_nR1RMSGAIN,m_nR1RMSIN,m_nR2RMSCAVG,m_nR2RMSGAIN,m_nR2RMSIN;
	short int m_nLineEditIndex;

	unsigned short m_nFTW_LSW,m_nFTW_MSW;
	double m_nFTWOutputFrequency;
	double m_nRangeSlope[5],m_nRangeConstant[5];
	double m_nAmplitude;

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	unsigned short int m_nAddress,m_nData;
	unsigned short int m_nBPAddress,m_nBPData;
        double m_nOffset,m_nDCVoltage;
	QLineEdit *objAddress,*objData;
	QLineEdit *objBPAddress,*objBPData;
	QLineEdit *objOffset;
        QLineEdit *objDCVoltage;
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    void calculateDDSFrequency();
private:
    Ui::Settings *ui;

private slots:
        void on_applySrc_clicked();
        void on_srcImpBox_10_currentIndexChanged(int index);
        void on_comboBox_currentIndexChanged(int index);
        void on_right_clicked();
        void on_left_clicked();
        void on_down_clicked();
        void on_up_clicked();
        double validateCursorPosition(short pos,double value,short incDec);

        void on_WriteAppCard_2_clicked();
        void on_ReadAppCard_2_clicked();
        void on_adc2_clicked();
        void on_adc1_clicked();
        void on_WriteAppCard_clicked();
 void on_ReadAppCard_clicked();
 void on_ExtInt_clicked(bool checked);
    void on_R2RMSIN_clicked(bool checked);
    void on_R2RMSGAIN_clicked(bool checked);
    void on_R2RMSCAVG_clicked(bool checked);
    void on_R1RMSIN_clicked(bool checked);
    void on_R1RMSGAIN_clicked(bool checked);
    void on_R1RMSCAVG_clicked(bool checked);
    void on_chkDivSel_clicked(bool checked);
    void on_chkPOTSel_clicked(bool checked);
    void on_chkCapSet_clicked(bool checked);
    void on_pushButton_clicked();

    void receiveValue(unsigned int);
    void receiveValue(double);
    void receiveValue(QString);

    void callForceVoltageEdit();
    void callFrequencyEdit();

    //~~~~~~~~~~~~~~~~~~~~~~~~~~
	void callAddressEdit();
	void callDataEdit();
	void callBPAddressEdit();
	void callBPDataEdit();
	void callOffset();
        void callDCVoltage();
	//~~~~~~~~~~~~~~~~~~~~~~~~~
	signals:
	    	void FrequencyChange(double);
                void SrcImpChange(QString);
	    	void OffsetChange(double);
                void FeedbackChange(int);
};

#endif // SETTINGS_H
