#ifndef WAVEFORMTESTJIGINTERFACE_H
#define WAVEFORMTESTJIGINTERFACE_H

#include<QObject>

class IQmaxWaveProduct
{
public:
	virtual void ICreateWaveProduct(QString,QWidget*)=0;
	virtual void IsetDimensions(int,int,int,int)=0;
    virtual void ILoadPlotterData(QString,stWaveData*)=0;
    virtual void IGenerateOscillatorPattern(QString,short int)=0;
    virtual void IWaveSettings()=0;
    virtual void IsetGainFactor(double)=0;
};

QT_BEGIN_NAMESPACE
Q_DECLARE_INTERFACE(IQmaxWaveProduct,"pt.waveproduct/1.0.0.1");
QT_END_NAMESPACE

#endif // WAVEFORMTESTJIGINTERFACE_H
