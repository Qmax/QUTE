#include "probestatus.h"
#include "ui_probestatus.h"

ProbeStatus::ProbeStatus(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProbeStatus)
{
    ui->setupUi(this);
    //setGeometry(20,450,600,120);
}

ProbeStatus::~ProbeStatus()
{
    painter = NULL;
    delete ui;

}

void ProbeStatus::changeEvent(QEvent *e)
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

void ProbeStatus::paintEvent(QPaintEvent *)
{
    painter = new QPainter(this);

    painter->setRenderHint(QPainter::Antialiasing);
    QPen pen(Qt::black);

    pen.setWidth(2);
    painter->setPen(pen);

    // Channel Draw
    painter->drawEllipse(50,20,40,40);
    painter->drawEllipse(55,25,30,30);
    painter->drawEllipse(50,70,40,40);
    painter->drawEllipse(55,75,30,30);
    // Probe Draw
    pen.setColor(Qt::black);
    pen.setWidth(3);
    painter->drawEllipse(160,20,40,40);
    painter->drawEllipse(220,20,40,40);
    pen.setColor(Qt::darkRed);
    pen.setWidth(6);
    painter->setPen(pen);
    painter->drawEllipse(165,25,30,30);
    painter->drawEllipse(225,25,30,30);

    pen.setColor(Qt::black);
    pen.setWidth(3);
    painter->setPen(pen);
    painter->drawEllipse(160,70,40,40);
    painter->drawEllipse(220,70,40,40);
    pen.setColor(Qt::darkRed);
    pen.setWidth(6);
    painter->setPen(pen);
    painter->drawEllipse(165,75,30,30);
    painter->drawEllipse(225,75,30,30);
}

void ProbeStatus::on_toolButton_clicked()
{
    this->setGeometry(0,0,48,120);
}
