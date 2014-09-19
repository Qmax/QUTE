#ifndef INTERFACEPTLIBRARY_H
#define INTERFACEPTLIBRARY_H
#include <QObject>
#include <QtCore>
#include <QString>
#include <PTLibraryInterfaces.h>
#include <numberpanel.h>
#include <myLineEdit.h>
#include "qmaxmessagebox.h"




class PTInterfaceObject:public QObject,public IQmaxPTLibrary,public IQmaxNumberPanel,public IQmaxLineEdit, public IQmaxMessageBox
{
    Q_OBJECT
    Q_INTERFACES(IQmaxPTLibrary IQmaxNumberPanel IQmaxLineEdit IQmaxMessageBox)
public:
    // IQmaxPTLibrary Interface
    void InitPTLibrary(QString,QString);
    QList<PT_MENU*> ReadPanel(QString);
    // IQmaxNumberPanel
    NumberPanel* getNumKBPanel(short int,QWidget *parent=0);
    NumberPanel* getNumKBPanelIncDec(short int,double incRatio,char type,double,double,QWidget *parent=0);
    //unsigned int  getNumKBValue();
    // IQmaxLineEdit
    MyLineEdit* getLineEdit(short int,int,int,int,int,QString,QWidget *parent=0);
    MyLineEdit* QmaxLineEdit(short int,QWidget *parent=0);
    bool QMsgBox(bool,bool,QString, QString,QString,QWidget *parent = 0);
    QPushButton* GetAbortButton();
    QPushButton* GetConnectButton();
    bool GetmsgBoxLiveStatus();
    void SetmsgBoxLiveStatus(bool val);
    void CloseMsgBox();

protected:
        QMap<QString, QList<PT_MENU*> > *m_mapMainWindowMenus;
        QString m_strWindowName,m_strFileName;
        NumberPanel *m_objNumberPanel;
        MyLineEdit *m_objLineEdit;
        QmaxMessageBox *m_objMsgBox;
};
#endif // INTERFACEPTLIBRARY_H
