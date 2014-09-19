QT += core
TARGET = HY3131CalibInterface
TEMPLATE = lib
CONFIG += plugin
DESTDIR = /exports/nfsroot-ccwmx51js/home/
HEADERS += appcardcomponents.h \
    appcardfunctiontemplate.h \
    AppdeviceRegisterDetails.h \
    ApplicationCardInterface.h \
    hy3131calibinterface.h \
    hy3131calibration.h \
    HY3131Calib.h \
    HY3131DMMLibInterface.h \
    HY3131Macro.h \
    InterfaceFunctionalComponents.h \
    InterfacePTLibrary.h \
    Keithley2100Interface.h 
SOURCES += hy3131calibinterface.cpp \
    hy3131calibration.cpp
FORMS += hy3131calibration.ui
RESOURCES += testSPI.qrc
