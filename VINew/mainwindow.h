#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vimodelview.h>
#include <InterfacePTLibrary.h>
#include <PTEventInterfaces.h>
#include <PTGPIOEventInterfaces.h>
#include <QButtonGroup>
#include "GPIOInterfaces.h"
#include <Waveformclass.h>
#include <vifunctionallogic.h>
#include <unistd.h>
#include "embeddedkeys.h"
#include "selectprobe.h"
#include "clipdialog.h"
#include "autocurvefittraces.h"
#include "interfaceHeader.h"
#include "multipletraces.h"
#include "mutlipewavedialog.h"
#include "PTSplashScreen.h"
#include "qtsvgslideswitch.h"
#include "EffectLabel.h"
#include "RLCInterface.h"
#include <qmovie.h>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QLabel>
#include "PTDACFInterface.h"
#include "AD5318TestJigInterface.h"

#define MAXCOUNT 5
#define REFERENCE_THRESHOLD	 0.5

const unsigned int guid = 0x56494D;


const QEvent::Type GpioEvent = (QEvent::Type) 1234;//embedded probe
const QEvent::Type KnobEvent = (QEvent::Type) 3456;//magnetic knob
const QEvent::Type PTKeyEvent = (QEvent::Type)5678;//pykey event
const QEvent::Type APPCARDDRIVEEVENT = (QEvent::Type) 7892;//Appcard drive Event


namespace Ui {
    class MainWindow;
}
static const QColor colorForIds[7] = {QColor(88,88,89,255),Qt::green,Qt::cyan,Qt::magenta,Qt::yellow,Qt::blue,Qt::white};
class MainWindow : public QMainWindow,public virtual IVIObserver {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    unsigned int getVIID() const{
        qDebug()<<"inside getVIID"<<guid;
        return guid;
    }
    void notifySubject();
    void updateVI();
    void notifyProbeObserver();
    void notifyClipObserver();

protected:
    // Interface Variables
    IQmaxMessageBox *IPTMessageBox;
    PTEventInterface *IPTKeyEvent;
    PTGPIOEventInterface *IGPIOEvent;
    InterfaceGPIOPins *IGPIOPin;
    InterfaceCalibrationLib *ICALIB;
    RLCInterface *IRLC;
    PTSplashScreen *ISplash;

    IAD5318TestJigInterface *AD5318;
    IPTDACFInterface *DACFValues;


    // Objects
    InteractiveData objInteractiveData;
    QButtonGroup *m_objVIButtonGroup;
    EmbeddedKeys *m_objEmbedded;
    SelectProbe *m_objProbeDialog;
    ClipDialog *m_objClipDialog;
    MultipleTraces *m_objMultipleTraceDialog;
    AutoCurveFitTraces *m_objAutoCurveFitWindow;



    QMessageBox *msgBox;
    QAbstractButton *connectButton,*abortButton;




    void changeEvent(QEvent *e);
    VIModel *m_objVISubject;
    //------------------------ WaveForm Product--------------------------
        WaveFormFactory *m_objWaveFactory;
        IWaveProduct *VIProduct;
    //--------------------------------------------------------------------
    //--------------------------- Functional Logic ----------------------
        VIFunctionalLogic *m_objFunctionalObject;
    //-------------------------------------------------------------------

   // Functions
        void clickedPRSCR();
        void InitializeUILibraries();
        void InitializeVIFunctions();
        void LoadInteractiveValues();
        void InitializeLegendLabels();
        void UpdateLegendLabels();
        bool validateLimit(short int);

        void LoadMiddelLayer();
        void LoadUpperLayer();
        void LoadLowerLayer();

        void readVISettings();
        void LoadEmbeddedKeys();

        void setGraphValues();

        bool checkProbeStatus();
        void initialiseInteractive();
        bool showMessageBox(bool,bool,QString,QString,QString);

        void customEvent(QEvent *e);
        void doPTKeyFunction();
        void doKeyFunction(int);

        void startVITimer();
        void stopVITimer();
        void updateInteractive();

        void switchString(short int);
        void switchFunctions(short int pKey,short int pIncrement,short int pDecrement);
        void displayComparison();
        void updateCalibrationData();
        void deleteTrace();
        void storeTrace();
        void clipLearn(bool pLearnFlag);
        void disableClipLearnGrp(bool);
        void disableInteractiveGrp(bool);
        bool compareTwoClipTraces(QString pStrLearntName,QString pStrTestName);

        //AutoCurveFit
        void callAutoCurveFit();
        void doAutoCurveFitAlgorithm();
        bool checkforOC();
        bool checkforSC();
        bool diodeDetection();
        bool resistanceDetection();
        short int selectImpedanceIndex(double);
        void driveACPattern(short int,short int,short int);
        short int measurePhaseShift();
        void measureVoltages(double *,double *,bool);
        void measureCapactiance();
        void measureInductance();

    // Variables
    int m_nPTKeyCode,m_nKeyCode,m_nWaveIndex,m_nStoreWaveIndex;
    short int m_nVoltageIndex,m_nFrequencyIndex,m_nImpedanceIndex,m_nAutoFitPatternCount,m_nAutoCount,m_nInductanceCount,m_nCapacitanceCount;
    short int m_nUpperBandPercentage,m_nLowerBandPercentage,m_nConfidenceBandPercentage,m_nDualIndex;
    short int m_nSelectInteractiveParam,m_nSelectedProbe,m_nToggleIndex,m_nSTIndex;
    short int m_nClipLVoltage,m_nClipLImepdance,m_nClipFrequency;
    bool m_bAutoCurveFit,msgBoxLive,m_startTimer,isChangeActive,isChangeActive1,m_isProbesOnly,isCompareActive,m_biSLearnFlag,m_bParamFlag,m_bClipLearn;
    bool m_ISCalibDone,m_bClipVerify,m_bPCMode,m_bStartApp;
    double m_nCurveFitResistance;
    bool m_bCapacitance,m_bInductance,m_bIsResistance;
    double m_nVoltArray[3],m_nCalibVoltArray[3];
    bool m_bDivideUpper,m_bDivideLower;
    unsigned short m_nPOSCalibRange,m_nNegCalibRange;
    double m_nShortDiff;
    short int m_nShortcount;
    short int m_nCheckDegree;
    QString m_strFunctionKey;
    CALIB *m_objCalibData;
    short int m_bDummyDrive;

    //Legend Labels Declaration
    QLabel  *l_objProbeStatus,*l_objPassFail,*l_objErrorPercentage,*l_objLearnVerify;
    QLabel  *l_objTraceNumber1,*l_objTraceNumber2,*l_objTraceNumber3,*l_objTraceNumber4,*l_objTraceNumber5;
    QLabel  *l_objFrequency,*l_objImpedance,*l_objVoltage;
    QLabel  *l_objKeyLeft,*l_objKeyRight,*l_objKeyMiddle;
    QLabel  *l_objRefType,*l_objCombinations,*l_objDriveSettings,*l_objComparison;

private:
    Ui::MainWindow *ui;

private slots:
        void on_bestFitButton_clicked();
        void on_butP2Area_clicked();
        void on_butP1Area_clicked();
        void on_DACFValues_clicked();
 void on_AD5318Panel_clicked();
    void on_butZoom_clicked();
    void on_yAxisBox_valueChanged(double );
    void on_xAxisBox_valueChanged(double );
    void on_butExternal_2_clicked();
    void on_tblFrequency_clicked();
    void on_tblImpedance_clicked();
    void on_tblVoltage_clicked();
    void on_butVerify_clicked();
    void on_butLearn_clicked();
    void on_butAM_clicked();
    /*void on_butExternal_clicked();//commented by rravivarman 24th july 2014*/
    void on_butProbe2_clicked();
    void on_butProbe1_clicked();
    void shrinkSize(int);
    void restoreSize(int);

private slots:


    void on_butR_clicked();
    void on_butM_clicked();
    void on_butL_clicked();
    void on_butDown_clicked();
    void on_butUP_clicked();
    void on_exit_clicked();
    void on_calibButton_clicked();
    void on_deleteButton_clicked();
    void on_storeButton_clicked();
    void on_butProbe_clicked();
    void on_butClip_clicked();
    void on_startButton_clicked();
    void on_butProClip_clicked();
    void on_tblVI_clicked();
    void on_tblVT_clicked();
    void on_butViewTrace_clicked();
    void on_chkAC_clicked(); // For Autocurvefit testing purpose

};

#endif // MAINWINDOW_H
