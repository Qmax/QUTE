#ifndef CHECKITEM_H
#define CHECKITEM_H

#include <QtGui/QColor>
#include <QtGui/QGraphicsItem>

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


class checkItem : public QGraphicsItem
{
public:
    checkItem(const QColor &color, int x, int y);

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
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
private:
    QColor color;
    PlotXYSettings *m_objPlotSettings;
    QRectF m_objRect;
    QMap<int,QList<double> > m_objCH1Data;

};

#endif // CHECKITEM_H
