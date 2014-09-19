# -------------------------------------------------
# Project created by QtCreator 2013-05-28T11:37:18
# -------------------------------------------------
TARGET = APPCardDRVRECE
QT += core \
    gui
TEMPLATE = lib
CONFIG += plugin
SOURCES += IAPPRXDRVWidget.cpp \
    main.cpp \
    ptappcarddrvrecev.cpp
HEADERS += APPRXDRVTestJigInterface.h \
    IAPPRXDRVWidget.h \
    PTLibraryInterfaces.h \
    ptappcarddrvrecev.h \
    ApplicationCardInterface.h \
    AppdeviceRegisterDetails.h \
    appcardfunctiontemplate.h \
    BackPlaneInterface.h \
    PTLibraryInterfaces.h
FORMS += ptappcarddrvrecev.ui
DESTDIR = /exports/nfsroot-ccwmx51js/home
RESOURCES = appdrvrx.qrc
