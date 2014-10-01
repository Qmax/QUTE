#include "plotterwidget.h"
#include <QApplication>
#include <qscreendriverplugin_qws.h>
#include <qpluginloader.h>

PlotterWidget::PlotterWidget(QWidget *parent) :
    QWidget(parent)
{
	//obj->initDevice();
	   Margin=12;
     m_nOffsetPointer=0.0;
     m_bRubberbandDrag=false;
     setBackgroundRole(QPalette::Shadow);
     setAutoFillBackground(true);
     setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
     setFocusPolicy(Qt::StrongFocus);
     curveMap.clear();
     m_bPaintFlag = true;
     m_nChannelCount=0;

}

void PlotterWidget::setChannelData(QMap<int,QList<double> > pObjData)
{
    m_objChannelData = pObjData;
}

void PlotterWidget::setChannelCount(unsigned short pCount)
{
	m_nChannelCount = pCount;
}


void PlotterWidget::setCurveData(int pID,QVector<QPointF> pData)
{
    curveMap[pID]=pData;
}

void PlotterWidget::setPlotSettings(PlotXYSettings *pObjSettings)
{
    m_objPlotSettings = pObjSettings;
}

void PlotterWidget::mouseMoveEvent(QMouseEvent *event)
{
    qDebug()<<"Mouse move";
    if( m_bRubberbandDrag == false)
        return;

}
bool PlotterWidget  ::event(QEvent *eve)
{
    if(eve->type() == QEvent::MouseMove)
    {
        QMouseEvent *me = static_cast<QMouseEvent*>(eve);
        qDebug()<<"Mouse Move Event Capture";
        return true;
    }
//    else if(eve->type() == QEvent::Paint)
//    {
//        qDebug()<<"Paint Event Capture";
//        //refreshPixmap(DRAW_GRID);
//        //return true;
//
//    }
    return QWidget::event(eve);
}


void PlotterWidget::mousePressEvent(QMouseEvent *event)
{
    if( m_bRubberbandDrag == false)
        return;

}

void PlotterWidget::mouseReleaseEvent(QMouseEvent *event)
{
    if( m_bRubberbandDrag == false)
        return;

}

void PlotterWidget::resizeEvent(QResizeEvent *event)
{
    if( m_bRubberbandDrag == false)
        return;

}

void PlotterWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QStylePainter painter(this);
    QColor l_objColor;
        painter.drawPixmap(0,0,pixmap);
    if(hasFocus())
    {
        QStyleOptionFocusRect option;
        option.initFrom(this);
        option.backgroundColor = palette().dark().color();
        painter.drawPrimitive(QStyle::PE_FrameFocusRect,option);
    }

}

void PlotterWidget::refreshPixmap(DRAW_DSO m_eDraw)
{
    qDebug()<<"Inside Refresh PixMap";
    pixmap = QPixmap(size());
    pixmap.fill(this,0,0);
    QPainter painter(&pixmap);
    painter.initFrom(this);
    drawGrid(&painter);
    drawoffsetArrow(&painter);
    //drawCurves(&painter);
    constructXYPolyData(&painter);
}
void PlotterWidget::drawoffsetArrow(QPainter *painter)
{
    QPointF sourcePoint,destPoint,gndSrcPoint,gndDestPoint,horgndPoint1,horgndPoint2,horgndPoint3,horgndPoint4;
    QPointF sourceArrowP1,sourceArrowP2;
    double angle=0.0;
    //painter->setRenderHint(QPainter::Antialiasing);
    QRectF rect(Margin,Margin,width()-2*Margin,height()-2*Margin);


    sourcePoint.setX(rect.x()-10);
    destPoint.setX(rect.x());
    sourcePoint.setY((Margin+rect.height()/2)+ m_nOffsetPointer);
    destPoint.setY((Margin+rect.height()/2) +  m_nOffsetPointer);



    gndSrcPoint.setX(rect.x()-10);
    gndDestPoint.setX(rect.x()-10);
    gndSrcPoint.setY((Margin+rect.height()/2) + m_nOffsetPointer );
    gndDestPoint.setY((Margin+rect.height()/2 +10) + m_nOffsetPointer);

    horgndPoint1.setX(rect.x()-15);
    horgndPoint2.setX(rect.x()-5);
    horgndPoint1.setY((Margin+rect.height()/2 +10) + m_nOffsetPointer);
    horgndPoint2.setY((Margin+rect.height()/2 +10) + m_nOffsetPointer);

    horgndPoint3.setX(rect.x()-12);
    horgndPoint4.setX(rect.x()-7);
    horgndPoint3.setY((Margin+rect.height()/2 +13) + m_nOffsetPointer);
    horgndPoint4.setY((Margin+rect.height()/2 +13) + m_nOffsetPointer);



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

void PlotterWidget::drawGrid(QPainter *painter)
{
    double offsetMargin=Margin;
    QPen pen;
    QColor objColor(88,88,87,255);
    pen.setColor(objColor);
    pen.setStyle(Qt::SolidLine);
    pen.setBrush(Qt::darkGray);
    QRectF rect(offsetMargin,offsetMargin,width()-2*offsetMargin,height()-2*offsetMargin);
    painter->setPen(pen);
     painter->drawRect(rect);
     int l_nHWidth = ((rect.width()) / (m_objPlotSettings->numXDivisions));
    for(int i=0;i<m_objPlotSettings->numXDivisions;i++)
    {
        int x =  rect.left() +(i * (rect.width()) / m_objPlotSettings->numXDivisions);
        if( i !=0 ){
           painter->drawLine(x,rect.top(),x,rect.bottom());
        }
        for(int j=0;j<5;j++){
            int y= (j*(l_nHWidth/5));
            if(j!=0){
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
            if(j!=0){
                painter->drawLine(((rect.width()+2*offsetMargin)/2)-2,y-x,((rect.width()+2*offsetMargin)/2)+2,y-x);
            }
        }
    }
    pen.setWidthF(1.0);
    pen.setStyle(Qt::SolidLine);
}

void PlotterWidget::drawPixelPlot(QPainter *painter)
{
    QPen pen;
    pen.setWidthF(1.0);
    pen.setStyle(Qt::SolidLine);
    pen.setBrush(QColor(88,88,87,255));
    painter->setPen(pen);
    //painter->setRenderHint(QPainter::Antialiasing);

    int offsetMargin=Margin;
    static const QColor colorForIds[8] = {Qt::red,Qt::green,Qt::cyan,Qt::magenta,Qt::yellow,Qt::white,Qt::gray,Qt::black};
    QRectF rect(offsetMargin,offsetMargin,width()-2*offsetMargin,height()-2*offsetMargin);
    double y =0.0,x=0.0,dx=0.0,dy=0.0;
    painter->setClipRect(rect.adjusted(+1,+1,-1,-1));
    int index=0;
    double l_nOffset=-0.1;
    double l_nIncX=0.0;
    unsigned short l_nDrawindex=0;
    bool l_bLessWidth=false;
    double dxFactor = 1.0;//(rect.width())/(m_objChannelData.count());
    QPolygonF polyline1(2);
    if(m_nChannelCount <=1)
    {
    	dxFactor = (rect.width())/(m_objChannelData.count());
    	polyline1.resize(m_objChannelData.count());
    	l_bLessWidth = true;
    }
    qDebug()<<"Dx1 Factor:"<<dxFactor<<m_objChannelData.count()<<m_nChannelCount;
    //QPolygonF polyline(m_objChannelData.count()*m_nChannelCount);
    painter->setPen(colorForIds[1]);
    if(l_bLessWidth == true)
		for(int l_nDataIndex=0; l_nDataIndex< m_objChannelData.count();l_nDataIndex++)
		{
			QPolygonF polyline(2);
			double dx = (rect.left()+ l_nIncX);
			QList<double> dy = m_objChannelData.value(l_nDataIndex);
			double y = ((rect.height()/2) - ((dy.value(0)+(m_objPlotSettings->m_nOffsetPointer+l_nOffset))*((rect.height()-1))/(m_objPlotSettings->spanY())));
			polyline[0]=QPointF(dx,y);
			l_nIncX = l_nIncX + dxFactor;
			dx = (rect.left()+ l_nIncX);
			dy.clear();
			dy = m_objChannelData.value(l_nDataIndex+1);
			y = ((rect.height()/2) - ((dy.value(0)+(m_objPlotSettings->m_nOffsetPointer+l_nOffset))*((rect.height()-1))/(m_objPlotSettings->spanY())));
			polyline[1]=QPointF(dx,y);
			//l_nIncX = l_nIncX + dxFactor;
			painter->drawPolyline(polyline);
		}
    else
		for(int l_nDataIndex=0; l_nDataIndex< m_objChannelData.count();l_nDataIndex++)
		{
			QPolygonF polyline(m_nChannelCount);
			 QList<double> l_nlstValues = m_objChannelData.value(l_nDataIndex);
			 dx = (rect.left()+ l_nIncX);
			 for(int l_nlstIndex=0;l_nlstIndex<l_nlstValues.count();l_nlstIndex++)
			 {
					 dy = l_nlstValues.value(l_nlstIndex);
					 y = ((rect.height()/2) - ((dy+(m_objPlotSettings->m_nOffsetPointer+l_nOffset))*((rect.height()-1))/(m_objPlotSettings->spanY())));
					// qDebug()<<"X Value:"<<dx<<"Y Value:"<<y;
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
			 if(l_bLessWidth == false)
				 painter->drawPolyline(polyline);
			 l_nIncX = l_nIncX + dxFactor;
			 //l_nDrawindex=0;
		}

}


void PlotterWidget::constructXYPolyData(QPainter *painter)
  {
  	//if(m_objChannelData.count()==0) return;
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

      int offsetMargin=Margin;
      static const QColor colorForIds[8] = {Qt::red,Qt::green,Qt::cyan,Qt::magenta,Qt::yellow,Qt::white,Qt::gray,Qt::black};
      QRectF rect(offsetMargin,offsetMargin,width()-2*offsetMargin,height()-2*offsetMargin);
      double y =0.0,x=0.0,dx=0.0,dy=0.0;
      painter->setClipRect(rect.adjusted(+1,+1,-1,-1));
      int index=0;
      double l_nOffset=-0.1;
      double l_nIncX=0.0;
      unsigned short l_nDrawindex=0;
      bool l_bLessWidth=false;
      double dxFactor = 1.0;//(rect.width())/(m_objChannelData.count());
      QPolygonF polyline1(1);
      double m_nSamplePerPixel =(double)floor((double)m_nSamplesCount/(double)rect.width());
      if(m_nSamplePerPixel <=1)
      {
      	dxFactor = (rect.width())/(m_objChannelData.count());
      	polyline1.resize(m_objChannelData.count());
      	l_bLessWidth = true;
      }
      painter->setPen(colorForIds[1]);
      unsigned int m_nValue = 1.0;
		//if(m_nSamples<rect.width())
		//{
			dxFactor = 1.0;
		//}
		unsigned int l_nTempIndex=m_nSamplePerPixel;
      qDebug()<<"Dx Factor:"<<dxFactor<<m_objChannelData.count()<<m_nSamplePerPixel;
		//qDebug()<<"Span Y:"<<m_objPlotSettings->spanY()<<m_eChannel<<m_nValue;
      if(l_bLessWidth == true)
  		for(int l_nDataIndex=0; l_nDataIndex< m_objChannelData.count();l_nDataIndex++)
  		{
  			QList<double> dy;
  			QPolygonF polyline(2);
  			double dx = (rect.left()+ l_nIncX);
 				dy = m_objChannelData.value(l_nDataIndex);
  			double y = ((rect.height()/2) - ((dy.value(0)+(m_objPlotSettings->m_nOffsetPointer+l_nOffset))*((rect.height()-1))/(m_nValue)));
  			polyline[0]=QPointF(dx,y);
  			l_nIncX = l_nIncX + dxFactor;
  			dx = (rect.left()+ l_nIncX);
  			dy.clear();
  			dy = m_objChannelData.value(l_nDataIndex+1);
  			y = ((rect.height()/2) - ((dy.value(0)+(m_objPlotSettings->m_nOffsetPointer+l_nOffset))*((rect.height()-1))/(m_nValue)));
  			polyline[1]=QPointF(dx,y);
  			//l_nIncX = l_nIncX + dxFactor;
  			painter->drawPolyline(polyline);
  		}
      else
  		for(int l_nDataIndex=0; l_nDataIndex< m_objChannelData.count();l_nDataIndex++)
  		{
  			QList<double> l_nlstValues;
  			QPolygonF polyline(m_nSamplePerPixel);
  			//if(m_eChannel == CHANNEL1)
  			l_nlstValues = m_objChannelData.value(l_nDataIndex);
  			dx = (rect.left()+ l_nIncX);
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
  				 dy=m_objChannelData.value(l_nDataIndex-1).value(m_nSamplePerPixel-1);
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


void PlotterWidget::draw_line(qreal x1, qreal y1, qreal x2, qreal y2,QPainter *painter)
{
	qreal dx = x2 - x1;
	qreal dy = y2 - y1;
	qreal m = dy/dx;
	for (int x = x1; x < x2; x++)
	{
		qreal y = m*x + y1 + 0.5;
		painter->drawPoint(x, y);
	}
}

void PlotterWidget::drawCurves(QPainter *painter)
{
      QPen pen;
      pen.setWidthF(1.0);
      pen.setStyle(Qt::SolidLine);
      pen.setBrush(QColor(88,88,87,255));
      painter->setPen(pen);
      //painter->setRenderHint(QPainter::Antialiasing);

      int offsetMargin=Margin;
      static const QColor colorForIds[8] = {Qt::red,Qt::green,Qt::cyan,Qt::magenta,Qt::yellow,Qt::white,Qt::gray,Qt::black};
      QRectF rect(offsetMargin,offsetMargin,width()-2*offsetMargin,height()-2*offsetMargin);
      double y =0.0,x=0.0,dx=0.0,dy=0.0;
      painter->setClipRect(rect.adjusted(+1,+1,-1,-1));
      int index=0;
     // qDebug()<<"Wave DB Count:"<<curveMap.count();
      double l_nOffset=-0.1;
      while(index<curveMap.count())
      {
          QVector<QPointF> m_objData = curveMap.value(index);
          QPolygonF polyline(m_objData.count());
          double dxFactor = (rect.width())/(m_objData.count());
          double l_nIncX=0.0;
       //   qDebug()<<"Index:"<<m_objData.count()<<index;
          for(int l_nDataIndex=0; l_nDataIndex< m_objData.count();l_nDataIndex++)
          {
               dx = m_objData[l_nDataIndex].x();
               dy = m_objData[l_nDataIndex].y();
               x = (rect.left()+ l_nIncX);
               y = ((rect.height()/2) - ((dy+(m_objPlotSettings->m_nOffsetPointer+l_nOffset))*((rect.height()-1))/(m_objPlotSettings->spanY())));
               l_nIncX = l_nIncX + dxFactor;
               polyline[l_nDataIndex] = QPointF(x,y);
           }
    //              if(m_eChannel == CHANNEL1 && m_bHideFlag==false)
    //                      painter->setPen(colorForIds[4]);
    //              else if(m_eChannel == CHANNEL2&& m_bHideFlag==false)
    //                      painter->setPen(colorForIds[3]);
    //              else if(m_eChannel == CHANNEL3&& m_bHideFlag==false)
    //                      painter->setPen(colorForIds[0]);
    //              else if(m_eChannel == CHANNEL4&& m_bHideFlag==false)
    //                      painter->setPen(colorForIds[1]);
    //              else
    //                      painter->setPen(Qt::NoPen);
          l_nOffset++;
          painter->setPen(colorForIds[index]);
          painter->drawPolyline(polyline);
          index++;
      }
}



//! [0]
