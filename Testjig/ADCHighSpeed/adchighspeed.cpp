#include "adchighspeed.h"
#include "ui_adchighspeed.h"

ADCHighSpeed::ADCHighSpeed(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ADCHighSpeed)
{
    ui->setupUi(this);

    QPluginLoader loaderApp("libPTApplicationcardInterface.so", this);
    IAppCard = qobject_cast<IApplicationCardInterface*> (loaderApp.instance());
    IAppCard->setDeviceName(SLOT0);
    IAppCard->enumerateAPPCard();
    IAppCard->setSPIAppendBit(0xC000);

    ui->appCardCodeID->setText(QString::number(IAppCard->readAppCardCodeId(),16));

    objISLA118P50=new ISLA118P50Component(IAppCard);
}

ADCHighSpeed::~ADCHighSpeed()
{
    delete ui;
}

void ADCHighSpeed::changeEvent(QEvent *e)
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

void ADCHighSpeed::on_readCodeID_clicked()
{
    ui->codeID->setText(QString::number(objISLA118P50->readChipID(),16));
}

void ADCHighSpeed::on_readVersion_clicked()
{
    ui->version->setText(QString::number(objISLA118P50->readChipVersion(),16));
}

void ADCHighSpeed::on_readVersion_2_clicked()
{
     unsigned short int pAddress=0,pData=0;

        pAddress = pAddress | ONE_BYTE;
        pAddress = pAddress | PORT_CONFIG;
        pAddress = pAddress | READ_MODE;

        IAppCard->setSPITXMSW(pAddress,SPI5);
        IAppCard->setSPITXLSW(0xFFFF,SPI5);
        IAppCard->setSPICW(DRIVE_32BIT,SPI5);
        IAppCard->readSPIDriveDoneBit(SPI5);
        usleep(1000);

        qDebug()<<"RXMSW:"<<hex<<IAppCard->getSPIRXMSW(SPI5);
        qDebug()<<"RXLSW:"<<hex<<IAppCard->getSPIRXLSW(SPI5);
}

void ADCHighSpeed::on_readVersion_3_clicked()
{
    unsigned short int pAddress=0,pData=0;

    pAddress = pAddress | ONE_BYTE;
    pAddress = pAddress | PORT_CONFIG;
    pAddress = pAddress & WRITE_MODE;

    pData = 0x80; //4-wire mode
//    pData = pData << 8;

    IAppCard->setSPITXMSW(pAddress,SPI5);
    IAppCard->setSPITXLSW(pData,SPI5);
    IAppCard->setSPICW(DRIVE_24BIT,SPI5);
    IAppCard->readSPIDriveDoneBit(SPI5);
    usleep(1000);
}
