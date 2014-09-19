# -------------------------------------------------
# Project created by QtCreator 2013-10-22T17:31:59
# -------------------------------------------------
TARGET = FGInterface
CONFIG += plugin
TEMPLATE = lib
SOURCES += ad5293.cpp \
    ad5318components.cpp \
    colors.cpp \
    fgmodel.cpp \
    hardwareinterface.cpp \
    plotter.cpp \
    ptfginterface.cpp \
    main.cpp \
    fg.cpp
HEADERS += AWGUIInterface2.h \
    AWGUIInterface.h \
    serialdevice.h \
    RefCALIBTestJigInterface.h \
    FGMacros.h \
    AppdeviceRegisterDetails.h \
    ApplicationCardInterface.h \
    BackPlaneInterface.h \
    CalibrationInterfaces.h \
    GPIOInterfaces.h \
    IPSOCCommunication.h \
    InterfaceFunctionalComponents.h \
    InterfacePTLibrary.h \
    PTAppBckPsocInterface.h \
    PTEventInterfaces.h \
    PTGPIOEventInterfaces.h \
    PTSPIMemoryInterface.h \
    ad5293.h \
    ad5318components.h \
    appcardcomponents.h \
    appcardfunctiontemplate.h \
    colors.h \
    fgmodel.h \
    hardwareinterface.h \
    interfaceHeader.h \
    plotter.h \
    ptfginterface.h \
    Waveformclass.h \
    fg.h \
    RefCALIBTestJigInterface.h
FORMS += fg.ui
RESOURCES += fp_res.qrc \
    fg.qrc
DESTDIR = /exports/nfsroot-ccwmx51js/home
