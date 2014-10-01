#ifndef DACFWIDGET_H
#define DACFWIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QFile>
#include <QTextStream>
#include <QPluginLoader>
#include "InterfacePTLibrary.h"

namespace Ui {
    class DACFWidget;
}

class DACFWidget : public QWidget {
    Q_OBJECT
public:
    DACFWidget(QWidget *parent = 0);
    ~DACFWidget();

protected:
    IQmaxLineEdit *ILineEdit;
    IQmaxNumberPanel *INumberPanel;
    QLineEdit *OffsetValueEdit;
    short int m_nLineEditIndex;

    QString values[5];

    void openNumKBPanel(short int);
    void changeEvent(QEvent *e);

private:
    Ui::DACFWidget *ui;

private slots:
    void on_butExit_clicked();
    void on_butSave_clicked();
    void callOffsetValue();
    void receiveValue(unsigned int pValue);
     void receiveValue(double);
     void receiveValue(QString);

};

#endif // DACFWIDGET_H
