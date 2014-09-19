#ifndef SELECTPROBE_H
#define SELECTPROBE_H

#include <QDialog>
#include <QLabel>
#include "qmaxbutton.h"
#include <qpluginloader.h>
#include "vimodelview.h"
//#include "clipdialog.h"
#include "InterfacePTLibrary.h"
#include <qlistwidget.h>

//#include "BackPlaneInterface.h"
#include "PTEventInterfaces.h"


namespace Ui {
    class SelectProbe;
}

namespace Ui {
    class SelectProbe;
}

class SelectProbe : public QDialog,public IVIObserver {
    Q_OBJECT
public:
    SelectProbe(QWidget *parent=0,VIModel *pObjSubject=0);
    ~SelectProbe();
     QString getProbeData() const;
     void showProbeWindow();
     void notifySubject(){}
     void updateVI(){}
     void notifyProbeObserver(){}
     void notifyClipObserver(){}

 signals:
     void closed();
     void dialogClosed();
protected:
     //IntefaceBackPlane *IBackPlane;	//BackPanel Interface
     void closeEvent(QCloseEvent *event);
     IQmaxNumberPanel *INumberPanel;
     IQmaxLineEdit *ILineEdit;

     PTEventInterface *IPTKeyEvent;

    void changeEvent(QEvent *e);
    virtual void hideEvent ( QHideEvent * event );
    void openNumKBPanel(short int pValue);
protected:

    void customEvent(QEvent *eve);
    void doPTKeyFunction();
    int m_nKeyCode,m_nPTKeyCode;
    bool selectProbeState;
    VIModel *m_objProbeSubject;

    //void changeEvent(QEvent *e);
    QString m_strSelectedProbe;
    //QLabel *m_strProbe;
    QmaxButton *m_but;
    //QRadioButton *m_opt1,*m_opt2;
    QLineEdit *m_objThresholdEdit;
    //QLibrary *m_objPTLibrary;
//    QLibrary *backPlaneLibrary;
    int m_nLineEditIndex;
private:
    Ui::SelectProbe *ui;
    public slots:
    void closeWindow();
private slots:
        void on_butOK_clicked();
        void on_butAdvSetup_clicked();
        void on_optAverage_clicked();
        void on_optLinear_clicked();
        void on_optResistance_clicked();
        void on_optCapcitance_clicked();
        void on_optInductance_clicked();
        void on_optDiode_clicked();
        void on_optAll_clicked();
        void selectPacakage(QListWidgetItem*);
        void callThresHoldEdit();
        void receiveValue(double);
        void receiveValue(unsigned int pValue);
        void on_chkCommonGnd_clicked();

};

#endif // SELECTPROBE_H
