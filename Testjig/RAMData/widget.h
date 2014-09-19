#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <PTLibraryInterfaces.h>

namespace Ui {
    class Widget;
}

class Widget : public QWidget {
    Q_OBJECT
public:
    Widget(QWidget *parent = 0);
    ~Widget();
    void enableRichGUI();
    IQmaxLineEdit *ILineEdit;
    IQmaxPTLibrary *IPTLibrary;
    IQmaxNumberPanel *INumberPanel;
protected:
    void changeEvent(QEvent *e);
    void initialiseTableWidget();
    QLineEdit *m_objLE_32BITFTW;
    unsigned short int m_nLineEditIndex,m_nFTW32BITData;

    void openNumKBPanel(short int pValue) ;
    void openNumKBPanel(short int pValue, double incDec, char type,double max, double min);

private:
    Ui::Widget *ui;

private slots:
    void on_pushButton_clicked();
    void callFTW32edit();
    void receiveValue(unsigned int pValue);
    void receiveValue(double);
    void receiveValue(QString);
};

#endif // WIDGET_H
