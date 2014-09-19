#ifndef CLIPDIALOG_H
#define CLIPDIALOG_H

#include <QDialog>
#include <vimodelview.h>
#include <qlibrary.h>
#include <QDialog>
#include <QtGui>
#include "InterfacePTLibrary.h"
#include "PTEventInterfaces.h"


//const QEvent::Type PTKeyEvent = (QEvent::Type) 5678;
namespace Ui {
    class ClipDialog;
}

class ClipDialog : public QDialog,public virtual IVIObserver {
    Q_OBJECT
public:
    ClipDialog(QWidget *parent=0,VIModel* pObjSUbj=0);
    ~ClipDialog();
    void notifySubject(){}
    void updateVI(){}
    void notifyProbeObserver(){}
    void notifyClipObserver(){}
    IQmaxLineEdit *ILineEdit;
    IQmaxNumberPanel *INumberPanel;

    signals:
         void closed();

protected:
    PTEventInterface *IPTKeyEvent;

    VIModel *m_objClipDialogSubject;
    QLineEdit *m_objPinsEdit,*m_objRefChannelEdit,*m_objThresholdEdit;
    int m_nLineEditIndex;
    unsigned int m_nPins;
    void openNumKBPanel(short int);
    void clickedPRSCR();

    QMessageBox *msgBox;
    QPushButton *connectButton,*abortButton;
    bool msgBoxLive;

    bool clipDialogState;

    void customEvent(QEvent *eve);
    void doPTKeyFunction();
    void LoadClipDefaultValues();
    int m_nKeyCode,m_nPTKeyCode;

protected:
    void changeEvent(QEvent *e);
    bool showMessageBox(bool ok,bool cancel,QString text, QString okText,QString calcelText);
private slots:
        void on_objFixedOption_2_clicked();
        void on_objFixedOption_clicked();
        //void on_pushButton_clicked();
        void receiveValue(unsigned int pValue);
        void receiveValue(double);
        void callPinsEdit();
        void callRefChannelEdit();
        void callThresHoldEdit();
        void on_butClose_clicked();
        void on_butOK_clicked();
        void on_optAverage_clicked();
        void on_optLinear_clicked();
        void on_chkStoponFail_clicked();
         void selectClip(QListWidgetItem*);
private:
    Ui::ClipDialog *ui;
};

#endif // CLIPDIALOG_H
