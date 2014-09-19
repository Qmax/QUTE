# -------------------------------------------------
# Project created by Ravivarman,Qmax 2012-01-25T16:10:41
# -------------------------------------------------
CONFIG += plugin
TARGET = DMMInterface
TEMPLATE = lib
DEFINES += DMMCONTROL_LIBRARY
SOURCES += dmmaccuracy.cpp \
    hy3131calibration.cpp \
    daccalibration.cpp \
    ptdmminterface.cpp \
    dmmcontrol.cpp \
    dmm.cpp
HEADERS += DIGrapherInterface.h \
    IPSOCCommunication.h \
    serialdevice.h \
    DMMSPITestJigInterface.h \
    dmmaccuracy.h \
    HY3131Calib.h \
    HY3131DMMLibInterface.h \
    HY3131Macro.h \
    InterfaceFunctionalComponents.h \
    appcardcomponents.h \
    hy3131calibration.h \
    display.h \
    PTLibraryInterfaces.h \
    daccalibration.h \
    PTAppBckPsocInterface.h \
    AppdeviceRegisterDetails.h \
    appcardfunctiontemplate.h \
    GPIOInterfaces.h \
    ptdmminterface.h \
    interfaceHeader.h \
    InterfacePTLibrary.h \
    PTGPIOEventInterfaces.h \
    PTEventInterfaces.h \
    ApplicationCardInterface.h \
    BackPlaneInterface.h \
    dmmcontrol.h \
    DMMControl_global.h \
    dmm.h \
    display.h
FORMS += dmmaccuracy.ui \
    hy3131calibration.ui \
    daccalibration.ui \
    dmm.ui
RESOURCES = fp_res.qrc \
    testSPI.qrc \
    pic.qrc
DESTDIR = /exports/nfsroot-ccwmx51js/home/
