/*
 *      Author: Ravivarman.R,Qmax
 */
#ifndef DISPLAY_H
#define DISPLAY_H

#include <QDebug>
#include <QFrame>
#include <QLabel>
#include <QWidget>
#include <math.h>
#include <limits.h>
#include <assert.h>

class DISPLAY:public QFrame{

    Q_OBJECT

protected:

    QLabel *digits[6];
    QLabel *dpoint[9];
    QLabel *sign;
    short noOfDigits;
	int m_intRange;

public:
    void initialize(){
    setStyleSheet("QFrame{ border:1px solid black; border-radius:0px; background-color:black;color:yellow;}");


    sign=new QLabel(this);
    sign->setStyleSheet("QLabel{border:0px solid black;border-radius:0px;background-color:black;color:#fbec5d;}");
    sign->setFont(QFont("DejaVu Sans", 85, 50, false));
    sign->setAlignment(Qt::AlignHCenter);
    sign->setAlignment(Qt::AlignVCenter);
    sign->setGeometry(20,3,30,80);
    sign->setText("-");
    sign->setVisible(false);

    for(short i=0;i<noOfDigits;i++){
            digits[i]=new QLabel(this);
            digits[i]->setStyleSheet("QLabel{border:0px solid white;border-radius:0px;background-color:black;color:#fbec5d;}");
            digits[i]->setFont(QFont("DejaVu Sans", 85, 50, false));
            digits[i]->setAlignment(Qt::AlignHCenter);
        }
	m_intRange = 1;
    }

    void setXYWH(){
        for(short i=0;i<noOfDigits;i++){
            digits[i]->setGeometry((i+1)*50,3,50,80);
        }
    }
    void selectGeometry(int x,int y){
        setGeometry(x,y,350,90);
    }
	void setRange(int pRange) {
		m_intRange = pRange;
	}
    void setNoOfDigits(short no){
        noOfDigits=no;
    }

    DISPLAY(QWidget * parent){

        setParent(parent);
        setNoOfDigits(6);
        initialize();
        setXYWH();
    }

    void setValue(double l_nValue){

        qDebug() << "display.h-Range:"<<m_intRange<<"Data:" << l_nValue;

		QString l_strDecimelValue;
		QString Inf=QChar(0x221E);
		int l_intValue=0, Q=0, R=0;
		double l_nDecimelValue = 0;

	    if (l_nValue !=l_nValue){
	    	setValue("Err");
		}
		else
		{
			if (l_nValue < 0){
				l_nValue = fabs(l_nValue);
				sign->setVisible(true);
			}else{
				sign->setVisible(false);
			}
			for (int i = 0; i < 6; i++) {
				digits[i]->setText("0");
			}
			l_intValue = int(l_nValue);
			qDebug()<<"After Rounding:"<<l_intValue;
//_________________________________________________________________________________________
			if (m_intRange == 1 || m_intRange == 3 ||m_intRange == 5 || m_intRange == 9) {
				if (m_intRange==1 &&l_nValue > 1)
					setValue("OL");
				else if (m_intRange==3 &&l_nValue > 3)
					setValue("OL");
				else if (m_intRange==5 &&l_nValue > 5)
					setValue("OL");
                                else if (m_intRange==9 &&l_nValue > 9.9)
					setValue("OL");
				else {
					digits[0]->setText(QString::number(l_intValue, 10));
					digits[1]->setText(".");

					l_nDecimelValue = l_nValue - (double)l_intValue;
					l_strDecimelValue = QString::number(fabs(l_nDecimelValue),'f',10);

//					qDebug() << "1-l_strDecimelValue->" << l_strDecimelValue;

					if (l_strDecimelValue.length() >= 3)
						digits[2]->setText(l_strDecimelValue.at(2));
					else
						digits[2]->setText("0");

					if (l_strDecimelValue.length() >= 4)
						digits[3]->setText(l_strDecimelValue.at(3));
					else
						digits[3]->setText("0");

					if (l_strDecimelValue.length() >= 5)
						digits[4]->setText(l_strDecimelValue.at(4));
					else
						digits[4]->setText("0");

					if (l_strDecimelValue.length() >= 6)
						digits[5]->setText(l_strDecimelValue.at(5));
					else
						digits[5]->setText("0");

				}
			}
//_________________________________________________________________________________________
			else if (m_intRange == 10 || m_intRange == 30 || m_intRange == 99) {
				if (m_intRange==10 && l_nValue >10)
					setValue("OL");
				else if (m_intRange==30 && l_nValue >30)
					setValue("OL");
                                else if (m_intRange==99 && l_nValue >99.9)
					setValue("OL");
				else {
					Q = l_intValue / 10;
					R = l_intValue % 10;
					digits[0]->setText(QString::number(Q, 10));
					digits[1]->setText(QString::number(R, 10));
					digits[2]->setText(".");

					l_nDecimelValue = l_nValue - (double)l_intValue;
					l_strDecimelValue = QString::number(fabs(l_nDecimelValue),'f',10);
                                        //qDebug() << "2-l_strDecimelValue->" << l_strDecimelValue;

					if (l_strDecimelValue.length() >= 3)
						digits[3]->setText(l_strDecimelValue.at(2));
					else
						digits[3]->setText("0");

					if (l_strDecimelValue.length() >= 4)
						digits[4]->setText(l_strDecimelValue.at(3));
					else
						digits[4]->setText("0");

					if (l_strDecimelValue.length() >= 5)
						digits[5]->setText(l_strDecimelValue.at(4));
					else
						digits[5]->setText("0");

				}
			}
//_________________________________________________________________________________________
			else if (m_intRange == 100 ||m_intRange == 300||m_intRange == 999) {
				if (m_intRange == 100 && l_nValue >100)
					setValue("OL");
				else if (m_intRange == 300 && l_nValue >300)
					setValue("OL");
                                else if (m_intRange == 999 && l_nValue >999.9)
					setValue("OL");
				else {
					Q = l_intValue / 100;
					R = l_intValue % 100;
					digits[0]->setText(QString::number(Q, 10));

					Q = R / 10;
					R = R % 10;
					digits[1]->setText(QString::number(Q, 10));

					digits[2]->setText(QString::number(R, 10));
					digits[3]->setText(".");

					l_nDecimelValue = l_nValue - (double)l_intValue;
					l_strDecimelValue = QString::number(fabs(l_nDecimelValue),'f',10);
                                        //qDebug() << "3-l_strDecimelValue->" << l_strDecimelValue;

					if (l_strDecimelValue.length() >= 3)
						digits[4]->setText(l_strDecimelValue.at(2));
					else
						digits[4]->setText("0");

					if (l_strDecimelValue.length() >= 4)
						digits[5]->setText(l_strDecimelValue.at(3));
					else
						digits[5]->setText("0");

				}
			}
		}
    }
    void setValue(QString strValue){
    //qDebug() << "display.h(str)-Data:" << strValue;
		int signIndex = strValue.indexOf("-");
		if (signIndex != -1) {
			strValue = strValue.remove("-");
			sign->setVisible(true);
		} else {
			sign->setVisible(false);
		}
		int count = strValue.count();
		if (count > 6)
			count = 6;
		for (short i = 0; i < 6; i++)
			if (i < count)
				digits[i]->setText(QString(strValue[i]));
			else
				digits[i]->setText(" ");
    }


    ~DISPLAY(){}

};
#endif // DISPLAY_H
