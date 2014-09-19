# -------------------------------------------------
# Project created by QtCreator 2013-03-16T12:30:49
# -------------------------------------------------
TARGET = DMM

# TEMPLATE = app
SOURCES += plotter.cpp \
    ad7190component.cpp \
    ad5318components.cpp \
    IDMMWidget.cpp \
    main.cpp \
    dmmjig.cpp
HEADERS += plotter.h \
    IPSOCCommunication.h \
    ad7190component.h \
    AppdeviceRegisterDetails.h \
    ApplicationCardInterface.h \
    InterfaceFunctionalComponents.h \
    ad5318components.h \
    appcardcomponents.h \
    appcardfunctiontemplate.h \
    WaveformTestjigInterface.h \
    IDMMWidget.h \
    DMMTestJigInterface.h \
    InterfacePTLibrary.h \
    dmmjig.h
FORMS += dmmjig.ui
DESTDIR = /exports/nfsroot-ccwmx51js/home
RESOURCES = dmmtj.qrc

# for interface
QT += core \
    gui
TEMPLATE = lib
CONFIG += plugin
