# -------------------------------------------------
# Project created by QtCreator 2013-12-31T10:00:53
# -------------------------------------------------
TARGET = AD9102GUI
TEMPLATE = lib
CONFIG += plugin
SOURCES += IAD9102Widget.cpp \
    main.cpp \
    ad9102ui.cpp \
    AD9102.cpp
HEADERS += IAD9102Widget.h \
    AD9102TestJigInterface.h \
    InterfaceFunctionalComponents.h \
    appcardcomponents.h \
    ad9102ui.h \
    appcardfunctiontemplate.h \
    AppdeviceRegisterDetails.h \
    ApplicationCardInterface.h \
    InterfacePTLibrary.h \
    AD9102.h
FORMS += ad9102ui.ui
RESOURCES = ad9102.qrc
