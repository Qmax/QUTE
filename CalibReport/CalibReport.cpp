/*
 * CalibReport.cpp
 *
 *  Created on: 20-May-2014
 *      Author: Ravivarman.R,Qmax
 */

#include "CalibReport.h"


CalibReport::CalibReport(QObject *parent):QObject(parent){

	m_document = new QTextDocument();
	m_cursor = QTextCursor(m_document);

}
CalibReport::~CalibReport(){
	delete m_document;
}
void CalibReport::generate(QStringList strList,const QString &appName){

	QTextCharFormat defaultFormat;
	defaultFormat.setFontPointSize(12);
	boldFormat = defaultFormat;
	boldFormat.setFontWeight(QFont::Bold);
	QTextCharFormat titleFormat = boldFormat;
	titleFormat.setFontPointSize(16);
	centerFormat.setAlignment(Qt::AlignHCenter);


	m_cursor.setBlockFormat(centerFormat);
	m_cursor.insertText(QString("\n\n %1 CALIBRATION REPORT\n\n").arg(appName),
			titleFormat);

	QTextTableFormat tableFormat;
	tableFormat.setCellPadding(5);
	tableFormat.setHeaderRowCount(1);
	tableFormat.setBorderStyle(QTextFrameFormat::BorderStyle_Solid);
	tableFormat.setWidth(QTextLength(QTextLength::PercentageLength, 100));

	m_cursor.insertTable(1, strList.count(), tableFormat);

	for(int i=0;i<strList.count();i++){
		m_cursor.insertText(strList.at(i), boldFormat);
		m_cursor.movePosition(QTextCursor::NextCell);
	}

}

void CalibReport::insertData(const report &rep){

	QTextTable *table = m_cursor.currentTable();
	if (! table)
		return;

	table->appendRows(1); // moves our cursor to the end of the doc...
	m_cursor.movePosition(QTextCursor::PreviousRow);

	for(int i=0;i<rep.DATASIZE;i++){
		m_cursor.movePosition(QTextCursor::NextCell);
		m_cursor.insertText(QString::number(rep.data[i]));
	}
	m_cursor.movePosition(QTextCursor::NextCell);
	m_cursor.insertText(rep.result);
	m_cursor.movePosition(QTextCursor::NextCell);
	m_cursor.insertText(rep.desc);

}

void CalibReport::write_odt(const QString &fileName){
	QTextDocumentWriter writer(fileName);
	writer.write(m_document);
}

void CalibReport::write_pdf(const QString &fileName){
	QPrinter printer;//QPrinter::HighResolution);
	printer.setPageSize(QPrinter::A4);
	printer.setOutputFormat(QPrinter::PdfFormat);
	printer.setOutputFileName(fileName);
	m_document->print(&printer);
	m_document->clear();
}

void CalibReport::setDeviceInfo(const device &dev){
	QImage image(":/qmax.png","png");
	m_cursor.insertImage(image);

	QTextCharFormat dFormat;
	dFormat.setFontPointSize(12);
	dFormat.setFontWeight(QFont::Bold);
	centerFormat.setAlignment(Qt::AlignLeft);

	m_cursor.setBlockFormat(centerFormat);
	m_cursor.insertText(QString("\n\nModel No: %1 \t\t Serial No: %2").arg(dev.modelNumber,dev.serialNumber),dFormat);
}

Q_EXPORT_PLUGIN2(CalibReportInterface, CalibReport)
