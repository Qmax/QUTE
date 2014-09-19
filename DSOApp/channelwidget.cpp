#include "channelwidget.h"
#include "ui_channelwidget.h"

ChannelWidget::ChannelWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChannelWidget)
{
    ui->setupUi(this);
}

ChannelWidget::~ChannelWidget()
{
    delete ui;
}

void ChannelWidget::changeEvent(QEvent *e)
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

void ChannelWidget::on_butClose_clicked()
{
    this->close();
}
