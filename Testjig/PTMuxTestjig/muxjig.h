#ifndef MUXJIG_H
#define MUXJIG_H

#include <QWidget>
#include <QPushButton>
#include <qradiobutton.h>
#include <qpluginloader.h>
#include <qdebug.h>
#include <qmessagebox.h>

#include "IPSOCCommunication.h"
#include "AppdeviceRegisterDetails.h"
#include "ApplicationCardInterface.h"
#include "appcardcomponents.h"
#include "ad5318components.h"
#include "BackPlaneInterface.h"
#include "PTAppBckPsocInterface.h"


namespace Ui {
    class MuxJig;
}
class customRadioButton;
class MuxJig : public QWidget {
    Q_OBJECT
public:
    MuxJig(QWidget *parent = 0);
    ~MuxJig();
    void enableRichGUI();

    customRadioButton *testBut[64],*refBut[64];
    unsigned int testSelected,refSelected;
protected:
    IPTAppBckPsocInterface *test;
    IntefaceBackPlane *IBackPlane;
    IApplicationCardInterface *IAppCard;
	IPSOCCOMMUNICATION *IPsoc;
    AD5318Components *m_objAD5318Component;
    AD5318_DACSELECT m_eSelect;

    void changeEvent(QEvent *e);

private:
    Ui::MuxJig *ui;

private slots:
        void on_readCodeId_clicked();
        void on_switchExtMux_clicked();
        void on_pushButton_5_clicked();
        void on_resetBothCh_clicked();
 void on_resetRefCh_clicked();
 void on_resetTestCh_clicked();
 void on_reset_2_clicked();
    void on_reset_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
    void switchTestChannel(int);
    void switchRefChannel(int);

};
class customRadioButton:public QRadioButton{
	Q_OBJECT
public:
	customRadioButton(int radIndex,QWidget *p=0):QRadioButton(p){
	m_nIndex=radIndex;
	setStyleSheet("QRadioButton{font:bold 14px;} QRadioButton::indicator {    width: 18px;     height:18px;	 border-radius:10px;	 border:1px solid black; } QRadioButton::indicator::unchecked {		background-color:white;     }     QRadioButton::indicator:unchecked:hover {		background-color:white;     }     QRadioButton::indicator:unchecked:pressed {		background-color:white;     }     QRadioButton::indicator::checked {		background-color:#f2a400;}          QRadioButton::indicator:checked:hover {		background-color:#f2a400;     }     QRadioButton::indicator:checked:pressed {		background-color:#f2a400;     }");
	connect(this,SIGNAL(clicked()),this,SLOT(pass()));
	}

public slots:
	void pass(){
		emit customClicked(m_nIndex);
	}
protected:
	int m_nIndex;
	signals:
		void customClicked(int);

};
#endif // MUXJIG_H
