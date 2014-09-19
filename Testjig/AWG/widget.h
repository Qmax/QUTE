#ifndef WIDGET_H
#define WIDGET_H

#include <qdebug.h>
#include <qpluginloader.h>
#include <QtCore>
#include <QObject>
#include <QWidget>
#include <qlineedit.h>
#include "InterfacePTLibrary.h"
#include "WaveformTestjigInterface.h"


namespace Ui {
    class Widget;
}

class Widget : public QWidget{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
    void Initialization();
    void enableRichGUI();
    void GenerateWaveform();
    stWaveData* showAWGTrace(int pWaveTrace);
	short int m_nLineEditIndex;

	QString m_strSelectWaveForm,m_strSingleContinuous;
	double n_offset,n_frequency,n_time,n_timeBase,n_duration,n_samples;
	double n_sourceImpedance,n_driveRange,n_cycles;

    QLineEdit *objAddress,*objData,*objOffset,*objFrequency,*objTime;
    QLineEdit *objTimeBase,*objDuration,*objSamples;

protected:
    void changeEvent(QEvent *e);
    IQmaxLineEdit *ILineEdit;
    IQmaxNumberPanel *INumberPanel;
    IQmaxWaveProduct *objWaveProduct;
    stWaveData *l_objReceive1Data,*m_objWaveData;

    void openNumKBPanel(short int);
    void openNumKBPanel(short int,double,char,double,double,QWidget*);

private:
    Ui::Widget *ui;

private slots:
        void on_cmbDriveMode_currentIndexChanged(int index);
        void on_cmbImpedance_currentIndexChanged(int index);
        void on_cmbDrvVoltage_currentIndexChanged(int index);
        void on_pushButton_clicked();
        void on_cmbPatterns_currentIndexChanged(QString );
 void receiveValue(unsigned int);
	void receiveValue(double);
	void receiveValue(QString);

	void callAddressEdit();
	void callDataEdit();
	void callOffsetEdit();
	void callFrequencyEdit();
	void callTimeEdit();
	void callTimeBaseEdit();
	void callDurationEdit();
	void callSamplesEdit();
};

#endif // WIDGET_H
