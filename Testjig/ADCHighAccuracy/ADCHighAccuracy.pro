# -------------------------------------------------
# Project created by QtCreator 2013-05-27T13:50:30
# -------------------------------------------------
TARGET = ADCHighAccuracy
QT += core \
    gui
TEMPLATE = lib
CONFIG += plugin
SOURCES += ad5318components.cpp \
    IHACADCWidget.cpp \
    main.cpp \
    adhighaccuracy.cpp \
    ad7190component.cpp
HEADERS += PTAppBckPsocInterface.h \
    AppdeviceRegisterDetails.h \
    AppdeviceRegisterDetails.h \
    InterfaceFunctionalComponents.h \
    ad5318components.h \
    HACADCTestJigInterface.h \
    IHACADCWidget.h \
    ApplicationCardInterface.h \
    adhighaccuracy.h \
    appcardcomponents.h \
    appcardfunctiontemplate.h \
    ad7190component.h
FORMS += adhighaccuracy.ui
DESTDIR = /exports/nfsroot-ccwmx51js/home
RESOURCES = haadc.qrc
