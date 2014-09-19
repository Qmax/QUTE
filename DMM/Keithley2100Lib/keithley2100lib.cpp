/*
 * hy3131dmmlib.cpp
 *
 *  Created on: 11-Mar-2014
 *      Author: Ravivarman.R
 */

#include "keithley2100lib.h"


Keithley2100Lib::Keithley2100Lib(QObject *parent) :QObject(parent)
{
       fp=open("/dev/usbtmc0",O_RDWR);

       writeKeithley((char*)"*IDN?");
       qDebug()<<readKeithley();

       clearKeithley();
       resetKeithley();

}
void Keithley2100Lib::clearKeithley(){
	writeKeithley((char*)"*CLS");
}
void Keithley2100Lib::resetKeithley(){
	writeKeithley((char*)"*RST");
}
void Keithley2100Lib::writeKeithley(char *wrData){
	int size=strlen(wrData);
    char *pStrout = ( char*)malloc(size);
    write(fp,wrData,size);
    usleep(100000);
}
char* Keithley2100Lib::readKeithley(){
	memset(buf,0,100);
    read(fp,&buf,100);
    usleep(100000);
    qDebug()<<"readKeithley:"<<buf;
    return buf;
}
void Keithley2100Lib::ConfigureResistance(int range){
	qDebug()<<"ConfigureResistance-index:"<<range;
	switch(range){
	case 0:
		writeKeithley((char*)"CONF:RES 100E0");
		break;
	case 1:
		writeKeithley((char*)"CONF:RES 1E3");
		break;
	case 2:
		writeKeithley((char*)"CONF:RES 10E3");
		break;
	case 3:
		writeKeithley((char*)"CONF:RES 100E3");
		break;
	case 4:
		writeKeithley((char*)"CONF:RES 1E6");
		break;
	case 5:
		writeKeithley((char*)"CONF:RES 10E6");
		break;
	case 6:
		writeKeithley((char*)"CONF:RES 100E6");
		break;
	}
	usleep(200000);
}
double Keithley2100Lib::MeasureResistance(int range){
	qDebug()<<"MeasureResistance-index:"<<range;
	bool ok=true;
	switch(range){
	case 0:
		writeKeithley((char*)"MEAS:RES? 100E0");
		break;
	case 1:
		writeKeithley((char*)"MEAS:RES? 1E3");
		break;
	case 2:
		writeKeithley((char*)"MEAS:RES? 10E3");
		break;
	case 3:
		writeKeithley((char*)"MEAS:RES? 100E3");
		break;
	case 4:
		writeKeithley((char*)"MEAS:RES? 1E6");
		break;
	case 5:
		writeKeithley((char*)"MEAS:RES? 10E6");
		usleep(100000);
		break;
	case 6:
		writeKeithley((char*)"MEAS:RES? 100E6");
		usleep(100000);
        break;
	}
		double retData=QString(readKeithley()).toDouble(&ok);
		return retData;
}
void Keithley2100Lib::ConfigureDCVoltage(int range){
	qDebug()<<"ConfigureDCVoltage-index:"<<range;

        switch(range){
        case 15:
                writeKeithley((char*)"CONF:VOLT:DC 0.1");
                break;
        case 16:
                writeKeithley((char*)"CONF:VOLT:DC 1");
                break;
        case 17:
                writeKeithley((char*)"CONF:VOLT:DC 10");
                break;
        case 18:
                writeKeithley((char*)"CONF:VOLT:DC 100");
                break;
        case 19:
        case 20:
                writeKeithley((char*)"CONF:VOLT:DC 1000");
                break;
        }
        usleep(200000);
}
double Keithley2100Lib::MeasureDCVoltage(int range){
	qDebug()<<"MeasureDCVoltage-index:"<<range;

        bool ok=true;
        switch(range){
        case 15:
                writeKeithley((char*)"MEAS:VOLT:DC? 0.1");
                break;
        case 16:
                writeKeithley((char*)"MEAS:VOLT:DC? 1");
                break;
        case 17:
                writeKeithley((char*)"MEAS:VOLT:DC? 10");
                break;
        case 18:
                writeKeithley((char*)"MEAS:VOLT:DC? 100");
                break;
        case 19:
        case 20:
                writeKeithley((char*)"MEAS:VOLT:DC? 1000");
                break;
        }
                double retData=QString(readKeithley()).toDouble(&ok);
                return retData;
}
void Keithley2100Lib::ConfigureACVoltage(int range){
	qDebug()<<"ConfigureACVoltage-index:"<<range;


        switch(range){
        case 9:
                writeKeithley((char*)"CONF:VOLT:AC 0.1");
                break;
        case 10:
                writeKeithley((char*)"CONF:VOLT:AC 1");
                break;
        case 11:
                writeKeithley((char*)"CONF:VOLT:AC 10");
                break;
        case 12:
                writeKeithley((char*)"CONF:VOLT:AC 100");
                break;
        case 13:
        case 14:
                writeKeithley((char*)"CONF:VOLT:AC 1000");
                break;
        }
        usleep(200000);
}
double Keithley2100Lib::MeasureACVoltage(int range){
	qDebug()<<"MeasureACVoltage-index:"<<range;

        bool ok=true;
        switch(range){
        case 9:
                writeKeithley((char*)"MEAS:VOLT:AC? 0.1");
                break;
        case 10:
                writeKeithley((char*)"MEAS:VOLT:AC? 1");
                break;
        case 11:
                writeKeithley((char*)"MEAS:VOLT:AC? 10");
                break;
        case 12:
                writeKeithley((char*)"MEAS:VOLT:AC? 100");
                break;
        case 13:
        case 14:
                writeKeithley((char*)"MEAS:VOLT:AC? 1000");
                break;
        }
                double retData=QString(readKeithley()).toDouble(&ok);
                return retData;
}
void Keithley2100Lib::ConfigureDCCurrent(int range){
	qDebug()<<"ConfigureDCCurrent-index:"<<range;

        switch(range){
        case 1:
                writeKeithley((char*)"CONF:CURR:DC 0.01");
                break;
        case 21:
                writeKeithley((char*)"CONF:CURR:DC 0.1");
                break;
        case 22:
                writeKeithley((char*)"CONF:CURR:DC 1");
                break;
        case 23:
                writeKeithley((char*)"CONF:CURR:DC 3");
                break;
        }
        usleep(200000);
}
double Keithley2100Lib::MeasureDCCurrent(int range){
	qDebug()<<"MeasureDCCurrent-index:"<<range;

        bool ok=true;
        switch(range){
        case 1:
                writeKeithley((char*)"MEAS:CURR:DC? 0.01");
                break;
        case 21:
                writeKeithley((char*)"MEAS:CURR:DC? 0.1");
                break;
        case 22:
                writeKeithley((char*)"MEAS:CURR:DC? 1");
                break;
        case 23:
                writeKeithley((char*)"MEAS:CURR:DC? 3");
                break;

        }
                double retData=QString(readKeithley()).toDouble(&ok);
                return retData;
}
void Keithley2100Lib::ConfigureACCurrent(int range){
	qDebug()<<"ConfigureACCurrent-index:"<<range;

        switch(range){
        case 24:
        case 25:
                writeKeithley((char*)"CONF:CURR:AC 1");
                break;
        case 26:
                writeKeithley((char*)"CONF:CURR:AC 3");
                break;
        }
        usleep(200000);
}
double Keithley2100Lib::MeasureACCurrent(int range){
	qDebug()<<"MeasureACCurrent-index:"<<range;

        bool ok=true;
        switch(range){
        case 24:
        case 25:
                writeKeithley((char*)"MEAS:CURR:AC? 1");
                break;
        case 26:
                writeKeithley((char*)"MEAS:CURR:AC? 3");
                break;
        }
                double retData=QString(readKeithley()).toDouble(&ok);
                return retData;
}
void Keithley2100Lib::ConfigureDiode(int range){
	qDebug()<<"ConfigureDiode-index:"<<range;

    switch(range){
    case 8:
       writeKeithley((char*)"CONF:DIOD");
       break;
   }
        usleep(200000);
}

double Keithley2100Lib::MeasureDiode(int range){
	qDebug()<<"MeasureDiode-index:"<<range;

    bool ok=true;
    switch(range){
    case 8:
        writeKeithley((char*)"MEAS:DIOD");
    break;
}
    double retData=QString(readKeithley()).toDouble(&ok);
    return retData;
}

void Keithley2100Lib::ConfigureContinuity(int range){
	qDebug()<<"ConfigureContinuity-index:"<<range;

    switch(range){
    case 7:
        writeKeithley((char*)"CONF:CONT");
        break;
    }
      usleep(200000);
}

double Keithley2100Lib::MeasureContinuity(int range){
	qDebug()<<"MeasureContinuity-index:"<<range;

    bool ok=true;
    switch(range){
    case 7:
        writeKeithley((char*)"MEAS:CONT");
        break;
    }
    double retData=QString(readKeithley()).toDouble(&ok);
    return retData;
}

Keithley2100Lib::~Keithley2100Lib(){
    close(fp);
}
Q_EXPORT_PLUGIN2(IKeithley2100Interface, Keithley2100Lib)
