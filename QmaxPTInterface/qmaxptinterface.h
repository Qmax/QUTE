#ifndef QMAXPTINTERFACE_H
#define QMAXPTINTERFACE_H

#include <QtCore>
#include<InterfacePTLibrary.h>
#include "myinputpanel.h"
#include "displayinfo.h"
#include "numberpanel.h"
#include "widget.h"
#include "qmaxbutton.h"
#include "myLineEdit.h"
#include "qmaxptlibrary.h"
#include "qmaxmessagebox.h"

#include <QMap>

//class  QmaxPTLibrary  {
//public:
//    QmaxPTLibrary(QString pStrFileName,QString pStrWindowName);
//    QList<PT_MENU*> ReadMenuFile(QString);
//    MyInputPanel *m_objInputPanel;
//    NumberPanel *m_objNumberPanel;
//    Widget *m_objTextKBPanel;
//    DisplayInfo *m_objDisplayInfo;
//    MyLineEdit *m_objLineEdit;
//    unsigned int m_nNumber;
//protected:
//    QMap<QString, QList<PT_MENU*> > *m_mapMainWindowMenus;
//    QString m_strWindowName,m_strFileName;
//
//
//};
//QmaxPTLibrary *g_objQmaxPTLibrary;
//extern "C"
//{
//    void InitPTLibrary(QString,QString);
//    QList<PT_MENU*> ReadPanel(QString);
//    MyInputPanel* getInputPanel(QWidget *);
//    DisplayInfo*  getDisplayInfoPanel(QWidget *);
//    NumberPanel*  getNumKBPanel(short int,QWidget *parent);
//    NumberPanel*  getNumKBPanelIncDec(short int,double incRatio,char type,double,double,QWidget *parent);
//    MyLineEdit*   getLineEdit(short int,int,int,int,int,QString,QWidget *);
//    Widget*  getTextKBPanel(QWidget *);
//    unsigned int  getNumKBValue();
//
//
//}

#endif // QMAXPTINTERFACE_H
