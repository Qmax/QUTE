// -------------------------------------------------
// Project created by Ravivarman.R 2014-09-09T14:08:47
// -------------------------------------------------
#ifndef TESTDIGRAPHER_H
#define TESTDIGRAPHER_H

#include <QMainWindow>
#include <DIGrapherInterface.h>

namespace Ui {
    class TestDIGrapher;
}

class TestDIGrapher : public QMainWindow {
    Q_OBJECT
public:
    TestDIGrapher(QWidget *parent = 0);
    ~TestDIGrapher();

protected:
    void changeEvent(QEvent *e);

    DIGrapherInterface *test;


private:
    Ui::TestDIGrapher *ui;
};

#endif // TESTDIGRAPHER_H
