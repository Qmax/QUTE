#include "vifunctionallogic.h"
#include <qapplication.h>

VIFunctionalLogic::VIFunctionalLogic()
{
	m_objVIWaveData = new stWaveData();
	m_nReadData = new unsigned short int[200];
}
VIFunctionalLogic::VIFunctionalLogic(const VIFunctionalLogic& pObj)
{
	qDebug()<<"Copy Constructor;";
	m_objVIWaveData = new stWaveData();
	m_objVIWaveData = pObj.m_objVIWaveData;
}

VIFunctionalLogic::~VIFunctionalLogic()
{
	qDebug()<<"Destructor";
	delete m_objVIWaveData;
	delete []m_nReadData,*m_nReadData=0;
}


void VIFunctionalLogic::setVISubject(VIModel *pObjSubject)
{
    m_objVISubject = pObjSubject;
    m_obVIHWInstance.initializeHWLibraries();
    DriveData = new unsigned short int[300];
    for(int i=0;i<4;i++)
    {
    	m_nRangeSlope[i]=1.0;
    	m_nRangeConstant[i]=m_nXVoltage[i]=m_nYVoltage[i]=0.0;
    	m_nVI1ReceiveConst[i]=0.0;
    	m_nVI1ReceiveSlope[i]=1.0;
    }
    if(QFile("ReferenceDriveCalibration.xml").exists())
    {
    	readParallelDACCalibrationFile(0);
    }
    if(QFile("VIADC1.xml").exists())
    {
    	readParallelDACCalibrationFile(1);
    }

}

// ------------------------------ Calibration-----------------------------

bool VIFunctionalLogic::checkSPICodeID()
{
	if( m_obVIHWInstance.checkSPIMemoryCodeID() == true)
		return true;
	else
		return false;
}

void VIFunctionalLogic::ReadCalibrationFunctionFile()
{
	InteractiveData objInteractiveData;
	objInteractiveData.InitialiseMap();
    QString l_strFileName =  "SINE_"+objInteractiveData.getVoltageMap(m_objVISubject->getIndexTemplate(0)) +"_"+
                                         objInteractiveData.getFrequencyMap(m_objVISubject->getIndexTemplate(1)) +"_" +
                                         objInteractiveData.getImpedanceMap(m_objVISubject->getIndexTemplate(2));
    unsigned int l_nMemIndex = m_objVISubject->getCalibMemoryIndex(l_strFileName);
   // qDebug() << "Memory Index:"<<l_nMemIndex;
    m_nReadData= m_obVIHWInstance.ReadSPIData(l_nMemIndex,200);
    storeCalibFile("./CalibrationReference.bin",m_nReadData);
}

void VIFunctionalLogic::ReadCalibrationFunctionFile(QString pStrName)
{
    unsigned int l_nMemIndex = m_objVISubject->getCalibMemoryIndex(pStrName);
    m_nReadData= m_obVIHWInstance.ReadSPIData(l_nMemIndex,200);
    storeCalibFile("./CalibrationReference.bin",m_nReadData);

}

double VIFunctionalLogic::getReceiveCalibrationConstant(short int pVoltIndex)
{
    int index=0;
    double l_nVoltValue = m_objVISubject->getVoltageValue();
//    qDebug()<<"Voltage:"<<l_nVoltValue;
	if(l_nVoltValue>0.5&&l_nVoltValue<=1.5){
		index=1;
	}else if(l_nVoltValue>1.5&&l_nVoltValue<=3.5){
		index=2;
	}else if(l_nVoltValue>3.5&&l_nVoltValue<=7){
		index=3;
	}else if(l_nVoltValue>7&&l_nVoltValue<=13){
		index=4;
	}else if(l_nVoltValue<=0.6){
		index=0;
	}
	return m_nVI1ReceiveConst[index];
}

double VIFunctionalLogic::getReceiveCalibrationGain(short int pVoltIndex)
{
    double l_nVoltValue = m_objVISubject->getVoltageValue();
  //  qDebug()<<"Voltage:"<<l_nVoltValue;
    int index=0;
	if(l_nVoltValue>0.5&&l_nVoltValue<=1.5){
		index=1;
	}else if(l_nVoltValue>1.5&&l_nVoltValue<=3.5){
		index=2;
	}else if(l_nVoltValue>3.5&&l_nVoltValue<=7){
		index=3;
	}else if(l_nVoltValue>7&&l_nVoltValue<=13){
		index=4;
	}else if(l_nVoltValue<=0.6){
		index=0;
	}
	return m_nVI1ReceiveSlope[index];
}

void VIFunctionalLogic::storeCalibFile(QString pStrCalibFile,short unsigned int *pReadData)
{
	   // QFile *l_objDataFile = new QFile(pStrCalibFile);

	    FILE *l_nFD;
	    unsigned int l_nFileData=0;
	    	  //printf("receiveFIFO\n");
	    l_nFD = fopen("./CalibrationReference.bin","w");
	    short int counter=0;
	    short int l_nWaveCounter=0;
	    short int l_nStartTick=100,l_nEndTick=200;

	   // bool ok=true;
	   // if(l_objDataFile->open(QFile::WriteOnly))
	   // {
			for(int l_nIndex=0;l_nIndex<l_nStartTick;l_nIndex++)
			{
				 l_nFileData = 0x1FFF;
				 fprintf(l_nFD,"%X\n",l_nFileData);
				//l_objDataFile->write(QString::number(0x7F,16).toUtf8(),2);
				//l_objDataFile->write("\n",1);
			}
	        while(counter<100)
	        {
	        	short unsigned int l_nMSWData = pReadData[l_nWaveCounter];
	        	l_nWaveCounter++;
	        	short unsigned int l_nLSWData =  pReadData[l_nWaveCounter];
	        	l_nWaveCounter++;
	        	short unsigned int l_SPIData = (0xFFFF&(l_nMSWData)<<8)|(0x00FF&l_nLSWData);
	        	//qDebug()<<hex<< "MSW DATA:"<<l_nMSWData<<"LSW DATA:"<<l_nLSWData;
	        	//qDebug()<<hex<<l_SPIData;
	        	 fprintf(l_nFD,"%X\n",l_SPIData);
	            counter++;
	            l_SPIData=0;
	        }
			for(int l_nIndex=0;l_nIndex<100;l_nIndex++)
			{
				 l_nFileData = 0x1FFF;
				 fprintf(l_nFD,"%X\n",l_nFileData);
				//l_objDataFile->write(QString::number(0x3FFF,16).toUcs4(),4);
				//l_objDataFile->write("\n",1);
			}
	    //}
	    //l_objDataFile->close();
	    fclose(l_nFD);
}

void VIFunctionalLogic::doMemoryCalibration()
{
    // 1. check for connected probe status

    // prompt user if probe is not connect if connected ensure probes are open.
    // check for SPICodeID exists if not flag user Memory problem.
	unsigned short temp_Voltage=m_objVISubject->getIndexTemplate(0);
	unsigned short temp_Frequency=m_objVISubject->getIndexTemplate(1);
	unsigned short temp_Impedance=m_objVISubject->getIndexTemplate(2);

	if(checkSPICodeID() == false)
	{
		qDebug() << "CodeID not done";
		return;
	}

	m_objVISubject->setCalibrationStatus(true);
	DISABLEINT();
    InteractiveData objInteractiveData;
    objInteractiveData.InitialiseMap();
    unsigned int l_nMemoryIndex=0;
    driveVI();
    //for(short int l_nVoltageIndex=0;l_nVoltageIndex<1;l_nVoltageIndex++)
    for(short int l_nVoltageIndex=0;l_nVoltageIndex<4;l_nVoltageIndex++)
    {
        for(short int l_nFrequencyIndex=0;l_nFrequencyIndex<13;l_nFrequencyIndex++)
    	//for(short int l_nFrequencyIndex=0;l_nFrequencyIndex<1;l_nFrequencyIndex++)
        {
            for(short int l_nImpedanceIndex=0;l_nImpedanceIndex<15;l_nImpedanceIndex++)
        //	for(short int l_nImpedanceIndex=0;l_nImpedanceIndex<2;l_nImpedanceIndex++)
            {
                m_objVISubject->setIndexTemplate(0,l_nVoltageIndex);
                m_objVISubject->setIndexTemplate(1,l_nFrequencyIndex);
                m_objVISubject->setIndexTemplate(2,l_nImpedanceIndex);
                switchVIF();
                peformDrive();
               // checkforDriveDoneBit();
                peformReceive("./CalibrationReference.bin");
               // qDebug()<<"Voltage:"<<l_nVoltageIndex<<"Frequency:"<<l_nFrequencyIndex<<"Impedance:"<<l_nImpedanceIndex;
                writeMemory(l_nMemoryIndex);
                m_objVISubject->notifyVIObserver();
                l_nMemoryIndex+=200;
                //qDebug()<< "MemoryIndex:"<<l_nMemoryIndex;
                QApplication::processEvents();
                if(!m_objVISubject->getCalibrationStatus())
                	break;
            }
            QApplication::processEvents();
            if(!m_objVISubject->getCalibrationStatus())
            	break;
        }
        QApplication::processEvents();
        if(!m_objVISubject->getCalibrationStatus())
        	break;
    }
    m_obVIHWInstance.stopDrive();
    ENINT();
    m_objVISubject->setCalibrationStatus(false);

    m_objVISubject->setIndexTemplate(0,temp_Voltage);
    m_objVISubject->setIndexTemplate(1,temp_Frequency);
    m_objVISubject->setIndexTemplate(2,temp_Impedance);
    switchVIF();
}
void VIFunctionalLogic::onCommonGNDRelay(bool pFlag)
{
	m_obVIHWInstance.onGNDRelay(pFlag);
}
void VIFunctionalLogic::stopDrive()
{
	m_obVIHWInstance.stopDrive();
}

QList<short int> VIFunctionalLogic::calculateLCSlope(QStringList pYActualData)
{
	//qDebug() << "------------------------------";
	short int l_nTemp=0;
	QList<short int> l_nTValues;
		bool ok=false;
		for(int l_nActualIndex=0;l_nActualIndex<pYActualData.count();l_nActualIndex++)
		{
			l_nTemp= pYActualData.value(l_nActualIndex).toShort(&ok,16);
			//qDebug() << l_nTemp;
			if(l_nActualIndex>40 && l_nActualIndex<50) // Changed only in Positive WaveArea.
			{
				l_nTValues.append(l_nTemp);
			}

		}
		//qDebug() << "------------------------------";
		return l_nTValues;
}

void VIFunctionalLogic::setTickValue(short int pTick)
{
	m_nTickValue=pTick;
	qDebug()<<"Tick Shift Value:"<<m_nTickValue;
}

QStringList VIFunctionalLogic::getFileData(QString pStrFileName)
{
	short int l_nStartTick=100+m_nTickValue,l_nEndTick=200+m_nTickValue;
	// Previous Value st - 100 ; et- 200
	//qDebug()<<pStrFileName;
	QFile l_objDataFile(pStrFileName);
	    QStringList l_strData;
	    char data[10];
			qint64 l_nLineLength=0;
			QString l_strWaveData;
			l_strData.clear();
			short int counter=0;
			 if(l_objDataFile.open(QFile::ReadOnly))
			        {
			            while(l_nLineLength !=-1)
			            {
			                l_nLineLength = l_objDataFile.readLine(data,10);
			               // if(counter >= 100 && counter < 150){
			                //if(counter <100){
			                if(counter>=0 && counter <l_nStartTick )
			                {
			                	l_strWaveData="";
			                }
			                if(counter>=l_nStartTick && counter<l_nEndTick){
								l_strWaveData.append(data);
								l_strWaveData.remove("\n");
								l_strWaveData.remove("\r");
								if(!l_strWaveData.isEmpty())
									l_strData.append(l_strWaveData);
								//qDebug() << "Data:"<<l_strWaveData;
								//qDebug()<<l_strWaveData;
								l_strWaveData ="";
			                }
			                if(counter>l_nEndTick && counter<300)
							{
								l_strWaveData ="";
							}
			                counter++;
			            }
			        }
			/*if(l_objDataFile.open(QFile::ReadOnly))
			{
				while(l_nLineLength !=-1)
				{
					l_nLineLength = l_objDataFile.readLine(data,10);
					//if(counter>=0 && counter <150 )
					//{
						//l_strWaveData ="";
					//}
	                if(counter>100 && counter<=200){
					if(counter >=150 && counter < 150+100){
						l_strWaveData.append(data);
						l_strWaveData.remove("\n");
						l_strWaveData.remove("\r");
						if(!l_strWaveData.isEmpty())
							l_strData.append(l_strWaveData);
						l_strWaveData ="";
					}
					if(counter>=250 && counter <300  )
					{
						l_strWaveData ="";
					}
					counter++;
				}
			}*/
			l_objDataFile.close();
			//delete data;
			return l_strData;
}
void VIFunctionalLogic::writeMemory(unsigned int pMemIndex)
{
	QStringList l_lstCalibData = getFileData("./CalibrationReference.bin");
    short unsigned int l_nWriteData[200];
    bool ok=true;
    short int l_nWaveIndex=0;
	for (int l_nCalibIndex = 0; l_nCalibIndex < 100; l_nCalibIndex++)
	{
		QString l_strWaveData = l_lstCalibData.value(l_nCalibIndex);
		unsigned short int l_nCalibData = l_strWaveData.toUShort(&ok,16);
		unsigned short int l_nMSW = (0xFF00 &l_nCalibData) >> 8;
		unsigned short int l_nLSW = (0x00FF &l_nCalibData);
        //qDebug()<<"Data:"<<l_strWaveData;
		l_nWriteData[l_nWaveIndex]=  l_nMSW;
		//qDebug()<<"MSW:"<<hex<<l_nWriteData[l_nWaveIndex];
		l_nWaveIndex++;
		l_nWriteData[l_nWaveIndex]=  l_nLSW;
		//qDebug()<<"LSW:"<<hex<<l_nWriteData[l_nWaveIndex];
		l_nWaveIndex++;


	}
	//qDebug() << "Memory Index:"<<pMemIndex;
	m_obVIHWInstance.writeSPIMemory(pMemIndex,200,&l_nWriteData[0]);
	//I->writeSPIMemory(pnMemIndex, 100, &l_nWriteData[0]);
}

void VIFunctionalLogic::setCalibDataMap()
{
	unsigned int l_nMemoryIndex=0;
    InteractiveData objInteractiveData;
    objInteractiveData.InitialiseMap();

    for(short int l_nVoltageIndex=0;l_nVoltageIndex<6;l_nVoltageIndex++)
    {
        for(short int l_nFrequencyIndex=0;l_nFrequencyIndex<13;l_nFrequencyIndex++)
        {
            for(short int l_nImpedanceIndex=0;l_nImpedanceIndex<15;l_nImpedanceIndex++)
            {
                QString l_strFileName =  "SINE_"+objInteractiveData.getVoltageMap(l_nVoltageIndex) +"_"+
                                         objInteractiveData.getFrequencyMap(l_nFrequencyIndex) +"_" +
                                         objInteractiveData.getImpedanceMap(l_nImpedanceIndex);
                m_objVISubject->setCalibData(l_strFileName,l_nMemoryIndex);
                l_nMemoryIndex+=200;
            }
        }
    }

}

unsigned short VIFunctionalLogic::getProbeStatus()
{
    return m_obVIHWInstance.checkProbeStatus();
}



//------------------------------------- Drive Logic for Probe Learn --------------------------------

void VIFunctionalLogic::driveVI()
{
	//m_obVIHWInstance.resetDAC();
    GenerateSINEPattern();
//    qDebug()<< "DFIFO Generated";
    switchVIF();
//    qDebug()<< "VIF Switched";
    loadDriveFIFO();
    ReadCalibrationFunctionFile();
}

void VIFunctionalLogic::peformDriveConfiguration()
{
	m_obVIHWInstance.peformDriveConfiguration();
}

void VIFunctionalLogic::GenerateSINEPattern()
{

    m_nData.clear();

    unsigned int l_nSampleIndex=0;
    unsigned int l_nIndex =0;
    unsigned int l_nSamples=0;
    unsigned int l_nRemainder =0;
    unsigned int l_nTemp=0;
    stWaveData *l_objWaveData = showVITrace(1,m_objVISubject->getIndexTemplate(0));
    m_obVIHWInstance.setDriveCount(l_objWaveData->m_nSamples,l_objWaveData->m_nPostamble+l_objWaveData->m_nPreamble);
    double l_nYPoint =0.0,l_nDegree =l_objWaveData->m_nPhase,l_nXPoint =0.0;

    l_nSamples = l_objWaveData->m_nSamples / l_objWaveData->m_nCycles;
    l_nRemainder = (l_objWaveData->m_nSamples%(int)l_objWaveData->m_nCycles)/l_nSamples;
    l_nTemp = l_nSamples;
    double l_nPhaseAngle=0.0;
    l_nPhaseAngle = (l_nDegree*PI) / 180.0;
    double l_nAmplitude = (l_objWaveData->m_nAmplitude)*l_objWaveData->m_nVRef;
    //qDebug() << "Inside Sine Pattern:" << l_nAmplitude << l_objWaveData->m_nAmplitude;
    double l_nTempYPoint=0.0;
    while(l_nSampleIndex < (l_objWaveData->m_nCycles+l_nRemainder))
    {
        for(;l_nIndex<l_nSamples;l_nIndex++)
        {
            l_nTempYPoint = l_nAmplitude*sin(l_nPhaseAngle);
            l_nYPoint = l_nTempYPoint * l_objWaveData->m_nVRef;
            l_nYPoint = l_nTempYPoint;
            if( l_objWaveData->m_bUniPolar == true)
                l_nYPoint = l_nYPoint + 1.0;
            m_nData.append(QPointF(l_nXPoint,l_nYPoint));
            l_nPhaseAngle = (l_nPhaseAngle +(2*PI) / (l_objWaveData->m_nSamples/l_objWaveData->m_nCycles));
            l_nXPoint += l_objWaveData->m_nTimeperSample;
            if(l_nPhaseAngle > (2*PI))
                l_nPhaseAngle = l_nPhaseAngle - (2*PI);

        }
        l_nSamples += l_nTemp;
        l_nSampleIndex++;
    }
    GenerateHexPattern();
}

 void VIFunctionalLogic::GenerateHexPattern()
 {
    FILE *fpWaveFile;
    fpWaveFile = fopen("./DFIFODrive.txt","w");
    stWaveData *l_objWaveData = showVITrace(1,m_objVISubject->getIndexTemplate(0));

    short l_nHexValue = 0;
        if(fpWaveFile == 0)
            printf("File I/O error\n");
    for(short int l_nPreIndex=0;l_nPreIndex<l_objWaveData->m_nPreamble;l_nPreIndex++)
    {
        l_nHexValue = (l_objWaveData->m_nVRef) * ((pow(2,l_objWaveData->m_nResolution))-1) / (2 * (l_objWaveData->m_nVRef));
        fprintf(fpWaveFile,"%X\n",l_nHexValue);

    }
    for(int l_nIndex=0;l_nIndex<m_nData.count();l_nIndex++)
    {
        QPointF m_nPointValue = m_nData.at(l_nIndex);

        //unsigned short l_nUniPolar =0;
        if( l_objWaveData->m_bUniPolar == true)
        {
            //printf("Y Point %f\n",m_nPointValue.y());
            l_nHexValue = (m_nPointValue.y()) *((pow(2,l_objWaveData->m_nResolution-1)))/(l_objWaveData->m_nAmplitude*2.0);
            l_nHexValue = l_nHexValue + 8192;
        }
        else
        {
            //printf("Y Point %f\n",m_nPointValue.y());
            double l_nRefPoint = 0.0;
            if(l_objWaveData->m_bCalibChecked)
            {
                    //l_nRefPoint =  (m_nPointValue.y() - m_objWaveData->m_nCalibrationConstant) /m_objWaveData->m_nCalibrationGain;
                    l_nRefPoint = m_nPointValue.y();
            }
            else
            {
                    l_nRefPoint = m_nPointValue.y();
            }
            //l_nHexValue = ((l_nRefPoint)+m_objWaveData->m_nVRef) * ((pow(2,m_objWaveData->m_nResolution))-1) / (2 * (m_objWaveData->m_nVRef));
            l_nHexValue = ((l_nRefPoint)+l_objWaveData->m_nVRef) * ((pow(2,l_objWaveData->m_nResolution))-1) / (2 * (l_objWaveData->m_nVRef));

           // printf("VRef %f %d\n",l_nRefPoint,l_nHexValue);
        }
        QString l_strHexValue;

        fprintf(fpWaveFile,"%X\n",l_nHexValue);
        //l_strHexValue.setNum(l_nHexValue & 0x00003FFF,16);
       // std::string hexString = l_strHexValue.toStdString();

        //QString hexQString(l_strHexValue);
        //out << hexQString<<endl;
    }
    /*
     * Edited 21-10-2012 For Double Drive.
     */
    for(int l_nIndex=0;l_nIndex<m_nData.count();l_nIndex++)
    {
                    QPointF m_nPointValue = m_nData.at(l_nIndex);
                    if( l_objWaveData->m_bUniPolar == true)
                    {
                            //printf("Y Point %f\n",m_nPointValue.y());
                            l_nHexValue = (m_nPointValue.y()) *((pow(2,l_objWaveData->m_nResolution-1)))/(l_objWaveData->m_nAmplitude*2.0);
                            l_nHexValue = l_nHexValue + 8192;
                    }
                    else
                    {
                            double l_nRefPoint = 0.0;
                            if(l_objWaveData->m_bCalibChecked)
                            {
                            //	l_nRefPoint =  (m_nPointValue.y() - m_objWaveData->m_nCalibrationConstant) /m_objWaveData->m_nCalibrationGain;
                                    l_nRefPoint = m_nPointValue.y();
                            }
                            else
                            {
                                    l_nRefPoint = m_nPointValue.y();
                            }
                            l_nHexValue = ((l_nRefPoint)+l_objWaveData->m_nVRef) * ((pow(2,l_objWaveData->m_nResolution))-1) / (2 * (l_objWaveData->m_nVRef));
                    }
                    QString l_strHexValue;
                    fprintf(fpWaveFile,"%X\n",l_nHexValue);
    }
        for(short int l_nPostIndex=0;l_nPostIndex<l_objWaveData->m_nPostamble;l_nPostIndex++)
        {
            l_nHexValue = (l_objWaveData->m_nVRef) * ((pow(2,l_objWaveData->m_nResolution))-1) / (2 * (l_objWaveData->m_nVRef));
            fprintf(fpWaveFile,"%X\n",l_nHexValue);
        }
    fclose(fpWaveFile);
   // qDebug()<<"Read HEx FIle";
    readHEXFile();
}

void VIFunctionalLogic::readHEXFile()
{
	QFile *l_objDataFile = new QFile("./DFIFODrive.txt");
	char *data = new char[10];
	qint64 l_nLineLength=0;
	short int l_nWaveIndex=0;
	QString l_strWaveData;
	bool ok=true;
	if(l_objDataFile->open(QFile::ReadOnly))
	{
		while(l_nLineLength !=-1)
		{
			l_nLineLength = l_objDataFile->readLine(data,10);
			l_strWaveData.append(data);
			l_strWaveData.remove("\n");
			l_strWaveData.remove("\r");
			//qDebug() << "Data:"<<l_strWaveData;
			DriveData[l_nWaveIndex] = l_strWaveData.toUShort(&ok,16)&0x3FFF;
			//qDebug()<<"StrData:"<<l_strWaveData << "int Data:"<<DriveData[l_nWaveIndex];
			l_nWaveIndex++;
			l_strWaveData="";
		}
	}
	l_objDataFile->close();
	//qDebug() << "Hex File Read end";
}

void VIFunctionalLogic::loadDriveFIFO()
{
    //m_obVIHWInstance.driveRAM(DriveData);
	m_obVIHWInstance.driveDDS();
}

void VIFunctionalLogic::peformDrive()
{
    m_obVIHWInstance.performDrive();
//    qDebug() << "Drive Perfomed";
}

void VIFunctionalLogic::checkforDriveDoneBit()
{
	m_obVIHWInstance.checkforDriveDoneBit();
//	usleep(100000);
}

void VIFunctionalLogic::setPSOCBaudRate(unsigned int pOption)
{
	m_obVIHWInstance.changePSOCBaudRate(pOption);
}

void VIFunctionalLogic::peformReceive(QString pStrFileName)
{
    m_obVIHWInstance.performReceive();
    QString l_strOldName = "./RWaveData.txt";
    QFile *l_objFile = new QFile();
    if (l_objFile->exists(pStrFileName))
            l_objFile->remove(pStrFileName);
    l_objFile->rename(l_strOldName, pStrFileName);
    l_objFile->close();
    //qDebug() << "Receive Perfomed";
}

void VIFunctionalLogic::renameFile(QString pStrFilename)
{
    QString l_strOldName = "./ActualData.bin";
    QFile *l_objFile = new QFile();
    if (l_objFile->exists(pStrFilename))
            l_objFile->remove(pStrFilename);
    l_objFile->rename(l_strOldName, pStrFilename);
    l_objFile->close();

}

void VIFunctionalLogic::readParallelDACCalibrationFile(short int pIndex)
{

	QString l_strFilename;
	if(pIndex == 0)
		l_strFilename="ReferenceDriveCalibration.xml";
	else if(pIndex == 1)
		l_strFilename="VIADC1.xml";

	    QFile *xmlFile= new QFile(l_strFilename);
	            if (!xmlFile->open(QIODevice::ReadOnly | QIODevice::Text)) {
	                 qDebug()<<"calibration file read error";
	            }

	            QXmlStreamReader xml(xmlFile);
	            short int index=0;
	            while(!xml.atEnd() &&  !xml.hasError())
	            {
	                QXmlStreamReader::TokenType token = xml.readNext();
	                QString l_strName = xml.name().toString();
	                QXmlStreamAttributes attributes = xml.attributes();
	                QString l_strValue = attributes.value("Value").toString();
	                if(token == QXmlStreamReader::StartDocument)
	                {
	                    continue;
	                }
	                if(xml.isStartElement())
	                {
	                                   if(xml.name() == "VoltageRange") {
	                                	   if(pIndex==0)
	                                	   {
	                                            m_nRangeSlope[index]=xml.attributes().value("Slope").toString().toDouble();
	                                            m_nRangeConstant[index]=xml.attributes().value("Constant").toString().toDouble();
	                                	   	}
	                                	   else if(pIndex==1)
	                                	   {
	                                            m_nVI1ReceiveSlope[index]=xml.attributes().value("Slope").toString().toDouble();
	                                            m_nVI1ReceiveConst[index]=xml.attributes().value("Constant").toString().toDouble();
	                                	   }

	                                            index++;
	                                        }
	                }
	            }
	    if(xml.hasError())
	            qDebug()<<"xmlFile.xml Parse Error";

	    //close reader and flush file
	    xml.clear();
	    xmlFile->close();

	    for(int i=0;i<index;i++)
	    {
	    	if(pIndex==0)
	    	{
				qDebug()<<"Gain :"<<m_nRangeSlope[i];
				qDebug()<<"Constant"<<m_nRangeConstant[i];
	    	}
	    	else if(pIndex==1)
	    	{
				qDebug()<<"Receive Slope:"<<m_nVI1ReceiveSlope[i];
				qDebug()<<"Receive Constant"<<m_nVI1ReceiveConst[i];
	    	}
	    }
}


void VIFunctionalLogic::switchVIF()
{
    switchFrequency();
	switchDDSFrequency();
    switchImpedance();
    switchVoltage();
}
void VIFunctionalLogic::switchDDSFrequency()
{
	m_obVIHWInstance.calculateDDSFrequency(m_objVISubject->getIndexTemplate(1));
}

void VIFunctionalLogic::switchFrequency()
{
    m_obVIHWInstance.switchFrequencyRegister(m_objVISubject->getIndexTemplate(1));
}

void VIFunctionalLogic::switchImpedance()
{
    m_obVIHWInstance.switchImpedanceRegister(m_objVISubject->getIndexTemplate(2));
}

void VIFunctionalLogic::switchVoltage()
{
//   if(m_objVISubject->getIndexTemplate(0) == 0 || m_objVISubject->getIndexTemplate(0) ==1)
//   {
//	   m_obVIHWInstance.setVoltageConstant(m_nRangeConstant[0]);
//	   m_obVIHWInstance.setVoltageGain(m_nRangeSlope[0]);
//   }
//   else
//   {
//	   m_obVIHWInstance.setVoltageConstant(m_nRangeConstant[m_objVISubject->getIndexTemplate(0)-1]);
//	   m_obVIHWInstance.setVoltageGain(m_nRangeSlope[m_objVISubject->getIndexTemplate(0)-1]);
//   }
    int index=0;
    double l_nVoltValue = m_objVISubject->getVoltageValue();
//    qDebug()<<"Voltage:"<<l_nVoltValue;
	if(l_nVoltValue>0.5&&l_nVoltValue<=1.5){
		index=1;
	}else if(l_nVoltValue>1.5&&l_nVoltValue<=3.5){
		index=2;
	}else if(l_nVoltValue>3.5&&l_nVoltValue<=7){
		index=3;
	}else if(l_nVoltValue>7&&l_nVoltValue<=13){
		index=4;
	}else if(l_nVoltValue<=0.6){
		index=0;
	}
//	qDebug()<<"Selected Calib Index:"<<index;
	   m_obVIHWInstance.setVoltageConstant(m_nRangeConstant[index]);
	   m_obVIHWInstance.setVoltageGain(m_nRangeSlope[index]);

   m_obVIHWInstance.switchVoltageRegister(m_objVISubject->getIndexTemplate(0));
}


void VIFunctionalLogic::generateFixedReference()
{
	//unsigned short nPins, unsigned short nSelectedIndex, int pIndex
    QList<short> *l_lstPins = new QList<short>();

	unsigned short l_nPins = m_objVISubject->getChipDialog(1);
	unsigned short l_nRefChannel = m_objVISubject->getChipDialog(3);

    //char buffer[5];
    //QString l_strPin;
    //sprintf(buffer,"%d",l_nRefChannel);
    //QString l_strSelectedPin = "Pin_";
    //l_strSelectedPin.append(buffer);
    for(int l_nPinIndex=1;l_nPinIndex <=l_nPins;l_nPinIndex++)
    {
        if( l_nPinIndex == l_nRefChannel )
            continue;
        //sprintf(buffer,"%d",l_nPinIndex);
        //l_strPin = l_strSelectedPin +"_";
        //l_strPin.append(buffer);
        //l_strPin.append(buffer);
        l_lstPins->insert(l_nPinIndex,l_nPinIndex);
        qDebug()<< l_nPinIndex;
    }
    qDebug()<<"~~~~~~~~~~~~~l_nRefChannel,l_lstPins"<<l_nRefChannel<<","<<l_lstPins;
    m_objVISubject->setPinCombinations(l_nRefChannel,l_lstPins);
    qDebug() <<"Fixed Reference";
}

void VIFunctionalLogic::readChannels()
{
	m_obVIHWInstance.readTestandRefChannel();
}
bool VIFunctionalLogic::checkMuxStatus()
{
	return m_obVIHWInstance.readMUXStatus();
}

unsigned int VIFunctionalLogic::switchTestChannel(short int pTestPinChannel)
{
	return m_obVIHWInstance.switchTestMuxChannel(pTestPinChannel);
}

unsigned int VIFunctionalLogic::switchRefChannel(short int pRefPinChannel)
{
	return m_obVIHWInstance.switchRefMuxChannel(pRefPinChannel);
}


void VIFunctionalLogic::externalMuxMeasurement(short int pTestChannel,short int pRefChannel)
{
	m_obVIHWInstance.switchExternalMux(pTestChannel,pRefChannel);
}

void VIFunctionalLogic::generateChannels()
{
	m_objVISubject->clearClipPrgMap();
	unsigned short l_nPins = m_objVISubject->getChipDialog(1);
	 int l_nLeftPinChannel=0,l_nRightPinChannel=l_nPins-1;
	 //VIData->m_objInteractiveData->m_mapPin2Channel.clear();
	 for(short int l_nPinIndex=0;l_nPinIndex < l_nPins;l_nPinIndex++)
	 {
		 if(l_nPinIndex < (l_nPins /2) )
		 {
			 qDebug() << "Left Clip Channel Assignment" << l_nPinIndex+1 <<l_nLeftPinChannel;
			 m_objVISubject->setPin2ChannelMap(l_nPinIndex+1,l_nLeftPinChannel);
			 l_nLeftPinChannel+=2;

		 }
		 else
		 {
			 qDebug() << "Right Clip Channel Assignment" << l_nPinIndex+1 <<l_nRightPinChannel;
			 m_objVISubject->setPin2ChannelMap(l_nPinIndex+1,l_nRightPinChannel);
			 l_nRightPinChannel-=2;
		 }
	 }
}

void VIFunctionalLogic::generateMovingReference()
{
	unsigned short l_nPins = m_objVISubject->getChipDialog(1);
    short int l_nCombinations=0;
    for(int l_nPinIndex=1;l_nPinIndex <=l_nPins;l_nPinIndex++)
    {
    	QList<short> *l_lstPins = new QList<short>();
        for(int l_nSubPinIndex=l_nPins;l_nSubPinIndex>=l_nPinIndex;l_nSubPinIndex--)
        {
            if( l_nPinIndex == l_nSubPinIndex) continue;

			l_lstPins->insert(l_nSubPinIndex,l_nSubPinIndex);
            l_nCombinations++;
            //qDebug()<<"Moving Reference Combination"<< l_strPin;
        }
        m_objVISubject->setPinCombinations(l_nPinIndex,l_lstPins);
        //VIData->m_objInteractiveData->m_mapPinCombinations.insert(l_nPinIndex,l_lstPins);
    }
    qDebug() << "No. of Combinations:"<<l_nCombinations;
}

/*unsigned int VIFunctionalLogic::caluculateClipErrorPercentance(QStringList pReferenceData, QStringList pActualData, unsigned int pA1, unsigned pA2)
{
    return 1;
}*/

void VIFunctionalLogic::switchPROBES(PROBESELECTION pPrbMode)
{
	m_obVIHWInstance.switchPROBE(pPrbMode);
}





stWaveData* VIFunctionalLogic::showVITrace(int pWaveTrace,short int pVoltIndex)
{
//stWaveData *objVIWaveData = new stWaveData;
double l_nVoltArray[6]= {0.2,2.5,8.0,13.0};

if(pWaveTrace == 1)
    {
    // VT
	m_objVIWaveData->m_nAmplitude = 0.6; // Screen Amplitude / 2 // Max Current
	m_objVIWaveData->m_nFrequency = 1.0;
	m_objVIWaveData->m_nSteps= 0;
	m_objVIWaveData->m_nSamples = 100;
	m_objVIWaveData->m_nScreenAmplitude =  1.0;  // Total Current
	m_objVIWaveData->m_nTimeperSample = 0.01;
	m_objVIWaveData->m_nScreenTime = 1.0; // Max Voltage
	m_objVIWaveData->m_nXunits = 10.0;
	m_objVIWaveData->m_nYunits = 8.0;
	m_objVIWaveData->m_nMinX =0.0; // Min Voltage
	m_objVIWaveData->m_nMinY =-1.0; // Min Current
	m_objVIWaveData->m_nPhase =0.0;
	m_objVIWaveData->m_nOffset =0.0;
	m_objVIWaveData->m_nDutyCycles =0;
    m_objVIWaveData->m_nCycles = 1.0;
    m_objVIWaveData->m_nPreamble =50;
    m_objVIWaveData->m_nPostamble=50;
    m_objVIWaveData->m_bUniPolar = false;
    m_objVIWaveData->m_nSteps =0.0;
    m_objVIWaveData->m_nVRef =0.6;
    m_objVIWaveData->m_bCalibChecked = false;
    m_objVIWaveData->m_nCalibrationConstant =0.0;
    m_objVIWaveData->m_nCalibrationGain=0.0;
    m_objVIWaveData->m_nResolution =14;
    m_objVIWaveData->m_nEnvelopBand=0.0;

    // ---- segemented-----------for voltage
    if(pVoltIndex==0) // 0.2V
    {
    	m_objVIWaveData->m_nAmplitude = 0.18; // Screen Amplitude / 2 // Max Current
    	m_objVIWaveData->m_nScreenAmplitude = 0.18;
    	m_objVIWaveData->m_nMinY = -0.18;
    }
    else if(pVoltIndex == 1) // 2.5V
    {
//    	m_objVIWaveData->m_nAmplitude = 0.24; // Screen Amplitude / 2 // Max Current
//    	m_objVIWaveData->m_nScreenAmplitude = 0.24;
//    	m_objVIWaveData->m_nMinY = -(0.24);
		m_objVIWaveData->m_nAmplitude = 0.31; // Screen Amplitude / 2 // Max Current
		m_objVIWaveData->m_nScreenAmplitude = 0.31;
		m_objVIWaveData->m_nMinY = -(0.31);

    }
    else if(pVoltIndex ==2 ) // 8.0V
    {
    	m_objVIWaveData->m_nAmplitude = 0.26; // Screen Amplitude / 2 // Max Current
    	m_objVIWaveData->m_nScreenAmplitude = 0.26;
    	m_objVIWaveData->m_nMinY = -(0.27);
    }
    else if(pVoltIndex ==3 ) // 13.0V
    {
    	m_objVIWaveData->m_nAmplitude = 0.41; // Screen Amplitude / 2 // Max Current
    	m_objVIWaveData->m_nScreenAmplitude = 0.41;
    	m_objVIWaveData->m_nMinY = -(0.41);
    }
}
else if(pWaveTrace ==0)
{
    //VI
	m_objVIWaveData->m_nAmplitude = 0.6; // Screen Amplitude / 2 // Max Current
	m_objVIWaveData->m_nFrequency = 1.0;
	m_objVIWaveData->m_nSteps= 0;
	m_objVIWaveData->m_nSamples = 100;
	m_objVIWaveData->m_nScreenAmplitude =  1.0;  // Total Current
	m_objVIWaveData->m_nTimeperSample = 0.01;
	m_objVIWaveData->m_nScreenTime = 1.0; // Max Voltage
	m_objVIWaveData->m_nXunits = 10.0;
	m_objVIWaveData->m_nYunits = 8.0;
	m_objVIWaveData->m_nMinX =-1.0; // Min Voltage
	m_objVIWaveData->m_nMinY =-1.0; // Min Current
	m_objVIWaveData->m_nPhase =0.0;
	m_objVIWaveData->m_nOffset =0.0;
	m_objVIWaveData->m_nDutyCycles =0;
	m_objVIWaveData->m_nCycles = 1.0;
	m_objVIWaveData->m_nPreamble =50;
	m_objVIWaveData->m_nPostamble=50;
	m_objVIWaveData->m_bUniPolar = false;
	m_objVIWaveData->m_nSteps =0.0;
	m_objVIWaveData->m_nVRef =0.6;
	m_objVIWaveData->m_bCalibChecked = false;
	m_objVIWaveData->m_nCalibrationConstant =0.0;
	m_objVIWaveData->m_nCalibrationGain=0.0;
    m_objVIWaveData->m_nResolution =14;
    m_objVIWaveData->m_nEnvelopBand=0.0;
	if(pVoltIndex == 0) // 0.2 V
	{
		m_objVIWaveData->m_nAmplitude = 0.18;
		m_objVIWaveData->m_nScreenAmplitude = 0.18;
		m_objVIWaveData->m_nScreenTime = 0.22;
		m_objVIWaveData->m_nMinY = -0.18;
		m_objVIWaveData->m_nMinX = -0.22;

	}
	else if (pVoltIndex ==1 ) // 2.5V
	{
		m_objVIWaveData->m_nAmplitude = 0.31;
		m_objVIWaveData->m_nScreenAmplitude =  0.31;
		m_objVIWaveData->m_nScreenTime =  0.31;
		m_objVIWaveData->m_nMinY = -0.32;
		m_objVIWaveData->m_nMinX = -0.32;
	}
	else if (pVoltIndex ==2 ) // 8.0V
	{
		m_objVIWaveData->m_nAmplitude = 0.26;
		m_objVIWaveData->m_nScreenAmplitude =  0.26;
		m_objVIWaveData->m_nScreenTime =  0.26;
		m_objVIWaveData->m_nMinY = -0.27;
		m_objVIWaveData->m_nMinX = -0.27;
	}
	else if (pVoltIndex ==3 ) // 13.0V
	{
		m_objVIWaveData->m_nAmplitude = 0.43;
		m_objVIWaveData->m_nScreenAmplitude =  0.43;
		m_objVIWaveData->m_nScreenTime =  0.43;
		m_objVIWaveData->m_nMinY = -0.43;
		m_objVIWaveData->m_nMinX = -0.43;
	}

}
else if(pWaveTrace ==2)
{
}
    return m_objVIWaveData;
}

// --------------------- Probe Comparison----------------------------------------
void VIFunctionalLogic::calculateAverage(QString pStrFileName)
{
	QStringList l_lstCalibData = getFileData(pStrFileName);
	short int l_nTemp = 0;
	bool ok = false;
	unsigned int l_nAvg1=0,l_nAvg2=0;
	for (int l_nActualIndex = 0; l_nActualIndex < l_lstCalibData.count(); l_nActualIndex++) {
		if (l_nActualIndex < 50) {

			l_nTemp = l_lstCalibData.value(l_nActualIndex).toShort(&ok, 16);
			//qDebug()<<"b4 Value:" << l_nTemp;
			if (l_nTemp > MID_RANGE)
				l_nTemp = l_nTemp - MID_RANGE;
			else
				l_nTemp = MID_RANGE - l_nTemp;
			//qDebug()<<"after Value:" << l_nTemp;
			l_nAvg1 += l_nTemp;

		}
		else if (l_nActualIndex >= 50)
		{
			l_nTemp = l_lstCalibData.value(l_nActualIndex).toShort(&ok, 16);
			if (l_nTemp > MID_RANGE)
				l_nTemp = l_nTemp - MID_RANGE;
			else
				l_nTemp = MID_RANGE - l_nTemp;
			l_nAvg2 += l_nTemp;
		}

	}
	//qDebug() << "AVerage1:"<<l_nAvg1;
	//qDebug() << "AVerage2:"<<l_nAvg2;
	m_objVISubject->setAverages(l_nAvg1,l_nAvg2);
}

void VIFunctionalLogic::ENINT()
{
	m_obVIHWInstance.enableInterrupt();
}

void VIFunctionalLogic::DISABLEINT()
{
	m_obVIHWInstance.disableInterrupt();
}

void VIFunctionalLogic::CLEARINT()
{
	m_obVIHWInstance.clearInterrupt();
}

unsigned int VIFunctionalLogic::readAppcardIntValue()
{
	return m_obVIHWInstance.readAPPCardInterruptValue();
}

void VIFunctionalLogic::writePSOC(unsigned int pValue)
{
	m_obVIHWInstance.writePSOC(pValue);
}
void VIFunctionalLogic::resetPSOC(){//added by ravivarman 31st july
	m_obVIHWInstance.resetPSOC();
}
unsigned int VIFunctionalLogic::readPSOC()
{
	return m_obVIHWInstance.readPSOC();
}

unsigned int VIFunctionalLogic::readEmbeddedKeyValue()
{
	return m_obVIHWInstance.readEmbKeyValue();
}

bool VIFunctionalLogic::isMuxDetected()
{
	return m_obVIHWInstance.checkMUXDetection();
}

int VIFunctionalLogic::caluculateErrorPercentange(QStringList pReferenceData,QStringList pActualData)
{
	QStringList l_lstRef = pReferenceData;
	QStringList l_lstAct = pActualData;
	//qDebug() << "Ref Count:" << pReferenceData.count()<<"Act Count:"<<pActualData.count();
	if(l_lstRef.count() == 0)
		return -1;
	int l_nRefHalfCurveAvg2=0,l_nRefHalfCurveAvg4=0;
	int l_nActHalfCurveAvg1=0,l_nActHalfCurveAvg3=0;
	short int l_nTemp=0;
	bool ok=false;
	for(int l_nActualIndex=0;l_nActualIndex<l_lstAct.count();l_nActualIndex++)
	{
		if(l_nActualIndex < 50){


			l_nTemp= l_lstAct.value(l_nActualIndex).toShort(&ok,16);
			//qDebug()<<"b4 Value:" << l_nTemp;
			if(l_nTemp>MID_RANGE)
				l_nTemp = l_nTemp - MID_RANGE;
			else
				l_nTemp = MID_RANGE-l_nTemp;
			//qDebug()<<"after Value:" << l_nTemp;
			l_nActHalfCurveAvg1 += l_nTemp;
		}
		else if(l_nActualIndex >=50)
		{
			l_nTemp=l_lstAct.value(l_nActualIndex).toShort(&ok,16);
			if(l_nTemp>MID_RANGE)
				l_nTemp = l_nTemp - MID_RANGE;
			else
				l_nTemp = MID_RANGE-l_nTemp;
			l_nActHalfCurveAvg3 += l_nTemp;
		}
	}
	//qDebug() <<"Acutal Value:"<< l_nActHalfCurve1 << l_nActHalfCurve2;
	//int l_nAcutualValue = l_nActHalfCurve1 + l_nActHalfCurve2;

	//qDebug() << "Actual Value:" << l_nAcutualValue;
	for(int l_nRefIndex=0;l_nRefIndex<l_lstRef.count();l_nRefIndex++)
	{
		if(l_nRefIndex < 50){
			l_nTemp=l_lstRef.value(l_nRefIndex).toShort(&ok,16);
			if(l_nTemp>MID_RANGE)
				l_nTemp = l_nTemp - MID_RANGE;
			else
				l_nTemp = MID_RANGE-l_nTemp;
			l_nRefHalfCurveAvg2 += l_nTemp;
		}
		else if(l_nRefIndex >=50)
		{
			l_nTemp=l_lstRef.value(l_nRefIndex).toShort(&ok,16);
			if(l_nTemp>MID_RANGE)
				l_nTemp = l_nTemp - MID_RANGE;
			else
				l_nTemp = MID_RANGE-l_nTemp;
			l_nRefHalfCurveAvg4 += l_nTemp;
		}
	}
	//qDebug() <<"Reference Value:"<< l_nRefHalfCurve1 << l_nRefHalfCurve2;

	unsigned int l_nAVG1=0,l_nAVG2=0;
	if(l_nRefHalfCurveAvg4 > l_nActHalfCurveAvg3)
		l_nAVG2 = l_nRefHalfCurveAvg4 - l_nActHalfCurveAvg3;
	else
		l_nAVG2 = l_nActHalfCurveAvg3 - l_nRefHalfCurveAvg4;

	if(l_nRefHalfCurveAvg2 > l_nActHalfCurveAvg1 )
		l_nAVG1 = l_nRefHalfCurveAvg2 - l_nActHalfCurveAvg1;
	else
		l_nAVG1 = l_nActHalfCurveAvg1 - l_nRefHalfCurveAvg2;

	unsigned int l_nAVERAGE1=0;
//	qDebug() << "AVerage1:"<<m_objVISubject->getAverage1();
//	qDebug() << "AVerage2:"<<m_objVISubject->getAverage2();

	//qDebug() << "average1:" << l_nAVG1;
	//qDebug() << "average2:" << l_nAVG2;
//	unsigned int l_nDivide1=0,l_nDivide2=0;
//	if(l_nRefHalfCurve1> l_nActHalfCurve1)
//		l_nDivide1 = l_nRefHalfCurve1;
//	else
//		l_nDivide1 = l_nActHalfCurve1;
//	if(l_nRefHalfCurve2> l_nActHalfCurve2)
//		l_nDivide2 = l_nRefHalfCurve2;
//	else
//		l_nDivide2 = l_nActHalfCurve2;

	l_nAVG1 = (l_nAVG1*100);
	l_nAVG1 = l_nAVG1 / m_objVISubject->getAverage1();
	l_nAVG2 = (l_nAVG2*100);
	l_nAVG2 = l_nAVG2 / m_objVISubject->getAverage2();

	//qDebug() << "average with 1:" << l_nAVG1;
	//qDebug() << "average with 2:" << l_nAVG2;

	if(l_nAVG1 > l_nAVG2)
		l_nAVERAGE1 = ((l_nAVG1));
	else
		l_nAVERAGE1 = ((l_nAVG2));
	if( l_nAVERAGE1 >100)
		l_nAVERAGE1 =100;
	//qDebug() << "Reference Value:" << l_nAVERAGE1;
	return l_nAVERAGE1;
}
//-------------------------------------------------------------------------------


//---------------------- Autocurve Fit Functionalties----------------------

void VIFunctionalLogic::setFileBit(bool pValue)
{
	m_bRefFile = pValue;
}

void VIFunctionalLogic::converttoVoltage(QStringList pActualData,double l_nGainFactor,CALIB *pObj)
{
	//Q_UNUSED(pObj);
	Q_UNUSED(l_nGainFactor);
	double l_nADCReceVoltage=0.0,l_nVRef=0.5;
	short int l_nTemp=0;
	bool ok= true;
	//double l_nGainValue = l_nGainFactor / l_nVRef;
	//qDebug() << "Calibratin Gain:" <<pObj->m_nGain <<"Calibration Constant:"<<pObj->m_nConstant<<"GainFactor:"<<l_nGainValue;
	bool isDegree=false;
	for(int l_nActualIndex=0;l_nActualIndex<pActualData.count();l_nActualIndex++)
	{
		l_nTemp= pActualData.value(l_nActualIndex).toShort(&ok,16);
		l_nADCReceVoltage = (2*l_nTemp*l_nVRef) / 16383;
		l_nADCReceVoltage = (l_nADCReceVoltage - l_nVRef);
		if(isDegree==false)
			if(l_nADCReceVoltage<0.025 && l_nADCReceVoltage >-0.025)
			{
				if(m_bRefFile == true)
					m_objVISubject->setActualZeroDegree(l_nADCReceVoltage);//((360*l_nActualIndex)/100);
				else if(m_bRefFile == false)
					m_objVISubject->setCalibZeroDegree(l_nADCReceVoltage);//((360*l_nActualIndex)/100);
				 //qDebug()<<"Zero Value:"<<l_nADCReceVoltage<<"Tick Value:"<<l_nActualIndex<<"Tick Degree:"<<(360*l_nActualIndex)/100;
				 isDegree=true;
			}
		//qDebug()<< "ADC Receive Voltage before Calibration:" << l_nADCReceVoltage;
		l_nADCReceVoltage = ((l_nADCReceVoltage - pObj->m_nConstant) / pObj->m_nGain);
		m_objVISubject->inserADCReceVoltage(l_nActualIndex,l_nADCReceVoltage);
	}
	short int l_nPeakIndex=0;
	double l_nPeakValue=0.0;
	//double l_nLeastValue=0.0;
	for(short int l_nlstIndex=0;l_nlstIndex<50;l_nlstIndex++)
	{
		if(l_nPeakValue < m_objVISubject->getADCReceVoltage(l_nlstIndex))
		{
			l_nPeakValue = m_objVISubject->getADCReceVoltage(l_nlstIndex);
			l_nPeakIndex = l_nlstIndex;
		}
		//qDebug() <<"Pos Peak:" << VIData->m_objInteractiveData->m_nADCReceVoltage.value(l_nlstIndex);
	}
	//qDebug()<<"Positive Peak Value:" << l_nPeakValue<< pActualData.value(l_nPeakIndex).toShort(&ok,16);
	m_objVISubject->setPosPeakValue(pActualData.value(l_nPeakIndex).toShort(&ok,16));
	m_objVISubject->setPosPeak(l_nPeakValue);
	m_objVISubject->setPosPeakIndex(l_nPeakIndex);
	//qDebug()<<"Positive Peak Index:" <<l_nPeakIndex;
	l_nPeakValue=0.0;
	short int l_nNegPeakIndex=0;
	for(short int l_nlstIndex=50;l_nlstIndex<100;l_nlstIndex++)
	{
		if(l_nPeakValue > m_objVISubject->getADCReceVoltage(l_nlstIndex))
		{
			l_nPeakValue = m_objVISubject->getADCReceVoltage(l_nlstIndex);
			l_nNegPeakIndex = l_nlstIndex;
		}
		//qDebug() <<"Neg Peak:" << VIData->m_objInteractiveData->m_nADCReceVoltage.value(l_nlstIndex);
	}
	m_objVISubject->setNegPeakValue(pActualData.value(l_nNegPeakIndex).toShort(&ok,16));
	m_objVISubject->setNegPeak(l_nPeakValue);
	m_objVISubject->setNegPeakIndex(l_nPeakIndex);
	//qDebug()<<"Negative Peak Value:" << l_nPeakValue<<pActualData.value(l_nNegPeakIndex).toShort(&ok,16);
}


bool VIFunctionalLogic::compareCureValues(QStringList pActualData,short int pLowerBand,short int pHigherBand,QString pStrPatternName)
{
	//int l_nRefHalfCurveAvg2=0,l_nRefHalfCurveAvg4=0;
	short int l_nPosConfidenceCount=0,l_nNegConfidenceCount=0,l_nPosHigherBandCount=0,
			l_nNegHigherBandCount=0,l_nPosLowerBandCount=0,l_nNegLowerBandCount=0;
	//bool m_bPointReached=false;
	//int l_nActHalfCurveAvg1=0,l_nActHalfCurveAvg3=0;
	short int l_nTemp=0;
	bool ok=false;
	for(int l_nActualIndex=0;l_nActualIndex<pActualData.count();l_nActualIndex++)
	{
		if(l_nActualIndex < 50){
			l_nTemp= pActualData.value(l_nActualIndex).toShort(&ok,16);

			if(l_nTemp>MID_RANGE)
				l_nTemp = l_nTemp - MID_RANGE;
			else
				l_nTemp = MID_RANGE-l_nTemp;
			qDebug()<<"Data:"<<hex<<l_nTemp;
			if(l_nTemp>pHigherBand)
				l_nPosHigherBandCount++;
			if(l_nTemp<pLowerBand)
				l_nPosLowerBandCount++;
			if(l_nTemp>=pLowerBand && l_nTemp<=pHigherBand)
			{
				//qDebug()<<"after Value:" << l_nTemp;
				//m_bPointReached = true;
				l_nPosConfidenceCount++;
				//qDebug() << "POS Confidence ADCVoltage:"<<VIData->m_objInteractiveData->m_nADCReceVoltage.value(l_nActualIndex);
				//break;
			}
			//l_nActHalfCurveAvg1 += l_nTemp;
		}
		else if(l_nActualIndex >=50)
		{
			l_nTemp=pActualData.value(l_nActualIndex).toShort(&ok,16);
			if(l_nTemp>MID_RANGE)
				l_nTemp = l_nTemp - MID_RANGE;
			else
				l_nTemp = MID_RANGE-l_nTemp;
			if(l_nTemp>pHigherBand)
				l_nNegHigherBandCount++;
			if(l_nTemp<pLowerBand)
				l_nNegLowerBandCount++;
			if(l_nTemp>=pLowerBand && l_nTemp<=pHigherBand)
			{
				//qDebug()<<"after Value:" << l_nTemp;
				l_nNegConfidenceCount++;
				//qDebug() << "Neg Confidence ADCVoltage:"<<VIData->m_objInteractiveData->m_nADCReceVoltage.value(l_nActualIndex);
			}

			//l_nActHalfCurveAvg3 += l_nTemp;
		}
	}
	qDebug() << "Positive Higher Band Count:" <<l_nPosHigherBandCount <<
			"Positive Lower Band Count:" << l_nPosLowerBandCount << "Confidence Band Count:"
		<< l_nPosConfidenceCount;
	qDebug() << "Negative Higher Band Count:" <<l_nNegHigherBandCount <<
			"Negative Lower Band Count:" << l_nNegLowerBandCount << "Confidence Band Count:"
			<< l_nNegConfidenceCount;
	m_objVISubject->setConfidencePosEdgeCount(l_nPosConfidenceCount);
	m_objVISubject->setConfidenceNegEdgeCount(l_nNegConfidenceCount);
	m_objVISubject->setPosLcount(l_nPosLowerBandCount);
	m_objVISubject->setPosUCount(l_nPosHigherBandCount);
	m_objVISubject->setNegLCount(l_nNegLowerBandCount);
	m_objVISubject->setNegUCount(l_nNegHigherBandCount);


	if(l_nPosConfidenceCount*2>=20||l_nNegConfidenceCount*2>=20)
	{

		if(m_objVISubject->is10PercentListExist(pStrPatternName) == false)
		{
			int l_nlstCount =m_objVISubject->get10PercentCount();
			if( l_nlstCount > 0)
				l_nlstCount ++;
			m_objVISubject->set10PercentList(l_nlstCount,pStrPatternName);
		}
		return true;
	}
	else
		return false;

}

unsigned int VIFunctionalLogic::ReadPSOCCODEID()
{
	return m_obVIHWInstance.readPSOCID();
}

void VIFunctionalLogic::setPSOCDelay()
{
	m_obVIHWInstance.setPSOCDelay();
}

