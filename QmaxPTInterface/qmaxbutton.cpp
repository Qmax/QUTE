#include "qmaxbutton.h"
#include "colors.h"


QmaxButton::QmaxButton(QString pText, QSize buttonSize, QString pImage,int pType, int pUserCode,QWidget *parent):
    QWidget(parent)
{
    this->m_nUserCode = pUserCode;
    this->m_strText = pText;
    this->m_nType = pType;
    this->m_strImage = pImage;
    m_nPressed =0;
    m_nHighlight =1;
    m_nStatus=false;
    setGeometry(0,0,buttonSize.width(),buttonSize.height());
    this->setCursor(Qt::PointingHandCursor);
    if(pType == 1|| pType == 0)
        this->logicalSize = QSize(buttonSize.width(),buttonSize.height());
    else
        this->logicalSize = QSize(buttonSize.width(),buttonSize.height());
        //this->logicalSize = QSize(int((buttonSize.width()/2.0f)-5),int(buttonSize.height()*1.5f));
//    if(pType == 3)
//        this->logicalSize = QSize(int((buttonSize.width() / 2.0f) - 5), int(buttonSize.height() * 1.5f));
    refreshButton();
}

void setGeometry(int pX, int pY, int pWidth, int pHeight)
{
    setGeometry(pX,pY,pWidth,pHeight);
}

void QmaxButton::setState(int pState)
{
    if(pState == 1)
        m_nHighlight =1;
    refreshButton();
}

void QmaxButton::createSideButton(QPainter &painter)
{
    QRect scaledRect;
    scaledRect = matrix.mapRect(QRect(0,0,this->logicalSize.width(),this->logicalSize.height()));
    QColor color1(80,85,85,255);
    QColor color(189,198,198,255);
    QColor color2(155,150,158,255);
    QPoint start(0,40);
    QPoint end(40,80);
    QLinearGradient gradient(start,end);
    QLinearGradient brush1(0,0,0,scaledRect.height());
    QPen pen(QBrush(color),2);
    if(m_nPressed)
    {
        painter.setPen(pen);
        gradient.setColorAt(0,color);
        gradient.setColorAt(1,color2);
    }
    else
    {
        painter.setPen(Qt::NoPen);
        gradient.setColorAt(0,color1);
        gradient.setColorAt(1,color1);
    }
    painter.setBrush(gradient);
    painter.drawRect(0,0,100,80);
    painter.drawPixmap(25, 25, this->m_strImage);
    QFont font( "DejaVu Sans" );
    font.setPointSize( 12 );
    painter.setFont( font );
    brush1.setColorAt(1.0f,QColor(255,255,255,255));
    if(this->isEnabled()==false)
    {
        brush1.setColorAt(1.0f,QColor(200,200,200,100));
    }
    painter.setPen(QPen(brush1,1));
    painter.setBrush(brush1);
    QFontMetrics fMetrics = painter.fontMetrics();
    QSize sz = fMetrics.size( Qt::TextWordWrap, m_strText );
    QRectF txtRect( scaledRect.center(), sz );
    int xPoint = (scaledRect.width()/2)- ((m_strText.count()/2));
    int yPoint = scaledRect.height()/2;
    painter.drawText(xPoint,yPoint,m_strText);

}

void  QmaxButton::createArrowBackground(QPainter &painter)
{

    /*  -------changes by ravivarman --------
      1.Up arrow should be in m_Type of 3,5,7,9
      2.Down arrow should be in m_Type of 4,6,8,10
      3.if up arrow is 3 then down arrow should be the number succeding it i.e 4.
      4.Number less than 3 and greater than 10 will not be accepted.
      5.m_Type number directly proportional to size of up/down arrow.
      */
   // printf("Arrow BackGround2\n");
    QRect scaledRect;
    scaledRect = matrix.mapRect(QRect(0, 0, this->logicalSize.width(), this->logicalSize.height()));

    QImage image(scaledRect.width(), scaledRect.height(), QImage::Format_ARGB32_Premultiplied);
    image.fill(QColor(0, 0, 0, 0).rgba());
    //QPainter painter(image);
    painter.setRenderHint(QPainter::SmoothPixmapTransform);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(Qt::NoPen);
    painter.drawImage(0, 0, image);

    if(Colors::useEightBitPalette)
    {
        painter.setPen(QColor(120,120,120));
        if(this->m_nPressed)
            painter.setBrush(QColor(60,60,60));
        else if(this->m_nHighlight)
            painter.setBrush(QColor(100,100,100));
        else
            painter.setBrush(QColor(80,80,80));
    }
    else
    {
        QLinearGradient outlinebrush(0,0,0,scaledRect.height());
        QLinearGradient brush(0,0,0,scaledRect.height());

        brush.setSpread(QLinearGradient::PadSpread);
        QColor highlight(255,255,255,128);
        QColor shadow(0,0,0,70);
        QColor sunken(220,220,220,30);
        QColor normal1(88,88,89,255);
        QColor normal2(88,88,89,255);
        QColor normal3(0,0,200,10);
        QColor normal4(255,255,250,255);

//         if(m_nType==3 || m_nType == 4)
         if(m_nType>=3 || m_nType <=10)
         {
            normal1 = QColor(100,180,189,55);
            normal2 = QColor(100,180,189,255);
         }
        if(m_nPressed)
        {
            outlinebrush.setColorAt(0.0f,shadow);
            outlinebrush.setColorAt(1.0f,highlight);
            brush.setColorAt(1.0f,sunken);
            painter.setPen(Qt::NoPen);

        }
        else
        {
            outlinebrush.setColorAt(0.75f,shadow);
            outlinebrush.setColorAt(0.0f,highlight);
            brush.setColorAt(0.0f,normal2);
            if(m_nHighlight)
                brush.setColorAt(1.0f,normal1);
            painter.setPen(QPen(outlinebrush,1));
        }
        if(this->isEnabled()==false )
        {
            outlinebrush.setColorAt(1.0f,shadow);
            outlinebrush.setColorAt(0.0f,highlight);
            brush.setColorAt(0.0f,normal3);
            painter.setPen(QPen(outlinebrush,2));

        }
        if(m_nStatus )
        {
            outlinebrush.setColorAt(1.0f,shadow);
            outlinebrush.setColorAt(0.0f,highlight);
            brush.setColorAt(0.0f,normal2);
            painter.setPen(QPen(outlinebrush,1));
        }
        painter.setBrush(brush);

    }


   // painter.drawRect(0, 0, scaledRect.width(), scaledRect.height());

    float xOff = scaledRect.width() / 2;
    float yOff = scaledRect.height() / 2;
    float sizex = 5.0f * matrix.m11();
    float sizey = 3.5f * matrix.m22();
//    if (m_nType == 3)
      if (m_nType%2!= 0)
        sizey *= -1;
    QPainterPath path;
    path.moveTo(xOff, yOff + (5 * sizey));

    if (m_nType%2!= 0){
        m_nType2=m_nType+1;
        path.lineTo(xOff - (m_nType2 * sizex), yOff - (m_nType2 * sizey));
        path.lineTo(xOff + (m_nType2 * sizex), yOff - (m_nType2 * sizey));
    }else
    path.lineTo(xOff - (m_nType * sizex), yOff - (m_nType * sizey));
    path.lineTo(xOff + (m_nType * sizex), yOff - (m_nType * sizey));

//    path.lineTo(xOff - (4 * sizex), yOff - (3 * sizey));
//    path.lineTo(xOff + (4 * sizex), yOff - (3 * sizey));

    path.lineTo(xOff, yOff + (5 * sizey));
    painter.drawPath(path);

}




void  QmaxButton::createButton(QPainter &painter)
{
    QRect scaledRect;
    scaledRect = matrix.mapRect(QRect(0,0,this->logicalSize.width(),this->logicalSize.height()));
    QImage bg(this->m_strImage);
    painter.setRenderHint(QPainter::SmoothPixmapTransform);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(Qt::NoPen);
    QLinearGradient brush1(0,0,0,scaledRect.height());
    painter.drawImage(20, 10, bg);


    if(Colors::useEightBitPalette)
    {
        painter.setPen(QColor(120,120,120));
        if(this->m_nPressed)
            painter.setBrush(QColor(60,60,60));
        else if(this->m_nHighlight)
            painter.setBrush(QColor(100,100,100));
        else
            painter.setBrush(QColor(80,80,80));
    }
    else
    {
        QLinearGradient outlinebrush(0,0,0,scaledRect.height());
        QLinearGradient brush(0,0,0,scaledRect.height());

        brush.setSpread(QLinearGradient::PadSpread);
        QColor highlight(255,255,255,128);
        QColor shadow(0,0,0,70);
        QColor sunken(220,220,220,30);
        QColor normal1(255,255,245,60);
        QColor normal2(255,255,235,10);
        QColor normal3(200,200,200,10);
        QColor normal4(255,255,250,255);

         if(m_nType)
         {
            normal1 = QColor(200,170,160,50);
            normal2 = QColor(50,10,0,50);
         }
        if(m_nPressed)
        {
            outlinebrush.setColorAt(0.0f,shadow);
            outlinebrush.setColorAt(1.0f,highlight);
            brush.setColorAt(1.0f,sunken);
            painter.setPen(Qt::NoPen);

        }
        else
        {
            outlinebrush.setColorAt(1.0f,shadow);
            outlinebrush.setColorAt(0.0f,highlight);
            brush.setColorAt(0.0f,normal1);
            if(m_nHighlight)
                brush.setColorAt(1.0f,normal2);
            painter.setPen(QPen(outlinebrush,1));
        }
        if(this->isEnabled()==false )
        {
            outlinebrush.setColorAt(1.0f,shadow);
            outlinebrush.setColorAt(0.0f,highlight);
            brush.setColorAt(0.0f,normal3);
            painter.setPen(QPen(outlinebrush,1));

        }
        if(m_nStatus )
        {
            outlinebrush.setColorAt(1.0f,shadow);
            outlinebrush.setColorAt(0.0f,highlight);
            brush.setColorAt(0.0f,normal4);
            painter.setPen(QPen(outlinebrush,1));
        }
        painter.setBrush(brush);

    }


    if(m_nType)
        painter.drawRect(0,0,scaledRect.width(),scaledRect.height());
    else
        painter.drawRoundedRect(0,0,scaledRect.width(),scaledRect.height(),20.0,25.0,Qt::RelativeSize);
    QFont font( "DejaVu Sans" );
    font.setPointSize( 12 );
    painter.setFont( font );
    brush1.setColorAt(1.0f,QColor(255,255,255,255));
    if(this->isEnabled()==false)
    {
        brush1.setColorAt(1.0f,QColor(200,200,200,100));
    }
    painter.setPen(QPen(brush1,1));
    painter.setBrush(brush1);
    QFontMetrics fMetrics = painter.fontMetrics();
    QSize sz = fMetrics.size( Qt::TextWordWrap, m_strText );
    QRectF txtRect( scaledRect.center(), sz );
    int xPoint = (scaledRect.width()/2)- ((m_strText.count()/2)*10);
    int yPoint = scaledRect.height()/2;
    painter.drawText(xPoint,yPoint,m_strText);
}


void QmaxButton::refreshButton()
{
    QRect scaledRect;
    scaledRect = matrix.mapRect(QRect(0,0,this->logicalSize.width(),this->logicalSize.height()));
    pixImage = QImage(scaledRect.width(),scaledRect.height(),QImage::Format_ARGB32_Premultiplied);
    pixImage.fill(QColor(0,0,0,0).rgba());
    QPainter painter(&pixImage);
    painter.initFrom(this);
    if(m_nType == 0 || m_nType == 1)
        createButton(painter);
    else if(m_nType ==2 )
        createSideButton(painter);
    else if(m_nType >=3 && m_nType<=10){
            createArrowBackground(painter);
        }
//    else if(m_nType ==3 ){
//        createArrowBackground(painter);
//    }
//    else if(m_nType ==4 )
//        createArrowBackground(painter);

    update();

}

void QmaxButton::setText(QString pText)
{
    m_strText = pText;
    refreshButton();
}

void QmaxButton::paintEvent(QPaintEvent *event)

{
    Q_UNUSED(event);
    QStylePainter painter(this);
    QColor l_objColor;
    QPoint x;
    x.setX(0); x.setY(0);
    bool wasSmoothPixmapTransform = painter.testRenderHint(QPainter::SmoothPixmapTransform);

    //painter.fillRect(pixImage.rect(), QColor(255, 0, 0, 50));
    if(Colors::noRescale)
    {
        painter.drawImage(x,pixImage);
    }
    else
    {
        QMatrix m = painter.worldMatrix();
        painter.setWorldMatrix(QMatrix());
        float x = m.dx();
        float y = m.dy();
        painter.drawImage(QPointF(x, y), pixImage);

    }
    if (!wasSmoothPixmapTransform)
    {
        painter.setRenderHint(QPainter::SmoothPixmapTransform, false);
    }

    painter.end();
}

void QmaxButton::mousePressEvent(QMouseEvent *e)
{
    Q_UNUSED(e);
    m_nPressed =1;
    refreshButton();
}

void QmaxButton::mouseReleaseEvent(QMouseEvent *e)
{
    Q_UNUSED(e);
    m_nPressed=0;
    refreshButton();


    emit clicked(this->m_nUserCode);
}

void QmaxButton::refresh()
{
    refreshButton();
}

void QmaxButton::changeStatus(bool pValue)
{
    m_nStatus = pValue;
    refreshButton();
}

bool QmaxButton::readStatus() const
{
    return m_nStatus;
}




