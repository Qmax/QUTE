# -------------------------------------------------
# Project created by QtCreator 2014-09-19T16:39:00
# -------------------------------------------------
TEMPLATE = lib
CONFIG += plugin
QT += core \
    gui
TARGET = PTToolBox
SOURCES +=  logindialog.cpp \
    main.cpp \
    toolbox.cpp \
    IPTToolBoxWidget.cpp \
    datetime.cpp
HEADERS +=   logindialog.h \
    PTTestjigInterface.h \
    PTToolBoxInterface.h \
    toolbox.h \
    IPTToolBoxWidget.h \
    PTToolBoxInterface.h \
    datetime.h
FORMS +=   toolbox.ui \
    datetime.ui
OTHER_FILES += 
RESOURCES += toolbox.qrc
DESTDIR = /exports/nfsroot-ccwmx51js/home/
