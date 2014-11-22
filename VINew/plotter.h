#ifndef PLOTTER_H
#define PLOTTER_H

#include <QWidget>
#include <QPixmap>
#include <QVector>
#include <QMap>
#include <QToolButton>
#include <QPointF>
#include <QStylePainter>
#include <QStyleOptionFocusRect>
#include <QPalette>
#include <QSize>
#include <stdlib.h>
#include <math.h>
#include <QRect>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QWheelEvent>
#include <stdio.h>
#include <QFile>
#include <math.h>


#define PI  3.14
#define XUNITS  10.0
#define YUNITS  8.0

struct stWaveData
{
    double m_nAmplitude;
    double m_nFrequency;
    double m_nTimeperSample;
    unsigned int m_nSamples;
    double m_nPhase;
    double m_nOffset;
    double m_nDutyCycles;
    double m_nScreenAmplitude;
    double m_nScreenTime;
    double m_nSteps;
    double m_nXunits;
    double m_nYunits;
    double m_nMinX;
    double m_nMinY;
    double m_nCycles;
    double m_nVRef;
    double m_nCalibrationGain;
    double m_nCalibrationConstant;
    unsigned int m_nMargin;
    unsigned int m_nResolution;
    bool m_bUniPolar;
    bool m_bCalibChecked;
    short int m_nPreamble;
    short int m_nPostamble;
    QString m_strXLabel;
    QString m_strYLabel;
    double m_nEnvelopBand;
};

struct stVIData
{
    double m_nVoltage;
    double m_nCurrent;
    double m_nImpedance;

};

enum m_eWaveSelection {SIN,SQUARE,TRIANGLE,SAWTOOTH,RAMP,PULSE,DC,AM,FM,PM,PWM,NONETYPE};


class PlotSettings;
class Plotter : public QWidget
{
    Q_OBJECT
public:
    Plotter(QWidget *parent = 0);
    void setRubberBandRect(QRect *pRect);
    void setMargin(int pMargin);
    void setEnvelopBand(double pBand);
    void showPixGraph();
    bool m_ZoomFlag;
    bool m_bClearTrace;
    bool m_bRubberbandDrag;
    bool m_bshowZoomRect;
    bool m_bGrid;
    bool m_bVILabels;
    bool m_bVIMode;
    bool m_bisSingleorContinuous;
    bool m_bUniPolar;
    bool m_nLoopDrive;
    QString m_strX1Label,m_strY1Label,m_strX2Label,m_strY2Label;
    void setPlotData(stWaveData*);
    void clearCurveData();
    void clearBand(int);
    virtual void setPlotSettings(const PlotSettings &settings);
    virtual void setAmplitude(double m_nAmplitude,double m_nDutyCycles);
    virtual void setCurveData(int id,const QVector<QPointF> &data);
    virtual void setBandData(int id,QVector<QPointF> &data,double pBand);
    short int getCompareWaveIndex() const;
    bool compareBand(int pId);
    virtual void clearCurve(int id);
    QSize minimumSizeHint() const;
    QSize sizeHint() const;
    m_eWaveSelection m_eWaveType;
    ~Plotter();
    bool m_showData;
    PlotSettings *m_ZoomSettings;
    bool m_moveFlag;
    double m_nOffset;
    bool zoomScreenFlag;
    void zooomScreenStatus(bool,double,double);
public slots:
    void zoomIn();
    void zommOut();
    void updateZoom(QRect,PlotSettings);

signals:
    void isRubberBandDragged(stWaveData*);
    void moveWindow(QRect,PlotSettings);
protected:
    stWaveData* m_objPlotData;
    short int m_nCompareWaveIndex;
	double adjustXaxis,adjustYaxis;//added by RRV 03072014


    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

    void keyPressEvent(QKeyEvent *event);
    void wheelEvent(QWheelEvent *event);
    void loopDrawCurves(QPainter *painter);
private:
    double m_nAmplitude;
    void updateRubberBandRegion();
    void refreshPixmap();
    void refreshlGrid();
    void drawGrid(QPainter *painter);
    void drawBand(QPainter *painter,int);
    void drawCurves(QPainter *painter);
    void drawZoomCurves(QPainter *painter);
    void generateCompareValues(int);

    int Margin;
    QRect m_objMainwindowRect;
    QMap<int,QVector<QPointF> >  curveMap;
    QMap<int,QVector<QPointF> > bandMap;
    QList<QPointF> m_lstUP,m_lstLO;
    QVector<QPointF>  loopMap;
    QVector<PlotSettings> zoomStack;
    int curZoom;
    bool rubberBandIsShown;
    QRect rubberBandRect;
    QPixmap pixmap;
    int m_nClearID;
    double m_nXZoomFactor,m_nYZoomFactor;

};

class PlotSettings
{
public:
    PlotSettings();
    PlotSettings(double pMaxX,double pMaxY,double pXTicls,double pYTicks,double pOffset,double pMinX, double pMinY);
    void scroll(int dx,int dy);
    void adjust();
    double spanX() const { return maxX - minX;}
    double spanY() const { return maxY - minY;}

    double minX;
    double maxX;
    int numXTicks;
    double minY;
    double maxY;
    int numYTicks;
    double m_nOffset;
private:
    static void adjustAxis(double &min,double &max,int &numTicks);
};
#endif
