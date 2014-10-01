#ifndef OFFSETWINDOW_H
#define OFFSETWINDOW_H

#include <QtGui/QWidget>
#include "ui_offsetwindow.h"
#include <qdebug.h>

class OffsetWindow : public QWidget
{
    Q_OBJECT

public:
    OffsetWindow(QWidget *parent = 0);
    ~OffsetWindow();
protected:
    short int m_nSelectedDACIndex;

private:
    Ui::OffsetWindowClass ui;
signals:
	void passDACValue(short int,double);


private slots:
    void on_dblDACSpin_valueChanged(double pValue);
    void on_m_rbDACA_clicked();
    void on_m_rbDACB_clicked();
    void on_m_rbDACC_clicked();
    void on_m_rbDACD_clicked();
    void on_m_rbDACE_clicked();

};

#endif // OFFSETWINDOW_H
