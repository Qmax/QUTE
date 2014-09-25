//# -------------------------------------------------
//# Project created by Ravivarman 2014-09-02T23:24:55
//# -------------------------------------------------

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QInputDialog>
#include <QPluginLoader>
#include <QLabel>
#include <QDebug>
#include "qcustomplot.h"
#include <unistd.h>

#include "InterfacePTLibrary.h"
#include "PTEventInterfaces.h"
#include "ApplicationCardInterface.h"
#include "AppdeviceRegisterDetails.h"
#include "PTSPIMemoryInterface.h"
#include "PTAppBckPsocInterface.h"
#include "hardwareinterface.h"
#include "wavedata.h"

namespace Ui {
class MainWindow;
}
class QmaxLineEdit:public QLineEdit{
    Q_OBJECT
public:
    QmaxLineEdit(int pIndex,QWidget *p=0):QLineEdit(p){
        m_nIndex=pIndex;
        setStyleSheet("color: rgb(255, 255, 255);""background-color: black;border:1px solid rgba(100,100,100,255);border-radius:5px;");
        setFrame(false);
        setFont(QFont("DejaVu Sans",14,50,false));
    }

protected:
    virtual void focusInEvent(QFocusEvent *e){
        QLineEdit::focusInEvent(e);
        emit(focussed(true));
    }

    virtual void focusOutEvent(QFocusEvent *e){
        QLineEdit::focusOutEvent(e);
        emit(focussed(false));
    }
    void mousePressEvent(QMouseEvent *event){
    	QLineEdit::mousePressEvent(event);
        emit(focussed(m_nIndex));
    }


    int m_nIndex;

signals:
    void focussed(bool hasFocus);
    void focussed(int no);
};

class QmaxLabel:public QLabel{
    Q_OBJECT
public:
    QmaxLabel(int pIndex,QWidget *p=0):QLabel(p){
        m_nIndex=pIndex;
        setAlignment(Qt::AlignCenter);
        setStyleSheet("color: rgba(0,0,0,255);""border: rgba(0,0,0,0);""border-radius: 3px;""background-color: rgba(0, 0, 0,0);""qproperty-wordWrap: true;");
        setFont(QFont("DejaVu Sans",14,75,false));
        setFrameStyle(3);
    }

public slots:
    void setlabelFocus(bool state){
        if(state)
            setStyleSheet("color: rgba(0,0,0,255);""border: 1px solid black;""border-radius: 3px;""background-color: rgba(170, 255, 127,255);""qproperty-wordWrap: true;");
        else
            setStyleSheet("color: rgba(0,0,0,255);""border: rgba(0,0,0,0);""border-radius: 3px;""background-color: rgba(0, 0, 0,0);""qproperty-wordWrap: true;");
    }

protected:
    int m_nIndex;

};

class MainWindow : public QMainWindow
{
  Q_OBJECT
  
public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();
  void clearGraphData();
  void MergeAll();

  void GenerateHexPattern();
  void loadRAM();

  QVector<double> m_nX,m_nY,m_nX1,m_nY1,m_nX2,m_nY2,m_nX3,m_nY3,m_nX4,m_nY4,m_nX5,m_nY5,m_nX6,m_nY6;
  int graphSelect,prevGraphSelect;

protected:
  //Widgets
  WaveData *m_objWaveData;
  IApplicationCardInterface *IAppCard;
  ISPIMemoryInterface *ISPIMemory;
  IPTAppBckPsocInterface *testjig;
  HardwareInterface *hwInterface;

  QmaxLineEdit *lineEdit[4];
  QmaxLabel *label[4];
  IQmaxNumberPanel *INumberPanel;
  PTEventInterface	*IPTKeyEvent;
  int m_nLineEditIndex,m_nPTKeyCode;

  double m_nAmplitude,m_nOffset;
  int m_nCycles,m_nSamples,m_nCount,m_nTotalSamples;
  int m_nWaveSamples,m_nWaveStartTick,m_nWaveStopTick,m_nWaveDutyCycle;
  bool rescaleAxis;
  bool m_bUnipolar;
  double xAxisLower,xAxisUpper,yAxisLower,yAxisUpper;
  double m_nVRef;

  QList<double> minList;
  QList<double> maxList;
  QList<char>   callType;

  void customEvent(QEvent *eve);
signals:
    void SendTotalSamples(int);
//    void triggerFGRelay(bool);
private slots:
  void on_butAppBck_clicked();
  void on_butRefresh_clicked();
  void on_butStop_clicked();
  void on_butStart_clicked();
  void on_butZoomIn_clicked();
  void on_butZoomOut_clicked();
  void on_butExit_clicked();
  void on_butRemoveAll_clicked();
  void on_butRemoveSelected_clicked();
  void on_butSine_clicked();
  void on_butSquare_clicked();
  void on_butTriangle_clicked();
  void on_butSawtooth_clicked();
  void on_butPulse_clicked();
  void on_butRandom_clicked();
  void on_butMergeAll_clicked();
  void on_actionZoom_Out_triggered();
  void on_actionZoomin_triggered();
  void on_actionRemove_Selected_triggered();
  void on_actionRemove_All_triggered();
  void on_actionRandom_triggered();
  void on_actionMerge_All_triggered();
  void on_actionPulse_triggered();
  void on_actionSAwtooth_triggered();
  void on_actionTriangle_triggered();
  void on_actionSquare_triggered();
  void on_actionSine_triggered();
  void titleDoubleClick(QMouseEvent *event, QCPPlotTitle *title);
  void axisLabelDoubleClick(QCPAxis* axis, QCPAxis::SelectablePart part);
  void legendDoubleClick(QCPLegend* legend, QCPAbstractLegendItem* item);
  void selectionChanged();
  void mousePress();
  void mouseWheel();

  void addRandomGraph();
  void addSineGraph();
  void addSquareGraph();
  void addTriangleGraph();
  void addSawtoothGraph();
  void addPulseGraph();

  void removeSelectedGraph();
  void removeAllGraphs();
  void contextMenuRequest(QPoint pos);
  void moveLegend();
  void graphClicked(QCPAbstractPlottable *plottable);

  void receiveValue(double pValue);
  void receiveValue(QString pValue);
  void receiveValue(uint pValue);
  void callLineEditInput(int leFocussed);
  
  void openWaveDataWindow();
  void RxSamples(int);
  void RxStartTick(int);
  void RxStopTick(int);
  void RxDutyCycle(int);

private:
  Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
