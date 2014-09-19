# -------------------------------------------------
# Project created by QtCreator 2013-03-16T09:25:25
# -------------------------------------------------
TARGET = AWG

# TEMPLATE = app				#commented for interface
SOURCES += IAWGWidget.cpp \
    main.cpp \
    widget.cpp
HEADERS += AppdeviceRegisterDetails.h \
    ApplicationCardInterface.h \
    appcardfunctiontemplate.h \
    WaveformTestjigInterface.h \
    IAWGWidget.h \
    AWGTestJigInterface.h \ # for interface
    InterfacePTLibrary.h \
    widget.h
FORMS += widget.ui
DESTDIR = /exports/nfsroot-ccwmx51js/home/
RESOURCES = awgtj.qrc

# for interface
QT += core \
    gui
TEMPLATE = lib
CONFIG += plugin
