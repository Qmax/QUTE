
#include "testkeithley2100lib.h"

testKeithley2100Lib::testKeithley2100Lib(QWidget *parent)
    : QWidget(parent)
{
	ui.setupUi(this);
        ADCTimer = new QTimer(this);
        connect(ADCTimer, SIGNAL(timeout()), this, SLOT(ADCRead()));

        QPluginLoader loader4("libKeithley2100Lib.so", this);
        KDmm = qobject_cast<IKeithley2100Interface*> (loader4.instance());

}
void testKeithley2100Lib::ADCRead(){

        switch(ui.comboBox_2->currentIndex()){

        case 1:
            ui.lineEdit->setText(QString::number(KDmm->MeasureResistance(ui.comboBox->currentIndex()),'g',10));
            break;
        case 2:
            ui.lineEdit->setText(QString::number(KDmm->MeasureDCVoltage(ui.comboBox->currentIndex()),'g',10));
            break;
        case 3:
            ui.lineEdit->setText(QString::number(KDmm->MeasureDCCurrent(ui.comboBox->currentIndex()),'g',10));
            break;
        case 4:
            ui.lineEdit->setText(QString::number(KDmm->MeasureACVoltage(ui.comboBox->currentIndex()),'g',10));
            break;
        case 5:
            ui.lineEdit->setText(QString::number(KDmm->MeasureACCurrent(ui.comboBox->currentIndex()),'g',10));
            break;
        case 6:
            ui.lineEdit->setText(QString::number(KDmm->MeasureDiode(ui.comboBox->currentIndex()),'g',10));
            break;
        case 7:
            ui.lineEdit->setText(QString::number(KDmm->MeasureContinuity(ui.comboBox->currentIndex()),'g',10));
            break;
        }
}


testKeithley2100Lib::~testKeithley2100Lib()
{

}

void testKeithley2100Lib::on_pushButton_clicked()
{
    ADCTimer->start(200);
}

void testKeithley2100Lib::on_pushButton_2_clicked()
{
    ADCTimer->stop();
}
void testKeithley2100Lib::on_comboBox_currentIndexChanged(int index)
{
    if(index!=0){
        switch(ui.comboBox_2->currentIndex()){

        case 1:
            KDmm->ConfigureResistance(index);
            break;
        case 2:
            KDmm->ConfigureDCVoltage(index);
            break;
        case 3:
            KDmm->ConfigureDCCurrent(index);
            break;
        case 4:
            KDmm->ConfigureACVoltage(index);
            break;
        case 5:
            KDmm->ConfigureACCurrent(index);
            break;
        case 6:
            KDmm->ConfigureDiode(index);
            break;
        case 7:
            KDmm->ConfigureContinuity(index);
            break;

        }

    }

}

void testKeithley2100Lib::on_comboBox_2_currentIndexChanged(int index)
{
	ui.comboBox->clear();
    switch(index){
    case 1:
        ui.comboBox->addItem("select...");
        ui.comboBox->addItem("100E");
        ui.comboBox->addItem("1KE");
        ui.comboBox->addItem("10KE");
        ui.comboBox->addItem("100KE");
        ui.comboBox->addItem("1ME");
        ui.comboBox->addItem("10ME");
        ui.comboBox->addItem("100ME");
        break;
    case 2:
    case 4:
        ui.comboBox->addItem("select...");
        ui.comboBox->addItem("100mV");
        ui.comboBox->addItem("1V");
        ui.comboBox->addItem("10V");
        ui.comboBox->addItem("100V");
        ui.comboBox->addItem("1000V");
        break;
    case 3:
        ui.comboBox->addItem("select...");
        ui.comboBox->addItem("10mA");
        ui.comboBox->addItem("100mA");
        ui.comboBox->addItem("1A");
        ui.comboBox->addItem("3A");
        break;
    case 5:
        ui.comboBox->addItem("select...");
        ui.comboBox->addItem("1A");
        ui.comboBox->addItem("3A");
        break;
    case 6:
        ui.comboBox->addItem("select...");
        ui.comboBox->addItem("Diode");
        break;
    case 7:
        ui.comboBox->addItem("select...");
        ui.comboBox->addItem("Continuity");
        break;
    }
}
