
#ifndef PTPSOCTESTJIGINTERFACE_H
#define PTPSOCTESTJIGINTERFACE_H

#include <QtGui/QWidget>
#include "ui_ptpsoctestjiginterface.h"

const QEvent::Type GpioEvent = (QEvent::Type) 1234;//embedded probe

#include "headers.h"


class PTPSoCTestJigInterface : public QWidget
{
    Q_OBJECT

public:
    PTPSoCTestJigInterface(QWidget *parent = 0);
    ~PTPSoCTestJigInterface();

    void Initialization();
    void LoadPlugins();
    void SignalsAndSlots();
    void enableRichGUI();
    void disableAllComboBox();
    void customEvent(QEvent *eve);
    void convertToBits(unsigned char,int);

    void openNumKBPanel(short int);


private:
    Ui::PTPSoCTestJigInterfaceClass ui;
protected:
	IPSOCCOMMUNICATION *IPsoc;
    IntefaceBackPlane *IBackPlane;
    PTGPIOEventInterface	*IGPIOEvent;
    InterfaceGPIOPins *IGPIOPin;
    IApplicationCardInterface *IAppCard;
    IGenericInterface *IGenCard;
    IDSOCardInterface *IDSOCard;

    IQmaxLineEdit *ILineEdit;
    IQmaxNumberPanel *INumberPanel;
    QLineEdit *AppAddr,*BckAddr,*CommandLineEdit,*AppData,*BckData;
    QLineEdit *GenData,*GenAddr,*GenBaseAddr;

	short int m_nLineEditIndex;
    unsigned char function;
	unsigned int byte1[8],byte2[8],byte3[8],byte4[8];
	unsigned int already1,already2,already3,already4;
	int m_nGPIOCode;



private slots:
        void on_pbGenWrite_clicked();
        void on_pbGenRead_clicked();
        void on_pushButton_7_clicked();
        void on_topRelay24_clicked();
        void on_comboBox_13_currentIndexChanged(int index);
        void on_pushButton_6_clicked();
        void on_pushButton_4_clicked();
        void on_pushButton_3_clicked();
        void on_pushButton_8_clicked();
        void on_pushButton_9_clicked();
        void on_pushButton_2_clicked();
        void on_pushButton_clicked();
        void on_pushButton_5_clicked();
        void on_butSeqWrite_clicked(); // Added for Sequence Write Operations Elangovan.D 1-11-2014
        void on_butSampling_clicked();
        void on_butSamplingRD_clicked();

//        void TestButton();
//        void SwitchMux();
//        void ReadCodeID();
        void ReadRelays();
        void ResetRelays();
        void SendCommand();

//        void Multimeter();
//        void Oscilloscope();
//        void FunctionGenerator();
//        void ShortLocator();
//        void InCircuitMeasurement();
//        void VoltageCurrent();

//        void Voltage(int);
//        void R2Wire(int);
//        void R4Wire(int);
//        void Current(int);
//        void Oscilloscope1(int);
//        void Oscilloscope2(int);
//        void FunctionGenerater(int);
//        void ShortLocater(int);
//        void InCircuitMeasureMent(int);
//        void VoltageCurrent1(int);
//        void VoltageCurrent2(int);
//        void MuxInputs(int);

//        void callMuxTestInput();
//        void callMuxRefInput();
        void callCommandInput();
        void callAppAddr();
        void callAppData();
        void callBckAddr();
        void callBckData();

        void callGenData();
        void callGenAddr();
        void callBaseAddr();

//        void EmbeddedKey();
        void CommandSelection(int);

        void psocError(bool);

    	void receiveValue(unsigned int);
    	void receiveValue(double);
    	void receiveValue(QString);
};

#endif // PTPSOCTESTJIGINTERFACE_H
