#include "dialwidget.h"
#include "ui_dialwidget.h"

dialWidget::dialWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::dialWidget)
{
    ui->setupUi(this);
    m_objVoltageDial = new PotentioMeter(ui->grpVoltDiv);
    m_objVoltageDial->setGeometry(10,25,140,140);
}

dialWidget::~dialWidget()
{
    delete ui;
}

void dialWidget::changeEvent(QEvent *e)
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

void dialWidget::on_butClose_clicked()
{
    this->close();
}
