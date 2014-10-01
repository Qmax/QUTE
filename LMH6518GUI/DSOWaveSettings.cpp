/*
 * DSOWaveSettings.cpp
 *
 *  Created on: Sep 13, 2013
 *      Author: sountharya
 */

//#include "DSOWaveSettings.h"

//DSOWaveSettings::DSOWaveSettings()
//{
//		QPluginLoader loaderSPI("libSPIMemoryInterface.so", this);
//        ISPIMemory = qobject_cast<ISPIMemoryInterface*> (loaderSPI.instance());
//		QPluginLoader loaderApp("libPTApplicationcardInterface.so", this);
//		IAppCard = qobject_cast<IApplicationCardInterface*> (loaderApp.instance());
//		qDebug() << "Appcard" << IAppCard;
//		IAppCard->setDeviceName(SLOT0);
//		IAppCard->enumerateAPPCard();
//		m_objAD5293Component = new AD5293(IAppCard);
//		m_objAD5318Component = new AD5318Components(IAppCard);
//		qDebug() << "Code ID:" << hex << IAppCard->readAppCardCodeId();
//		qDebug()<<"DSOWaveSettings Interface";
//}
//
//DSOWaveSettings::~DSOWaveSettings()
//{
//}
//
//
//void DSOWaveSettings::setMaximumMemory(unsigned short int pMemory)
//{
//	Q_UNUSED(pMemory);
//}
//
//void DSOWaveSettings::setPostSampleCount(unsigned short int pPostCount)
//{
//	IAppCard->setDSOPostCount(pPostCount);
//}
//
//void DSOWaveSettings::setPreSampleCount(unsigned short int pPreCount)
//{
//	IAppCard->setDSOPreCount(pPreCount);
//}
//
//void DSOWaveSettings::setDSOBDR(unsigned int pBDR)
//{
//	IAppCard->setDSOBDR(pBDR);
//}
//
//void DSOWaveSettings::setForceTrigger(bool pTrigger)
//{
//	if(pTrigger)
//		IAppCard->setDSOTrigger(1);
//	else
//		IAppCard->setDSOTrigger(0);
//}
//
//void DSOWaveSettings::setDSOBTUR(unsigned int pBTUR)
//{
//	IAppCard->setDSOBTUR(pBTUR);
//}
//void DSOWaveSettings::DSODrive(DSO_RECEIVE_FIFO pSelFIFO)
//{
//	FILE *l_nFD;
//	unsigned int l_nFileData=0;
//	if(pSelFIFO == R1FIFO)
//	 l_nFD = fopen("./R1FIFO.txt","w");
//	else
//		l_nFD = fopen("./R2FIFO.txt","w");
//	  if(l_nFD == 0)
//		  printf("File I/O error\n");
//	IAppCard->setDSOReceiveFIFOMode(true,true);
//	usleep(1000);
//	IAppCard->setDSOReceiveFIFOConfiguration(R1FIFO,false,false,true);
//	IAppCard->setDSOCR(true);
//	// Force Trigger
//
//	IAppCard->setDSOCR(true);
//	IAppCard->setDSOReceiveFIFOMode(false,false);
//	unsigned int l_nPreCount = IAppCard->readRegister(PT_APPCARD_MODULES::PT_DSO_PRETCR)& 0xFFFF;
//	unsigned int l_nPosCount = IAppCard->readRegister(PT_APPCARD_MODULES::PT_DSO_POSTCR)& 0xFFFF;
//
//	qDebug()<<"Count:"<<(l_nPreCount+l_nPosCount);
//	unsigned short int l_nOddSample;
//	unsigned short int l_nEvenSample;
//
//	for(int l_nAddrIndex=0;l_nAddrIndex<(l_nPreCount+l_nPosCount);l_nAddrIndex++)
//	{
//		if(pSelFIFO == R1FIFO)
//		{
//			l_nOddSample= IAppCard->getDSOReceiveFIFOODD_RD(R1FIFO)&0x01FF;
//			l_nEvenSample = IAppCard->getDSOReceiveFIFOEVEN_RD(R1FIFO)&0x01FF;
//		}
//		else
//		{
//			l_nOddSample= IAppCard->getDSOReceiveFIFOODD_RD(R2FIFO)&0x01FF;
//			l_nEvenSample = IAppCard->getDSOReceiveFIFOEVEN_RD(R2FIFO)&0x01FF;
//		}
//	    fprintf(l_nFD,"%X\n",l_nOddSample);
//	    fprintf(l_nFD,"%X\n",l_nEvenSample);
//
//	}
//	fclose(l_nFD);
//}

