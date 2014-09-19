#include "fgmodel.h"

FGModel::FGModel(QObject *parent)
{
    Q_UNUSED(parent);
      FGData = new FG_INTERACTIVE_DATA();
}

void FGModel::setWaveData(stWaveData *pObjData)
{
    FGData->m_objWaveData = pObjData;
}

void FGModel::setDriveData(Drive2Data *pObjDriveData)
{
    FGData->m_objDriveData = pObjDriveData;
}

Drive2Data* FGModel::getDriveData()
{
    return FGData->m_objDriveData;
}

stWaveData* FGModel::getWaveData()
{
    return FGData->m_objWaveData;
}


void FGModel::setAmplitude(double pData){ FGData->m_nAmplitude = pData;}
void FGModel::setDelay(double pData){FGData->m_nDelay=pData;}
void FGModel::setDuty(double pData){FGData->m_nDuty=pData;}
void FGModel::setDutyCycle(double pData){FGData->m_nDutycycle= pData;}
void FGModel::setFrequency(double pData){FGData->m_nFrequency=pData;}
void FGModel::setHlevel(double pData){FGData->m_nHLevel=pData;}
void FGModel::setLlevel(double pData){FGData->m_nLLevel=pData;}
void FGModel::setMean(double pData){FGData->m_nMean=pData;}
void FGModel::setOffset(double pData){FGData->m_nOffset=pData;}
void FGModel::setPeriod(double pData){FGData->m_nPeriod=pData;}
void FGModel::setPhase(double pData){FGData->m_nPhase=pData;}
void FGModel::setSymmetry(double pData){FGData->m_nSymmetry=pData;}
void FGModel::setVariance(double pData){FGData->m_nVariance=pData;}
void FGModel::setPulseWidth(double pData) {FGData->m_nPulseWidth=pData;}
void FGModel::setDisplayVoltage(double pData){FGData->m_nDisplayVoltage = pData;}




double FGModel::getAmplitude(){return FGData->m_nAmplitude;}
double FGModel::getDelay(){    return FGData->m_nDelay;}
double FGModel::getDuty(){    return FGData->m_nDuty;}
double FGModel::getDutyCycle(){    return FGData->m_nDutycycle;}
double FGModel::getFrequency(){    return FGData->m_nFrequency;}
double FGModel::getHlevel(){    return FGData->m_nHLevel;}
double FGModel::getLlevel(){    return FGData->m_nLLevel;}
double FGModel::getPeriod(){    return FGData->m_nPeriod;}
double FGModel::getOffset(){    return FGData->m_nOffset;}
double FGModel::getMean(){    return FGData->m_nMean;}
double FGModel::getPhase(){    return FGData->m_nPhase;}
double FGModel::getVariance(){    return FGData->m_nVariance;}
double FGModel::getSymmetry(){    return FGData->m_nSymmetry;}
double FGModel::getPulseWidth() { return FGData->m_nPulseWidth;}
double FGModel::getDisplayVoltage() {return FGData->m_nDisplayVoltage;}


stWaveData* FGModel::showVITrace(int pWaveTrace)
{

    if(pWaveTrace==1)
    {
        FGData->m_objWaveData->m_nAmplitude = 0.6;
        FGData->m_objWaveData->m_nFrequency = 1.0;
        FGData->m_objWaveData->m_nSteps= 0;
        FGData->m_objWaveData->m_nSamples = 1000;
        FGData->m_objWaveData->m_nScreenAmplitude = 1.0;
        FGData->m_objWaveData->m_nTimeperSample = 0.01;
        FGData->m_objWaveData->m_nScreenTime = 1.0;
        FGData->m_objWaveData->m_nXunits = 10.0;
        FGData->m_objWaveData->m_nYunits = 8.0;
        FGData->m_objWaveData->m_nMinX =0.0;
        FGData->m_objWaveData->m_nMinY =-1.0;
        FGData->m_objWaveData->m_nPhase =0.0;
        FGData->m_objWaveData->m_nOffset =0.0;
        FGData->m_objWaveData->m_nDutyCycles =0.0;
        FGData->m_objWaveData->m_nCycles = 1.0;
        FGData->m_objWaveData->m_nPreamble =0;
        FGData->m_objWaveData->m_nPostamble=0;
        FGData->m_objWaveData->m_bUniPolar = false;
        FGData->m_objWaveData->m_nSteps =0.0;
        FGData->m_objWaveData->m_nVRef =0.6;
        FGData->m_objWaveData->m_bCalibChecked = false;
        FGData->m_objWaveData->m_nCalibrationConstant =0.0;
        FGData->m_objWaveData->m_nCalibrationGain=0.0;
        FGData->m_objWaveData->m_nResolution =14;
        return FGData->m_objWaveData;
    }
    return 0;
}


//void FGModel::init(const int obs_str)
//{
//    std::vector<Observer*>::iterator iter;
//
//        {
//            iter = observers.begin();
//            (*iter)->call(this,obs_str);
//        }
//}
//void FGModel::register_observer(Observer *o)
//{
//    observers.push_back(o);
//}


