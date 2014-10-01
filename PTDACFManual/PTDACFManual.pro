# -------------------------------------------------
# Project created by QtCreator 2014-09-30T12:37:46
# -------------------------------------------------
QT += core \
    gui
TARGET = PTDACFManual
TEMPLATE = lib
CONFIG += plugin
SOURCES += IPTDACFWidget.cpp \
    main.cpp \
    dacfwidget.cpp
HEADERS += IPTDACFWidget.h \
    PTDACFInterface.h \
    InterfacePTLibrary.h \
    dacfwidget.h
FORMS += dacfwidget.ui
DESTDIR = /exports/nfsroot-ccwmx51js/home/
