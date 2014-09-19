
#include "test_calibreportinterface.h"

#include <QXmlStreamAttributes>
#include <QXmlStreamReader>
#include <QIODevice>
#include <QDebug>
#include <QMessageBox>
#include <QtXml/QXmlStreamReader>
#include <QtXml/QXmlStreamWriter>
#include <QFile>

test_CalibReportInterface::test_CalibReportInterface(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);

    QPluginLoader loader("libCalibReport.so", this);
    calibReport = qobject_cast<CalibReportInterface*> (loader.instance());

}

test_CalibReportInterface::~test_CalibReportInterface()
{

}

void test_CalibReportInterface::on_pushButton_clicked()
{
    QStringList strList;
    strList << "Drive" << "Before" << "After" << "Max" << "Min" << "Result" << "Description";

    device dev;
    dev.modelNumber="PT6 QUTE ULTIMATE";
    dev.serialNumber="001";

    report repo[2];

    repo[0].DATASIZE=5;
    repo[0].data[0]=1.0;
    repo[0].data[1]=0.95;
    repo[0].data[2]=0.99;
    repo[0].data[3]=1.1;
    repo[0].data[4]=0.9;
    repo[0].result="PASS";
    repo[0].desc="test1";

    repo[1].DATASIZE=5;
    repo[1].data[0]=1.0;
    repo[1].data[1]=0.85;
    repo[1].data[2]=0.79;
    repo[1].data[3]=1.1;
    repo[1].data[4]=0.9;
    repo[1].result="FAIL";
    repo[1].desc="test2";

    calibReport->setDeviceInfo(dev);
    calibReport->generate(strList,"TEST");
    calibReport->insertData(repo[0]);
    calibReport->insertData(repo[1]);
    calibReport->write_odt("test.odt");
    calibReport->write_pdf("test.pdf");
    strList.clear();
}

void test_CalibReportInterface::on_pushButton_2_clicked()
{

    QStringList strList;
    strList << "Drive" << "Before" << "After" << "Max" << "Min" << "Result" << "Description";
    device dev;
    dev.modelNumber="PT6 QUTE ULTIMATE";
    dev.serialNumber="001";
    report repo;
    repo.DATASIZE=5;

    double l_nGain=0.0,l_nConstant=0.0;
    QFile *xmlFile;
    QXmlStreamReader *xmlReader;
    xmlFile = new QFile("CurrentCalibration.xml");
    if (!xmlFile->open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this,"Load XML File Problem",
                              "Couldn't open xmlfile.xml to load settings for download",
                              QMessageBox::Ok);
        return;
    }
    xmlReader = new QXmlStreamReader(xmlFile);

    int i=0;
    //Parse the XML until we reach end of it
    while(!xmlReader->atEnd() && !xmlReader->hasError()) {
        QXmlStreamReader::TokenType token = xmlReader->readNext();        // Read next element
        if(token == QXmlStreamReader::StartDocument) {        //If token is just StartDocument - go to next
            continue;
        }
        if(token == QXmlStreamReader::StartElement) {        //If token is StartElement - read it

//            qDebug()<<xmlReader->attributes();
//            qDebug()<<xmlReader->attributes();
//            qDebug()<<"Value:"<<xmlReader->attributes().value("Value");//.toString();
//            qDebug()<<"Slope:"<<xmlReader->attributes().value("Slope");//.toString();
//            qDebug()<<"Constant:"<<xmlReader->attributes().value("Constant");//.toString();
//
//            qDebug()<<"XCurrent:"<<scientific<<xmlReader->attributes().value("XCurrent");//.toString();
//            qDebug()<<"YCurrent:"<<scientific<<xmlReader->attributes().value("YCurrent");//.toString();
//            if(token == QXmlStreamReader::StartElement) {
//                qDebug()<<"XCurrent:"<<scientific<<xmlReader->attributes().value("XCurrent");//.toString();
//                qDebug()<<"YCurrent:"<<scientific<<xmlReader->attributes().value("YCurrent");//.toString();
//            }

//            QString value = xmlReader->attributes().value("Value").toString();
//            if(value.count())
//            {
//                l_nGain = xmlReader->attributes().value("Slope").toString().toDouble();
//                qDebug()<<"Gain:"<<l_nGain;
//                l_nConstant = xmlReader->attributes().value("Constant").toString().toDouble();
//                qDebug()<<"Constant:"<<l_nConstant;
//            }

        }
        i++;
    }

    if(xmlReader->hasError()) {
        QMessageBox::critical(this,
                              "xmlFile.xml Parse Error",xmlReader->errorString(),
                              QMessageBox::Ok);
        return;
    }
    //close reader and flush file
    xmlReader->clear();
    xmlFile->close();

}
