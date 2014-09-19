# -------------------------------------------------
# Project created by QtCreator 2013-05-25T15:40:16
# -------------------------------------------------
TARGET = PlotWaveForm
QT += core \
    gui
TEMPLATE = lib
CONFIG += plugin
SOURCES += IPWFWidget.cpp \
    main.cpp \
    widget.cpp \
    plotter.cpp
HEADERS += IPWFWidget.h \
    PWFTestJigInterface.h \
    widget.h \
    plotter.h \
    Waveformclass.h \
    InterfacePTLibrary.h \
    appcardfunctiontemplate.h \
    AppdeviceRegisterDetails.h \
    ApplicationCardInterface.h \
    PTSPIMemoryInterface.h
FORMS += widget.ui
DESTDIR = /exports/nfsroot-ccwmx51js/home
RESOURCES = pwf.qrc
