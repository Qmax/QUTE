
#ifndef TEST_CALIBREPORTINTERFACE_H
#define TEST_CALIBREPORTINTERFACE_H

#include <QtGui/QWidget>
#include <QPluginLoader>
#include "ui_test_calibreportinterface.h"
#include "CalibReportInterface.h"

class test_CalibReportInterface : public QWidget
{
    Q_OBJECT

public:
    test_CalibReportInterface(QWidget *parent = 0);
    ~test_CalibReportInterface();
protected:
    CalibReportInterface *calibReport;
private:
    Ui::test_CalibReportInterfaceClass ui;

private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
};

#endif // TEST_CALIBREPORTINTERFACE_H
