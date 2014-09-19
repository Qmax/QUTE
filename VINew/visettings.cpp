#include "visettings.h"
#include <qpluginloader.h>

VISettings::VISettings(QWidget *parent)
    : QWidget(parent)
{
	ui.setupUi(this);
	setWindowModality(Qt::WindowModal);
    QPluginLoader loader4("libQmaxPTInterface.so",this);
    INumberPanel=qobject_cast<IQmaxNumberPanel*>(loader4.instance());
    ILineEdit = qobject_cast<IQmaxLineEdit*> (loader4.instance());
    m_objTicksEdit = ILineEdit->QmaxLineEdit(0,ui.grpTicks);
    m_objTicksEdit->setGeometry(109,26,71,51);
    m_objTicksEdit->setText("0");
    connect(m_objTicksEdit,SIGNAL(focussed(bool)),this,SLOT(callTicksEdit()));
    m_nTick=0;
    readVISettings();
}

void VISettings::callTicksEdit()
{
    if(m_objTicksEdit->hasFocus())
    {
    		openNumKBPanel(2);
            m_nLineEditIndex = 0;
    }
}

void VISettings::readVISettings()
{
	QString l_strFilename;
	l_strFilename="VISettings.xml";
	QFile *xmlFile= new QFile(l_strFilename);
	if (!xmlFile->open(QIODevice::ReadOnly | QIODevice::Text)) {
		// qDebug()<<"Settings Calibration file read error";
	}
	QXmlStreamReader xml(xmlFile);
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
			if(xml.name() == "TickValue")
			{
				m_objTicksEdit->setText(l_strValue);
			}
		}
	}
	//qDebug()<<"TickValue:"<<m_nTickValue;
}

void VISettings::on_butOK_clicked()
{
	saveSettingsXML();
	this->close();
}

void VISettings::saveSettingsXML()
{
    QString l_strFileName;
    l_strFileName = "./VISettings.xml";

    QFile *file = new QFile(l_strFileName);
    if (!file->open(QIODevice::WriteOnly | QIODevice::Text)) {
            return;
    }
    QXmlStreamWriter objCalibration(file);

    objCalibration.setAutoFormatting(true);
    objCalibration.writeStartDocument();

    objCalibration.writeStartElement("VISettings");
	objCalibration.writeStartElement("TickValue");
	objCalibration.writeAttribute("Value", QString::number(m_nTick,10));
    objCalibration.writeEndElement();
    objCalibration.writeEndDocument();
    file->close();

}

void VISettings::receiveValue(unsigned int pValue)
{
	m_objTicksEdit->setText(QString::number(pValue,10));
	m_nTick = pValue;
}


VISettings::~VISettings()
{

}
void VISettings::openNumKBPanel(short int pValue)
{
//    typedef QWidget* (*pf2)(short int,QWidget*);
//    pf2 getNumKBPanel = (pf2)m_objPTLibrary->resolve("getNumKBPanel");
    QWidget *w = INumberPanel->getNumKBPanel(pValue,this);
    w->setWindowFlags(Qt::WindowCloseButtonHint|Qt::Dialog);
    w->show();
}
