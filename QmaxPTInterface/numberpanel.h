#ifndef NUMBERPANEL_H
#define NUMBERPANEL_H

#include <QWidget>
#include <QVariant>
#include <QMessageBox>
#include "qmaxbutton.h"

namespace Ui {
    class NumberPanel;
}

class NumberPanel : public QWidget {
    Q_OBJECT
public:
    NumberPanel(short int,QWidget *parent);
    NumberPanel(short int,double incRatio,char type,double max,double min,QWidget *parent);
    double maxMinCheck(double,double,double);
    ~NumberPanel();
    void setNumer(unsigned int*);
    void setNumer(double*);
    void setNumer(QString*);
    int deci_length;
    double ratio,Max,Min;
    int panelType;
    QMessageBox *alert;
    int posValue;
public slots:
    void buttonPressed(int);

signals:
   void passText(unsigned int);
   void passText1(double);
   void passText2(QString);

protected:
    void changeEvent(QEvent *e);
    QmaxButton *m_objVKeyButtons[25];
    QmaxButton *m_objVOKCancelButtons[2];
    QmaxButton *m_objVMiscButtons[3];
    QmaxButton *m_objVHexButtons[6];
    QmaxButton *ArrowButtons[2];
    QString validateKey(QString pKey);
    unsigned int *m_nNumber;
    double *m_nFloatNumber;
    QString *m_sNumber;
    short int m_nFlag;
private:
    Ui::NumberPanel *ui;
    QMap<int,QString> m_mapPTNumKeys;
    QMap<int,QString> m_mapPTMiscKeys;
    QMap<int,QString> m_mapOKCancelKeys;
    QMap<int,QString> m_mapVHexKeys;
    void constructVirtualNumPad();
    void InitialisePTNumKeyMap();
    QString m_strNumber;
    unsigned int l_nNumber;
    double l_nDeciNumber;




private slots:
    void on_numEdit_textChanged(QString );
};

#endif // NUMBERPANEL_H
