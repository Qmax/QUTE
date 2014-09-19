/*
 * DSOCommon.h
 *
 *  Created on: Mar 28, 2014
 *      Author: D.Elangovan
 */

#ifndef DSOCOMMON_H_
#define DSOCOMMON_H_
enum BASEWIDGET {CHANNEL_1=0,CHANNEL_2=1,TIMEBASE=2,TRIGGER=3,DSONAVIGATION=4,CURSORS=5,MEASUREMENTS=6};

enum SAMPLING_TYPE{NORMAL=0,MIN_MAX,AVERAGE,MOVING_AVERAGE,LINEAR_INTERPOLATION,MOVING_LINEAR,WAVEFORM_MEMORY};
enum DSO_CHANNEL{CHANNEL1,CHANNEL2,CHANNEL3,CHANNEL4};
enum TIMEUNIT{NANOSECONDS,MICROSECONDS,MILLISECONDS,SECONDS};
enum SAMPLEUNIT{MEGAS,KILOS,ONES};


const QString gStrDnCH1Widget = QString(("QWidget{background-color: rgb(143, 143, 142,255);border:2px solid #3a5976;border-radius:8px;}"));
const QString gStrEnCH1Widget = QString(("QWidget{background-color: rgb(255, 255, 0);border:2px solid #3a5976;border-radius:8px;}"));

const QString gStrDnCH2Widget = QString(("QWidget{background-color: rgb(143, 143, 142,255);border:2px solid #3a5976;border-radius:8px;}"));
const QString gStrEnCH2Widget = QString(("QWidget{background-color: rgb(255, 0, 255);border:2px solid #3a5976;border-radius:8px;}"));


const QString gStrDnTriggerWidget = QString(("QWidget{background-color: rgb(143, 143, 142,255);border:2px solid #3a5976;border-radius:8px;}"));
const QString gStrEnTriggerWidget = QString(("QWidget{background-color: rgb(108, 108, 107,255);border:2px solid #3a5976;border-radius:8px;}"));

const QString gPushButton = QString(("QPushButton{color: rgb(143, 143, 142,255);}"));


#endif /* DSOCOMMON_H_ */
