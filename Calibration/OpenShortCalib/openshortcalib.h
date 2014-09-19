#ifndef OPENSHORTCALIB_H
#define OPENSHORTCALIB_H

#include <QWidget>
#include "BackPlaneInterface.h"
#include "hardwareinterface.h"
#include "ad7190component.h"

namespace Ui {
    class OpenShortCalib;
}

class OpenShortCalib : public QWidget {
    Q_OBJECT
public:
    OpenShortCalib(QWidget *parent = 0);
    ~OpenShortCalib();

    void Initialization();
    void HardwareInitialization();
    void readADC();
    void GetDisplayInductance(double p_nData,short int p_nRange);
    void GetDisplayCapcitance(double p_nData,short int p_nRange);
    void GetDisplayResistance(double pResistanceValue,double pRangeValue);
    void initialiseFeedBackResistance();



protected:
    IntefaceBackPlane *IBackPlane;
    HardwareInterface *hwInterface;
    IApplicationCardInterface *IAppCard;
    AD7190Component *m_objAD7190Component;
    AD5318Components *m_objAD5318Component;
    AD5318_DACSELECT m_eSelect;
    QTimer *ADCtimer;

    double l_nAIN1,l_nAIN2;
    unsigned int m_nADC1Voltage,m_nADC2Voltage;
    int C_Index,R_Index,L_Index;
    double m_nResistance,m_nCapacitance,m_nInductance;
    double m_nImpedanceValue;
    double m_nFrequency;

    unsigned short m_nICMMGR;

    QList<double>m_lstRFResistance;
    QList<double>m_lstRFCapcitance;
    QList<double>m_lstRFInductance;

    double m_dOffset,m_dNull;
    bool m_bNull;
    QString micro,ohms,kiloOhms,picoFarad,nanoFarad,microFarad,milliFarad,microHenry,milliHenry,Henry;

    void changeEvent(QEvent *e);

private:
    Ui::OpenShortCalib *ui;

private slots:

private slots:
    void on_pbClose_released();
    void on_pbClose_pressed();
    void on_pbCalibrate_released();
    void on_pbCalibrate_pressed();
    void on_pbStop_released();
    void on_pbStop_pressed();
    void on_pbMeasure_released();
    void on_pbMeasure_pressed();
    void on_pbCalibrate_clicked();
    void on_pbStop_clicked();
    void on_pbMeasure_clicked();
    void on_cmbRRange_currentIndexChanged(int index);
    void on_cmbLRange_currentIndexChanged(int index);
    void on_cmbCRange_currentIndexChanged(int index);
    void on_chkCalibrated_clicked(bool checked);
    void on_chkLoad_clicked(bool checked);
    void on_chkShort_clicked(bool checked);
    void on_chkOpen_clicked(bool checked);
    void on_cmbCompnt_currentIndexChanged(int index);
    void on_pbClose_clicked();
};

#endif // OPENSHORTCALIB_H
