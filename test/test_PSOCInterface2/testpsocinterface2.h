#ifndef TESTPSOCINTERFACE2_H
#define TESTPSOCINTERFACE2_H

#include <QMainWindow>
#include <QPluginLoader>
#include "IPSOCCommunication.h"

namespace Ui {
    class testPSOCInterface2;
}

class testPSOCInterface2 : public QMainWindow {
    Q_OBJECT
public:
    testPSOCInterface2(QWidget *parent = 0);
    ~testPSOCInterface2();

protected:
    void changeEvent(QEvent *e);

    IPSOCCOMMUNICATION *IPsoc;  //PSOC Interface Plugin

private:
    Ui::testPSOCInterface2 *ui;

private slots:
    void on_readCodeID_clicked();
};

#endif // TESTPSOCINTERFACE2_H
