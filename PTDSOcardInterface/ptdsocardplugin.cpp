#include "ptdsocardplugin.h"


//static const char *device = "/dev/emiapp";

void PTDSOCardPlugin::setDeviceName()
{
    mapDeviceString.insert(0,"/dev/emiapp");	//CS0-SLOT0
	mapDeviceString.insert(1,"/dev/emics3");	//CS0-SLOT1
	mapDeviceString.insert(2,"/dev/emics4");	//CS0-SLOT2
	mapDeviceString.insert(3,"/dev/emics5");	//CS0-SLOT3
	m_strdevice = mapDeviceString.value(0);
}

void PTDSOCardPlugin::enumerateDSOCard()
{
    tempAddr=0;
    baseAddr = 0x000000;
    m_nDSOFD = open(mapDeviceString.value(0),O_RDWR);
    if (m_nDSOFD < 0)    		{
                printf("Can't open device for DSO card communication.\n");
                close(m_nDSOFD);
    		}
/*    for(int l_nDSOCardIndex=0;l_nDSOCardIndex<4;l_nDSOCardIndex++)
    {
    	int l_nDSOFD = open(mapDeviceString.value(l_nDSOCardIndex),O_RDWR);
    	if (l_nDSOFD < 0)
		{
            printf("Can't open device for DSO card communication.\n");
            close(l_nDSOFD);
		}
		m_nDSOFD = l_nDSOFD;
    	if( readDSOCardCodeId() == 0x1982)    	{
    		qDebug()<<"DSO CODE ID:"<<hex<<readDSOCardCodeId();
        	break;
    	}
    }*/
}
unsigned int PTDSOCardPlugin::readScratchPad(){
	return readRegister(0x0005);
}
unsigned  int PTDSOCardPlugin::readDSOCardCodeId(){
    return readRegister(0x0000);
}
void PTDSOCardPlugin::writeScratchpad(unsigned int pData){
    writeRegister(pData,0x0023);//Data,Addr
}
unsigned int PTDSOCardPlugin::readRegister(unsigned int pAddress){
    unsigned int *m_ptrReadValues;
    m_ptrReadValues = (unsigned int*)malloc(1*sizeof(unsigned int));
    unsigned int l_nReceiveData=0;
     tempAddr=pAddress;
     pAddress=baseAddr|tempAddr;
     m_ptrReadValues[0] = pAddress;
     l_nReceiveData = read(m_nDSOFD,m_ptrReadValues,sizeof(m_ptrReadValues));
     free(m_ptrReadValues);
     return l_nReceiveData;
}
void PTDSOCardPlugin::writeRegister(unsigned int pData, unsigned int pAddress){
    unsigned int *m_ptrWriteValues;
    m_ptrWriteValues = (unsigned int*)malloc(2*sizeof(unsigned int));
    tempAddr=pAddress;
    pAddress=baseAddr|tempAddr;
    m_ptrWriteValues[0] = pData;
    m_ptrWriteValues[1] = pAddress;
    write(m_nDSOFD,m_ptrWriteValues,sizeof(m_ptrWriteValues));
    free(m_ptrWriteValues);
}
Q_EXPORT_PLUGIN2(IDSOCardInterface, PTDSOCardPlugin)
