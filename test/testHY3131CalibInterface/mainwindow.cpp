#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPropertyAnimation>
#include <QPluginLoader>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPluginLoader loaderGeneral("libHY3131CalibInterface.so", this);
    calib = qobject_cast<IHY3131CalibInterface*> (loaderGeneral.instance());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::on_pushButton_clicked()
{
        QWidget *newWidget=new QWidget(this);
        newWidget=calib->getCALIB();
        newWidget->setWindowTitle("General Calibration Panel");
        newWidget->show();
}
