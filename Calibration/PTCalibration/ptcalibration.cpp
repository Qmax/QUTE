/***********************************************************
***************Created by Ravivarman.R,Qmax*****************
***********************************************************/
#include "ptcalibration.h"
#include "ui_ptcalibration.h"

#include <QPlastiqueStyle>
#include <QCleanlooksStyle>
#include <QWindowsXPStyle>
#include <QWindowsVistaStyle>
#include <QMotifStyle>
#include <QCDEStyle>

PTCalibration::PTCalibration(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PTCalibration)
{
    ui->setupUi(this);
    setStyle(new QPlastiqueStyle);
}

PTCalibration::~PTCalibration()
{
    delete ui;
}

void PTCalibration::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void PTCalibration::on_pushButton_clicked()
{
}

void PTCalibration::on_comboBox_5_currentIndexChanged(int index)
{
    switch(index){
    case 0:
        setStyle(new QPlastiqueStyle);
        break;
    case 1:
        setStyle(new QCleanlooksStyle);
        break;
    case 2:
        setStyle(new QMotifStyle());
        break;
    case 3:
        setStyle(new QCDEStyle());
        break;

    }
}

void PTCalibration::on_exitBut_2_clicked()
{
    this->close();
}
