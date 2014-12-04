#include "mainwindow.h"
#include <qpushbutton.h>

#include <QtCore/QCoreApplication>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    m_pWebView = new QWebView(this);
    //set position and size
    m_pWebView->setGeometry(0,0,800,570);
    m_pWebView->load(QUrl("doc/html/index.html"));
//    m_pWebView->load(QUrl("pt6-trial/AboutPT6.html"));
    setGeometry(0,0,800,600);

    QPushButton *closeBut = new QPushButton(this);
    closeBut->setGeometry(700,571,96,28);
    closeBut->setText("CLOSE");
    connect(closeBut,SIGNAL(clicked()),this,SLOT(close()));
}

MainWindow::~MainWindow()
{

}
