#include "dmmutility.h"
#include "ui_dmmutility.h"

DMMUtility::DMMUtility(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DMMUtility)
{
    ui->setupUi(this);
    setGeometry(0,0,270,80);
    ui->label_2->setText("m"+QString(QChar(0x2126)));
}

DMMUtility::~DMMUtility()
{
    delete ui;
}

void DMMUtility::changeEvent(QEvent *e)
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

void DMMUtility::on_pushButton_12_clicked()
{
    if(geometry().height()==80){
        setGeometry(0,0,270,145);
        ui->pushButton_12->setText("Shrink");
    }
    else if(geometry().height()==200){
        setGeometry(0,0,270,80);
        ui->pushButton_12->setText("Expand");
    }
    else if(geometry().height()==145){
        setGeometry(0,0,270,80);
        ui->pushButton_12->setText("Expand");
    }

}

void DMMUtility::on_pushButton_13_clicked()
{
    if(geometry().height()==80){
        setGeometry(0,0,270,200);
        ui->pushButton_13->setText("Manual");
         ui->pushButton_12->setText("Shrink");
    }
    else if(geometry().height()==145){
        setGeometry(0,0,270,200);
        ui->pushButton_13->setText("Manual");
         ui->pushButton_12->setText("Shrink");
    }
    else if(geometry().height()==200){
        setGeometry(0,0,270,145);
        ui->pushButton_13->setText("Auto");
         ui->pushButton_12->setText("Shrink");
    }
}
