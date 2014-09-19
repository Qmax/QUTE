QT += core \
    gui
TEMPLATE = lib
CONFIG += plugin
TARGET = VCalib
QT += core \
    gui
HEADERS += ad5293.h \
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
SOURCES += ad5293.cpp \
    ad5318components.cpp \
    IVCALIBWidget.cpp \
    daccalibration.cpp \
    main.cpp
FORMS += daccalibration.ui
DESTDIR = /exports/nfsroot-ccwmx51js/home
RESOURCES += 
#QMAKE_POST_LINK += cp /exports/nfsroot-ccwmx51js/home/libVCalib.so /mnt/TestingPC/nfsroot-ccwmx51js/home/libVCalib.so