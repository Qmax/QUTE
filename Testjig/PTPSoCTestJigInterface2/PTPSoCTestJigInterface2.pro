TEMPLATE = lib
CONFIG += plugin
TARGET = PTPSoCTestJigInterface2
QT += core \
    gui
HEADERS += serialdevice.h \
    InterfacePTLibrary.h \
    BackPlaneInterface.h \
    GPIOInterfaces.h \
    IPSOCCommunication.h \
    PTEventInterfaces.h \
    PTGPIOEventInterfaces.h \
    PSoCTestJigInterface2.h \
    macros.h \
    headers.h \
    IPSoCWidget.h \
    ptpsoctestjiginterface2.h
SOURCES += IPSoCWidget.cpp \
    main.cpp \
    ptpsoctestjiginterface2.cpp
FORMS += ptpsoctestjiginterface2.ui
RESOURCES += psoctj.qrc
DESTDIR = /exports/nfsroot-ccwmx51js/home
