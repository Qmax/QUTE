#include "numberpanel.h"
#include "ui_numberpanel.h"
#include <qdebug.h>
#include <math.h>


NumberPanel::NumberPanel(short int pDeciValue,QWidget *parent) :
        QWidget(parent,Qt::WindowTitleHint),
    ui(new Ui::NumberPanel)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/image.png"));
    this->setFont(QFont("DejaVu Sans",14,50,false));
    InitialisePTNumKeyMap();
    constructVirtualNumPad();
    m_nFlag = pDeciValue;
    ratio=1;
    deci_length=0;
    //setGeometry(parent->width()/2,parent->height()/2,400,450)
    setGeometry(100,100,450,450);
    connect(this,SIGNAL(passText(uint)),parent,SLOT(receiveValue(uint)));
    connect(this,SIGNAL(passText1(double)),parent,SLOT(receiveValue(double)));
    connect(this,SIGNAL(passText2(QString)),parent,SLOT(receiveValue(QString)));
    Max=117440512;
    Min=-7000000;
    alert=new QMessageBox(this);
    alert->setFont(QFont("DejaVu Sans",14,50,false));
}

NumberPanel::NumberPanel(short int pDeciValue,double incRatio,char type,double max,double min,QWidget *parent) :
        QWidget(parent,Qt::WindowTitleHint),
    ui(new Ui::NumberPanel)
{
    ui->setupUi(this);

    this->setWindowIcon(QIcon(":/image(2).png"));
    this->setFont(QFont("DejaVu Sans",14,50,false));

    deci_length=0;
    ratio=incRatio;	    Max=max;	    Min=min;	panelType=type;		m_nFlag = pDeciValue;

    //qDebug()<<"incRatio"<<incRatio;
    //qDebug("Panel Type : %c",panelType);

    if(panelType=='V'||panelType=='v'){
    	this->setWindowTitle("Voltage");
    	ui->label->setText("V");
    }
    if(panelType=='I'){
    	this->setWindowTitle("Current");
    	ui->label->setText("A");
    }
    if(panelType=='F'){
    	this->setWindowTitle("Frequency");
    	ui->label->setText("Hz");
    }
    if(panelType=='K'){
    	this->setWindowTitle("Temperature");
    	QString cel=QChar(0x2103);
    	ui->label->setText(cel);
    }
    if(panelType=='T'){
    	this->setWindowTitle("Period");
    	ui->label->setText("sec");
    }
    if(panelType=='D'){
    	this->setWindowTitle("Phase");
    	QString deg=QChar(0x00B0);
    	ui->label->setText(deg);
    }
    if(panelType=='H'){
        this->setWindowTitle("Hex");
        ui->label->setText("Hex");
    }
    if(panelType=='R'){
    	this->setWindowTitle("Resistance");
    	QString ohms=QChar(0x2126);
    	ui->label->setText(ohms);
    }
    if(panelType=='L'){
      	this->setWindowTitle("Inductance");
       	ui->label->setText("H");
    }
    if(panelType=='C'){
    	this->setWindowTitle("Capacitance");
    	ui->label->setText("F");
    }

    InitialisePTNumKeyMap();
    constructVirtualNumPad();

    //setGeometry(parent->width()/2,parent->height()/2,400,450)
    setGeometry(100,100,450,450);
    connect(this,SIGNAL(passText(uint)),parent,SLOT(receiveValue(uint)));
    connect(this,SIGNAL(passText1(double)),parent,SLOT(receiveValue(double)));
    connect(this,SIGNAL(passText2(QString)),parent,SLOT(receiveValue(QString)));

    alert=new QMessageBox(this);
    alert->setFont(QFont("DejaVu Sans",14,50,false));

}
double NumberPanel::maxMinCheck(double max,double min,double value){
    if(value>=min&&value<=max){
//        qDebug()<<"max min check passed";
        return value;
    }
    else{
        if(value>max){
            alert->setText("Entered Value is greater than Maximum Value");
            alert->exec();
//            qDebug()<<"Entered Value is greater than Maximum Value";
            return max;
        }
        else if(value<min){
            alert->setText("Entered Value is lesser than Minimum Value");
            alert->exec();
//            qDebug()<<"Entered Value is lesser than Minimum Value";
            return min;
        }
    }
    return value;
}
void NumberPanel::setNumer(double* pNum)
{
	m_nFloatNumber = pNum;
}
void NumberPanel::setNumer(unsigned int *pNum)
{
	m_nNumber = pNum;
}
void NumberPanel::setNumer(QString *pNum)
{
        m_sNumber = pNum;
}

NumberPanel::~NumberPanel()
{
	 delete ui;

}

void NumberPanel::changeEvent(QEvent *e)
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

void NumberPanel::InitialisePTNumKeyMap()
{

    m_mapPTMiscKeys.insert(0,"Max");
    m_mapPTMiscKeys.insert(1,"Default");
    m_mapPTMiscKeys.insert(2,"Min");

    m_mapOKCancelKeys.insert(0,"Cancel");
    m_mapOKCancelKeys.insert(1,"OK");

    m_mapVHexKeys.insert(0,"A");
    m_mapVHexKeys.insert(1,"B");
    m_mapVHexKeys.insert(2,"C");
    m_mapVHexKeys.insert(3,"D");
    m_mapVHexKeys.insert(4,"E");
    m_mapVHexKeys.insert(5,"F");

    m_mapPTNumKeys.insert(0,"7");
    m_mapPTNumKeys.insert(1,"8");
    m_mapPTNumKeys.insert(2,"9");
    m_mapPTNumKeys.insert(3,"A");

    if(panelType=='V'||panelType=='v'||panelType=='L'||panelType=='I')
    	m_mapPTNumKeys.insert(4,"u");
    else if(panelType=='F'||panelType=='R')
    	m_mapPTNumKeys.insert(4,"K");
    else
    	m_mapPTNumKeys.insert(4,"m");

    m_mapPTNumKeys.insert(5,"4");
    m_mapPTNumKeys.insert(6,"5");
    m_mapPTNumKeys.insert(7,"6");
    m_mapPTNumKeys.insert(8,"B");
    if(panelType=='V'||panelType=='v'||panelType=='L'||panelType=='I')
    	m_mapPTNumKeys.insert(9,"m");
    else if(panelType=='F'||panelType=='R')
    	m_mapPTNumKeys.insert(9,"M");
    else
    	m_mapPTNumKeys.insert(9,"u");

    m_mapPTNumKeys.insert(10,"1");
    m_mapPTNumKeys.insert(11,"2");
    m_mapPTNumKeys.insert(12,"3");
    m_mapPTNumKeys.insert(13,"C");
    m_mapPTNumKeys.insert(14,"n");
    m_mapPTNumKeys.insert(15,".");
    m_mapPTNumKeys.insert(16,"0");
    m_mapPTNumKeys.insert(17,"+/-");
    m_mapPTNumKeys.insert(18,"D");
    m_mapPTNumKeys.insert(19,"p");
    m_mapPTNumKeys.insert(20,"Clear");
    m_mapPTNumKeys.insert(21,"Back");
    m_mapPTNumKeys.insert(22,"EXP");
    m_mapPTNumKeys.insert(23,"E");
    m_mapPTNumKeys.insert(24,"F");



}
void NumberPanel::constructVirtualNumPad()
{

    QSize l_tempSize(60,50);
    int l_nXMove=90,l_nYMove=95;
    int l_nHeight=50,l_nWidth=60;

    if(panelType!='V'&&panelType!='F'&&panelType!='D'&&panelType!='H'&&panelType!='T'&&panelType!='K'&&panelType!='v'&&panelType!='R'&&panelType!='L'&&panelType!='C')
    	for(int l_nButtonIndex=0;l_nButtonIndex < m_mapPTNumKeys.count();l_nButtonIndex++){
 	    	m_objVKeyButtons[l_nButtonIndex] = new QmaxButton(m_mapPTNumKeys.value(l_nButtonIndex),l_tempSize,"",0,l_nButtonIndex,this);
    	    connect(m_objVKeyButtons[l_nButtonIndex],SIGNAL(clicked(int)),this,SLOT(buttonPressed(int)));
            m_objVKeyButtons[l_nButtonIndex]->setGeometry(l_nXMove,l_nYMove,l_nWidth,l_nHeight);
            if(l_nButtonIndex == 3 || l_nButtonIndex == 8 ||l_nButtonIndex == 13 ||l_nButtonIndex == 18 ||l_nButtonIndex == 23)
                l_nXMove +=75;
            else
                l_nXMove +=65;
            if(l_nButtonIndex == 4 || l_nButtonIndex == 9 ||l_nButtonIndex == 14 || l_nButtonIndex == 19){
                l_nYMove +=52;
                l_nXMove = 90;
            }

        }


    	if(panelType=='V'||panelType=='v'||panelType=='F'||panelType=='T'||panelType=='I')
        	for(int l_nButtonIndex=0;l_nButtonIndex < m_mapPTNumKeys.count();l_nButtonIndex++)
        	{
        		if(l_nButtonIndex!=3&&l_nButtonIndex!=8&&l_nButtonIndex!=13/*&&l_nButtonIndex!=14*/&&l_nButtonIndex!=18&&
        				l_nButtonIndex!=19&&l_nButtonIndex!=22&&l_nButtonIndex!=23&&l_nButtonIndex!=24){
         	    	m_objVKeyButtons[l_nButtonIndex] = new QmaxButton(m_mapPTNumKeys.value(l_nButtonIndex),l_tempSize,"",0,l_nButtonIndex,this);
            	    connect(m_objVKeyButtons[l_nButtonIndex],SIGNAL(clicked(int)),this,SLOT(buttonPressed(int)));
                    m_objVKeyButtons[l_nButtonIndex]->setGeometry(l_nXMove,l_nYMove,l_nWidth,l_nHeight);
        		}
                    if(l_nButtonIndex == 3 || l_nButtonIndex == 8 ||l_nButtonIndex == 13 ||l_nButtonIndex == 18 ||l_nButtonIndex == 23)
                        l_nXMove +=75;
                    else
                        l_nXMove +=65;
                    if(l_nButtonIndex == 4 || l_nButtonIndex == 9 ||l_nButtonIndex == 14 || l_nButtonIndex == 19){
                        l_nYMove +=52;
                        l_nXMove = 90;
                    }

        	}
    	else if(panelType=='D'||panelType=='K')
        	for(int l_nButtonIndex=0;l_nButtonIndex < m_mapPTNumKeys.count();l_nButtonIndex++)
        	{
        		if(l_nButtonIndex!=3&&l_nButtonIndex!=4&&l_nButtonIndex!=8&&l_nButtonIndex!=9&&l_nButtonIndex!=13&&l_nButtonIndex!=14&&
        				l_nButtonIndex!=18&&l_nButtonIndex!=19&&l_nButtonIndex!=22&&l_nButtonIndex!=23&&l_nButtonIndex!=24){
         	    	m_objVKeyButtons[l_nButtonIndex] = new QmaxButton(m_mapPTNumKeys.value(l_nButtonIndex),l_tempSize,"",0,l_nButtonIndex,this);
            	    connect(m_objVKeyButtons[l_nButtonIndex],SIGNAL(clicked(int)),this,SLOT(buttonPressed(int)));
                    m_objVKeyButtons[l_nButtonIndex]->setGeometry(l_nXMove,l_nYMove,l_nWidth,l_nHeight);
        		}
                    if(l_nButtonIndex == 3 || l_nButtonIndex == 8 ||l_nButtonIndex == 13 ||l_nButtonIndex == 18 ||l_nButtonIndex == 23)
                        l_nXMove +=75;
                    else
                        l_nXMove +=65;
                    if(l_nButtonIndex == 4 || l_nButtonIndex == 9 ||l_nButtonIndex == 14 || l_nButtonIndex == 19){
                        l_nYMove +=52;
                        l_nXMove = 90;
                    }

        	}
        else if(panelType=='H')
                for(int l_nButtonIndex=0;l_nButtonIndex < m_mapPTNumKeys.count();l_nButtonIndex++)
                {
                        if(l_nButtonIndex!=4&&l_nButtonIndex!=9&&l_nButtonIndex!=14&&
                                        l_nButtonIndex!=19&&l_nButtonIndex!=22){
                        m_objVKeyButtons[l_nButtonIndex] = new QmaxButton(m_mapPTNumKeys.value(l_nButtonIndex),l_tempSize,"",0,l_nButtonIndex,this);
                    connect(m_objVKeyButtons[l_nButtonIndex],SIGNAL(clicked(int)),this,SLOT(buttonPressed(int)));
                    m_objVKeyButtons[l_nButtonIndex]->setGeometry(l_nXMove,l_nYMove,l_nWidth,l_nHeight);
                        }
                    if(l_nButtonIndex == 3 || l_nButtonIndex == 8 ||l_nButtonIndex == 13 ||l_nButtonIndex == 18 ||l_nButtonIndex == 23)
                        l_nXMove +=75;
                    else
                        l_nXMove +=65;
                    if(l_nButtonIndex == 4 || l_nButtonIndex == 9 ||l_nButtonIndex == 14 || l_nButtonIndex == 19){
                        l_nYMove +=52;
                        l_nXMove = 90;
                    }

                }
        else if(panelType=='R'||panelType=='L')
        	for(int l_nButtonIndex=0;l_nButtonIndex < m_mapPTNumKeys.count();l_nButtonIndex++){
        		if(l_nButtonIndex!=3&&l_nButtonIndex!=8&&l_nButtonIndex!=13&&l_nButtonIndex!=14&&l_nButtonIndex!=18&&
        				l_nButtonIndex!=19&&l_nButtonIndex!=22&&l_nButtonIndex!=23&&l_nButtonIndex!=24){
         	    	m_objVKeyButtons[l_nButtonIndex] = new QmaxButton(m_mapPTNumKeys.value(l_nButtonIndex),l_tempSize,"",0,l_nButtonIndex,this);
            	    connect(m_objVKeyButtons[l_nButtonIndex],SIGNAL(clicked(int)),this,SLOT(buttonPressed(int)));
                    m_objVKeyButtons[l_nButtonIndex]->setGeometry(l_nXMove,l_nYMove,l_nWidth,l_nHeight);
        		}
                    if(l_nButtonIndex == 3 || l_nButtonIndex == 8 ||l_nButtonIndex == 13 ||l_nButtonIndex == 18 ||l_nButtonIndex == 23)
                        l_nXMove +=75;
                    else
                        l_nXMove +=65;
                    if(l_nButtonIndex == 4 || l_nButtonIndex == 9 ||l_nButtonIndex == 14 || l_nButtonIndex == 19){
                        l_nYMove +=52;
                        l_nXMove = 90;
                    }
        }
        else if(panelType=='C')
        	for(int l_nButtonIndex=0;l_nButtonIndex < m_mapPTNumKeys.count();l_nButtonIndex++){
        		if(l_nButtonIndex!=3&&l_nButtonIndex!=8&&l_nButtonIndex!=13/*&&l_nButtonIndex!=14*/&&l_nButtonIndex!=18/*&&
        				l_nButtonIndex!=19*/&&l_nButtonIndex!=22&&l_nButtonIndex!=23&&l_nButtonIndex!=24){
         	    	m_objVKeyButtons[l_nButtonIndex] = new QmaxButton(m_mapPTNumKeys.value(l_nButtonIndex),l_tempSize,"",0,l_nButtonIndex,this);
            	    connect(m_objVKeyButtons[l_nButtonIndex],SIGNAL(clicked(int)),this,SLOT(buttonPressed(int)));
                    m_objVKeyButtons[l_nButtonIndex]->setGeometry(l_nXMove,l_nYMove,l_nWidth,l_nHeight);
        		}
                    if(l_nButtonIndex == 3 || l_nButtonIndex == 8 ||l_nButtonIndex == 13 ||l_nButtonIndex == 18 ||l_nButtonIndex == 23)
                        l_nXMove +=75;
                    else
                        l_nXMove +=65;
                    if(l_nButtonIndex == 4 || l_nButtonIndex == 9 ||l_nButtonIndex == 14 || l_nButtonIndex == 19){
                        l_nYMove +=52;
                        l_nXMove = 90;
                    }
        }

//    l_nYMove=95;
//    for(int l_nHexIndex=0;l_nHexIndex<m_mapVHexKeys.count();l_nHexIndex++){
//    	m_objVHexButtons[l_nHexIndex] = new QmaxButton(m_mapVHexKeys.value(l_nHexIndex),l_tempSize,"",0,24+l_nHexIndex,this);
//        connect(m_objVHexButtons[l_nHexIndex],SIGNAL(clicked(int)),this,SLOT(buttonPressed(int)));
//        m_objVHexButtons[l_nHexIndex]->setGeometry(400,l_nYMove,100,40);
//        l_nYMove +=52;
//    }

    m_objVOKCancelButtons[0] = new QmaxButton(m_mapOKCancelKeys.value(0),QSize(100,40),"",0,25,this);
    connect(m_objVOKCancelButtons[0],SIGNAL(clicked(int)),this,SLOT(buttonPressed(int)));
    m_objVOKCancelButtons[0]->setGeometry(200,390,100,40);

    m_objVOKCancelButtons[1] = new QmaxButton(m_mapOKCancelKeys.value(1),QSize(100,40),"",0,26,this);
    connect(m_objVOKCancelButtons[1],SIGNAL(clicked(int)),this,SLOT(buttonPressed(int)));
    m_objVOKCancelButtons[1]->setGeometry(80,390,100,40);

    if(panelType!='V'&&panelType!='F'&&panelType!='D'){
    m_objVMiscButtons[0] = new QmaxButton(m_mapPTMiscKeys.value(0),QSize(70,50),"",0,27,this);
    connect(m_objVMiscButtons[0],SIGNAL(clicked(int)),this,SLOT(buttonPressed(int)));
    m_objVMiscButtons[0]->setGeometry(5,95,70,50);

    m_objVMiscButtons[1] = new QmaxButton(m_mapPTMiscKeys.value(1),QSize(70,50),"",0,28,this);
    connect(m_objVMiscButtons[1],SIGNAL(clicked(int)),this,SLOT(buttonPressed(int)));
    m_objVMiscButtons[1]->setGeometry(5,180,70,50);

    m_objVMiscButtons[2] = new QmaxButton(m_mapPTMiscKeys.value(2),QSize(70,50),"",0,29,this);
    connect(m_objVMiscButtons[2],SIGNAL(clicked(int)),this,SLOT(buttonPressed(int)));
    m_objVMiscButtons[2]->setGeometry(5,270,70,50);
    }
    ArrowButtons[0]=new QmaxButton("INC",QSize(60,40),"",5,30,this);
    connect(ArrowButtons[0],SIGNAL(clicked(int)),this,SLOT(buttonPressed(int)));
    ArrowButtons[0]->setGeometry(300,30,60,40);

    ArrowButtons[1]=new QmaxButton("DEC",QSize(60,40),"",6,31,this);
    connect(ArrowButtons[1],SIGNAL(clicked(int)),this,SLOT(buttonPressed(int)));
    ArrowButtons[1]->setGeometry(350,30,60,40);


}

void NumberPanel::buttonPressed(int pKeyCode)
{
    bool ok=true;
    //qDebug()<<"key :"<<m_mapPTNumKeys.value(pKeyCode)<<"keyCode"<<pKeyCode;

    m_strNumber+=validateKey(m_mapPTNumKeys.value(pKeyCode));
   // qDebug() <<"String Number: "<< m_strNumber<< m_mapPTNumKeys.value(pKeyCode);
    m_strNumber.simplified();
    int posValue = ui->numEdit->cursorPosition();
    ui->numEdit->setText(m_strNumber);
    if(m_mapPTNumKeys.value(pKeyCode).contains("Back")){
        ui->numEdit->setCursorPosition(posValue-1);
        if(pKeyCode!=30&&pKeyCode!=31)
        	deci_length--;
    }
    else{
       ui->numEdit->setCursorPosition(posValue+1);
       if(pKeyCode!=30&&pKeyCode!=31)
    	   deci_length++;
       //qDebug()<<"("<<deci_length<<")";
       if(pKeyCode==15)
    	   deci_length=0;
    }

    if(pKeyCode==4||pKeyCode==9)	//if unit is pressed then perform OK
    	buttonPressed(26);

    if(pKeyCode==15){

    }

    if(pKeyCode == 25){
        m_strNumber ="";
        this->close();
    }

    if(pKeyCode==30){
    	ratio=1.0/pow(10.0,deci_length);
        //qDebug()<<"ratio :"<<ratio;
        l_nDeciNumber=l_nDeciNumber+ratio;
        m_strNumber=QString::number(l_nDeciNumber);
        ui->numEdit->setText(QString::number(l_nDeciNumber));
    }
    else if(pKeyCode==31){
    	ratio=1.0/pow(10.0,deci_length);
        //qDebug()<<"ratio :"<<ratio;
    	if(panelType=='F'||panelType=='R'||panelType=='D'||panelType=='L'||panelType=='C'){
    		if(l_nDeciNumber>0)
    			l_nDeciNumber=l_nDeciNumber-ratio;
    		else
    			l_nDeciNumber=0;
    	}
    	else
        l_nDeciNumber=l_nDeciNumber-ratio;

        m_strNumber=QString::number(l_nDeciNumber);
        ui->numEdit->setText(QString::number(l_nDeciNumber));
    }

    if(pKeyCode == 26){

        if(m_nFlag==0){
                        //qDebug()<<"inside unsigned hex flag";
			l_nNumber = m_strNumber.toUInt(&ok,16);
			if(l_nNumber==maxMinCheck(Max,Min,l_nNumber)){
			emit passText(l_nNumber);
                        emit passText2("0x"+m_strNumber);
			}
                        else{
                            return;
                        }
        }
        else if(m_nFlag ==1)
        {

                //qDebug()<<"inside double flag";

                if(m_strNumber.endsWith('m')==true){
                    m_strNumber.chop(1);
                    l_nDeciNumber = m_strNumber.toDouble(&ok)*0.001;
                    m_strNumber=m_strNumber+"m";
                }
                else if(m_strNumber.endsWith('u')==true){
                    m_strNumber.chop(1);
                    l_nDeciNumber = m_strNumber.toDouble(&ok)*0.000001;
                    m_strNumber=m_strNumber+"u";
                }
                else if(m_strNumber.endsWith('n')==true){
                    m_strNumber.chop(1);
                   l_nDeciNumber=m_strNumber.toDouble(&ok)*0.000000001;
                   m_strNumber=m_strNumber+"n";

                }
                else if(m_strNumber.endsWith('p')==true){
                    m_strNumber.chop(1);
                   l_nDeciNumber=m_strNumber.toDouble(&ok)*0.000000000001;
                   m_strNumber=m_strNumber+"p";
                }
                else if(m_strNumber.endsWith('K')==true){
                    m_strNumber.chop(1);
                   l_nDeciNumber=m_strNumber.toDouble(&ok)*1000;
                   m_strNumber=m_strNumber+"K";
                }
                else if(m_strNumber.endsWith('M')==true){
                    m_strNumber.chop(1);
                   l_nDeciNumber=m_strNumber.toDouble(&ok)*1000000;
                   m_strNumber=m_strNumber+"M";
                }
                if(l_nDeciNumber==maxMinCheck(Max,Min,l_nDeciNumber)){   //validate with min/max
                emit passText1(l_nDeciNumber);
                if(panelType=='V')
                	emit passText2(m_strNumber+"Vpp");
                else if(panelType=='I')
                	emit passText2(m_strNumber+"A");
                else if(panelType=='v')
                	emit passText2(m_strNumber+"V");
                else if(panelType=='F')
                	emit passText2(m_strNumber+"Hz");
                else if(panelType=='R'){
                	QString ohms=QChar(0x2126);
                	emit passText2(m_strNumber+ohms);
                }
                else if(panelType=='L')
                	emit passText2(m_strNumber+"H");

                else if(panelType=='C')
                	emit passText2(m_strNumber+"F");

                else if(panelType=='D'){
                	QString deg=QChar(0x00B0);
                	emit passText2(m_strNumber+deg);
                }
                else if(panelType=='H'){
                    emit passText2("0x"+m_strNumber);
                }
                else if(panelType=='K'){
                  	QString cel=QChar(0x2103);
                   	emit passText2(m_strNumber+cel);
                }
                else if(panelType=='T'){
                   	emit passText2(m_strNumber+"sec");
                }
                else
                	emit passText2(m_strNumber);
                }
                else
                    return;
        }
        else if(m_nFlag ==2)
        {
//                qDebug()<<"inside unsigned decimel flag";
        	l_nNumber = m_strNumber.toUInt(&ok,10);
        	if(l_nNumber==maxMinCheck(Max,Min,l_nNumber)){
        		emit passText(l_nNumber);
                }else   return;

        }
        else if(m_nFlag==3){
                //qDebug()<<"inside string flag";
                if(panelType=='V')
                	emit passText2(m_strNumber+"Vpp");
                else if(panelType=='I')
                	emit passText2(m_strNumber+"A");
                else if(panelType=='v')
                	emit passText2(m_strNumber+"V");
                else if(panelType=='F')
                	emit passText2(m_strNumber+"Hz");
                else if(panelType=='R'){
                	QString ohms=QChar(0x2126);
                	emit passText2(m_strNumber+ohms);
                }
                else if(panelType=='L')
                	emit passText2(m_strNumber+"H");

                else if(panelType=='C')
                	emit passText2(m_strNumber+"F");
                else if(panelType=='D'){
                	QString deg=QChar(0x00B0);
                	emit passText2(m_strNumber+deg);
                }
                else if(panelType=='H'){
                    emit passText2("0x"+m_strNumber);
                }
                else if(panelType=='C'){
                  	QString cel=QChar(0x2103);
                   	emit passText2(m_strNumber+cel);
                }
                else if(panelType=='T'){
                   	emit passText2(m_strNumber+"sec");
                }
                else
                	emit passText2(m_strNumber);
        }

//        qDebug() << "title" <<this->windowTitle();
        this->close();
//        qDebug() << "title1" <<this->windowTitle();
    }

}



QString NumberPanel::validateKey(QString pKey)
{
    QStringList m_strKey;
    QString l_nTempKey;
    l_nTempKey = m_strNumber;
//    printf("Length:%d\n",pKey.length());
    if(pKey.length() >=3 )
    {
        if(pKey.contains("Back"))
        {

            m_strNumber = "";
            l_nTempKey.remove(l_nTempKey.length()-1,l_nTempKey.length());
            return l_nTempKey;
        }
        if(pKey.contains("EXP"))
        {
            m_strNumber = "";
            return l_nTempKey;
        }
        if(pKey.contains("Clear"))
        {
            m_strNumber = "";
            return m_strNumber;
        }
        if(pKey.contains("+/-"))
        {
            m_strNumber = "";
        	if(l_nTempKey.contains("-"))
        	{
        		l_nTempKey.remove("-");
        		return l_nTempKey;
        	}
            return QString("-")+l_nTempKey;
        }
    }
    else
        return pKey;
    return pKey;
}

void NumberPanel::on_numEdit_textChanged(QString )
{
    l_nDeciNumber=ui->numEdit->text().toDouble();
}
