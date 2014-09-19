#ifndef DACCALIBRATION_H
#define DACCALIBRATION_H

#include <QtGui/QWidget>
#include "ui_daccalibration.h"
#include <QDebug>
#include <QDesktopWidget>
#include <QLineEdit>
#include <QPluginLoader>
#include "PTLibraryInterfaces.h"
#include <QFile>
#include <QTimer>
#include <QXmlStreamWriter>
class DACCalibration : public QWidget
{
    Q_OBJECT

public:

    DACCalibration(QWidget *parent = 0);
    ~DACCalibration();
    void makeScreenCenter();
    void InitializeCalibration();
    void InitializeLineEditControls();
    void loadQmaxPlugins();
    void readCalibrationFile();

    QTimer *timer;


protected:
    IQmaxLineEdit *ILineEdit;
    IQmaxNumberPanel *INumberPanel;

    QLineEdit *m_objLE_NoOfPoints;
    QLineEdit *m_objLE_ActualValue;
    QLineEdit *m_objLE_RxedValue;

    unsigned int m_nLineEditIndex;

    void openNumKBPanel(short int pValue) ;
    void openNumKBPanelminmax(short int pValue,char type,double pMax,double pMin);

    int m_nNoOfPoints,m_nNoOfSamples;
    double m_nActualValue,m_nRxedValue;

    double m_nSlope[5][9],m_nConstant[5][9],m_nslope,m_nconstant;
    double XVoltage[5][9][5],YVoltage[5][9][5],m_nXVoltage[5],m_nYVoltage[5];

private:
    Ui::DACCalibrationClass ui;
private slots:

    void on_comboBox_2_currentIndexChanged(int index);
    void on_nextBut_clicked();
    void on_exitBut_clicked();
    void on_saveBut_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void callNoOfPointsEdit();
    void callActualValueEdit();
    void callRxedValueEdit();

    void receiveValue(unsigned int pValue);
    void receiveValue(double);
    void receiveValue(QString);
};

#endif // DACCALIBRATION_H
