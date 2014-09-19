// -------------------------------------------------
// Project created by Ravivarman.R 2014-09-09T14:08:47
// -------------------------------------------------
#include "testdigrapher.h"
#include "ui_testdigrapher.h"

TestDIGrapher::TestDIGrapher(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TestDIGrapher)
{
    ui->setupUi(this);

    QStringList lst;
    lst.append("Max Value");
    lst.append("Min Value");
    lst.append("Measured Value");


    QPluginLoader testing("libDIGrapher.so", this);
    test = qobject_cast<DIGrapherInterface*> (testing.instance());
    QWidget *newWidget = test->getDIGraph();
    test->setZoomInGraphGeometry(10,202,693,392);
    test->setZoomOutGraphGeometry(10,434,693,160);
    test->setGraphCount(3);
//    test->setGraphTitle(lst);
    test->setLegendVisible(false);
    test->setupGraphWindow();
    newWidget->setParent(this);
    newWidget->show();
    test->setGraphGeometry(10,434,693,160);


    // generate ideal sinc curve data and some randomly perturbed data for scatter plot:
     QVector<double> x0(250), y0(250);
     QVector<double> yConfUpper(250), yConfLower(250);
     for (int i=0; i<250; ++i)
     {
       x0[i] = (i/249.0-0.5)*30+0.01; // by adding a small offset we make sure not do divide by zero in next code line
       y0[i] = sin(x0[i])/x0[i]; // sinc function
       yConfUpper[i] = y0[i]+0.15;
       yConfLower[i] = y0[i]-0.15;
       x0[i] *= 1000;
     }
     QVector<double> x1(50), y1(50), y1err(50);
     for (int i=0; i<50; ++i)
     {
       // generate a gaussian distributed random number:
       double tmp1 = rand()/(double)RAND_MAX;
       double tmp2 = rand()/(double)RAND_MAX;
       double r = sqrt(-2*log(tmp1))*cos(2*M_PI*tmp2); // box-muller transform for gaussian distribution
       // set y1 to value of y0 plus a random gaussian pertubation:
       x1[i] = (i/50.0-0.5)*30+0.25;
       y1[i] = sin(x1[i])/x1[i]+r*0.15;
       x1[i] *= 1000;
       y1err[i] = 0.15;
     }
    test->setGraphRange("time",-15000,15000,"Resistance",-0.4,1.2);
    test->setGraphData(0,x0,y0);
    test->setGraphData(1,x0,yConfUpper);
    test->setGraphData(2,x0,yConfLower);
    test->plotGraphWindow();
}

TestDIGrapher::~TestDIGrapher()
{
    delete ui;
}

void TestDIGrapher::changeEvent(QEvent *e)
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
