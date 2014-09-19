#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <Waveformclass.h>
#include <InterfacePTLibrary.h>
#include <PTSPIMemoryInterface.h>
#include <ApplicationCardInterface.h>
#include <QGraphicsScene>
#include <QGraphicsView>

namespace Ui {
    class Widget;
}

class Widget : public QWidget {
    Q_OBJECT
public:
    Widget(QWidget *parent = 0);
    ~Widget();
    void enableRichGUI();

protected:
    void changeEvent(QEvent *e);
    void initialiseLibraries();
    void waveData();
    void writeWaveData(short int);
    WaveFormFactory *m_objWaveFactory;
   IWaveProduct *PlotProduct,*PlotProduct1;
   IQmaxLineEdit *ILineEdit;
   IQmaxNumberPanel *INumberPanel;
   ISPIMemoryInterface *ISPIMemory;
   IApplicationCardInterface *IAppCard;
   stWaveData *objVIWaveData,*objReceData;

   QLineEdit *m_objstAddr,*m_objAddrCount,*m_objReceStAddr,*m_objReceAddrCount;
   QLineEdit *m_objstRece1Addr,*m_objstRece1Count,*m_objstRece2Addr,*m_objstRece2Count;
   void openNumKBPanel(short int);
   void openNumKBPanel(short int,double,char,double,double,QWidget*);
   int m_nLineEditIndex;
   unsigned short int  *m_nMEMLOCATIONS,*m_nRECELocations;
   unsigned short m_nStartAddress,m_nEndAddress,m_nAdressCount,m_nReceStartAddress,m_nReceAddrCount;
   unsigned short int m_nR1Samples;
private:
    Ui::Widget *ui;

private slots:
    void on_pushButton_clicked();
    void on_butReceive_clicked();
    void on_butDSOReceive_clicked();
    void receiveValue(unsigned int);
    void receiveValue(double);
    void receiveValue(QString);

    void callstAddressEdit();
    void callAddrCoutEdit();
    void callstReceAddressEdit();
    void callReceAddrCoutEdit();
    void callR1Count();

};

#endif // WIDGET_H
