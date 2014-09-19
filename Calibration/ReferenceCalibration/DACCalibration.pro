QT += core \
    gui
TEMPLATE = lib
CONFIG += plugin
TARGET = RefCalib
QT += core \
    gui
HEADERS += ad5318components.h \
    appcardcomponents.h \
    InterfaceFunctionalComponents.h \
    ad5293.h \
    IRefCALIBWidget.h \
    RefCALIBTestJigInterface.h \
    daccalibration.h \
    AppdeviceRegisterDetails.h \
    ApplicationCardInterface.h \
    PTLibraryInterfaces.h \
    appcardfunctiontemplate.h
SOURCES += ad5318components.cpp \
    ad5293.cpp \
    IRefCALIBWidget.cpp \
    daccalibration.cpp \
    main.cpp
FORMS += daccalibration.ui
DESTDIR = /exports/nfsroot-ccwmx51js/home
RESOURCES += 
