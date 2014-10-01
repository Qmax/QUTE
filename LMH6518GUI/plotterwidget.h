#ifndef PLOTTERWIDGET_H
#define PLOTTERWIDGET_H

#include <QWidget>
#include <QPixmap>
#include <QStylePainter>
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
#include <QDebug>
#include <QLinuxFbScreen>




class DBScreen : public QLinuxFbScreen
{
public:
    DBScreen(int displayId) : QLinuxFbScreen(displayId) {};
    ~DBScreen() {}
    bool initDevice();
    void shutdownDevice();
    void blit(const QImage &image, const QPoint &topLeft, const QRegion &region);
    void solidFill(const QColor &color, const QRegion &region);
    void exposeRegion(QRegion region, int changing);

private:
    QPainter *painter;
    QImage *image;
};


class PlotXYSettings
{
public:
    double minTimeDivision;
    double maxTimeDivision;
    int numXDivisions;
    double minVoltageDivision;
    double maxVoltageDivsion;
    int numYDivisions;
    double m_nOffsetPointer;
    PlotXYSettings()
    {
        minTimeDivision = 0.0;
        maxTimeDivision = 0.0;
        numXDivisions = 10;

        minVoltageDivision = 0.0;
        maxVoltageDivsion = 0.0;
        numYDivisions = 8;
        m_nOffsetPointer=0.0;

    }

    PlotXYSettings(double pMinTimeDivision,double pMaxTimeDivision,double pXDivsions,double pYDivisions,double pOffsetPointer,double pMinVoltageDivision,double pMaxVoltageDivision)
    {

        minTimeDivision = pMinTimeDivision;
        maxTimeDivision = pMaxTimeDivision;
        numXDivisions = pXDivsions;
        numYDivisions = pYDivisions;
        m_nOffsetPointer = pOffsetPointer;
        minVoltageDivision = pMinVoltageDivision*4.0;
        maxVoltageDivsion = pMaxVoltageDivision*4.0;
    }

    void setMaxTimeDivision(double pMaxTime)
    {
        maxTimeDivision = pMaxTime;
    }

    void setMinTimeDivision(double pMinTime)
    {
        minTimeDivision = pMinTime;
    }

    void setMinVoltageDivision(double pMinVoltage)
    {
        minVoltageDivision = pMinVoltage*4;
    }

    void setMaxVoltageDivision(double pMaxVoltage)
    {
        maxVoltageDivsion = pMaxVoltage*4;
    }

    double spanX() const { return maxTimeDivision - minTimeDivision;}
    double spanY() const { return (maxVoltageDivsion) - (minVoltageDivision);}
};

enum DRAW_DSO{DRAW_GRID,DRAW_ARRO};
static const double Pi = 3.14159265358979323846264338327950288419717;
static double TwoPi = 2.0 * Pi;
//enum DSO_CHANNEL{CHANNEL1,CHANNEL2,CHANNEL3,CHANNEL4};

class PlotterWidget : public QWidget
{
Q_OBJECT
public:
    explicit PlotterWidget(QWidget *parent = 0);
    ~PlotterWidget()
    {
        //dbScreen->shutdownDevice();
    }
    void refreshPixmap(DRAW_DSO);
    void drawGrid(QPainter *painter);
    void drawoffsetArrow(QPainter*);
    void constructXYPolyData(QPainter*);
    void drawPixelPlot(QPainter*);
    void drawCurves(QPainter*);
    void setPlotSettings(PlotXYSettings *pObjSettings);
    void setCurveData(int,QVector<QPointF>);
    void setChannelData(QMap<int,QList<double> >);
    void clearCurveData();
    void setChannelCount(unsigned short);
    void draw_line(qreal x1, qreal y1, qreal x2, qreal y2,QPainter *painter);
    void setSamplesCount(unsigned short pCount)
    {
    	m_nSamplesCount=pCount;
    }

    /* Event Mechanisms*/
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

    bool event(QEvent *);
signals:

public slots:
protected:
    int Margin;
    QPixmap pixmap;
     bool m_bRubberbandDrag;
     PlotXYSettings* m_objPlotSettings;
     double m_nOffsetPointer;
     QMap<int,QVector<QPointF> >  curveMap;
     QMap<int,QList<double> > m_objChannelData;
     bool m_bPaintFlag;
     DBScreen *dbScreen;
     unsigned short m_nChannelCount;
     unsigned short m_nSamplesCount;
};




#endif // PLOTTERWIDGET_H
