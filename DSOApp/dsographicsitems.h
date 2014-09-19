#ifndef DSOGRAPHICSITEMS_H
#define DSOGRAPHICSITEMS_H

#include <QObject>
#include <QtGui>
#include <QtGui/QColor>
#include <QtGui/QGraphicsItem>
#include "DSOCommon.h"
const unsigned short dsoMargin=15;
static const double Pi = 3.14159265358979323846264338327950288419717;
static double TwoPi = 2.0 * Pi;
class DSOGraphicsItems : public QObject
{
public:
    DSOGraphicsItems();
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

class DSOXYPlane : public QGraphicsItem
{
public:
    DSOXYPlane(const QColor &color, int x, int y);

    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void setPlotSettings(PlotXYSettings*);
    void setBorderRect(QRectF);
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);


private:
    int x,y;
    QColor color;
    QList<QPointF> stuff;
    PlotXYSettings *m_objPlotSettings;
    QRectF m_objRect;

};

class HCursorItem:public QGraphicsItem
{
public:
    HCursorItem(const QColor &color, int x, int y);
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void setBorderRect(QRectF);
    void setCursorPosition(double pY1);
    void changeDashes( QVector<qreal> pdashes);
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

private:
    int x,y;
    QColor color;
    QList<QPointF> stuff;
    QRectF m_objRect;
    double m_nY1Position;
    QVector<qreal> Y1dashes;
};

class LineItem:public QGraphicsItem
{
public:
	LineItem(const QColor &color, int x, int y);
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void setBorderRect(QRectF);
    void setSoruceDestPoint(double,double);
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

private:
    int x,y;
    QColor color;
    QList<QPointF> stuff;
    QRectF m_objRect;
    double m_nSourcePoint,m_nDestPoint;

};


class offsetItem:public QGraphicsItem
{
public:
	offsetItem(const QColor &color, int x, int y);
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void setBorderRect(QRectF);
    void setOffsetPosition(double);
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

private:
    int x,y;
    QColor color;
    QList<QPointF> stuff;
    QRectF m_objRect;
    double m_nOffsetPointer;

};


class VCursorItem:public QGraphicsItem
{
public:
    VCursorItem(const QColor &color, int x, int y);
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void setBorderRect(QRectF);
    void setCursorPosition(double pY1);
    void setTitleText(QString);
    void setTextPostion(int x,int y);
    void changeDashes( QVector<qreal> pdashes);
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

private:
    int x,y;
    QColor color;
    QList<QPointF> stuff;
    QRectF m_objRect;
    double m_nXPosition;
    QVector<qreal> X1dashes;
    QString m_strText;
    QGraphicsTextItem m_strTextItem;
};


class VTriggerItem:public QGraphicsItem
{
public:
    VTriggerItem(const QColor &color, int x, int y);
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void setBorderRect(QRectF);
    void setTriggerPostion(double pTrigger);
    void changeColor(QColor);
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

private:
    int x,y;
    QColor color;
    QList<QPointF> stuff;
    QRectF m_objRect;
    double m_nTriggerPos;
};


class HTriggerItem:public QGraphicsItem
{
public:
    HTriggerItem(const QColor &color, int x, int y);
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void setBorderRect(QRectF);
    void setTriggerPostion(double pTrigger);
    void changeColor(QColor pColor);
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

private:
    int x,y;
    QColor color;
    QList<QPointF> stuff;
    QRectF m_objRect;
    double m_nTriggerPos;
};


class channelItem: public QGraphicsItem
{
public:
    channelItem(const QColor &color);

    QRectF boundingRect() const;
    QPainterPath shape() const;
    //void update(const QRectF pRect);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void setPlotSettings(PlotXYSettings*);
    void setBorderRect(QRectF);
    void setPlotData(QMap<int,QList<double> >);
    void setSamplingType(SAMPLING_TYPE,int);
    void setSamples(int);
    double getYPosition(double pAmpValue);
    double getXPosition(double pValue);
    void moveOffsetPostion(double pOffsetPos);
    double getOffsetPostion();
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
private:
    QColor color;
    PlotXYSettings *m_objPlotSettings;
    QRectF m_objRect;
    SAMPLING_TYPE m_eSamplesType;
    unsigned int m_nSamples;
    QMap<int,QList<double> > m_objCH1Data;

};


#endif // DSOGRAPHICSITEMS_H
