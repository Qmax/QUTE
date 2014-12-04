# -------------------------------------------------
# Project created by QtCreator 2014-11-24T10:08:03
# -------------------------------------------------
TEMPLATE = lib
CONFIG += plugin
QT += webkit \
	core \
    gui
TARGET = Help
#TEMPLATE = app
#QT += webkit
SOURCES += IPTHelpWidget.cpp \
    main.cpp \
    mainwindow.cpp
HEADERS += PTHelpInterface.h \
    IPTHelpWidget.h \
    mainwindow.h
FORMS += mainwindow.ui
DESTDIR = /exports/nfsroot-ccwmx51js/home/
