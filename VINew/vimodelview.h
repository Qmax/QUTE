#ifndef VIMODELVIEW_H
#define VIMODELVIEW_H


#include <vidataclas.h>
#include <qstringlist.h>
#include <QFile>
class VIModelView
{
public:
    VIModelView();
};

//struct Drive2Data
//{
//    unsigned short m_nBTUR;
//    unsigned short m_nBDR;
//    unsigned short m_nDriveCount;
//};

struct VIPinData
{
        short int m_nRefPin;
        short int m_nTestPin;
        short int m_nDriveChannel;
};


class IVIObserver
{
    //virtual void notifyObserver()=0;
public:
    virtual void notifySubject()=0;
    virtual void updateVI()=0;
    virtual void notifyProbeObserver()=0;
    virtual void notifyClipObserver()=0;

};

enum CHIPMODE {SINGLE,FIXED};
enum PROBEMODE {SINGLE_PROBE,DUAL_PROBE,EXTERNAL_PROBE};
enum PROBESELECTION {PROBE1=0x01,PROBE2=0x10,DUALPROBE=0x11,EXT_PROBE=0x12,EXT_FLY=0x13,NOPROBE=0};
enum WAVETYPE{IV,VT,VZ};

class VIModel
{
public:
    VIModel();
    ~VIModel()
    {
        delete m_objInteractiveDataClass,m_objInteractiveDataClass=NULL;
        delete m_objEmbeddedDataClass,m_objEmbeddedDataClass=NULL;
        m_mapObservers.clear();
    }
    void notifyEmbeddedKeysObserver()
    {
        m_mapObservers[0]->notifySubject();
    }

    void notifyProbeOserver()
    {
    	m_mapObservers[0]->notifyProbeObserver();
    }

    void notifyClipObserver()
    {
    	m_mapObservers[0]->notifyClipObserver();
    }

    void notifyVIObserver()
    {
    	m_mapObservers[0]->updateVI();
    }
    void registerObserver(short int pWinID,IVIObserver *pObserver=0);
    short int getIndexTemplate(short int);
    QString getIndexTemplate(short int,bool value);
    void setIndexTemplate(short int,short int);
    void setIndexTemplate(short int,QString);
//    void setChipSelectMode(CHIPMODE p_eChipMode);
//    CHIPMODE getChipSelectMode();

//------------------------- Store and Delete Trace----------------------
    void storeWaveTrace(short int pIndex,QStringList pData);
    void clearWaveTraces();
    void deleteWaveTrace(short int pIndex);
    QStringList getReferenceWaveData(short int pIndex);

//---------------------------------------------------------------------


//------------------------ Clip Dialog---------------------------------
    short int getChipDialog(short int);
    void setChipDialog(short int,short int);

//------------------------------ Probe Dialog --------------------------
    double getProbeThreshold();
    void setProbeThreshold(double);

    short int getProbeDialog(short int);
    void setProbeDialog(short int,short int);
//----------------------------------------------------------------------
//------------------------------ Calibration,Learn & Verify Status--------------------------------
    bool getCalibrationStatus();
    void setCalibrationStatus(bool);

    bool getLearnStatus();
    void setLearnStatus(bool);

    bool getVerifyStatus();
    void setVerifyStatus(bool);
//----------------------------------------------------------------------
//-----------------------WaveForm Type----------------------------------
    void setWaveType(WAVETYPE pWaveType)
    {
        m_eWaveType = pWaveType;
    }

    WAVETYPE getWaveType()
    {
        return m_eWaveType;
    }

//----------------------------------------------------------------------
//------------- store CalibData--------------
    void setCalibData(QString pStrCalibFilename,unsigned int pMemoryIndex)
    {
        m_mapCalibrationMemoryIndices.insert(pStrCalibFilename,pMemoryIndex);
    }

    unsigned int getCalibMemoryIndex(QString pStrFileName)
    {
        return m_mapCalibrationMemoryIndices.value(pStrFileName);
    }
// Probe Comparison
    unsigned int getAverage1() const
    {
    	return m_nAverage1;
    }
    unsigned int getAverage2() const
    {
    	return m_nAverage2;
    }

    void setAverages(unsigned int pA1,unsigned int pA2)
    {
    	m_nAverage1 = pA1;
    	m_nAverage2 = pA2;
    }
    void setPin2ChannelMap(short int,short int);
    void setPinCombinations(short int pIndex, QList<short>* pPinsList);
    QMap<short int,QList<short>* > getPinCombinations()
	{
    	return m_mapPinCombinations;
	}
    short int getPin2Channel(short int pPinNo)
    {
    	return m_mapPin2Channel.value(pPinNo);
    }
    void clearClipPrgMap()
    {
    	m_mapPin2Channel.clear();
    	m_mapPinCombinations.clear();
    }
    // CLip Checking
    void setClipLearntFlag(bool pFlag)
    {
    	isClipLearnFlag=pFlag;
    }
    bool getClipLearntFlag() const
    {
    	return isClipLearnFlag;
    }
    // -- AutoCurveFit Fuctions

    void inserADCReceVoltage(unsigned int pIndex,double pVoltage)
    {
    	m_nADCReceVoltage.insert(pIndex,pVoltage);
    }
    double getADCReceVoltage(unsigned int pIndex)
    {
    	return m_nADCReceVoltage.value(pIndex);
    }

    short int getPosPeakValue() const { return m_nPosPeakValue;}
    void setPosPeakValue(short int pValue){ m_nPosPeakValue = pValue;}

    short int getNegPeakValue() const { return m_nNegPeakValue;}
    void setNegPeakValue(short int pValue){ m_nNegPeakValue = pValue;}

    double  getPosPeak() const { return m_nPosPeak;}
    void setPosPeak(double pValue){ m_nPosPeak = pValue;}

    double getNegPeak() const { return m_nNegPeak;}
    void setNegPeak(double pValue) { m_nNegPeak = pValue;}

    short int getPosPeakIndex() const { return m_nPosPeakIndex;}
    void setPosPeakIndex(short int pValue){ m_nPosPeakIndex = pValue;}

    short int getNegPeakIndex() const { return m_nNegPeakIndex;}
    void setNegPeakIndex(short int pValue){ m_nNegPeakIndex = pValue;}

    void setAutoCurvePattern(short int pIndex,QString pName,QStringList pData);

    double getVoltageValue() ;
    double getFrequencyValue() ;
    unsigned int getImpedanceValue() ;

    void setConfidencePosEdgeCount(short int pValue) { m_nConfindencePosEdgeCount = pValue;}
    short int getConfidencePosEdgeCount() { return m_nConfindencePosEdgeCount;}

    void setConfidenceNegEdgeCount(short int pValue) { m_nConfidenceNegEdgeCount = pValue;}
    short int getConfidenceNegEdgeCount() { return m_nConfidenceNegEdgeCount;}

    void setPosLcount(short int pValue) { m_nPosLCount = pValue;}
    void setPosUCount(short int pValue) { m_nPosUCount = pValue;}
    void setNegLCount(short int pValue) { m_nNegLCount = pValue;}
    void setNegUCount(short int pValue) { m_nNegUCount = pValue;}

    short int getPosLcount() { return m_nPosLCount;}
    short int getPosUCount() { return m_nPosUCount ;}
    short int getNegLCount() { return m_nNegLCount;}
    short int getNegUCount() { return m_nNegUCount;}

    void setClipThreshold(double pThrm_nX1Positioneshold)
    {
    	m_nClipThresholdValue = pThrm_nX1Positioneshold;
    }
    double getClipThreshold()
    {
    	return m_nClipThresholdValue;
    }
    bool is10PercentListExist(QString pName)
    {
    	if(m_lst10PercentFitPatterns.contains(pName) == true)
    		return true;
    	else
    		return false;

    }
    short int get10PercentCount()
    {
    	return m_lst10PercentFitPatterns.count();
    }
    void set10PercentList(short int pIndex,QString pPattern)
    {
    	m_lst10PercentFitPatterns.insert(pIndex,pPattern);
    }

    void set5PercentList(short int pIndex,QString pPattern)
    {
    	m_lst5PercentFitPatterns.insert(pIndex,pPattern);
    }

    QString get10PercentValue(short int pIndex)
    {
    	return m_lst10PercentFitPatterns.value(pIndex);
    }

    QString get5PercentValue(short int pIndex)
    {
    	return m_lst5PercentFitPatterns.value(pIndex);
    }

    void clearPatterns()
    {
    	m_lst10PercentFitPatterns.clear();
    	m_lst5PercentFitPatterns.clear();
    	m_lstAutoCurveFitPatterns.clear();
    	m_lstConfidentCount.clear();
    }

    void clearAutoCurveFitPatters()
    {
    	m_lstAutoCurveFitPatterns.clear();
    	m_lstDetectedPatterns.clear();
    }
    QStringList getAutoPatterns()
    {
    	return m_lstAutoCurveFitPatterns;
    }

    void setCalibZeroDegree(double pValue)
    {
    	m_nCalibZeroDegree=pValue;
    }

    void setActualZeroDegree(double pValue)
    {
    	m_nActualZeroDegree=pValue;
    }

    double getActualZeroDegree()
    {
    	return m_nActualZeroDegree;
    }

    double getCalibZeroDegree()
    {
    	return m_nCalibZeroDegree;
    }

    void setCapacitorFlag(bool pFlag)
    {
    	m_bisCapacitor =pFlag;
    }
    void setInductorFlag(bool pFlag)
    {
    	m_bisInductor=pFlag;
    }
    void setDiodeFlag(bool pFlag)
    {
    	m_bDiode=pFlag;
    }
    void setResitorFlag(bool pFlag)
    {
    	m_bResistor = pFlag;
    }

    bool isResistorFound() const
    {
    	return m_bResistor;
    }

    bool isCapacitorFound() const
    {
    	return m_bisCapacitor;
    }

    bool isInductorFound() const
    {
    	return m_bisInductor;
    }
    bool isDiodeFount() const
    {
    	return m_bDiode;
    }

    void setComponent(short int pIndex,short int pValue)
    {
    	m_lstDetectedPatterns.insert(pIndex,pValue);
    }

    short int getComponent(short int pIndex)
    {
    	return m_lstDetectedPatterns.value(pIndex);
    }

protected:
    QMap<short int,IVIObserver*> m_mapObservers;
    DataClass<short int,short int>  *m_objInteractiveDataClass;
    DataClass<QString,short int>  *m_objEmbeddedDataClass;
    DataClass<short int,short int> *m_objClipDialogClass;
    DataClass<short int,short int> *m_objProbeDialogClass;

    QMap<QString,unsigned int>  m_mapCalibrationMemoryIndices;
    QMap<short int,QStringList> m_mapReferenceWaveVector;

    QMap<short int,short int> m_mapPin2Channel;
    QMap<short int,QList<short>* > m_mapPinCombinations;

    bool m_bCalibStatus,m_bLearnStatus,m_bVerifyStatus;

    WAVETYPE m_eWaveType;
    double m_nThresholdValue;
    double m_nClipThresholdValue;
    unsigned int m_nAverage1,m_nAverage2;
    bool isClipLearnFlag;

    // Auto CurveFit Variables
    short int m_nACFIndex;
    QList<double> m_nADCReceVoltage;
    QList<double> m_nADCVIReceVoltage;
    short int m_nPosPeakValue,m_nNegPeakValue;
    double m_nPosPeak,m_nNegPeak;
    short int m_nPosPeakIndex,m_nNegPeakIndex;

    double m_nCalibZeroDegree,m_nActualZeroDegree;

    short int m_nConfindencePosEdgeCount,m_nConfidenceNegEdgeCount;
    short int m_nPosLCount,m_nPosUCount,m_nNegLCount,m_nNegUCount;
    QStringList m_lstAutoCurveFitPatterns;
    QList<short int> m_lstDetectedPatterns;
    QStringList m_lst10PercentFitPatterns,m_lst5PercentFitPatterns;
    QList<int> m_lstConfidentCount;

    bool m_bisInductor,m_bisCapacitor,m_bDiode,m_bResistor;


};


#endif // VIMODELVIEW_H
