#include "dsographicsitems.h"

DSOGraphicsItems::DSOGraphicsItems()
{
}
DSOXYPlane::DSOXYPlane(const QColor &color, int x, int y)
{
    this->setPos(x,y);
    this->color = color;
    //setZValue((x + y) % 2);
   // setFlags(ItemIsSelectable | ItemIsMovable);
    setAcceptsHoverEvents(true);
}

QRectF DSOXYPlane::boundingRect() const
{
    return m_objRect;
}

QPainterPath DSOXYPlane::shape() const
{
    QPainterPath path;
    path.addRect(14, 14, 82, 42);
    return path;
}

void DSOXYPlane::setPlotSettings(PlotXYSettings *pObjSettings)
{
    m_objPlotSettings= pObjSettings;
}

void DSOXYPlane::setBorderRect(QRectF pRect)
{
    m_objRect = pRect;

}

void DSOXYPlane::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //qDebug()<<"plot XY Grid";
    Q_UNUSED(widget);
    Q_UNUSED(option);
    double offsetMargin=dsoMargin;

    QPen pen;
    QColor objColor(88,88,87,255);
    pen.setColor(objColor);
    pen.setWidthF(1.0);
    pen.setStyle(Qt::SolidLine);
    painter->setPen(pen);
 //   qDebug()<<"ObjRect:"<<m_objRect.width();
    QRectF rect(offsetMargin,offsetMargin,m_objRect.width()-(2*offsetMargin),m_objRect.height()-(2*offsetMargin));
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
    int l_nVWidth = ((rect.height()+(2*offsetMargin)) / m_objPlotSettings->numYDivisions);
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
                painter->drawLine(((rect.width()+(2*offsetMargin))/2)-2,y-x,((rect.width()+2*offsetMargin)/2)+2,y-x);
            }
        }
    }
}

void DSOXYPlane::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mousePressEvent(event);
    update();
}

void DSOXYPlane::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->modifiers() & Qt::ShiftModifier) {
        stuff << event->pos();
        //qDebug()<<event->pos();
        update();
        return;
    }
    QGraphicsItem::mouseMoveEvent(event);
}

void DSOXYPlane::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mouseReleaseEvent(event);
    update();
}

// HCursor Item

HCursorItem::HCursorItem(const QColor &color, int x, int y)
{
    this->setPos(x,y);
    this->color = color;
    //setZValue((x + y) % 2);
    setFlags(ItemIsMovable  | QGraphicsItem::ItemIsSelectable);
    setAcceptsHoverEvents(true);
}

void HCursorItem::changeDashes(QVector<qreal>pdashes)
{
    Y1dashes = pdashes;
}

void HCursorItem::setCursorPosition(double pY1)
{
    m_nY1Position = dsoMargin+ pY1;
    update();
}

QRectF HCursorItem::boundingRect() const
{
    return m_objRect;
}

QPainterPath HCursorItem::shape() const
{
    QPainterPath path;
    path.addRect(14, 14, 82, 42);
    return path;
}

void HCursorItem::setBorderRect(QRectF pRect)
{
    m_objRect = pRect;

}

void HCursorItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);
    Q_UNUSED(option);
    double l_nOffsetMargin=dsoMargin;
    QColor fillColor = (option->state & QStyle::State_Selected) ? color.dark(150) : color;
       if (option->state & QStyle::State_MouseOver)
           fillColor = fillColor.light(125);

    QPointF sourceY1Point,destY1Point;
    QPen pen;

    //qreal space = 6;
//    if( m_bDashes == true)
//    {

//    }
    //if( m_bDashes == false){
       // Y1dashes << 18 << space <<8<<space<<2;
//        pen.setDashOffset(8);
    //}
    pen.setBrush(QColor(255,255,255,255));
    pen.setColor(QColor(255,255,255,255));
    pen.setWidthF(1.0);
    pen.setCapStyle(Qt::SquareCap);
    pen.setJoinStyle(Qt::MiterJoin);
//    if( m_hideHCursors !=true){
        pen.setDashOffset(4);
        pen.setDashPattern(Y1dashes);
        painter->setPen(pen);
  //  }
   // else
    //    painter->setPen(Qt::NoPen);

    sourceY1Point.setX(m_objRect.x()+l_nOffsetMargin);
    sourceY1Point.setY(m_objRect.top()+m_nY1Position);
    destY1Point.setX(m_objRect.width()-l_nOffsetMargin);
    destY1Point.setY(m_objRect.top()+m_nY1Position);
    QLineF HY1Cursor(sourceY1Point,destY1Point);

    painter->drawLine(HY1Cursor);
}

void HCursorItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mousePressEvent(event);
    qDebug()<<"HCurson Got Selected";
    update();
}

void HCursorItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->modifiers() & Qt::ShiftModifier) {
        stuff << event->pos();
        //qDebug()<<event->pos();
        update();
        return;
    }
    QGraphicsItem::mouseMoveEvent(event);
}

void HCursorItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mouseReleaseEvent(event);
    update();
}
//-----------------------------------

// VCursor Item

VCursorItem::VCursorItem(const QColor &color, int x, int y)
{
    this->setPos(x,y);
    this->color = color;
    //setZValue((x + y) % 2);
    //m_strTextItem.setParentItem(this);
    setFlags(ItemIsSelectable | ItemIsMovable);
    setAcceptsHoverEvents(true);
}

void VCursorItem::changeDashes(QVector<qreal>pdashes)
{
    X1dashes = pdashes;
}

void VCursorItem::setCursorPosition(double pX)
{
    m_nXPosition = dsoMargin+ pX;
    update();
}

void VCursorItem::setTitleText(QString pStrTitleText)
{
	m_strText = pStrTitleText;
}

void VCursorItem::setTextPostion(int pX,int pY)
{
	m_strTextItem.setPos(pX,pY);
}

QRectF VCursorItem::boundingRect() const
{
    return m_objRect;
}

QPainterPath VCursorItem::shape() const
{
    QPainterPath path;
    path.addRect(14, 14, 82, 42);
    return path;
}

void VCursorItem::setBorderRect(QRectF pRect)
{
    m_objRect = pRect;

}

void VCursorItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);
    Q_UNUSED(option);
    double l_nOffsetMargin=dsoMargin;
    QPen pen;
    QPointF sourceX1Point,destX1Point;

//    if( m_bDashes == true)
//    {

//    }
    //if( m_bDashes == false){
       // Y1dashes << 18 << space <<8<<space<<2;
//        pen.setDashOffset(8);
    //}
    //m_strTextItem.setPos(m_objRect.top()+m_nXPosition,m_objRect.height()/4);
//    m_strTextItem.setPlainText(m_strText);
//    m_strTextItem.setDefaultTextColor(Qt::yellow);
//    m_strTextItem.setFont(QFont("Times", 14, QFont::Bold));
    pen.setBrush(QColor(255,255,255,255));
    pen.setColor(QColor(255,255,255,255));
    pen.setWidthF(1.0);
    pen.setCapStyle(Qt::SquareCap);
    pen.setJoinStyle(Qt::MiterJoin);

//    if( m_hideHCursors !=true){
        pen.setDashOffset(4);
        pen.setDashPattern(X1dashes);
        painter->setPen(pen);
  //  }
   // else
    //    painter->setPen(Qt::NoPen);

    sourceX1Point.setX(m_objRect.top()+m_nXPosition);
    sourceX1Point.setY(m_objRect.top()+l_nOffsetMargin);
    destX1Point.setX(m_objRect.top()+m_nXPosition);
    destX1Point.setY(m_objRect.height()-l_nOffsetMargin);
    QLineF VXCursor(sourceX1Point,destX1Point);
    painter->drawLine(VXCursor);
}

void VCursorItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mousePressEvent(event);
    update();
}

void VCursorItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->modifiers() & Qt::ShiftModifier) {
        stuff << event->pos();
        //qDebug()<<event->pos();
        update();
        return;
    }
    QGraphicsItem::mouseMoveEvent(event);
}

void VCursorItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mouseReleaseEvent(event);
    update();
}
//---------------------------------------------------------------

// Vertical Trigger Item--
VTriggerItem::VTriggerItem(const QColor &color, int x, int y)
{
    this->setPos(x,y);
    this->color = color;
    //setZValue((x + y) % 2);
    setFlags(ItemIsSelectable | ItemIsMovable);
    setAcceptsHoverEvents(true);
}

QRectF VTriggerItem::boundingRect() const
{
    return m_objRect;
}

void VTriggerItem::changeColor(QColor pColor)
{
	color = pColor;
	update();
}
QPainterPath VTriggerItem::shape() const
{
    QPainterPath path;
    path.addRect(14, 14, 82, 42);
    return path;
}

void VTriggerItem::setBorderRect(QRectF pRect)
{
    m_objRect = pRect;

}

void VTriggerItem::setTriggerPostion(double pTrigger)
{
    m_nTriggerPos = pTrigger;
}

void VTriggerItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);
    Q_UNUSED(option);
    double l_nOffsetMargin=dsoMargin;
    QPen pen;
    pen.setColor(color);
    painter->setPen(pen);

    QPointF sourcePoint,destPoint;
    QPointF sourceArrowP1,sourceArrowP2;
    double angle=0.0;
    if( (((m_objRect.height()-l_nOffsetMargin)/2) +(m_nTriggerPos)) > (m_objRect.height()))
    {
    	return;
    }
    sourcePoint.setX(m_objRect.width()-l_nOffsetMargin);
    destPoint.setX(m_objRect.width());
    sourcePoint.setY((m_objRect.height()/2) +m_nTriggerPos );
    destPoint.setY((m_objRect.height()/2)+m_nTriggerPos);
    QLineF horizontalLine (sourcePoint,destPoint);
    QLineF triggerLine(QPointF(sourcePoint.x()-10,sourcePoint.y()),QPointF(destPoint.x()-m_objRect.width()-l_nOffsetMargin,destPoint.y()));
    painter->setPen(QPen(Qt::lightGray, 1.0, Qt::DotLine, Qt::RoundCap, Qt::RoundJoin));
    painter->setBrush(color);
    painter->setPen(QPen(color, 1.0, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));

    angle = ::acos(horizontalLine.dx() / horizontalLine.length());
    if (horizontalLine.dy() >= 0)
        angle = TwoPi - angle;

    qreal l_nArrowSize = 8.0;
    sourceArrowP1 = sourcePoint + QPointF(sin(angle + Pi / 3) * l_nArrowSize,cos(angle +Pi / 3) * l_nArrowSize);
    sourceArrowP2 = sourcePoint + QPointF(sin(angle + Pi - Pi / 3) * l_nArrowSize,cos(angle + Pi - Pi / 3) * l_nArrowSize);
    painter->drawPolygon(QPolygonF() << horizontalLine.p1() << sourceArrowP1 << sourceArrowP2);
}

void VTriggerItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mousePressEvent(event);
    update();
}

void VTriggerItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->modifiers() & Qt::ShiftModifier) {
        stuff << event->pos();
        //qDebug()<<event->pos();
        update();
        return;
    }
    QGraphicsItem::mouseMoveEvent(event);
}

void VTriggerItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mouseReleaseEvent(event);
    update();
}


// Horizontal Trigger Item--
HTriggerItem::HTriggerItem(const QColor &color, int x, int y)
{
    this->setPos(x,y);
    this->color = color;
    //setZValue((x + y) % 2);
    setFlags(ItemIsSelectable | ItemIsMovable);
    setAcceptsHoverEvents(true);
}

QRectF HTriggerItem::boundingRect() const
{
    return m_objRect;
}

void HTriggerItem::changeColor(QColor pColor)
{
	color = pColor;
	update();
}
QPainterPath HTriggerItem::shape() const
{
    QPainterPath path;
    path.addRect(14, 14, 82, 42);
    return path;
}

void HTriggerItem::setBorderRect(QRectF pRect)
{
    m_objRect = pRect;

}

void HTriggerItem::setTriggerPostion(double pTrigger)
{
    m_nTriggerPos = pTrigger;
    update();
}

void HTriggerItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);
    Q_UNUSED(option);
    double l_nOffsetMargin=dsoMargin;
    qreal l_nArrowSize = 8.0;
    QPen pen;
    pen.setColor(color);
    painter->setPen(pen);
    QPointF sourceHorPoint,destHorPoint;
    QPointF sourceHArrowP1,sourceHArrowP2;
    double angle=0.0;
    sourceHorPoint.setX(((m_objRect.width())/2)+m_nTriggerPos);
    destHorPoint.setX(((m_objRect.width())/2)+m_nTriggerPos);

    sourceHorPoint.setY(m_objRect.height()-l_nOffsetMargin);
    destHorPoint.setY(m_objRect.height());

    painter->setPen(QPen(Qt::lightGray, 1.0, Qt::DotLine, Qt::RoundCap, Qt::RoundJoin));
    painter->setBrush(color);
    painter->setPen(QPen(color, 1.0, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));

    QLineF verticalLine(sourceHorPoint,destHorPoint);
    angle = ::acos(verticalLine.dx() / verticalLine.length());
    if (verticalLine.dy() >= 0)
        angle = TwoPi - angle;
    sourceHArrowP1 = destHorPoint + QPointF(sin(angle - Pi / 3) * l_nArrowSize,cos(angle -Pi / 3) * l_nArrowSize);
    sourceHArrowP2 = destHorPoint + QPointF(sin(angle - Pi + Pi / 3) * l_nArrowSize,cos(angle - Pi + Pi / 3) * l_nArrowSize);
    painter->drawPolygon(QPolygonF() << verticalLine.p1() << sourceHArrowP1 << sourceHArrowP2);
}

void HTriggerItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mousePressEvent(event);
    update();
}

void HTriggerItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->modifiers() & Qt::ShiftModifier) {
        stuff << event->pos();
        //qDebug()<<event->pos();
        update();
        return;
    }
    QGraphicsItem::mouseMoveEvent(event);
}

void HTriggerItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
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

double channelItem::getOffsetPostion()
{
	return m_objPlotSettings->m_nOffsetPointer;
}

void channelItem::moveOffsetPostion(double pOffsetPos)
{
	m_objPlotSettings->m_nOffsetPointer = pOffsetPos;
	update();
}

void channelItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
 //   qDebug()<<"plot Channel Item"<<m_objCH1Data.count();
    Q_UNUSED(widget);
    Q_UNUSED(option);
    double offsetMargin=dsoMargin;
    double  m_nSamplePerPixel=0;
    QPen pen;
    //QColor objColor(255,0,0,255);
    pen.setColor(color);
    pen.setWidthF(1.0);
    pen.setStyle(Qt::SolidLine);
    painter->setPen(pen);
    //QRectF rect(l_nOffsetMargin,l_nOffsetMargin,m_objRect.width()-(2*l_nOffsetMargin),m_objRect.height()-(2*l_nOffsetMargin));
    QRectF rect(offsetMargin,offsetMargin,m_objRect.width()-(2*offsetMargin),m_objRect.height()-(2*offsetMargin));
    double y =0.0,x=0.0,dx=0.0,dy=0.0;
    painter->setClipRect(rect.adjusted(+1,+1,-1,-1));

    double dxFactor = 1.0;
    double l_nIncX=0.0;
    painter->setPen(pen);
    m_nSamplePerPixel = (double)floor((double)m_nSamples/(double)rect.width());

	if(m_eSamplesType == LINEAR_INTERPOLATION || m_eSamplesType == MOVING_LINEAR)
			m_nSamplePerPixel = m_nSamplePerPixel*2.0;
//	qDebug()<<"Samples Per Pixel:"<<m_nSamplePerPixel;

	double l_nMulFactor=1.0;
	bool l_bLessWidth=false;
	if(m_nSamplePerPixel<=0)
		m_nSamplePerPixel=1.0;

	if(m_eSamplesType == NORMAL || m_eSamplesType == MIN_MAX || m_eSamplesType == AVERAGE){
    	dxFactor = 1.0;
    	l_bLessWidth = true;
    	//l_nMulFactor = m_nPreCount/((m_nPreCount+m_nPostCount) / 10.0);
    	//m_nPreCount = ((rect.width()/10.0) * ((l_nMulFactor)));
    	m_nSamplePerPixel=1.0;

	}
	if(m_nSamples<rect.width())
	{
		dxFactor = rect.width()/m_nSamples;
	}

  //  qDebug()<<"Dx Factor:"<<dxFactor<<m_objCH1Data.count()<<m_nSamplePerPixel<<m_nSamples<<m_eSamplesType<<m_objCH1Data.value(0).count();

	//unsigned int l_nTempIndex=m_nSamplePerPixel;
	int l_nDrawindex=0;
	 if(l_bLessWidth == true)
	 {
			for(int l_nDataIndex=0; l_nDataIndex< m_objCH1Data.count();l_nDataIndex++)
			{
				//	qDebug()<<l_nDataIndex<<l_nIncX<<m_objCH1Data.value(l_nDataIndex);
					QList<double> dy;
					QPolygonF polyline(2);
					double dx = (rect.left()+ l_nIncX);
					dy = m_objCH1Data.value(l_nDataIndex);
					double y = ((rect.height()/2) - ((dy.value(0)+(m_objPlotSettings->m_nOffsetPointer))*((rect.height()-1))/(m_objPlotSettings->spanY())));
					polyline[0]=QPointF(dx,y);
					l_nIncX = l_nIncX + dxFactor;
					dx = (rect.left()+ l_nIncX);
					dy.clear();
					dy = m_objCH1Data.value(l_nDataIndex+1);
					y = ((rect.height()/2) - ((dy.value(0)+(m_objPlotSettings->m_nOffsetPointer))*((rect.height()-1))/(m_objPlotSettings->spanY())));
					polyline[1]=QPointF(dx,y);
					painter->drawPolyline(polyline);
			}
	 }
	 else
		for(int l_nDataIndex=0; l_nDataIndex< m_objCH1Data.count();l_nDataIndex++)
		{
			QList<double> l_nlstValues;
			QPolygonF polyline(m_nSamplePerPixel);
			//if(m_eChannel == CHANNEL1)
			l_nlstValues = m_objCH1Data.value(l_nDataIndex);
			dx = (rect.left()+ l_nIncX);
//				if((l_nTempIndex)<m_nPreCount)
//				{
//					painter->setPen(colorForIds[3]);
//				}
//				else
//				{
//					painter->setPen(colorForIds[4]);
//				}
//				l_nTempIndex+=m_nSamplePerPixel;
			// qDebug()<<dx<<l_nIn
			 for(int l_nlstIndex=0;l_nlstIndex<l_nlstValues.count();l_nlstIndex++)
			 {
					 dy = l_nlstValues.value(l_nlstIndex);
					 y = ((rect.height()/2) - ((dy+(m_objPlotSettings->m_nOffsetPointer))*((rect.height()-1))/(m_objPlotSettings->spanY())));
					 //qDebug()<<"X Value:"<<dx<<"Y Value:"<<y;
					 if(l_bLessWidth == false)
						 polyline[l_nlstIndex]=QPointF(dx,y);
			 }
			 if(l_nDataIndex>0)
			 {
				 QPolygonF tepolyline(2);
				 dy=m_objCH1Data.value(l_nDataIndex-1).value(m_nSamplePerPixel-1);
				 y = ((rect.height()/2) - ((dy+(m_objPlotSettings->m_nOffsetPointer))*((rect.height()-1))/(m_objPlotSettings->spanY())));
				 tepolyline[0] = QPointF(polyline[0].x()-dxFactor,y);
				 tepolyline[1] = polyline[0];
				 painter->drawPolyline(tepolyline);
			 }
			 if(l_bLessWidth == false)
			 {
				 painter->drawPolyline(polyline);
			 }
			 l_nIncX = l_nIncX + dxFactor;
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
        qDebug()<<event->pos();
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

double channelItem::getXPosition(double pValue)
{
	double offsetMargin = dsoMargin;
    QRectF rect(offsetMargin,offsetMargin,m_objRect.width()-(2*offsetMargin),m_objRect.height()-(2*offsetMargin));
    double dx = (rect.left()+ pValue);
	return dx+dsoMargin;
}

double channelItem::getYPosition(double pAmpValue)
{
	double offsetMargin = dsoMargin;
    QRectF rect(offsetMargin,offsetMargin,m_objRect.width()-(2*offsetMargin),m_objRect.height()-(2*offsetMargin));
	double y = ((rect.height()/2) - ((pAmpValue+(m_objPlotSettings->m_nOffsetPointer))*((rect.height()-1))/(m_objPlotSettings->spanY())));
	return (y-dsoMargin);
}

void channelItem::setSamplingType(SAMPLING_TYPE pType,int pSamples)
{
	m_eSamplesType = pType;
	m_nSamples = pSamples;
}

void channelItem::setSamples(int pSamples)
{
	m_nSamples = pSamples;
}
void channelItem::setPlotData(QMap<int, QList<double> > pObjData)
{
    m_objCH1Data.clear();
    m_objCH1Data = pObjData;
    update();
}


// Line Item



LineItem::LineItem(const QColor &color, int x, int y)
{
    this->setPos(x,y);
    this->color = color;
    //setZValue((x + y) % 2);
    setFlags(ItemIsMovable  | QGraphicsItem::ItemIsSelectable);
    setAcceptsHoverEvents(true);
}


QRectF LineItem::boundingRect() const
{
    return m_objRect;
}

QPainterPath LineItem::shape() const
{
    QPainterPath path;
    path.addRect(14, 14, 82, 42);
    return path;
}

void LineItem::setBorderRect(QRectF pRect)
{
    m_objRect = pRect;

}

void LineItem::setSoruceDestPoint(double pSource,double pDest)
{
	m_nSourcePoint = pSource+dsoMargin;
	m_nDestPoint = pDest+dsoMargin;
}

void LineItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);
    Q_UNUSED(option);
    double l_nOffsetMargin=dsoMargin;
    QColor fillColor = (option->state & QStyle::State_Selected) ? color.dark(150) : color;
       if (option->state & QStyle::State_MouseOver)
           fillColor = fillColor.light(125);

    QPointF sourceX1Point,destX1Point;
    QPen pen;
    pen.setBrush(QColor(255,255,255,255));
    pen.setColor(QColor(255,255,255,255));
    pen.setWidthF(1.0);
    pen.setCapStyle(Qt::SquareCap);
    pen.setJoinStyle(Qt::MiterJoin);
	pen.setDashOffset(4);
	//pen.setDashPattern(Y1dashes);
	painter->setPen(pen);
	sourceX1Point.setX(m_objRect.top()+m_nSourcePoint);
	sourceX1Point.setY(m_objRect.top()+m_nDestPoint);
	destX1Point.setX(m_objRect.top()+m_nSourcePoint);
	destX1Point.setY(m_objRect.height()/2+m_nDestPoint);
    QLineF HY1Cursor(sourceX1Point,destX1Point);
 //   qDebug()<<"QLine:"<<HY1Cursor;
    painter->drawLine(HY1Cursor);
}

void LineItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mousePressEvent(event);
    qDebug()<<"HCurson Got Selected";
    update();
}

void LineItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->modifiers() & Qt::ShiftModifier) {
        stuff << event->pos();
        //qDebug()<<event->pos();
        update();
        return;
    }
    QGraphicsItem::mouseMoveEvent(event);
}

void LineItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mouseReleaseEvent(event);
    update();
}
//-----------------------------------


// offset Item


offsetItem::offsetItem(const QColor &color, int x, int y)
{
    this->setPos(x,y);
    this->color = color;
    //setZValue((x + y) % 2);
    setFlags(ItemIsMovable  | QGraphicsItem::ItemIsSelectable);
    setAcceptsHoverEvents(true);
}


QRectF offsetItem::boundingRect() const
{
    return m_objRect;
}

QPainterPath offsetItem::shape() const
{
    QPainterPath path;
    path.addRect(14, 14, 82, 42);
    return path;
}

void offsetItem::setBorderRect(QRectF pRect)
{
    m_objRect = pRect;

}

void offsetItem::setOffsetPosition(double pOffsetPointer)
{
	m_nOffsetPointer = pOffsetPointer;
	update();
}

void offsetItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);
    Q_UNUSED(option);
    //double l_nOffsetMargin=dsoMargin;
    QColor fillColor = (option->state & QStyle::State_Selected) ? color.dark(150) : color;
       if (option->state & QStyle::State_MouseOver)
           fillColor = fillColor.light(125);

    QPointF sourceX1Point,destX1Point;
    QPen pen;
    pen.setColor(color);
    pen.setWidthF(2.0);
    pen.setCapStyle(Qt::SquareCap);
    pen.setJoinStyle(Qt::MiterJoin);
	painter->setPen(pen);
	qDebug()<<"Offset Postion:"<<m_nOffsetPointer;
	sourceX1Point.setX(m_objRect.left());
	sourceX1Point.setY((m_objRect.height()/2 )+ m_nOffsetPointer);
	destX1Point.setX(m_objRect.left()+dsoMargin);
	destX1Point.setY(m_objRect.height()/2 + m_nOffsetPointer);
    QLineF HY1Cursor(sourceX1Point,destX1Point);
 //   qDebug()<<"QLine:"<<HY1Cursor;
    painter->drawLine(HY1Cursor);
}

void offsetItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mousePressEvent(event);
    //qDebug()<<"HCurson Got Selected";
    update();
}

void offsetItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->modifiers() & Qt::ShiftModifier) {
        stuff << event->pos();
        //qDebug()<<event->pos();
        update();
        return;
    }
    QGraphicsItem::mouseMoveEvent(event);
}

void offsetItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mouseReleaseEvent(event);
    update();
}
