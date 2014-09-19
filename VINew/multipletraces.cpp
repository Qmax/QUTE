#include "multipletraces.h"
#include <qlabel.h>
#include <QPixmap>
#include <qclipboard.h>
#include <qmessagebox.h>
#include <QList>
#include <QPrintDialog>
#include <QPrinter>
#include <QPainter>
#include <QDirIterator>

MultipleTraces::MultipleTraces(QWidget *parent,VIModel *pObjSubject,VIFunctionalLogic *pFunObj)
    : QMainWindow(parent,Qt::WindowSystemMenuHint)
{
	uiMT.setupUi(this);
	setWindowFlags(Qt::Widget);
	//	qDebug()<<"MultipleTraces Constructor";
    m_obVImodel = pObjSubject;
    m_objFunctionLogic = pFunObj;
	m_lstMultipleTraces.clear();
	m_mapCombinations = m_obVImodel->getPinCombinations();

    //m_lstMultipleTraces = m_obVImodel->getPinCombinations()
	//m_lstMultipleTraces.sort();
	connect(uiMT.objClose,SIGNAL(clicked()),this,SLOT(closeAppMT()));
	connect(uiMT.butNext,SIGNAL(clicked()),this,SLOT(onNext()));
	connect(uiMT.butPrev,SIGNAL(clicked()),this,SLOT(onPrevious()));
	connect(uiMT.butPass,SIGNAL(clicked()),this,SLOT(onPassTraces()));
	connect(uiMT.butFail,SIGNAL(clicked()),this,SLOT(onFailTraces()));
	connect(uiMT.butALL,SIGNAL(clicked()),this,SLOT(onAllTraces()));

	m_nSelectedIndex=0;
	//m_nEndIndex=0;
	uiMT.lblCombinations->setText(QString::number(m_obVImodel->getChipDialog(4),10));
	if(m_obVImodel->getChipDialog(4) > 6)
		uiMT.lblCurrenttoTotal->setText("1 to "+ QString::number(m_obVImodel->getChipDialog(4),10));
	else
		uiMT.lblCurrenttoTotal->setText(QString::number(m_obVImodel->getChipDialog(4),10)+ " to "+ QString::number(m_obVImodel->getChipDialog(4),10));

	initializeWaveProduct();
	isPassFlag=isFailFlag=false;
	//calculateCombinationalTraces(m_obVImodel->getClipLearntFlag());
	//LoadVITraces(m_nSelectedIndex);
}

int MultipleTraces::getFailCount()
{
	return m_lstFailStrTraces.count();
}

int MultipleTraces::getPassCount()
{
	return m_lstPassStrTraces.count();
}

void MultipleTraces::LoadLearntTraces()
{
	QString l_strTestFileName="";
	QList<short int> l_lstKeys = m_mapCombinations.keys();
	short int l_nLoopIndex=0;
	for(short int l_nRefIndex=0;l_nRefIndex<l_lstKeys.count();l_nRefIndex++)
		{
			short int l_nReferencePin= l_lstKeys.value(l_nRefIndex);
			//qDebug() << "Reference Pin:"<<l_nReferencePin;
			for(short l_nPinsIndex=0;l_nPinsIndex<m_mapCombinations.value(l_lstKeys.value(l_nRefIndex))->count();l_nPinsIndex++)
			{
				QList<short>* l_lstPindexIndex = m_mapCombinations.value(l_lstKeys.value(l_nRefIndex));
				l_strTestFileName = QString::number(l_nReferencePin,10)+"_"+QString::number(l_lstPindexIndex->value(l_nPinsIndex),10);
				m_lstMultipleTraces.insert(l_nLoopIndex++,l_strTestFileName);
			}
		}
}


void MultipleTraces::calculateCombinationalTraces(bool pFlag)
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
    	uiMT.butPass->setDisabled(false);
    else
    	uiMT.butPass->setDisabled(true);
    if(m_lstFailStrTraces.count() >0)
    	uiMT.butFail->setDisabled(false);
    else
    	uiMT.butFail->setDisabled(true);
    uiMT.butALL->setDisabled(false);
    //isPassFlag=isFailFlag = true;
    qDebug() << "PassTraces Count:" << m_lstPassStrTraces.count();
    qDebug() << "FailTraces Count:" << m_lstFailStrTraces.count();
	uiMT.butFail->setStyleSheet("QPushButton { background-color :rgb(88,88,87,255); color : white; }");
	uiMT.butPass->setStyleSheet("QPushButton { background-color :rgb(88,88,87,255); color : white; }");
	uiMT.butALL->setStyleSheet("QPushButton { background-color: rgb(82, 127, 162); color : white; }");

}

void MultipleTraces::clickedPRSCR()
{
	QPixmap Pix;
    Pix = QPixmap();
    //Pix = QPixmap::grabWidget(uiMT->FGSubwindow,0,0,800,600);
    Pix = QPixmap::grabWindow(this->winId());
    Pix.save("MultipleTraces.jpg");
    QClipboard *board = QApplication::clipboard();
    board->setPixmap(Pix);
    QWidget::showFullScreen();
}


void MultipleTraces::setTestFlag(bool pFlag)
{
	isLearn = pFlag;
	isPassFlag=isFailFlag=false;
    if(isLearn == true)
    {
    	uiMT.butPass->setDisabled(true);
    	uiMT.butFail->setDisabled(true);
    	uiMT.butALL->setDisabled(true);
    }

}

void MultipleTraces::initializeWaveProduct()
{
	   int l_nXIndex=0,l_nYIndex=0;
	   QFont font;
	   font.setFamily("DejaVu Sans");
	   font.setBold(true);
	   font.setPointSize(15);
        m_objWaveFactory = new WaveFormFactory();
	    //uiMT.lbl1->setGeometry(9+l_nXIndex,9+l_nYIndex,200,12);
	    for(int l_nVIIndex=0;l_nVIIndex<6;l_nVIIndex++)
	    {
	    	VIProduct[l_nVIIndex] = m_objWaveFactory->getWaveProduct("VI",this);
	    	VIProduct[l_nVIIndex]->setDimensions(10+l_nXIndex,40+l_nYIndex,150,150);
	    	VIProduct[l_nVIIndex]->setTickValue(0);
	    	label[l_nVIIndex] = new QLabel(this);
	    	label[l_nVIIndex]->setText("");
	    	label[l_nVIIndex]->setGeometry(9+l_nXIndex,24+l_nYIndex,200,12);
	    	label[l_nVIIndex]->setStyleSheet("QLabel { color : white; }");
	    	//label[l_nVIIndex]->setPalette(QColor(QColor(255,255,255,255)));
	    	compareLabel[l_nVIIndex] = new QLabel(this);
	    	compareLabel[l_nVIIndex]->setText("");
	    	compareLabel[l_nVIIndex]->setFont(font);
	    	compareLabel[l_nVIIndex]->setGeometry(80+l_nXIndex,24+l_nYIndex,200,12);

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

void MultipleTraces::LoadFailTraces(short int pStartIndex)
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



void MultipleTraces::LoadPassTraces(short int pStartIndex)
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
void MultipleTraces::LoadVITraces(short int pStartIndex)
{

	//Qt::darkGreen
    short int l_nMoveIndex=pStartIndex;
    int l_nXIndex=0,l_nYIndex=0;
    l_nXIndex=l_nYIndex=0;
    QString l_strLabel="CalibrationReference.bin";
    QString l_strActualFileName;
//    qDebug()<<"StartCount:"<<l_nMoveIndex<<"Total Count:"<<m_lstMultipleTraces.count();
    for(int l_nLstIndex=0;l_nLstIndex<6;l_nLstIndex++)
    {
    	//QString l_strLabel =  "SINE_"+ QString::number(m_obVImodel->getVoltageValue(),'f',1)+"V_"+QString::number(m_obVImodel->getFrequency(),'f',0)+"_HZ_"+QString::number(m_obVImodel->getImpedanceValue())+".bin";
    	if(isPassFlag==true)
    		l_strActualFileName = m_lstPassStrTraces.value(l_nMoveIndex++);
    	else if(isFailFlag == true)
    		l_strActualFileName = m_lstFailStrTraces.value(l_nMoveIndex++);
    	else
   		    l_strActualFileName = m_lstMultipleTraces.value(l_nMoveIndex++);
//   		qDebug()<<"MoveIndex:"<<l_nMoveIndex;
    	if(l_strActualFileName.count() == 0) return;
//    	qDebug() << "Actual FileName" << l_strActualFileName<<"Count:"<<l_strActualFileName.count();
    	l_nXIndex+=160;
    	if(l_nLstIndex == 2) {l_nYIndex +=172;l_nXIndex=0;}
    	if(m_lstMultipleTraces.value(l_nLstIndex).count() >0 ){
    		label[l_nLstIndex]->setText("Pin_"+l_strActualFileName);
//    		qDebug()<<"Label Count:"<<label[l_nLstIndex]->text().count();
            stWaveData* l_objVIWaveData = m_objFunctionLogic->showVITrace(0,m_obVImodel->getIndexTemplate(0));
//            qDebug()<<m_obVImodel->getVoltageValue();
           	l_objVIWaveData->m_bCalibChecked=true;
            l_objVIWaveData->m_nCalibrationConstant=m_objFunctionLogic->getReceiveCalibrationConstant(m_obVImodel->getIndexTemplate(0));
           	l_objVIWaveData->m_nCalibrationGain=m_objFunctionLogic->getReceiveCalibrationGain(m_obVImodel->getIndexTemplate(0));

    		if(isLearn==true)
    		{
    			if(m_obVImodel->getChipDialog(5) == 0 || m_obVImodel->getChipDialog(5) == 1) {
    				VIProduct[l_nLstIndex]->LoadVIData(l_strLabel,"Learnt_"+l_strActualFileName+".bin",0,0,l_objVIWaveData);
    				//VIProduct[l_nLstIndex]->showPixGraph();
    			}
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
    		uiMT.butFail->setEnabled(true);
    		uiMT.butPass->setEnabled(true);
    	}
    }
}


void MultipleTraces::clearTraces()
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



MultipleTraces::~MultipleTraces()
{

}

void MultipleTraces::onNext()
{
	if(isFailFlag== true)
	{
		if(m_nSelectedIndex<m_lstFailStrTraces.count()-6 )
			m_nSelectedIndex+=6;
		uiMT.lblCurrenttoTotal->setText(QString::number(m_nSelectedIndex+1,10)+ " to "+ QString::number(m_lstFailStrTraces.count(),10));
		clearTraces();
		LoadFailTraces(m_nSelectedIndex);
	}
	else if(isPassFlag == true)
	{
		if(m_nSelectedIndex<m_lstPassStrTraces.count()-6 )
			m_nSelectedIndex+=6;
		uiMT.lblCurrenttoTotal->setText(QString::number(m_nSelectedIndex+1,10)+ " to "+ QString::number(m_lstPassStrTraces.count(),10));
		clearTraces();
		LoadPassTraces(m_nSelectedIndex);
	}
	else{
		if(m_nSelectedIndex<m_lstMultipleTraces.count()-6 )
			m_nSelectedIndex+=6;
		uiMT.lblCurrenttoTotal->setText(QString::number(m_nSelectedIndex+1,10)+ " to "+ QString::number(m_lstMultipleTraces.count(),10));
		clearTraces();
		LoadVITraces(m_nSelectedIndex);
	}
}

void MultipleTraces::onPrevious()
{
//	qDebug() << "onPrevious Button";
    if(m_nSelectedIndex >0)
    	m_nSelectedIndex-=6;
    else
    	m_nSelectedIndex=0;
//    qDebug() << "Previous Move:"<<m_nSelectedIndex;
    if(isPassFlag == true)
    {
    	uiMT.lblCurrenttoTotal->setText(QString::number(m_nSelectedIndex+1,10)+ " to "+ QString::number(m_lstPassStrTraces.count(),10));
		clearTraces();
		LoadPassTraces(m_nSelectedIndex);
    }
    else if(isFailFlag == true)
    {
    	uiMT.lblCurrenttoTotal->setText(QString::number(m_nSelectedIndex+1,10)+ " to "+ QString::number(m_lstFailStrTraces.count(),10));
        clearTraces();
        LoadFailTraces(m_nSelectedIndex);
    }
    else
    {
    	uiMT.lblCurrenttoTotal->setText(QString::number(m_nSelectedIndex+1,10)+ " to "+ QString::number(m_lstMultipleTraces.count(),10));
        clearTraces();
        LoadVITraces(m_nSelectedIndex);
    }
   // uiMT.lblCurrenttoTotal->setText(QString::number(m_nSelectedIndex+1,10)+ " to "+ QString::number(m_lstMultipleTraces.count(),10));

}

void MultipleTraces::closeAppMT()
{
	//clickedPRSCR();
//	this->close();
	MultipleTraces::close();


}
//void MultipleTraces::closeEvent (QCloseEvent *event)
//{
//    QMessageBox::StandardButton resBtn = QMessageBox::question( this, "MultipleTrace",
//                                                                tr("Are you sure?\n"),
//                                                                QMessageBox::Cancel | QMessageBox::No | QMessageBox::Yes,
//                                                                QMessageBox::Yes);
//    if (resBtn != QMessageBox::Yes) {
//        event->ignore();
//    } else {
//        event->accept();
//    }
//}


void MultipleTraces::onAllTraces()
{
	//border: 1px solid #2D5059;
	//border-radius: 20px;
	uiMT.butFail->setStyleSheet("QPushButton { border-radius: 20px;background-color : rgb(88,88,87,255); color : white; }");
	uiMT.butPass->setStyleSheet("QPushButton {border-radius: 20px; background-color : rgb(88,88,87,255); color : white; }");
	uiMT.butALL->setStyleSheet("QPushButton { border-radius: 20px;background-color : rgb(82,127,162,255); color : white; }");
	m_nSelectedIndex=0;
	uiMT.lblCombinations->setText(QString::number(m_lstMultipleTraces.count(),10));
	if(m_lstMultipleTraces.count() > 6)
		uiMT.lblCurrenttoTotal->setText("1 to "+ QString::number(m_lstMultipleTraces.count(),10));
	else
		uiMT.lblCurrenttoTotal->setText(QString::number(m_lstMultipleTraces.count(),10)+ " to "+ QString::number(m_lstMultipleTraces.count(),10));
	clearTraces();
	isPassFlag=isFailFlag=false;
	LoadVITraces(m_nSelectedIndex);
}
void MultipleTraces::onFailTraces()
{
	uiMT.butALL->setStyleSheet("QPushButton { border-radius: 20px;background-color : rgb(88,88,87,255); color : white; }");
	uiMT.butPass->setStyleSheet("QPushButton {border-radius: 20px; background-color : rgb(88,88,87,255); color : white; }");
	uiMT.butFail->setStyleSheet("QPushButton { border-radius: 20px;background-color : rgb(82,127,162,255); color : white; }");
	m_nSelectedIndex=0;
	uiMT.lblCombinations->setText(QString::number(m_lstFailStrTraces.count(),10));
	if(m_lstFailStrTraces.count() > 6)
		uiMT.lblCurrenttoTotal->setText("1 to "+ QString::number(m_lstFailStrTraces.count(),10));
	else
		uiMT.lblCurrenttoTotal->setText(QString::number(m_lstFailStrTraces.count(),10)+ " to "+ QString::number(m_lstFailStrTraces.count(),10));
	clearTraces();
	isPassFlag = false;
	isFailFlag=true;
	LoadFailTraces(m_nSelectedIndex);
}

void MultipleTraces::onPassTraces()
{
	m_nSelectedIndex=0;
	uiMT.butALL->setStyleSheet("QPushButton { border-radius: 20px;background-color : rgb(88,88,87,255); color : white; }");
	uiMT.butFail->setStyleSheet("QPushButton { border-radius: 20px;background-color : rgb(88,88,87,255); color : white; }");
	uiMT.butPass->setStyleSheet("QPushButton { border-radius: 20px;background-color : rgb(82,127,162,255); color : white; }");
	uiMT.lblCombinations->setText(QString::number(m_lstPassStrTraces.count(),10));
	if(m_lstPassStrTraces.count() > 6)
		uiMT.lblCurrenttoTotal->setText("1 to "+ QString::number(m_lstPassStrTraces.count(),10));
	else
		uiMT.lblCurrenttoTotal->setText(QString::number(m_lstPassStrTraces.count(),10)+ " to "+ QString::number(m_lstPassStrTraces.count(),10));
	clearTraces();
	isFailFlag = false;
	isPassFlag=true;
	LoadPassTraces(m_nSelectedIndex);
}

void MultipleTraces::on_objSave_clicked()
{
    QPixmap Pix;
    Pix = QPixmap();
    Pix = QPixmap::grabWindow(this->winId());
    Pix.save("MultipleTraces.jpg");

    QPrinter *printer = new QPrinter();
    printer->setOutputFormat(QPrinter::PdfFormat);

    //~~~~~~~~~~~~
    QString directory_path = QDir::currentPath();
    QDirIterator directory_walker(directory_path, QDir::Files | QDir::NoSymLinks, QDirIterator::Subdirectories);
    QString fn,nfn;
    int tfn=0;
    QStringList lst;
    bool ok=true;
    while(directory_walker.hasNext()){
         directory_walker.next();
         fn=directory_walker.fileName();
         if(fn.startsWith("mtraces")==true){
        	 lst= fn.split('s');
        	 lst[1].chop(4);
        	 tfn = lst[1].toInt(&ok,10)+1;
//        	 break;
         }
      }
    	nfn = "mtraces"+QString::number(tfn)+".pdf";
    //~~~~~~~~~~~~
    printer->setOutputFileName(QDir::currentPath()+"/"+nfn);
    printer->setPaperSize(QPrinter::A4);
    printer->setFullPage(true);
    printer->setResolution(100);

    QPrintDialog *printDialog = new QPrintDialog(printer, this);
    if (printDialog->exec() == QDialog::Accepted) {
    QRect rect(0, 0, width(), height());
    QPainter painter(printer);
    painter.drawPixmap(rect,Pix);
    }
}
