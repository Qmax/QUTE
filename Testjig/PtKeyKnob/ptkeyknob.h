
#ifndef PTKEYKNOB_H
#define PTKEYKNOB_H

#include <QtGui/QWidget>
#include <QtCore>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPixmap>
#include <QBrush>
#include <qdebug.h>
#include <unistd.h>
#include "ui_ptkeyknob.h"

#include "PTEventInterfaces.h"
#include "PTGPIOEventInterfaces.h"
#include "BackPlaneInterface.h"

#define		KNOBINT		0x0800
#define		NOINT		0x0000

const QEvent::Type KnobEvent = (QEvent::Type) 3456;//magnetic knob
const QEvent::Type PTKeyEvent = (QEvent::Type) 5678;//pykey event


class PtKeyKnob : public QWidget
{
    Q_OBJECT

public:
    PtKeyKnob(QWidget *parent = 0);
    ~PtKeyKnob();
    void enableRichGUI();

	int m_nGPIOCode, m_nPTKeyCode;
	void customEvent(QEvent *eve);
	void IndicateKeyPressed(QLabel *label);

	int delay;
protected:
	IntefaceBackPlane *IBackPlane; ////BackPlaneInterfacePlugin
    PTEventInterface	*IPTKeyEvent;
    PTGPIOEventInterface	*IGPIOEvent;

private:
    Ui::PtKeyKnobClass ui;

private slots:
    void on_spinBox_3_valueChanged(int );
    void on_spinBox_valueChanged(int );
    void on_spinBox_2_valueChanged(int );
    void on_pushButton_clicked();
    void on_groupBox_24_clicked();
    void changeDelay(int);

};

#endif // PTKEYKNOB_H
