#include "qmaxmessagebox.h"

QmaxMessageBox::QmaxMessageBox(QWidget *parent) :
    QWidget(parent)
{
	msgBox = new QMessageBox(parent);
	msgBoxLive=false;

}
bool QmaxMessageBox::MessageBox(bool ok, bool cancel, QString text,QString okText = "Ok", QString calcelText = "Cancel",QWidget *parent) {

	qDebug() << "~~~~~~~~~~QMAX MESSAGE BOX~~~~~~~~~~~~~~~~~~~~~";

	msgBoxLive = true;
	if (ok == true) {
		connectButton = msgBox->addButton(okText, QMessageBox::YesRole);
		connectButton->setFont(QFont("DejaVu Sans", 20, 50, false));
	}
	if (cancel == true) {
		abortButton = msgBox->addButton(calcelText, QMessageBox::NoRole);
		abortButton->setFont(QFont("DejaVu Sans", 20, 50, false));
	}
	msgBox->setFont(QFont("DejaVu Sans", 15, 50, false));
	msgBox->setIcon(QMessageBox::Information);
	msgBox->setStyleSheet("color : white;background-color :rgb(88,88,87,255);");
	msgBox->setWindowIcon(QIcon(":/image.png"));
	msgBox->setText(text);
	msgBox->exec();
	if (msgBox->clickedButton() == connectButton)//(l_bTrue == true)//
	{
		qDebug()<<"connectButton Clicked";
		return true;
	}
	if (cancel == true)
		if (msgBox->clickedButton() == abortButton) //(l_bTrue == false) //
		{
			qDebug()<<"abortButton Clicked";
			return false;
		}
	msgBoxLive=false;
}
