#ifndef VIJIG_H
#define VIJIG_H

#include <QWidget>
#include <qlineedit.h>
#include "qpluginloader.h"
#include "InterfacePTLibrary.h"
#include <QtCore>
#include <QObject>
#include "WaveformTestjigInterface.h"
//#include "VITestJigInterface.h"

namespace Ui {
    class VIJig;
}

class VIJig : public QWidget{//,public IVITestJigInterface  {
    Q_OBJECT
//    Q_INTERFACES(IVITestJigInterface)
public:
    VIJig(QWidget *parent = 0);
    ~VIJig();

//    void setVI(QWidget* parent){
//     	VIJig* obj=new VIJig(parent);
//     	qDebug()<<"VI GUI INIT";
//     	obj->show();
//     }

//    void HardwareInitializtaion();

    void Initialization();
    void enableRichGUI();
    void GenerateWaveform();
    stWaveData* showVITrace(int pWaveTrace);
	short int m_nLineEditIndex;


    QLineEdit *objAddress,*objData,*objOffset,*objFrequency;

protected:
    void changeEvent(QEvent *e);
    IQmaxLineEdit *ILineEdit;
    IQmaxNumberPanel *INumberPanel;
    IQmaxWaveProduct *objWaveProduct;
        stWaveData *l_objReceive1Data,*m_objWaveData;
        void openNumKBPanel(short int);
    void openNumKBPanel(short int,double,char,double,double,QWidget*);

private:
    Ui::VIJig *ui;

private slots:
	void receiveValue(unsigned int);
	void receiveValue(double);
	void receiveValue(QString);

	void callAddressEdit();
	void callDataEdit();
	void callOffsetEdit();
	void callFrequencyEdit();
};

#endif // VIJIG_H
