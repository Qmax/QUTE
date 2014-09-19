#ifndef AUTOCURVEFITTRACES_H
#define AUTOCURVEFITTRACES_H

#include <QtGui/QMainWindow>
#include "ui_autocurvefittraces.h"
#include "Waveformclass.h"
#include "qlibrary.h"
#include "vimodelview.h"
#include "vifunctionallogic.h"



class AutoCurveFitTraces : public QMainWindow
{
    Q_OBJECT

public:
    AutoCurveFitTraces(VIModel *pObj=0,VIFunctionalLogic *pFunObj=0,QWidget *parent = 0);
    ~AutoCurveFitTraces();
    VIModel *m_obVImodel;
    VIFunctionalLogic *m_objFunctionalObject;
protected:
    WaveFormFactory *m_objWaveFactory;
    QStringList m_lstBestFitPatterns;
    IWaveProduct *VIProduct[6];
    short int *m_nReadData;
    void clickedPRSCR();
private:
    Ui::AutoCurveFitTracesClass ui;
    void LoadVITraces();
private slots:
        void on_print_clicked();
 void closeApp();
};

#endif // AUTOCURVEFITTRACES_H
