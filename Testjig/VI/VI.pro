# -------------------------------------------------
# Project created by QtCreator 2013-03-16T10:47:04
# -------------------------------------------------
TARGET = VI

# TEMPLATE = app
SOURCES += IVIWidget.cpp \
    main.cpp \
    vijig.cpp
HEADERS += WaveformTestjigInterface.h \
    IVIWidget.h \
    VITestJigInterface.h \
    InterfacePTLibrary.h \
    vijig.h
FORMS += vijig.ui
DESTDIR = /exports/nfsroot-ccwmx51js/home
RESOURCES = vitj.qrc

# for interface
QT += core \
    gui
TEMPLATE = lib
CONFIG += plugin
