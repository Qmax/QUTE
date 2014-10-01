#ifndef DISPLAYWIDGETINTERFACE_H
#define DISPLAYWIDGETINTERFACE_H
#include <QObject>
#include <QVector>
#include<QPointF>

enum TIMEUNIT{NANOSECONDS,MICROSECONDS,MILLISECONDS,SECONDS};
enum SAMPLEUNIT{MEGAS,KILOS,ONES};
enum SAMPLING_TYPE{NORMAL=0,MIN_MAX,AVERAGE,MOVING_AVERAGE,LINEAR_INTERPOLATION,MOVING_LINEAR,WAVEFORM_MEMORY};
enum DSO_CHANNEL{CHANNEL1,CHANNEL2,CHANNEL3,CHANNEL4};
#include <QRectF>
class DisplayWidgetInterface{
public:
    virtual QWidget* getDisplayWidget()=0;
    virtual void initializeWaveDisplay(QRect)=0;
    virtual void moveVertical1Cursors(int)=0;
    virtual void moveVertical2Cursor(int)=0;
    virtual void moveHorizontal1Cursors(int)=0;
    virtual void moveHorizontal2Cursors(int)=0;
    virtual void moveVerticalTriggerPointer(double)=0;
    virtual void moveHorizontalTriggerPointer(double)=0;
    virtual void moveOffsetPointer(double)=0;
    virtual void setBorderGeometry(int,int,int,int)=0;
    virtual double getRectWidth()=0;
    virtual double getRectHeight()=0;
    virtual void hideVerticalCursors(short int,bool)=0;
    virtual void hideHorizontalCursors(short int,bool)=0;
    virtual void LoadFIFOData(double,double,bool,bool)=0;
    virtual void LoadOddEvenData(double pVoltageTrigger,double pHorizontalTrigger,bool bODDData,bool bEvenData,DSO_CHANNEL,unsigned int,unsigned int) =0;
    virtual void initialiseWaveSettings()=0;
    virtual void setVectorData()=0;
    virtual void clearVectorData()=0;
    virtual void setCH1VectorData(QMap<int,QList<double> > pData)=0;
    virtual void setCH2VectorData(QMap<int,QList<double> > pData)=0;
    virtual void setCH3VectorData(QMap<int,QList<double> > pData)=0;
    virtual void setCH4VectorData(QMap<int,QList<double> > pData)=0;
    virtual void setChannelVectData(QMap<int,QList<double> > pData,bool,bool,DSO_CHANNEL)=0;

    virtual void setTimePerDivision(double pTimePerDiv,TIMEUNIT pTUnits,DSO_CHANNEL)=0;
    virtual void setMaxRecordLength(unsigned int pMaxRecordLength,short int pMaxIndex)=0;
    virtual void setMaximumSampleRate(unsigned short pSampleRate,SAMPLEUNIT)=0;
    virtual void setVoltPerDivision(double pVoltPerDiv,DSO_CHANNEL)=0;
    virtual double getVoltPerDivsion(DSO_CHANNEL)=0;
    virtual double getTimePerDivision(DSO_CHANNEL)=0;
    virtual void calculateAcquisitionTime(DSO_CHANNEL)=0;
    virtual double calculateRecordLength()=0;
    virtual double calculateSampleRate()=0;
    virtual unsigned int getMaximumSampleRate()=0;
    virtual void moveChannelOffset(DSO_CHANNEL,double)=0;
    virtual void HideDSOChannel(DSO_CHANNEL,bool)=0;
    virtual void setFPAtteunationFactor(unsigned int,DSO_CHANNEL )=0;
    virtual unsigned short getFPAtteunationFactor(DSO_CHANNEL)=0;
    virtual void setFSSettings(double,DSO_CHANNEL)=0;
    virtual double getFSSettings(DSO_CHANNEL)=0;
    virtual unsigned int setSamplesCount(unsigned int,unsigned int,SAMPLING_TYPE)=0;
    virtual void LoadChannel1Data(double pVoltTrigger,double pHorizontalTrigger)=0;

};
Q_DECLARE_INTERFACE(DisplayWidgetInterface,"pt.displaywidgetInterface/1.0.0.1");

#endif // DISPLAYWIDGETINTERFACE_H
