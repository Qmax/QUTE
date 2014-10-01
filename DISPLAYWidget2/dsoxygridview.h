#ifndef DSOXYGRIDVIEW_H
#define DSOXYGRIDVIEW_H

#include <QtGui>
#include <qdebug.h>
#include <QtGui/QGraphicsItem>

enum SAMPLING_TYPE{NORMAL=0,MIN_MAX,AVERAGE,MOVING_AVERAGE,LINEAR_INTERPOLATION,MOVING_LINEAR,WAVEFORM_MEMORY};

/*
    XY Rect Pane
        ( Pane Height,Width,XPos,YPos)
    X ScaleLength
    Y ScaleLength
    X Divisions - Time
    Y Divisions - Voltage
    Horizontal Trigger Position
    Vertical Trigger Position
    Offset Point
 */

static const double Pi = 3.14159265358979323846264338327950288419717;
static double TwoPi = 2.0 * Pi;
static const int dsoMargin = 12;

enum DSO_CHANNEL{CHANNEL1,CHANNEL2,CHANNEL3,CHANNEL4};
class PT_DSO_CURSORS
{
public:
    enum PT_CURSORS
    {
        HORIZONTAL_CURSOR_X1 = 0x01,
        HORIZONTAL_CURSOR_X2 = 0x02,
        VERTICAL_CURSOR_Y1 = 0x03,
        VERTICAL_CURSOR_Y2 = 0x04
    };
    Q_DECLARE_FLAGS(DSO_CURSORS,PT_CURSORS);
};

Q_DECLARE_OPERATORS_FOR_FLAGS(PT_DSO_CURSORS::DSO_CURSORS);


class PT_DSO_TRIGGER_OPTIONS
{
public:
    enum PT_TRIGGER_OPTIONS
    {
        TRIGGER_HORIZONTAL = 0x01,
        TRIGGER_VERTICAL = 0x02
    };

    Q_DECLARE_FLAGS(DSO_TRIGGER,PT_TRIGGER_OPTIONS);
};

Q_DECLARE_OPERATORS_FOR_FLAGS(PT_DSO_TRIGGER_OPTIONS::DSO_TRIGGER);




struct DSOGridRect
{
public:
    DSOGridRect(double pX,double pY,double pWidth,double pHeight)
    {
        m_nHeight = pHeight;
        m_nWidth = pWidth;
        m_nXPos = pX;
        m_nYPos = pY;
    }
//
//protected:
            
    double m_nHeight;
    double m_nWidth;
    double m_nXPos;
    double m_nYPos;
};
Q_DECLARE_METATYPE(DSOGridRect*)


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


class DSOXYGridData
{
public:
    DSOXYGridData()
    {
        //m_DSOGridRect = new DSOGridRect();
    }
    ~DSOXYGridData()
    {
      //  qDebug() << "Grid Data Deleted";
        delete m_DSOGridRect;
    }

    DSOGridRect *m_DSOGridRect;
    PlotXYSettings *m_DSOPlotSettings,*m_DSOPlotSettingsCH2;
protected:

};
// Model Class
class DSOXYGridModel:public QObject
{
    Q_OBJECT
public:
    DSOXYGridModel(QObject *parent=0):QObject(parent)
    {
        m_objGridData = new DSOXYGridData();
    }
   ~DSOXYGridModel()
   {
       //qDebug() << "Grid Model Object Deleted";
       delete m_objGridData;
   }
   void setXYGridRect(DSOGridRect *pValue)
   {
           m_objGridData->m_DSOGridRect = pValue;

   }

   DSOGridRect* getXYGridRect()
   {
       return m_objGridData->m_DSOGridRect;
   }

   void setPlotSettings(PlotXYSettings *pObjSettings,DSO_CHANNEL pChannel)
   {
	   if(pChannel == CHANNEL1 || pChannel == CHANNEL2)
		   m_objGridData->m_DSOPlotSettings= pObjSettings;
	   else if(pChannel == CHANNEL3 || pChannel == CHANNEL4)
		   m_objGridData->m_DSOPlotSettingsCH2 = pObjSettings;
	   qDebug()<<"PlottSettings Completed";
   }

   PlotXYSettings* getPlotSettings(DSO_CHANNEL pChannel)
   {
	   if(pChannel == CHANNEL1 || pChannel == CHANNEL2)
		   return m_objGridData->m_DSOPlotSettings;
	   else if(pChannel == CHANNEL3 || pChannel == CHANNEL4)
	   		   return m_objGridData->m_DSOPlotSettingsCH2;
   }
protected:
   DSOXYGridData *m_objGridData;
};


class DisplayRect:public QGraphicsItem
{
public:
    DisplayRect(QGraphicsItem *parent=0):QGraphicsItem(parent)
    {

    }
    QRectF boundingRect() const
    {
        return QRectF(32, 10, 150, 75);
    }
    void setRect(QRectF pObjRect)
    {
        m_objDisplayRect = pObjRect;
    }

protected:
    QRectF m_objDisplayRect;
};


class HCursorsItem:public QGraphicsItem
{
public:
    HCursorsItem(QGraphicsItem *parent=0):QGraphicsItem(parent)
    {
        m_nY1Position =0.0;
        m_nY2Position =0.0;
        m_nPaintFlag=true;
    }

    QRectF boundingRect() const
    {
        return QRectF(m_objRect);
    }
    void setBoundaryRect(QRectF pObjRect)
    {
        m_objRect = pObjRect;
       // m_nY1Position = m_objRect.height()/4.0;
       // m_nY2Position = m_objRect.height()/8.0;
    }

    void setY1Cursor(double pY1)
    {
        m_nY1Position = pY1;
    }
    void setY2Cursor(double pY2)
    {
    	m_nY1Position = pY2;
    }

    void hideHCursors(bool pFlag)
    {
        m_hideHCursors = pFlag;
    }
    void changeDashes(bool pChangedashes)
    {
    	m_bDashes=pChangedashes;
    }
    void paintHCursorItem(QPainter *painter)
    {
    	 int l_nOffsetMargin=dsoMargin;
    //	qDebug()<<"HCursor"<<m_hideHCursors;
        QPointF sourceY1Point,destY1Point,sourceY2Point,destY2Point;
        //painter->setRenderHint(QPainter::Antialiasing);

        QPen pen;
        QVector<qreal> Y1dashes,Y2dashes;
        qreal space = 6;
        if( m_bDashes == true)
        {
        	Y1dashes << 20 << space ;
        	pen.setDashOffset(4);
        }
        if( m_bDashes == false){
        	Y1dashes << 18 << space <<9<<space<<3;
        	pen.setDashOffset(8);
        }
        pen.setBrush(QColor(255,255,255,255));
        pen.setColor(QColor(255,255,255,255));
        pen.setWidthF(1.0);
        pen.setCapStyle(Qt::SquareCap);
        pen.setJoinStyle(Qt::MiterJoin);
        if( m_hideHCursors !=true){

            pen.setDashPattern(Y1dashes);
            painter->setPen(pen);
        }
        else
            painter->setPen(Qt::NoPen);

        sourceY1Point.setX(m_objRect.x());
        sourceY1Point.setY(m_objRect.top()+m_nY1Position);
        destY1Point.setX(m_objRect.width()-l_nOffsetMargin);
        destY1Point.setY(m_objRect.top()+m_nY1Position);
        QLineF HY1Cursor(sourceY1Point,destY1Point);
        if(m_hideHCursors == false)
        	painter->drawLine(HY1Cursor);
//        space=4;
//        Y2dashes << 18 << space <<9<<space<<3;
//
//        if( m_hideHCursors !=true){
//            painter->setPen(pen);
//        	pen.setDashPattern(Y2dashes);
//        }
//        else
//            painter->setPen(Qt::NoPen);
//        sourceY2Point.setX(m_objRect.x());
//        sourceY2Point.setY((m_objRect.top()+m_nY2Position));
//        destY2Point.setX(m_objRect.width()-l_nOffsetMargin);
//        destY2Point.setY(m_objRect.top()+m_nY2Position);
//        QLineF HX2Cursor(sourceY2Point,destY2Point);
//        if(m_nCursorPtr==2)
//        	painter->drawLine(HX2Cursor);

    }
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
    {
        //qDebug() << "Inside HCursors Paint";
        Q_UNUSED(option);
        Q_UNUSED(widget);
        //if(m_nPaintFlag)
        //{
        	paintHCursorItem(painter);
        	m_nPainter=painter;
        //	m_nPaintFlag=false;
        //}
    }
//    void mousePressEvent(QGraphicsSceneMouseEvent *event)
//    {
//        QGraphicsItem::mousePressEvent(event);
//        update();
//    }
//
//    void mouseMoveEvent(QGraphicsSceneMouseEvent *event)
//    {
//    	event->ignore();
//    }
//
//    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
//    {
//        QGraphicsItem::mouseReleaseEvent(event);
//        update();
//    }

protected:
    double m_nY1Position;
    double m_nY2Position;
    bool m_hideHCursors;
    QRectF m_objRect;
    bool m_nPaintFlag;
    QPainter *m_nPainter;
    bool m_bDashes;


};



class VCursorsItem:public QGraphicsItem
{
public:
    VCursorsItem(QGraphicsItem *parent=0):QGraphicsItem(parent)
    {
        m_nX1Postion=0.0;
        m_nX2Position=0.0;
        m_nPaintFlag=true;
    }
    QRectF boundingRect() const
    {
        //return QRectF(32, 10, 150, 75);
        return QRectF(m_objRect);
    }

    double X1Position() const
    {
        return m_nX1Postion;
    }

    double X2Position() const
    {
        return m_nX1Postion;
    }

    void setX1Position(double pX1Pos)
    {
        m_nX1Postion = pX1Pos;
    }
    void setX2Position(double pX2Pos)
    {
    	m_nX1Postion = pX2Pos;
    }
    void changeDashes(bool pChangedashes)
     {
     	m_bDashes=pChangedashes;
     }
    void hideCursors(bool pFlag,short int pValue)
    {
        hideVCursors = pFlag;
    }

    void paintVCursors(QPainter *painter)
    {
        QPointF sourceX1Point,destX1Point,sourceX2Point,destX2Point;
        //painter->setRenderHint(QPainter::Antialiasing);
        int l_nOffsetMargin=dsoMargin;
        QPen pen;
        QVector<qreal> X1dashes,X2dashes;
        qreal space = 6;
        X1dashes << 20 << space ;
        if(m_bDashes)
        	pen.setDashOffset(4);
        else
        	pen.setDashOffset(8);
        pen.setBrush(QColor(255,255,255,255));
        pen.setColor(QColor(255,255,255,255));
        pen.setWidthF(1.0);
        pen.setCapStyle(Qt::SquareCap);
        pen.setJoinStyle(Qt::MiterJoin);
        if( hideVCursors !=true)
        {

            pen.setDashPattern(X1dashes);
            painter->setPen(pen);
        }
        else
            painter->setPen(Qt::NoPen);
        //painter->setPen(QPen(QColor(255,255,255,255), 1.5, Qt::CustomDashLine, Qt::SquareCap, Qt::MiterJoin));
        sourceX1Point.setX(m_objRect.top()+m_nX1Postion);
        sourceX1Point.setY(m_objRect.top());
        destX1Point.setX(m_objRect.top()+m_nX1Postion);
        destX1Point.setY(m_objRect.height()-l_nOffsetMargin);
        QLineF HX1Cursor(sourceX1Point,destX1Point);
        if( hideVCursors !=true)
        	painter->drawLine(HX1Cursor);
        //painter->setPen(QPen(QColor(255,255,255,255), 1.5, Qt::DashLine, Qt::SquareCap, Qt::MiterJoin));
//        space=4;
//        X2dashes << 18 << space <<9<<space<<3;
//
//        if( hideVCursors !=true){
//            painter->setPen(pen);
//            pen.setDashPattern(X2dashes);
//        }
//        else
//            painter->setPen(Qt::NoPen);
//        sourceX2Point.setX(m_objRect.top()+m_nX2Position);
//        sourceX2Point.setY(m_objRect.top());
//        destX2Point.setX(m_objRect.top()+m_nX2Position);
//        destX2Point.setY(m_objRect.height()-l_nOffsetMargin);
//        QLineF HX2Cursor(sourceX2Point,destX2Point);
//        painter->drawLine(HX2Cursor);
    }

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
    {
        //qDebug() << "Inside VCursors Paint";
        Q_UNUSED(option);
        Q_UNUSED(widget);
      //  if(m_nPaintFlag)
       // {
        //	qDebug() << "Inside VCursors Paint Once";
        	paintVCursors(painter);
        	m_nPainter =painter;
        //	m_nPaintFlag=false;
       // }

    }
    void setBoundaryRect(QRectF pObjRect)
    {
        m_objRect = pObjRect;
      //  m_nX1Postion = m_objRect.width()/4.0;
  //      m_nX2Position = m_objRect.width()/8.0;
    }
protected:
    double m_nX1Postion;
    double m_nX2Position;
    bool hideVCursors;
    QRectF m_objRect;
    QPainter *m_nPainter;
    bool m_nPaintFlag;
    bool m_bDashes;
//    void mousePressEvent(QGraphicsSceneMouseEvent *event)
//       {
//           QGraphicsItem::mousePressEvent(event);
//           update();
//       }
//
//       void mouseMoveEvent(QGraphicsSceneMouseEvent *event)
//       {
//    	   event->ignore();
//           //QGraphicsItem::mouseMoveEvent(event);
//           //update();
//       }
//
//       void mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
//       {
//           QGraphicsItem::mouseReleaseEvent(event);
//           update();
//       }

};


class TriggerItem:public QGraphicsItem
{
public:
    TriggerItem(QGraphicsItem *parent=0):QGraphicsItem(parent)
    {
        m_nHorizontalTriggerPos =0.0;
        m_nVerticalTriggerPos =0.0;
        m_nPaintFlag=true;
    }

    double getHorizontalTriggerPostion() const
    {
        return m_nHorizontalTriggerPos;
    }

    double getVerticalTriggerPostion() const
    {
        return m_nVerticalTriggerPos;
    }
    QRectF boundingRect() const
    {
        //return QRectF(32, 10, 150, 75);
        return QRectF(m_objRect);
    }

    void setHorizontalTriggerPosition(double pTriggerPosition)
    {
        m_nHorizontalTriggerPos = pTriggerPosition;
        //update();
    }

    void setVerticalTriggerPostion(double pTriggerPostiion)
    {
        m_nVerticalTriggerPos = pTriggerPostiion;
       // update();
    }

    void paintTriggers(QPainter *painter)
    {
        int l_nOffsetMargin=dsoMargin;
          QPointF sourcePoint,destPoint,sourceHorPoint,destHorPoint;
          QPointF sourceArrowP1,sourceArrowP2,sourceHArrowP1,sourceHArrowP2;
          double angle=0.0;
          //painter->setRenderHint(QPainter::Antialiasing);
          sourcePoint.setX(m_objRect.width()-l_nOffsetMargin);
          destPoint.setX(m_objRect.width());
          sourcePoint.setY((m_objRect.height()/2) +m_nVerticalTriggerPos );
          destPoint.setY((m_objRect.height()/2)+m_nVerticalTriggerPos);

          QLineF horizontalLine (sourcePoint,destPoint);
          QLineF triggerLine(QPointF(sourcePoint.x()-10,sourcePoint.y()),QPointF(destPoint.x()-m_objRect.width()-l_nOffsetMargin,destPoint.y()));
          //painter->setBrush(Qt::magenta);
          painter->setPen(QPen(Qt::lightGray, 1.0, Qt::DotLine, Qt::RoundCap, Qt::RoundJoin));
        //  painter->drawLine(triggerLine);
          painter->setBrush(Qt::magenta);
          painter->setPen(QPen(Qt::magenta, 1.0, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));

          angle = ::acos(horizontalLine.dx() / horizontalLine.length());
          if (horizontalLine.dy() >= 0)
              angle = TwoPi - angle;

          qreal l_nArrowSize = 8.0;
          sourceArrowP1 = sourcePoint + QPointF(sin(angle + Pi / 3) * l_nArrowSize,cos(angle +Pi / 3) * l_nArrowSize);
          sourceArrowP2 = sourcePoint + QPointF(sin(angle + Pi - Pi / 3) * l_nArrowSize,cos(angle + Pi - Pi / 3) * l_nArrowSize);
          painter->drawPolygon(QPolygonF() << horizontalLine.p1() << sourceArrowP1 << sourceArrowP2);

        //  qDebug()<<"Horizontal Init Pos:"<<((m_objRect.width())/2)<<"Trigger Pos:"<<((m_objRect.width())/2)+m_nHorizontalTriggerPos;
          sourceHorPoint.setX(((m_objRect.width())/2)+m_nHorizontalTriggerPos);
          destHorPoint.setX(((m_objRect.width())/2)+m_nHorizontalTriggerPos);

          sourceHorPoint.setY(m_objRect.height()-l_nOffsetMargin);
          destHorPoint.setY(m_objRect.height());
          QLineF verticalLine(sourceHorPoint,destHorPoint);
          angle = ::acos(verticalLine.dx() / verticalLine.length());

          if (verticalLine.dy() >= 0)
              angle = TwoPi - angle;

          sourceHArrowP1 = destHorPoint + QPointF(sin(angle - Pi / 3) * l_nArrowSize,cos(angle -Pi / 3) * l_nArrowSize);
          sourceHArrowP2 = destHorPoint + QPointF(sin(angle - Pi + Pi / 3) * l_nArrowSize,cos(angle - Pi + Pi / 3) * l_nArrowSize);
          painter->drawPolygon(QPolygonF() << verticalLine.p1() << sourceHArrowP1 << sourceHArrowP2);
    }

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
    {
        //qDebug()<<"Inside Trigger Paint";
        Q_UNUSED(option);
        Q_UNUSED(widget);
       // if(m_nPaintFlag)
      //  {
        //	qDebug()<<"Paint Trigger Once";
        	paintTriggers(painter);
        	m_nPainter=painter;
        //	m_nPaintFlag=false;
      //  }
    }

    void setTriggerPostion(double m_nPos)
    {
        if(m_optTrigger.testFlag(PT_DSO_TRIGGER_OPTIONS::TRIGGER_HORIZONTAL))
        {
            m_nHorizontalTriggerPos = m_nPos;
        }
        if(m_optTrigger.testFlag(PT_DSO_TRIGGER_OPTIONS::TRIGGER_VERTICAL))
        {
            m_nVerticalTriggerPos = m_nPos;
        }
    }

    void setBoundaryRect(QRectF pObjRect)
    {
        m_objRect = pObjRect;
    }

    void setTriggerOption(PT_DSO_TRIGGER_OPTIONS::DSO_TRIGGER pTriggerOptions)
    {
        m_optTrigger = pTriggerOptions;
    }

protected:
    double m_nHorizontalTriggerPos;
    double m_nVerticalTriggerPos;
    PT_DSO_TRIGGER_OPTIONS::DSO_TRIGGER m_optTrigger;
    QRectF m_objRect;
    QPainter *m_nPainter;
    bool m_nPaintFlag;
//    void mousePressEvent(QGraphicsSceneMouseEvent *event)
//       {
//           QGraphicsItem::mousePressEvent(event);
//           update();
//       }
//
//       void mouseMoveEvent(QGraphicsSceneMouseEvent *event)
//       {
//    	   event->ignore();
//       }
//
//       void mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
//       {
//           QGraphicsItem::mouseReleaseEvent(event);
//           update();
//       }

};



class OffsetItem: public QGraphicsItem
{
public:
    OffsetItem(QGraphicsItem *parent=0):QGraphicsItem(parent)
    {
        m_nOffsetPointer = 0.0;
        m_nPaintFlag = true;
    }
    double getOffsetPointer() const
    {
        return m_nOffsetPointer;
    }
    QRectF boundingRect() const
    {
        //return QRectF(32, 10, 150, 75);
        return QRectF(m_objRect);
    }

    void moveOffsetPosition(double pOffsetPostion)
    {
        m_nOffsetPointer = pOffsetPostion;
    }

    void painOffsetItem(QPainter *painter)
    {
        QPointF sourcePoint,destPoint,gndSrcPoint,gndDestPoint,horgndPoint1,horgndPoint2,horgndPoint3,horgndPoint4;
        QPointF sourceArrowP1,sourceArrowP2;
        double angle=0.0;
//        painter->setRenderHint(QPainter::Antialiasing);

        sourcePoint.setX(m_objRect.x()-10);
        destPoint.setX(m_objRect.x());
        sourcePoint.setY((m_objRect.height()/2)+ m_nOffsetPointer);
        destPoint.setY((m_objRect.height()/2) +  m_nOffsetPointer);


        gndSrcPoint.setX(m_objRect.x()-10);
        gndDestPoint.setX(m_objRect.x()-10);
        gndSrcPoint.setY((m_objRect.height()/2) + m_nOffsetPointer );
        gndDestPoint.setY((m_objRect.height()/2 +10) + m_nOffsetPointer);

        horgndPoint1.setX(m_objRect.x()-15);
        horgndPoint2.setX(m_objRect.x()-5);
        horgndPoint1.setY((m_objRect.height()/2 +10) + m_nOffsetPointer);
        horgndPoint2.setY((m_objRect.height()/2 +10) + m_nOffsetPointer);

        horgndPoint3.setX(m_objRect.x()-12);
        horgndPoint4.setX(m_objRect.x()-7);
        horgndPoint3.setY((m_objRect.height()/2 +13) + m_nOffsetPointer);
        horgndPoint4.setY((m_objRect.height()/2 +13) + m_nOffsetPointer);



        QLineF offsetline(sourcePoint, destPoint);
        painter->setBrush(QColor(255,255,0,255));
        painter->setPen(QPen(QColor(255,255,127,255), 1.0, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
        painter->drawLine(offsetline);
        QLineF groudLine(gndSrcPoint,gndDestPoint);
        QLineF horGnd1Line(horgndPoint1,horgndPoint2);
        QLineF horGnd2Line(horgndPoint3,horgndPoint4);
        painter->drawLine(groudLine);
        painter->drawLine(horGnd1Line);
        painter->drawLine(horGnd2Line);
        angle = ::acos(offsetline.dx() / offsetline.length());
        if (offsetline.dy() >= 0)
            angle = TwoPi - angle;

        qreal l_nArrowSize = 8.0;
        sourceArrowP1 = sourcePoint + QPointF(sin(angle + Pi / 3) * l_nArrowSize,cos(angle +Pi / 3) * l_nArrowSize);
        sourceArrowP2 = sourcePoint + QPointF(sin(angle + Pi - Pi / 3) * l_nArrowSize,cos(angle + Pi - Pi / 3) * l_nArrowSize);
        painter->drawPolygon(QPolygonF() << offsetline.p2() << sourceArrowP1 << sourceArrowP2);

    }

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
    {
        Q_UNUSED(option);
        Q_UNUSED(widget);
      //  if(m_nPaintFlag)
     //   {
       // 	qDebug()<<"Paint Offset Once";
        	painOffsetItem(painter);
        	m_nPainter=painter;
        //	m_nPaintFlag=false;
      //  }

    }

    void setPointerValue(double pValue, QRectF pRect)
    {
        m_nOffsetPointer = pValue;
        m_objRect = pRect;
    }

protected:
    double m_nOffsetPointer;
    QRectF m_objRect;
    QPainter *m_nPainter;
    bool m_nPaintFlag;
//    void mousePressEvent(QGraphicsSceneMouseEvent *event)
//       {
//           QGraphicsItem::mousePressEvent(event);
//           update();
//       }
//
//       void mouseMoveEvent(QGraphicsSceneMouseEvent *event)
//       {
//    	   event->ignore();
//       }
//
//       void mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
//       {
//           QGraphicsItem::mouseReleaseEvent(event);
//           update();
//       }
};

class DSOXYChannelItem:public QGraphicsItem
{
public:
    DSOXYChannelItem(QGraphicsItem *parent=0):QGraphicsItem(parent)
    {
    	m_nOffset=0.0;
    	m_bHideFlag=false;
    	m_nPaintFlag =true;
    	m_nSamplePerPixel=1.0;
    	//installSceneEventFilter(this);
    	setCacheMode(QGraphicsItem::DeviceCoordinateCache);
    }

//    bool sceneEventFilter ( QGraphicsItem * watched, QEvent * event )
//	{
//    	if(event->type() == QEvent::MouseMove)
//    	{
//    		qDebug()<<"Mouse Move Event Filter";
//    		return true;
//    	}
//	}
    void setSamplesPerPixel(double pCount)
    {
    	m_nSamplePerPixel = pCount;
    }
    QRectF boundingRect() const
    {
        //return QRectF(32, 10, 150, 75);
        return QRectF(m_objRect);
    }
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
    {

        //qDebug()<<"Inside DSOXYChannelItem"<<sizeof(*this);
        Q_UNUSED(option);
        Q_UNUSED(widget);
        //if(m_nPaintFlag)
        //{
      //  	qDebug()<<"Inside DSOXYChannelItem Once";

        	constructXYPolyData(painter);
	//		m_nPainter = painter;
		//	m_nPaintFlag=false;
        //}
    }

    void clearChannelData()
    {
        m_objData.clear();
    }

    void HideChannelItem(bool isHideFlag)
    {
    	m_bHideFlag=isHideFlag;
    }


    void constructXYPolyData(QPainter *painter)
    {
    	if(m_objCH1Data.count()==0) return;
        QPen pen;
        QBrush polyBrush;
        polyBrush.setStyle(Qt::SolidPattern);
        pen.setWidthF(1.0);
        pen.setStyle(Qt::SolidLine);
        pen.setJoinStyle(Qt::RoundJoin);
        pen.setBrush(QColor(88,88,87,255));
        painter->setPen(pen);
        QPainterPath path;

       // painter->setRenderHint(QPainter::Antialiasing);

        int l_nOffsetMargin=dsoMargin;
        static const QColor colorForIds[8] = {Qt::red,Qt::green,Qt::cyan,Qt::magenta,Qt::yellow,Qt::white,Qt::gray,Qt::black};
        QRectF rect(l_nOffsetMargin,l_nOffsetMargin,m_objRect.width()-(2*l_nOffsetMargin),m_objRect.height()-(2*l_nOffsetMargin));
        double y =0.0,x=0.0,dx=0.0,dy=0.0;
        painter->setClipRect(rect.adjusted(+1,+1,-1,-1));
        int index=0;
        double l_nOffset=-0.1;
        double l_nIncX=0.0;
        unsigned short l_nDrawindex=0;
        bool l_bLessWidth=false;
        double dxFactor = 1.0;//(rect.width())/(m_objChannelData.count());
        QPolygonF polyline1(1);
        m_nSamplePerPixel = (double)floor((double)m_nSamples/(double)rect.width());
        if(m_nSamplePerPixel <=1)
        {
        	dxFactor = (rect.width())/(m_objCH1Data.count());
        	polyline1.resize(m_objCH1Data.count());
        	l_bLessWidth = true;
        }
		if(m_eChannel == CHANNEL1 && m_bHideFlag==false){
			painter->setPen(colorForIds[4]);
		}
		else if(m_eChannel == CHANNEL2&& m_bHideFlag==false){
			painter->setPen(colorForIds[3]);
		}
		else if(m_eChannel == CHANNEL3&& m_bHideFlag==false)
		{
			painter->setPen(colorForIds[0]);
		}
		else if(m_eChannel == CHANNEL4&& m_bHideFlag==false){
			painter->setPen(colorForIds[1]);
		}
		else{
			painter->setPen(Qt::NoPen);
			return;
		}
	   if(m_eSamplesType==MIN_MAX )
	   {
		   m_nSamplePerPixel=2.0;
		   //l_bLessWidth=true;
	   }
	   else if (m_eSamplesType==AVERAGE)
	   {
		   m_nSamplePerPixel=1.0;
		   l_bLessWidth=true;
	   }
	   else if( m_eSamplesType == MOVING_AVERAGE)
	   {
//		   m_nSamplePerPixel = m_objCH1Data.count()/rect.width();
		 //  m_nSamplePerPixel = (double)floor((double)m_nSamples/(double)rect.width());
	   }

		if(m_nSamples<rect.width())
		{
			dxFactor = rect.width()/m_nSamples;
		}
		if(m_eSamplesType == LINEAR_INTERPOLATION || m_eSamplesType == MOVING_LINEAR)
				m_nSamplePerPixel = m_nSamplePerPixel*2.0;
		//qDebug()<<"Samples Per Pixel:"<<m_nSamplePerPixel;

		double l_nMulFactor=1.0;
		if(m_eSamplesType == NORMAL || m_eSamplesType == MIN_MAX || m_eSamplesType == AVERAGE){
        	dxFactor = 1.0;
        	l_bLessWidth = true;
        	l_nMulFactor = m_nPreCount/((m_nPreCount+m_nPostCount) / 10.0);
        	//qDebug()<<"MulFactor:"<<l_nMulFactor<<"PreCount:"<<m_nPreCount<<m_nPostCount;
        	m_nPreCount = ((rect.width()/10.0) * ((l_nMulFactor)));
        	//qDebug()<<"Cal PreCount:"<<m_nPreCount;
        	m_nSamplePerPixel=1.0;
    		if(m_nSamples<rect.width())
    		{
    			dxFactor = rect.width()/m_nSamples;
    		}

		}
		unsigned int l_nTempIndex=m_nSamplePerPixel;
		//qDebug()<<"PreCount:"<<m_nPreCount<<"PostCount:"<<m_nPostCount;
        qDebug()<<"Dx Factor:"<<dxFactor<<m_objCH1Data.count()<<m_nSamplePerPixel<<m_nSamples<<m_eSamplesType;
		//qDebug()<<"Span Y:"<<m_objPlotSettings->spanY()<<m_eChannel<<m_nValue;
        if(l_bLessWidth == true)
    		for(int l_nDataIndex=0; l_nDataIndex< m_objCH1Data.count();l_nDataIndex++)
    		{
    			QList<double> dy;
    			QPolygonF polyline(2);
    			double dx = (rect.left()+ l_nIncX);
   				dy = m_objCH1Data.value(l_nDataIndex);
   				if(l_nDataIndex<(m_nPreCount))
   				{
   					painter->setPen(colorForIds[3]);
   				}
   				else
   				{
   					painter->setPen(colorForIds[4]);
   				}
    			double y = ((rect.height()/2) - ((dy.value(0)+(m_objPlotSettings->m_nOffsetPointer+l_nOffset))*((rect.height()-1))/(m_nValue)));
    			polyline[0]=QPointF(dx,y);
    			l_nIncX = l_nIncX + dxFactor;
    			dx = (rect.left()+ l_nIncX);
    			dy.clear();
    			dy = m_objCH1Data.value(l_nDataIndex+1);
    			y = ((rect.height()/2) - ((dy.value(0)+(m_objPlotSettings->m_nOffsetPointer+l_nOffset))*((rect.height()-1))/(m_nValue)));
    			polyline[1]=QPointF(dx,y);
    			//l_nIncX = l_nIncX + dxFactor;
    			painter->drawPolyline(polyline);
    		}
        else
    		for(int l_nDataIndex=0; l_nDataIndex< m_objCH1Data.count();l_nDataIndex++)
    		{
    			QList<double> l_nlstValues;
    			QPolygonF polyline(m_nSamplePerPixel);
    			//if(m_eChannel == CHANNEL1)
    			l_nlstValues = m_objCH1Data.value(l_nDataIndex);
    			dx = (rect.left()+ l_nIncX);
   				if((l_nTempIndex)<m_nPreCount)
   				{
   					painter->setPen(colorForIds[3]);
   					//qDebug()<<"Check Count:"<<l_nTempIndex;
   				}
   				else
   				{
   					painter->setPen(colorForIds[4]);
   				}
   				l_nTempIndex+=m_nSamplePerPixel;
    			// qDebug()<<dx<<l_nIn
    			 for(int l_nlstIndex=0;l_nlstIndex<l_nlstValues.count();l_nlstIndex++)
    			 {
    					 dy = l_nlstValues.value(l_nlstIndex);
    					 y = ((rect.height()/2) - ((dy+(m_objPlotSettings->m_nOffsetPointer+l_nOffset))*((rect.height()-1))/(m_nValue)));
    					 //qDebug()<<"X Value:"<<dx<<"Y Value:"<<y;
    					 if(l_bLessWidth == false)
    						 polyline[l_nlstIndex]=QPointF(dx,y);
    					 else if(l_bLessWidth== true){
    						 polyline1[l_nDrawindex++] = QPointF(dx,y);
    					 }
    	//                	 //painter->drawPolyline(polyline1);
    	//                 }
    					//	 polyline1[l_nDrawindex++] = QPointF(dx,y);
    					 //painter->drawPoint(dx,y);

    			 }
    			 if(l_nDataIndex>0)
    			 {
    				 QPolygonF tepolyline(2);
    				 dy=m_objCH1Data.value(l_nDataIndex-1).value(m_nSamplePerPixel-1);
					 y = ((rect.height()/2) - ((dy+(m_objPlotSettings->m_nOffsetPointer+l_nOffset))*((rect.height()-1))/(m_nValue)));
					 tepolyline[0] = QPointF(polyline[0].x()-dxFactor,y);
					 tepolyline[1] = polyline[0];
					 painter->drawPolyline(tepolyline);
    			 }
    			 if(l_bLessWidth == false){
    				// path.addPolygon(polyline);
    				// painter->fillPath(path,polyBrush);
    				 painter->drawPolyline(polyline);
    				 //painter->drawPolygon(polyline);

    			 }
    			 l_nIncX = l_nIncX + dxFactor;
    			 //l_nDrawindex=0;
    		}


    }


    void constructXYData(QPainter *painter)
    {
    	//qDebug()<<"Hide Flag:"<<m_bHideFlag;
        QPen pen;

		pen.setWidthF(1.0);
		pen.setStyle(Qt::SolidLine);
		pen.setBrush(QColor(88,88,87,255));
		painter->setPen(pen);
		//painter->setRenderHint(QPainter::Antialiasing);

        int l_nOffsetMargin=dsoMargin;
        static const QColor colorForIds[8] = {Qt::red,Qt::green,Qt::cyan,Qt::magenta,Qt::yellow,Qt::white,Qt::gray,Qt::black};
        QRectF rect(l_nOffsetMargin,l_nOffsetMargin,m_objRect.width()-(2*l_nOffsetMargin),m_objRect.height()-(2*l_nOffsetMargin));
        double y =0.0,x=0.0,dx=0.0,dy=0.0;
        painter->setClipRect(rect.adjusted(+1,+1,-1,-1));
        //int l_nCounter=0;
        QPolygonF polyline(m_objData.count());
      //  qDebug() << "Plotting Count:"<<m_objData.count();
        //qDebug()<<"Channel Offset:"<<m_nOffset;
        double dxFactor = (rect.width())/(m_objData.count());
        double l_nIncX=0.0;
       // qDebug()<<"Pixel Factor:"<<dxFactor<<"Rect Width():"<<rect.width();

        for(int l_nDataIndex=0; l_nDataIndex< m_objData.count();l_nDataIndex++)
        {
             dx = m_objData[l_nDataIndex].x();
             dy = m_objData[l_nDataIndex].y();
             //x = (m_objRect.left()+ ((dx)*(((m_objRect.width()-1)))/(m_objPlotSettings->spanX())));
             x = (rect.left()+ l_nIncX);
             y = ((rect.height()/2) - ((dy+(m_objPlotSettings->m_nOffsetPointer+m_nOffset))*((rect.height()-1))/(m_objPlotSettings->spanY())));
             l_nIncX = l_nIncX + dxFactor;
//             if(( m_objData[l_nDataIndex].x()>=m_objPlotSettings->minTimeDivision && m_objData[l_nDataIndex].x()<=m_objPlotSettings->maxTimeDivision)&&(( m_objData[l_nDataIndex].y()>=m_objPlotSettings->minVoltageDivision && m_objData[l_nDataIndex].y()<=m_objPlotSettings->maxVoltageDivsion)))
//             {
//                  polyline[l_nDataIndex] = QPointF(x,y);
//             }

             polyline[l_nDataIndex] = QPointF(x,y);
         }
     //   qDebug()<<"Inside Channel Plotting";

		if(m_eChannel == CHANNEL1 && m_bHideFlag==false)
			painter->setPen(colorForIds[4]);
		else if(m_eChannel == CHANNEL2&& m_bHideFlag==false)
			painter->setPen(colorForIds[3]);
		else if(m_eChannel == CHANNEL3&& m_bHideFlag==false)
			painter->setPen(colorForIds[0]);
		else if(m_eChannel == CHANNEL4&& m_bHideFlag==false)
			painter->setPen(colorForIds[1]);
		else
			painter->setPen(Qt::NoPen);
        painter->drawPolyline(polyline);
    }

    void setVectorData(QVector<QPointF> pObjData)
    {
    	m_objData.clear();
        m_objData = pObjData;
    }

    void setChannelVectorData( QMap<int,QList<double> > pobjData,DSO_CHANNEL pChannel)
    {
    	m_objCH1Data.clear();
   		m_objCH1Data = pobjData;
   		update(m_objRect);
   		//qDebug()<<"View Data:"<<m_objCH1Data.count();
    }
    void setSpanData(double pValue)
    {
   		m_nValue = pValue;
    	//qDebug()<<"MValue:"<<m_nValue;

    }
    void setChannel(DSO_CHANNEL pChannel)
    {
    	m_eChannel = pChannel;
    }
    void moveChannelOffset(double pOffset)
    {
    	m_nOffset=pOffset;
    }

    void setPrePostCount(unsigned int pPostCount,unsigned int pPreCount)
    {
    	m_nPostCount= pPostCount;
    	m_nPreCount = pPreCount;
    //	qDebug()<<"Pre Post Count:"<<m_nPostCount<<m_nPreCount;
    }
    void setPointerValue( QRectF pRect,PlotXYSettings *pSettings=0)
    {
        m_objRect = pRect;
       	m_objPlotSettings = pSettings;
    }

    void setSamplesCount(unsigned int pSamples,SAMPLING_TYPE pSamplesType)
    {
    	m_nSamples=pSamples;
    	m_eSamplesType = pSamplesType;
    }
   void mouseMoveEvent( QGraphicsSceneMouseEvent* event )
    {
      //  qDebug("move");

    }
protected:
    QRectF m_objRect;
    double m_nValue;
    PlotXYSettings* m_objPlotSettings,*m_objPlotSettingsCH2;
    QVector<QPointF> m_objData;
    QMap<int,QList<double> > m_objCH1Data;
    DSO_CHANNEL m_eChannel;
    double m_nOffset;
    bool m_bHideFlag;
    QPainter *m_nPainter;
    bool m_nPaintFlag;
    double m_nSamplePerPixel;
    unsigned int m_nSamples;
    SAMPLING_TYPE m_eSamplesType;
    unsigned int m_nPreCount,m_nPostCount;
//    void mousePressEvent(QGraphicsSceneMouseEvent *event)
//       {
//           QGraphicsItem::mousePressEvent(event);
//           update();
//       }
//
//       void mouseMoveEvent(QGraphicsSceneMouseEvent *event)
//       {
//    	   event->ignore();
//       }
//
//       void mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
//       {
//           QGraphicsItem::mouseReleaseEvent(event);
//           update();
//       }
};

class DSOXYPlane:public QGraphicsItem
{
public:
    DSOXYPlane(QGraphicsItem *parent=0):QGraphicsItem(parent)
    {
    	m_nPaintFlag = true;
    //	qDebug()<<"DSOXYPlane";

    	//prepareGeometryChange();
    }

    virtual QRectF boundingRect() const
    {
        return QRectF(m_objRect.x(), m_objRect.y(), m_objRect.width(), m_objRect.height());
    }

    void paintDSOPlane(QPainter *painter)
    {
        QPen pen;
        pen.setWidthF(1.0);
        pen.setStyle(Qt::SolidLine);
        pen.setBrush(QColor(88,88,87,255));
        painter->setPen(pen);
        constructDSOXYAxes(painter);

    }

    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
    {
        Q_UNUSED(option);
        Q_UNUSED(widget);
     //   m_nPainter=painter;
    	//if(m_nPaintFlag)
    	//{
    	//	qDebug()<<"Inside DSO XY Once";
    		paintDSOPlane(painter);
    	//	m_nPainter=painter;
    		//m_nPaintFlag=false;
    	//}
    }
    void setPointerValue( QRectF pRect,PlotXYSettings *pSettings=0)
    {
        m_objRect = pRect;
        m_objPlotSettings = pSettings;
    }



    void constructDSOXYAxes(QPainter *painter)
    {
    	double offsetMargin=dsoMargin;
        QPen pen;
        QColor objColor(88,88,87,255);
        pen.setColor(objColor);
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
	pen.setWidthF(1.0);
	pen.setStyle(Qt::SolidLine);
}

    void constructXYGridPlane(QPainter *painter)
    {
        QColor objColor(88,88,87,255);
        QPen pen;
        pen.setWidthF(0.2);
        pen.setStyle(Qt::DotLine);
        pen.setColor(objColor);
        
        for(int i=0;i<m_objPlotSettings->numXDivisions;i++)
        {
            int x = m_objRect.left() + (i * (m_objRect.width()) / m_objPlotSettings->numXDivisions);
            if( i !=0 && i!=m_objPlotSettings->numXDivisions/2){

            	painter->drawLine(x,m_objRect.top(),x,m_objRect.height());
            }

        }

        for(int i=0;i<m_objPlotSettings->numYDivisions;i++)
        {
            int y = m_objRect.bottom() - (i * (m_objRect.height()) / m_objPlotSettings->numYDivisions);
            if( i !=0 && i!=m_objPlotSettings->numYDivisions/2)
            {
                painter->drawLine(m_objRect.left(),y,m_objRect.width(),y);
            }
        }
    }

    void setPlotsettings(PlotXYSettings *pSettings=0)
    {
        m_objPlotSettings = pSettings;
    }
    void construcXYDivisions (QPainter *painter)
    {
        //Q_UNUSED(pSettings)
        QPen pen;
        pen.setStyle(Qt::SolidLine);
        double l_nSpaceMargin=12.0;

        int l_nHWidth = m_objRect.left() + ((m_objRect.width()-l_nSpaceMargin) / (m_objPlotSettings->numXDivisions));
       // qDebug() << "Horizontal Width:"<<l_nHWidth;
        for(int i=0;i<m_objPlotSettings->numXDivisions;i++)
        {
            int x = m_objRect.left() + (i*(m_objRect.width()-l_nSpaceMargin) / (m_objPlotSettings->numXDivisions));
            for(int j=0;j<5;j++){
                int y= m_objRect.left() +(j*(l_nHWidth/5));
                if(j!=0)
                    painter->drawLine(x+y,m_objRect.height()/2-2,x+y,m_objRect.height()/2+2);
            }
        }

        int l_nVWidth = ((m_objRect.height()) / m_objPlotSettings->numYDivisions);
       // qDebug() << "Vertical Width:"<<l_nVWidth;
        for(int i=0;i<m_objPlotSettings->numYDivisions;i++)
        {
            int x = m_objRect.bottom() - (i * (m_objRect.height()/m_objPlotSettings->numYDivisions));
            //qDebug() <<"X:"<<x;
            for(int j=0;j<5;j++)
            {
                int y= (j*(l_nVWidth/5));
               // qDebug()<<"Y:"<<y;
                if(j!=0)
                    painter->drawLine(m_objRect.width()/2-2,x-y,m_objRect.width()/2+2,x-y);

            }
        }
    }

protected:
    QRectF m_objRect;
    PlotXYSettings* m_objPlotSettings;
    QPainter *m_nPainter;
    bool m_nPaintFlag;
//    void mousePressEvent(QGraphicsSceneMouseEvent *event)
//       {
//           QGraphicsItem::mousePressEvent(event);
//           update();
//       }
//
//       void mouseMoveEvent(QGraphicsSceneMouseEvent *event)
//       {
//    	   event->ignore();
//       }
//
//       void mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
//       {
//           QGraphicsItem::mouseReleaseEvent(event);
//           update();
//       }
};



class DSOXYGridView : public QGraphicsView
{
    Q_OBJECT
public:
    DSOXYGridView(QWidget *obj=0):QGraphicsView(obj)
    {
        //setGeometry(10,10,790,600);
        //setRenderHint(QPainter::Antialiasing, false);
//        setDragMode(QGraphicsView::RubberBandDrag);
        setOptimizationFlags(QGraphicsView::DontSavePainterState);
        setViewportUpdateMode(QGraphicsView::SmartViewportUpdate);
        setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        setRenderHints(QPainter::SmoothPixmapTransform);
        setFrameStyle(QFrame::NoFrame);
        setMouseTracking(true);

    }

//    void mouseMoveEvent(QGraphicsSceneMouseEvent *event)
//    {
////		QMouseEvent event2(QEvent::MouseMove, event->pos(), Qt::NoButton, Qt::LeftButton, Qt::NoModifier);
////		QGraphicsView::mouseMoveEvent(&event2);
//    	QString string = QString("%1, %2")
//    	               .arg(event->scenePos().x())
//    	              .arg(event->scenePos().y()); // Update the cursor position text
//    	    qDebug()<<string;
//    	 //   this->update();
//    	    qDebug()<<"Hello Mouse Move";
//    }

//    void mousePressEvent(QGraphicsSceneMouseEvent *event)
//    {
//    	qDebug()<<"Hello Mouse Press";
//     //   this->update();
//    }
//    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
//    {
//    	qDebug()<<"Hello Mouse Release";
//       // this->update();
//    }
    void setDSOChannelCount(double pSamplePerPixel)
    {
    	m_objDSOChannelData->setSamplesPerPixel(pSamplePerPixel);
    }

    void initialiseGridScene()
    {
        pen.setWidthF(1.0);
        pen.setStyle(Qt::SolidLine);
        pen.setBrush(QColor(88,88,87,255));
        m_objGridscene=  new QGraphicsScene(this);
        m_objDSOXYPlane = new DSOXYPlane();
        m_objOffsetPointer = new OffsetItem();
        m_objTriggers = new TriggerItem();
        m_objVCursors = new VCursorsItem();
        m_objVCursors1 = new VCursorsItem();
        m_objHCursors = new HCursorsItem();
        m_objHCursors1 = new HCursorsItem();
        m_objDSOChannelData = new DSOXYChannelItem();
        m_objDSOChannel2Data = new DSOXYChannelItem();
        m_objDSOChannel3Data = new DSOXYChannelItem();
        m_objDSOChannel4Data = new DSOXYChannelItem();
       // m_objGridscene->installEventFilter(this);

    }
    void intialiseDisplayWidget()
    {
    //    m_objDisplayWidgetScene = new QGraphicsScene();
    }

    ~DSOXYGridView()
    {
        //delete this;
    }

    void udpateGridView()
    {
      //  updateScene();
      //  updateGeometry();
    //	QList<QGraphicsItem*> objItems = m_objGridscene->items();
    //	objItems.value(0)->
    }

    void setBorderRect(double pX,double pY,double pWidth,double pHeigth)
    {
        double Margin=dsoMargin;
        //m_objPlotSettings = pSettings;
        setGeometry(pX,pY,pWidth,pHeigth);
        m_objBorderRect.setX(pX+Margin);
        m_objBorderRect.setY(pY+Margin);
        m_objBorderRect.setHeight(pHeigth-(2*Margin));
        m_objBorderRect.setWidth(pWidth-(2*Margin));
//

       // qDebug()<<"BRect X:"<<m_objBorderRect.x();qDebug()<<"BRect Y:"<<m_objBorderRect.y();
       // qDebug()<<"BRect W:"<<m_objBorderRect.width();qDebug()<<"BRect H:"<<m_objBorderRect.height();

        m_objDSOXYPlane->setPointerValue(m_objBorderRect,m_objPlotSettings);
        m_objOffsetPointer->setPointerValue(0.0,m_objBorderRect);
        m_objHCursors->setBoundaryRect(m_objBorderRect);
        m_objHCursors1->setBoundaryRect(m_objBorderRect);
        m_objVCursors->setBoundaryRect(m_objBorderRect);
        m_objVCursors1->setBoundaryRect(m_objBorderRect);
        m_objTriggers->setBoundaryRect(m_objBorderRect);
        m_objDSOChannelData->setPointerValue(m_objBorderRect,m_objPlotSettings);
        m_objDSOChannel2Data->setPointerValue(m_objBorderRect,m_objPlotSettings);
        m_objDSOChannel3Data->setPointerValue(m_objBorderRect,m_objPlotSettings);
        m_objDSOChannel4Data->setPointerValue(m_objBorderRect,m_objPlotSettings);
        updateSceneRect(m_objBorderRect);
    	//qDebug()<<"inside dsoxygridview setBorderRect after updateSceneRect"<<pX<<" "<<pY<<" "<<pWidth<<" "<<pHeigth;
    }

    void clearVectorData()
    {
        m_objDSOChannelData->clearChannelData();
        m_objDSOChannel2Data->clearChannelData();
        m_objDSOChannel3Data->clearChannelData();
        m_objDSOChannel4Data->clearChannelData();
    }
    void setSamplesCount(unsigned int pSamples,SAMPLING_TYPE pType)
    {
    	m_objDSOChannel3Data->setSamplesCount(pSamples,pType);
    	m_objDSOChannel4Data->setSamplesCount(pSamples,pType);
    	m_objDSOChannel2Data->setSamplesCount(pSamples,pType);
    	m_objDSOChannelData->setSamplesCount(pSamples,pType);
    }
    void setChannelVectorData(QMap<int,QList<double> > pObjData,bool pOdd,bool pEven,DSO_CHANNEL pChannel)
    {
    	if(pChannel == CHANNEL1){
    		m_objDSOChannelData->setChannelVectorData(pObjData,pChannel);
    		m_objDSOChannelData->setChannel(CHANNEL1);
    	//	m_objDSOChannelData->setSpanData(m_objPlotSettings->spanY());
    	}
    	if(pChannel == CHANNEL2){
    		m_objDSOChannel2Data->setChannelVectorData(pObjData,pChannel);
    		m_objDSOChannel2Data->setChannel(CHANNEL2);
    	//	m_objDSOChannel2Data->setSpanData(m_objPlotSettings->spanY());
    	}
    	if(pChannel == CHANNEL3){
    		m_objDSOChannel3Data->setChannelVectorData(pObjData,pChannel);
    		m_objDSOChannel3Data->setChannel(CHANNEL3);
    	//	m_objDSOChannel3Data->setSpanData(m_objPlotSettings->spanY());
    	}
    	if(pChannel == CHANNEL4){
    		m_objDSOChannel4Data->setChannelVectorData(pObjData,pChannel);
    		m_objDSOChannel4Data->setChannel(CHANNEL4);
    	//	m_objDSOChannel4Data->setSpanData(m_objPlotSettings->spanY());
    	}

    }

    void setVectorData(QVector<QPointF> pObjData,bool pCH1,bool pCH2,bool pCH3,bool pCH4)
    {
    	if(pCH1==true){
    		m_objDSOChannelData->setVectorData(pObjData);
    		m_objDSOChannelData->setChannel(CHANNEL1);
    	}
    	if(pCH2==true){
    		m_objDSOChannel2Data->setVectorData(pObjData);
    		m_objDSOChannel2Data->setChannel(CHANNEL2);
    	}
    	if(pCH3==true){
    		m_objDSOChannel3Data->setVectorData(pObjData);
    		m_objDSOChannel3Data->setChannel(CHANNEL3);
    	}
    	if(pCH4==true){
    		m_objDSOChannel4Data->setVectorData(pObjData);
    		m_objDSOChannel4Data->setChannel(CHANNEL4);
    	}

    }

    void constructDSOPlane(DSOGridRect *pObj,PlotXYSettings *pSettings)
    {
        double Margin=dsoMargin;
        m_objPlotSettings = pSettings;
        setGeometry(Margin,Margin,m_objBorderRect.width(),m_objBorderRect.height());
        m_objBorderRect.setX(Margin); m_objBorderRect.setY(Margin);
        m_objBorderRect.setHeight(pObj->m_nHeight-(2*(Margin)));
        m_objBorderRect.setWidth(pObj->m_nWidth-(2*(Margin)));
        m_objGridscene->addItem(m_objDSOXYPlane);
        setSceneRect(m_objBorderRect);
        setScene(m_objGridscene);
  //      qDebug()<<"DSO Plane";
    }

    void changePlotSettings(DSO_CHANNEL pChannel,PlotXYSettings *pSettings,double pData)
    {
    	if(pChannel == CHANNEL1 || pChannel== CHANNEL2){
    		m_objPlotSettings = pSettings;
    		m_objDSOChannelData->setChannel(CHANNEL1);
            m_objDSOChannelData->setPointerValue(m_objBorderRect,m_objPlotSettings);

    	}
    	else if (pChannel == CHANNEL3 || pChannel== CHANNEL4)
    	{
    		m_objPlotSettings = pSettings;
    		m_objDSOChannelData->setChannel(CHANNEL3);
            m_objDSOChannel3Data->setPointerValue(m_objBorderRect,m_objPlotSettings);
    	}
    }

    void setSpanData(double pData,DSO_CHANNEL pChannel)
    {
    	if(pChannel == CHANNEL1 || pChannel== CHANNEL2){
    		m_objDSOChannelData->setSpanData(pData);
    		m_objDSOChannel2Data->setSpanData(pData);
    	}
    	else if (pChannel == CHANNEL3 || pChannel== CHANNEL4)
    	{
    		m_objDSOChannel3Data->setSpanData(pData);
    		m_objDSOChannel4Data->setSpanData(pData);
    	}
    }

    void setPrePostCount(unsigned int pPostCount,unsigned int pPreCount,DSO_CHANNEL pChannel)
    {
    	if(pChannel == CHANNEL1 || pChannel== CHANNEL2){
    		m_objDSOChannelData->setPrePostCount(pPostCount,pPreCount);
    		m_objDSOChannel2Data->setPrePostCount(pPostCount,pPreCount);
    	}
    	else if (pChannel == CHANNEL3 || pChannel== CHANNEL4)
    	{
    		m_objDSOChannel3Data->setPrePostCount(pPostCount,pPreCount);
    		m_objDSOChannel4Data->setPrePostCount(pPostCount,pPreCount);
    	}

    }
    double getRectWidth()
    {
    	return m_objBorderRect.width()-(2*(dsoMargin));
    }

    double getRectHeight()
    {
    	return m_objBorderRect.height()-(2*(dsoMargin));
    }

    void contructChannelData(PlotXYSettings* pSettings1,PlotXYSettings* pSettings2)
    {
    	//qDebug()<<"ch";
        m_objDSOChannelData->setPointerValue(m_objBorderRect,pSettings1);
        m_objGridscene->addItem(m_objDSOChannelData);
        m_objDSOChannel2Data->setPointerValue(m_objBorderRect,pSettings1);
        m_objGridscene->addItem(m_objDSOChannel2Data);
        m_objDSOChannel3Data->setPointerValue(m_objBorderRect,pSettings2);
        m_objGridscene->addItem(m_objDSOChannel3Data);
        m_objDSOChannel4Data->setPointerValue(m_objBorderRect,pSettings2);
        m_objGridscene->addItem(m_objDSOChannel4Data);
       // qDebug()<<"ch1";
    }

    void moveChannelOffset(DSO_CHANNEL pEChannel,double pOffset=0.0)
    {
    	if(pEChannel == CHANNEL1)
    		m_objDSOChannelData->moveChannelOffset(pOffset);
    	if(pEChannel == CHANNEL2)
    		m_objDSOChannel2Data->moveChannelOffset(pOffset);
    	else if(pEChannel == CHANNEL3)
    		m_objDSOChannel3Data->moveChannelOffset(pOffset);
    	else if(pEChannel == CHANNEL4)
    		m_objDSOChannel4Data->moveChannelOffset(pOffset);
    }

    void constructOffsetPointer()
    {
        m_objOffsetPointer->setPointerValue(0.0,m_objBorderRect);
        m_objGridscene->addItem(m_objOffsetPointer);


    }

    void constructTriggerPointers()
    {
        m_objTriggers->setBoundaryRect(m_objBorderRect);
        m_objTriggers->setTriggerOption(PT_DSO_TRIGGER_OPTIONS::TRIGGER_HORIZONTAL|PT_DSO_TRIGGER_OPTIONS::TRIGGER_VERTICAL);
        m_objTriggers->setTriggerPostion(0.0);
        m_objGridscene->addItem(m_objTriggers);

    }


    void constructVCursor()
    {
        m_objVCursors->setBoundaryRect(m_objBorderRect);
        m_objGridscene->addItem(m_objVCursors);
        m_objVCursors1->setBoundaryRect(m_objBorderRect);
        m_objGridscene->addItem(m_objVCursors1);

    }

    void constructHCursor()
    {
        m_objHCursors->setBoundaryRect(m_objBorderRect);
        m_objGridscene->addItem(m_objHCursors);
        m_objHCursors->changeDashes(true);
        m_objHCursors1->setBoundaryRect(m_objBorderRect);
        m_objGridscene->addItem(m_objHCursors1);
        m_objHCursors1->changeDashes(false);

    }


    void moveV1Cursor(double x1)
    {
        m_objVCursors->setX1Position(x1);
        m_objVCursors->changeDashes(true);
        update();


    }
    void moveV2Cursor(double x2)
    {
        m_objVCursors1->setX1Position(x2);
        m_objVCursors1->changeDashes(false);
        update();

    }

    void HideVerticalCursros(short int pValue,bool pFlag)
    {
    	if(pValue==2)
    		m_objVCursors->hideCursors(pFlag,pValue);
    	if(pValue==3)
    		m_objVCursors1->hideCursors(pFlag,pValue);
    	update();
    }

    void HideHorizontalCursor1(bool pFlag)
    {
    	m_objHCursors->hideHCursors(pFlag);
    	update();
    }
    void HideHorizontalCursor2(bool pFlag)
    {
    	m_objHCursors1->hideHCursors(pFlag);
    	update();
    }
    void HideHorizontalCursors(short int pValue,bool pFlag)
    {
    	//qDebug()<<pValue;
    	if(pValue ==0 )
    		HideHorizontalCursor1(pFlag);
    	if(pValue == 1)
    		HideHorizontalCursor2(pFlag);
    }

    void moveH1Cursor(double y1)
    {
        m_objHCursors->setY1Cursor(y1);
        m_objHCursors1->changeDashes(true);
        update();
    }

    void HideChannelData(DSO_CHANNEL pChannel,bool pFlag)
    {
    	//qDebug()<<"Channel Data:"<<pFlag;
    	if(pChannel == CHANNEL1)
    		m_objDSOChannelData->HideChannelItem(pFlag);
    	if(pChannel == CHANNEL2)
    		m_objDSOChannel2Data->HideChannelItem(pFlag);
    	if(pChannel == CHANNEL3)
    		m_objDSOChannel3Data->HideChannelItem(pFlag);
    	if(pChannel == CHANNEL4)
  		m_objDSOChannel4Data->HideChannelItem(pFlag);
    }

    void moveH2Cursor(double y2)
    {
        m_objHCursors1->setY2Cursor(y2);
        m_objHCursors1->changeDashes(false);
        update();

    }

    void moveHorizontalTriggerPointer(double pTriggerPos)
    {
        m_objTriggers->setTriggerOption(PT_DSO_TRIGGER_OPTIONS::TRIGGER_HORIZONTAL);
        m_objTriggers->setHorizontalTriggerPosition(pTriggerPos);
    }

    void moveVerticalTriggerPointer(double pTriggerPos)
    {
        m_objTriggers->setTriggerOption(PT_DSO_TRIGGER_OPTIONS::TRIGGER_VERTICAL);
        m_objTriggers->setVerticalTriggerPostion(pTriggerPos);
    }

    void moveOffsetPointer(double pOffsetPos)
    {
        m_objOffsetPointer->moveOffsetPosition(pOffsetPos);
    }



protected:
    QPen pen;
    QGraphicsScene *m_objGridscene;
    QRectF m_objBorderRect;
    OffsetItem *m_objOffsetPointer;
    TriggerItem *m_objTriggers;
    VCursorsItem *m_objVCursors;
    VCursorsItem *m_objVCursors1;
    HCursorsItem *m_objHCursors;
    HCursorsItem *m_objHCursors1;
    DSOXYPlane *m_objDSOXYPlane;

    DSOXYChannelItem *m_objDSOChannelData;
    DSOXYChannelItem *m_objDSOChannel2Data;
    DSOXYChannelItem *m_objDSOChannel3Data;
    DSOXYChannelItem *m_objDSOChannel4Data;

    PlotXYSettings* m_objPlotSettings;

private:

};
#endif // DSOXYGRIDVIEW_H
