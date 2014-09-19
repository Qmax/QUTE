
#ifndef PTPSOCTESTJIGINTERFACE2_H
#define PTPSOCTESTJIGINTERFACE2_H

#include <QtGui/QWidget>
#include "ui_ptpsoctestjiginterface2.h"

const QEvent::Type GpioEvent = (QEvent::Type) 1234;//embedded probe

#include "headers.h"


class PTPSoCTestJigInterface2 : public QWidget
{
    Q_OBJECT

public:
    PTPSoCTestJigInterface2(QWidget *parent = 0);
    ~PTPSoCTestJigInterface2();

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

    IQmaxLineEdit *ILineEdit;
    IQmaxNumberPanel *INumberPanel;
    QLineEdit *MuxTestLineEdit,*MuxRefLineEdit,*CommandLineEdit;

        unsigned int source_impedance;
	short int m_nLineEditIndex;
    unsigned char function;
	unsigned int byte1[8],byte2[8],byte3[8],byte4[8];
	unsigned int already1,already2,already3,already4;
	int m_nGPIOCode;



private slots:
        void on_switchFLY_clicked();
        void on_switchSRCIMP_clicked();
        void on_comboBox_10_currentIndexChanged(int index);
        void EnDisSRCIM(bool);

        void TestButton();
        void SwitchMux();
        void ReadCodeID();
        void ReadRelays();
        void ResetRelays();
        void SendCommand();

        void Multimeter();
        void Oscilloscope();
        void FunctionGenerator();
        void ShortLocator();
        void InCircuitMeasurement();
        void VoltageCurrent();

        void Voltage(int);
        void R2Wire(int);
        void R4Wire(int);
        void Current(int);
        void Oscilloscope1(int);
        void Oscilloscope2(int);
        void FunctionGenerater(int);
        void ShortLocater(int);
        void InCircuitMeasureMent(int);
        void VoltageCurrent1(int);
        void VoltageCurrent2(int);
        void MuxInputs(int);

        void callMuxTestInput();
        void callMuxRefInput();
        void callCommandInput();
        void EmbeddedKey();
        void CommandSelection(int);

        void psocError(bool);

    	void receiveValue(unsigned int);
    	void receiveValue(double);
    	void receiveValue(QString);
};

#endif // PTPSOCTESTJIGINTERFACE2_H
