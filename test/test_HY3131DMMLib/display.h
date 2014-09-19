#ifndef DISPLAY_H
#define DISPLAY_H

#include <QDebug>
#include <QFrame>
#include <QLabel>
#include <QWidget>

class DISPLAY:public QFrame{

    Q_OBJECT

protected:

    QLabel *digits[10];
    QLabel *dpoint[9];
    QLabel *sign;
    short noOfDigits;

public:
    void initialize(){
    setStyleSheet("QFrame{ border:1px solid black; border-radius:0px; background-color:black;color:yellow;}");

    sign=new QLabel(this);
    sign->setStyleSheet("QLabel{border:0px solid black;border-radius:0px;background-color:black;color:#fbec5d;}");
    sign->setFont(QFont("DejaVu Sans", 50, 50, false));
    sign->setAlignment(Qt::AlignHCenter);
    sign->setAlignment(Qt::AlignVCenter);
    sign->setGeometry(20,3,30,80);
    sign->setText("-");
    sign->setVisible(false);

    for(short i=0;i<noOfDigits;i++){
            digits[i]=new QLabel(this);
            digits[i]->setStyleSheet("QLabel{border:0px solid white;border-radius:0px;background-color:black;color:#fbec5d;}");
            digits[i]->setFont(QFont("DejaVu Sans", 50, 50, false));
            digits[i]->setAlignment(Qt::AlignHCenter);
        }
    for(short i=0;i<(noOfDigits-1);i++){
           dpoint[i]=new QLabel(this);
           dpoint[i]->setStyleSheet("QLabel{border:0px solid black; border-radius:5px;background-color:#fbec5d;}");
           dpoint[i]->setFont(QFont("DejaVu Sans", 15, 50, false));
           dpoint[i]->setAlignment(Qt::AlignHCenter);

       }
        selectDPoint(-1);
    }

    void setXYWH(){
        for(short i=0;i<noOfDigits;i++){
            digits[i]->setGeometry((i+1)*50,3,50,80);
//            digits[i]->setText("8");
        }
        for(short i=0;i<(noOfDigits-1);i++){
            dpoint[i]->setGeometry(((i+1)*50)+45,60,10,10);
        }

    }
    void selectGeometry(int x,int y){
        setGeometry(x,y,350,90);
    }
    void selectDPoint(short dpno){
        for(short i=0;i<(noOfDigits-1);i++){
            if(i==dpno)
                dpoint[i]->setVisible(true);
            else
                dpoint[i]->setVisible(false);
        }
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

    void setValue(double value){

        QString strValue=QString::number(value);
        qDebug()<<strValue;

    /*    int dpIndex=strValue.indexOf(".");

        if(dpIndex!=-1)
            strValue=strValue.remove(".");*/

        int signIndex=strValue.indexOf("-");

        if(signIndex!=-1){
            strValue=strValue.remove("-");
            sign->setVisible(true);
        }else{
            sign->setVisible(false);
        }

        int count=strValue.count();

        if(count>6)  count=6;

        for(short i=0;i<6;i++)
            if(i<count)
                digits[i]->setText(QString(strValue[i]));
            else
                digits[i]->setText("");

     /*   if(signIndex!=-1)
             selectDPoint(dpIndex-2);
        else
             selectDPoint(dpIndex-1);*/
    }
    void setValue(QString strValue){
       /* int dpIndex=strValue.indexOf(".");
        if(dpIndex!=-1)
            strValue=strValue.remove(".");*/

        int signIndex=strValue.indexOf("-");

        if(signIndex!=-1){
            strValue=strValue.remove("-");
            sign->setVisible(true);
        }else{
            sign->setVisible(false);
        }

        int count=strValue.count();

        if(count>6)  count=6;

        for(short i=0;i<6;i++)
            if(i<count)
                digits[i]->setText(QString(strValue[i]));
            else
                digits[i]->setText("");

     /*   if(signIndex!=-1)
             selectDPoint(dpIndex-2);
        else
             selectDPoint(dpIndex-1);  */
    }


    ~DISPLAY(){}

};
#endif // DISPLAY_H
