# -------------------------------------------------
# Project created by QtCreator 2013-02-05T17:04:01
# -------------------------------------------------
QT += core
TARGET = QmaxPTInterface
TEMPLATE = lib
CONFIG += plugin

# DESTDIR = $$[QT_INSTALL_PLUGINS]/codecs
SOURCES += qmaxmessagebox.cpp \
    qmaxptinterface.cpp \
    widget.cpp \
    qmaxbutton.cpp \
    numberpanel.cpp \
    myLineEdit.cpp \
    myinputpanel.cpp \
    displayinfo.cpp \
    colors.cpp \
    qmaxptlibrary.cpp
HEADERS += qmaxmessagebox.h \
    qmaxptinterface.h \
    ui_widget.h \
    ui_NumberWidget.h \
    qmaxbutton.h \
    ui_displayinfo.h \
    ui_myinputpanelform.h \
    ui_numberpanel.h \
    numberpanel.h \
    myLineEdit.h \
    myinputpanel.h \
    displayinfo.h \
    colors.h \
    InterfacePTLibrary.h \
    qmaxptlibrary.h \
    widget.h \
    PTLibraryInterfaces.h
FORMS += widget.ui \
    numberpanel.ui \
    myinputpanelform.ui \
    displayinfo.ui
RESOURCES = qmaxptresource.qrc
DESTDIR = /exports/nfsroot-ccwmx51js/home