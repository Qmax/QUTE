#include "dmmaccuracy.h"
#include "ui_dmmaccuracy.h"

DMMAccuracy::DMMAccuracy(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DMMAccuracy)
{
    ui->setupUi(this);
    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
}

DMMAccuracy::~DMMAccuracy()
{
    delete ui;
}

void DMMAccuracy::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
void DMMAccuracy::executeSystemCommand(QString Command,QString args){
    QProcess::execute(Command+" "+args);
    QProcess::execute("hwclock --systohc");
}

void DMMAccuracy::on_pushButton_clicked()
{
    close();
}

void DMMAccuracy::on_pushButton_2_clicked()
{
    close();
}



void DMMAccuracy::on_dateTimeEdit_dateTimeChanged(QDateTime date)
{
    QString cmd;
    QString l_strDate=date.toString();
    qDebug()<<l_strDate;
    QStringList l_arryDate=l_strDate.split(" ");
    QStringList l_arryTime=l_arryDate.at(3).split(":");
    if(l_arryDate.at(1)=="Jan")cmd="01"+l_arryDate.at(2)+l_arryTime.at(0)+l_arryTime.at(1)+l_arryDate.at(4);
    if(l_arryDate.at(1)=="Feb")cmd="02"+l_arryDate.at(2)+l_arryTime.at(0)+l_arryTime.at(1)+l_arryDate.at(4);
    if(l_arryDate.at(1)=="Mar")cmd="03"+l_arryDate.at(2)+l_arryTime.at(0)+l_arryTime.at(1)+l_arryDate.at(4);
    if(l_arryDate.at(1)=="Apr")cmd="04"+l_arryDate.at(2)+l_arryTime.at(0)+l_arryTime.at(1)+l_arryDate.at(4);
    if(l_arryDate.at(1)=="May")cmd="05"+l_arryDate.at(2)+l_arryTime.at(0)+l_arryTime.at(1)+l_arryDate.at(4);
    if(l_arryDate.at(1)=="Jun")cmd="06"+l_arryDate.at(2)+l_arryTime.at(0)+l_arryTime.at(1)+l_arryDate.at(4);
    if(l_arryDate.at(1)=="Jul")cmd="07"+l_arryDate.at(2)+l_arryTime.at(0)+l_arryTime.at(1)+l_arryDate.at(4);
    if(l_arryDate.at(1)=="Aug")cmd="08"+l_arryDate.at(2)+l_arryTime.at(0)+l_arryTime.at(1)+l_arryDate.at(4);
    if(l_arryDate.at(1)=="Sep")cmd="09"+l_arryDate.at(2)+l_arryTime.at(0)+l_arryTime.at(1)+l_arryDate.at(4);
    if(l_arryDate.at(1)=="Oct")cmd="10"+l_arryDate.at(2)+l_arryTime.at(0)+l_arryTime.at(1)+l_arryDate.at(4);
    if(l_arryDate.at(1)=="Nov")cmd="11"+l_arryDate.at(2)+l_arryTime.at(0)+l_arryTime.at(1)+l_arryDate.at(4);
    if(l_arryDate.at(1)=="Dec")cmd="12"+l_arryDate.at(2)+l_arryTime.at(0)+l_arryTime.at(1)+l_arryDate.at(4);
    qDebug()<<cmd;
    executeSystemCommand("date",cmd);
}

