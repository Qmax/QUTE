/*
 * CalibReportInterface.h
 *
 *  Created on: 20-May-2014
*      Author: Ravivarman.R,Qmax
 */

#ifndef CALIBREPORTINTERFACE_H
#define CALIBREPORTINTERFACE_H

#include <QObject>

struct report {
        int DATASIZE;
        double data[20];
        QString result,desc;
};

struct device {
    QString modelNumber,serialNumber;
};

class CalibReportInterface
{
public:
    virtual void setDeviceInfo(const device &dev)=0;
    virtual void generate(QStringList strList,const QString &appNam)=0;
    virtual void insertData(const report &rep)=0;
    virtual void write_odt(const QString &fileName)=0;
    virtual void write_pdf(const QString &fileName)=0;

};
Q_DECLARE_INTERFACE(CalibReportInterface,"pt.CalibReportInterface/1.0.0.1");


#endif // HY3131DMMLIBINTERFACE_H
