# -------------------------------------------------
# Project created by QtCreator 2013-04-03T10:54:00
# -------------------------------------------------
TARGET = FLASHMEMORY

# TEMPLATE = app
SOURCES += IFMWidget.cpp \
    messagewidget.cpp \
    main.cpp \
    flashMemory.cpp
HEADERS += BackPlaneInterface.h \
    PTSplashScreen.h \
    AppdeviceRegisterDetails.h \
    appcardfunctiontemplate.h \
    ApplicationCardInterface.h \
    PTSPIMemoryInterface.h \
    FMTestJigInterface.h \
    IFMWidget.h \
    messagewidget.h \
    flashMemory.h \
    InterfacePTLibrary.h
FORMS += messagewidget.ui \
    flashMemory.ui
DESTDIR = /exports/nfsroot-ccwmx51js/home

# for interface
QT += core \
    gui
TEMPLATE = lib
CONFIG += plugin
RESOURCES = fm.qrc
