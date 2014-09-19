#include "vimodelview.h"

VIModelView::VIModelView()
{

}

VIModel::VIModel()
{
    qDebug() << "VIModel Class";
    m_objInteractiveDataClass = new DataClass<short int,short int>();
    m_objInteractiveDataClass->setIndex(0,1); // voltage
    m_objInteractiveDataClass->setIndex(1,7); // frequency
    m_objInteractiveDataClass->setIndex(2,7); // impedance

    m_objEmbeddedDataClass = new DataClass<QString,short int>();
    m_objEmbeddedDataClass->setIndex(0,"RUN/STOP"); // Left
    m_objEmbeddedDataClass->setIndex(1,"STORE"); // Middle
    m_objEmbeddedDataClass->setIndex(2,"DELETE"); // Right

    m_objClipDialogClass = new DataClass<short int,short int>(7);
    m_objClipDialogClass->setIndex(0,0); // clip pins selection index
    m_objClipDialogClass->setIndex(1,14); // pin Count
    m_objClipDialogClass->setIndex(2,0); // Fixed / Moving option
    m_objClipDialogClass->setIndex(3,1); // Ref Channel
    m_objClipDialogClass->setIndex(4,13); // No. of Pin Combinations
    m_objClipDialogClass->setIndex(5,0); // Comparison Option
    m_objClipDialogClass->setIndex(6,0); // stop on fail


    m_objProbeDialogClass = new DataClass<short int,short int>(5);
    m_objProbeDialogClass->setIndex(0,0); // Probe Mode
    m_objProbeDialogClass->setIndex(1,0); // Comparison Option
    m_objProbeDialogClass->setIndex(2,0); // AutoCurveFit Mode
    m_objProbeDialogClass->setIndex(3,0); // Common Ground
    m_objProbeDialogClass->setIndex(4,0); // Reference Probe Selection


    m_nAverage1=m_nAverage2=0;
}

short int VIModel::getIndexTemplate(short int pIndex)
{
    return m_objInteractiveDataClass->getIndex(pIndex);
}

void VIModel::setIndexTemplate(short pIndex, short int pValue)
{
    m_objInteractiveDataClass->setIndex(pIndex,pValue);
}

void VIModel::setIndexTemplate(short pIndex, QString pValue)
{
    m_objEmbeddedDataClass->setIndex(pIndex,pValue);
}

void VIModel::setPin2ChannelMap(short int pPinName,short int pPinChannel)
{
	m_mapPin2Channel.insert(pPinName,pPinChannel);
}

void VIModel::setPinCombinations(short int pIndex, QList<short>* pPinsList)
{
	for(int i=0;i<pPinsList->count();i++)
	m_mapPinCombinations.insert(pIndex,pPinsList);
}

QString VIModel::getIndexTemplate(short int pIndex,bool pValue)
{
    Q_UNUSED(pValue);
    return m_objEmbeddedDataClass->getIndex(pIndex);
}

void VIModel::registerObserver(short int pWinID,IVIObserver *pObserver)
{
    m_mapObservers.insert(pWinID,pObserver);
}

short int VIModel::getChipDialog(short int pChipIndex)
{
    return m_objClipDialogClass->getIndex(pChipIndex);
}

void VIModel::setChipDialog(short int pChipIndex, short int pValue)
{
    m_objClipDialogClass->setIndex(pChipIndex,pValue);
}

void VIModel::clearWaveTraces()
{
	m_mapReferenceWaveVector.clear();
}

void VIModel::storeWaveTrace(short int pIndex,QStringList pData)
{
	//m_objVISubject->storeTrace(m_nStoreWaveIndex-1,m_objFunctionalObject->getFileData(ACTUAL_FILENAME));
	m_mapReferenceWaveVector.insert(pIndex,pData);
}

QStringList VIModel::getReferenceWaveData(short int pIndex)
{
	//qDebug() << "WaveIndex:" << pIndex<<m_mapReferenceWaveVector.value(pIndex).count();
	return m_mapReferenceWaveVector.value(pIndex);
}

void VIModel::deleteWaveTrace(short int pIndex)
{
	m_mapReferenceWaveVector.remove(pIndex);
}


void VIModel::setProbeThreshold(double pValue)
{
    m_nThresholdValue = pValue;
}

double VIModel::getProbeThreshold()
{
    return m_nThresholdValue;
}

void VIModel::setProbeDialog(short pIndex, short pValue)
{
    m_objProbeDialogClass->setIndex(pIndex,pValue);
}

short int VIModel::getProbeDialog(short pIndex)
{
	m_objProbeDialogClass->getIndex(pIndex);
}

bool  VIModel::getCalibrationStatus(){
	return m_bCalibStatus;
}
void  VIModel::setCalibrationStatus(bool state){
	m_bCalibStatus = state;
}

bool  VIModel::getLearnStatus(){
	return m_bLearnStatus;
}
void  VIModel::setLearnStatus(bool state){
	m_bLearnStatus = state;
}

bool  VIModel::getVerifyStatus(){
	return m_bVerifyStatus;
}
void  VIModel::setVerifyStatus(bool state){
	m_bVerifyStatus = state;
}

void VIModel::setAutoCurvePattern(short int pIndex,QString pStrName,QStringList pData)
{

	if(m_lstAutoCurveFitPatterns.contains(pStrName) == false)
	{
		m_lstAutoCurveFitPatterns.insert(pIndex,pStrName);
	}
    //QFile *l_objDataFile = new QFile("./AutoCurve"+QString::number(pIndex,16)+".bin");
   /* short int counter=0;
    unsigned int l_nFileData=0;
    FILE *l_nFD;
    l_nFD = fopen("./AutoCurve"+QString::number(pIndex,16).toUtf8()+".bin","w");
    bool ok=true;
    if(1)
    {
		for(int l_nIndex=0;l_nIndex<100;l_nIndex++)
		{
			 l_nFileData = 0x1FFF;
			 fprintf(l_nFD,"%X\n",l_nFileData);
		}
        while(counter < pData.count())
        {
        	unsigned short l_SPIData = pData.value(counter).toUShort(&ok,16);
        	fprintf(l_nFD,"%X\n",l_SPIData);
            counter++;
        }
        for(int l_nIndex=0;l_nIndex<100;l_nIndex++)
		{
			 l_nFileData = 0x1FFF;
			 fprintf(l_nFD,"%X\n",l_nFileData);
			//l_objDataFile->write(QString::number(0x3FFF,16).toUcs4(),4);
			//l_objDataFile->write("\n",1);
		}
    	}
    fclose(l_nFD);*/
    //l_objDataFile->close();
}


double VIModel::getVoltageValue()
{
	//{0.6,0.6,2.0,4.0,8.0,14.0};
	//{0.2,0.5,1.5,3.5,7.0,13.0};
	//double l_nVoltArray[6] = {0.2,0.5,1.5,3.5,7.0,13.0};
	double l_nVoltArray[4] = {0.2,2.5,8.0,13.0};
	return l_nVoltArray[getIndexTemplate(0)];
}

double VIModel::getFrequencyValue()
{
	double l_nFrequenceArray[13] = {10.0,50.0,100.0,200.0,500.0,1000.0,2000.0,5000.0,10000.0,20000.0,50000.0,100000.0};
	return l_nFrequenceArray[getIndexTemplate(1)];
}

unsigned int VIModel::getImpedanceValue()
{
    unsigned int l_nImpedanceArray[16] = {10,20,50,100,200,500,1000,2000,5000,10000,20000,50000,100000,200000,500000,1000000};
	return l_nImpedanceArray[getIndexTemplate(2)];
}

