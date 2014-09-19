#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <math.h>
#include <QPluginLoader>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    initialiseTableWidget();
    enableRichGUI();
}

void Widget::initialiseTableWidget()
{
    ui->tableWidget->resizeColumnsToContents();
      ui->tableWidget->resizeRowsToContents();
      ui->tableWidget->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
      short int l_nTempIndex=0;
      for(int l_nTableRowIndex=0;l_nTableRowIndex<33;l_nTableRowIndex++)
      {

          for(int l_nTableColumnIndex=0;l_nTableColumnIndex<3;l_nTableColumnIndex++)
          {
              ui->tableWidget->setItem(l_nTableRowIndex,l_nTableColumnIndex,new QTableWidgetItem(""));
          }
      }
      m_nLineEditIndex=0;
      QPluginLoader loader4("libQmaxPTInterface.so", this);
      ILineEdit = qobject_cast<IQmaxLineEdit*> (loader4.instance());
      IPTLibrary = qobject_cast<IQmaxPTLibrary*> (loader4.instance());
      INumberPanel = qobject_cast<IQmaxNumberPanel*> (loader4.instance());
      m_objLE_32BITFTW = ILineEdit->QmaxLineEdit(0, ui->grpGeneral);
      m_objLE_32BITFTW->setGeometry(130, 20, 80, 40);
      connect(m_objLE_32BITFTW, SIGNAL(focussed(bool)), this, SLOT(callFTW32edit()));


}
void Widget::enableRichGUI() {
	QWidget *m_objWidget = new QWidget(this);
	QGraphicsScene *entireScene = new QGraphicsScene(0, 0, 800, 600);
	QGraphicsView *entireView = new QGraphicsView(m_objWidget);
	QPixmap obj1 = QPixmap(":/bg.png");
	QBrush obj2 = QBrush(obj1);
	obj2.setStyle(Qt::TexturePattern);
	obj2.setTexture(obj1);
	entireView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	entireView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	entireView->setFrameStyle(QFrame::Plain | QFrame::Sunken);
	entireView->setBackgroundBrush(obj2);
	entireView->setScene(entireScene);
	entireView->setGeometry(0, 0, 800, 600);

	ui->grpGeneral->setParent(m_objWidget);
	ui->tableWidget->setParent(m_objWidget);

	ui->grpGeneral->setGeometry(20, 10, 310, 181);
        ui->tableWidget->setGeometry(400, 20, 320, 490);

}
void Widget::callFTW32edit()
{
    if (m_objLE_32BITFTW->hasFocus()) {
             openNumKBPanel(1,1,'F',20000000,0);
             m_nLineEditIndex = 0;
     }
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeEvent(QEvent *e)
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

void Widget::on_pushButton_clicked()
{
    bool ok = true;
    double l_nFS = 50000000.0;
    double l_nFValue = ui->le32Bit->text().toDouble(&ok);
    double l_nDiv = (m_nFTW32BITData/l_nFS);
    unsigned int l_nFTW32 = (pow(2,32))*l_nDiv;
    qDebug()<<"FTW 32:"<<hex<<l_nFTW32;
    ui->labelFTW32->setText(QString::number(l_nFTW32,16));

    double l_n14BitValue = ui->le14Bit->text().toDouble(&ok);
    l_nDiv = (l_n14BitValue/l_nFS);
    qDebug()<<"Div 14:"<<hex<<l_nDiv;
    unsigned int l_nFTW14 = (pow(2,14))*l_nDiv;
    qDebug()<<"FTW 14:"<<hex<<l_nFTW14;
    ui->labelFTW14->setText(QString::number(l_nFTW14,16));
    short int l_n32BitIndex=31,l_nPadIndex=18;
    double l_nFo=0.0;
    unsigned int l_nValue1= (l_nFTW32&0x000003FFF);
    for(int l_nIndex=0;l_nIndex<33;l_nIndex++)
    {
        QTableWidgetItem *item1 = ui->tableWidget->item(l_nIndex,0);
        QTableWidgetItem *item2 = ui->tableWidget->item(l_nIndex,1);
        QTableWidgetItem *item3 = ui->tableWidget->item(l_nIndex,2);
        item1->setText(QString::number(l_nIndex,16).toUpper());
        unsigned int l_nBitValue = l_nFTW32 >> l_n32BitIndex;
        unsigned int l_nTotalValue = (l_nBitValue<<l_n32BitIndex) | (l_nValue1<<l_nPadIndex);
        l_nFo = (l_nTotalValue * l_nFS) / (pow(2,32));
        item2->setText(QString::number(l_nTotalValue,16).toUpper());
        item3->setText(QString::number(l_nFo,'f',2));
        if(l_n32BitIndex <0)
            l_n32BitIndex=0;
        if(l_nPadIndex<0)
            l_nPadIndex=0;
        qDebug()<<"Bit["<<l_nIndex<<"]"<<hex<<l_nBitValue<<l_nPadIndex<<l_n32BitIndex;
        l_n32BitIndex--;l_nPadIndex--;
        qDebug()<<"Total Value:"<<hex<<l_nTotalValue;
    }
}


void Widget::openNumKBPanel(short int pValue) {
        QWidget *w = INumberPanel->getNumKBPanel(pValue, this);
        w->setWindowFlags(Qt::WindowCloseButtonHint | Qt::Dialog);
        w->show();
}
void Widget::openNumKBPanel(short int pValue, double incDec, char type,double max, double min) {

	QWidget *m_w = INumberPanel->getNumKBPanelIncDec(pValue, incDec, type, max,min, this);
	m_w->setWindowFlags(Qt::WindowCloseButtonHint | Qt::Dialog);
	m_w->show();
}


void Widget::receiveValue(unsigned int pValue) {
	Q_UNUSED(pValue)
}



void Widget::receiveValue(QString pValue) {
	qDebug() << "Receive QString Value:" << hex << pValue;
	if (m_nLineEditIndex == 0) {
		m_objLE_32BITFTW->setText(pValue);
	}
}

void Widget::receiveValue(double pValue) {
	qDebug() << "Receive double Value:" << hex << pValue;
	        if (m_nLineEditIndex == 0) {
	                m_nFTW32BITData = (unsigned int)pValue;
	        }

}
