#include "messagewidget.h"
#include "qdebug.h"

MessageWidget::MessageWidget(QWidget *parent)
    : QWidget(parent)
{
	ui.setupUi(this);
	qDebug()<< "Message Loaded";
}

MessageWidget::~MessageWidget()
{

}

void MessageWidget::setText(QString pStr)
{
    ui.lblMsg->setText(pStr);
    qDebug()<< "Message Label";
}
