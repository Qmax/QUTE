#include "dmmaccuracy.h"
#include "ui_dmmaccuracy.h"

DMMAccuracy::DMMAccuracy(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DMMAccuracy)
{
//	qDebug()<<"DMMAccuracy";
    ui->setupUi(this);
    this->setGeometry( QStyle::alignedRect(Qt::LeftToRight,Qt::AlignCenter,this->size(),qApp->desktop()->availableGeometry()));
    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());

    m_nACCuTimer = new QTimer(this);
    connect(m_nACCuTimer, SIGNAL(timeout()), this, SLOT(saveToFile()));
    connect(parent, SIGNAL(DMM2AccuCalc(double,QString)), this, SLOT(getData(double,QString)));

    m_nIteration=0;
    m_nInterval=1;
    m_nSamples=2;

}
void DMMAccuracy::saveToFile(){

    QString dt = QDateTime::currentDateTime().toString("dd/MM/yyyy hh:mm:ss");
    QString txt = QString("[%1] ").arg(dt);

    QFile outFile("DMMAccuracy.log");

    if(outFile.size()>1298368)
        outFile.open(QIODevice::WriteOnly | QIODevice::Text);
    else
        outFile.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append);

    QTextStream textStream(&outFile);

    QString str,str2;
    str2= rxRange;

    bool ok=true;
	if (str2.endsWith("V") || str2.endsWith("A") || str2.endsWith("E"))
		str2.chop(1);
	if (str2.endsWith("m") || str2.endsWith("K") || str2.endsWith("M"))
		str2.chop(1);

    double l_nRange=str2.toDouble(&ok);

    if(l_nRange==5)
        str= QString::number(rxData, 'f', 4);
    else if(l_nRange==50)
    	str= QString::number(rxData, 'f', 3);
    else if(l_nRange==500 || l_nRange==750)
        str= QString::number(rxData, 'f', 2);

    m_nSampleData[m_nIteration]=str.toDouble(&ok);

    textStream << txt << m_nSampleData[m_nIteration]<<endl;

    m_nIteration++;

    if(m_nIteration==m_nSamples){
        m_nACCuTimer->stop();
        double avg=0,avgData=0,diff[m_nSamples],diffSum=0,sigma=0,perOfRange=0,perOfReading=0;

        textStream << "Range : "<<rxRange <<endl;

        for(int i=0;i<m_nSamples;i++)
           avg = avg + m_nSampleData[i];
        avgData= avg / m_nSamples;
        for(int j=0;j<m_nSamples;j++){
            diff[j] = avgData - m_nSampleData[j];
            diff[j] = diff[j] * diff[j];
            diffSum = diffSum + diff[j];
        }
        sigma = sqrt(diffSum) / (m_nSamples-1);
        perOfRange = sigma / sqrt(m_nSamples);

        perOfReading = (l_nRange-avgData)/100;
        textStream << "Avg of Readings : "<<avgData<<endl<<"% of Range : " << perOfRange <<endl<< "% of Reading : "<< perOfReading <<endl;
        textStream << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
        m_nIteration=0;
    }
}
double DMMAccuracy::digitsLimiter() {
	QRegExp rx("[0-9]\\d{0,3}");
	ui->dmmData->setValidator(new QRegExpValidator(rx, this));
	return ui->dmmData->text().toDouble();
}
DMMAccuracy::~DMMAccuracy()
{
    delete ui;
}
void DMMAccuracy::getData(double data,QString range){
    rxData=data;
    rxRange=range;
    ui->dmmData->setText(QString::number(data));
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
    m_nACCuTimer->setInterval(60000*m_nInterval);
    m_nACCuTimer->start();
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
    //qDebug()<<l_strDate;
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
    //qDebug()<<cmd;
    executeSystemCommand("date",cmd);
}


void DMMAccuracy::on_spinBox_valueChanged(int interval)
{
    m_nInterval=interval;
}

void DMMAccuracy::on_spinBox_2_valueChanged(int samples)
{
    m_nSamples= samples;
}
