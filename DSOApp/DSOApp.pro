# -------------------------------------------------
# Project created by QtCreator 2014-03-17T10:25:22
# -------------------------------------------------
TARGET = DSOApp
TEMPLATE = app
QT += xml \
    svg
SOURCES += dsodatasettings.cpp \
    lmh6518.cpp \
    main.cpp \
    mainwindow.cpp \
    dsographicsitems.cpp \
    channeluiwidget.cpp \
    channelwidget.cpp \
    cdsomapdetails.cpp \
    ad5318components.cpp \
    ad5293.cpp \
    dial.cpp \
    dialwidget.cpp
HEADERS += DSOCommon.h \
    dsodatasettings.h \
    mainwindow.h \
    dsographicsitems.h \
    channeluiwidget.h \
    channelwidget.h \
    cdsomapdetails.h \
    PTSPIMemoryInterface.h \
    PTGPIOEventInterfaces.h \
    PTEventInterfaces.h \
    PTAppBckPsocInterface.h \
    hardwareinterface.h \
    lmh6518.h \
    IPSOCCommunication.h \
    InterfaceFunctionalComponents.h \
    BackPlaneInterface.h \
    ApplicationCardInterface.h \
    AppdeviceRegisterDetails.h \
    appcardfunctiontemplate.h \
    appcardcomponents.h \
    ad5318components.h \
    ad5293.h \
    dial.h \
    dialwidget.h
FORMS += mainwindow.ui \
    channelwidget.ui \
    dialwidget.ui
RESOURCES += dso.qrc
DESTDIR = /exports/nfsroot-ccwmx51js/home

