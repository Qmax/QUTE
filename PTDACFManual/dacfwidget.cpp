#include "dacfwidget.h"
#include "ui_dacfwidget.h"

DACFWidget::DACFWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DACFWidget)
{
    ui->setupUi(this);

    QPluginLoader loader4("libQmaxPTInterface.so", this);
    ILineEdit = qobject_cast<IQmaxLineEdit*> (loader4.instance());
    INumberPanel = qobject_cast<IQmaxNumberPanel*> (loader4.instance());

    OffsetValueEdit = ILineEdit->QmaxLineEdit(1,this);
    OffsetValueEdit->setGeometry(ui->leOffset->geometry());
    connect(OffsetValueEdit, SIGNAL(focussed(bool)), this, SLOT(callOffsetValue()));

    ui->cmgRanges->setFont(QFont("DejaVu Sans",14,75,false));
    ui->tableWidget->setFont(QFont("DejaVu Sans",14,75,false));

    //~~~~~~~~~~~~~Reading Short Values from File~~~~~~~~~~~~~~~~~~~~~~
    QStringList stringList; QFile textFile;
    textFile.setFileName("OffsetValues.txt");

    if (textFile.open(QIODevice::ReadOnly)) {
            QTextStream textStream(&textFile);
            while (!textStream.atEnd()) {
                    stringList.append(textStream.readLine());
            }
            for(int i=0;i<5;i++){
                ui->tableWidget->setItem(0,i,new QTableWidgetItem(stringList.value(i)));
                values[i]=stringList.value(i);
            }
    }
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

}
void DACFWidget::receiveValue(double dbl){
        if (m_nLineEditIndex == 1) {
            OffsetValueEdit->setText(QString::number(dbl));
            values[ui->cmgRanges->currentIndex()]=QString::number(dbl);
            ui->tableWidget->setItem(0,ui->cmgRanges->currentIndex(),new QTableWidgetItem(QString::number(dbl)));
        }
}
void DACFWidget::receiveValue(QString str){
    Q_UNUSED(str)
}
void DACFWidget::receiveValue(unsigned int uint){
    Q_UNUSED(uint)
}
void DACFWidget::callOffsetValue()
{
        double m_nVoltRangeArray[5]={0.6,1.5,3.5,7.0,13.0};
        QWidget *w = INumberPanel->getNumKBPanelIncDec(1, 1, 'v', m_nVoltRangeArray[ui->cmgRanges->currentIndex()],m_nVoltRangeArray[ui->cmgRanges->currentIndex()]*-1,this);
        w->setWindowFlags(Qt::WindowCloseButtonHint | Qt::Dialog);
        w->show();
        m_nLineEditIndex = 1;
}
DACFWidget::~DACFWidget()
{
    delete ui;
}

void DACFWidget::changeEvent(QEvent *e)
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

void DACFWidget::on_butSave_clicked()
{
    QFile outFile;
    outFile.setFileName("OffsetValues.txt");
    outFile.open(QIODevice::WriteOnly);
    QTextStream ts(&outFile);
    for(int i=0;i<5;i++){
        ts << values[i] << endl;
    }
}

void DACFWidget::on_butExit_clicked()
{
    this->close();
}
