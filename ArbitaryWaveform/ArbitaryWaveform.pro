# -------------------------------------------------
# Project created by QtCreator 2013-07-10T15:15:53
# -------------------------------------------------
TARGET = ArbitaryWaveform
QT += core \
    gui
TEMPLATE = lib
CONFIG += plugin
SOURCES += IAWGUIInterface.cpp \
    plotter.cpp \
    main.cpp \
    arbitary.cpp
HEADERS += AWG/AppdeviceRegisterDetails.h \
    ApplicationCardInterface.h \
    appcardfunctiontemplate.h \
    AppdeviceRegisterDetails.h \
    ApplicationCardInterface.h \
    appcardfunctiontemplate.h \
    IAWGUIInterface.h \
    AWGUIInterface.h \
    Waveformclass.h \
    plotter.h \
    arbitary.h \
    Waveformclass.h
FORMS += arbitary.ui
RESOURCES += arbitary.qrc
DESTDIR = /exports/nfsroot-ccwmx51js/home
