#include "dsodatasettings.h"


DSODataSettings::DSODataSettings()
{
}
void DSODataSettings::setFPAtteunationFactor(unsigned int pValue,BASEWIDGET pChannel)
{
	if(pChannel == CHANNEL_1)
            m_nCH1FPAtteunationFactor = pValue;
	else if(pChannel == CHANNEL_2);
            m_nCH2FPAtteunationFactor = pValue;
}
unsigned short DSODataSettings::getFPAtteunationFactor(BASEWIDGET pChannel)
{
    if(pChannel == CHANNEL_1)
            return m_nCH1FPAtteunationFactor;
    else if(pChannel == CHANNEL_2);
            return m_nCH2FPAtteunationFactor;

}
void DSODataSettings::setFSSettings(double pFSSetting,BASEWIDGET pChannel)
{
	if(pChannel == CHANNEL_1)
            m_nCH1FSSettings = pFSSetting;
    else if(pChannel == CHANNEL_2);
            m_nCH2FSSettings = pFSSetting;
}
void DSODataSettings::setTimePerDivision(double pTimePerDiv,TIMEUNIT pTUnits,BASEWIDGET pChannel)
{
    qDebug()<<"Time Value:"<<pTimePerDiv<<"Unit:"<<pTUnits;
    double  l_nUnitFactor=0.0;
    if(pTUnits == NANOSECONDS)
        l_nUnitFactor = 1 / 1000000000.0;
    else if(pTUnits == MICROSECONDS)
        l_nUnitFactor = 1 / 1000000.0;
    else if(pTUnits == MILLISECONDS)
        l_nUnitFactor = 1 / 1000.0;
    else if(pTUnits == SECONDS)
        l_nUnitFactor = 1.0;
    if(pChannel == CHANNEL_1)
            m_nCH1TimePerDivision = pTimePerDiv * l_nUnitFactor;
    else if(pChannel == CHANNEL_2)
            m_nCH2TimePerDivision = pTimePerDiv * l_nUnitFactor;
    qDebug()<< "TimeScale:"<<m_nCH1TimePerDivision<<m_nCH2TimePerDivision;
}
void DSODataSettings::setMaximumSampleRate(unsigned short pSampleRate,SAMPLEUNIT pSampleUnit)
{
    if(pSampleUnit == MEGAS)
        m_nSampleRate = pSampleRate * 1000000;
    else if(pSampleUnit == KILOS)
        m_nSampleRate = pSampleRate * 1000;
    else if(pSampleUnit == ONES)
        m_nSampleRate = pSampleRate * 1;

 //   qDebug() << "Maximum Sample Rate:"<<m_nSampleRate;
}

unsigned int DSODataSettings::getMaximumSampleRate()
{
    return m_nSampleRate;
}

void DSODataSettings::setVoltPerDivision(double pVoltPerDiv,BASEWIDGET pChannel)
{
    if(pChannel == CHANNEL_1 )
            m_nCH1VoltPerDivision = pVoltPerDiv;
    else if(pChannel == CHANNEL_2)
            m_nCH2VoltPerDivsion = pVoltPerDiv;
}
void DSODataSettings::calculateAcquisitionTime(BASEWIDGET pChannel)
{
    if(pChannel == CHANNEL_1 )
            m_nAcquisitionTime = (m_nCH1TimePerDivision) *10.0;//(Horizontal Divisions);
    else if(pChannel == CHANNEL_2)
            m_nAcquisitionTime = (m_nCH2TimePerDivision) *10.0;//(Horizontal Divisions);
//    qDebug()<<"Acquisition Time:"<<m_nAcquisitionTime;
}

unsigned int DSODataSettings::setSamplesCount(unsigned int pPreSampleCount,unsigned int pPostSampleCount,SAMPLING_TYPE pSampleType)
{
    m_nSamplesCount = pPreSampleCount+pPostSampleCount;
    m_eSamplesType = pSampleType;
    return m_nSamplesCount;
}

SAMPLING_TYPE DSODataSettings::getSampleType() const
{
    return m_eSamplesType;
}
unsigned int DSODataSettings:: getSamplesCount(BASEWIDGET pChannel)
{
    if(pChannel == CHANNEL_1)
            return m_nSamplesCount;
    else if(pChannel == CHANNEL_2)
            return m_nSamplesCount;

}

double DSODataSettings::calculateRecordLength()
{

            m_nAcutalRecordLength = m_nSampleRate * m_nAcquisitionTime;
  //  qDebug()<<"Record Length:"<<m_nAcutalRecordLength;
    return m_nAcutalRecordLength;
}

double DSODataSettings::getVoltPerDivsion(BASEWIDGET pChannel)
{
    if(pChannel == CHANNEL_1)
            return m_nCH1VoltPerDivision;
    else if(pChannel == CHANNEL_2)
            return m_nCH2VoltPerDivsion;
}

double DSODataSettings::getTimePerDivision(BASEWIDGET pChannel)
{
	if(pChannel == CHANNEL_1)
            return m_nCH1TimePerDivision;
	   else if(pChannel == CHANNEL_2)
            return m_nCH2TimePerDivision;
}

double DSODataSettings::calculateSampleRate()
{
    double l_nSampleRate = m_nMaxRecordLength / m_nAcquisitionTime;
    return l_nSampleRate;
}

void DSODataSettings::setMaxRecordLength(unsigned int pMaxRecordLength,short int pMaxIndex)
{
    m_nMaxRecordLength = pMaxRecordLength;
    m_nRecordIndex = pMaxIndex;
}

void DSODataSettings::validateSampleRate(unsigned short pIndex)
{
//                if(m_nAcutalRecordLength > m_nMaxRecordLength)
//                    m_nSampleRate =m_nArrSampleRate[m_nRecordIndex-1];
//                else
//                    return;
}

void DSODataSettings::setSamplingType(SAMPLING_TYPE pType)
{
	m_eSamplesType = pType;
}
double DSODataSettings::getFSSettings(BASEWIDGET pChannel)
{
    if(pChannel == CHANNEL1 || pChannel == CHANNEL2)
            return m_nCH1FSSettings;
    else if(pChannel == CHANNEL3 || pChannel == CHANNEL4)
            return m_nCH2FSSettings;
}
