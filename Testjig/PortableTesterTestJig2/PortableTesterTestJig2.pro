TEMPLATE = app
TARGET = PortableTesterTestJig2
QT += core \
    gui
HEADERS += IPSOCCommunication.h \
    serialdevice.h \
    PSoCTestJigInterface2.h \
    AD9102TestJigInterface.h \
    ACRTestJigInterface.h \
    AD5318TestJigInterface.h \
    APPRXDRVTestJigInterface.h \
    AWGTestJigInterface.h \
    AppdeviceRegisterDetails.h \
    ApplicationCardInterface.h \
    DDSTestJigInterface.h \
    DMMTestJigInterface.h \
    FMTestJigInterface.h \
    HACADCTestJigInterface.h \
    ICMTestJigInterface.h \
    InterfacePTLibrary.h \
    KeyKnobTestJigInterface.h \
    PSoCTestJigInterface.h \
    PWFTestJigInterface.h \
    RAMTestJigInterface.h \
    VITestJigInterface.h \
    ViewerTestJigInterface.h \
    appcardfunctiontemplate.h \
    portabletestertestjig2.h \
    appcardfunctiontemplate.h
SOURCES += main.cpp \
    portabletestertestjig2.cpp
FORMS += portabletestertestjig2.ui
RESOURCES += pttj2.qrc
DESTDIR = /exports/nfsroot-ccwmx51js/home
