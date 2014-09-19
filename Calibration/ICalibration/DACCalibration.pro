QT += core \
    gui
TEMPLATE = lib
CONFIG += plugin
TARGET = ICalib
HEADERS += InterfaceFunctionalComponents.h \
    ad5318components.h \
    appcardcomponents.h \
    ICALIBTestJigInterface.h \
    IICALIBWidget.h \
    AppdeviceRegisterDetails.h \
    ApplicationCardInterface.h \
    PTLibraryInterfaces.h \
    appcardfunctiontemplate.h \
    daccalibration.h \
    ui_daccalibration.h
SOURCES += ad5318components.cpp \
    main.cpp \
    IICALIBWidget.cpp \
    daccalibration.cpp
FORMS += daccalibration.ui
DESTDIR = /exports/nfsroot-ccwmx51js/home
