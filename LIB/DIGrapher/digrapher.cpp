// -------------------------------------------------
// Project created by Ravivarman.R 2014-09-09T14:08:47
// -------------------------------------------------
#include "digrapher.h"
#include "ui_digrapher.h"

DIGrapher::DIGrapher(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DIGrapher)
{
    ui->setupUi(this);
    ui->plotter->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectAxes |QCP::iSelectLegend | QCP::iSelectPlottables);
    ui->ZoomOut->setVisible(false);
    ui->ZoomIn->setVisible(true);
}
void DIGrapher::setGraphGeometry(int x,int y,int w,int h){
    setGeometry(x,y,w,h);
}
void DIGrapher::setupGraphWindow(){
    setup(ui->plotter);
}
void DIGrapher::setup(QCustomPlot *customPlot){

    QPen pen[m_nGraphCount];

    customPlot->legend->setVisible(m_bLegendState);
    customPlot->legend->setFont(QFont("Helvetica",9));
    customPlot->setLocale(QLocale(QLocale::English, QLocale::India));
    customPlot->setBackground(QColor(212,208,197) );

    for(int i=0;i<m_nGraphCount;i++){
        if((i==1)|(i==2)){
            pen[i].setStyle(Qt::DotLine);
            pen[i].setWidth(1);
            pen[i].setColor(Qt::black);
        }
        if(i==0){
            pen[i].setStyle(Qt::SolidLine);
            pen[i].setWidth(2);
            pen[i].setColor(Qt::blue);
        }
        customPlot->addGraph();
        customPlot->graph(i)->setName(m_strGraphTitle.value(i));
        customPlot->graph(i)->setPen(pen[i]);
    }
}
void DIGrapher::plotGraphWindow(){
    plot(ui->plotter);
}

void DIGrapher::plot(QCustomPlot *customPlot){
    customPlot->xAxis->setLabel(xName);
    customPlot->yAxis->setLabel(yName);
    customPlot->xAxis->setRange(xLRange,xHRange);
    customPlot->yAxis->setRange(yLRange,yHRange);

    for(int i=0;i<m_nGraphCount;i++){
        customPlot->graph(i)->setData(xData[i],yData[i]);
//        customPlot->rescaleAxes();
    }
    customPlot->replot();
}

DIGrapher::~DIGrapher()
{
    delete ui;
}

void DIGrapher::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void DIGrapher::on_ZoomOut_clicked()
{
    QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry");
    animation->setEasingCurve(QEasingCurve::OutCubic);
    animation->setDuration(300);
    animation->setStartValue(QRect(geometry().x(),geometry().y(),geometry().width(),geometry().height()));
    animation->setEndValue(QRect(zoX,zoY,zoW,zoH));
    animation->start();
    ui->ZoomOut->setVisible(false);
    ui->ZoomIn->setVisible(true);
}

void DIGrapher::on_ZoomIn_clicked()
{
    QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry");
    animation->setEasingCurve(QEasingCurve::InCubic);
    animation->setDuration(300);
    animation->setStartValue(QRect(geometry().x(),geometry().y(),geometry().width(),geometry().height()));
    animation->setEndValue(QRect(ziX,ziY,ziW,ziH));
    animation->start();
    ui->ZoomOut->setVisible(true);
    ui->ZoomIn->setVisible(false);
}

void DIGrapher::on_Refresh_clicked()
{
	ui->plotter->rescaleAxes(true);
	ui->plotter->replot();
}
