# -------------------------------------------------
# Project created by Ravivarman.R,Qmax 2014-04-30T11:59:14
# -------------------------------------------------
QT += core
TARGET = SPIController
TEMPLATE = lib
CONFIG += plugin
DESTDIR = /exports/nfsroot-ccwmx51js/home
SOURCES += DSOPSOC.cpp \
    LMH6518.cpp \
    ISLA118P50.cpp \
    DAC8563.cpp \
    AD5293.cpp \
    AD5318.cpp \
    AD5260.cpp \
    spicontroller.cpp
HEADERS += DSOPSOC.h \
    LMH6518.h \
    ISLA118P50.h \
    DAC8563.h \
    AD5318.h \
    AD5293.h \
    AD5260.h \
    Macros.h \
    SPIInterface.h \
    spicontroller.h \
    appcardcomponents.h \
    appcardfunctiontemplate.h \
    ApplicationCardInterface.h \
    InterfaceFunctionalComponents.h
OTHER_FILES += AD5260.pdf \
    AD5293.pdf \
    AD5318.pdf \
    DAC8563.pdf \
    ISLA118P50.pdf
