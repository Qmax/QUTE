#ifndef MAINWINDOWVIEW_H
#define MAINWINDOWVIEW_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsTextItem>
#include <QTime>
#include <QMainWindow>
#include <stdio.h>
#include <QSignalMapper>
#include <QGraphicsSceneMouseEvent>
#include <QMouseEvent>
#include <QLibrary>
#include "qmaxbutton.h"


//struct PT_MENU
//{
//    QString m_strButtonCaption;
//    double m_nXPos;
//    double m_nYPos;
//    int m_nHeight;
//    int m_nWidth;
//    QString m_strDescription;
//};

class TimerThread : public QThread
{
    Q_OBJECT

public:
    TimerThread() { }
    QDateTime m_objDate;
    void run()
    {
        qDebug() << "new thread id " << QThread::currentThreadId();
        doWork();
    }

public slots:
    void doWork()
    {
        QTime objTime = QTime::currentTime();
        m_objDate = QDateTime::currentDateTime();
        qDebug() << "executing thread id - " << QThread::currentThreadId();
    }
};

class MainWindowView:public QWidget
{
Q_OBJECT
public:
    MainWindowView(QWidget *parent = 0);
    void InitHeaderView(int,QString);
    void InitPrimaryView();
    void InitTitleView();
    void InitMainPane();
    void InitSidePane();
    void InitBasePane();
    void showWindows();
    void hideWindows();
    void closeButtons();
    void showButtons();
    ~MainWindowView();
    QTimer *timer;
    QDateTime m_objDate;
    QString m_strTime ;
    QGraphicsTextItem *m_objTimeItem;
public slots:
    void checkSlot(int);
    void pressed(int);
    void timerTimeout();

signals:
    void buttonClicked(int);

protected:
    TimerThread *objTimerThread;
    QWidget *m_objWidget;
    QSignalMapper *signalMapper;
    QGraphicsScene* headerScene;
    QGraphicsView *headerView;

    QGraphicsScene *mainpaneScene;
    QGraphicsView *mainpaneView;

    QGraphicsScene *sidepaneScene;
    QGraphicsView *sidepaneView;

    QGraphicsScene *basepaneScene;
    QGraphicsView *basepaneView;

    QGraphicsView *entireView;
    QGraphicsScene *entireScene;

    QGraphicsView *titleView;
    QGraphicsScene *titleScene;
    QGraphicsTextItem* pItem;
    QGraphicsTextItem* pItem1;
    QLabel *lbl;
signals:
public slots:
};

class CustomItem : public QGraphicsItem
{
public:
    CustomItem(QGraphicsItem *parent=0): QGraphicsItem(parent){}

    QRectF boundingRect() const
    {
        return QRectF(0, 0, 250, 250);
    }

    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget)
    {
        Q_UNUSED(option);
        Q_UNUSED(widget);
        painter->setRenderHint(QPainter::Antialiasing);
        QColor color(55,191,191,30);
        painter->setBrush(QBrush(color));

        // Rounded Rectangle
        //painter->drawRect(125,110,390,280);
        painter->drawRoundedRect(90,100,400,30, 15, 15);
    }
    QPixmap pixmap;
//private:
//    QPolygonF polygon;
//    QPainterPath path;
};



#endif // MAINWINDOWVIEW_H
