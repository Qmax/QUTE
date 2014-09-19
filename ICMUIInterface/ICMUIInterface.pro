# -------------------------------------------------
# Project created by Ravivarman 2013-04-18T15:09:18
# -------------------------------------------------
# TEMPLATE = app
# TARGET = ICMUIInterface
# QT += core \
# gui
CONFIG += plugin
TARGET = ICMUIInterface
TEMPLATE = lib
SOURCES += qcustomplot.cpp \
    ad5318components.cpp \
    daccalibration.cpp \
    ad5293.cpp \
    ad7190component.cpp \
    main.cpp \
    icm.cpp \
    pticminterface.cpp \
    settings.cpp
HEADERS += qcustomplot.h \
    serialdevice.h \
    display.h \
    GPIOInterfaces.h \
    PTEventInterfaces.h \
    PTGPIOEventInterfaces.h \
    AppdeviceRegisterDetails.h \
    ad5318components.h \
    appcardcomponents.h \
    appcardfunctiontemplate.h \
    PTLibraryInterfaces.h \
    daccalibration.h \
    PTAppBckPsocInterface.h \
    BackPlaneInterface.h \
    GCALIBTestJigInterface.h \
    hardwareinterface.h \
    IPSOCCommunication.h \
    InterfaceFunctionalComponents.h \
    ad5293.h \
    ApplicationCardInterface.h \
    InterfacePTLibrary.h \
    PTSPIMemoryInterface.h \
    ad7190component.h \
    icm.h \
    pticminterface.h \
    interfaceHeader.h \
    Qmax/qtsvgslideswitch.h \
    settings.h
FORMS += daccalibration.ui \
    icm.ui \
    settings.ui
DESTDIR = /exports/nfsroot-ccwmx51js/home/
RESOURCES += fp_res.qrc \
    icm.qrc
