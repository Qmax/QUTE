# -------------------------------------------------
# Project created by QtCreator 2013-03-18T09:41:24
# -------------------------------------------------
TARGET = ICMJig

# TEMPLATE = app
SOURCES += IICMWidget.cpp \
    ad5318components.cpp \
    ad7190component.cpp \
    main.cpp \
    widget.cpp \
    ad5318components.cpp \
    ad7190component.cpp \
    IICMWidget.cpp \
    main.cpp \
    widget.cpp
HEADERS += AppdeviceRegisterDetails.h \
    ApplicationCardInterface.h \
    ICMTestJigInterface.h \
    IICMWidget.h \
    InterfacePTLibrary.h \
    PTSPIMemoryInterface.h \
    WaveformTestjigInterface.h \
    ad5318components.h \
    ad7190component.h \
    appcardcomponents.h \
    appcardfunctiontemplate.h \
    widget.h \
    ad5318components.h \
    PTSPIMemoryInterface.h \
    AppdeviceRegisterDetails.h \
    ApplicationCardInterface.h \
    ad7190component.h \
    appcardcomponents.h \
    appcardfunctiontemplate.h \
    WaveformTestjigInterface.h \
    IICMWidget.h \
    ICMTestJigInterface.h \
    InterfacePTLibrary.h \
    widget.h
FORMS += widget.ui \
    widget.ui
DESTDIR = /exports/nfsroot-ccwmx51js/home/Testjig2/
RESOURCES = icmtj.qrc \
    icmtj.qrc

# for interface
QT += core \
    gui
TEMPLATE = lib
CONFIG += plugin
