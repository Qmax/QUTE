# -------------------------------------------------
# Project created by Ravivarman.R 2014-09-09T14:08:47
# -------------------------------------------------
TEMPLATE = lib
CONFIG += plugin
TARGET = DIGrapher
QT += core \
    gui

# TEMPLATE = app
SOURCES += main.cpp \
    digrapher.cpp \
    qcustomplot.cpp \
    interfacedigrapher.cpp
HEADERS += digrapher.h \
    qcustomplot.h \
    DIGrapherInterface.h \
    interfacedigrapher.h
FORMS += digrapher.ui
DESTDIR = /exports/nfsroot-ccwmx51js/home/
RESOURCES += DIGraphRes.qrc
