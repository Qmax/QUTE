#ifndef VIFUNCTIONALLOGIC_H
#define VIFUNCTIONALLOGIC_H

#include <QString>
#include <QStringList>
#include <vimodelview.h>
#include <vihwclass.h>
#include <Waveformclass.h>


#define MID_RANGE 8191

class VIFunctionalLogic
{
public:
    VIFunctionalLogic();
    VIFunctionalLogic(const VIFunctionalLogic& pObj);
    ~VIFunctionalLogic();
    void setVISubject(VIModel *pObjSubject=0);
    void driveVI();

    void loadDriveFIFO();
    void peformReceive(QString);
    QStringList getFileData(QString);

    void peformDrive();
    void storeTrace();
    void deleteTrace();
    void clipLearn(bool);
    unsigned short getProbeStatus();
    void ReadCalibrationFunctionFile();
    void ReadCalibrationFunctionFile(QString pStrName);
    unsigned int ReadPSOCCODEID();
    void renameFile(QString pStrFilename);
    void switchPROBES(PROBESELECTION);
    bool isMuxDetected();
    bool checkMuxStatus();
    unsigned int switchTestChannel(short int pTestPinChannel);
    unsigned int switchRefChannel(short int pRefPinChannel);
    void readChannels();
    void externalMuxMeasurement(short int,short int);
    void ENINT();
    void DISABLEINT();
    void CLEARINT();
    unsigned int readEmbeddedKeyValue();
    unsigned int readAppcardIntValue();
    void readParallelDACCalibrationFile(short int);
    double getReceiveCalibrationConstant(short int);
    double getReceiveCalibrationGain(short int);
    void writePSOC(unsigned int);
    void resetPSOC();//added by ravivarman 31st july
    unsigned int readPSOC();
    void stopDrive();
    void onCommonGNDRelay(bool);
    void setPSOCDelay();
    void setPSOCBaudRate(unsigned int);
    void checkforDriveDoneBit();
    void setFileBit(bool);

    //-----------waveData
    stWaveData* showVITrace(int pWaveTrace,short int);
    void setGraphValues();
    void setTickValue(short int pTick=0);

    // ---- Calibration steps--------------------------------------------

    void doMemoryCalibration();
    void setCalibDataMap();

    // ---------- AutoCurve Fit Functions
    void doAutoCurveFitAlgorithm();
    void converttoVoltage(QStringList pActualData,double l_nGainFactor,CALIB *pObj);
    void measurePhaseShift(QStringList pActualData,CALIB *pObj);
    bool compareCureValues(QStringList pActualData,short int pLowerBand,short int pHigherBand,QString pStrPatternName);
    QList<short int> calculateLCSlope(QStringList pYActualData);


    //------------------------------------------------------------------------
    //------------- ProbeComparison-----------------------------------------
    int caluculateErrorPercentange(QStringList,QStringList pActualData);
    void calculateAverage(QString l_strFileName);
    //----------------------------------------------------------------------

    //--------------------- Clip Dialog ------------------------------------------------------------
    void generateFixedReference();
    void generateMovingReference();
    void generateChannels();
    //---------------------------------------------------------------------------------------------
protected:

    // ----------------- Probe Learn--------------------------------

        bool checkandSwitchProbeStatus();
        bool isDualorSingle();
        bool checkMUXStatus();
    // --------------- CLip Learn-------------------------------------

    unsigned int caluculateClipErrorPercentance(QStringList pReferenceData,QStringList pActualData,unsigned int pA1,unsigned pA2);
    void doClipLearnorVerify();

    // ------------------- Calibration---------------------
    void writeMemory(unsigned int);
    bool checkSPICodeID();
    void storeCalibFile(QString pStrCalibFile,short unsigned int *pReadData);


    // ----------------- AutoCurveFIt-----------------------
    void switchVIF();
    void switchVoltage();
    void switchDDSFrequency();
    void switchImpedance();
    void switchFrequency();
    void GenerateSINEPattern();
    void GenerateHexPattern();
    void readHEXFile();
    void peformDriveConfiguration();




    //void converttoVoltage(QStringList pActualData,double pData,CALIB *obj);
    //void converttoVIVoltage(QStringList pReferenceData,QStringList pActualData,double pData,CALIB *obj);


   // ------------------------ Trace Logi ----------------------
    void storeTrace(short int pIndex,QStringList pData,bool isRef);
    void deleteTrace(short int pIndex);
    QStringList receiveRefTrace(short int pIndex);
    QStringList receiveActualTraces(short int pIndex);
    unsigned short int *DriveData;
    double m_nRangeSlope[6],m_nRangeConstant[6],m_nXVoltage[6],m_nYVoltage[6];
    double m_nVI1ReceiveSlope[6],m_nVI1ReceiveConst[6];

private:
   VIModel *m_objVISubject;
   VIHWClass m_obVIHWInstance;
   QVector<QPointF> m_nData;
   bool m_bRefFile;
   stWaveData *m_objVIWaveData;
   unsigned short int *m_nReadData;
   short int m_nTickValue;
};

#endif // VIFUNCTIONALLOGIC_H
