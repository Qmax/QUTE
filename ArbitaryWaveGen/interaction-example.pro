# -------------------------------------------------
# Project created by Ravivarman 2014-09-02T23:24:55
# -------------------------------------------------
QT += core \
    gui
TARGET = ArbitaryWaveGen
TEMPLATE = lib
CONFIG += plugin
SOURCES += wavedata.cpp \
    ad5293.cpp \
    ad5318components.cpp \
    IAWGUIInterface2.cpp \
    qcustomplot.cpp \
    main.cpp \
    mainwindow.cpp
HEADERS += WaveDataClass.h \
    wavedata.h \
    InterfaceFunctionalComponents.h \
    appcardcomponents.h \
    ad5293.h \
    ad5318components.h \
    hardwareinterface.h \
    PTAppBckPsocInterface.h \
    AppdeviceRegisterDetails.h \
    ApplicationCardInterface.h \
    appcardfunctiontemplate.h \
    InterfacePTLibrary.h \
    PTEventInterfaces.h \
    PTSPIMemoryInterface.h \
    IAWGUIInterface2.h \
    AWGUIInterface2.h \
    qcustomplot.h \
    mainwindow.h
FORMS += wavedata.ui \
    mainwindow.ui
DESTDIR = /exports/nfsroot-ccwmx51js/home
RESOURCES = ArbitaryWaveGen.qrc
