# -------------------------------------------------
# Project created by Ravivarman.R,Qmax 2014-04-17T14:38:29
# -------------------------------------------------
TARGET = ADCHighSpeed
QT += core \
    gui
TEMPLATE = app
#CONFIG += plugin
SOURCES += main.cpp \
    adchighspeed.cpp \
    isla118p50component.cpp
HEADERS += adchighspeed.h \
    isla118p50component.h \
    appcardfunctiontemplate.h \
    AppdeviceRegisterDetails.h \
    ApplicationCardInterface.h \
    appcardcomponents.h \
    InterfaceFunctionalComponents.h
FORMS += adchighspeed.ui
DESTDIR = /exports/nfsroot-ccwmx51js/home
