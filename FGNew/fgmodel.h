#ifndef FGMODEL_H
#define FGMODEL_H

#include <QObject>
#include "Waveformclass.h"


struct Drive2Data
{
    unsigned short m_nBTUR;
    unsigned short m_nBDR;
    unsigned short m_nDriveCount;
};



class FG_INTERACTIVE_DATA
{
public:
    Drive2Data* m_objDriveData;
    stWaveData *m_objWaveData;

    FG_INTERACTIVE_DATA()
    {
        m_objDriveData = new Drive2Data();
        m_objWaveData = new stWaveData();
        m_nFrequency =0.0;
        m_nPeriod=0.0;
        m_nHLevel=0.0;
        m_nLLevel=0.0;
        m_nPhase=0.0;
        m_nDuty=0.0;
        m_nDelay=0.0;
        m_nDutycycle=50.0;
        m_nAmplitude=0.0;
        m_nSymmetry=0.0;
        m_nMean=0.0;
        m_nVariance=0.0;
        m_nOffset=0.0;
        m_nPulseWidth=0.0;
        m_bClamp =false;
        m_bACorDC = true;
        m_bVIS = true;
        m_nIRS = 0;
        m_nGainSelect=0;
        m_nSourceImpedance=0;
        m_nDisplayVoltage=0.0;
        m_nDisplayFreq=0.0;
    }
    ~FG_INTERACTIVE_DATA()
    {
        delete m_objDriveData;
        delete m_objWaveData;
    }
    double m_nFrequency;
    double m_nPeriod;
    double m_nHLevel;
    double m_nLLevel;
    double m_nOffset;
    double m_nPhase;
    double m_nDutycycle;
    double m_nSymmetry;
    double m_nAmplitude;
    double m_nDuty;
    double m_nDelay;
    double m_nVariance;
    double m_nMean;
    double m_nPulseWidth;
    double m_nDisplayVoltage;
    double m_nDisplayFreq;
    bool m_bClamp;
    bool m_bACorDC;
    bool m_bVIS;
    short int m_nIRS;
    short int m_nGainSelect;
    short int m_nSourceImpedance;

};
Q_DECLARE_METATYPE(FG_INTERACTIVE_DATA*)


//struct FGParams
//{
//    double m_nFrequency;
//    double m_nPeriod;
//    double m_nHLevel;
//    double m_nLLevel;
//    double m_nOffset;
//    double m_nPhase;
//    double m_nDutycycle;
//    double m_nSymmetry;
//    double m_nAmplitude;
//    double m_nDuty;
//    double m_nDelay;
//    double m_nVariance;
//    double m_nMean;
//
//};



class FGModel;
class Observer
{
public:
    virtual void call(FGModel* s,const int obs_str) = 0;
    virtual ~Observer() {};
};

class FGModel
{

public:
    explicit FGModel(QObject *parent = 0);
    stWaveData* showVITrace(int pWaveTrace);
    void setWaveData(stWaveData*);
    stWaveData* getWaveData();
    void setDriveData(Drive2Data*);
    Drive2Data* getDriveData();
    //Q_PROPERTY(double value READ GetFrequency WRITE setFrequency);
    double getFrequency();
    void setFrequency(double);
    double getAmplitude();
    void setAmplitude(double);
    double getOffset();
    void setOffset(double);
    double getHlevel();
    void setHlevel(double);
    double getLlevel();
    void setLlevel(double);
    double getDutyCycle();
    void setDutyCycle(double);
    double getDuty();
    void setDuty(double);
    double getSymmetry();
    void setSymmetry(double);
    double getDelay();
    void setDelay(double);
    double getVariance();
    void setVariance(double);
    double getMean();
    void setMean(double);
    double getPeriod();
    void setPeriod(double);
    double getPhase();
    void setPhase(double);
    double getPulseWidth();
    void setPulseWidth(double);
    bool getClamp(){ return FGData->m_bClamp;}
    bool getACorDC(){ return FGData->m_bACorDC;}
    bool getVIS(){ return FGData->m_bVIS;}
    short int getIRS(){ return FGData->m_nIRS;}
    short int getGainSelect(){ return FGData->m_nGainSelect;}
    short int getSourceImpedance(){return FGData->m_nSourceImpedance;}
    void setGainSelect(short int pValue){FGData->m_nGainSelect =pValue;}
    double getDisplayVoltage();
    void setDisplayVoltage(double);
    double getDisplayFrequency(){ return FGData->m_nDisplayFreq;}
    void setDisplayFrequency(double pValue) { FGData->m_nDisplayFreq = pValue;}



    //void register_observer(Observer *ob);
    //void init(const int obs_str);
    //std::vector<Observer*> observers;
protected:
    FG_INTERACTIVE_DATA *FGData;
signals:

public slots:

};


//
//class DSO_SUBJECT_CLASS
//{
//
//public:
//    DSO_SUBJECT_CLASS(QWidget *parent = 0);
//    ~DSO_SUBJECT_CLASS();
//    void init(const int obs_str);
//
//    void register_observer(Observer *o);
//    std::vector<Observer*> observers;
//    struct subject_data *obj_for_subject_data;
//};







#endif // FGMODEL_H
