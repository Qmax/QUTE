# -------------------------------------------------
# Project created by QtCreator 2013-06-24T19:18:24
# -------------------------------------------------
TARGET = RAMData
QT += core \
    gui
TEMPLATE = lib
CONFIG += plugin
SOURCES += IRAMWidget.cpp \
    main.cpp \
    widget.cpp
HEADERS += IRAMWidget.h \
    RAMTestJigInterface.h \
    PTLibraryInterfaces.h \
    widget.h \
    PTLibraryInterfaces.h
FORMS += widget.ui
DESTDIR = /exports/nfsroot-ccwmx51js/home
RESOURCES = RAMData.qrc
