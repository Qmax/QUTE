#ifndef WAVEDATA_H
#define WAVEDATA_H

#include <QDialog>
#include <QDebug>
#include <QLineEdit>
#include <QPluginLoader>
#include "InterfacePTLibrary.h"

namespace Ui {
    class WaveData;
}
class WaveData : public QDialog {
    Q_OBJECT
public:
    WaveData(short waveNumber,QWidget *parent = 0);
    ~WaveData();

protected:
    void changeEvent(QEvent *e);
    void openNumKBPanel(short int);
    void openNumKBPanelminmax(short int pValue, double pMax, double pMin);

    IQmaxLineEdit *ILineEdit;
    IQmaxNumberPanel *INumberPanel;

    QLineEdit *m_objSamples,*m_objStartTick,*m_objStoptick,*m_objDutyCycle;

    int m_nWaveNumber,m_nTotalSamples,m_nSamples,m_nStartTick,m_nStoptick,m_nDutyCycle;
    short int m_nLineEditIndex;

private:
    Ui::WaveData *ui;
signals:
    void SendSamples(int);
    void SendStartTick(int);
    void SendStopTick(int);
    void SendDutyCycle(int);

private slots:
    void on_pb_Cancel_clicked();
    void on_pb_Ok_clicked();

    void receiveValue(unsigned int);
    void receiveValue(double);
    void receiveValue(QString);

    void callSamplesEdit();
    void callStartTickEdit();
    void callStopTickEdit();
    void callDutyCylceEdit();

    void RxTotalSamples(int);
};

#endif // WAVEDATA_H
