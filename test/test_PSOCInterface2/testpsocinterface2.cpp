#include "testpsocinterface2.h"
#include "ui_testpsocinterface2.h"

testPSOCInterface2::testPSOCInterface2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::testPSOCInterface2)
{
    ui->setupUi(this);

    QPluginLoader loader3("libPTPsocInterface.so",this);
    IPsoc = qobject_cast<IPSOCCOMMUNICATION*>(loader3.instance());
    IPsoc->openSerial();

}

testPSOCInterface2::~testPSOCInterface2()
{
    delete ui;
}

void testPSOCInterface2::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void testPSOCInterface2::on_readCodeID_clicked()
{
    ui->showCodeID->setText(QString::number(IPsoc->readPsocCodeID(),16));
}
