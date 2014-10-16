#include "plotter.h"
#include <qdebug.h>
#include "unistd.h"

#include <QFile>
#include <QTextStream>

Plotter::Plotter(QWidget *parent) :
    QWidget(parent,Qt::FramelessWindowHint | Qt::WindowSystemMenuHint)
{

    Margin =40;
    m_objPlotData = new stWaveData();
    setBackgroundRole(QPalette::Shadow);
    setAutoFillBackground(true);
    setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    setFocusPolicy(Qt::StrongFocus);
    rubberBandIsShown = false;
    m_bshowZoomRect = false;
    this->setGeometry(0,0,710,490);
    //this->setFocusPolicy(Qt::NoFocus);
    setPlotSettings(PlotSettings());
    m_showData=false;
    m_moveFlag = false;
    m_bClearTrace = false;
    m_nClearID=-1;
    m_nOffset=0.0;
    zoomScreenFlag=false;
}

void Plotter::zooomScreenStatus(bool status){
	zoomScreenFlag=status;
}
void Plotter::clearCurveData()
{
	//curveMap.clear();
}
void Plotter::setPlotData(stWaveData *pObjData)
{
    m_objPlotData = pObjData;
}
void Plotter::setMargin(int pMargin)
{
    Margin = pMargin;
}
void Plotter::setRubberBandRect(QRect *pRect)
{

    rubberBandRect.setX(pRect->x());
    float l_nY = (pRect->y()/(490.0/8.0))*15.0;
    rubberBandRect.setY(l_nY);
    rubberBandRect.setHeight((pRect->height()/(490.0/8.0))*15.0);
    rubberBandRect.setWidth(pRect->width());
}

void Plotter::setPlotSettings(const PlotSettings &settings)
{
    zoomStack.clear();
    zoomStack.append(settings);
    curZoom = 0;
}
void Plotter::setAmplitude(double pAmplitude,double pDutyCycles)
{
    m_nAmplitude = pAmplitude;
    m_objPlotData->m_nDutyCycles = pDutyCycles;
}

void Plotter::updateZoom(QRect pRect,PlotSettings pSettings)
{
    setRubberBandRect(&pRect);
    m_ZoomSettings = new PlotSettings();
    m_ZoomSettings = &pSettings;
    m_moveFlag = true;
    refreshPixmap();
}

void Plotter::showPixGraph()
{
	refreshPixmap();
}
void Plotter::zommOut()
{
    if(curZoom >0)
    {
        --curZoom;
    }
}
void Plotter::zoomIn()
{

    PlotSettings zoomSettings  =zoomStack[1];
    PlotSettings *newObj = new PlotSettings();
    newObj->maxX = zoomSettings.maxX;
    newObj->maxY = zoomSettings.maxY;
    newObj->minX = zoomSettings.minX;
    newObj->minY = zoomSettings.minY;
    newObj->m_nOffset = zoomSettings.m_nOffset;
//    ZoomPlotter *objzoomPlotter = new ZoomPlotter(this,newObj,&rubberBandRect);
//    objzoomPlotter->show();

}

void Plotter::setCurveData(int pID,const QVector<QPointF> & pData)
{
   // qDebug() << "CurveID"<<pID;
//    loopMap.clear();
//    if(m_nLoopDrive){
//        //loopMap = pData;
//        //refreshlGrid();
//        }
//    else
//    {
//        curveMap[pID] = pData;
//        refreshPixmap();
//    }
    curveMap[pID] = pData;
    refreshPixmap();//added for VI grap hide in multiple traces.

}

void Plotter::clearBand(int pID)
{
    if(bandMap.contains(pID))
    {
    	bandMap.remove(pID);
    	refreshPixmap();
    }

}

void Plotter::setBandData(int pID,QVector<QPointF> &data,double pBand)
{
    bandMap[pID] = data;
    m_objPlotData->m_nEnvelopBand = pBand;
   // qDebug() << "Band:"<<m_objPlotData->m_nEnvelopBand;
    generateCompareValues(pID);
    refreshPixmap();
}



void Plotter::clearCurve(int pID)
{
    //for(int l_nIndex=0;l_nIndex< curveMap.count();l_nIndex++) 496213
    //    curveMap.remove(l_nIndex);
	m_bClearTrace = true;
	m_nClearID = pID;
	//qDebug()<<"Clear Curve Trace Index:" << m_nClearID;
    if(curveMap.contains(pID))
    {
        curveMap.remove(pID);
        refreshPixmap();
    }
}

QSize Plotter::minimumSizeHint() const
{
    return QSize(12 * Margin,8 *Margin);
}

QSize Plotter::sizeHint() const
{
    return QSize(24 * Margin,16*Margin);
}

void Plotter::paintEvent(QPaintEvent *pEvent)
{
    Q_UNUSED(pEvent);
    QStylePainter painter(this);
    QColor l_objColor;
    painter.drawPixmap(0,0,pixmap);
    if(rubberBandIsShown)
    {
        painter.setPen(palette().light().color());
        painter.setBackgroundMode(Qt::TransparentMode);
        painter.fillRect(rubberBandRect,Qt::NoBrush);
        painter.drawRect(rubberBandRect.normalized());
    }
    if(hasFocus())
    {
        QStyleOptionFocusRect option;
        option.initFrom(this);
        option.backgroundColor = palette().dark().color();
        painter.drawPrimitive(QStyle::PE_FrameFocusRect,option);
//        qDebug() << "Inside Focus Painter Class";
    }
}

void Plotter::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event);
    refreshPixmap();
}


void Plotter::mousePressEvent(QMouseEvent *event)
{
    if( m_bRubberbandDrag == false)
        return;
    QRect rect(Margin,Margin,width()-2*Margin,height()-2*Margin);
    if(event->button() == Qt::LeftButton)
    {
        if(rect.contains(event->pos()))
        {
            rubberBandIsShown = true;
            QPoint l_objValues = event->pos();
            if((l_objValues.x() < width()- 2*Margin) && (l_objValues.y() < height()- 2*Margin ))
            {
                rubberBandRect.setTopLeft(event->pos());
                rubberBandRect.setBottomRight(event->pos());
                updateRubberBandRegion();
                setCursor(Qt::CrossCursor);
            }
        }
    }
}

void Plotter::mouseMoveEvent(QMouseEvent *event)
{
    if( m_bRubberbandDrag == false)
        return;
    if(rubberBandIsShown)
    {
        updateRubberBandRegion();
        rubberBandRect.setBottomRight(event->pos());
        updateRubberBandRegion();
    }
}

void Plotter::mouseReleaseEvent(QMouseEvent *event)
{
    if( m_bRubberbandDrag == false)
        return;
    if((event->button() == Qt::LeftButton) && rubberBandIsShown)
    {
        rubberBandIsShown = false;
        updateRubberBandRegion();
        unsetCursor();
        QRect rect = rubberBandRect.normalized();
        if(rect.width() < 4 || rect.height() < 4 )
        {
            return;
        }
        rect.translate(-Margin,-Margin);
        PlotSettings prevSettings = zoomStack[curZoom];
        PlotSettings settings;
        settings.m_nOffset = prevSettings.m_nOffset;
        double dx = prevSettings.spanX() / (width()-2*Margin);
        double dy = prevSettings.spanY() / (height()-2*Margin);
        settings.minX = prevSettings.minX + dx * rect.left();
        settings.maxX = prevSettings.minX + dx * rect.right();
        settings.minY = prevSettings.maxY - dy * rect.bottom();
        settings.maxY = prevSettings.maxY - dy * rect.top();
        settings.adjust();
        zoomStack.resize(curZoom + 1);
        zoomStack.append(settings);
        zoomIn();
    }
}



void Plotter::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
    case Qt::Key_Right:
        if(rubberBandRect.x() < this->width()-(rubberBandRect.width()-10))
        {
        rubberBandRect.setLeft(rubberBandRect.x() + 10);
        rubberBandRect.setWidth(rubberBandRect.width()+10);
        updateRubberBandRegion();
        }
        break;
    case Qt::Key_Left:
        if(rubberBandRect.x() > 10){
        rubberBandRect.setLeft(rubberBandRect.x() - 10);
        rubberBandRect.setWidth(rubberBandRect.width()-10);
        updateRubberBandRegion();

    }
        break;
    case Qt::Key_Down:
        if(rubberBandRect.y() < this->height()-rubberBandRect.height()){
        rubberBandRect.setTop(rubberBandRect.y() + 10);
        rubberBandRect.setHeight(rubberBandRect.height()+10);
        updateRubberBandRegion();

    }
        break;
    case Qt::Key_Up:
        if(rubberBandRect.y() >0){
        rubberBandRect.setTop(rubberBandRect.y() - 10);
        rubberBandRect.setHeight(rubberBandRect.height()-10);
        updateRubberBandRegion();

    }
        break;
     default: QWidget::keyPressEvent(event);
    }
    QRect rect = rubberBandRect.normalized();
    if(rect.width() < 4 || rect.height() < 4 )
    {
        return;
    }
    rect.translate(-Margin,-Margin);
    PlotSettings prevSettings = zoomStack[curZoom];
    PlotSettings settings;
    settings.m_nOffset = prevSettings.m_nOffset;
    double dx = prevSettings.spanX() / (width()-2*Margin);
    double dy = prevSettings.spanY() / (height()-2*Margin);
    settings.minX = prevSettings.minX + dx * rect.left();
    settings.maxX = prevSettings.minX + dx * rect.right();
    settings.minY = prevSettings.maxY - dy * rect.bottom();
    settings.maxY = prevSettings.maxY - dy * rect.top();
    settings.adjust();
    PlotSettings *pTemp = new PlotSettings();
    pTemp = &settings;
    zoomStack.resize(curZoom + 1);
    zoomStack.append(settings);
    refreshPixmap();
    emit moveWindow(rubberBandRect,settings);
}

void Plotter::wheelEvent(QWheelEvent *event)
{
    int numDegrees = event->delta() /8;
    int numTicks = numDegrees / 15;
    if(event->orientation() == Qt::Horizontal)
        zoomStack[curZoom].scroll(numTicks,0);
    else
        zoomStack[curZoom].scroll(0,numTicks);
   //refreshPixmap();
}

void Plotter::updateRubberBandRegion()
{
    QRect rect = rubberBandRect.normalized();
    setBackgroundRole(QPalette::Shadow);
    update(rect.left(),rect.top(),rect.width(),1);
    update(rect.left(),rect.top(),1,rect.height());
    update(rect.left(),rect.bottom(),rect.width(),1);
    update(rect.right(),rect.top(),1,rect.height());
}

void Plotter::refreshlGrid()
{
    pixmap = QPixmap(size());
    pixmap.fill(this,0,0);
    QPainter painter(&pixmap);
    painter.initFrom(this);
    drawGrid(&painter);
    painter.setRenderHint(QPainter::Antialiasing);

    loopDrawCurves(&painter);
    //repaint();
    update();

}
void Plotter::refreshPixmap()
{
        pixmap = QPixmap(size());
        pixmap.fill(this,0,0);
        QPainter painter(&pixmap);
        painter.initFrom(this);
        drawGrid(&painter);
        drawBand(&painter,0);
    if(curveMap.count()>=0 )
    {
        if(m_showData == true){
        	painter.setRenderHint(QPainter::Antialiasing);
        }
    }
    drawCurves(&painter);
    if(m_nLoopDrive==false){
        update();
    }
    else{
         setFocus(Qt::ActiveWindowFocusReason);
        //loopDrawCurves(&painter);
        repaint();
    }
}

void Plotter::drawGrid(QPainter *painter)
{
        //qDebug() << "Inside DrawGrid";
    QRect rect(Margin,Margin,width()-2*Margin,height()-2*Margin);
    if(!rect.isValid())
        return;
    QPen pen;
    QColor objColor(55,55,55,255);
    pen.setBrush(Qt::darkGray);
    pen.setStyle(Qt::DotLine);
    pen.setColor(objColor);
    pen.setCapStyle(Qt::RoundCap);
    pen.setJoinStyle(Qt::RoundJoin);
    painter->setPen(pen);
    //QPoint *pixPoint = new QPoint();
    PlotSettings settings = zoomStack[curZoom];
    if(m_bGrid)
    {
        for(int i=0;i<settings.numXTicks;i++)
        {
            int x = rect.left() + (i * (rect.width()) / settings.numXTicks);
            double label = settings.minX + (i*settings.spanX()/settings.numXTicks);
            //printf("X Axis:%f\n",label);
            for(float l_nPoint=1;l_nPoint<rect.height();l_nPoint+=2.0)
                painter->drawPoint(QPointF(x,rect.top()+l_nPoint));
            //painter->drawLine(x,rect.bottom(),x,rect.bottom()+5);
            painter->drawText(x-50,rect.bottom()+5,100,20, Qt::AlignHCenter|Qt::AlignTop,QString::number(label,5,2));
        }
        for(int j=0;j<settings.numYTicks;j++)
        {
            int y = rect.bottom() - (j * (rect.height()) / settings.numYTicks);
            double label = settings.minY + (j*settings.spanY()/settings.numYTicks);
            //printf("Y Axis:%f\n",label);
            for(float l_nPoint=0;l_nPoint<rect.width();l_nPoint+=2.0)
                painter->drawPoint(QPointF(rect.left()+l_nPoint,y));
            //painter->drawLine(rect.left(),y,rect.right(),y);
            painter->drawText(rect.left()-Margin,y-10,Margin-5, 20,Qt::AlignRight|Qt::AlignVCenter,QString::number(label,5,2));
        }

    pen.setStyle(Qt::SolidLine);
    painter->setPen(pen);
    //int Value =0;
    
        for(int i=0;i<rect.height();i+=((rect.height()/settings.numYTicks)/5))
        {
            if(i!=0 && i%5!=0){
                //painter->drawLine(Margin+rect.width()/2-3,Margin+i,Margin+rect.width()/2+3,Margin+i);
            }
        }
        for(int j=0;j<rect.width();j+=(rect.width()/settings.numXTicks)/5 )
        {
            if(j!=0 && j%5!=0){
                //painter->drawLine(Margin+j,Margin+rect.height()/2-3,Margin+j,Margin+rect.height()/2+3);
            }
        }
    }
    if(m_bGrid == false){
        pen.setStyle(Qt::SolidLine);
        pen.setBrush(Qt::darkGray);
        pen.setColor(objColor);
        pen.setWidth(1);
        painter->setPen(pen);
        if(zoomScreenFlag==true){
/*vertical line*/        painter->drawLine(Margin+rect.width()/2-1,Margin,Margin+rect.width()/2-1,Margin+rect.height());
/*horizontal line*/      painter->drawLine(Margin,Margin+rect.height()/2-1,Margin+rect.width(),Margin+rect.height()/2-1);
        }
        else if(zoomScreenFlag==false){
/*vertical line*/        painter->drawLine(Margin+rect.width()/2-1,Margin,Margin+rect.width()/2-1,Margin+rect.height());
/*horizontal line*/      painter->drawLine(Margin,Margin+rect.height()/2-1,Margin+rect.width(),Margin+rect.height()/2-1);
        }

        for(int i=0;i<rect.height();i+=((rect.height()/settings.numYTicks)/2))
        {
            if(i!=0 && i%2!=0)
            {
            if(zoomScreenFlag==true){
///*vertical grid*/   painter->drawLine((Margin+rect.width()/2-3)-1,Margin+i,(Margin+rect.width()/2+3)-1,Margin+i);
            }
           }
        }
        for(int j=0;j<rect.width();j=j+(rect.width()/settings.numXTicks)+5 )
        {
            if(j!=0)
            {
///*horizontal grid*/  painter->drawLine(Margin+j-5,Margin+rect.height()/2-3,Margin+j-5,Margin+rect.height()/2+3);
            }
        }


    }
    if(m_bVILabels == true)
    {
        pen.setWidth(2);
        pen.setBrush(Qt::gray);
        painter->setPen(pen);
    	//qDebug() << "XLabel" << m_strXLabel << "YLabel" << m_strYLabel;
//        painter->drawText(Margin+rect.width()/2+8,3,65,45,Qt::AlignLeft|Qt::AlignTop,m_strY1Label);
//        painter->drawText(4,Margin+rect.height()/2+2,35,45,Qt::AlignLeft|Qt::AlignTop,m_strX1Label);
//        painter->drawText(Margin+rect.width()-35,Margin+rect.height()/2,35,45,Qt::AlignHCenter|Qt::AlignTop,m_strX2Label);
//        painter->drawText(Margin+rect.width()/2+8,Margin+rect.height()-20,65,45,Qt::AlignLeft|Qt::AlignTop,m_strY2Label);
        painter->drawText(Margin+rect.width()/2+8,8,65,45,Qt::AlignLeft|Qt::AlignTop,"+"+m_strY1Label);
        painter->drawText(15,Margin+rect.height()/2+2,35,45,Qt::AlignLeft|Qt::AlignTop,"+"+m_strX1Label);
        painter->drawText(Margin+rect.width()-45,Margin+rect.height()/2,35,45,Qt::AlignHCenter|Qt::AlignTop,m_strX2Label);
        painter->drawText(Margin+rect.width()/2+8,Margin+rect.height()-25,65,45,Qt::AlignLeft|Qt::AlignTop,m_strY2Label);
    }
    //painter->drawRect(rect.adjusted(+0,+0,-1,-1));
   // qDebug() << "outSide DrawGrid";
    //painter->drawRect(rect.adjusted(+0,+0,-1,-1));
}

void Plotter::loopDrawCurves(QPainter *painter)
{

    PlotSettings settings = zoomStack[curZoom];
    QRect rect(Margin,Margin,width()-(2*Margin),height()-(2*Margin));
    painter->setClipRect(rect.adjusted(+1,+1,-1,-1));
     QVector<QPointF> data = loopMap;
    QPolygonF polyline(data.count());
    //qDebug() << "Data Count:"<<data.count();
    double y =0.0,x=0.0;
    int l_nCounter =0;
    m_nOffset =0.0;
    double dx=0.0,dy=0.0;
    for(int j=0; j< data.count();++j)
    {
         dx = data[j].x();
         dy = data[j].y();
         if(m_bUniPolar == true)
         {
             float l_nDiv = (dy/2.0);
//             printf("UniPolar %f->%f\n",l_nDiv,dy - l_nDiv);
         }
         if(( data[j].x()>=settings.minX && data[j].x()<=settings.maxX))
         {
             //printf("X:%f Y:%f\n",dx,dy);
         }
        y =0.0,x=0.0;
        if(m_bVIMode == true)
            x = ((rect.width()/2)+5.0  + ((dx)*(((rect.width()-1)))/(settings.spanX())));
        else
            x = (rect.left()+ ((dx)*(((rect.width()-1)))/(settings.spanX())));

        if( m_bUniPolar == true){
            y = ((Margin+rect.bottom()) - (((dy/2.0)+settings.m_nOffset)*((rect.height()-1))/(settings.spanY())));
            //y+=10;
//            printf(" Coord-Y %f\n",dy/2.0);
        }
        else
            y = ((Margin+rect.height()/2) - ((dy+m_nOffset)*((rect.height()-1))/(settings.spanY())));
       // printf(" Coord- X & Y %f %f\n",x,y);
        if(( data[j].x()>=settings.minX && data[j].x()<=settings.maxX)&&(( data[j].y()>=settings.minY && data[j].y()<=settings.maxY)))
        {
            polyline[j] = QPointF(x,y);
            l_nCounter++;
        }
    }
    y =0.0,x=0.0;
//    for(int l_nIndex=0;l_nIndex< data.count();l_nIndex++)
//    {
//        QPointF(x,y);
//        x = polyline.at(l_nIndex).x();
//        y = polyline.at(l_nIndex).y();
//    }

    painter->setPen(Qt::red);
     painter->drawPolyline(polyline);
     loopMap.clear();
    // qDebug() << "Inside Loop Draw Curves";

}

void Plotter::setEnvelopBand(double pBand)
{
	m_objPlotData->m_nEnvelopBand = pBand;
}
bool Plotter::compareBand(int pId)
{
    PlotSettings settings = zoomStack[curZoom];
    QRect rect(Margin,Margin,width()-(2*Margin),height()-(2*Margin));
    QVector<QPointF> data =curveMap[pId];
    double dx=0.0,dy=0.0;
    double y =0.0,x=0.0;
    bool isPass=true;
    for(int j=0; j< data.count();++j)
    {
        dx = data[j].x();
        dy = data[j].y();
        x = ((rect.width()/2)+5.0  + ((dx)*(((rect.width()-1)))/(settings.spanX())));
        y = ((Margin+rect.height()/2) - ((dy+m_nOffset)*((rect.height()-1))/(settings.spanY())));
       // qDebug() << "Inside Compare Band"<<dx<<dy;
        if(!((x>=m_lstLO.at(j).x()&&y>=m_lstLO.at(j).y()) && (x<=m_lstUP.at(j).x()&&y<=m_lstUP.at(j).y())))
        {
            isPass=false;
            m_nCompareWaveIndex = j;
            break;
        }
    }
    if(isPass == true)
        return true;
    else
        return false;
}

short int Plotter::getCompareWaveIndex() const
{
	return m_nCompareWaveIndex;
}

void Plotter::generateCompareValues(int pId)
{
    PlotSettings settings = zoomStack[curZoom];
    QRect rect(Margin,Margin,width()-(2*Margin),height()-(2*Margin));
    m_lstLO.clear();m_lstUP.clear();
    QVector<QPointF> data =bandMap[pId];
    double y =0.0,x=0.0;
    double dx=0.0,dy=0.0;
    //qDebug() << "Inside Compare Values";
    for(int j=0; j< data.count();++j)
    {
         dx = data[j].x();
         dy = data[j].y();
         x = ((rect.width()/2)+5.0  + ((dx)*(((rect.width()-1)))/(settings.spanX())));
         y = ((Margin+rect.height()/2) - ((dy+m_nOffset)*((rect.height()-1))/(settings.spanY())));
         //qDebug()<<dx<<dy;
        m_lstLO.insert(j,QPointF(x-m_objPlotData->m_nEnvelopBand,y-m_objPlotData->m_nEnvelopBand));
        m_lstUP.insert(j,QPointF(x+m_objPlotData->m_nEnvelopBand*2,y+m_objPlotData->m_nEnvelopBand*2));
    }
    //QRectF rect(x - m_objPlotData->m_nEnvelopBand,y - m_objPlotData->m_nEnvelopBand,m_objPlotData->m_nEnvelopBand*2, m_objPlotData->m_nEnvelopBand*2);
    //    qDebug()<<"RectXStart:"<<x - m_objPlotData->m_nEnvelopBand<<"RectYStart:"<<y - m_objPlotData->m_nEnvelopBand<<
    //"RectXWidt:"<<x+m_objPlotData->m_nEnvelopBand*2<<
      //          "RectYHeigt"<<y+m_objPlotData->m_nEnvelopBand;
}



void Plotter::drawBand(QPainter *painter,int pId)
{
/*    // double xPointHeight = y- m_objPlotData->m_nEnvelopBand;

     //if(l_nIndex==1)
     //pen.setBrush(QColor(162,162,161,100));
     QRectF rect(x - m_objPlotData->m_nEnvelopBand,y - m_objPlotData->m_nEnvelopBand,m_objPlotData->m_nEnvelopBand*2, m_objPlotData->m_nEnvelopBand*2);
     //painter->fillRect(rect,QColor(162,162,161,255));
         //painter->drawRect();
     //polyline1[l_nIndex] = QPointF(x - m_objPlotData->m_nEnvelopBand,y+m_objPlotData->m_nEnvelopBand*2);
  */
  //  qDebug() << "Draw Band:"<<m_objPlotData->m_nEnvelopBand;

    PlotSettings settings = zoomStack[curZoom];
    QRect rect(Margin,Margin,width()-(2*Margin),height()-(2*Margin));
    painter->setClipRect(rect.adjusted(+1,+1,-1,-1));
     QVector<QPointF> data =bandMap[pId];
     QPolygonF polyline1(data.count());
  //  qDebug() << "Data Count:"<<data.count();
    double y =0.0,x=0.0;
    m_nOffset =0.0;
    double dx=0.0,dy=0.0;
    for(int j=0; j< data.count();++j)
    {
         dx = data[j].x();
         dy = data[j].y();
        x = ((rect.width()/2)+5.0  + ((dx)*(((rect.width()-1)))/(settings.spanX())));
        y = ((Margin+rect.height()/2) - ((dy+m_nOffset)*((rect.height()-1))/(settings.spanY())));
        polyline1[j] =QPointF(x,y);
    }
    QPen pen;
    pen.setWidthF(m_objPlotData->m_nEnvelopBand*2);
    pen.setBrush(QColor(162,162,161,100));
    pen.setCapStyle(Qt::SquareCap);
    pen.setJoinStyle(Qt::RoundJoin);
    painter->setPen(pen);
    painter->drawPolyline(polyline1);
    pen.setWidthF(1);
    painter->setPen(pen);
    painter->drawPolyline(polyline1);
}

void Plotter::drawCurves(QPainter *painter)
{
	//~~~~~~~~Adjust X-y Axis ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    QStringList stringList;
    bool ok=true;
    QFile textFile("AdjustXYaxisVI.txt");
    if (textFile.open(QIODevice::ReadOnly))
    {
        QTextStream textStream(&textFile);
        while (!textStream.atEnd())
        {
            stringList.append(textStream.readLine());
        }
        adjustXaxis=stringList.value(0).toDouble(&ok);
        adjustYaxis=stringList.value(1).toDouble(&ok);
    }else{
        adjustXaxis=5.5;
        adjustYaxis=0;
    }
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    static const QColor colorForIds[8] = {Qt::red,Qt::green,Qt::cyan,Qt::magenta,Qt::yellow,Qt::white,Qt::gray,Qt::black};
    PlotSettings settings = zoomStack[curZoom];
    if( m_moveFlag == true)
    {
        settings.maxX = m_ZoomSettings->maxX;
        settings.maxY = m_ZoomSettings->maxY;
        settings.minX = m_ZoomSettings->minX;
        settings.minY = m_ZoomSettings->minY;
        settings.m_nOffset = m_ZoomSettings->m_nOffset;
        settings.numXTicks = m_ZoomSettings->numXTicks;
        settings.numYTicks = m_ZoomSettings->numYTicks;
    }
    QRect rect(Margin,Margin,width()-(2*Margin),height()-(2*Margin));
    if(m_bshowZoomRect == true)
    {
        painter->setPen(colorForIds[6]);
        painter->drawRect(rubberBandRect);
    }

    if(!rect.isValid())
        return;
    painter->setClipRect(rect.adjusted(+1,+1,-1,-1));
    QMapIterator<int, QVector<QPointF> > i(curveMap);
//    printf("Rect Left: %d\n",rect.left());
//    printf("Rect Height: %d\n",rect.height());
//    printf("Rect width: %d\n",rect.width());
//    printf("Rect Bottom: %d\n",rect.bottomLeft().y());
//    printf("Rect Top: %d\n",rect.top());
    double dx,dy;
    while(i.hasNext()){

        i.next();
        int id = i.key();
      //  qDebug() << "Curve ID" << id;
        QVector<QPointF> data = i.value();
        QPolygonF polyline(data.count());
        double y =0.0,x=0.0;
        int l_nCounter =0;
        //printf("MinY:%f\n",settings.minY);
        //printf("Offset:%f\n",m_nOffset);
        m_nOffset =0.0;
        for(int j=0; j< data.count();++j)
        {
             dx = data[j].x();
             dy = data[j].y();
             if(m_bUniPolar == true)
             {
                 float l_nDiv = (dy/2.0);
//                 printf("UniPolar %f->%f\n",l_nDiv,dy - l_nDiv);
             }
             if(( data[j].x()>=settings.minX && data[j].x()<=settings.maxX))
             {
                 //printf("X:%f Y:%f\n",dx,dy);
             }
            y =0.0,x=0.0;
            if(m_ZoomFlag == false)
            {
                if(m_bVIMode == true)
                    x = ((rect.width()/2)+adjustXaxis  + ((dx)*(((rect.width()-1)))/(settings.spanX())));
                else
                    x = (rect.left()+ ((dx)*(((rect.width()-1)))/(settings.spanX())));

                if( m_bUniPolar == true){
                    y = ((Margin+rect.bottom()) - (((dy/2.0)+settings.m_nOffset)*((rect.height()-1))/(settings.spanY())));
                    //y+=10;
//                    printf(" Coord-Y %f\n",dy/2.0);
                }
                else
                    y = (((Margin+rect.height()/2)+adjustYaxis) - ((dy+m_nOffset)*((rect.height()-1))/(settings.spanY())));//TO CHANGE THE Y AXIS IN THE GRAPH
               // printf(" Coord- X & Y %f %f\n",x,y);
            }
            else if(m_ZoomFlag == true)
            {
                x = (rect.left() + ((dx-settings.minX)*(((rect.width()-1)))/(settings.spanX())));
                y = ((Margin+rect.height()) - (((dy-settings.minY)+settings.m_nOffset)*((rect.height()-1))/(settings.spanY())));
            }
            if(( data[j].x()>=settings.minX && data[j].x()<=settings.maxX)&&(( data[j].y()>=settings.minY && data[j].y()<=settings.maxY)))
            {

            	polyline[j] = QPointF(x,y);
                l_nCounter++;
            }
        }
        QPolygonF zoomPolyline(l_nCounter);
        y =0.0,x=0.0;
        int l_nIndex1 =0;
        for(int l_nIndex=0;l_nIndex< data.count();l_nIndex++)
        {
            QPointF(x,y);
            x = polyline.at(l_nIndex).x();
            y = polyline.at(l_nIndex).y();
            //qDebug()<<x<<y;
            if(x!=0.0 || y!=0.0 )
            {
                zoomPolyline[l_nIndex1] = QPointF(x,y);
                l_nIndex1++;
            }
        }
//        if( m_nClearID == id)
//        	painter->setPen(Qt::black);
        //else
        	QPen pen;
        	painter->setPen(colorForIds[uint(id) %6]);
//        	pen.setColor(colorForIds[uint(id) %6]);
//            pen.setWidth(20);
//            painter->setPen(pen);


        if(m_ZoomFlag == false)
        {
        	painter->setPen(colorForIds[uint(id) %6]);
                painter->drawPolyline(polyline);
//            qDebug()<<"Band:"<<m_objPlotData->m_nEnvelopBand;
            //compareCurvePoints(polyline1);
        }
        else
            painter->drawPolyline(zoomPolyline);
        }
   // qDebug() << "Exit Draw Cruves.";
}

Plotter::~Plotter()
{
    //delete ui;
}


PlotSettings::PlotSettings()
{
    minX = 0.0;
    maxX = 0.0;
    numXTicks = 10;

    minY = 0.0;
    maxY = 0.0;
    numYTicks = 8;
    m_nOffset=0.0;

}

PlotSettings::PlotSettings(double pMaxX,double pMaxY,double pXTicks,double pYTicks,double pOffset,double pMinX=0.0,double pMinY=0.0)
{
    minX = pMinX;
    maxX = pMaxX;
    numXTicks = pXTicks;

    minY = pMinY;
    maxY = pMaxY;
    numYTicks = pYTicks;
    m_nOffset = pOffset;

}


void PlotSettings::scroll(int dx, int dy)
{
    double stepX = spanX(); // numXTicks
    minX += dx * stepX;
    maxX += dx * stepX;

    double stepY = spanY(); // numYTicks
    minY += dy * stepY;
    maxY += dy * stepY;
}

void PlotSettings::adjust()
{
    adjustAxis(minX,maxX,numXTicks);
    adjustAxis(minY,maxY,numYTicks);
}

void PlotSettings::adjustAxis(double &min, double &max, int &numTicks)
{
    const int MinTicks = 4;
    double grossStep = (max-min)/ MinTicks;
    double step = pow(10.0,floor(log10(grossStep)));

    if( 5* step<grossStep)
        step *=5;
    else if( 2*step < grossStep)
        step *=2;
    numTicks = int(ceil(max/step) - floor(min/step));
    if( numTicks<MinTicks)
        numTicks = MinTicks;
    min = floor(min/step)* step;
    max = ceil(max/step)* step;
}
