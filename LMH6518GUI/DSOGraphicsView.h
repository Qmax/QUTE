#include<QtGui>
#include<QtCore>
#include <qdebug.h>
#include <QtGui/QGraphicsItem>
#include "DisplayWidgetInterface.h"



static const double Pi = 3.14159265358979323846264338327950288419717;
static double TwoPi = 2.0 * Pi;
static const int dsoMargin = 12;




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
class DSOXYPlane:public QGraphicsItem
{
public:
    DSOXYPlane(QGraphicsItem *parent=0):QGraphicsItem(parent)
    {
    }

    virtual QRectF boundingRect() const
    {
        return QRectF(dsoMargin,dsoMargin,m_nWidth-2*dsoMargin,m_nHeight-2*dsoMargin);
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
		paintDSOPlane(painter);
    }
    void setPointerValue( QRectF pRect,double pHeight,double pWidth,PlotXYSettings *pSettings=0)
    {
        m_objRect = pRect;
        m_objPlotSettings = pSettings;
        m_nHeight = pHeight;
        m_nWidth = pWidth;
    }



    void constructDSOXYAxes(QPainter *painter)
    {
    	qDebug()<<"Inside DOSXYAxes";
    	double offsetMargin=dsoMargin;
        QPen pen;
        QColor objColor(88,88,87,255);
        pen.setColor(objColor);
        //QRectF rect(offsetMargin,offsetMargin,width()-2*Margin,height()-2*Margin);

//        QRectF rect(offsetMargin,offsetMargin,m_nWidth-2*offsetMargin,m_nHeight-2*offsetMargin);
        QRectF rect(offsetMargin,offsetMargin,m_objRect.width()-2*offsetMargin,m_objRect.height()-2*offsetMargin);
        qDebug()<<"Rect Width:"<<rect.width();
        qDebug()<<"Rect Height:"<<rect.height();
        qDebug()<<"Rect X:"<<rect.x()<<rect.left();
        qDebug()<<"Rect Y:"<<rect.y()<<rect.top();
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


    void setPlotsettings(PlotXYSettings *pSettings=0)
    {
        m_objPlotSettings = pSettings;
    }

protected:
    QRectF m_objRect;
    PlotXYSettings* m_objPlotSettings;
    double m_nHeight,m_nWidth;
};


class DSOXYChannelItem:public QGraphicsItem
{
public:
    DSOXYChannelItem(QGraphicsItem *parent=0):QGraphicsItem(parent)
    {
    	m_nOffset=0.0;
    	m_bHideFlag=false;
    	m_nSamplePerPixel=1.0;
    	setCacheMode(QGraphicsItem::DeviceCoordinateCache);
    //	setFlag(QGraphicsItem::ItemIsMovable,true);
    }

    void setSamplesPerPixel(double pCount)
    {
    	m_nSamplePerPixel = pCount;
    }
    QRectF boundingRect() const
    {
        return QRectF(m_objRect);
    }
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
    {
        Q_UNUSED(option);
        Q_UNUSED(widget);
		constructXYPolyData(painter);
    }


    void HideChannelItem(bool isHideFlag)
    {
    	m_bHideFlag=isHideFlag;
    }


    void constructXYPolyData(QPainter *painter)
    {
    	qDebug()<<"XYPolyData";
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
		unsigned int l_nTempIndex=m_nSamplePerPixel;
        qDebug()<<"Dx Factor:"<<dxFactor<<m_objCH1Data.count()<<m_nSamplePerPixel<<m_nSamples<<m_eSamplesType;
		//qDebug()<<"Span Y:"<<m_objPlotSettings->spanY()<<m_eChannel<<m_nValue;
        if(l_bLessWidth == true)
    		for(int l_nDataIndex=0; l_nDataIndex< m_objCH1Data.count();l_nDataIndex++)
    		{
    			QList<double> dy;
    			QPolygonF polyline(2);
    			double dx = (rect.left()+ l_nIncX);
   				dy = m_objCH1Data.value(l_nDataIndex);
//   				if(l_nDataIndex<m_nPreCount)
//   				{
//   					painter->setPen(colorForIds[3]);
//   				}
//   				else
//   				{
//   					painter->setPen(colorForIds[4]);
//   				}
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
//   				if((l_nTempIndex)<m_nPreCount)
//   				{
//   					painter->setPen(colorForIds[3]);
//   					//qDebug()<<"Check Count:"<<l_nTempIndex;
//   				}
//   				else
//   				{
//   					painter->setPen(colorForIds[4]);
//   				}
//   				l_nTempIndex+=m_nSamplePerPixel;
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


    void setChannelVectorData( QMap<int,QList<double> > pobjData,DSO_CHANNEL pChannel)
    {
    	m_objCH1Data.clear();
   		m_objCH1Data = pobjData;
 	   qDebug()<<"View Count:"<<m_objCH1Data.count();

    }
    void setSpanData(double pValue)
    {
   		m_nValue = pValue;
    }
    void setChannel(DSO_CHANNEL pChannel)
    {
    	m_eChannel = pChannel;
    }
    void moveChannelOffset(double pOffset)
    {
    	m_nOffset=pOffset;
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
protected:
    QRectF m_objRect;
    double m_nValue;
    QMap<int,QList<double> > m_objCH1Data;
    DSO_CHANNEL m_eChannel;
    double m_nOffset;
    bool m_bHideFlag;
    double m_nSamplePerPixel;
    unsigned int m_nSamples;
    SAMPLING_TYPE m_eSamplesType;
    PlotXYSettings* m_objPlotSettings;
};

class DSOXYGridView : public QGraphicsView
{
    Q_OBJECT
public:
    DSOXYGridView(QWidget *obj=0):QGraphicsView(obj)
    {
    //	this->setGeometry(obj->geometry());
        setOptimizationFlags(QGraphicsView::DontSavePainterState);
        setViewportUpdateMode(QGraphicsView::SmartViewportUpdate);
        setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        setRenderHints(QPainter::SmoothPixmapTransform);
        setFrameStyle(QFrame::NoFrame);
        setMouseTracking(true);
    	initializeDSOPlane();

    }

    void initializeDSOPlane()
    {
    	m_objGridscene1=  new QGraphicsScene(this);
        m_objDSOXYPlane = new DSOXYPlane();
    	m_objDSOChannelData = new DSOXYChannelItem();

    }

    void constructDSOPlane(QRectF pObj,PlotXYSettings *pSettings)
    {
    	qDebug()<<"----------------------------------------------";
    	qDebug()<<"DSO GRID VIEW.";
       // m_objPlotSettings = pSettings;
        //setGeometry(Margin,Margin,pObj.width()-(2*(Margin),pObj.height()-(2*(Margin));
        m_objDSOXYPlane->setPointerValue(pObj,geometry().height(),geometry().width(),pSettings);
    	m_objDSOChannelData->setPointerValue(pObj,pSettings);
        m_objGridscene1->addItem(m_objDSOXYPlane);
        m_objGridscene1->addItem(m_objDSOChannelData);
        setSceneRect(pObj);
        setScene(m_objGridscene1);
    }

    void setSamplesCount(unsigned int pSamples,SAMPLING_TYPE pType)
    {
     	m_objDSOChannelData->setSamplesCount(pSamples,pType);
    }
    void setChannelVectorData(QMap<int,QList<double> > pObjData,DSO_CHANNEL pChannel)
    {
 		if(pChannel == CHANNEL1){
 			m_objDSOChannelData->setChannelVectorData(pObjData,pChannel);
 			m_objDSOChannelData->setChannel(CHANNEL1);
 		}
 		update();
    }
    void changePlotSettings(DSO_CHANNEL pChannel,PlotXYSettings *pSettings,double pData)
    {
    	if(pChannel == CHANNEL1 || pChannel== CHANNEL2){
    		//m_objPlotSettings = pSettings;
    		m_objDSOChannelData->setChannel(CHANNEL1);
   //      m_objDSOChannelData->setPointerValue(m_objBorderRect,m_objPlotSettings);

    	}
    	else if (pChannel == CHANNEL3 || pChannel== CHANNEL4)
    	{
    		//m_objPlotSettings = pSettings;
    		m_objDSOChannelData->setChannel(CHANNEL3);
 //        m_objDSOChannel3Data->setPointerValue(m_objBorderRect,m_objPlotSettings);
    	}
    }

    void setSpanData(double pData,DSO_CHANNEL pChannel)
    {
    	if(pChannel == CHANNEL1 || pChannel== CHANNEL2){
    		m_objDSOChannelData->setSpanData(pData);
    	//	m_objDSOChannel2Data->setSpanData(pData);
    	}
    	else if (pChannel == CHANNEL3 || pChannel== CHANNEL4)
    	{
    		//m_objDSOChannel3Data->setSpanData(pData);
    		//m_objDSOChannel4Data->setSpanData(pData);
    	}
    }

    void setPrePostCount(unsigned int pPostCount,unsigned int pPreCount,DSO_CHANNEL pChannel)
    {
    	if(pChannel == CHANNEL1 || pChannel== CHANNEL2){
    		//m_objDSOChannelData->setPrePostCount(pPostCount,pPreCount);
    		//m_objDSOChannel2Data->setPrePostCount(pPostCount,pPreCount);
    	}
    	else if (pChannel == CHANNEL3 || pChannel== CHANNEL4)
    	{
    		//m_objDSOChannel3Data->setPrePostCount(pPostCount,pPreCount);
    		//m_objDSOChannel4Data->setPrePostCount(pPostCount,pPreCount);
    	}
    }

protected:

    DSOXYPlane *m_objDSOXYPlane;
	QGraphicsScene *m_objGridscene1;
    DSOXYChannelItem *m_objDSOChannelData;


};



class DSOChannelDataView:public QGraphicsView
{
    Q_OBJECT
public:
    DSOChannelDataView(QWidget *obj=0):QGraphicsView(obj)
    {
        setOptimizationFlags(QGraphicsView::DontSavePainterState);
        setViewportUpdateMode(QGraphicsView::SmartViewportUpdate);
        setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        setRenderHints(QPainter::SmoothPixmapTransform);
        setFrameStyle(QFrame::NoFrame);
        setMouseTracking(true);

    	m_objDSOChannelData = new DSOXYChannelItem();
    	m_objChannelDatascene = new QGraphicsScene(this);

    }
    void intializeChannelData(QRectF pObj,PlotXYSettings *pSettings)
    {
    	m_objDSOChannelData->setPointerValue(pObj,pSettings);
    	m_objChannelDatascene->addItem(m_objDSOChannelData);
        setSceneRect(pObj);
        setScene(m_objChannelDatascene);

    }
    void clearVectorData()
    {
        //m_objDSOChannelData->clearChannelData();
    }
   void setSamplesCount(unsigned int pSamples,SAMPLING_TYPE pType)
   {
    	m_objDSOChannelData->setSamplesCount(pSamples,pType);
   }
   void setChannelVectorData(QMap<int,QList<double> > pObjData,DSO_CHANNEL pChannel)
   {
		if(pChannel == CHANNEL1){
			m_objDSOChannelData->setChannelVectorData(pObjData,pChannel);
			m_objDSOChannelData->setChannel(CHANNEL1);
		}
		update();
   }
   void changePlotSettings(DSO_CHANNEL pChannel,PlotXYSettings *pSettings,double pData)
   {
   	if(pChannel == CHANNEL1 || pChannel== CHANNEL2){
   		//m_objPlotSettings = pSettings;
   		m_objDSOChannelData->setChannel(CHANNEL1);
  //      m_objDSOChannelData->setPointerValue(m_objBorderRect,m_objPlotSettings);

   	}
   	else if (pChannel == CHANNEL3 || pChannel== CHANNEL4)
   	{
   		//m_objPlotSettings = pSettings;
   		m_objDSOChannelData->setChannel(CHANNEL3);
//        m_objDSOChannel3Data->setPointerValue(m_objBorderRect,m_objPlotSettings);
   	}
   }

   void setSpanData(double pData,DSO_CHANNEL pChannel)
   {
   	if(pChannel == CHANNEL1 || pChannel== CHANNEL2){
   		m_objDSOChannelData->setSpanData(pData);
   	//	m_objDSOChannel2Data->setSpanData(pData);
   	}
   	else if (pChannel == CHANNEL3 || pChannel== CHANNEL4)
   	{
   		//m_objDSOChannel3Data->setSpanData(pData);
   		//m_objDSOChannel4Data->setSpanData(pData);
   	}
   }

   void setPrePostCount(unsigned int pPostCount,unsigned int pPreCount,DSO_CHANNEL pChannel)
   {
   	if(pChannel == CHANNEL1 || pChannel== CHANNEL2){
   		//m_objDSOChannelData->setPrePostCount(pPostCount,pPreCount);
   		//m_objDSOChannel2Data->setPrePostCount(pPostCount,pPreCount);
   	}
   	else if (pChannel == CHANNEL3 || pChannel== CHANNEL4)
   	{
   		//m_objDSOChannel3Data->setPrePostCount(pPostCount,pPreCount);
   		//m_objDSOChannel4Data->setPrePostCount(pPostCount,pPreCount);
   	}
   }
protected:
    QGraphicsScene *m_objChannelDatascene;
    DSOXYChannelItem *m_objDSOChannelData;

};


