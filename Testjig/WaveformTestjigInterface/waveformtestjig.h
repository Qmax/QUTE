#ifndef WAVEFORMTESTJIG_H
#define WAVEFORMTESTJIG_H

#include<QObject>
#include<QtCore>
#include "Waveformclass.h"
#include "WaveformTestjigInterface.h"

class InterfaceWaveformClass:public QObject,public IQmaxWaveProduct
{
    Q_OBJECT
    Q_INTERFACES(IQmaxWaveProduct)

public:
    void ICreateWaveProduct(QString,QWidget*);
    void IsetDimensions(int,int,int,int);
    void ILoadPlotterData(QString,stWaveData *);
    void IGenerateOscillatorPattern(QString ,short int);
    void IWaveSettings();
    void IsetGainFactor(double);
protected:
    createProduct *objCreateProduct;
};

#endif // WAVEFORMTESTJIG_H
