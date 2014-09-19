#include <InterfacePTLibrary.h>


void PTInterfaceObject::InitPTLibrary(QString pStrFileName,QString pStrWindowName)
{
    //qDebug()<< "InitPtLibrary";
    m_strFileName = pStrFileName;
    m_strWindowName = pStrWindowName;
    m_mapMainWindowMenus = new QMap<QString, QList<PT_MENU*> >();
    m_mapMainWindowMenus->clear();
    if(m_strWindowName == "MainWindow")
    {
        m_mapMainWindowMenus->insert("FunctionPanel",ReadPanel("FunctionPanel"));
        m_mapMainWindowMenus->insert("ApplicationPanel",ReadPanel("ApplicationPanel"));
        m_mapMainWindowMenus->insert("SettingsPanel",ReadPanel("SettingsPanel"));
        m_mapMainWindowMenus->insert("UtilitiesPanel",ReadPanel("UtilitiesPanel"));
        m_mapMainWindowMenus->insert("BottomPanel",ReadPanel("BottomPanel"));
    }
    if(m_strWindowName == "DMM")
    {
        m_mapMainWindowMenus->insert("MeasurmentPanel",ReadPanel("MeasurmentPanel"));
        m_mapMainWindowMenus->insert("DMMMainPanel",ReadPanel("DMMMainPanel"));
        m_mapMainWindowMenus->insert("ResistancePanel",ReadPanel("ResistancePanel"));
        m_mapMainWindowMenus->insert("DMMFunctionPanel",ReadPanel("DMMFunctionPanel"));
    }
    if(m_strWindowName == "FG")
    {
        m_mapMainWindowMenus->insert("FGFunctionPanel",ReadPanel("FGFunctionPanel"));
    }
    if(m_strWindowName == "ICM")
    {
        m_mapMainWindowMenus->insert("ICMMainPanel",ReadPanel("ICMMainPanel"));
        m_mapMainWindowMenus->insert("ICMMeasurePanel",ReadPanel("ICMMeasurePanel"));
    }
}

QList<PT_MENU*>PTInterfaceObject::ReadPanel(QString pStrPanelName)
{
    QList<PT_MENU*> l_lstWindowParmas;
    QFile *l_patternFile = new QFile(m_strFileName);
    if (!l_patternFile->open(QIODevice::ReadOnly | QIODevice::Text))
    {
        //QMessageBox::critical(this,"cISPReader::parseISCXML","Couldn't open ISC.xml",QMessageBox::Ok);
    }
    QXmlStreamReader xml(l_patternFile);
    QXmlStreamAttributes attributes;
    QString l_strKey="",l_strCommandName="";
    while(!xml.atEnd() &&  !xml.hasError())
    {
        QXmlStreamReader::TokenType token = xml.readNext();
        QString l_strName = xml.name().toString();
        if(token == QXmlStreamReader::StartDocument)
        {
            continue;
        }
        if(token == QXmlStreamReader::StartElement )
        {
        }

            l_strName = xml.name().toString();
            QString l_strPanelName = xml.attributes().value("Panel").toString();
            QString l_strWindowName = xml.attributes().value("Window").toString();
            if(xml.name().toString() =="ButtonName" && l_strPanelName == pStrPanelName && l_strWindowName == m_strWindowName)
            {
                   PT_MENU* l_objWindowParam = new PT_MENU();
                   l_objWindowParam->m_strButtonCaption = xml.attributes().value("Caption").toString();
                   l_objWindowParam->m_nXPos = xml.attributes().value("Xpos").toString().toDouble();
                   l_objWindowParam->m_nYPos = xml.attributes().value("Ypos").toString().toDouble();
                   l_objWindowParam->m_nHeight = xml.attributes().value("Height").toString().toInt();
                   l_objWindowParam->m_nWidth =  xml.attributes().value("Width").toString().toInt();
                   l_objWindowParam->m_strDescription = xml.attributes().value("Description").toString();
                   l_objWindowParam->m_strImageName = xml.attributes().value("Image").toString();
                   QString l_strType = xml.attributes().value("Type").toString();

                   l_lstWindowParmas.append(l_objWindowParam);
            }
        //}
    }
    l_patternFile->close();
    return l_lstWindowParmas;
}

NumberPanel* PTInterfaceObject::getNumKBPanel(short pValue, QWidget *parent)
{
    m_objNumberPanel = new NumberPanel(pValue,parent);
    return m_objNumberPanel;
}

NumberPanel* PTInterfaceObject::getNumKBPanelIncDec(short pValue, double incRatio, char type, double pMax, double pMin, QWidget *parent)
{
    m_objNumberPanel = new NumberPanel(pValue,incRatio,type,pMax,pMin,parent);
    return m_objNumberPanel;
}

MyLineEdit* PTInterfaceObject::getLineEdit(short pIndex, int x, int y, int w, int h, QString pTitle, QWidget *parent)
{
    m_objLineEdit = new MyLineEdit(pIndex,true,parent);
    m_objLineEdit->customGeometry(x,y,w,h,pTitle,parent);
    return m_objLineEdit;
}
MyLineEdit* PTInterfaceObject::QmaxLineEdit(short int pIndex,QWidget *parent)//Added by Ravivarman on 08-02-13
{
    m_objLineEdit = new MyLineEdit(pIndex,false,parent);
//    qDebug()<<"inside line edit interface";
    return m_objLineEdit;
}
bool PTInterfaceObject::QMsgBox(bool ok,bool cancel,QString text,QString okText = "Ok", QString calcelText = "Cancel",QWidget *parent){
	m_objMsgBox=new QmaxMessageBox(parent);
	return m_objMsgBox->MessageBox(ok,cancel,text,okText,calcelText,parent);
}
QPushButton* PTInterfaceObject::GetAbortButton(){
	return m_objMsgBox->getAbortButton();
}
QPushButton* PTInterfaceObject::GetConnectButton(){
	return m_objMsgBox->getConnectButton();
}
bool PTInterfaceObject::GetmsgBoxLiveStatus(){
	return m_objMsgBox->getmsgBoxLiveStatus();
}
void PTInterfaceObject::SetmsgBoxLiveStatus(bool val){
	m_objMsgBox->setmsgBoxLiveStatus(val);
}
void PTInterfaceObject::CloseMsgBox(){
	m_objMsgBox->closeMessageBox();
}
QT_BEGIN_NAMESPACE
Q_EXPORT_PLUGIN2(pnp_basictools, PTInterfaceObject)
QT_END_NAMESPACE





