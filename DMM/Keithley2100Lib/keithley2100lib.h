/*
 * hy3131dmmlib.cpp
 *
 *  Created on: 11-Mar-2014
 *      Author: Ravivarman.R
 */

#ifndef KEITHLEY2100LIB_H
#define KEITHLEY2100LIB_H

#include <unistd.h>
#include <QtCore>
#include <QPluginLoader>
#include <qdebug.h>
#include<stdio.h>
#include<fcntl.h>
#include<assert.h>
#include<string.h>

#include "Keithley2100Interface.h"


class Keithley2100Lib : public QObject,public IKeithley2100Interface{
    Q_OBJECT
    Q_INTERFACES(IKeithley2100Interface)
public:
    Keithley2100Lib(QObject *parent = 0);
    ~Keithley2100Lib();

    void writeKeithley( char*);
    char* readKeithley();

    void clearKeithley();
    void resetKeithley();

    void ConfigureResistance(int);
    double MeasureResistance(int);

    void ConfigureDCVoltage(int);
    double MeasureDCVoltage(int);

    void ConfigureACVoltage(int);
    double MeasureACVoltage(int);

    void ConfigureDCCurrent(int);
    double MeasureDCCurrent(int);

    void ConfigureACCurrent(int);
    double MeasureACCurrent(int);

    void ConfigureDiode(int);
    double MeasureDiode(int);

    void ConfigureContinuity(int);
    double MeasureContinuity(int);

    int fp;
    char buf[100];
};

#endif // KEITHLEY2100LIB_H
