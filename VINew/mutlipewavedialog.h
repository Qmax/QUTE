#ifndef MUTLIPEWAVEDIALOG_H
#define MUTLIPEWAVEDIALOG_H

#include <QtGui/QDialog>
#include "ui_mutlipewavedialog.h"
#include "Waveformclass.h"
#include "vimodelview.h"
#include "vifunctionallogic.h"

class MutlipeWaveDialog : public QDialog
{
    Q_OBJECT

public:
    MutlipeWaveDialog(QWidget *parent,VIModel *pObjSubject,VIFunctionalLogic *pFunObj);
    ~MutlipeWaveDialog();
    void setTestFlag(bool);
     void LoadVITraces(short int);
     void LoadPassTraces(short int);
     void LoadFailTraces(short int);
     void LoadLearntTraces();
     void calculateCombinationalTraces(bool pFlag);
     int getPassCount();
     int getFailCount();
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


 private slots:
 	void onNext();
 	void onPrevious();
 	void closeApp();
 	void onPassTraces();
 	void onFailTraces();
 	void onAllTraces();
private:
    Ui::MutlipeWaveDialogClass ui;
};

#endif // MUTLIPEWAVEDIALOG_H
