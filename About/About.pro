# -------------------------------------------------
# Project created by QtCreator 2014-12-04T09:48:07
# -------------------------------------------------
TEMPLATE = lib
CONFIG += plugin
QT += webkit \
    core \
    gui
TARGET = About
SOURCES += IPTAboutWidget.cpp \
    main.cpp \
    about.cpp
HEADERS += IPTAboutWidget.h \
    about.h
FORMS += about.ui
DESTDIR = /exports/nfsroot-ccwmx51js/home/
RESOURCES += about.qrc \
    about.qrc
