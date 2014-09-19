#ifndef GPIOEVENTINTERFACE_H
#define GPIOEVENTINTERFACE_H

#include<QtCore>
#include<PTEventInterfaces.h>
#include <QtGui>
#include <QWSKeyboardHandler>
#include <string.h>

#include "/usr/local/DigiEL-5.6/kernel/linux-2.6.31/include/linux/input.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <dirent.h>
#include <linux/input.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/select.h>
#include <sys/time.h>
#include <termios.h>
#include <signal.h>
#include <QSocketNotifier>
#include <QFile>
#include <QString>
#include <QDebug>
#include <QCoreApplication>
#include <QApplication>
#include <QEvent>
#include <QKeyEvent>
#include <QCustomEvent>
#include "qevent.h"
#include "KeyObject.h"
#include <PtKeys.h>

#include <qdebug.h>

#if 1
#define qLog(x) qDebug()
#else
#define qLog(x) while (0) qDebug()
#endif

struct TranslatedKeyEvent
{
    explicit TranslatedKeyEvent(input_event const & event);
    int unicode_;
    int keyCode_;
    bool isPress_;
    bool autoRepeat_;
    private:
    static const int unknownCode = 0xffff;
};


const QEvent::Type PTKeyEventCode = (QEvent::Type) 5678;

class PTKeyEvent:public QWidget,public QWSKeyboardHandler
{
    Q_OBJECT
public:

    PTKeyEvent(QWidget *parent=0,int *pKey=0);
    ~PTKeyEvent();
    int callclosefd();
    void create(QString driver, QString pDevice);
    unsigned int l_nRegisterValue;
    QWidget *m_TW;

private:
    QSocketNotifier *m_notify;
    int  kbdFD;
    bool shift;
    int *m_nKey;
private Q_SLOTS:
    void readKbdData();
};



class PTKeyEventInterface:public QObject,public PTEventInterface
{
    Q_OBJECT
    Q_INTERFACES(PTEventInterface)
public:
    ~PTKeyEventInterface(){}
    void  InvokeGPIOEvent(QWidget *parent,QString driver, QString device,int *pKeyCode);
    void closefd(void);
    bool BlockSig(bool get);
protected:
    PTKeyEvent *g_objKeyevent;
};


class PTKeyPressEvent:public QEvent
{
public:
        //static const QEvent::Type myType = static_cast<QEvent::Type>(2000);
        PTKeyPressEvent(int pKbdData):QEvent((QEvent::Type)1236)
        {
                //PTKeyPressEvent = (QEvent::Type)1234;
                m_nKeycode = pKbdData;
                qLog() << "PTKEYCODE" << hex << pKbdData;
        }
        int m_nKeycode;
public slots:

protected:

};


#endif // GPIOEVENTINTERFACE_H
