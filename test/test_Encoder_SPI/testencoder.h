#ifndef TESTENCODER_H
#define TESTENCODER_H

#include <QtCore>
#include <QTimer>
#include <unistd.h>
#include <QLineEdit>
#include <QMainWindow>
#include <qpluginloader.h>
#include <qdesktopwidget.h>
#include "BackPlaneInterface.h"
#include "PTLibraryInterfaces.h"
#include "PTGPIOEventInterfaces.h"

#define BP_SPIFLASH_CMD   0x0028
#define BP_SPIFLASH_TXLSW   0x002A
#define BP_SPIFLASH_TXMSW   0x002C
#define BP_SPIFLASH_RXLSW   0x2E
#define BP_SPIFLASH_RXMSW   0x0030
#define BP_SPI_BUSY 0x0
#define BP_SPI_STP_DRV     0x60

#define		INT0		0x0100
#define		KNOBINT		0x0800

const QEvent::Type KnobEvent = (QEvent::Type) 3456;//magnetic knob
const QEvent::Type GpioEvent = (QEvent::Type) 1234;//embedded probe


namespace Ui {
    class TestEncoder;
}

class TestEncoder : public QMainWindow {
    Q_OBJECT
public:
    TestEncoder(QWidget *parent = 0);
    ~TestEncoder();

protected:
    void changeEvent(QEvent *e);
    void customEvent(QEvent *e);

    IntefaceBackPlane *IBackPlane;
    unsigned short int spiData,m_nEncoder,m_nSwitch;
    QTimer *SPItimer;

    void openNumKBPanel(short int pValue) ;
    void openNumKBPanelminmax(short int pValue,double pMax,double pMin);

    unsigned int m_nLineEditIndex;
    IQmaxLineEdit *ILineEdit;
    IQmaxPTLibrary *IPTLibrary;
    IQmaxNumberPanel *INumberPanel;
    PTGPIOEventInterface *IGPIOEvent;
    int m_nKeyCode;

    QLineEdit *m_objLE_ADDR;
    QLineEdit *m_objLE_DATA;


private:
    Ui::TestEncoder *ui;

    unsigned short m_nAddress;
    unsigned short m_nData;

private slots:
        void on_pbData_clicked();
 void on_pbAddr_clicked();
 void readSPI();
    void on_pushButton_clicked();
    void on_stop_clicked();
    void on_exit_clicked();

    void callAddressEdit();
    void callDataEdit();
    void receiveValue(unsigned int pValue);
    void receiveValue(double);
    void receiveValue(QString);
};

#endif // TESTENCODER_H
