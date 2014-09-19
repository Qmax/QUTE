#ifndef MULTIPLETRACES_H
#define MULTIPLETRACES_H

#include <QtGui/QMainWindow>
#include "ui_multipletraces.h"
#include "Waveformclass.h"
#include "vimodelview.h"
#include "vifunctionallogic.h"
//#include <vimodel.h>
//#include "qlibrary.h"

class MultipleTraces : public QMainWindow
{
    Q_OBJECT

public:
    MultipleTraces(QWidget *parent = 0,VIModel *pObj=0,VIFunctionalLogic *pFun=0);
    ~MultipleTraces();
    void setTestFlag(bool);
    void LoadVITraces(short int);
    void LoadPassTraces(short int);
    void LoadFailTraces(short int);
    void LoadLearntTraces();
    void calculateCombinationalTraces(bool pFlag);
    int getPassCount();
    int getFailCount();
    //virtual void closeEvent (QCloseEvent *event);
protected:
    WaveFormFactory *m_objWaveFactory;
    QStringList m_lstMultipleTraces,m_lstFailStrTraces,m_lstPassStrTraces;
    QMap<short int,QList<short>* > m_mapCombinations;
    IWaveProduct *VIProduct[6];
    QLabel *label[6];
    QLabel *compareLabel[6];
    short int m_nSelectedIndex;
    void clearTraces();
    void initializeWaveProduct();
    void clickedPRSCR();
    VIModel *m_obVImodel;
    VIFunctionalLogic *m_objFunctionLogic;
    //short int m_nEndIndex;
    bool isLearn,isPassFlag,isFailFlag;
private:

	Ui::MultipleTracesClass uiMT;
private slots:
        void on_objSave_clicked();
 void onNext();
	void onPrevious();
	void closeAppMT();
	void onPassTraces();
	void onFailTraces();
	void onAllTraces();

};

#endif // MULTIPLETRACES_H
