TEMPLATE = lib
CONFIG += plugin
TARGET = AppBckPsoc
QT += core \
    gui
HEADERS += DSOCardInterface.h \
    GenericInterface.h \
    InterfaceFunctionalComponents.h \
    IPTAppBckPsocWidget.h \
    PTAppBckPsocInterface.h \
    InterfacePTLibrary.h \
    BackPlaneInterface.h \
    GPIOInterfaces.h \
    IPSOCCommunication.h \
    PTEventInterfaces.h \
    PTGPIOEventInterfaces.h \
    macros.h \
    headers.h \
    ptpsoctestjiginterface.h
SOURCES += IPTAppBckPsocWidget.cpp \
    main.cpp \
    ptpsoctestjiginterface.cpp
FORMS += ptpsoctestjiginterface.ui
RESOURCES += psoctj.qrc
DESTDIR = /exports/nfsroot-ccwmx51js/home/
