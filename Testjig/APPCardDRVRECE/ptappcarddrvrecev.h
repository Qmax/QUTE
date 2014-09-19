#ifndef PTAPPCARDDRVRECEV_H
#define PTAPPCARDDRVRECEV_H

#include <QWidget>
#include <QDebug>
#include <ApplicationCardInterface.h>
#include <QPluginLoader>
#include <BackPlaneInterface.h>
#include "AppdeviceRegisterDetails.h"
#include <PTLibraryInterfaces.h>
#include <QGraphicsScene>
#include <QGraphicsView>

namespace Ui {
    class PtAppCardDrvRecev;
}

class PtAppCardDrvRecev : public QWidget {
    Q_OBJECT
public:
    PtAppCardDrvRecev(QWidget *parent = 0);
    ~PtAppCardDrvRecev();
    void enableRichGUI();

protected:
    void changeEvent(QEvent *e);
    unsigned short m_nDRSER;
    unsigned short m_nDSAR;
    unsigned short m_nDRGSR;
    unsigned short m_nR1CR;
    unsigned short m_nR2CR;
    unsigned short m_nICMMGR;
    unsigned short int m_nLineEditIndex,m_nAddress,m_nData;

    QLineEdit *m_objLE_ADDR;
    QLineEdit *m_objLE_DATA;


    DSAR m_objDSAR;
    DRSER m_objDRSER;

    void InitialiseHWLibraries();
    void openNumKBPanel(short int pValue) ;
    IQmaxLineEdit *ILineEdit;
    IQmaxPTLibrary *IPTLibrary;
    IQmaxNumberPanel *INumberPanel;

    IApplicationCardInterface *IAppCard;
    IntefaceBackPlane *IBackPlane;

    QString m_strRelayFile;

private:
    Ui::PtAppCardDrvRecev *ui;

private slots:
    void on_butAppWrite_clicked();
    void on_butAppRead_clicked();
    void on_cmbICMRange_currentIndexChanged(int index);
    void on_chkRece2RMSCAVG_clicked();
    void on_chkRece1RMSCAVG_clicked();
    void on_chkICMBCAPSEL_clicked();
    void on_chkICMIASEL_clicked();
    void on_chkICMGAIN_clicked();
    void on_cmbR2Coupling_currentIndexChanged(int index);
    void on_chkRece2HAIPSEL_clicked();
    void on_chkRece2RMSGAIN_clicked();
    void on_chkRece2RMSIN_clicked();
    void on_chkRece2HAAC_clicked();
    void on_chkRece2ICMEN_clicked();
    void on_chkRece2HSHA_clicked();
    void on_cmbR1Coupling_currentIndexChanged(int index);
    void on_chkRece1HSVI_clicked();
    void on_chkRece1HAIPSEL_clicked();
    void on_chkRece1RMSGAIN_clicked();
    void on_chkRece1RMSIN_clicked();
    void on_chkRece1HAAC_clicked();
    void on_chkRece1HSHA_clicked();
    void on_cmbBPSourceImpedance_currentIndexChanged(int index);
    void on_chkSlotOffsetEN_clicked();
    void on_cmbVISelection_currentIndexChanged(int index);
    void on_cmbSourceSelection_currentIndexChanged(int index);
    void on_chkSRCN_clicked();
    void on_cmbIRS_currentIndexChanged(int index);
    void on_chkVIS_clicked();
    void on_butReceiveRelay_clicked();
    void on_butDriveRelay_clicked();

    void callAddressEdit();
    void callDataEdit();
    void receiveValue(unsigned int pValue);
    void receiveValue(double);
    void receiveValue(QString);

};

#endif // PTAPPCARDDRVRECEV_H
