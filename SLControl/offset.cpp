#include "offset.h"
#include "ui_offset.h"
#include <qdebug.h>

offset::offset(IDMMLibInterface* dmmLib,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::offset)
{
    ui->setupUi(this);

    QPluginLoader loader4("libQmaxPTInterface.so",this);
    ILineEdit = qobject_cast<IQmaxLineEdit*>(loader4.instance());
    INumberPanel=qobject_cast<IQmaxNumberPanel*>(loader4.instance());

    objDACF=ILineEdit->QmaxLineEdit(1,ui->OffsetDAC);
    objDACF->setGeometry(40,40,151,41);
    objDACF->setStyleSheet("border-width: 2px;border-style: outset;border-color: gray; 					    padding: 0 8px;     background: black;     selection-background-color: yellow;   color:white;     font: bold 14px;"    );
    connect(objDACF,  SIGNAL(focussed(bool)), this, SLOT(callDACFEdit()));

    IDMMLib=dmmLib;
    IDMMLib->ApplyDACOffset(0.0);
    m_nDACF=0.0;
}

offset::~offset()
{
    delete ui;
}

void offset::changeEvent(QEvent *e)
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
void offset::openNumKBPanel(short int pValue) {

        QWidget *w = INumberPanel->getNumKBPanel(pValue, this);
        w->setStyleSheet("border:1px solid rgba(0,0,0,255); color:black;");
        w->setWindowFlags(Qt::WindowCloseButtonHint | Qt::Dialog);
        w->show();
}
void offset::openNumKBPanel(short int pValue,double incRatio,char type,double max,double min,QWidget* parent) {

        QWidget *w = INumberPanel->getNumKBPanelIncDec(pValue,incRatio,type,max,min,parent);
        w->setStyleSheet("");
        w->setWindowFlags(Qt::WindowCloseButtonHint | Qt::Dialog);
        w->show();
}
void offset::callDACFEdit(){
    if (objDACF->hasFocus()) {
            openNumKBPanel(1, 1, 'v', 10, -10,this);
            m_nLineEditIndex = 1;
    }
}

void offset::receiveValue(QString pValue){}
void offset::receiveValue(unsigned int pValue){}
void offset::receiveValue(double pValue){
    if(m_nLineEditIndex==1){
        objDACF->setText(QString::number(pValue));
        m_nDACF= pValue;
        IDMMLib->ApplyDACOffset(m_nDACF);
    }
}

void offset::on_Fleft_clicked()
{
    objDACF->setCursorPosition(objDACF->cursorPosition()-1);
}

void offset::on_Fright_clicked()
{
    objDACF->setCursorPosition(objDACF->cursorPosition()+1);
}

void offset::on_Fup_clicked()
{
    bool ok=true;
    QString str=objDACF->text();
    double value=str.toDouble(&ok);
    short curPos=objDACF->cursorPosition();
    m_nDACF=validateCursorPosition(curPos-1,value,1);
    objDACF->setText(QString::number(m_nDACF));
    objDACF->setCursorPosition(curPos);

    IDMMLib->ApplyDACOffset(m_nDACF);
}

void offset::on_Fdown_clicked()
{
    bool ok=true;
    QString str=objDACF->text();
    double value=str.toDouble(&ok);
    short curPos=objDACF->cursorPosition();
    m_nDACF=validateCursorPosition(curPos-1,value,0);
    objDACF->setText(QString::number(m_nDACF));
    objDACF->setCursorPosition(curPos);

    IDMMLib->ApplyDACOffset(m_nDACF);
}

void offset::on_Gleft_clicked()
{

}

void offset::on_Gright_clicked()
{

}

void offset::on_Gup_clicked()
{

}

void offset::on_Gdown_clicked()
{

}
double offset::validateCursorPosition(short pos,double value,short incDec){

	//qDebug()<<"Position:"<<pos<<"Value:"<<value<<"Inc/Dec:"<<incDec;
    double one,ten,hundred,thousand,ten_thousand,hundred_thousand,mega;
    if(incDec==1){
        one=1;ten=10;hundred=100;thousand=1000;ten_thousand=10000;hundred_thousand=100000;mega=1000000;
    }
    if(incDec==0){
        one=-1;ten=-10;hundred=-100;thousand=-1000;ten_thousand=-10000;hundred_thousand=-100000;mega=-1000000;
    }

    if((value/1000000)>=1&&(value/1000000)<=10){
        //qDebug<<"1000000 Range";
        if(pos==0)
            value=value+mega;
        if(pos==1)
            value=value+hundred_thousand;
        if(pos==2)
            value=value+ten_thousand;
        if(pos==3)
            value=value+thousand;
        if(pos==4)
            value=value+hundred;
        if(pos==5)
            value=value+ten;
        if(pos==6)
            value=value+one;
    }
    else if((value/100000)>=1&&(value/100000)<=10){
        //qDebug<<"100000 Range";
        if(pos==0)
            value=value+hundred_thousand;
        if(pos==1)
            value=value+ten_thousand;
        if(pos==2)
            value=value+thousand;
        if(pos==3)
            value=value+hundred;
        if(pos==4)
            value=value+ten;
        if(pos==5)
            value=value+one;
    }
    else if((value/10000)>=1&&(value/10000)<=10){
        //qDebug<<"10000 Range";
        if(pos==0)
            value=value+ten_thousand;
        if(pos==1)
            value=value+thousand;
        if(pos==2)
            value=value+hundred;
        if(pos==3)
            value=value+ten;
        if(pos==4)
            value=value+one;
    }
    else if((value/1000)>=1&&(value/1000)<=10){
        //qDebug<<"1000 Range";
        if(pos==0)
            value=value+thousand;
        if(pos==1)
            value=value+hundred;
        if(pos==2)
            value=value+ten;
        if(pos==3)
            value=value+one;
    }
    else if((value/100)>=1&&(value/100)<=10){
        //qDebug<<"100 Range";
        if(pos==0)
            value=value+hundred;
        if(pos==1)
            value=value+ten;
        if(pos==2)
            value=value+one;
    }
    else if((value/10)>=1&&(value/10)<=10){
        //qDebug<<"10 Range";
        if(pos==0)
            value=value+ten;
        if(pos==1)
            value=value+one;
    }

    else if((value)>=1&&(value)<=10&&pos<1){
//           qDebug()<<"1 Range";
           if(value==1&&one==-1)
               one=0;
           else
               value=value+one;
       }/*else if((value*10)>=1&&(value*10)<=10){
//           qDebug()<<"0.1 Range";
           value=value*10;
           if(pos==0)
               value=value+(ten);
           if(pos==1)
               value=value+(one);
           value=value/10;
       }
       else if((value*100)>=1&&(value*100)<=10){
//           qDebug()<<"0.01 Range";
           value=value*100;

           if(pos==0)
               value=value+(hundred);
           if(pos==1)
               value=value+(ten);
           if(pos==2)
               value=value+(one);

           value=value/100;
       }
       else if((value*1000)>=1&&(value*1000)<=10){
//           qDebug()<<"0.001 Range";
           value=value*1000;
           if(pos==0)
               value=value+(thousand);
           if(pos==1)
               value=value+(hundred);
           if(pos==2)
               value=value+(ten);
           if(pos==3)
               value=value+(one);
           value=value/1000;
       }
       else if((value*10000)>=1&&(value*10000)<=10){
//           qDebug()<<"0.0001 Range";
           value=value*10000;
           if(pos==0)
               value=value+(ten_thousand);
           if(pos==1)
               value=value+(thousand);
           if(pos==2)
               value=value+(hundred);
           if(pos==3)
               value=value+(ten);
           if(pos==4)
               value=value+(one);
           value=value/10000;
       }
       else if((value*100000)>=1&&(value*100000)<=10){
//           qDebug()<<"0.00001 Range";
           value=value*100000;
           if(pos==0)
               value=value+(hundred_thousand);
           if(pos==1)
               value=value+(ten_thousand);
           if(pos==2)
               value=value+(thousand);
           if(pos==3)
               value=value+(hundred);
           if(pos==4)
               value=value+(ten);
           if(pos==5)
               value=value+(one);
           value=value/100000;
       }
       else if((value*1000000)>=1&&(value*1000000)<=10){
//           qDebug()<<"0.000001 Range";
           value=value*1000000;
           if(pos==0)
               value=value+(mega);
           if(pos==1)
               value=value+(hundred_thousand);
           if(pos==2)
               value=value+(ten_thousand);
           if(pos==3)
               value=value+(thousand);
           if(pos==4)
               value=value+(hundred);
           if(pos==5)
               value=value+(ten);
           if(pos==6)
               value=value+(one);
           value=value/1000000;
       }*/
       else if((value)>=0&&(value)<10&&pos>=1){
           if(pos==1){
//               qDebug()<<"0.1 Range";
                   if(incDec==1)value=value+0.1;else value=value-0.1;
           }
           else if(pos==2){
//               qDebug()<<"0.01 Range";
                   if(incDec==1)value=value+0.01;else value=value-0.01;
           }else if(pos==3){
//               qDebug()<<"0.001 Range";
                   if(incDec==1)value=value+0.001;else value=value-0.001;
           }
           else if(pos==4){
//               qDebug()<<"0.0001 Range";
                   if(incDec==1)value=value+0.0001;else value=value-0.0001;
           }
           else if(pos==5){
//               qDebug()<<"0.00001 Range";
                    if(incDec==1)value=value+0.00001;else value=value-0.00001;
           }
           else if(pos==6){
//               qDebug()<<"0.000001 Range";
                    if(incDec==1)value=value+0.000001;else value=value-0.000001;
           }
       }
       else{
           qDebug()<<"out of Range";
    }
//    qDebug()<<"validateCursorPosition->output:"<<value;
    return value;
}

void offset::on_pushButton_clicked()
{
    this->close();
}
