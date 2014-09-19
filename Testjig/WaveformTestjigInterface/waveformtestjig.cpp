#include "waveformtestjig.h"

void InterfaceWaveformClass::ICreateWaveProduct(QString function,QWidget* parent){
	objCreateProduct=new createProduct();
	objCreateProduct->CreateWaveProduct(function,parent);
}


void InterfaceWaveformClass::ILoadPlotterData(QString pStrFileName,stWaveData *pObjWaveData){
	objCreateProduct->LoadPlotterData(pStrFileName,pObjWaveData);
}

void InterfaceWaveformClass::IGenerateOscillatorPattern(QString pStrPatternselected,short int value){
	objCreateProduct->GenerateOscillatorPattern(pStrPatternselected,value);
}
void InterfaceWaveformClass::IsetDimensions(int x,int y,int w,int h){
	objCreateProduct->SetDimensions(x,y,w,h);
}
void InterfaceWaveformClass::IWaveSettings(){
	objCreateProduct->WaveSettings();
}

void InterfaceWaveformClass::IsetGainFactor(double value){
	objCreateProduct->setGainFactor(value);
}



Q_EXPORT_PLUGIN2(IQmaxWaveProduct, InterfaceWaveformClass)

