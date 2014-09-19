#ifndef FLASHMEMORY_H
#define FLASHMEMORY_H

#include <QWidget>
#include <InterfacePTLibrary.h>
#include "PTSPIMemoryInterface.h"
#include "ApplicationCardInterface.h"
#include "BackPlaneInterface.h"
#include "PTSplashScreen.h"
#include "qpluginloader.h"
#include "messagewidget.h"
#include <QStringList>
#include <QFileDialog>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QtCore>
#include <qsettings.h>


#define     MAX_MEM_SIZE       256






namespace Ui {
    class Widget;
}

class Widget : public QWidget {
    Q_OBJECT
public:
    Widget(QWidget *parent = 0);
    ~Widget();

    QLineEdit *m_objstAddr,*m_objendAddr,*m_objIndexLocation,*m_objEditData,*m_objDataCount,*m_objAddrCount,*m_objEraseAddr;
protected:
    void changeEvent(QEvent *e);
    void initializeTable();
    void initializeLineEdits();
    void initialiseDataValues();
    void initializeHWInterfaces();
    void updateTableWidget();
    void clearTableWidget();
    void clearMemLocations(short int);
    void changeTableIndex(bool);
    void callSingleDrive();
    void callSingleRead();

    void enableRichGUI();

    void LoadFile(QString);
    IQmaxLineEdit *ILineEdit;
    IQmaxNumberPanel *INumberPanel;
    ISPIMemoryInterface *ISPIMemory;
    IntefaceBackPlane *IBackPlane; ////BackPlaneInterfacePlugin
    IApplicationCardInterface *IAppCard;
    PTSplashScreen *ISplashScreen;


    void openNumKBPanel(short int);
    void openNumKBPanel(short int,double,char,double,double,QWidget*);
    int m_nLineEditIndex;
    unsigned short int  *m_nMEMLOCATIONS;
    unsigned short int m_nHWIndex;
    unsigned short int m_nMemIndex;
    unsigned short int m_nEditData;
    QString m_strFillValue;
    //data class will be moved in future

    unsigned int m_nStartAddress,m_nEndAddress,m_nAdressCount,m_nEraseAddress,m_nIndexLocation,m_nDataCount;
    unsigned short m_nRow,m_nCol;


    //Settings
    void saveSettings();
    void loadSettings();
    void LoadSettingsData();
    QString m_strFLASHSettingsFile;
private:
    Ui::Widget *ui;
    QStringList m_lstWaveData;
private slots:
    void on_cmbHWSelect_currentIndexChanged(int index);
    void on_butWrite_clicked();
    void on_butRead_clicked();
    //void on_butConfigureMem_clicked();
    //void on_butConfigureAddr_clicked();
    //void on_butWRLoadData_clicked();
    void on_butReadSave_clicked();
    void on_butPageErase_clicked();
    void on_butSaveFile_clicked();
    void on_butLoadFile_clicked();
    void on_butCODEID_clicked();
    void on_butErase_clicked();

    void receiveValue(unsigned int);
    void receiveValue(double);
    void receiveValue(QString);

    void callstAddressEdit();
    void callAddrCoutEdit();
    void callEndAddrEdit();
    void callIndexLocEdit();
    void callPageEraseEdit();
    void callDataCountEdit();
    void callDataEdit();

    void setAddressIndex(int,int);

    void on_optSystemMemory_clicked();
    void on_optDDR_clicked();
    void on_optRAM_clicked();
    void on_optFlash_clicked();
    void on_optReceiveRAM_clicked();
    void on_optSlot0_clicked();
    void on_optSlot1_clicked();
    void on_optSlot2_clicked();
    void on_optSlot3_clicked();
    void on_chkSingle_clicked();

    void on_optZeros_clicked();
    void on_optFFs_clicked();


};
#endif // FLASHMEMORY_H
