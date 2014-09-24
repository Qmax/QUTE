#ifndef TOOLBOX_H
#define TOOLBOX_H

#include <QMessageBox>
#include <qdebug.h>
#include <QWSServer>
#include <QProcess>
#include <QProcessEnvironment>
#include <QWidget>
#include <QDate>
#include <qmessagebox.h>
#include <QDesktopWidget>
#include <QPropertyAnimation>
#include "PTTestjigInterface.h"
#include "logindialog.h"
#include "datetime.h"
namespace Ui {
    class ToolBox;
}

class ToolBox : public QWidget {
    Q_OBJECT
public:
    ToolBox(QWidget *parent = 0);
    ~ToolBox();

protected:
    void changeEvent(QEvent *e);
    IPTTestjigInterface *testJig;

    LoginDialog* loginDialog;
    bool m_nPassword;
    bool m_bCursor;

private:
    Ui::ToolBox *ui;

private slots:
        void on_pb_curEnDis_clicked();
        void on_pb_exit_clicked();
 void slotAcceptUserLogin(QString& name,QString& password);

    void on_pb_datetime_clicked();
    void on_pb_touchcalib_clicked();
    void on_pb_selftest_clicked();
    void on_pb_testjig_clicked();
};

#endif // TOOLBOX_H
