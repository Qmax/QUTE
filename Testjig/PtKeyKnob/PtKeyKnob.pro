TEMPLATE = lib
TARGET = PtKeyKnob
QT += core \
    gui
CONFIG += plugin
HEADERS += AppdeviceRegisterDetails.h \
    ApplicationCardInterface.h \
    appcardfunctiontemplate.h \
    BackPlaneInterface.h \
    PTEventInterfaces.h \
    PTGPIOEventInterfaces.h \
    KeyKnobTestJigInterface.h \
    IKeyKnobWidget.h \
    ptkeyknob.h
SOURCES += IKeyKnobWidget.cpp \
    main.cpp \
    ptkeyknob.cpp
FORMS += ptkeyknob.ui
RESOURCES += ptkeyknob.qrc
DESTDIR = /exports/nfsroot-ccwmx51js/home
