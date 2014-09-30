

#ifndef PORTABLETESTERTESTJIG2_H
#define PORTABLETESTERTESTJIG2_H

#include <QtGui/QWidget>
#include "ui_portabletestertestjig2.h"
#include <qobject.h>
#include <qpluginloader.h>
#include <qlineedit.h>

#include "AWGTestJigInterface.h"
#include "DMMTestJigInterface.h"
#include "ICMTestJigInterface.h"
#include "VITestJigInterface.h"
#include "FMTestJigInterface.h"
#include "ACRTestJigInterface.h"
#include "PSoCTestJigInterface2.h"
#include "KeyKnobTestJigInterface.h"
#include "ViewerTestJigInterface.h"
#include "DDSTestJigInterface.h"
#include "PWFTestJigInterface.h"
#include "HACADCTestJigInterface.h"
#include "APPRXDRVTestJigInterface.h"
#include "AD5318TestJigInterface.h"
#include "RAMTestJigInterface.h"
#include "AD9102TestJigInterface.h"
#include "logindialog.h"
//pdf viewer
//#include "documentwidget.h"
#include <QFileDialog>
#include <QMessageBox>


class PortableTesterTestJig2 : public QWidget
{
    Q_OBJECT

public:
    PortableTesterTestJig2(QWidget *parent = 0);
    ~PortableTesterTestJig2();

    IAWGTestJigInterface *AWGUI;
    IDMMTestJigInterface *DMMSLGUI;
    IICMTestJigInterface *ICMGUI;
    IVITestJigInterface *VIGUI;
    IFMTestJigInterface *FMGUI;
    IACRTestJigInterface *ACRUI;
    IPSOCTestJigInterface2 *PSOCUI;
    IKeyKnobTestJigInterface *KPKBBLUI;
    IViewerTestJigInterface *VIEWER;
    IDDSTestJigInterface *DDS;
    IPWFTestJigInterface *PWF;
    IHACADCTestJigInterface *HAADC;
    IAPPRXDRVTestJigInterface *APPDRVRX;
    IAD5318TestJigInterface *AD5318;
    IRAMTestJigInterface *RAMData;
    IAD9102TestJigInterface *AD9102;

protected:
    int currentIndex;
    bool m_bAPPDRVRECEUI;
    bool m_bICMVI;
    bool m_bADCUI;
    bool m_bDDSUI;
    bool m_nPassword;
private:
    Ui::PortableTesterTestJig2Class ui;

    //pdf viewer
//    DocumentWidget *documentWidget;
    QString lastPath;
    QVector<qreal> scaleFactors;

private slots:
    void slotAcceptUserLogin(QString& name,QString& password);
//    void on_pushButton_clicked();
//    void on_pushButton_5_clicked();
//    void on_pushButton_4_clicked();
//    void on_pushButton_3_clicked();
//    void on_pushButton_2_clicked();
    void checkIndex(int );

    //pdf viewer
//    void setPageValue();
//    void openFile();
//    void scaleDocument(int index);
};

#endif // PORTABLETESTERTESTJIG2_H
