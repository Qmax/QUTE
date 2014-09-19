#CONFIG += plugin
#TEMPLATE = lib

TEMPLATE = app
TARGET = testSPI
QT += core \
    gui
HEADERS += BackPlaneInterface.h \
    DMMSPITestJigInterface.h \
    DMMSPIWidget.h \
    HY3131Macro.h \
    HY3131DMMLibInterface.h \
    hy3131calibration.h \
    display.h \
    AppdeviceRegisterDetails.h \
    ApplicationCardInterface.h \
    InterfaceFunctionalComponents.h \
    InterfacePTLibrary.h \
    appcardcomponents.h \
    appcardfunctiontemplate.h \
    testspi.h \
    display.h
SOURCES += DMMSPIWidget.cpp \
    hy3131calibration.cpp \
    main.cpp \
    testspi.cpp
FORMS += hy3131calibration.ui \
    testspi.ui
RESOURCES += testSPI.qrc
DESTDIR = /exports/nfsroot-ccwmx51js/home
