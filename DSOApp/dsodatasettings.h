#ifndef DSODATASETTINGS_H
#define DSODATASETTINGS_H

#include<QDebug>
#include "DSOCommon.h"



class DSODataSettings
{
public:
    DSODataSettings();
public:
    double m_nCH1TimePerDivision,m_nCH2TimePerDivision;
    double m_nCH1VoltPerDivision,m_nCH2VoltPerDivsion;
    double m_nAcquisitionTime;
    double m_nAcutalRecordLength,m_nMaxRecordLength;
    unsigned short m_nRecordIndex;
    unsigned int m_nSampleRate;
    unsigned int m_nCH1FPAtteunationFactor,m_nCH2FPAtteunationFactor;
    double m_nCH1FSSettings,m_nCH2FSSettings;
    unsigned int m_nSamplesCount;
    double m_nMinPoint,m_nMaxPoint,m_nAveragePoint;


    void setFPAtteunationFactor(unsigned int pValue,BASEWIDGET pChannel);
    unsigned short getFPAtteunationFactor(BASEWIDGET pChannel);
    void setFSSettings(double pFSSetting,BASEWIDGET pChannel);
    void setTimePerDivision(double pTimePerDiv,TIMEUNIT pTUnits,BASEWIDGET pChannel);
    void setMaximumSampleRate(unsigned short pSampleRate,SAMPLEUNIT pSampleUnit);
    unsigned int getMaximumSampleRate();
    void setVoltPerDivision(double pVoltPerDiv,BASEWIDGET pChannel);
    void calculateAcquisitionTime(BASEWIDGET pChannel);
    unsigned int setSamplesCount(unsigned int pPreSampleCount,unsigned int pPostSampleCount,SAMPLING_TYPE pSampleType);
    SAMPLING_TYPE getSampleType() const;
    unsigned int getSamplesCount(BASEWIDGET pChannel);
    double calculateRecordLength();
    double getVoltPerDivsion(BASEWIDGET pChannel);
    double getTimePerDivision(BASEWIDGET pChannel);
    double calculateSampleRate();
    void setMaxRecordLength(unsigned int pMaxRecordLength,short int pMaxIndex);
    void validateSampleRate(unsigned short pIndex);
    double getFSSettings(BASEWIDGET pChannel);
    void setSamplingType(SAMPLING_TYPE pType);
    SAMPLING_TYPE m_eSamplesType;

};

#endif // DSODATASETTINGS_H
