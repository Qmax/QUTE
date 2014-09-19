#include "autocurvefittraces.h"
#include <qlabel.h>
#include <qclipboard.h>
#include <QPrintDialog>
#include <QPrinter>

AutoCurveFitTraces::AutoCurveFitTraces(VIModel *pObj,VIFunctionalLogic *pobjFun,QWidget *parent)
    : QMainWindow(parent,Qt::WindowSystemMenuHint)
{
	ui.setupUi(this);
	m_obVImodel = pObj;
	m_objFunctionalObject = pobjFun;
	m_lstBestFitPatterns.clear();
	m_nReadData = new short int[100];
	m_lstBestFitPatterns = m_obVImodel->getAutoPatterns();
	connect(ui.objClose,SIGNAL(clicked()),this,SLOT(closeApp()));
//	ui.chkResistance->setChecked(false);
//	ui.chkCapacitance->setChecked(false);
//	ui.chkInductance->setChecked(false);
//	ui.chkDiode->setChecked(false);
	LoadVITraces();
}

void AutoCurveFitTraces::clickedPRSCR()
{
	QPixmap Pix;
    Pix = QPixmap();
    //Pix = QPixmap::grabWidget(ui->FGSubwindow,0,0,800,600);
    Pix = QPixmap::grabWindow(this->winId());
    Pix.save("AutoCurveFit.jpg");
    QClipboard *board = QApplication::clipboard();
    board->setPixmap(Pix);
  //  QWidget::showFullScreen();

	/*QPrinter *printer = new QPrinter();
	            printer->setOutputFormat(QPrinter::PdfFormat);
	            printer->setOutputFileName("./home/sample.pdf");
	            printer->setPaperSize(QPrinter::A4);
	            printer->setFullPage(true);
	            printer->setResolution(100);

	 QPrintDialog *printDialog = new QPrintDialog(printer, this);
	        if (printDialog->exec() == QDialog::Accepted) {
	            QPainter p(printer);
	            p.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing | QPainter::SmoothPixmapTransform, true);
	            QPixmap pm = QPixmap::grabWidget(this);
	            p.drawPixmap(50, 0, pm);
	        }*/
}




AutoCurveFitTraces::~AutoCurveFitTraces()
{

}

void AutoCurveFitTraces::LoadVITraces()
{
    m_objWaveFactory = new WaveFormFactory();
//	typedef short int*  (*RDSPI)(unsigned int,unsigned int);
//	RDSPI ReadSPI = (RDSPI)m_objBPLib->resolve("ReadSPI");

    int l_nXIndex=0,l_nYIndex=0;
    for(int l_nVIIndex=0;l_nVIIndex<6;l_nVIIndex++)
    {
    	VIProduct[l_nVIIndex] = m_objWaveFactory->getWaveProduct("VI",this);
    	VIProduct[l_nVIIndex]->setDimensions(10+l_nXIndex,25+l_nYIndex,150,150);
    	VIProduct[l_nVIIndex]->setTickValue(0);
    	l_nXIndex+=160;
    	if(l_nVIIndex == 2) {l_nYIndex +=170;l_nXIndex=0;}
    }
    //double l_nI=0.0;
    l_nXIndex=l_nYIndex=0;
    short int l_nColor=0;
    if(m_obVImodel->isResistorFound()==true)
    {
    	l_nColor=1;
    	//ui.chkResistance->setChecked(true);
    }
    if(m_obVImodel->isCapacitorFound()==true)
    {
    	l_nColor=3;
    	//ui.chkCapacitance->setChecked(true);
    }
    if(m_obVImodel->isInductorFound()==true)
    {
    	l_nColor=4;
    	//ui.chkInductance->setChecked(true);
    }
    if(m_obVImodel->isDiodeFount()==true)
    {
    	l_nColor=2;
    	//ui.chkDiode->setChecked(true);
    }
    qDebug()<<"Color:"<<l_nColor;
    for(int l_nLstIndex=0;l_nLstIndex<6;l_nLstIndex++)
    {
    	if(l_nLstIndex < m_lstBestFitPatterns.count()){
    	QStringList l_strListValues = m_lstBestFitPatterns.value(l_nLstIndex).split("_");
    	int l_nImpedance = l_strListValues.value(4).remove(".bin").toUInt()/1000.0;
    	QString l_strOhmUnit="KOhm";
    	if(l_nImpedance==0){
    		l_nImpedance = l_strListValues.value(4).remove(".bin").toUInt();
    		l_strOhmUnit="Ohm";
    	}
    	l_nColor = m_obVImodel->getComponent(l_nLstIndex);

    	//qDebug() << "Impedance" << l_nImpedance << l_strListValues[4];
    	//QString l_strLabel = l_strListValues[0]+"_"+l_strListValues[1]+"_"+l_strListValues[2]+"_"+l_strListValues[3]+"_"+QString::number(l_nImpedance)+l_strOhmUnit;
    	QString l_strLabel = l_strListValues[0]+"_"+l_strListValues[1]+"_"+l_strListValues[2]+"_"+l_strListValues[3]+"_"+l_strOhmUnit;
    	QString l_strActualFileName = "AutoCurve"+QString::number(l_nLstIndex,16)+".bin";
    	QString l_strReferenceFileName = m_lstBestFitPatterns.value(l_nLstIndex).remove(".bin");
    	m_objFunctionalObject->ReadCalibrationFunctionFile(l_strReferenceFileName);
    	qDebug() << "Auto Curve Fit FileName:" << l_strActualFileName<<l_strReferenceFileName;
    	bool ok=true;
    	QString l_strVoltageValue= l_strListValues[1].remove("V");
    	qDebug() << "AutoCurveFIt Voltage Value:" <<l_strVoltageValue.toDouble(&ok);
    	QLabel *label = new QLabel(this);
    	label->setGeometry(9+l_nXIndex,9+l_nYIndex,200,12);
    	l_nXIndex+=160;
    	if(l_nLstIndex == 2) {l_nYIndex +=172;l_nXIndex=0;}
    	if(m_lstBestFitPatterns.value(l_nLstIndex).count() >0){
        	label->setText(l_strLabel);
        	stWaveData* l_objVIWaveData = m_objFunctionalObject->showVITrace(0,l_strVoltageValue.toDouble(&ok));
        	l_objVIWaveData->m_bCalibChecked=true;
        	l_objVIWaveData->m_nCalibrationConstant=m_objFunctionalObject->getReceiveCalibrationConstant(m_obVImodel->getIndexTemplate(0));
        	l_objVIWaveData->m_nCalibrationGain=m_objFunctionalObject->getReceiveCalibrationGain(m_obVImodel->getIndexTemplate(0));
    		VIProduct[l_nLstIndex]->LoadVIData("./CalibrationReference.bin",l_strActualFileName,l_nColor,0,l_objVIWaveData);
    	}
    	}
    }
}



void AutoCurveFitTraces::closeApp()
{
    this->close();
}

void AutoCurveFitTraces::on_print_clicked()
{
    clickedPRSCR();
}
