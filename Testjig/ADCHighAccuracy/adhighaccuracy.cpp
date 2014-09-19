#include "adhighaccuracy.h"
#include "ui_adhighaccuracy.h"
#include <qfile.h>

ADHighAccuracy::ADHighAccuracy(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ADHighAccuracy)
{
    ui->setupUi(this);
    InitialiseRegisterMap();
    InitialiseHWLibraries();
    enableRichGUI();
//    if(QFile(m_strADCSettingsFile).exists())
//    	loadSettings();
    mTimer = new QTimer(this);
    connect(mTimer, SIGNAL(timeout()), this, SLOT(checkADC()));
}

ADHighAccuracy::~ADHighAccuracy()
{
	saveSettings();
	mTimer->stop();
    delete ui;
}
void ADHighAccuracy::enableRichGUI(){
	QWidget *m_objWidget=new QWidget(this);
	QGraphicsScene *entireScene = new QGraphicsScene(0,0,800,600);
	QGraphicsView  *entireView =  new QGraphicsView(m_objWidget);
	QPixmap obj1 = QPixmap(":/bg.png");
	QBrush obj2 = QBrush(obj1);
	obj2.setStyle(Qt::TexturePattern);
	obj2.setTexture(obj1);
	entireView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	entireView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	entireView->setFrameStyle(QFrame::Plain|QFrame::Sunken);
	entireView->setBackgroundBrush(obj2);
	entireView->setScene(entireScene);
	entireView->setGeometry(0,0,800,600);

	ui->groupBox->setParent(m_objWidget);
	ui->groupBox_2->setParent(m_objWidget);
	ui->groupBox_3->setParent(m_objWidget);
	ui->groupBox_57->setParent(m_objWidget);
	ui->groupBox_62->setParent(m_objWidget);
	ui->groupBox_63->setParent(m_objWidget);
	ui->groupBox_64->setParent(m_objWidget);
	ui->groupBox_65->setParent(m_objWidget);
	ui->groupBox_66->setParent(m_objWidget);
	ui->groupBox_67->setParent(m_objWidget);
//	ui->groupBox_68->setParent(m_objWidget);
	ui->GPCon->setParent(m_objWidget);
        ui->settings->setParent(m_objWidget);

	ui->groupBox->setGeometry(585,288,197,99);
	ui->groupBox_2->setGeometry(663,459,118,63);
	ui->groupBox_3->setGeometry(340,390,440,60);
	ui->groupBox_57->setGeometry(10,0,321,281);
	ui->groupBox_62->setGeometry(10,280,321,161);
        ui->groupBox_63->setGeometry(10,440,230,81);
	ui->groupBox_64->setGeometry(340,0,231,201);
	ui->groupBox_65->setGeometry(340,200,231,80);
	ui->groupBox_66->setGeometry(340,280,241,91);
	ui->groupBox_67->setGeometry(580,0,201,281);
//	ui->groupBox_68->setGeometry(320,450,341,71);
	ui->GPCon->setGeometry(320,450,341,71);
        ui->settings->setGeometry(240,450,70,70);
}
void ADHighAccuracy::changeEvent(QEvent *e)
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

void ADHighAccuracy::InitialiseHWLibraries()
{
    QPluginLoader loaderApp("libPTApplicationcardInterface.so", this);
    IAppCard = qobject_cast<IApplicationCardInterface*> (loaderApp.instance());
    qDebug() << "Appcard" << IAppCard;
    IAppCard->setDeviceName(SLOT0);
    IAppCard->enumerateAPPCard();
    IAppCard->setSPIAppendBit(0xC000);
    qDebug()<<"Code ID:"<<hex<<IAppCard->readAppCardCodeId();
    m_objAD7190 = new AD7190Component(IAppCard);

    QPluginLoader testing("libAppBckPsoc.so", this);
    test = qobject_cast<IPTAppBckPsocInterface*> (testing.instance());
}

void ADHighAccuracy::loadSPIBIT()
{
	IAppCard->setSPIAppendBit(0xC000);
}
void ADHighAccuracy::InitialiseRegisterMap() {
        m_GainValues.insert(0, 7);
        m_GainValues.insert(1, 6);
        m_GainValues.insert(2, 5);
        m_GainValues.insert(3, 4);
        m_GainValues.insert(4, 3);
        m_GainValues.insert(5, 0);

        m_GainFactors.insert(0, 128.0);
        m_GainFactors.insert(1, 64.0);
        m_GainFactors.insert(2, 32.0);
        m_GainFactors.insert(3, 16.0);
        m_GainFactors.insert(4, 8.0);
        m_GainFactors.insert(5, 1.0);

        m_nStatusRegister = 0;
        m_nDataRegister = 0;
        m_nIDRegister = 0;
        m_nFullScaleRegister = 0;
        m_nOffsetRegister = 0;
        m_nModeRegister = 0x80060;
        m_nConfigurationRegister = 0x117;
        m_nGPConRegister = 0;
        m_nGainFactor = 128.0;
        m_nADC = 1;
        //m_nChop == false;
        m_nP0 = 0;
        m_nP1 = 0;
        m_nP2 = 0;
        m_nP3 = 0;

        ui->cmbGain_3->setCurrentIndex(0);
        ui->cmbClock_3->setCurrentIndex(2);
        ui->cmbADCSel_3->setCurrentIndex(0);
        ui->cmdRWop_3->setCurrentIndex(0);
        m_strADCSettingsFile="ADC7190SettingsFIle.txt";
}

void ADHighAccuracy::on_cmbGain_3_currentIndexChanged(int pIndex)
{
    printf("B4 Conversion : %X\n", m_nConfigurationRegister);
    m_nConfigurationRegister = m_nConfigurationRegister & 0x00FFFFF8;
    printf("Anding B4 Conversion : %X\n", m_nConfigurationRegister);
    m_nConfigurationRegister = m_nConfigurationRegister | m_GainValues.value(
                    pIndex);
    m_nGainFactor = m_GainFactors.value(pIndex);
    printf("After Conversion : %X\n", m_nConfigurationRegister);
    QString l_nData;
    l_nData.setNum(m_nConfigurationRegister, 16);
    ui->m_strConfiguration_3->setText(l_nData);

}

void ADHighAccuracy::on_cmbPolarity_3_currentIndexChanged(int pIndex)
{
    printf("B4 Conversion : %X\n", m_nConfigurationRegister);
    m_nConfigurationRegister = m_nConfigurationRegister & 0x00FFFFF7;
    printf("Anding B4 Conversion : %X\n", m_nConfigurationRegister);
    m_nConfigurationRegister = m_nConfigurationRegister | (pIndex << (3));
    printf("After Conversion : %X\n", m_nConfigurationRegister);
    QString l_nData;
    l_nData.setNum(m_nConfigurationRegister, 16);
    ui->m_strConfiguration_3->setText(l_nData);

}

void ADHighAccuracy::on_cmbBuffer_3_currentIndexChanged(int pIndex)
{
    printf("B4 Conversion : %X\n", m_nConfigurationRegister);
    m_nConfigurationRegister = m_nConfigurationRegister & 0x00FFFFEF;
    printf("Anding B4 Conversion : %X\n", m_nConfigurationRegister);
    m_nConfigurationRegister = m_nConfigurationRegister | (pIndex << (4));
    printf("After Conversion : %X\n", m_nConfigurationRegister);
    QString l_nData;
    l_nData.setNum(m_nConfigurationRegister, 16);
    ui->m_strConfiguration_3->setText(l_nData);
}

void ADHighAccuracy::on_cmbChopping_3_currentIndexChanged(int pIndex)
{
    printf("B4 Conversion : %X\n", m_nConfigurationRegister);
    m_nConfigurationRegister = m_nConfigurationRegister & 0x007FFFFF;
    printf("Anding B4 Conversion : %X\n", m_nConfigurationRegister);
    m_nConfigurationRegister = m_nConfigurationRegister | (pIndex << (23));
    printf("After Conversion : %X\n", m_nConfigurationRegister);
    QString l_nData;
    l_nData.setNum(m_nConfigurationRegister, 16);
    ui->m_strConfiguration_3->setText(l_nData);
    if (pIndex == 0)
            m_nChop = false;
    else
            m_nChop = true;
}

void ADHighAccuracy::on_cmbDiagnostic_3_currentIndexChanged(int pIndex)
{

}

void ADHighAccuracy::on_cmbHzReject_3_currentIndexChanged(int pIndex)
{
    printf("B4 Conversion : %X\n", m_nModeRegister);
    m_nModeRegister = m_nModeRegister & 0x00FFFBFF;
    printf("Anding B4 Conversion : %X\n", m_nModeRegister);
    m_nModeRegister = m_nModeRegister | (pIndex << 10);
    printf("After Conversion : %X\n", m_nModeRegister);
    QString l_nData;
    l_nData.setNum(m_nModeRegister, 16);
    ui->m_strMode_3->setText("");
    ui->m_strMode_3->setText(l_nData);
}

void ADHighAccuracy::on_cmbRefSelect_3_currentIndexChanged(int pIndex)
{
    printf("B4 Conversion : %X\n", m_nConfigurationRegister);
    m_nConfigurationRegister = m_nConfigurationRegister & 0x00EFFFFF;
    printf("Anding B4 Conversion : %X\n", m_nConfigurationRegister);
    m_nConfigurationRegister = m_nConfigurationRegister | (pIndex << (20));
    printf("After Conversion : %X\n", m_nConfigurationRegister);
    QString l_nData;
    l_nData.setNum(m_nConfigurationRegister, 16);
    ui->m_strConfiguration_3->setText(l_nData);
}

void ADHighAccuracy::on_cmbRefDetect_3_currentIndexChanged(int pIndex)
{
    printf("B4 Conversion : %X\n", m_nConfigurationRegister);
    m_nConfigurationRegister = m_nConfigurationRegister & 0x00FFFFBF;
    printf("Anding B4 Conversion : %X\n", m_nConfigurationRegister);
    m_nConfigurationRegister = m_nConfigurationRegister | (pIndex << (6));
    printf("After Conversion : %X\n", m_nConfigurationRegister);
    QString l_nData;
    l_nData.setNum(m_nConfigurationRegister, 16);
    ui->m_strConfiguration_3->setText(l_nData);
}

void ADHighAccuracy::on_cmbModes_3_currentIndexChanged(int pIndex)
{
    printf("B4 Conversion : %X\n", m_nModeRegister);
    m_nModeRegister = m_nModeRegister & 0x001FFFFF;
    printf("Anding B4 Conversion : %X\n", m_nModeRegister);
    m_nModeRegister = m_nModeRegister | (pIndex << (21));
    printf("After Conversion : %X\n", m_nModeRegister);
    QString l_nData;
    l_nData.setNum(m_nModeRegister, 16);
    ui->m_strMode_3->setText("");
    ui->m_strMode_3->setText(l_nData);
}

void ADHighAccuracy::on_cmbFilter_3_currentIndexChanged(int pIndex)
{
    printf("B4 Conversion : %X\n", m_nModeRegister);
    m_nModeRegister = m_nModeRegister & 0x00FF7FFF;
    printf("Anding B4 Conversion : %X\n", m_nModeRegister);
    m_nModeRegister = m_nModeRegister | (pIndex << 15);
    printf("After Conversion : %X\n", m_nModeRegister);
    QString l_nData;
    l_nData.setNum(m_nModeRegister, 16);
    ui->m_strMode_3->setText("");
    ui->m_strMode_3->setText(l_nData);
}

void ADHighAccuracy::on_cmbZeroLatency_3_currentIndexChanged(int pIndex)
{
    printf("B4 Conversion : %X\n", m_nModeRegister);
    m_nModeRegister = m_nModeRegister & 0x00FFF7FF;
    printf("Anding B4 Conversion : %X\n", m_nModeRegister);
    m_nModeRegister = m_nModeRegister | (pIndex << 11);
    printf("After Conversion : %X\n", m_nModeRegister);
    QString l_nData;
    l_nData.setNum(m_nModeRegister, 16);
    ui->m_strMode_3->setText("");
    ui->m_strMode_3->setText(l_nData);
}

void ADHighAccuracy::on_cmbClock_3_currentIndexChanged(int pIndex)
{
    printf("B4 Conversion : %X\n", m_nModeRegister);
    m_nModeRegister = m_nModeRegister & 0x00F3FFFF;
    printf("Anding B4 Conversion : %X\n", m_nModeRegister);
    m_nModeRegister = m_nModeRegister | (pIndex << 18);
    printf("After Conversion : %X\n", m_nModeRegister);
    QString l_nData;
    l_nData.setNum(m_nModeRegister, 16);
    ui->m_strMode_3->setText("");
    ui->m_strMode_3->setText(l_nData);
}

void ADHighAccuracy::on_cmbOPData_3_currentIndexChanged(int pIndex)
{
    printf("B4 Conversion : %X\n", m_nModeRegister);
    m_nModeRegister = m_nModeRegister & 0x00EFFFFF;
    printf("Anding B4 Conversion : %X\n", m_nModeRegister);
    m_nModeRegister = m_nModeRegister | (pIndex << 20);
    printf("After Conversion : %X\n", m_nModeRegister);
    QString l_nData;
    l_nData.setNum(m_nModeRegister, 16);
    ui->m_strMode_3->setText("");
    ui->m_strMode_3->setText(l_nData);
}


void ADHighAccuracy::on_cmbOPParity_3_currentIndexChanged(int pIndex)
{
    printf("B4 Conversion : %X\n", m_nModeRegister);
    m_nModeRegister = m_nModeRegister & 0x00FFDFFF;
    printf("Anding B4 Conversion : %X\n", m_nModeRegister);
    m_nModeRegister = m_nModeRegister | (pIndex << 13);
    printf("After Conversion : %X\n", m_nModeRegister);
    QString l_nData;
    l_nData.setNum(m_nModeRegister, 16);
    ui->m_strMode_3->setText("");
    ui->m_strMode_3->setText(l_nData);
}

void ADHighAccuracy::on_cmbADCSel_3_currentIndexChanged(int pIndex)
{
    if (pIndex == 0) {
            m_nADC = 1;
    } else {
            m_nADC = 2;
    }
}

void ADHighAccuracy::on_cmdRWop_3_currentIndexChanged(int index)
{

}

void ADHighAccuracy::on_butA1A2_3_clicked()
{
    short l_nIndex = 0;
    if (ui->butA1A2_3->text() == "0") {
            ui->butA1A2_3->setText("1");
            l_nIndex = 1;
    } else
            ui->butA1A2_3->setText("0");
    //printf("B4 Conversion : %X\n",m_nConfigurationRegister);
    m_nConfigurationRegister = m_nConfigurationRegister & 0x00FF00FF;
    //printf("Anding B4 Conversion : %X\n",m_nConfigurationRegister);
    m_nConfigurationRegister = m_nConfigurationRegister | (l_nIndex << (8));
    //printf("After Conversion : %X\n",m_nConfigurationRegister);
    QString l_nData;
    l_nData.setNum(m_nConfigurationRegister, 16);
    ui->m_strConfiguration_3->setText(l_nData);

}

void ADHighAccuracy::on_butA3A4_3_clicked()
{
    short l_nIndex = 0;

    if (ui->butA3A4_3->text() == "0") {
            ui->butA3A4_3->setText("1");
            l_nIndex = 2;
    } else
            ui->butA3A4_3->setText("0");
    //printf("B4 Conversion : %X\n",m_nConfigurationRegister);
    m_nConfigurationRegister = m_nConfigurationRegister & 0x00FF00FF;
    //printf("Anding B4 Conversion : %X\n",m_nConfigurationRegister);
    m_nConfigurationRegister = m_nConfigurationRegister | (l_nIndex << (8));
    //printf("After Conversion : %X\n",m_nConfigurationRegister);
    QString l_nData;
    l_nData.setNum(m_nConfigurationRegister, 16);
    ui->m_strConfiguration_3->setText(l_nData);
}

void ADHighAccuracy::on_butTempSensor_3_clicked()
{
    short l_nIndex = 0;

    if (ui->butTempSensor_3->text() == "0") {
            ui->butTempSensor_3->setText("1");
            l_nIndex = 4;
    } else
            ui->butTempSensor_3->setText("0");
    //printf("B4 Conversion : %X\n",m_nConfigurationRegister);
    m_nConfigurationRegister = m_nConfigurationRegister & 0x00FF00FF;
    // printf("Anding B4 Conversion : %X\n",m_nConfigurationRegister);
    m_nConfigurationRegister = m_nConfigurationRegister | (l_nIndex << (8));
    //printf("After Conversion : %X\n",m_nConfigurationRegister);
    QString l_nData;
    l_nData.setNum(m_nConfigurationRegister, 16);
    ui->m_strConfiguration_3->setText(l_nData);
}

void ADHighAccuracy::on_butA2A2_3_clicked()
{
    short l_nIndex = 0;

    if (ui->butA2A2_3->text() == "0") {
            ui->butA2A2_3->setText("1");
            l_nIndex = 8;
    } else
            ui->butA2A2_3->setText("0");
    //printf("B4 Conversion : %X\n",m_nConfigurationRegister);
    m_nConfigurationRegister = m_nConfigurationRegister & 0x00FF00FF;
    //printf("Anding B4 Conversion : %X\n",m_nConfigurationRegister);
    m_nConfigurationRegister = m_nConfigurationRegister | (l_nIndex << (8));
    //printf("After Conversion : %X\n",m_nConfigurationRegister);
    QString l_nData;
    l_nData.setNum(m_nConfigurationRegister, 16);
    ui->m_strConfiguration_3->setText(l_nData);
}

void ADHighAccuracy::on_butAinCOm_3_clicked()
{
    short l_nIndex = 0;

    if (ui->butAinCOm_3->text() == "0") {
            ui->butAinCOm_3->setText("1");
            l_nIndex = 0x10;
    } else
            ui->butAinCOm_3->setText("0");
    //printf("B4 Conversion : %X\n",m_nConfigurationRegister);
    m_nConfigurationRegister = m_nConfigurationRegister & 0x00FF00FF;
    //printf("Anding B4 Conversion : %X\n",m_nConfigurationRegister);
    m_nConfigurationRegister = m_nConfigurationRegister | (l_nIndex << (8));
    //printf("After Conversion : %X\n",m_nConfigurationRegister);
    QString l_nData;
    l_nData.setNum(m_nConfigurationRegister, 16);
    ui->m_strConfiguration_3->setText(l_nData);
}

void ADHighAccuracy::on_butA2Com_3_clicked()
{
    short l_nIndex = 0;

    if (ui->butA2Com_3->text() == "0") {
            ui->butA2Com_3->setText("1");
            l_nIndex = 0x20;
    } else
            ui->butA2Com_3->setText("0");
    printf("B4 Conversion : %X\n", m_nConfigurationRegister);
    m_nConfigurationRegister = m_nConfigurationRegister & 0x00FF00FF;
    printf("Anding B4 Conversion : %X\n", m_nConfigurationRegister);
    m_nConfigurationRegister = m_nConfigurationRegister | (l_nIndex << (8));
    printf("After Conversion : %X\n", m_nConfigurationRegister);
    QString l_nData;
    l_nData.setNum(m_nConfigurationRegister, 16);
    ui->m_strConfiguration_3->setText(l_nData);
}

void ADHighAccuracy::on_butA3Com_3_clicked()
{
    short l_nIndex = 0;

    if (ui->butA3Com_3->text() == "0") {
            ui->butA3Com_3->setText("1");
            l_nIndex = 0x40;
    } else
            ui->butA3Com_3->setText("0");
    printf("B4 Conversion : %X\n", m_nConfigurationRegister);
    m_nConfigurationRegister = m_nConfigurationRegister & 0x00FF00FF;
    printf("Anding B4 Conversion : %X\n", m_nConfigurationRegister);
    m_nConfigurationRegister = m_nConfigurationRegister | (l_nIndex << (8));
    printf("After Conversion : %X\n", m_nConfigurationRegister);
    QString l_nData;
    l_nData.setNum(m_nConfigurationRegister, 16);
    ui->m_strConfiguration_3->setText(l_nData);
}

void ADHighAccuracy::on_butA4Com_3_clicked()
{
    short l_nIndex = 0;

    if (ui->butA4Com_3->text() == "0") {
            ui->butA4Com_3->setText("1");
            l_nIndex = 0x80;
    } else
            ui->butA4Com_3->setText("0");
    printf("B4 Conversion : %X\n", m_nConfigurationRegister);
    m_nConfigurationRegister = m_nConfigurationRegister & 0x00FF00FF;
    printf("Anding B4 Conversion : %X\n", m_nConfigurationRegister);
    m_nConfigurationRegister = m_nConfigurationRegister | (l_nIndex << (8));
    printf("After Conversion : %X\n", m_nConfigurationRegister);
    QString l_nData;
    l_nData.setNum(m_nConfigurationRegister, 16);
    ui->m_strConfiguration_3->setText(l_nData);
}

void ADHighAccuracy::on_butReset_3_clicked()
{
    m_objAD7190->resetADC(m_nADC);
}

void ADHighAccuracy::on_butStatus_3_clicked()
{
    ui->m_strStatus_3->setText("0");
    ui->m_strStatus_3->setText(QString::number(m_objAD7190->readADCStatusRegister(m_nADC)
                    & 0xFF, 16));
}

void ADHighAccuracy::on_butChipID_3_clicked()
{
    ui->m_strID_3->setText("0");
    ui->m_strID_3->setText(QString::number(m_objAD7190->readADCIDRegister(m_nADC) & 0xFF, 16));
//    qDebug() << m_nADC;
//    qDebug() << hex << m_objAD7190->readADCIDRegister(m_nADC);
//    qDebug() << hex << (m_objAD7190->readADCIDRegister(m_nADC) & 0xFF);
}

void ADHighAccuracy::on_butMode_3_clicked()
{
    ui->m_strMode_3->setText("0");
    if (ui->cmdRWop_3->currentIndex() == 0) {
            ui->m_strMode_3->setText(QString::number(m_objAD7190->readADCModeRegister(m_nADC)
                            & 0x00FFFFFF, 16));
    } else {
            m_objAD7190->writeADCModeRegister(m_nADC, m_nModeRegister);
    }

}

void ADHighAccuracy::on_butConfig_3_clicked()
{
    ui->m_strConfiguration_3->setText("0");
    if (ui->cmdRWop_3->currentIndex() == 0) {
            ui->m_strConfiguration_3->setText(QString::number(
                            m_objAD7190->readADCConfigurationRegister(m_nADC) & 0x00FFFFFF, 16));
    } else {
            m_objAD7190->writeADCConfigurationRegister(m_nADC, m_nConfigurationRegister);
    }
}

void ADHighAccuracy::on_butData_3_clicked()
{
    ui->m_strData_3->setText("0");
    ui->m_strData_3->setText(QString::number(m_objAD7190->readADCDataRegister(m_nADC)
                    & 0x00FFFFFF, 16));
}

void ADHighAccuracy::on_butGPCon_3_clicked()
{
    ui->m_strGPCon_3->setText("0");
    if (ui->cmdRWop_3->currentIndex() == 0) {
		ui->m_strGPCon_3->setText(QString::number(m_objAD7190->readADCGPConRegister(m_nADC)
						& 0x00FFFFFF, 16));
    }
    else
    {
    	m_objAD7190->writeADCGPConRegister(m_nADC,m_nGPConRegister);
    }
}

void ADHighAccuracy::on_butOffset_3_clicked()
{
    ui->m_strOffset_3->setText("0");
    ui->m_strOffset_3->setText(QString::number(m_objAD7190->readADCOffsetRegister(m_nADC)
                    & 0x00FFFFFF, 16));
}

void ADHighAccuracy::on_butFullScale_3_clicked()
{
    ui->m_strFullScale_3->setText("0");
    ui->m_strFullScale_3->setText(QString::number(
                    m_objAD7190->readADCFullScaleRegister(m_nADC) & 0x00FFFFFF, 16));
}

void ADHighAccuracy::on_butGP0_3_clicked()
{
    short l_nIndex=0;
    if(ui->butGP0_3->text() == "0"){
        ui->butGP0_3->setText("1");
        l_nIndex =1;
    }
    else{
        ui->butGP0_3->setText("0");
        m_nGPConRegister = m_nGPConRegister & 0x00FE;
    }
    m_nGPConRegister = m_nGPConRegister &  0x00FF;
    qDebug()<<"Configuration Register:"<<m_nGPConRegister;
    m_nGPConRegister = m_nGPConRegister |(l_nIndex);
    qDebug()<<"Configuration Register:"<<m_nGPConRegister;
    QString l_nData;
    l_nData.setNum(m_nGPConRegister,16);
    ui->m_strGPCon_3->setText(l_nData);

}

void ADHighAccuracy::on_butGP1_3_clicked()
{
    short l_nIndex=0;
    if(ui->butGP1_3->text() == "0"){
        ui->butGP1_3->setText("1");
        l_nIndex =2;
    }
    else{
        ui->butGP1_3->setText("0");
        m_nGPConRegister = m_nGPConRegister & 0x00FD;
    }
    m_nGPConRegister = m_nGPConRegister &  0x00FF;
    qDebug()<<"Configuration Register:"<<m_nGPConRegister;
    m_nGPConRegister = m_nGPConRegister |(l_nIndex);
    qDebug()<<"Configuration Register:"<<m_nGPConRegister;
    QString l_nData;
    l_nData.setNum(m_nGPConRegister,8);
    ui->m_strGPCon_3->setText(l_nData);
}

void ADHighAccuracy::on_butGP2_3_clicked()
{
    short l_nIndex=0;
    if(ui->butGP2_3->text() == "0"){
        ui->butGP2_3->setText("1");
        l_nIndex =4;
    }
    else{
        ui->butGP2_3->setText("0");
        m_nGPConRegister = m_nGPConRegister & 0x00FB;
    }
    m_nGPConRegister = m_nGPConRegister &  0x00FF;
    qDebug()<<"Configuration Register:"<<m_nGPConRegister;
    m_nGPConRegister = m_nGPConRegister |(l_nIndex);
    qDebug()<<"Configuration Register:"<<m_nGPConRegister;
    QString l_nData;
    l_nData.setNum(m_nGPConRegister,16);
    ui->m_strGPCon_3->setText(l_nData);

}

void ADHighAccuracy::on_butGP3_3_clicked()
{
    short l_nIndex=0;
    if(ui->butGP3_3->text() == "0"){
        ui->butGP3_3->setText("1");
        l_nIndex =8;
    }
    else{
        ui->butGP3_3->setText("0");
        m_nGPConRegister = m_nGPConRegister &  0x00F7;
    }
    m_nGPConRegister = m_nGPConRegister &  0x00FF;
    qDebug()<<"Configuration Register:"<<m_nGPConRegister;
    m_nGPConRegister = m_nGPConRegister |(l_nIndex);
    qDebug()<<"Configuration Register:"<<m_nGPConRegister;
    QString l_nData;
    l_nData.setNum(m_nGPConRegister,16);
    ui->m_strGPCon_3->setText(l_nData);
}

void ADHighAccuracy::on_butGP4_3_clicked()
{
    short l_nIndex=0;
    if(ui->butGP4_3->text() == "0"){
        ui->butGP4_3->setText("1");
        l_nIndex =0x10;
    }
    else{
        ui->butGP4_3->setText("0");
        m_nGPConRegister = m_nGPConRegister &  0x00EF;
    }
    m_nGPConRegister = m_nGPConRegister &  0x00FF;
    m_nGPConRegister = m_nGPConRegister |(l_nIndex);
    QString l_nData;
    l_nData.setNum(m_nGPConRegister,16);
    ui->m_strGPCon_3->setText(l_nData);
}

void ADHighAccuracy::on_butGP5_3_clicked()
{
    short l_nIndex=0;
    if(ui->butGP5_3->text() == "0"){
        ui->butGP5_3->setText("1");
        l_nIndex =0x20;
    }
    else{
        ui->butGP5_3->setText("0");
        m_nGPConRegister = m_nGPConRegister &  0x00DF;
       }
    m_nGPConRegister = m_nGPConRegister &  0x00FF;
    qDebug()<<"Configuration Register:"<<m_nGPConRegister;
    m_nGPConRegister = m_nGPConRegister |(l_nIndex);
    qDebug()<<"Configuration Register:"<<m_nGPConRegister;
    QString l_nData;
    l_nData.setNum(m_nGPConRegister,16);
    ui->m_strGPCon_3->setText(l_nData);
}

void ADHighAccuracy::on_butGP6_3_clicked()
{
    short l_nIndex=0;
    if(ui->butGP6_3->text() == "0"){
        ui->butGP6_3->setText("1");
        l_nIndex =0x40;
    }
    else{
        ui->butGP6_3->setText("0");
        m_nGPConRegister = m_nGPConRegister &  0x00BF;
    }
    m_nGPConRegister = m_nGPConRegister &  0x00FF;
    qDebug()<<"Configuration Register:"<<m_nGPConRegister;
    m_nGPConRegister = m_nGPConRegister |(l_nIndex);
    qDebug()<<"Configuration Register:"<<m_nGPConRegister;
    QString l_nData;
    l_nData.setNum(m_nGPConRegister,16);
    ui->m_strGPCon_3->setText(l_nData);

}

void ADHighAccuracy::on_butGP7_3_clicked()
{
    short l_nIndex=0;
    if(ui->butGP7_3->text() == "0"){
        ui->butGP7_3->setText("1");
        l_nIndex =0x80;
    }
    else{
        ui->butGP7_3->setText("0");
        m_nGPConRegister = m_nGPConRegister &  0x007F;
    }
    m_nGPConRegister = m_nGPConRegister &  0x00FF;
    qDebug()<<"Configuration Register:"<<m_nGPConRegister;
    m_nGPConRegister = m_nGPConRegister |(l_nIndex);
    qDebug()<<"Configuration Register:"<<m_nGPConRegister;
    QString l_nData;
    l_nData.setNum(m_nGPConRegister,16);
    ui->m_strGPCon_3->setText(l_nData);
}

void ADHighAccuracy::on_spnFSBits_3_valueChanged(int pIndex)
{
    m_nModeRegister = m_nModeRegister & 0x00FFFC00;
    //	    printf("Anding B4 Conversion : %X\n",m_nModeRegister);
    m_nModeRegister = m_nModeRegister | pIndex;
    double l_nFMOD = (4.92 * 1000000.0) / 16.0;
    double l_nOutput, nValue = 1.0;
    if (m_nChop == true) {
            if (ui->cmbFilter_3->currentIndex() == 0)
                    nValue = 4.0;
            else
                    nValue = 3.0;
    }
    l_nOutput = (l_nFMOD / 64) / pIndex * nValue;
    QString l_nData;
    l_nData.setNum(l_nOutput, 'f', 2);
    ui->notchText_3->setText(l_nData);
    //	    printf("After Conversion : %X\n",m_nModeRegister);
    l_nData.setNum(m_nModeRegister, 16);
    ui->m_strMode_3->setText("");
    ui->m_strMode_3->setText(l_nData);
}

void ADHighAccuracy::on_doubleSpinBox_6_valueChanged(double )
{

}

void ADHighAccuracy::on_butStTimer_clicked()
{
	if(mTimer->isActive()){
		ui->butStTimer->setText("Start");
		mTimer->stop();
	}
	else{
		ui->butStTimer->setText("Stop");
		mTimer->start(200);
	}
}

void ADHighAccuracy::checkADC()
{
	short int l_nResoulution = 23;
	double l_nGain = m_nGainFactor, l_nVREF = 2.048;
	double l_nFactor1 = 0.0, l_nFactor2 = 0.0, l_nAIN = 0.0;
	unsigned int m_nADC1Voltage=m_objAD7190->readADCDataRegister(m_nADC) & 0xFFFFFF;
	qDebug()<<"Hex ADC Code:"<<hex<<m_nADC1Voltage;
	l_nFactor1 = (m_nADC1Voltage / pow(2, l_nResoulution)) - 1;
	l_nFactor2 = (l_nGain / l_nVREF);
	l_nAIN = l_nFactor1 / l_nFactor2;
	if(ui->chkPsuedo->isChecked())
	{
		l_nFactor1 = (((m_nADC1Voltage * l_nVREF) / (pow(2, l_nResoulution)))-l_nVREF) / l_nGain;
		l_nAIN=l_nFactor1;
	}

	ui->leADCData->setText(QString::number(l_nAIN,'f',8));
	qDebug()<<"Converted ADC Code:"<<l_nAIN;
}


void ADHighAccuracy::saveSettings()
{

    QSettings settings(m_strADCSettingsFile, QSettings::NativeFormat);
    settings.setValue("Mode",m_nModeRegister);
    settings.setValue("Configuration",m_nConfigurationRegister);
    settings.setValue("GPConfiguration",m_nGPConRegister);
    settings.setValue("GainFactor",m_nGainFactor);
}

void ADHighAccuracy::loadSettings()
{

	bool ok=true;
	QSettings settings(m_strADCSettingsFile, QSettings::NativeFormat);
	m_nModeRegister = settings.value("Mode",0).toUInt();
	m_nConfigurationRegister = settings.value("Configuration",0).toUInt();
	m_nGPConRegister = settings.value("GPConfiguration",0).toUInt();
	m_nGainFactor = settings.value("GainFactor",0).toDouble(&ok);

	for(int l_nIndex=0;l_nIndex<m_GainFactors.count();l_nIndex++)
		if(m_GainFactors.value(l_nIndex) == m_nGainFactor)
			ui->cmbGain_3->setCurrentIndex(l_nIndex);


	ui->m_strMode_3->setText(QString::number(m_nModeRegister,16));
	ui->m_strConfiguration_3->setText(QString::number(m_nConfigurationRegister,16));
	ui->m_strGPCon_3->setText(QString::number(m_nGPConRegister,16));

	//m_objAD7190->writeADCConfigurationRegister(m_nADC,m_nConfigurationRegister);
//	m_objAD7190->writeADCModeRegister(m_nADC,m_nModeRegister);
}

void ADHighAccuracy::on_comboBox_currentIndexChanged(int index)
{
	m_nGPConRegister=48+index;
	qDebug()<<"GPCON:"<<hex<<m_nGPConRegister<<"(hex)"<<bin<<m_nGPConRegister<<"(bin)";
	ui->GPCONHexLabel->setText(QString::number(m_nGPConRegister,16)+("<sub>HEX</sub>"));
}

void ADHighAccuracy::on_settings_clicked()
{
    QWidget *newWidget = test->getPTAppBckPsoc();
    newWidget->setWindowTitle("AppCard BackPanel PSoC Panel");
    newWidget->show();
}
