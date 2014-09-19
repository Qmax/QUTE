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
    m_ncheckColor = QColor(88,88,89,255);
    m_nXPoint = m_nYPoint =0;
    setGeometry(0,0,buttonSize.width(),buttonSize.height());
    //this->setCursor(Qt::PointingHandCursor);
    if(pType == 1|| pType == 0 || pType == 5)
        this->logicalSize = QSize(buttonSize.width(),buttonSize.height());
    else
        this->logicalSize = QSize(buttonSize.width(),buttonSize.height());
        //this->logicalSize = QSize(int((buttonSize.width()/2.0f)-5),int(buttonSize.height()*1.5f));
//    if(pType == 3)
//        this->logicalSize = QSize(int((buttonSize.width() / 2.0f) - 5), int(buttonSize.height() * 1.5f));
    refreshButton();
}
void QmaxButton::setStyle(QString style){
	this->setStyleSheet(style);
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

void QmaxButton::setTextPoints(int pX,int pY)
{
	m_nXPoint = pX;
	m_nYPoint = pY;
	refreshButton();
}
void QmaxButton::createSideButton(QPainter &painter)
{
    QRect scaledRect;
    scaledRect = matrix.mapRect(QRect(0,0,this->logicalSize.width(),this->logicalSize.height()));
    QColor color1(80,85,85,255);
    QColor color(189,198,198,255);
    QColor color2(155,150,158,255);
    QColor checkColor(37,57,72,255);
    QColor checkColor2(88,88,89,255);
    QPoint start(0,40);
    QPoint end(40,80);
    QLinearGradient gradient(start,end);
    QLinearGradient brush1(0,0,0,scaledRect.height());
    QPen pen(QBrush(color),2);
    if(m_nPressed && m_nStatus==false)
    {
        painter.setPen(Qt::NoPen);
        gradient.setColorAt(0,checkColor);
        gradient.setColorAt(1,checkColor);
    }
    else if(m_nPressed == false)
    {
        painter.setPen(Qt::NoPen);
        gradient.setColorAt(0,QColor(0,0,0,0));
        gradient.setColorAt(1,QColor(0,0,0,0));
    }
    if(m_nStatus)
    {
        painter.setPen(Qt::NoPen);
		gradient.setColorAt(0,QColor(0,0,0,0));
		gradient.setColorAt(1,QColor(0,0,0,0));
        //painter.setPen(Qt::NoPen);
        //gradient.setColorAt(0,m_ncheckColor);
        //gradient.setColorAt(1,m_ncheckColor);
    }
    painter.setBrush(gradient);
    painter.drawRect(0,0,100,80);
    painter.drawPixmap(15, 15, this->m_strImage);
    QFont font;
    font.setFamily("DejaVu Sans");

	font.setBold(false);
	font.setPointSize(20);

    painter.setFont(font);

    brush1.setColorAt(1.0f,QColor(255,255,127,255));
    if(this->isEnabled()==false)
    {
        brush1.setColorAt(1.0f,QColor(200,200,200,100));
    }
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(QPen(brush1,1));
    painter.setBrush(brush1);
    QFontMetrics fMetrics = painter.fontMetrics();
    QSize sz = fMetrics.size( Qt::TextWordWrap, m_strText );
    QRectF txtRect( scaledRect.center(), sz );
    //int xPoint = (scaledRect.width()/2)- ((m_strText.count()/2));
    //int yPoint = scaledRect.height()/2;
    painter.drawText(m_nXPoint,m_nYPoint,m_strText);

}

void  QmaxButton::createArrowBackground(QPainter &painter)
{
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

         if(m_nType==3 || m_nType == 4)
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
    if (m_nType == 3)
        sizey *= -1;
    QPainterPath path;
    path.moveTo(xOff, yOff + (5 * sizey));
    path.lineTo(xOff - (4 * sizex), yOff - (3 * sizey));
    path.lineTo(xOff + (4 * sizex), yOff - (3 * sizey));
    path.lineTo(xOff, yOff + (5 * sizey));
    painter.drawPath(path);

}

QString QmaxButton::getImage()
{
	return this->m_strImage;
}

void QmaxButton::changeImage(QString pStrImage)
{
	this->m_strImage = pStrImage;
	refresh();
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
    painter.drawImage(-2, -2, bg);


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

         if(m_nType&& m_nType!=5)
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
            brush.setColorAt(0.0f,m_ncheckColor);
            painter.setPen(QPen(outlinebrush,1));
        }

        painter.setBrush(brush);

    }


    if(m_nType == 1)
        painter.drawRect(0,0,scaledRect.width(),scaledRect.height());
    else if(m_nType ==0)
        painter.drawRoundedRect(0,0,scaledRect.width(),scaledRect.height(),40.0,40.0,Qt::RelativeSize); //20.0,25.0
    else if(m_nType == 5)
        painter.drawEllipse(0,0,scaledRect.width(),scaledRect.height());
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
    if(m_nType == 0 || m_nType == 1 || m_nType == 5)
        createButton(painter);
    else if(m_nType ==2 )
        createSideButton(painter);
    else if(m_nType ==3 ){
        createArrowBackground(painter);
    }
    else if(m_nType ==4 )
        createArrowBackground(painter);

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

void QmaxButton::changeColor(QColor pColor)
{
	m_ncheckColor = pColor;
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




