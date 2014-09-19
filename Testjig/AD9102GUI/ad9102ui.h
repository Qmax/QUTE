#ifndef AD9102UI_H
#define AD9102UI_H

#include <QWidget>

#include <QLineEdit>
#include <qpluginloader.h>
#include <QtCore>
#include <QObject>
#include <unistd.h>

#include "ApplicationCardInterface.h"
#include "InterfacePTLibrary.h"
#include "AD9102.h"

namespace Ui {
    class AD9102UI;
}

class AD9102UI : public QWidget {
    Q_OBJECT
public:
    AD9102UI(QWidget *parent = 0);
    void enableRichGUI();
    ~AD9102UI();

    AD9102Component *AD9102;
    QString FileName,SRAMFileName;
    QStringList RegvalFiles;

protected:
    IApplicationCardInterface *IAppCard;

    unsigned short m_nAddress,m_nData;
    unsigned short m_nAppAddress,m_nAppData;
    unsigned short m_nSRAMAddress,m_nSRAMData;
    unsigned short m_nSRAMStartddress,m_nSRAMCount;
    unsigned short m_nDelay;
    unsigned int m_nFrequency,m_nPhase;

    IQmaxLineEdit *ILineEdit;
    IQmaxNumberPanel *INumberPanel;

    QLineEdit *objAddress,*objData;
    QLineEdit *objAppAddress,*objAppData;
    QLineEdit *objDelay;
    QLineEdit *objSRAMAddress,*objSRAMData;
    QLineEdit *objSRAMStartddress,*objSRAMCount;
    QLineEdit *objFrequency,*objPhase;

    short int m_nLineEditIndex;

    void openNumKBPanel(short int);
    void openNumKBPanel(short int,double,char,double,double,QWidget*);

    void changeEvent(QEvent *e);

    bool m_bTriggerState,m_bRunStop;

private:
    Ui::AD9102UI *ui;
private slots:
    void on_pushButton_3_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
    void on_pb_TestRead_clicked();
    void on_pb_TestRUN_clicked();
    void on_pb_SRAMUpdate_clicked();
    void on_pb_SRAMLoad_clicked();
    void on_pb_SRAMWrite_clicked();
    void on_pb_SRAMRead_clicked();
    void on_pb_Update_clicked();
    void on_comboBox_currentIndexChanged(int index);
    void on_pb_TestWrite_clicked();
    void on_pb_Trigger_clicked();
    void on_pb_Reset_clicked();
    void on_pb_Test_clicked();
    void on_pb_AppWrite_clicked();
    void on_pb_AppRead_clicked();
    void on_pb_Write_clicked();
    void on_pb_Read_clicked();
    void receiveValue(unsigned int);
    void receiveValue(double);
    void receiveValue(QString);

    void callAddressEdit();
    void callDataEdit();
    void callAppAddressEdit();
    void callAppDataEdit();
    void callDelay();
    void callSRAMAddress();
    void callSRAMData();
    void callSRAMStartAddress();
    void callSRAMCount();
    void callFrequency();
    void callPhase();
};

#endif // AD9102UI_H
