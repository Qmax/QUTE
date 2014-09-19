#ifndef VISETTINGS_H
#define VISETTINGS_H

#include <QtGui/QWidget>
#include "ui_visettings.h"
#include "InterfacePTLibrary.h"
#include <QFile>
#include <QXmlStreamWriter>




class VISettings : public QWidget
{
    Q_OBJECT

public:
    VISettings(QWidget *parent = 0);
    ~VISettings();
    void openNumKBPanel(short int pValue);

    IQmaxNumberPanel *INumberPanel;
    IQmaxLineEdit *ILineEdit;

    QLineEdit *m_objTicksEdit;
    int m_nLineEditIndex;
    short int m_nTick;

private:
    void readVISettings();
    Ui::VISettingsClass ui;
private slots:
	void callTicksEdit();
    void receiveValue(unsigned int);
    void on_butOK_clicked();
    void saveSettingsXML();

};

#endif // VISETTINGS_H
