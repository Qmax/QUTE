# -------------------------------------------------
# Project created by QtCreator 2013-05-27T10:06:36
# -------------------------------------------------
QT += core \
    gui
TEMPLATE = lib
CONFIG += plugin
TARGET = AD5318
SOURCES += ad5293.cpp \
    ad7190component.cpp \
    main.cpp \
    ad5318.cpp \
    ad5318components.cpp \
    IAD5318Widget.cpp
HEADERS += PTAppBckPsocInterface.h \
    PTLMH6518Interface.h \
    BackPlaneInterface.h \
    ICALIBTestJigInterface.h \
    RXCALIBTestJigInterface.h \
    RefCALIBTestJigInterface.h \
    VCALIBTestJigInterface.h \
    ICALIBTestJigInterface.h \
    RXCALIBTestJigInterface.h \
    RefCALIBTestJigInterface.h \
    VCALIBTestJigInterface.h \
    ad5293.h \
    ad7190component.h \
    ad5318.h \
    PTLibraryInterfaces.h \
    ApplicationCardInterface.h \
    AppdeviceRegisterDetails.h \
    appcardfunctiontemplate.h \
    InterfaceFunctionalComponents.h \
    appcardcomponents.h \
    ad5318components.h \
    IAD5318Widget.h \
    AD5318TestJigInterface.h
FORMS += ad5318.ui
DESTDIR = /exports/nfsroot-ccwmx51js/home/
RESOURCES = ad5318.qrc
