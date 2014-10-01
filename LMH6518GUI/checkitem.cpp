#include "checkitem.h"
#include <qdebug.h>

#include <QtGui>

checkItem::checkItem(const QColor &color, int x, int y)
{
//    this-> = x;
//    this->y = y;
    this->setPos(x,y);
    this->color = color;
    //setZValue((x + y) % 2);

   // setFlags(ItemIsSelectable | ItemIsMovable);
    setAcceptsHoverEvents(true);
}

QRectF checkItem::boundingRect() const
{
    return m_objRect;
}

QPainterPath checkItem::shape() const
{
    QPainterPath path;
    path.addRect(14, 14, 82, 42);
    return path;
}

void checkItem::setPlotSettings(PlotXYSettings *pObjSettings)
{
    m_objPlotSettings= pObjSettings;
}

void checkItem::setBorderRect(QRectF pRect)
{
    m_objRect = pRect;

}

void checkItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //qDebug()<<"plot XY Grid";
    Q_UNUSED(widget);
    double offsetMargin=20;

    QPen pen;
    QColor objColor(88,88,87,255);
    pen.setColor(objColor);
    pen.setWidthF(1.0);
    pen.setStyle(Qt::SolidLine);
    painter->setPen(pen);
 //   qDebug()<<"ObjRect:"<<m_objRect.width();
    QRectF rect(offsetMargin,offsetMargin,m_objRect.width()-2*offsetMargin,m_objRect.height()-2*offsetMargin);
 //   qDebug()<<"Rect:"<<rect.width();
    painter->drawRect(rect);
    int l_nHWidth = ((rect.width()) / (m_objPlotSettings->numXDivisions));
    for(int i=0;i<m_objPlotSettings->numXDivisions;i++)
    {
        int x =  rect.left() +(i * (rect.width()) / m_objPlotSettings->numXDivisions);
        if( i !=0 ){
           painter->drawLine(x,rect.top(),x,rect.bottom());
        }
        for(int j=0;j<5;j++)
        {
            int y= (j*(l_nHWidth/5));
            if(j!=0)
            {
                painter->drawLine((x+y),(rect.height()+2*offsetMargin)/2-2,x+y,(rect.height()+2*offsetMargin)/2+2);
            }
        }
    }
    int l_nVWidth = ((rect.height()+2*offsetMargin) / m_objPlotSettings->numYDivisions);
    for(int i=0;i<m_objPlotSettings->numYDivisions;i++)
    {
        int y =  rect.bottom() -(i * (rect.height()) / m_objPlotSettings->numYDivisions);
        if( i !=0 ){
            painter->drawLine(rect.left(),y,rect.right(),y);
        }
        for(int j=0;j<5;j++)
        {
            int x= (j*(l_nVWidth/5));
            if(j!=0)
            {
                painter->drawLine(((rect.width()+2*offsetMargin)/2)-2,y-x,((rect.width()+2*offsetMargin)/2)+2,y-x);
            }
        }
    }
}

void checkItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mousePressEvent(event);
    update();
}

void checkItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->modifiers() & Qt::ShiftModifier) {
        stuff << event->pos();
        //qDebug()<<event->pos();
        update();
        return;
    }
    QGraphicsItem::mouseMoveEvent(event);
}

void checkItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mouseReleaseEvent(event);
    update();
}


// Channel Item

channelItem::channelItem(const QColor &color)
{
    this->color = color;
  //  setZValue(0);
   // setFlags(ItemIsSelectable | ItemIsMovable);
    setAcceptsHoverEvents(true);
}

QRectF channelItem::boundingRect() const
{
    return m_objRect;
}

QPainterPath channelItem::shape() const
{
    QPainterPath path;
    path.addRect(14, 14, 82, 42);
    return path;
}

void channelItem::setPlotSettings(PlotXYSettings *pObjSettings)
{
    m_objPlotSettings= pObjSettings;
}

void channelItem::setBorderRect(QRectF pRect)
{
    m_objRect = pRect;

}

void channelItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
 //   qDebug()<<"plot Channel Item"<<m_objCH1Data.count();
    Q_UNUSED(widget);
    Q_UNUSED(option);
    double offsetMargin=20;
    QPen pen;
    //QColor objColor(255,0,0,255);
    pen.setColor(color);
    pen.setWidthF(1.0);
    pen.setStyle(Qt::SolidLine);
    painter->setPen(pen);
    QRectF rect(offsetMargin,offsetMargin,m_objRect.width()-2*offsetMargin,m_objRect.height()-2*offsetMargin);
    double y =0.0,x=0.0,dx=0.0,dy=0.0;
    painter->setClipRect(rect.adjusted(+1,+1,-1,-1));

    double dxFactor = 1.0;
    double l_nIncX=0.0;
    painter->setPen(pen);

    for(int l_nDataIndex=0; l_nDataIndex< m_objCH1Data.count();l_nDataIndex++)
    {
            QList<double> dy;
            QPolygonF polyline(2);
            double dx = (rect.left()+ l_nIncX);
            dy = m_objCH1Data.value(l_nDataIndex);
            double y = ((rect.height()/2) - ((dy.value(0)+(m_objPlotSettings->m_nOffsetPointer))*((rect.height()-1))/(1.0)));
            polyline[0]=QPointF(dx,y);
            l_nIncX = l_nIncX + dxFactor;
            dx = (rect.left()+ l_nIncX);
            dy.clear();
            dy = m_objCH1Data.value(l_nDataIndex+1);
            y = ((rect.height()/2) - ((dy.value(0)+(m_objPlotSettings->m_nOffsetPointer))*((rect.height()-1))/(1.0)));
            polyline[1]=QPointF(dx,y);
            painter->drawPolyline(polyline);
    }
}

void channelItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mousePressEvent(event);
    update();
}

void channelItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->modifiers() & Qt::ShiftModifier) {
        //stuff << event->pos();
        //qDebug()<<event->pos();
        update();
        return;
    }
    QGraphicsItem::mouseMoveEvent(event);
}

void channelItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mouseReleaseEvent(event);
    update();
}

//void channelItem::update(const QRectF pRect)
//{
////	qDebug()<<"Update overrided";
//	update(pRect);
//}

void channelItem::setPlotData(QMap<int, QList<double> > pObjData)
{
    m_objCH1Data.clear();
    m_objCH1Data = pObjData;
    update();
}






