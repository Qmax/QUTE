#include "offsetwindow.h"

OffsetWindow::OffsetWindow(QWidget *parent)
    : QWidget(parent)
{
	ui.setupUi(this);
}

OffsetWindow::~OffsetWindow()
{

}

void OffsetWindow::on_m_rbDACA_clicked()
{
	m_nSelectedDACIndex =0;
	ui.dblDACSpin->setMinimum(0.0);
	ui.dblDACSpin->setMaximum(2.5);
	ui.dblDACSpin->setSingleStep(0.1);
}

void OffsetWindow::on_m_rbDACB_clicked()
{
	m_nSelectedDACIndex =1;

}

void OffsetWindow::on_m_rbDACC_clicked()
{
	m_nSelectedDACIndex =2;
	ui.dblDACSpin->setMinimum(0.0);
	ui.dblDACSpin->setMaximum(2.5);
	ui.dblDACSpin->setSingleStep(0.1);
}
void OffsetWindow::on_m_rbDACD_clicked()
{
	m_nSelectedDACIndex =3;

}
void OffsetWindow::on_m_rbDACE_clicked()
{
	m_nSelectedDACIndex =4;
}

void OffsetWindow::on_dblDACSpin_valueChanged(double pValue)
{
//	if(ui.m_rbDACA->isChecked()){
//		m_nSelectedDACIndex =0;
//	}
//	else if(ui.m_rbDACB->isChecked()){
//		m_nSelectedDACIndex =1;
//	}
//	else if(ui.m_rbDACC->isChecked())
//	{
//		m_nSelectedDACIndex =2;
//	}
//	else if(ui.m_rbDACD->isChecked())
//	{
//		m_nSelectedDACIndex =3;
//	}
//	else if(ui.m_rbDACE->isChecked())
//	{
//		m_nSelectedDACIndex =4;
//	}
	qDebug()<<"Selected DAC:"<<m_nSelectedDACIndex<<"Value:"<<pValue;
	emit passDACValue(m_nSelectedDACIndex,pValue);
}
