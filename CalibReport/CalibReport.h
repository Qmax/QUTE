/*
 * CalibReport.h
 *
 *  Created on: 20-May-2014
*      Author: Ravivarman.R,Qmax
 */

#ifndef CALIBREPORT_H
#define CALIBREPORT_H

#include <QtGui>
#include <QFile>
#include <QtCore>
#include <QImage>
#include <qdebug.h>
#include <QPrinter>
#include <unistd.h>
#include <QTextTable>
#include <QTextCursor>
#include <QPluginLoader>
#include <QTextDocument>
#include <QTextFrameFormat>
#include <QTextDocumentWriter>
#include "CalibReportInterface.h"

class CalibReport :public QObject,public CalibReportInterface {
    Q_OBJECT
    Q_INTERFACES(CalibReportInterface)

public:
   CalibReport(QObject *parent = 0);
   ~CalibReport();

   void setDeviceInfo(const device &dev);
   void generate(QStringList strList,const QString &appNam);
   void insertData(const report &rep);
   void write_odt(const QString &fileName);
   void write_pdf(const QString &fileName);
   void setTolorence(double tolPercentage);

protected:
   QString appName;
private:
    QTextBlockFormat centerFormat,rightFormat;
    QTextCharFormat boldFormat;
    QTextCursor m_cursor;
    QTextDocument *m_document;
};

#endif // CALIBREPORT_H
