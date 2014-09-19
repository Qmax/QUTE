QT += core \
    gui
TEMPLATE = lib
CONFIG += plugin
TARGET = RXCalib
QT += core \
    gui
HEADERS += ad5293.h \
    ad5318components.h \
    InterfaceFunctionalComponents.h \
    appcardcomponents.h \
    ad7190component.h \
    adccalibration.h \
    IRXCALIBWidget.h \
    RXCALIBTestJigInterface.h \
    AppdeviceRegisterDetails.h \
    ApplicationCardInterface.h \
    PTLibraryInterfaces.h \
    appcardfunctiontemplate.h
SOURCES += ad5293.cpp \
    ad5318components.cpp \
    ad7190component.cpp \
    adccalibration.cpp \
    IRXCALIBWidget.cpp \
    main.cpp
FORMS += daccalibration.ui
DESTDIR = /exports/nfsroot-ccwmx51js/home
RESOURCES += 
