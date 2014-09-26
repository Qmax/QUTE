#ifndef DISPLAY_H
#define DISPLAY_H

#include <QDebug>
#include <QFrame>
#include <QLabel>
#include <QWidget>
#include <math.h>
#include <limits.h>
#include <assert.h>

class DISPLAY: public QFrame {

Q_OBJECT

protected:

	QLabel *digits[6];
	QLabel *dpoint[9];
	QLabel *sign;
	short noOfDigits;
	int m_intRange;

public:
	void initialize() {
		setStyleSheet(
				"QFrame{ border:1px solid black; border-radius:0px; background-color:black;color:yellow;}");

		sign = new QLabel(this);
		sign->setStyleSheet(
				"QLabel{border:0px solid black;border-radius:0px;background-color:black;color:#fbec5d;}");
		sign->setFont(QFont("DejaVu Sans", 85, 50, false));
		sign->setAlignment(Qt::AlignHCenter);
		sign->setAlignment(Qt::AlignVCenter);
		sign->setGeometry(20, 3, 30, 80);
		sign->setText("-");
		sign->setVisible(false);

		for (short i = 0; i < noOfDigits; i++) {
			digits[i] = new QLabel(this);
			digits[i]->setStyleSheet(
					"QLabel{border:0px solid white;border-radius:0px;background-color:black;color:#fbec5d;}");
			digits[i]->setFont(QFont("DejaVu Sans", 85, 50, false));
			digits[i]->setAlignment(Qt::AlignHCenter);
		}
		//    for(short i=0;i<(noOfDigits-1);i++){
		//           dpoint[i]=new QLabel(this);
		//           dpoint[i]->setStyleSheet("QLabel{border:0px solid black; border-radius:5px;background-color:#fbec5d;}");
		//           dpoint[i]->setFont(QFont("DejaVu Sans", 15, 50, false));
		//           dpoint[i]->setAlignment(Qt::AlignHCenter);
		//
		//       }
		//        selectDPoint(-1);
		m_intRange = 1;
	}

	void setXYWH() {
		for (short i = 0; i < noOfDigits; i++) {
			digits[i]->setGeometry((i + 1) * 50, 3, 50, 80);
		}
		//        for(short i=0;i<(noOfDigits-1);i++){
		//            dpoint[i]->setGeometry(((i+1)*50)+45,60,10,10);
		//        }

	}
	void selectGeometry(int x, int y) {
		setGeometry(x, y, 350, 90);
	}
	//    void selectDPoint(short dpno){
	//        for(short i=0;i<(noOfDigits-1);i++){
	//            if(i==dpno)
	//                dpoint[i]->setVisible(true);
	//            else
	//                dpoint[i]->setVisible(false);
	//        }
	//    }
	void setRange(int pRange) {
		m_intRange = pRange;
	}
	void setNoOfDigits(short no) {
		noOfDigits = no;
	}

	DISPLAY(QWidget * parent) {

		setParent(parent);
		setNoOfDigits(6);
		initialize();
		setXYWH();
	}
	void setValue(double l_nValue) {
		qDebug() << "display.h:\tDATA:" << l_nValue<<"\tRANGE:"<<m_intRange;

		QString l_strDecimelValue;
		QString Inf=QChar(0x221E);
		int l_intValue=0, Q=0, R=0;
		double l_nDecimelValue = 0;

	    if (l_nValue !=l_nValue){
	    	setValue("Err");
		}
/*	    else if (value > std::numeric_limits<qreal>::max()){
	    	setValue("+"+Inf);
	    }
	    else if (value < -std::numeric_limits<qreal>::max()){
	    	return "-"+Inf;
	    }*/
		else
		{
			if (l_nValue < 0){
				l_nValue = fabs(l_nValue);
				sign->setVisible(true);
			}else{
				sign->setVisible(false);
			}
//			qDebug()<<"after fabs:"<<l_intValue<<"\t"<<l_nValue;;
			for (int i = 0; i < 6; i++) {
				digits[i]->setText("0");
			}

/*			if (l_nValue != 0)
				l_intValue = floor(l_nValue);
			else if(l_nValue==0)
				l_intValue=0;*/
//			l_intValue  = ((l_nValue >= 0) ? (int)(l_nValue + 0.5) : (int)(l_nValue - 0.5));
//			l_intValue = qRound(l_nValue);
			l_intValue = int(l_nValue);
//			qDebug()<<"after qRound:"<<l_intValue<<"\t"<<l_nValue;
//_________________________________________________________________________________________
			if (m_intRange == 3) {
				if (l_nValue > 3.1)
					setValue("OL");
				else {
					digits[0]->setText(QString::number(l_intValue, 10));
					digits[1]->setText(".");

					l_nDecimelValue = l_nValue - (double)l_intValue;
					l_strDecimelValue = QString::number(fabs(l_nDecimelValue),'f',10);

					//qDebug() << "1-l_strDecimelValue->" << l_strDecimelValue;

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
			else if (m_intRange == 5) {
				if (l_nValue >5.1)
					setValue("OL");
				else {
					digits[0]->setText(QString::number(l_intValue, 10));
					digits[1]->setText(".");
					l_nDecimelValue = l_nValue - (double)l_intValue;
					l_strDecimelValue = QString::number(fabs(l_nDecimelValue),'f',10);
					//qDebug() << "1-l_strDecimelValue->" << l_strDecimelValue;

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
			else if (m_intRange == 50) {
				if (l_nValue >51)
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
			else if (m_intRange == 500) {
				if (l_nValue >510)
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
					////qDebug() << "3-l_strDecimelValue->" << l_strDecimelValue;

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
//_________________________________________________________________________________________
			else if (m_intRange == 750) {
				if (l_nValue >760)
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
//_________________________________________________________________________________________
			else if (m_intRange ==1000) {
				if (l_nValue > 1100)
					setValue("OL");
				else {
					Q = l_intValue / 1000;
					R = l_intValue % 1000;
					digits[0]->setText(QString::number(Q, 10));

					Q = R / 100;
					R = R % 100;
					digits[1]->setText(QString::number(Q, 10));

					Q = R / 10;
					R = R % 10;
					digits[2]->setText(QString::number(Q, 10));

					digits[3]->setText(QString::number(R, 10));
					digits[4]->setText(".");

					l_nDecimelValue = l_nValue - (double)l_intValue;
					l_strDecimelValue = QString::number(fabs(l_nDecimelValue),'f',10);
					//qDebug() << "4-l_strDecimelValue->" << l_strDecimelValue;

					if (l_strDecimelValue.length() >= 3)
						digits[5]->setText(l_strDecimelValue.at(2));
					else
						digits[5]->setText("0");

				}
			}
		}
	}
	void setValueOld(double value) {

		QString strValue = QString::number(value);
		//qDebug() << "Inside display.h-->Received Data:" << strValue;
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
	void setValue(QString strValue) {
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

	~DISPLAY() {
	}

};
#endif // DISPLAY_H
