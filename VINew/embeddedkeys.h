#ifndef EMBEDDEDKEYS_H
#define EMBEDDEDKEYS_H

#include <QtGui/QWidget>
#include <QtGui>

#include "ui_embeddedkeys.h"
#include <vimodelview.h>
//#include "PTGPIOEventInterfaces.h"
#include "PTEventInterfaces.h"


#define LEFT 		0
#define MIDDLE 	1
#define RIGHT 		2

class EmbeddedKeys : public QMainWindow,public virtual IVIObserver
{
    Q_OBJECT
public:
    EmbeddedKeys(QWidget *parent = 0,VIModel* p_objVISubject=0);
    ~EmbeddedKeys();
    void notifySubject()
    {
    }
    void updateVI(){}

    void notifyProbeObserver(){}
    void notifyClipObserver(){}
protected:
//    PTGPIOEventInterface *IGPIOEvent;
    PTEventInterface *IPTKeyEvent;
    unsigned char whoIsActive;
    void hightlight(QWidget*);
    void customEvent(QEvent *eve);
    void doPTKeyFunction();
    int m_nKeyCode,m_nPTKeyCode;
    void clickedPRSCR();
    void initialiseKeyCombinations();
    VIModel *m_objSubject;
    QMap<QString,QList<QString> >m_lstKeyCombinations;
private:
    Ui::EmbeddedKeysClass ui;
private slots:
    void on_butRigth_clicked();
    void on_butMiddle_clicked();
    void on_butLeft_clicked();
    void on_butClose_clicked();

    void on_cmbCombinationKeys_currentIndexChanged(QString);
};

#endif // EMBEDDEDKEYS_H
