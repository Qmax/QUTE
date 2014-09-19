#include "arbitary.h"
#include "ui_arbitary.h"

Arbitary::Arbitary(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Arbitary)
{
    ui->setupUi(this);
    setWindowTitle("Arbitary Waveform Generator");

    m_nAmplitude=0.5;

    m_nFrequency=10;
    m_nTime=(1/m_nFrequency)*10;

    waveCount=-1;

    createGridPanel();
    createLabels();
    updateXAxis();
    updateYAxis();

    this->showFullScreen();
}

Arbitary::~Arbitary()
{
    delete ui;
}

void Arbitary::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void Arbitary::createLabels()
{
   for(int l_nIndex=0;l_nIndex<10;l_nIndex++)
    {
       objGraphicsText[l_nIndex] = m_objGridscene->addText("");
       objGraphicsText[l_nIndex]->setDefaultTextColor(Qt::white);

   }
   for(int l_nIndex=0;l_nIndex<20;l_nIndex++)
    {
       objGraphicsTextX[l_nIndex] = m_objGridscene->addText("");
       objGraphicsTextX[l_nIndex]->setDefaultTextColor(Qt::white);

   }
}

void Arbitary::createGridPanel()
{
    QRectF l_nRect(4,4,789,452);
    m_nRectF = l_nRect;
    m_objGridview = new QGraphicsView(ui->groupBox_2);
    m_objGridscene = new QGraphicsScene(4,4,789,452,ui->groupBox_2);
    m_objGridview->setGeometry(4,4,789,452);
    m_objGridview->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_objGridview->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_objGridview->setFrameStyle(QFrame::Plain);
    m_objGridItem = m_objGridscene->addRect(l_nRect, QPen(Qt::NoPen), QBrush(QColor(89,89,89,255)));
    QPen pen;
    pen.setWidthF(1.0);

    for(int i=10;i<l_nRect.height();i+=10)     {
        if(i%40==0){
            pen.setBrush(Qt::white);
            pen.setStyle(Qt::SolidLine);
            m_objGridscene->addLine(l_nRect.left()+20,i,l_nRect.left()+30,i,pen);   //Amplitude Label Dot lines
        }
        pen.setBrush(Qt::darkBlue);
        pen.setStyle(Qt::DotLine);
        m_objGridscene->addLine(l_nRect.left()+m_nMargin,i,l_nRect.width(),i,pen); //Horizontal grid lines
       }

    pen.setBrush(Qt::darkBlue);
    pen.setStyle(Qt::DotLine);

     for(int i=0;i<l_nRect.width();i+=10) {
         if(i>30){
           pen.setBrush(Qt::darkBlue);             pen.setStyle(Qt::DotLine);
           m_objGridscene->addLine(i,l_nRect.left(),i,l_nRect.width(),pen);     //Vertical grid lines

           if(i%40==0){
               pen.setBrush(Qt::white);           pen.setStyle(Qt::DotLine);
               m_objGridscene->addLine(i,240,i,230,pen);    //Timebase Label Dot lines
           }


        }

       }
     
    pen.setStyle(Qt::SolidLine);
    pen.setBrush(Qt::lightGray);
    pen.setWidthF(1.0);
    m_objGridscene->addLine(l_nRect.left()+m_nMargin,l_nRect.left(),l_nRect.left()+m_nMargin,l_nRect.bottom(),pen);
    m_objGridscene->addLine(l_nRect.left()+m_nMargin,l_nRect.height()/2,l_nRect.width(),l_nRect.height()/2,pen);
    pen.setBrush(Qt::cyan);
    m_objGridscene->addLine(l_nRect.left()+m_nMargin,l_nRect.height()/2,l_nRect.width(),l_nRect.height()/2,pen);
    m_objGridview->setScene(m_objGridscene);
    m_objGridview->setRenderHints(QPainter::SmoothPixmapTransform);
    m_objGridview->show();

}
void Arbitary::updateYAxis()
{
    QPen pen;
    double l_nYunit = m_nAmplitude;
    short int l_nIndex=0;

    for(int i=0;i<m_nRectF.height();i+=40)
    {
        if(i%40==0)
        {
            pen.setBrush(Qt::white);
            pen.setStyle(Qt::SolidLine);
            objGraphicsText[l_nIndex]->setPos(m_nRectF.left(),i+20);
            objGraphicsText[l_nIndex]->setPlainText(QString::number(l_nYunit,'f',2));
            l_nYunit-=(m_nAmplitude/5.0);
            l_nIndex++;
        }
    }
}
void Arbitary::updateXAxis()
{
    QPen pen;
    double l_nXunit = m_nTime;
    short int l_nIndex=0;


    for(int i=0;i<m_nRectF.width();i+=40)
    {
        if(i%40==0)
        {
            pen.setBrush(Qt::white);
            pen.setStyle(Qt::SolidLine);
            objGraphicsTextX[l_nIndex]->setPos(i+25,240);
            objGraphicsTextX[l_nIndex]->setPlainText(QString::number(l_nXunit-m_nTime,'f',2));
            l_nXunit=l_nXunit+(m_nTime/20);
            l_nIndex++;
        }
    }
}

void Arbitary::on_cmbAmplitude_currentIndexChanged(int index)
{

    switch(index){
    case 0:
        m_nAmplitude=0.5;
        break;
    case 1:
        m_nAmplitude=1.5;
        break;
    case 2:
        m_nAmplitude=3.5;
        break;
    case 3:
        m_nAmplitude=7;
        break;
    case 4:
        m_nAmplitude=13;
        break;
    }
    updateYAxis();
}

void Arbitary::on_sine_clicked()
{
    waveCount++;
    m_objWaveItem = new waveItem(SINE);
    m_objWaveItem->setPos(150*waveCount,176);
    m_objGridscene->addItem(m_objWaveItem);
    m_lstWaveItems.insert(m_lstWaveItems.count(),m_objWaveItem);
    updateWaveform();

}

void Arbitary::on_square_clicked()
{
    waveCount++;
    m_objWaveItem = new waveItem(SQUARE);
    m_objWaveItem->setPos(150*waveCount,177);
    m_objGridscene->addItem(m_objWaveItem);
    m_lstWaveItems.insert(m_lstWaveItems.count(),m_objWaveItem);
    updateWaveform();
}

void Arbitary::on_ramp_clicked()
{
    waveCount++;
    m_objWaveItem = new waveItem(RAMP);
    m_objWaveItem->setPos(150*waveCount,177);
    m_objGridscene->addItem(m_objWaveItem);
    m_lstWaveItems.insert(m_lstWaveItems.count(),m_objWaveItem);
    updateWaveform();

}


void Arbitary::on_triangle_clicked()
{
    waveCount++;
    m_objWaveItem = new waveItem(TRIANGLE);
    m_objWaveItem->setPos(150*waveCount,177);
    m_objGridscene->addItem(m_objWaveItem);
    m_lstWaveItems.insert(m_lstWaveItems.count(),m_objWaveItem);
    updateWaveform();

}

void Arbitary::on_dc_clicked()
{
    waveCount++;
    m_objWaveItem = new waveItem(DC);
    m_objWaveItem->setPos(150*waveCount,177);
    m_objGridscene->addItem(m_objWaveItem);
    m_lstWaveItems.insert(m_lstWaveItems.count(),m_objWaveItem);
    updateWaveform();

}
void Arbitary::updateWaveform(){
    waveItem *selectWaveItem;
    selectWaveItem = getWaveItem();
    qreal l_nX = selectWaveItem->getXPos();
    qDebug()<<"Pos X:"<<selectWaveItem->getXPos()<<"Pos Y:"<<selectWaveItem->getYPos();
    qreal l_nWidth = m_nWidth;
    QPointF l_nPosPoints = selectWaveItem->pos();
    qDebug()<<"Update:"<<"Height:"<<selectWaveItem->getHeight()<<"Width"<<selectWaveItem->getWidth();
    QPen pen;
    pen.setBrush(Qt::cyan);
    pen.setStyle(Qt::SolidLine);
    if(selectWaveItem->getWaveType() == SINE)
    {
        m_objGridscene->addLine(l_nPosPoints.x()+l_nX,l_nPosPoints.y()+m_nHeight/1.5,l_nPosPoints.x()+l_nX,(l_nPosPoints.y())+((m_nRectF.height()/2)-l_nPosPoints.y()),pen);
        m_objGridscene->addLine(l_nPosPoints.x()+(l_nX+l_nWidth),l_nPosPoints.y()+m_nHeight/1.5,l_nPosPoints.x()+(l_nX+l_nWidth),(l_nPosPoints.y())+((m_nRectF.height()/2)-l_nPosPoints.y()),pen);
    }
    else if(selectWaveItem->getWaveType() == RAMP)
    {
        m_objGridscene->addLine(l_nPosPoints.x()+l_nX,l_nPosPoints.y(),l_nPosPoints.x()+l_nX,(l_nPosPoints.y())+((m_nRectF.height()/2)-l_nPosPoints.y()),pen);
        m_objGridscene->addLine(l_nPosPoints.x()+(l_nX+l_nWidth),l_nPosPoints.y()+m_nHeight,l_nPosPoints.x()+(l_nX+l_nWidth),(l_nPosPoints.y())+((m_nRectF.height()/2)-l_nPosPoints.y()),pen);
    }
    else
    {
        m_objGridscene->addLine(l_nPosPoints.x()+l_nX,l_nPosPoints.y()+m_nHeight,l_nPosPoints.x()+l_nX,(l_nPosPoints.y())+((m_nRectF.height()/2)-l_nPosPoints.y()),pen);
        m_objGridscene->addLine(l_nPosPoints.x()+(l_nX+l_nWidth),l_nPosPoints.y()+m_nHeight,l_nPosPoints.x()+(l_nX+l_nWidth),(l_nPosPoints.y())+((m_nRectF.height()/2)-l_nPosPoints.y()),pen);
    }
    selectWaveItem->updateRect();
    selectWaveItem->setFlags(QGraphicsItem::ItemClipsToShape|QGraphicsItem::ItemIsSelectable|QGraphicsItem::ItemIgnoresTransformations);

}
waveItem* Arbitary::getWaveItem()
{
    waveItem *objItem;
    for(int l_nlstIndex=0;l_nlstIndex<m_lstWaveItems.count();l_nlstIndex++)
    {
        objItem = m_lstWaveItems.at(l_nlstIndex);
        qDebug()<<"GetWaveItem:"<<"Height:"<<objItem->getHeight()<<"Width:"<<objItem->getWidth();
        if(objItem->isSelected()==true){
            m_nSelectedItemIndex = l_nlstIndex;
            qDebug()<<"Rect Item Selected:"<<m_nSelectedItemIndex;
            break;
        }
    }
    return objItem;
}

void Arbitary::on_userDefined_clicked()
{
    waveItem *selectWaveItem;
    selectWaveItem = getWaveItem();
    qreal l_nX = selectWaveItem->getXPos();
    qDebug()<<"Pos X:"<<selectWaveItem->getXPos()<<"Pos Y:"<<selectWaveItem->getYPos();
    qreal l_nWidth = m_nWidth;
    QPointF l_nPosPoints = selectWaveItem->pos();
    qDebug()<<"Update:"<<"Height:"<<selectWaveItem->getHeight()<<"Width"<<selectWaveItem->getWidth();
    QPen pen;
    pen.setBrush(Qt::cyan);
    pen.setStyle(Qt::SolidLine);
    if(selectWaveItem->getWaveType() == SINE)
    {
        m_objGridscene->addLine(l_nPosPoints.x()+l_nX,l_nPosPoints.y()+m_nHeight/1.5,l_nPosPoints.x()+l_nX,(l_nPosPoints.y())+((m_nRectF.height()/2)-l_nPosPoints.y()),pen);
        m_objGridscene->addLine(l_nPosPoints.x()+(l_nX+l_nWidth),l_nPosPoints.y()+m_nHeight/1.5,l_nPosPoints.x()+(l_nX+l_nWidth),(l_nPosPoints.y())+((m_nRectF.height()/2)-l_nPosPoints.y()),pen);
    }
    else if(selectWaveItem->getWaveType() == RAMP)
    {
        m_objGridscene->addLine(l_nPosPoints.x()+l_nX,l_nPosPoints.y(),l_nPosPoints.x()+l_nX,(l_nPosPoints.y())+((m_nRectF.height()/2)-l_nPosPoints.y()),pen);
        m_objGridscene->addLine(l_nPosPoints.x()+(l_nX+l_nWidth),l_nPosPoints.y()+m_nHeight,l_nPosPoints.x()+(l_nX+l_nWidth),(l_nPosPoints.y())+((m_nRectF.height()/2)-l_nPosPoints.y()),pen);
    }
    else
    {
        m_objGridscene->addLine(l_nPosPoints.x()+l_nX,l_nPosPoints.y()+m_nHeight,l_nPosPoints.x()+l_nX,(l_nPosPoints.y())+((m_nRectF.height()/2)-l_nPosPoints.y()),pen);
        m_objGridscene->addLine(l_nPosPoints.x()+(l_nX+l_nWidth),l_nPosPoints.y()+m_nHeight,l_nPosPoints.x()+(l_nX+l_nWidth),(l_nPosPoints.y())+((m_nRectF.height()/2)-l_nPosPoints.y()),pen);
    }
    selectWaveItem->updateRect();
    selectWaveItem->setFlags(QGraphicsItem::ItemClipsToShape|QGraphicsItem::ItemIsSelectable|QGraphicsItem::ItemIgnoresTransformations);

}

void Arbitary::on_cmbFrequency_currentIndexChanged(int index)
{
    switch(index){
    case 0:
        m_nFrequency=10;
        m_nTime=(1/m_nFrequency)*10;
        break;
    case 1:
        m_nFrequency=100;
        m_nTime=(1/m_nFrequency)*100;
        break;
    case 2:
        m_nFrequency=1000;
        m_nTime=(1/m_nFrequency)*1000;
        break;
    case 3:
        m_nFrequency=10000;
        m_nTime=(1/m_nFrequency)*10000;
        break;
    case 4:
        m_nFrequency=100000;
        m_nTime=(1/m_nFrequency)*100000;
        break;
    }
    updateXAxis();
}

void Arbitary::on_spinFrequency_valueChanged(double value)
{
    m_nFrequency=value;
    if(m_nFrequency>=1000)
        m_nTime=(1/m_nFrequency)*1000;
    else if(m_nFrequency>=1000000)
        m_nTime=(1/m_nFrequency)*1000000;

    updateXAxis();

}

void Arbitary::on_spinAmplitude_valueChanged(double value)
{
    m_nAmplitude=value/2;
    updateYAxis();
}

void Arbitary::on_userDefined_2_clicked()
{
    this->close();
}
