QT += core \
    gui
TEMPLATE = lib
CONFIG += plugin
TARGET = GCalib
HEADERS += ad5318components.h \
    GCALIBTestJigInterface.h \
    IGCALIBWidget.h \
    InterfaceFunctionalComponents.h \
    GCALIBTestJigInterface.h \
    daccalibration.h \
    PTLibraryInterfaces.h
SOURCES += IGCALIBWidget.cpp \
    daccalibration.cpp \
    main.cpp
FORMS += daccalibration.ui
DESTDIR = /exports/nfsroot-ccwmx51js/home/
RESOURCES += 
equals(TEMPLATE, lib) { 
    target.path = $${DESTDIR} # or whatever other dir
    target.extra = cp \
        $${QMAKE_PREFIX_SHLIB}$${TARGET}.$${QMAKE_EXTENSION_SHLIB} \
        /exports/nfsroot-ccwmx51js/home; \
        cp \
        $${QMAKE_PREFIX_SHLIB}$${TARGET}.$${QMAKE_EXTENSION_SHLIB} \
        /mnt/ElangovanPC/nfsroot-ccwmx51js/home;
    INSTALLS += target
}
