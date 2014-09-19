#include "mutlipewavedialog.h"
#include <qlabel.h>
#include <QPixmap>
#include <qclipboard.h>


MutlipeWaveDialog::MutlipeWaveDialog(QWidget *parent,VIModel *pObjSubject,VIFunctionalLogic *pFunObj)
    : QDialog(parent,Qt::WindowSystemMenuHint)
{
	ui.setupUi(this);
	m_obVImodel = pObjSubject;
	m_objFunctionLogic = pFunObj;
	m_lstMultipleTraces.clear();
	m_mapCombinations = m_obVImodel->getPinCombinations();
	//m_lstMultipleTraces = m_obVImodel->getPinCombinations()
	//m_lstMultipleTraces.sort();
	connect(ui.objClose,SIGNAL(clicked()),this,SLOT(closeApp()));
	connect(ui.butNext,SIGNAL(clicked()),this,SLOT(onNext()));
	connect(ui.butPrev,SIGNAL(clicked()),this,SLOT(onPrevious()));
	connect(ui.butPass,SIGNAL(clicked()),this,SLOT(onPassTraces()));
	connect(ui.butFail,SIGNAL(clicked()),this,SLOT(onFailTraces()));
	connect(ui.butALL,SIGNAL(clicked()),this,SLOT(onAllTraces()));

	m_nSelectedIndex=0;
	//m_nEndIndex=0;
	ui.lblCombinations->setText(QString::number(m_obVImodel->getChipDialog(4),10));
	if(m_obVImodel->getChipDialog(4) > 6)
		ui.lblCurrenttoTotal->setText("1 to "+ QString::number(m_obVImodel->getChipDialog(4),10));
	else
		ui.lblCurrenttoTotal->setText(QString::number(m_obVImodel->getChipDialog(4),10)+ " to "+ QString::number(m_obVImodel->getChipDialog(4),10));

	initializeWaveProduct();
	isPassFlag=isFailFlag=false;
	//calculateCombinationalTraces(m_obVImodel->getClipLearntFlag());
	//LoadVITraces(m_nSelectedIndex);

}

MutlipeWaveDialog::~MutlipeWaveDialog()
{

}

int MutlipeWaveDialog::getFailCount()
{
	return m_lstFailStrTraces.count();
}

int MutlipeWaveDialog::getPassCount()
{
	return m_lstPassStrTraces.count();
}

void MutlipeWaveDialog::LoadLearntTraces()
{
	QString l_strTestFileName="";
	QList<short int> l_lstKeys = m_mapCombinations.keys();
	//qDebug()<< "Learnt Count:"<<l_lstKeys.count();
	short int l_nLoopIndex=0;
	for(short int l_nRefIndex=0;l_nRefIndex<l_lstKeys.count();l_nRefIndex++)
		{
			short int l_nReferencePin= l_lstKeys.value(l_nRefIndex);
			//qDebug() << "Reference Pin:"<<l_nReferencePin;
			for(short l_nPinsIndex=0;l_nPinsIndex<m_mapCombinations.value(l_lstKeys.value(l_nRefIndex))->count();l_nPinsIndex++)
			{
				QList<short>* l_lstPindexIndex = m_mapCombinations.value(l_lstKeys.value(l_nRefIndex));
				//qDebug()<<"Pins Index:"<<l_lstPindexIndex->value(l_nPinsIndex);
				l_strTestFileName = QString::number(l_nReferencePin,10)+"_"+QString::number(l_lstPindexIndex->value(l_nPinsIndex),10);
				m_lstMultipleTraces.insert(l_nLoopIndex++,l_strTestFileName);
			}
		}
}


void MutlipeWaveDialog::calculateCombinationalTraces(bool pFlag)
{
	Q_UNUSED(pFlag)
	int l_nFailIndex=0,l_nPassIndex=0;
	QString l_strTestFileName="",l_strLearnt="Learnt";
	QList<short int> l_lstKeys = m_mapCombinations.keys();
	m_lstFailStrTraces.clear();
	m_lstPassStrTraces.clear();
	short int l_nLoopIndex=0;
	for(short int l_nRefIndex=0;l_nRefIndex<l_lstKeys.count();l_nRefIndex++)
	{
		short int l_nReferencePin= l_lstKeys.value(l_nRefIndex);
		for(short l_nPinsIndex=0;l_nPinsIndex<m_mapCombinations.value(l_lstKeys.value(l_nRefIndex))->count();l_nPinsIndex++)
		{
		QList<short>* l_lstPindexIndex = m_mapCombinations.value(l_lstKeys.value(l_nRefIndex));
		QString l_strActualFileName = "Learnt_"+QString::number(l_nReferencePin,10)+"_"+QString::number(l_lstPindexIndex->value(l_nPinsIndex),10)+".bin";
		QString l_strTestFileName = "Test_"+QString::number(l_nReferencePin,10)+"_"+QString::number(l_lstPindexIndex->value(l_nPinsIndex),10)+".bin";
		QString l_strCombination = QString::number(l_nReferencePin,10)+"_"+QString::number(l_lstPindexIndex->value(l_nPinsIndex),10);
		if(m_obVImodel->getChipDialog(5)==1)
		{
			m_lstMultipleTraces.insert(l_nPinsIndex,l_strCombination);
			continue;
		}
		QStringList l_lstRefData = m_objFunctionLogic->getFileData(l_strActualFileName);//m_obVImodel->getFileData("Learnt" +l_strActualFileName+".bin");
		QStringList l_lstTestData = m_objFunctionLogic->getFileData(l_strTestFileName);
		m_objFunctionLogic->calculateAverage("./CalibrationReference.bin");
		unsigned int l_nErrpercentage = m_objFunctionLogic->caluculateErrorPercentange(l_lstRefData,l_lstTestData);
        //qDebug() << "Pin:" << l_strActualFileName << "Index:" << l_nLstIndex;
		if(l_nErrpercentage >m_obVImodel->getClipThreshold()){
			m_lstFailStrTraces.insert(l_nFailIndex,l_strCombination);
			l_nFailIndex++;
		}
		else{
			m_lstPassStrTraces.insert(l_nPassIndex,l_strCombination);
			l_nPassIndex++;
            }
			m_lstMultipleTraces.insert(l_nLoopIndex++,l_strCombination);
		}
	}
    if(m_lstPassStrTraces.count() >0)
    	ui.butPass->setDisabled(false);
    else
    	ui.butPass->setDisabled(true);
    if(m_lstFailStrTraces.count() >0)
    	ui.butFail->setDisabled(false);
    else
    	ui.butFail->setDisabled(true);
    ui.butALL->setDisabled(false);
    //isPassFlag=isFailFlag = true;
    qDebug() << "PassTraces Count:" << m_lstPassStrTraces.count();
    qDebug() << "FailTraces Count:" << m_lstFailStrTraces.count();
	ui.butFail->setStyleSheet("QPushButton { background-color :rgb(88,88,87,255); color : white; }");
	ui.butPass->setStyleSheet("QPushButton { background-color :rgb(88,88,87,255); color : white; }");
	ui.butALL->setStyleSheet("QPushButton { background-color: rgb(82, 127, 162); color : white; }");

}

void MutlipeWaveDialog::clickedPRSCR()
{
	QPixmap Pix;
    Pix = QPixmap();
    //Pix = QPixmap::grabWidget(ui->FGSubwindow,0,0,800,600);
    Pix = QPixmap::grabWindow(this->winId());
    Pix.save("MultipleTraces.jpg");
    QClipboard *board = QApplication::clipboard();
    board->setPixmap(Pix);
    QWidget::showFullScreen();
}


void MutlipeWaveDialog::setTestFlag(bool pFlag)
{
	isLearn = pFlag;
	isPassFlag=isFailFlag=false;
    if(isLearn == true)
    {
    	ui.butPass->setDisabled(true);
    	ui.butFail->setDisabled(true);
    	ui.butALL->setDisabled(true);
    }

}

void MutlipeWaveDialog::initializeWaveProduct()
{
	   int l_nXIndex=0,l_nYIndex=0;
	   QFont font;
	   font.setFamily("DejaVu Sans");
	   font.setBold(true);
	   font.setPointSize(15);
        m_objWaveFactory = new WaveFormFactory();
	    //ui.lbl1->setGeometry(9+l_nXIndex,9+l_nYIndex,200,12);
	    for(int l_nVIIndex=0;l_nVIIndex<6;l_nVIIndex++)
	    {
	    	VIProduct[l_nVIIndex] = m_objWaveFactory->getWaveProduct("VI",this);
	    	VIProduct[l_nVIIndex]->setDimensions(10+l_nXIndex,25+l_nYIndex,150,150);
	    	VIProduct[l_nVIIndex]->setTickValue(0);
	    	label[l_nVIIndex] = new QLabel(this);
	    	label[l_nVIIndex]->setText("");
	    	label[l_nVIIndex]->setGeometry(9+l_nXIndex,9+l_nYIndex,200,12);
	    	label[l_nVIIndex]->setStyleSheet("QLabel { color : white; }");
	    	//label[l_nVIIndex]->setPalette(QColor(QColor(255,255,255,255)));
	    	compareLabel[l_nVIIndex] = new QLabel(this);
	    	compareLabel[l_nVIIndex]->setText("");
	    	compareLabel[l_nVIIndex]->setFont(font);
	    	compareLabel[l_nVIIndex]->setGeometry(80+l_nXIndex,9+l_nYIndex,200,12);

	    	l_nXIndex+=160;
                if(l_nVIIndex == 2) {l_nYIndex +=170;l_nXIndex=0;}
	    }
	    if(m_obVImodel->getClipLearntFlag() == true)
	    {
	    	setTestFlag(true);
	    }
	    else
	    {
	    	setTestFlag(false);
	    }
}

void MutlipeWaveDialog::LoadFailTraces(short int pStartIndex)
{
    short int l_nMoveIndex=pStartIndex;
    int l_nXIndex=0,l_nYIndex=0;
    l_nXIndex=l_nYIndex=0;
//    qDebug() << "Fail Trace:" << pStartIndex;
    QString l_strLabel = "./CalibrationReference.bin";
    for(int l_nLstIndex=0;l_nLstIndex<6;l_nLstIndex++)
    {
    	QString l_strActualFileName;
   		l_strActualFileName = m_lstFailStrTraces.value(l_nMoveIndex++);
    	if(l_strActualFileName.count() == 0) return;
    	l_nXIndex+=160;
    	if(l_nLstIndex == 2) {l_nYIndex +=172;l_nXIndex=0;}
    	if(m_lstFailStrTraces.value(l_nLstIndex).count() >0 )
    	{
    		label[l_nLstIndex]->setText("Pin_"+l_strActualFileName);
			stWaveData* l_objVIWaveData = m_objFunctionLogic->showVITrace(0,m_obVImodel->getIndexTemplate(0));
        	l_objVIWaveData->m_bCalibChecked=true;
        	l_objVIWaveData->m_nCalibrationConstant=m_objFunctionLogic->getReceiveCalibrationConstant(m_obVImodel->getIndexTemplate(0));
        	l_objVIWaveData->m_nCalibrationGain=m_objFunctionLogic->getReceiveCalibrationGain(m_obVImodel->getIndexTemplate(0));

			if(m_obVImodel->getChipDialog(5) == 1)
        	{
				l_objVIWaveData->m_nEnvelopBand = m_obVImodel->getClipThreshold();
				VIProduct[l_nLstIndex]->LoadVIData(l_strLabel,"Learnt_"+l_strActualFileName+".bin", 0,3, l_objVIWaveData);
			    if (VIProduct[l_nLstIndex]->compareBand(0) == true)
			    {
			    	compareLabel[l_nLstIndex]->setStyleSheet("QLabel { color : lightgreen; }");
			    	compareLabel[l_nLstIndex]->setText("PASS");
				}
			    else
			    {
			    	compareLabel[l_nLstIndex]->setStyleSheet("QLabel { color : red; }");
			    	compareLabel[l_nLstIndex]->setText("FAIL");
				}
			    continue;
        	}

			VIProduct[l_nLstIndex]->LoadVIData(l_strLabel,"Learnt_" +l_strActualFileName+".bin",0,0,l_objVIWaveData);
			VIProduct[l_nLstIndex]->LoadVIData(l_strLabel,"Test_" + l_strActualFileName+".bin",1,0,l_objVIWaveData);
			QStringList l_lstRefData = m_objFunctionLogic->getFileData("Learnt_" +l_strActualFileName+".bin");
			QStringList l_lstTestData = m_objFunctionLogic->getFileData("Test_" +l_strActualFileName+".bin");
			QStringList l_lstAvgData = m_objFunctionLogic->getFileData(l_strLabel);
			m_objFunctionLogic->calculateAverage(l_strLabel);
			unsigned int l_nErrpercentage = m_objFunctionLogic->caluculateErrorPercentange(l_lstRefData,l_lstTestData);
			if(l_nErrpercentage >m_obVImodel->getClipThreshold())
				compareLabel[l_nLstIndex]->setStyleSheet("QLabel { color : red; }");
			else
				compareLabel[l_nLstIndex]->setStyleSheet("QLabel { color : lightgreen; }");
			compareLabel[l_nLstIndex]->setText("Err:"+QString::number(l_nErrpercentage,10)+"%");
    	 }
    	}
}



void MutlipeWaveDialog::LoadPassTraces(short int pStartIndex)
{
    short int l_nMoveIndex=pStartIndex;
    int l_nXIndex=0,l_nYIndex=0;
    l_nXIndex=l_nYIndex=0;
    QString l_strLabel = "./CalibrationReference.bin";
    for(int l_nLstIndex=0;l_nLstIndex<6;l_nLstIndex++)
    {
    	QString l_strActualFileName;
   		l_strActualFileName = m_lstPassStrTraces.value(l_nMoveIndex++);
    	if(l_strActualFileName.count() == 0) return;
    	l_nXIndex+=160;
    	if(l_nLstIndex == 2) {l_nYIndex +=172;l_nXIndex=0;}
    	if(m_lstPassStrTraces.value(l_nLstIndex).count() >0 ){
    		label[l_nLstIndex]->setText("Pin_"+l_strActualFileName);
			stWaveData* l_objVIWaveData = m_objFunctionLogic->showVITrace(0,m_obVImodel->getIndexTemplate(0));
	       	l_objVIWaveData->m_bCalibChecked=true;
	        	l_objVIWaveData->m_nCalibrationConstant=m_objFunctionLogic->getReceiveCalibrationConstant(m_obVImodel->getIndexTemplate(0));
	        	l_objVIWaveData->m_nCalibrationGain=m_objFunctionLogic->getReceiveCalibrationGain(m_obVImodel->getIndexTemplate(0));

			if(m_obVImodel->getChipDialog(5) == 1)
        	{
				l_objVIWaveData->m_nEnvelopBand = m_obVImodel->getClipThreshold();
				VIProduct[l_nLstIndex]->LoadVIData(l_strLabel,"Learnt_"+l_strActualFileName+".bin", 0,3, l_objVIWaveData);
			    if (VIProduct[l_nLstIndex]->compareBand(0) == true)
			    {
			    	compareLabel[l_nLstIndex]->setStyleSheet("QLabel { color : lightgreen; }");
			    	compareLabel[l_nLstIndex]->setText("PASS");
				}
			    else
			    {
			    	compareLabel[l_nLstIndex]->setStyleSheet("QLabel { color : red; }");
			    	compareLabel[l_nLstIndex]->setText("FAIL");
				}
			    continue;
        	}
			VIProduct[l_nLstIndex]->LoadVIData(l_strLabel,"Learnt_" +l_strActualFileName+".bin",0,0,l_objVIWaveData);
			VIProduct[l_nLstIndex]->LoadVIData(l_strLabel,"Test_" + l_strActualFileName+".bin",1,0,l_objVIWaveData);

			QStringList l_lstRefData = m_objFunctionLogic->getFileData("Learnt_" +l_strActualFileName+".bin");
			QStringList l_lstTestData = m_objFunctionLogic->getFileData("Test_" +l_strActualFileName+".bin");
			QStringList l_lstAvgData = m_objFunctionLogic->getFileData(l_strLabel);
			m_objFunctionLogic->calculateAverage(l_strLabel);

			unsigned int l_nErrpercentage = m_objFunctionLogic->caluculateErrorPercentange(l_lstRefData,l_lstTestData);
			if(l_nErrpercentage >m_obVImodel->getClipThreshold())
				compareLabel[l_nLstIndex]->setStyleSheet("QLabel { color : red; }");
			else
				compareLabel[l_nLstIndex]->setStyleSheet("QLabel { color : lightgreen; }");
			compareLabel[l_nLstIndex]->setText("Err:"+QString::number(l_nErrpercentage,10)+"%");    	}
    }
}
void MutlipeWaveDialog::LoadVITraces(short int pStartIndex)
{

	//Qt::darkGreen
    short int l_nMoveIndex=pStartIndex;
    int l_nXIndex=0,l_nYIndex=0;
    l_nXIndex=l_nYIndex=0;
    QString l_strLabel="CalibrationReference.bin";
    QString l_strActualFileName;
   // qDebug()<<"StartCount:"<<l_nMoveIndex<<"Total Count:"<<m_lstMultipleTraces.count();
    for(int l_nLstIndex=0;l_nLstIndex<6;l_nLstIndex++)
    {
    	//QString l_strLabel =  "SINE_"+ QString::number(m_obVImodel->getVoltageValue(),'f',1)+"V_"+QString::number(m_obVImodel->getFrequency(),'f',0)+"_HZ_"+QString::number(m_obVImodel->getImpedanceValue())+".bin";
    	if(isPassFlag==true)
    		l_strActualFileName = m_lstPassStrTraces.value(l_nMoveIndex++);
    	else if(isFailFlag == true)
    		l_strActualFileName = m_lstFailStrTraces.value(l_nMoveIndex++);
    	else
   		    l_strActualFileName = m_lstMultipleTraces.value(l_nMoveIndex++);
   		//qDebug()<<"MoveIndex:"<<l_nMoveIndex;
    	if(l_strActualFileName.count() == 0) return;
    	qDebug() << "Actual FileName" << l_strActualFileName<<"Count:"<<l_strActualFileName.count();
    	l_nXIndex+=160;
    	if(l_nLstIndex == 2) {l_nYIndex +=172;l_nXIndex=0;}
    	if(m_lstMultipleTraces.value(l_nLstIndex).count() >0 ){
    		label[l_nLstIndex]->setText("Pin_"+l_strActualFileName);
    		//qDebug()<<"Label Count:"<<label[l_nLstIndex]->text().count();
            stWaveData* l_objVIWaveData = m_objFunctionLogic->showVITrace(0,m_obVImodel->getIndexTemplate(0));
            qDebug()<<m_obVImodel->getVoltageValue();
           	l_objVIWaveData->m_bCalibChecked=true;
            l_objVIWaveData->m_nCalibrationConstant=m_objFunctionLogic->getReceiveCalibrationConstant(m_obVImodel->getIndexTemplate(0));
           	l_objVIWaveData->m_nCalibrationGain=m_objFunctionLogic->getReceiveCalibrationGain(m_obVImodel->getIndexTemplate(0));

    		if(isLearn==true)
    		{
    			//qDebug()<<"Clip Dialog:"<<m_obVImodel->getChipDialog(5);
    			if(m_obVImodel->getChipDialog(5) == 0 || m_obVImodel->getChipDialog(5) == 1)
    				VIProduct[l_nLstIndex]->LoadVIData(l_strLabel,"Learnt_"+l_strActualFileName+".bin",0,0,l_objVIWaveData);
//    			else if(m_obVImodel->getChipDialog(5) == 1)
//            	{
//    				l_objVIWaveData->m_nEnvelopBand = m_obVImodel->getClipThreshold();
//    				VIProduct[l_nLstIndex]->LoadVIData(l_strLabel,"Learnt_"+l_strActualFileName+".bin", 0,3, l_objVIWaveData);
//            		//isCompareActive = true;
//            	}
    		}
    		else if(isLearn == false){
    			if(m_obVImodel->getChipDialog(5) == 1)
            	{
    				l_objVIWaveData->m_nEnvelopBand = m_obVImodel->getClipThreshold();
    				VIProduct[l_nLstIndex]->LoadVIData(l_strLabel,"Learnt_"+l_strActualFileName+".bin", 0,3, l_objVIWaveData);
        			VIProduct[l_nLstIndex]->LoadVIData(l_strLabel,"Test_" + l_strActualFileName+".bin",1,0,l_objVIWaveData);
    			    if (VIProduct[l_nLstIndex]->compareBand(1) == true)
    			    {
    			    	compareLabel[l_nLstIndex]->setStyleSheet("QLabel { color : lightgreen; }");
    			    	compareLabel[l_nLstIndex]->setText("PASS");
    				}
    			    else
    			    {
    			    	compareLabel[l_nLstIndex]->setStyleSheet("QLabel { color : red; }");
    			    	compareLabel[l_nLstIndex]->setText("FAIL");
    				}
            	}
    			else if(m_obVImodel->getChipDialog(5) == 0){
					VIProduct[l_nLstIndex]->LoadVIData(l_strLabel,"Learnt_" +l_strActualFileName+".bin",0,0,l_objVIWaveData);
					VIProduct[l_nLstIndex]->LoadVIData(l_strLabel,"Test_" + l_strActualFileName+".bin",1,0,l_objVIWaveData);
					qDebug()<<"Learnt_" +l_strActualFileName<<"Test_" +l_strActualFileName;
					QStringList l_lstRefData = m_objFunctionLogic->getFileData("Learnt_" +l_strActualFileName+".bin");
					QStringList l_lstTestData = m_objFunctionLogic->getFileData("Test_" +l_strActualFileName+".bin");
					QStringList l_lstAvgData = m_objFunctionLogic->getFileData(l_strLabel);
					m_objFunctionLogic->calculateAverage(l_strLabel);

					unsigned int l_nErrpercentage = m_objFunctionLogic->caluculateErrorPercentange(l_lstRefData,l_lstTestData);
					if(l_nErrpercentage >m_obVImodel->getClipThreshold())
						compareLabel[l_nLstIndex]->setStyleSheet("QLabel { color : red; }");
					else
						compareLabel[l_nLstIndex]->setStyleSheet("QLabel { color : lightgreen; }");
					compareLabel[l_nLstIndex]->setText("Err:"+QString::number(l_nErrpercentage,10)+"%");
    			}
    		}
    	}
    }
    if(m_obVImodel->getChipDialog(5) == 1)
    {
    	if(isFailFlag==true){
    		ui.butFail->setEnabled(true);
    		ui.butPass->setEnabled(true);
    	}
    }
}


void MutlipeWaveDialog::clearTraces()
{
	for(int l_nLstIndex=0;l_nLstIndex<6;l_nLstIndex++)
	{
		VIProduct[l_nLstIndex]->clearCurve(0);
		if(m_obVImodel->getChipDialog(5)==1)
		{
			//qDebug()<<"Clear Band Data";
			VIProduct[l_nLstIndex]->clearBandData(0);
		}
		label[l_nLstIndex]->setText("");
		if( isLearn == false){
			VIProduct[l_nLstIndex]->clearCurve(1);
			if(m_obVImodel->getChipDialog(5)==1)
			{
				//qDebug()<<"Clear Band Data";
				VIProduct[l_nLstIndex]->clearBandData(0);
			}
			compareLabel[l_nLstIndex]->setText("");
		}
		label[l_nLstIndex]->setText("");
	}
}




void MutlipeWaveDialog::onNext()
{
	qDebug() << "onNext Button-Multiple wave Dialog";
	if(isFailFlag== true)
	{	qDebug() << "onNext Button-Multiple wave Dialog-Fail";
		if(m_nSelectedIndex<m_lstFailStrTraces.count()-6 )
			m_nSelectedIndex+=6;
		ui.lblCurrenttoTotal->setText(QString::number(m_nSelectedIndex+1,10)+ " to "+ QString::number(m_lstFailStrTraces.count(),10));
		clearTraces();
		LoadFailTraces(m_nSelectedIndex);
	}
	else if(isPassFlag == true)
	{
		if(m_nSelectedIndex<m_lstPassStrTraces.count()-6 )
			m_nSelectedIndex+=6;
		ui.lblCurrenttoTotal->setText(QString::number(m_nSelectedIndex+1,10)+ " to "+ QString::number(m_lstPassStrTraces.count(),10));
		clearTraces();
		LoadPassTraces(m_nSelectedIndex);
	}
	else{
		if(m_nSelectedIndex<m_lstMultipleTraces.count()-6 )
			m_nSelectedIndex+=6;
		ui.lblCurrenttoTotal->setText(QString::number(m_nSelectedIndex+1,10)+ " to "+ QString::number(m_lstMultipleTraces.count(),10));
		clearTraces();
		LoadVITraces(m_nSelectedIndex);
	}
	qDebug() << "Next Move:"<<m_nSelectedIndex;
}

void MutlipeWaveDialog::onPrevious()
{
//	qDebug() << "onPrevious Button";
    if(m_nSelectedIndex >0)
    	m_nSelectedIndex-=6;
    else
    	m_nSelectedIndex=0;
//    qDebug() << "Previous Move:"<<m_nSelectedIndex;
    if(isPassFlag == true)
    {
    	ui.lblCurrenttoTotal->setText(QString::number(m_nSelectedIndex+1,10)+ " to "+ QString::number(m_lstPassStrTraces.count(),10));
		clearTraces();
		LoadPassTraces(m_nSelectedIndex);
    }
    else if(isFailFlag == true)
    {
    	ui.lblCurrenttoTotal->setText(QString::number(m_nSelectedIndex+1,10)+ " to "+ QString::number(m_lstFailStrTraces.count(),10));
        clearTraces();
        LoadFailTraces(m_nSelectedIndex);
    }
    else
    {
    	ui.lblCurrenttoTotal->setText(QString::number(m_nSelectedIndex+1,10)+ " to "+ QString::number(m_lstMultipleTraces.count(),10));
        clearTraces();
        LoadVITraces(m_nSelectedIndex);
    }
   // ui.lblCurrenttoTotal->setText(QString::number(m_nSelectedIndex+1,10)+ " to "+ QString::number(m_lstMultipleTraces.count(),10));

}

void MutlipeWaveDialog::closeApp()
{
	//clickedPRSCR();
	this->close();
}


void MutlipeWaveDialog::onAllTraces()
{
	//border: 1px solid #2D5059;
	//border-radius: 20px;
	ui.butFail->setStyleSheet("QPushButton { border-radius: 20px;background-color : rgb(88,88,87,255); color : white; }");
	ui.butPass->setStyleSheet("QPushButton {border-radius: 20px; background-color : rgb(88,88,87,255); color : white; }");
	ui.butALL->setStyleSheet("QPushButton { border-radius: 20px;background-color : rgb(82,127,162,255); color : white; }");
	m_nSelectedIndex=0;
	ui.lblCombinations->setText(QString::number(m_lstMultipleTraces.count(),10));
	if(m_lstMultipleTraces.count() > 6)
		ui.lblCurrenttoTotal->setText("1 to "+ QString::number(m_lstMultipleTraces.count(),10));
	else
		ui.lblCurrenttoTotal->setText(QString::number(m_lstMultipleTraces.count(),10)+ " to "+ QString::number(m_lstMultipleTraces.count(),10));
	clearTraces();
	isPassFlag=isFailFlag=false;
	LoadVITraces(m_nSelectedIndex);
}
void MutlipeWaveDialog::onFailTraces()
{
	ui.butALL->setStyleSheet("QPushButton { border-radius: 20px;background-color : rgb(88,88,87,255); color : white; }");
	ui.butPass->setStyleSheet("QPushButton {border-radius: 20px; background-color : rgb(88,88,87,255); color : white; }");
	ui.butFail->setStyleSheet("QPushButton { border-radius: 20px;background-color : rgb(82,127,162,255); color : white; }");
	m_nSelectedIndex=0;
	ui.lblCombinations->setText(QString::number(m_lstFailStrTraces.count(),10));
	if(m_lstFailStrTraces.count() > 6)
		ui.lblCurrenttoTotal->setText("1 to "+ QString::number(m_lstFailStrTraces.count(),10));
	else
		ui.lblCurrenttoTotal->setText(QString::number(m_lstFailStrTraces.count(),10)+ " to "+ QString::number(m_lstFailStrTraces.count(),10));
	clearTraces();
	isPassFlag = false;
	isFailFlag=true;
	LoadFailTraces(m_nSelectedIndex);
}

void MutlipeWaveDialog::onPassTraces()
{
	m_nSelectedIndex=0;
	ui.butALL->setStyleSheet("QPushButton { border-radius: 20px;background-color : rgb(88,88,87,255); color : white; }");
	ui.butFail->setStyleSheet("QPushButton { border-radius: 20px;background-color : rgb(88,88,87,255); color : white; }");
	ui.butPass->setStyleSheet("QPushButton { border-radius: 20px;background-color : rgb(82,127,162,255); color : white; }");
	ui.lblCombinations->setText(QString::number(m_lstPassStrTraces.count(),10));
	if(m_lstPassStrTraces.count() > 6)
		ui.lblCurrenttoTotal->setText("1 to "+ QString::number(m_lstPassStrTraces.count(),10));
	else
		ui.lblCurrenttoTotal->setText(QString::number(m_lstPassStrTraces.count(),10)+ " to "+ QString::number(m_lstPassStrTraces.count(),10));
	clearTraces();
	isFailFlag = false;
	isPassFlag=true;
	LoadPassTraces(m_nSelectedIndex);
}
