#ifndef APPCARDRELAYREAD_H
#define APPCARDRELAYREAD_H

#include <QWidget>
#include <QPushButton>
#include <QDebug>
#include <QtCore>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "InterfacePTLibrary.h"

#include "ApplicationCardInterface.h"
#include "BackPlaneInterface.h"

namespace Ui {
    class AppCardRelayRead;
}

class AppCardRelayRead : public QWidget {
    Q_OBJECT
public:
    AppCardRelayRead(QWidget *parent = 0);
    ~AppCardRelayRead();

    void Initialization();
    void enableRichGUI();

	short int m_nLineEditIndex;
    QLineEdit *objAddress,*objData;

signals:
    void bitSelected(bool,short);

protected:
    IQmaxLineEdit *ILineEdit;
    IQmaxNumberPanel *INumberPanel;
    IApplicationCardInterface *IAppCard;
    IntefaceBackPlane *IBP;

    void openNumKBPanel(short int);
    void openNumKBPanel(short int,double,char,double,double,QWidget*);

    void changeEvent(QEvent *e);
    void setRelayPanel();
    void updateRelayStatus(unsigned int);
    void updateICMVIRelayStatus(unsigned int);
    void readDrvRecvRelays();
    void readICMVIPiggyRelays();
    QPushButton *m_objPushButtons[27];
    QPushButton *m_objICMVIButtons[9];
    bool m_nRelayPoint;
    unsigned int m_nRelayDetails;
    short int m_nICMVIrlyDetails;
    unsigned int m_nAddressValue,m_nDataValue;
private:
    Ui::AppCardRelayRead *ui;

private slots:
	void receiveValue(unsigned int);
	void receiveValue(double);
	void receiveValue(QString);

	void callAddressEdit();
	void callDataEdit();
    void on_butReadRelay_clicked();
    void on_butWrite_clicked();
    void on_butREAD_clicked();
    void changeColor(bool,short);
};

#endif // APPCARDRELAYREAD_H
