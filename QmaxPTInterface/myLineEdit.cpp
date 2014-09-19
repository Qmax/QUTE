#include "myLineEdit.h"
#include <QLabel>

void MyLineEdit::customGeometry(int a, int b, int c, int d,QString str_Title,QWidget *appa){

    setGeometry(a,b,c,d);
    setStyleSheet("color: rgb(255, 255, 255);""background-color: black;");
    setFrame(false);
    setFont(QFont("DejaVu Sans",14,50,false));

    lbl_Title=new QLabel(appa);
    lbl_Title->setText(str_Title);
    //lbl_Title->setGeometry(a,b-(lbl_Title->text().size())-10,c,(lbl_Title->text().size())+13);
    //lbl_Title->setGeometry(a-2,b-d,c+4,d);
    lbl_Title->setGeometry(a,b-(d-11),c,d-10);
    lbl_Title->setAlignment(Qt::AlignCenter);
    lbl_Title->setStyleSheet("color: rgba(255,255,255,255);""border: rgba(0,0,0,0);""border-radius: 3px;""background-color: rgba(0, 0, 0,0);""qproperty-wordWrap: true;");
    lbl_Title->setFont(QFont("DejaVu Sans",14,75,false));
    lbl_Title->setFrameStyle(3);
    lbl_Title->setFrameRect(QRect(0,0,c,(lbl_Title->text().size())+13));
    lbl_Title->setVisible(true);
    checkFocus();

}

void MyLineEdit::changeLabel()
{
        //qDebug()<<"label Focus change";
	lbl_Title->setStyleSheet("color: rgba(255,255,255,255);""border: rgba(0,0,0,0);""border-radius: 3px;""background-color: rgba(0, 0, 0,0);""qproperty-wordWrap: true;");
}

MyLineEdit::MyLineEdit(short int pIndex,bool titleEnabled,QWidget *parent)
    : QLineEdit(parent)
{
    setStyleSheet("color: rgb(255, 255, 255);""background-color: black;");
    setFrame(false);
    setFont(QFont("DejaVu Sans",14,50,false));
    m_nObjectIndex  = pIndex;
    title=titleEnabled;
//    //qDebug()<<"inside line edit";
   // connect(parent,SIGNAL(focussed(bool)),this,SLOT(changeLabel()));
}
void MyLineEdit::checkFocus(){
//	//qDebug()<<"MyLineEdit checkFocus";
	 if(hasFocus() == true){
                ////qDebug()<<"Clear Focus True";
		  lbl_Title->setStyleSheet("color: rgba(0,0,0,255);""border: 1px solid black;""border-radius: 3px;""background-color: rgba(170, 255, 127,255);""qproperty-wordWrap: true;");
			emit focussed(false);
	 }
	 else if(m_nObjectIndex==0)
	 {
                        ////qDebug()<<"Clear Focus True";
 		    lbl_Title->setStyleSheet("color: rgba(0,0,0,255);""border: 1px solid black;""border-radius: 3px;""background-color: rgba(170, 255, 127,255);""qproperty-wordWrap: true;");
 		    emit focussed(false);
	 }
//	 else if(hasFocus() == false){
//	    	//qDebug()<<"Clear Focus False";
//	    	emit focussed(true);
//	        }
}
MyLineEdit::~MyLineEdit()
{}
void MyLineEdit::mousePressEvent(QMouseEvent *event)
{
    Q_UNUSED(event)
    if(hasFocus() == true){
        //qDebug()<<"Clear Focus True";
        //lbl_Title->setVisible(true);
    	if(title==true)
    	  lbl_Title->setStyleSheet("color: rgba(0,0,0,255);""border: 1px solid black;""border-radius: 3px;""background-color: rgba(170, 255, 127,255);""qproperty-wordWrap: true;");
        emit focussed(false);
            }
    if(hasFocus() == false){
        //qDebug()<<"Clear Focus False";
//    	lbl_Title->setStyleSheet("color: rgba(255,255,255,255);""border: rgba(0,0,0,0);""border-radius: 3px;""background-color: rgba(0, 0, 0,0);""qproperty-wordWrap: true;");
    	emit focussed(true);
//        setFocus(Qt::MouseFocusReason);
//        setFocusPolicy(Qt::ClickFocus);
        }
}


