#ifndef OFFSET_H
#define OFFSET_H

#include <QWidget>
#include <QLineEdit>
#include "DMMLibInterface.h"
#include "InterfacePTLibrary.h"


namespace Ui {
    class offset;
}

class offset : public QWidget {
    Q_OBJECT
public:
    offset(IDMMLibInterface*,QWidget *parent = 0);
    ~offset();

    IQmaxLineEdit *ILineEdit;
    IQmaxNumberPanel *INumberPanel;

    void openNumKBPanel(short int);
    void openNumKBPanel(short int,double,char,double,double,QWidget*);

    double validateCursorPosition(short pos,double value,short incDec);

    short int m_nLineEditIndex;

    QLineEdit *objDACF;

    double m_nDACF;

protected:
    void changeEvent(QEvent *e);

    IDMMLibInterface	*IDMMLib;

private:
    Ui::offset *ui;

private slots:
    void on_pushButton_clicked();
    void callDACFEdit();

    void receiveValue(unsigned int);
    void receiveValue(double);
    void receiveValue(QString);

    void on_Gdown_clicked();
    void on_Gup_clicked();
    void on_Gright_clicked();
    void on_Gleft_clicked();
    void on_Fdown_clicked();
    void on_Fup_clicked();
    void on_Fright_clicked();
    void on_Fleft_clicked();
};

#endif // OFFSET_H
