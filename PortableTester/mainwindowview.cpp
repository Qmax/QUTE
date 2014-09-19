#include "mainwindowview.h"
#include <QPainterPath>
#include <QGraphicsPathItem>
#include <QtPlugin>
#include <QPluginLoader>
#include <QMessageBox>
#include <QThread>
#include <QLinearGradient>
#include <QGraphicsProxyWidget>

MainWindowView::MainWindowView(QWidget *parent):QWidget(parent)
{
    m_objWidget = parent;
}

void MainWindowView::timerTimeout()
{
    QTime objTime = QTime::currentTime();
    m_objDate = QDateTime::currentDateTime();
    //qDebug() << "executing thread id - "<<m_objDate;
    InitHeaderView(1,"Portable Tester");
}

void MainWindowView::InitHeaderView(int value,QString pTitle)
{
    headerScene = new QGraphicsScene(0,0,800,30);
    headerView = new QGraphicsView(m_objWidget);
    //lbl = new QLabel;
//    lbl->setText("Hello");

    if(value ==0)
    {
        headerView->update();
        //m_objTimeItem->setPlainText(m_strTime);

        QFont font;
        pItem->setPlainText(pTitle);
        pItem->setDefaultTextColor(QColor(Qt::white));
        font.setBold(true);
        font.setPointSize(20);
        font.setFamily("DejaVu Sans");
        pItem->setFont(font);

        return;
    }

    m_objTimeItem = new QGraphicsTextItem(0, headerScene);

    headerScene->removeItem(m_objTimeItem);		//ravivar added 04_09_12

    QColor color1(0,40,60,255);
    QColor color2(0,70,100,255);
    QLinearGradient gradient(QPointF(100, 100), QPointF(200, 200));
    gradient.setColorAt(0, color1);
    gradient.setColorAt(1, color2);

    headerScene->addRect(0,0,800,30,QPen(Qt::black),QBrush(gradient));//QBrush(QColor(37,57,72,255)));
    //QGraphicsProxyWidget *proxy = headerScene->addWidget(lbl);

    QPixmap obj1 = QPixmap(":/Symbols/MainScreen.png");
//    QBrush obj2 = QBrush(obj1);
//    obj2.setStyle(Qt::TexturePattern);
    //obj2.setTexture(obj1);

    headerScene->addPixmap(obj1);
    m_objTimeItem->setPos(600,2);
    //m_objTimeItem->setPlainText(m_strTime);
    headerScene->addItem(m_objTimeItem);
    pItem = new QGraphicsTextItem(0, headerScene);
    //pItem1 = new QGraphicsTextItem(0, headerScene);

    pItem->setPlainText(pTitle);
    pItem->setDefaultTextColor(QColor(Qt::white));
    QFont font;

    QDateTime l_obj= QDateTime::currentDateTime();
//    QString l_strTime = l_obj.toString(Qt::TextDate);
//    l_strTime = m_strTime;
    //QDateTime::toString("YYYY-MM-DDTHH:MM:SS");

    //lbl->setGeometry(600,0,150,50);
    //lbl->setText(m_strTime);

    //qDebug() << "time" <<m_strTime ;
    font.setFamily("DejaVu Sans");
    font.setBold(false);
    font.setPointSize(20);
    pItem->setFont(font);
    pItem->setPos(2,1);
    //pItem1->setFont(font);
   // pItem1->setPos(600,2);;
    //pItem1->setDefaultTextColor(QColor(Qt::white));
   // pItem1->setPlainText(l_strTime);
    m_objTimeItem->setPos(10,10);
    m_objTimeItem->setFont(font);

    //pItem1->setPlainText(l_strTime );
    headerView->setGeometry(1,1,800,30);
    headerView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    headerView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    headerView->setFrameShape(QFrame::NoFrame);
    headerView->setScene(headerScene);
}

void MainWindowView::InitBasePane()
{
/*    basepaneScene = new QGraphicsScene(0,500,700,200);
    //basepaneScene->setBackgroundBrush(QBrush(QColor(188,190,192,255)));
    QPixmap obj1 = QPixmap(":/Symbols/simple_gray.png");
        QBrush obj2 = QBrush(obj1);
        obj2.setStyle(Qt::TexturePattern);
        obj2.setTexture(obj1);
    basepaneScene->setBackgroundBrush(obj2);
    basepaneView = new QGraphicsView(m_objWidget);

    QPixmap obj3 = QPixmap(":/Symbols/ivory_texture1.png");
    QBrush obj4 = QBrush(obj1);
    obj4.setStyle(Qt::TexturePattern);
    obj4.setTexture(obj3);

    QPolygonF myPolygon;
    myPolygon << QPointF(130.0,530.0)<<QPointF(100.0,580.0)<<QPointF(700.0,580.0)<<QPointF(670.0,530.0);
    basepaneScene->addPolygon(myPolygon,QPen(Qt::transparent,20),QBrush(obj4));//QColor(255,255,255,55)));

    basepaneView->setGeometry(0,500,700,200);
    basepaneView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    basepaneView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    basepaneView->setFrameShape(QFrame::NoFrame);
    basepaneView->setScene(basepaneScene);*/
}

MainWindowView::~MainWindowView()
{
    headerScene = NULL;
    headerView = NULL;

    mainpaneScene = NULL;
//    mainpaneView = NULL;

    sidepaneScene = NULL;
//    sidepaneView = NULL;

    basepaneScene = NULL;
    basepaneView = NULL;
    //delete headerScene,headerView;
}

void MainWindowView::InitPrimaryView()
{
    entireScene = new QGraphicsScene(0,0,800,600);
    entireView = new QGraphicsView(m_objWidget);
    QPixmap obj1 = QPixmap(":/images/simple_gray.png");
    QBrush obj2 = QBrush(obj1);
    obj2.setStyle(Qt::TexturePattern);
    obj2.setTexture(obj1);

    entireView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    entireView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    entireView->setFrameStyle(QFrame::Plain|QFrame::Sunken);

    entireView->setBackgroundBrush(obj2);

    entireView->setScene(entireScene);
    entireView->setGeometry(0,0,800,600);

    //connect(button1,SIGNAL(clicked(int)),this,SLOT(checkSlot(int)));


}

void MainWindowView::InitTitleView()
{
    titleScene = new QGraphicsScene(120,80,400,25);
    titleView = new QGraphicsView(m_objWidget);

    QColor color1(0,40,60,255);
    QColor color2(0,70,100,255);
    QLinearGradient gradient(QPointF(100, 100), QPointF(200, 200));
    gradient.setColorAt(0, color1);
    gradient.setColorAt(1, color2);

    titleScene->addRect(120,80,400,25,QPen(Qt::white),gradient);//QBrush(QColor(37,57,72,255)));
    titleView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    titleView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    titleView->setFrameStyle(QFrame::Panel|QFrame::Plain);
    QPixmap obj1 = QPixmap(":/Symbols/Application.png");
    titleView->setLineWidth(1);
    titleView->setStyleSheet("background: transparent");
    titleScene->addPixmap(obj1);
    titleView->setScene(titleScene);
    //titleScene->addRect(120,80,400,20,QPen(Qt::red),QBrush(QColor(37,57,72,255)));
    QGraphicsTextItem* pItem = new QGraphicsTextItem(0, titleScene);
    QFont font;
    pItem->setPos(120,80);
    pItem->setPlainText("Applications");
    pItem->setDefaultTextColor(QColor(Qt::white));
    font.setBold(true);
    font.setPointSize(15);
    font.setFamily("DejaVu Sans");
    pItem->setFont(font);

    titleView->setGeometry(120,80,400,25);
}

void MainWindowView::InitMainPane()
{
    //objWid->show();

    mainpaneScene = new QGraphicsScene(120,100,400,300);
    mainpaneView = new QGraphicsView(m_objWidget);
    mainpaneView->setWindowModality(Qt::ApplicationModal);
    QColor color(89,88,88,255);
    QPixmap obj1 = QPixmap(":/Symbols/PTFront.PNG");
    QBrush obj2 = QBrush(obj1);
    obj2.setStyle(Qt::TexturePattern);
    obj2.setTexture(obj1);
    //mainpaneScene->addItem(obj);
    // Button Creation---------------------------------------------------------------
    //mainpaneScene->addItem(roundRectPath);
    //-------------------------------------------------------------------]]
    mainpaneView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    mainpaneView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    mainpaneView->setFrameStyle(QFrame::Panel|QFrame::Plain);
    mainpaneView->setLineWidth(1);
    mainpaneView->setStyleSheet("background: transparent");
    //mainpaneScene->addRect(110,50,400,20,QPen(Qt::black),QBrush(QColor(37,57,72,255)));
    QGraphicsProxyWidget proxy;

    mainpaneView->setScene(mainpaneScene);
    mainpaneView->setBackgroundBrush(obj2);
    mainpaneView->setGeometry(120,100,400,250);
    InitTitleView();
}


void MainWindowView::checkSlot(int pIndex)
{
    emit buttonClicked(pIndex);
}

void MainWindowView::pressed(int pIndex)
{
    emit buttonClicked(pIndex);
}

void MainWindowView::InitSidePane()
{
    QColor color(89,88,88,255);
    QPixmap obj1 = QPixmap(":/Symbols/PTFront.PNG");
    QBrush obj2 = QBrush(obj1);
    obj2.setStyle(Qt::TexturePattern);
    obj2.setTexture(obj1);

    sidepaneScene = new QGraphicsScene(700,35,100,560);
    sidepaneView = new QGraphicsView(m_objWidget);
    sidepaneView->setGeometry(700,35,100,400);
    sidepaneScene->addRect(700,35,100,560,QPen(color),QBrush(color));
    sidepaneView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    sidepaneView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    sidepaneView->setFrameStyle(QFrame::Panel | QFrame::Raised);
    sidepaneView->setLineWidth(1);
     sidepaneView->setBackgroundBrush(obj2);
      sidepaneView->setScene(sidepaneScene);
    sidepaneView->setGeometry(700,35,100,560);
}

void MainWindowView::hideWindows()
{
	qDebug() << "Hide WIndows";
//    mainpaneView->close();
//    titleView->close();
    entireView->close();
//    sidepaneView->close();
//    basepaneView->close();
    
}

void MainWindowView::showWindows()
{
//	qDebug() << "Show WIndows";
//    mainpaneView->show();
//    titleView->show();

    entireView->show();
//    sidepaneView->show();
//    basepaneView->show();
}

void MainWindowView::closeButtons()
{

}

void MainWindowView::showButtons()
{

}


