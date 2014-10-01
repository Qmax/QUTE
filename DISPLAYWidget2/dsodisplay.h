#ifndef DSODISPLAY_H
#define DSODISPLAY_H

#include <QWidget>
#include "dsoxygridview.h"
#include "DisplayWidgetInterface.h"

namespace Ui {
    class DSODisplay;
}

class DSODisplay : public QWidget{
    Q_OBJECT
public:
    DSODisplay(QWidget *parent = 0);
    ~DSODisplay();

    DSOXYGridModel *m_objXYModel;
    DSOXYGridView *m_objXYView;
    void initializeWaveDisplay(int x,int y,int w,int h);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
protected:

    void changeEvent(QEvent *e);
    bool evenFilter(QObject *target,QEvent *e);

private:
    Ui::DSODisplay *ui;
};

class DSODisplayInterface : public QObject,public DisplayWidgetInterface {
    Q_OBJECT
    Q_INTERFACES(DisplayWidgetInterface)
public:
            DSODisplayInterface();
            ~DSODisplayInterface();
            QWidget* getDisplayWidget();
            void initializeWaveDisplay(QRect obj);
            void moveVertical1Cursors(double);
            void moveVertical2Cursor(double);
            void moveHorizontal1Cursors(double);
            void moveHorizontal2Cursors(double);
            void moveVerticalTriggerPointer(double);
            void moveHorizontalTriggerPointer(double);
            void moveOffsetPointer(double);
            void setBorderGeometry(int,int,int,int);
            void hideVerticalCursors(short int,bool);
            void hideHorizontalCursors(short int,bool);
            void setVectorData();
            void clearVectorData();
            void setCH1VectorData(QMap<int,QList<double> > pData);
            void setCH2VectorData(QMap<int,QList<double> > pData);
            void setCH3VectorData(QMap<int,QList<double> > pData);
            void setCH4VectorData(QMap<int,QList<double> > pData);
            void setChannelVectData(QMap<int,QList<double> > pData,bool,bool,DSO_CHANNEL);
            void moveChannelOffset(DSO_CHANNEL,double);

            void LoadFIFOData(double,double,bool,bool);
            double convertFIFOData(QString);
            void initialiseWaveSettings();
            void LoadChannel1Data(double pVoltTrigger,double pHorizontalTrigger);
            void LoadOddEvenData(double pVoltageTrigger,double pHorizontalTrigger,bool bODDData,bool bEvenData,DSO_CHANNEL pChannel,unsigned int,unsigned int );
            void HideDSOChannel(DSO_CHANNEL,bool);
            void convertToInterPolatePoints();
            void convertToDecimation();
            void findMinMax(QList<double>);
            void calculateAveragePoints(QList<double>);


            void setFPAtteunationFactor(unsigned int pValue,DSO_CHANNEL pChannel)
            {
            	if(pChannel == CHANNEL1 || pChannel == CHANNEL2)
            		m_nCH1FPAtteunationFactor = pValue;
            	else if(pChannel == CHANNEL3 || pChannel == CHANNEL4)
            		m_nCH2FPAtteunationFactor = pValue;
            }
            unsigned short getFPAtteunationFactor(DSO_CHANNEL pChannel)
            {
            	if(pChannel == CHANNEL1 || pChannel == CHANNEL2)
            		return m_nCH1FPAtteunationFactor;
            	else if(pChannel == CHANNEL3 || pChannel == CHANNEL4)
            		return m_nCH2FPAtteunationFactor;

            }
            void setFSSettings(double pFSSetting,DSO_CHANNEL pChannel)
            {
            	if(pChannel == CHANNEL1 || pChannel == CHANNEL2)
            		m_nCH1FSSettings = pFSSetting;
            	else if(pChannel == CHANNEL3 || pChannel == CHANNEL4)
            		m_nCH2FSSettings = pFSSetting;
            }
            void setTimePerDivision(double pTimePerDiv,TIMEUNIT pTUnits,DSO_CHANNEL pChannel)
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
                if(pChannel == CHANNEL1 || pChannel == CHANNEL2)
                	m_nCH1TimePerDivision = pTimePerDiv * l_nUnitFactor;
                else if(pChannel == CHANNEL3 || pChannel == CHANNEL4)
                	m_nCH2TimePerDivision = pTimePerDiv * l_nUnitFactor;
                qDebug()<< "TimeScale:"<<m_nCH1TimePerDivision<<m_nCH2TimePerDivision;
            }
            void setMaximumSampleRate(unsigned short pSampleRate,SAMPLEUNIT pSampleUnit)
            {
                if(pSampleUnit == MEGAS)
                    m_nSampleRate = pSampleRate * 1000000;
                else if(pSampleUnit == KILOS)
                    m_nSampleRate = pSampleRate * 1000;
                else if(pSampleUnit == ONES)
                    m_nSampleRate = pSampleRate * 1;

             //   qDebug() << "Maximum Sample Rate:"<<m_nSampleRate;
            }

            unsigned int getMaximumSampleRate()
            {
            	return m_nSampleRate;
            }

            void setVoltPerDivision(double pVoltPerDiv,DSO_CHANNEL pChannel)
            {
            	if(pChannel == CHANNEL1 || pChannel == CHANNEL2)
            		m_nCH1VoltPerDivision = pVoltPerDiv;
            	else if(pChannel == CHANNEL3 || pChannel == CHANNEL4)
            		m_nCH2VoltPerDivsion = pVoltPerDiv;
            }
            void calculateAcquisitionTime(DSO_CHANNEL pChannel)
            {
            	if(pChannel == CHANNEL1 || pChannel == CHANNEL2)
            		m_nAcquisitionTime = (m_nCH1TimePerDivision) *10.0;//(Horizontal Divisions);
            	else if(pChannel == CHANNEL3 || pChannel == CHANNEL4)
            		m_nAcquisitionTime = (m_nCH2TimePerDivision) *10.0;//(Horizontal Divisions);
            //    qDebug()<<"Acquisition Time:"<<m_nAcquisitionTime;
            }

            unsigned int setSamplesCount(unsigned int pPreSampleCount,unsigned int pPostSampleCount,SAMPLING_TYPE pSampleType)
            {
            	m_nSamplesCount = pPreSampleCount+pPostSampleCount;
            	m_eSamplesType = pSampleType;
            	return m_nSamplesCount;
            }

            SAMPLING_TYPE getSampleType() const
            {
            	return m_eSamplesType;
            }
            unsigned int getSamplesCount(DSO_CHANNEL pChannel)
            {
            	if(pChannel == CHANNEL1 || pChannel == CHANNEL2)
            		return m_nSamplesCount;
            	else if(pChannel == CHANNEL3 || pChannel == CHANNEL4)
            		return m_nSamplesCount;

            }

            double calculateRecordLength()
            {

            		m_nAcutalRecordLength = m_nSampleRate * m_nAcquisitionTime;
              //  qDebug()<<"Record Length:"<<m_nAcutalRecordLength;
                return m_nAcutalRecordLength;
            }

            double getRectWidth()
            {
                return m_objDSODisplay->m_objXYView->getRectWidth();
            }

            double getRectHeight()
            {
                return m_objDSODisplay->m_objXYView->getRectHeight();
            }

            double getVoltPerDivsion(DSO_CHANNEL pChannel)
            {
            	if(pChannel == CHANNEL1 || pChannel == CHANNEL2)
            		return m_nCH1VoltPerDivision;
            	else if(pChannel == CHANNEL3 || pChannel == CHANNEL4)
            		return m_nCH2VoltPerDivsion;
            }

            double getTimePerDivision(DSO_CHANNEL pChannel)
            {
            	if(pChannel == CHANNEL1 || pChannel == CHANNEL2)
            		return m_nCH1TimePerDivision;
            	else if(pChannel == CHANNEL3 || pChannel == CHANNEL4)
            		return m_nCH2TimePerDivision;
            }

            double calculateSampleRate()
            {
                double l_nSampleRate = m_nMaxRecordLength / m_nAcquisitionTime;
                return l_nSampleRate;
            }

            void setMaxRecordLength(unsigned int pMaxRecordLength,short int pMaxIndex)
            {
                m_nMaxRecordLength = pMaxRecordLength;
                m_nRecordIndex = pMaxIndex;
            }

            void validateSampleRate(unsigned short pIndex)
            {
//                if(m_nAcutalRecordLength > m_nMaxRecordLength)
//                    m_nSampleRate =m_nArrSampleRate[m_nRecordIndex-1];
//                else
//                    return;
            }

            double getFSSettings(DSO_CHANNEL pChannel)
            {
            	if(pChannel == CHANNEL1 || pChannel == CHANNEL2)
            		return m_nCH1FSSettings;
            	else if(pChannel == CHANNEL3 || pChannel == CHANNEL4)
            		return m_nCH2FSSettings;
            }

protected:
        DSODisplay *m_objDSODisplay;
        QVector<QPointF> m_objCH1Data;
        QVector<QPointF> m_objCH2Data;
        QVector<QPointF> m_objCH3Data;
        QVector<QPointF> m_objCH4Data;
        QMap<int,QList<double> > m_objChannel1Data;
        QMap<int,QList<double> > m_objChannel2Data;
        QMap<int,QList<double> > m_objChannel3Data;
        QMap<int,QList<double> > m_objChannel4Data;

      //  unsigned short m_nArrSampleRate[4];
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

        SAMPLING_TYPE m_eSamplesType;
        DSOXYGridModel *m_objXYModel;
        DSOXYGridView *m_objXYView;



};

#endif // DSODISPLAY_H
