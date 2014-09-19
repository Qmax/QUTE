# -------------------------------------------------
# Project created by QtCreator 2013-03-08T15:45:50
# -------------------------------------------------
TARGET = APPCardRelayUI

# TEMPLATE = app
SOURCES += IACRWidget.cpp \
    main.cpp \
    mainwindow.cpp \
    appcardrelayread.cpp
HEADERS += AppdeviceRegisterDetails.h \
    AppdeviceRegisterDetails.h \
    BackPlaneInterface.h \
    ApplicationCardInterface.h \
    appcardfunctiontemplate.h \
    InterfacePTLibrary.h \
    IACRWidget.h \
    ACRTestJigInterface.h \
    mainwindow.h \
    appcardrelayread.h
FORMS += mainwindow.ui
DESTDIR = /exports/nfsroot-ccwmx51js/home

# for interface
QT += core \
    gui
TEMPLATE = lib
CONFIG += plugin
RESOURCES = apc.qrc
