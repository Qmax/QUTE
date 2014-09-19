/*
 *      Author: Ravivarman.R,Qmax
 */
#ifndef PTLIBRARYINTERFACES_H
#define PTLIBRARYINTERFACES_H
#include <QList>
#include <QMap>
#include <QWidget>
#include <qlineedit.h>
#include <qpushbutton.h>
struct PT_MENU
{
    QString m_strButtonCaption;
    double m_nXPos;
    double m_nYPos;
    int m_nHeight;
    int m_nWidth;
    QString m_strDescription;
    QString m_strImageName;
};

class IQmaxPTLibrary
{
public:
    virtual void InitPTLibrary(QString,QString)=0;
    virtual QList<PT_MENU*> ReadPanel(QString)=0;
};

class IQmaxNumberPanel
{
public:
     virtual QWidget* getNumKBPanel(short int,QWidget *parent=0)=0;
     virtual QWidget* getNumKBPanelIncDec(short int,double incRatio,char type,double,double,QWidget *parent=0)=0;
     //virtual unsigned int  getNumKBValue()=0;
};

class IQmaxLineEdit
{
public:
    virtual QLineEdit* getLineEdit(short int,int,int,int,int,QString,QWidget *parent=0)=0;
    virtual QLineEdit* QmaxLineEdit(short int,QWidget *parent=0)=0;
};

class IQmaxMessageBox
{
public:
	virtual bool QMsgBox(bool,bool,QString,QString,QString,QWidget *parent=0)=0;
    virtual QPushButton* GetAbortButton()=0;
    virtual QPushButton* GetConnectButton()=0;
    virtual bool GetmsgBoxLiveStatus()=0;
    virtual void SetmsgBoxLiveStatus(bool)=0;
};
QT_BEGIN_NAMESPACE
Q_DECLARE_INTERFACE(IQmaxPTLibrary,"IQmaxPTLibrary/1.0")
Q_DECLARE_INTERFACE(IQmaxNumberPanel,"IQmaxNumberPanel/1,0")
Q_DECLARE_INTERFACE(IQmaxLineEdit,"IQmaxLineEdit/1,0")
Q_DECLARE_INTERFACE(IQmaxMessageBox,"IQmaxMessageBox/1,0")
QT_END_NAMESPACE
#endif // PTLIBRARYINTERFACES_H
