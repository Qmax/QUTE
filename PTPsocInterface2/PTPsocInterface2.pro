# -------------------------------------------------
# Project created by QtCreator 2013-02-02T14:44:05
# -------------------------------------------------
QT += core
TARGET = PTPsocInterface2
TEMPLATE = lib
CONFIG += plugin
SOURCES += ptpsocinterface2.cpp
HEADERS += AppdeviceRegisterDetails.h \
    ApplicationCardInterface.h \
    appcardfunctiontemplate.h \
    ptpsocinterface2.h \
    IPSOCCommunication.h \
    serialdevice.h
DEPENDPATH += .
CONFIG += console
include(./src/qextserialport.pri)
DESTDIR = /exports/nfsroot-ccwmx51js/home/
