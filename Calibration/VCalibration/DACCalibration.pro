QT += core \
    gui
TEMPLATE = lib
CONFIG += plugin
TARGET = VCalib
QT += core \
    gui
HEADERS += AppdeviceRegisterDetails.h \
    ApplicationCardInterface.h \
    IVCALIBWidget.h \
    InterfaceFunctionalComponents.h \
    PTLibraryInterfaces.h \
    VCALIBTestJigInterface.h \
    ad5293.h \
    ad5318components.h \
    appcardcomponents.h \
    appcardfunctiontemplate.h \
    daccalibration.h \
    ad5293.h \
    ad5318components.h \
    InterfaceFunctionalComponents.h \
    appcardcomponents.h \
    IVCALIBWidget.h \
    VCALIBTestJigInterface.h \
    daccalibration.h \
    AppdeviceRegisterDetails.h \
    ApplicationCardInterface.h \
    PTLibraryInterfaces.h \
    appcardfunctiontemplate.h
SOURCES += IVCALIBWidget.cpp \
    ad5293.cpp \
    ad5318components.cpp \
    daccalibration.cpp \
    main.cpp \
    ad5293.cpp \
    ad5318components.cpp \
    IVCALIBWidget.cpp \
    daccalibration.cpp \
    main.cpp
FORMS += daccalibration.ui \
    daccalibration.ui
DESTDIR = /exports/nfsroot-ccwmx51js/home
RESOURCES += 
