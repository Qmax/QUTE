#ifndef MYLINEEDIT_H
#define MYLINEEDIT_H

#include <QMainWindow>
#include <QLibrary>
#include <QLineEdit>
#include <QDebug>
#include <QLabel>

class MyLineEdit : public QLineEdit
{
  Q_OBJECT

public:
  MyLineEdit(short int pIndex,bool titleEnabled,QWidget *parent = 0);
  QLabel *lbl_Title;
  void customGeometry(int a, int b, int c, int d,QString str_Title,QWidget *appa=0);
  ~MyLineEdit();

    short int m_nSelectedIndex;
protected:


  void mousePressEvent(QMouseEvent* event);
    short int m_nObjectIndex;
    bool title;


public slots:
	void changeLabel();
	void checkFocus();
signals:
  void focussed(bool hasFocus);

};

#endif // MYLINEEDIT_H
