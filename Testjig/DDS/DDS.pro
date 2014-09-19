# -------------------------------------------------
# Project created by QtCreator 2013-05-10T09:08:53
# -------------------------------------------------
TARGET = DDS
QT += core \
    gui
TEMPLATE = lib
CONFIG += plugin
SOURCES += ad5318components.cpp \
    ad5293.cpp \
    daccalibration.cpp \
    IDDSWidget.cpp \
    main.cpp \
    ddswidget.cpp
HEADERS += ad5318components.h \
    PTGPIOEventInterfaces.h \
    appcardcomponents.h \
    InterfaceFunctionalComponents.h \
    ad5293.h \
    AppdeviceRegisterDetails.h \
    daccalibration.h \
    BackPlaneInterface.h \
    IDDSWidget.h \
    DDSTestJigInterface.h \
    ddswidget.h \
    PTLibraryInterfaces.h \
    ApplicationCardInterface.h \
    appcardfunctiontemplate.h \
    PTLibraryInterfaces.h \
    AppdeviceRegisterDetails.h \
    ApplicationCardInterface.h \
    appcardfunctiontemplate.h
FORMS += daccalibration.ui \
    ddswidget.ui
DESTDIR = /exports/nfsroot-ccwmx51js/home/
RESOURCES = ddstj.qrc \
    ddstj.qrc \
    ddstj.qrc
