#ifndef PORTABLETESTER_H
#define PORTABLETESTER_H

#include "mainwindowview.h"
#include <unistd.h>
#include <QMainWindow>
#include <QtGui/QMainWindow>
#include <QtGui>
#include <StdAPI.h>
#include <QPainter>
#include <QGraphicsScene>
#include <QTableWidget>
#include <QGraphicsView>
#include <QStylePainter>
#include <QPushButton>
#include <QMessageBox>
#include <QGraphicsBlurEffect>
#include <QGraphicsEffect>
#include <QPropertyAnimation>
#include <QPixmap>
#include <QSplashScreen>
#include <QProcess>
#include <QWSServer>
#include <QEvent>
//#include <Qmax/hwid/HardwareClient.h>
#include "qmaxbutton.h"
#include "BackPlaneInterface.h"
#include "ApplicationCardInterface.h"
#include "IPSOCCommunication.h"
#include "PTEventInterfaces.h"
#include "PTGPIOEventInterfaces.h"
#include "InterfacePTLibrary.h"
#include "GPIOInterfaces.h"
#include "IHWIDInterface.h"
#include "UtilityWidgetInterface.h"
#include "operatorInterface.h"
#include "QDigitalClock.h"
#include "logindialog.h"
#include "FGAppInterface.h"
#include "PTToolBoxInterface.h"
#include "DSOCardInterface.h"

//~~~~~~~~~~~DMM SPI Back Panel Registers~~~~~~~~~~~~~
#define DMM_CMD_BP             0x0036
#define DMM_ADDR_BP            0x0038
#define DMM_DATA_TX_MSW_BP     0x003C
#define DMM_DATA_TX_LSW_BP     0x003A
#define DMM_DATA_RX_MSW_BP     0x0040
#define DMM_DATA_RX_LSW_BP     0x003E
#define DMM_CLK_DIV_BP         0x0042
#define DMM_RLY_SEL_BP         0x0044
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#define _DMM_ 0
#define _VI_  1
#define _FG_  2
#define _SL_  3
#define _ICM_ 4
#define _DSO_ 5

#define _UP_   20
#define _DOWN_ 21

const QEvent::Type PTKeyEvent = (QEvent::Type) 5678;
const QEvent::Type ShutDownEvent=  (QEvent::Type) 7890;//shutdown

#define APPLICATIONS 9
#define FUNCTIONS	 6

namespace Ui {
class PortableTester;
}
class QmaxPushButton:public QPushButton{
        Q_OBJECT
public:
        QmaxPushButton(int pIndex,QWidget *p=0):QPushButton(p){
			m_nIndex=pIndex;
			setStyleSheet("QPushButton{background-color:rgba(0,0,0,0); border: 2px solid rgba(0,0,0,0);border-radius: 25px;}");
			setFocusPolicy(Qt::NoFocus);
			if(pIndex==6||pIndex==7||pIndex==8||pIndex==9 ||pIndex==15){
					setIconSize(QSize(70,70));
					QGraphicsDropShadowEffect* effect	= new QGraphicsDropShadowEffect();
					effect->setOffset(4,8);
					effect->setBlurRadius(3);
					setGraphicsEffect(effect);
			}
			else{
				setIconSize(QSize(96,96));
				QGraphicsDropShadowEffect* effect	= new QGraphicsDropShadowEffect();
				effect->setOffset(1,1);
				effect->setBlurRadius(1);
				setGraphicsEffect(effect);
			}


			connect(this,SIGNAL(clicked()),this,SLOT(pass()));
			connect(this,SIGNAL(pressed()),this,SLOT(shrink()));
			connect(this,SIGNAL(released()),this,SLOT(expand()));
        }

public slots:
        void pass(){
                emit CClicked(m_nIndex);
        }
        void shrink(){
        	if(m_nIndex==17||m_nIndex==18)
        		setIconSize(QSize(50,25));
        	else
        		setIconSize(QSize(60,60));
        }
        void expand(){
        	if(m_nIndex==17||m_nIndex==18)
        		setIconSize(QSize(24,24));
        	else if(m_nIndex==6||m_nIndex==7||m_nIndex==8||m_nIndex==9||m_nIndex==15)
				setIconSize(QSize(70,70));
        	else
        		setIconSize(QSize(96,96));

        }

protected:
        int m_nIndex;
        signals:
          void CClicked(int);

};
class PortableTester : public QMainWindow {
	Q_OBJECT
public:
	QFrame *baseFrame;
	QString argument;
	IPTComponentsInterface *IPT;
	PortableTester(QWidget *parent = 0);
	~PortableTester();
	void clickedPRSCR();
	void paintEvent(QPaintEvent *pEvent);
	QPixmap background;
	bool dmmPlugin,slPlugin,viPlugin,fgPlugin,icmPlugin;
	unsigned int myID;
	QSplashScreen *splashIdle;
	bool m_bTouchFlag;
    QProcess process;
    QDigitalClock *clock;
protected:
    IPTFGAppInterface *ptFG;

    IntefaceBackPlane *IBackPlane;	////BackPlaneInterfacePlugin
    IPSOCCOMMUNICATION *IPsoc;				//PSOC Interface Plugin
    IApplicationCardInterface	*IAppCard;
    PTEventInterface	*IPTKeyEvent;
    PTGPIOEventInterface	*IGPIOEvent;
    InterfaceGPIOPins *IGPIOPin;
    IHWIDInterface *IHWID;
    UtilityInterface *IUtility;

    IQmaxPTLibrary *IptLib;
    IQmaxNumberPanel *INumberPanel;
    IQmaxLineEdit *ILineEdit;

    IPTToolBoxInterface *toolBox;
    IDSOCardInterface *IDSOCard;

	QMessageBox *msgBox;
	QPushButton *connectButton,*abortButton,*cancelButton;
	bool msgBoxLive;
	char showMessageBox(bool,bool,bool,QString,QString,QString,QString);
	void Functions(int);
	void UpDownButton(int);
        u_int32_t readDMMSPI(u_int16_t _Address);
        void writeDMMSPI(u_int16_t _Address, u_int16_t _Data);
	void changeEvent(QEvent *e);

	void customEvent(QEvent *eve);
	int m_nGPIOCode,m_nPTKeyCode,m_nPTShutDown;
	QTimer *objTimer,*idleTimer;
	MainWindowView *l_objMainView;
	int selectedX, selectedY;
	int preX,preY;
	QPointF startPos;
	QPointF endPos;
	QLibrary *MyLib,*m_DMMLibrary,*m_ICMLibrary,*m_FGLibrary,*m_VILibrary,*m_SLLibrary,*m_checkLibrary;
	bool isWindowOpen;
	void initialitation();

	// Application Panel & Functional Panel Buttons;
	QmaxButton *AppButtons[6],*FunctionalButtons[6];
	void CreateButtons(QWidget *pWidget,QString);
	void closeButtons();
	void showButtons();
	QLabel m_TimeLabel;

    QmaxPushButton *shutDownButton,*testjigButton;
    QmaxPushButton *shlocButton;
    QmaxPushButton *AppButton[APPLICATIONS],*FunctionalButton[FUNCTIONS];
    QmaxPushButton *prevButton,*nextButton;
    QPushButton *glowButton[APPLICATIONS];
	void CreateButton();

	void on_shutDownButton_clicked();
	void on_testjigButton_clicked();

    bool m_nPassword;

private:
	Ui::PortableTester *ui;

public slots:
        void startFG();
	void buttonPressed(int);
	void poweroff();
	void houseKeeping();
	void UnHide();
	void checkButton();
	void idleScreen();
    void slotAcceptUserLogin(QString& name,QString& password);

};




#endif // PORTABLETESTER_H
