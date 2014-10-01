/*
 * DSOWaveSettings.h
 *
 *  Created on: Sep 13, 2013
 *      Author: Elangovan
 */


#ifndef DSOWAVESETTINGS_H_
#define DSOWAVESETTINGS_H_
#include <ApplicationCardInterface.h>
#include <QPluginLoader>
#include <QtCore>
#include <QObject>
#include "AppdeviceRegisterDetails.h"
#include "PTSPIMemoryInterface.h"
#include "ad5293.h"
#include "ad5318components.h"


//enum SAMPLING_TYPE{NORMAL=0,MIN_MAX,AVERAGE};

class DSOWaveSettings:public QObject
{
	//Q_OBJECT
public:
	DSOWaveSettings()
	{
		QPluginLoader loaderSPI("libSPIMemoryInterface.so", this);
		ISPIMemory = qobject_cast<ISPIMemoryInterface*> (loaderSPI.instance());

		QPluginLoader loader2("libBackPlaneInterface.so");
		IBackPlane = qobject_cast<IntefaceBackPlane*> (loader2.instance());
		IBackPlane->InitializeBpObject();

		QPluginLoader loaderApp("libPTApplicationcardInterface.so", this);
		IAppCard = qobject_cast<IApplicationCardInterface*> (loaderApp.instance());
		qDebug() << "Appcard" << IAppCard;
		IAppCard->setDeviceName(SLOT0);
		IAppCard->enumerateAPPCard();
		m_nInterruptValue = IAppCard->readScratchPad();

		qDebug()<<"Scratch:"<<m_nInterruptValue;
		m_objAD5293Component = new AD5293(IAppCard);
		m_objAD5318Component = new AD5318Components(IAppCard);
		qDebug() << "Code ID:" << hex << IAppCard->readAppCardCodeId();
		qDebug()<<"DSOWaveSettings Interface";
	}

	~DSOWaveSettings()
	{
	}

	void configureReceiverAndTrigger(RECEIVER_CONF pConf,DSO_TRIGGER pTrigger)
	{
		IAppCard->setDSOTriggerSource(pConf,pTrigger);
	}

	void setMaximumMemory(unsigned short int pMemory)
	{
		Q_UNUSED(pMemory);
	}

	void setPostSampleCount(unsigned short int pPostCount)
	{
		IAppCard->setDSOPostCount(pPostCount);
	}

	void setPreSampleCount(unsigned short int pPreCount)
	{
		IAppCard->setDSOPreCount(pPreCount);
	}

	void setSamplingType(SAMPLING_TYPE pType)
	{
		m_eSamplesType = pType;
	}

	void setDSOBDR(unsigned int pBDR)
	{
		IAppCard->setDSOBDR(pBDR);

	}

	void setForceTrigger(bool pTrigger)
	{
		//Q_UNUSED(pTrigger)
		IAppCard->setDSOTrigger(1);
		if(pTrigger== true)
			IAppCard->checkDSODriveDone();

	}

	void enableInterrupt()
	{
		unsigned int l_nIntPadValue = 0x0080;
		l_nIntPadValue = 0x0000 | l_nIntPadValue;
		//qDebug()<<"Enable Interrupt Value:"<<hex<<l_nIntPadValue;
		IBackPlane->writeBackPlaneRegister(l_nIntPadValue, 0x0020);//enabling psoc INT0 embedded key interrupt / App Card SLOT 0 Interrupt
		IBackPlane->writeBackPlaneRegister(0x80, 0x001E);//clear all interrupts
		IBackPlane->writeBackPlaneRegister(0x1, 0x0024); //enabling global interrupt
	}

	void disableInterrupt()
	{
		unsigned int l_nIntPadValue = 0x0080;
		//qDebug()<<"Disable Interrupt Value:"<<hex<<l_nIntPadValue;
		IBackPlane->writeBackPlaneRegister(l_nIntPadValue, 0x001E);//clear all interrupts
		IBackPlane->writeBackPlaneRegister(0x0000, 0x0020);//disable all interrupts
		IBackPlane->writeBackPlaneRegister(0x0000, 0x0024);//disable global interrupt
	}

	void clearInterrupt()
	{
		unsigned int l_nIntPadValue = 0x0080 | m_nInterruptValue;
		//	qDebug()<<"Interrupt Value:"<<hex<<l_nIntPadValue;
		IBackPlane->writeBackPlaneRegister(m_nInterruptValue, 0x001E);//clear all interrupts

	}

	void setDSOBTUR(unsigned int pBTUR)
	{
		IAppCard->setDSOBTUR(pBTUR);
	}
	QMap<int,QList<double> > getYVectorPoints(DSO_CHANNEL pChannel) const
			{
		if(pChannel == CHANNEL1)
		{
			return m_objChannel1OddData;
		}
		if(pChannel == CHANNEL2)
			return m_objChannel1EvenData;
		if(pChannel == CHANNEL3)
			return m_objChannel2OddData;
		if(pChannel == CHANNEL4)
			return m_objChannel2EvenData;
			}

	void convertToDecimation(double pVolt,double PFSSettings,int pRectWidth,DSO_RECEIVE_FIFO pSelFIFO,int pSampleCount,QList<unsigned char> pLstOdd,QList<unsigned char> pLstEven)
	{
		unsigned short l_nGCounter=0,l_nCounter=0;
		double m_nXData=0.0;
		m_nVolt = pVolt;
		m_nFSSettings= PFSSettings;
		QList<double> l_nlstYPoints,l_nlstEvenPoints;
		IAppCard->setDSOReceiveFIFOMode(false,false);
		l_nlstYPoints.clear();l_nlstEvenPoints.clear();
		double l_nSamplesperPixel = (double)floor((double)pSampleCount/(double)pRectWidth);
		//		if(m_eSamplesType == NORMAL)
		//			l_nSamplesperPixel = 1.0;
		//qDebug()<<"samples Per Pixel:"<<l_nSamplesperPixel<<pSampleCount<<pLstEven.count();

		m_nTriggerSamples = l_nSamplesperPixel * pRectWidth;
		if(m_eSamplesType == NORMAL || m_eSamplesType == MIN_MAX || m_eSamplesType == AVERAGE)
			l_nSamplesperPixel = 1.0;

		for(unsigned short int l_nAddrIndex=0;l_nAddrIndex<pRectWidth;l_nAddrIndex++)
		{
			int l_nCounterIndex=0,l_nEvenCounter=0;
			for(int l_nFileCount=0;l_nFileCount<l_nSamplesperPixel;l_nFileCount++)
			{
				if(pSelFIFO == R1FIFO )
				{
					l_nlstYPoints.insert(l_nCounterIndex++,convertFIFOData(pLstOdd.value(l_nGCounter)));
					l_nlstEvenPoints.insert(l_nEvenCounter++,convertFIFOData(pLstEven.value(l_nGCounter)));
				}
				else  if(pSelFIFO == R2FIFO )
				{
					l_nlstYPoints.insert(l_nCounterIndex++,convertFIFOData(pLstOdd.value(l_nGCounter)));
					l_nlstEvenPoints.insert(l_nEvenCounter++,convertFIFOData(pLstEven.value(l_nGCounter)));
				}
				l_nGCounter++;
			}
			if(pSelFIFO == R1FIFO){
				m_objChannel1OddData.insert(m_nXData,l_nlstYPoints);
				m_objChannel1EvenData.insert(m_nXData,l_nlstEvenPoints);
			}
			if(pSelFIFO == R2FIFO)
			{
				m_objChannel2OddData.insert(m_nXData,l_nlstYPoints);
				m_objChannel2EvenData.insert(m_nXData,l_nlstEvenPoints);
			}

			l_nlstYPoints.clear();
			l_nlstEvenPoints.clear();
			l_nCounter++;
			m_nXData = l_nCounter;//m_nXData + l_nSamplingRate;
		}

		if(m_eSamplesType == LINEAR_INTERPOLATION)
		{
			doLinearInterpolation(pSelFIFO,pRectWidth);
		}
		else if(m_eSamplesType == MOVING_LINEAR)
		{
			doLinearInterpolation(pSelFIFO,pRectWidth,false);
			calcuateMovingAverage(pSelFIFO,pRectWidth);
		}
	}

	void convertToDecimation(double pVolt,double pFSSettings,int pRectWidth,DSO_RECEIVE_FIFO pSelFIFO,int pSampleCount,bool pOdd,bool pEven)
	{
		unsigned short int l_nOddSample=0;
		//
		//		for(unsigned short int l_nAddrIndex=0;l_nAddrIndex<4;l_nAddrIndex++)
		//		{
		//			   l_nOddSample= ~(IAppCard->getDSOReceiveFIFOODD_RD(R1FIFO))&0x0FF;
		//		}
		//		return;
		// Displaying all Points
		//qDebug()<<m_nFSSettings<<pVolt;
		//FILE *l_nFD;
		//l_nFD = fopen("./R1FIFO.txt","w");
		//pRectWidth =4;
		m_nVolt = pVolt;
		m_nFSSettings= pFSSettings;
		//qDebug()<<"FS Settings:"<<m_nFSSettings<<"Voltage:"<<m_nVolt;
		double m_nXData=0.0;
		unsigned short l_nCounter=0;
		unsigned int l_nTC=0;
		double l_nSamplesperPixel=0.0;
		l_nSamplesperPixel = (double)floor((double)pSampleCount/(double)pRectWidth);
		//  qDebug()<<"samples Per Pixel:"<<l_nSamplesperPixel<<pSampleCount;
		if(l_nSamplesperPixel <= 1.0){
			l_nTC = pSampleCount;
			l_nSamplesperPixel=1.0;
		}
		else
		{
			l_nTC = pRectWidth*2;
			//	           l_nSamplesperPixel*=2;
		}
		//qDebug()<<"samples Per Pixel:"<<l_nSamplesperPixel<<l_nTC<<pRectWidth;
		QList<double> l_nlstYPoints,l_nlstEvenPoints;
		m_objGlobalList.clear();
		IAppCard->setDSOReceiveFIFOMode(false,false);
		unsigned int l_nPreCount = IAppCard->readRegister(PT_APPCARD_MODULES::PT_DSO_PRETCR);//& 0xFFFF;
		unsigned int l_nPosCount = IAppCard->readRegister(PT_APPCARD_MODULES::PT_DSO_POSTCR);//& 0xFFFF;

		l_nlstYPoints.clear();l_nlstEvenPoints.clear();
		unsigned short int l_nEvenSample=0;
		unsigned short int l_nGCounter=0;
		//qDebug()<<"Pre and Post Count:"<<(l_nPreCount+l_nPosCount)<<pRectWidth;
		m_nTriggerSamples = l_nSamplesperPixel * pRectWidth;
		//	qDebug()<<"Inside Convert To Decimation"<<m_nTriggerSamples;
		unsigned short int l_nInterPolateCount=0;
		for(unsigned short int l_nAddrIndex=0;l_nAddrIndex<pRectWidth;l_nAddrIndex++)
		{
			int l_nCounterIndex=0,l_nEvenCounter=0;
			for(int l_nFileCount=0;l_nFileCount<l_nSamplesperPixel;l_nFileCount++)
			{
				//   qDebug()<<"1"
				if(pSelFIFO == R1FIFO)
				{
					l_nOddSample= ~(IAppCard->getDSOReceiveFIFOODD_RD(R1FIFO))&0x0FF;
					l_nEvenSample = ~(IAppCard->getDSOReceiveFIFOEVEN_RD(R1FIFO))&0x0FF;
				}
				else
				{
					l_nOddSample= ~(IAppCard->getDSOReceiveFIFOODD_RD(R2FIFO))&0x0FF;
					l_nEvenSample = ~(IAppCard->getDSOReceiveFIFOEVEN_RD(R2FIFO))&0x0FF;
				}

				m_objGlobalList.insert(l_nGCounter++,convertFIFOData(l_nEvenSample));
				l_nlstYPoints.insert(l_nCounterIndex++,convertFIFOData(l_nOddSample));
				l_nlstEvenPoints.insert(l_nEvenCounter++,convertFIFOData(l_nEvenSample));
				// fprintf(l_nFD,"%f\n",convertFIFOData(l_nEvenSample));

			}
			if(m_eSamplesType == AVERAGE && l_nSamplesperPixel >1)
			{
				calculateAveragePoints(l_nlstYPoints);
				l_nlstYPoints.clear();
				l_nlstYPoints.insert(0,m_nAveragePoint);
				calculateAveragePoints(l_nlstEvenPoints);
				l_nlstEvenPoints.clear();
				l_nlstEvenPoints.insert(0,m_nAveragePoint);

			}
			else if(m_eSamplesType == MIN_MAX && l_nSamplesperPixel >1)
			{
				// Find Min Max points
				findMinMax(l_nlstYPoints);
				l_nlstYPoints.clear();
				l_nlstYPoints.insert(0,m_nMinPoint);
				l_nlstYPoints.insert(1,m_nMaxPoint);
				findMinMax(l_nlstEvenPoints);
				l_nlstEvenPoints.clear();
				l_nlstEvenPoints.insert(0,m_nMinPoint);
				l_nlstEvenPoints.insert(1,m_nMaxPoint);

			}
			else if(m_eSamplesType == NORMAL && l_nSamplesperPixel > 1)
			{
				// l_nlstYPoints = findRedundantPoints(l_nlstYPoints);
				//  l_nlstEvenPoints = findRedundantPoints(l_nlstEvenPoints);
			}
			if(pSelFIFO == R1FIFO){
				m_objChannel1OddData.insert(m_nXData,l_nlstYPoints);
				m_objChannel1EvenData.insert(m_nXData,l_nlstEvenPoints);
			}
			if(pSelFIFO == R2FIFO)
			{
				m_objChannel2OddData.insert(m_nXData,l_nlstYPoints);
				m_objChannel2EvenData.insert(m_nXData,l_nlstEvenPoints);
			}

			l_nlstYPoints.clear();
			l_nlstEvenPoints.clear();
			l_nCounter++;
			m_nXData = l_nCounter;//m_nXData + l_nSamplingRate;
		}
		if(m_eSamplesType==MIN_MAX && l_nSamplesperPixel >1)
		{
			l_nSamplesperPixel=2.0;
		}
		else if (m_eSamplesType==AVERAGE && l_nSamplesperPixel >1)
		{
			l_nSamplesperPixel=1.0;
		}
		else if(m_eSamplesType == MOVING_AVERAGE){
			calcuateMovingAverage(pSelFIFO,pRectWidth);
		}
		else if(m_eSamplesType == LINEAR_INTERPOLATION)
		{
			doLinearInterpolation(pSelFIFO,pRectWidth);
		}
		else if(m_eSamplesType == MOVING_LINEAR)
		{
			doLinearInterpolation(pSelFIFO,pRectWidth,false);
			calcuateMovingAverage(pSelFIFO,pRectWidth);
		}

		// fclose(l_nFD);
	}

	double doLinearInterpolation(DSO_RECEIVE_FIFO pSelFIFO,unsigned short pRectWidth,bool bOnlyLinear=true)
	{
		double l_nX1,l_nX2,l_nY1,l_nY2;
		l_nX1=l_nX2=l_nY1=l_nY2=0.0;
		double l_nIntoX1,l_nIntoY1;
		l_nIntoX1=l_nIntoY1=0.0;
		double l_nIncX=0.0;
		double dxFactor = (pRectWidth)/((double)m_objGlobalList.count());
		l_nIncX = dxFactor;
		//qDebug()<<"Dx Factor:"<<dxFactor<<m_objGlobalList.count();
		m_nLinearInterpolatedList.clear();
		m_objChannel1OddData.clear();
		m_objChannel1EvenData.clear();
		QList<double> l_nlstYPoints;
		l_nlstYPoints.clear();
		short int l_nCounter=0;
		for(unsigned short l_nWaveCounter=0;l_nWaveCounter<(m_objGlobalList.count());l_nWaveCounter++)
		{
			l_nX1 = l_nIncX;
			l_nY1 = m_objGlobalList.value(l_nWaveCounter);
			l_nIncX = l_nIncX + dxFactor;
			l_nX2 = l_nIncX;
			l_nY2 = m_objGlobalList.value(l_nWaveCounter+1);
			m_nLinearInterpolatedList.insert(l_nCounter++,l_nY1);

			//	qDebug()<<"X1:"<<l_nX1<<"X2:"<<l_nX2<<"Y1:"<<l_nY1<<"Y2:"<<l_nY2;
			l_nIntoY1 = ((((l_nX1+l_nX2)/2) - l_nX2) / (l_nX1 - l_nX2))*(l_nY1) + ((((l_nX1+l_nX2)/2) - l_nX1) / (l_nX2 - l_nX1))*(l_nY2);
			m_nLinearInterpolatedList.insert(l_nCounter++,l_nIntoY1);
			//qDebug()<<"Inter Polated Y1:"<<l_nIntoY1<<l_nY1;
		}
		m_objGlobalList.clear();
		if(bOnlyLinear == false){
			m_objGlobalList = m_nLinearInterpolatedList;
			return 1.0;
		}
		double l_nSamplesperPixel = (double)floor((double)m_nLinearInterpolatedList.count()/(double)pRectWidth);
		if(l_nSamplesperPixel <= 1.0){
			l_nSamplesperPixel=1.0;
		}
		short int l_nCounterIndex=0;
		l_nCounter=0;
		double m_nXData=0.0;
		// qDebug()<<"Samples Per Pixel:"<<l_nSamplesperPixel;
		m_nTriggerSamples = l_nSamplesperPixel * pRectWidth;
		short int l_nMoveIndex=0;
		FILE *l_nFD;
		l_nFD = fopen("./File1.txt","w");
		for(int l_nTC=0;l_nTC<pRectWidth;l_nTC++)
		{
			l_nCounterIndex=0;
			for(int l_nFileCount=l_nMoveIndex;l_nFileCount<l_nMoveIndex+l_nSamplesperPixel;l_nFileCount++)
			{
				//   qDebug()<<"1"
				if(pSelFIFO == R1FIFO)
				{
					l_nlstYPoints.insert(l_nCounterIndex++,m_nLinearInterpolatedList.value(l_nFileCount));
					fprintf(l_nFD,"%f\n",m_nLinearInterpolatedList.value(l_nFileCount));
				}
			}
			if(pSelFIFO == R1FIFO){
				// m_objChannel1OddData.insert(m_nXData,l_nlstYPoints);
				m_objChannel1EvenData.insert(m_nXData,l_nlstYPoints);
			}
			l_nlstYPoints.clear();
			m_nXData=l_nCounter;
			l_nCounter++;
			l_nMoveIndex +=l_nSamplesperPixel;
		}
		//m_nLinearInterpolatedList.clear();
		fclose(l_nFD);
		//qDebug()<<"Linear Interpolation completed."<<m_objChannel1EvenData.count();
	}


	void calcuateMovingAverage(DSO_RECEIVE_FIFO pSelFIFO,unsigned short pRectWidth)
	{
		//qDebug()<<"Inside Moving Average.";
		unsigned short l_nWindowSize = 5,l_nAverageCounter=0;
		//	FILE *l_nFD;
		//	FILE *l_ntemp;
		//	l_nFD = fopen("./File1.txt","w");
		//	l_ntemp = fopen("./File2.txt","w");
		double l_nSum=0.0;
		QList<double> l_nlstYPoints;
		m_objMovingAverage.clear();
		m_objChannel1OddData.clear();
		m_objChannel1EvenData.clear();
		l_nlstYPoints.clear();
		unsigned short l_nCounter=0;
		double m_nXData=0.0;
		//qDebug()<<"Global Counter:"<<m_objGlobalList.count();
		for(unsigned short l_nWaveCounter=0;l_nWaveCounter<(m_objGlobalList.count());l_nWaveCounter++)
		{
			l_nSum=0.0;
			//fprintf(l_ntemp,"%f\n",m_objGlobalList.value(l_nWaveCounter));
			for(unsigned short l_nIndex=l_nWaveCounter;l_nIndex<l_nWaveCounter+l_nWindowSize;l_nIndex++)
			{
				l_nSum +=m_objGlobalList.value(l_nIndex);

			}
			if(pSelFIFO == R1FIFO)
				m_objMovingAverage.insert(l_nAverageCounter++,(l_nSum/(double)l_nWindowSize));
		}
		double l_nSamplesperPixel = (double)floor((double)m_objMovingAverage.count()/(double)pRectWidth);
		if(l_nSamplesperPixel <= 1.0){
			l_nSamplesperPixel=1.0;
		}

		m_nTriggerSamples = l_nSamplesperPixel * pRectWidth;
		//qDebug()<<"Moving Average Finished."<<m_objMovingAverage.count()<<l_nSamplesperPixel;
		short int l_nCounterIndex=0;
		short int l_nMoveIndex=0;
		for(int l_nTC=0;l_nTC<pRectWidth;l_nTC++)
		{
			l_nCounterIndex=0;
			for(int l_nFileCount=l_nMoveIndex;l_nFileCount<l_nMoveIndex+l_nSamplesperPixel;l_nFileCount++)
			{
				//   qDebug()<<"1"
				if(pSelFIFO == R1FIFO)
				{
					l_nlstYPoints.insert(l_nCounterIndex++,m_objMovingAverage.value(l_nFileCount));
					//fprintf(l_nFD,"%f\n",m_objMovingAverage.value(l_nFileCount));
				}
			}
			if(pSelFIFO == R1FIFO){
				// m_objChannel1OddData.insert(m_nXData,l_nlstYPoints);
				m_objChannel1EvenData.insert(m_nXData,l_nlstYPoints);
			}
			l_nlstYPoints.clear();
			l_nMoveIndex +=l_nSamplesperPixel;
			m_nXData=l_nCounter;
			l_nCounter++;
		}
		m_objGlobalList.clear();
		//	qDebug()<<"Completed Moving Average.";
		//fclose(l_nFD);
		//fclose(l_ntemp);
	}
	double	convertFIFOData(unsigned char pStrData)
	{
		//return 0.0;
		double l_nVref = m_nFSSettings;
		double l_nYPoint = (((2*pStrData)*l_nVref)/ (pow(2,8)-1)) - l_nVref;
		l_nYPoint = l_nYPoint * ((m_nVolt * 8.0) / m_nFSSettings);
		//qDebug()<<"YPoint:"<<l_nYPoint;
		return l_nYPoint;
	}


	void calculateAveragePoints(QList<double> plstPoints)
	{
		m_nAveragePoint=0.0;
		for(int l_nMinMaxIndex=0;l_nMinMaxIndex<plstPoints.count();l_nMinMaxIndex++)
		{
			m_nAveragePoint +=plstPoints.value(l_nMinMaxIndex);
		}
		m_nAveragePoint= m_nAveragePoint / plstPoints.count();

	}
	QList<double> findRedundantPoints(QList<double> pList)
			{
		for(int l_nIndex=0;l_nIndex<pList.count();l_nIndex++)
		{
			double l_nValue = pList.value(l_nIndex);
			for(int l_nLoopIndex=l_nIndex+1;l_nLoopIndex<pList.count();l_nLoopIndex++)
			{
				if(pList.value(l_nLoopIndex) == l_nValue)
				{
					pList.removeAt(l_nLoopIndex);
				}
			}
		}

		return pList;
			}


	void findMinMax(QList<double> plstPoints)
	{
		//m_nMinPoint=m_nMaxPoint=0.0;
		m_nMinPoint = plstPoints.value(0);
		m_nMaxPoint= plstPoints.value(0);
		for(int l_nMinMaxIndex=0;l_nMinMaxIndex<plstPoints.count();l_nMinMaxIndex++)
		{
			if(m_nMinPoint > plstPoints.value(l_nMinMaxIndex) )
				m_nMinPoint = plstPoints.value(l_nMinMaxIndex);
			if(m_nMaxPoint< plstPoints.value(l_nMinMaxIndex))
				m_nMaxPoint=plstPoints.value(l_nMinMaxIndex);
		}
		//qDebug()<<"Min Point:"<<m_nMinPoint<<"Max Point:"<<m_nMaxPoint;
	}

	void DSODrive(DSO_RECEIVE_FIFO pSelFIFO)
	{
		FILE *l_nFD,*l_nFB;
		//unsigned int l_nFileData=0;
		if(pSelFIFO == R1FIFO){
			l_nFD = fopen("./R1FIFO.txt","w");
			l_nFB = fopen("./R1FIFO.bin","wb");
		}
		else{
			l_nFD = fopen("./R2FIFO.txt","w");
			l_nFB = fopen("./R2FIFO.bin","wb");
		}
		if(l_nFD == 0 || l_nFB ==0)
			printf("File I/O error\n");


		IAppCard->setDSOReceiveFIFOMode(false,false);
		unsigned int l_nPreCount = IAppCard->readRegister(PT_APPCARD_MODULES::PT_DSO_PRETCR);//& 0xFFFF;
		unsigned int l_nPosCount = IAppCard->readRegister(PT_APPCARD_MODULES::PT_DSO_POSTCR);//& 0xFFFF;

		//qDebug()<<"Count:"<<(l_nPreCount+l_nPosCount);
		unsigned short int l_nOddSample;
		unsigned short int l_nEvenSample;

		unsigned int l_nCompressedSample=0;
		unsigned short int l_nX1=24,l_nX2=16;
		for(unsigned short int l_nAddrIndex=0;l_nAddrIndex<(l_nPreCount+l_nPosCount)/2;l_nAddrIndex++)
		{
			l_nX1=24;l_nX2=16;
			if(pSelFIFO == R1FIFO)
			{

				for(int l_nFileIndex=0;l_nFileIndex<2;l_nFileIndex++)
				{
					l_nOddSample= IAppCard->getDSOReceiveFIFOODD_RD(R1FIFO)&0x00FF;
					l_nEvenSample = IAppCard->getDSOReceiveFIFOEVEN_RD(R1FIFO)&0x00FF;
					l_nCompressedSample|=(l_nOddSample<<l_nX1)|(l_nEvenSample<<l_nX2);
					l_nX1=8;l_nX2=0;
				}
			}
			fprintf(l_nFB,"%X\n",l_nCompressedSample);
		}
		fclose(l_nFB);

		for(unsigned short int l_nAddrIndex=0;l_nAddrIndex<(l_nPreCount+l_nPosCount);l_nAddrIndex++)
		{
			if(pSelFIFO == R1FIFO)
			{
				l_nOddSample= IAppCard->getDSOReceiveFIFOODD_RD(R1FIFO)&0x0FF;
				l_nEvenSample = IAppCard->getDSOReceiveFIFOEVEN_RD(R1FIFO)&0x0FF;
			}
			else
			{
				l_nOddSample= IAppCard->getDSOReceiveFIFOODD_RD(R2FIFO)&0x0FF;
				l_nEvenSample = IAppCard->getDSOReceiveFIFOEVEN_RD(R2FIFO)&0x0FF;
			}
			fprintf(l_nFD,"%X\n",l_nOddSample);
			fprintf(l_nFD,"%X\n",l_nEvenSample);

		}
		fclose(l_nFD);
	}

	void ReceiverConfiguration()
	{
		IAppCard->setDSOReceiveFIFOMode(true,true);
		usleep(1000);
		IAppCard->setDSOReceiveFIFOConfiguration(R1FIFO,false,false,true);
		IAppCard->setDSOReceiveFIFOConfiguration(R2FIFO,false,false,true);
	}

	void DriveInterrupt(bool isNormal=false)
	{
		ReceiverConfiguration();
		IAppCard->setDSOCR(true);
		if(isNormal == false){
			usleep(5000);
			while(!(IAppCard->readRegister(PT_APPCARD_MODULES::PT_DSO_CR)&0x04)==0x04);
			//usleep(20000);
			setForceTrigger(false);
		}
		//	qDebug()<<"Drive Interrupt";
	}

	void Drive(bool pFlag)
	{
		if(pFlag==true)
		{
			ReceiverConfiguration();
			IAppCard->setDSOCR(pFlag);
			usleep(1000);
			while(!(IAppCard->readRegister(PT_APPCARD_MODULES::PT_DSO_CR)&0x04)==0x04);
		}
		else
		{
			IAppCard->setDSOCR(pFlag);
		}
	}
	unsigned int getTriggerSamples() const
	{
		return m_nTriggerSamples;
	}
protected:
	unsigned short int m_nMaximumSamples;
	unsigned short int m_nPreSamples;
	unsigned short int m_nPostSamples;
	unsigned short int m_nBTUR;
	unsigned short int m_nBDR;
	IApplicationCardInterface *IAppCard;
	IntefaceBackPlane *IBackPlane;
	ISPIMemoryInterface *ISPIMemory;
	AD5293 *m_objAD5293Component;
	AD5318Components *m_objAD5318Component;
	AD5318_DACSELECT m_eSelect;
	unsigned int m_nInterruptValue;
	double m_nMinPoint,m_nMaxPoint,m_nAveragePoint;
	QList<double> m_objMovingAverage,m_objGlobalList,m_nLinearInterpolatedList;
	QMap<int,QList<double> > m_objChannel1OddData,m_objChannel1EvenData;
	QMap<int,QList<double> > m_objChannel2OddData,m_objChannel2EvenData;
	double m_nVolt,m_nFSSettings;
	unsigned int m_nTriggerSamples;
	SAMPLING_TYPE m_eSamplesType;

};
#endif /* DSOWAVESETTINGS_H_ */










