# -------------------------------------------------
# Project created by QtCreator 2013-10-29T17:25:20
# -------------------------------------------------
TARGET = VIInterface
CONFIG += plugin
TEMPLATE = lib

# TARGET = VINew
# TEMPLATE = app
SOURCES += mutlipewavedialog.cpp \
    ptviinterface.cpp \
    autocurvefittraces.cpp \
    multipletraces.cpp \
    clipdialog.cpp \
    colors.cpp \
    qmaxbutton.cpp \
    visettings.cpp \
    selectprobe.cpp \
    embeddedkeys.cpp \
    main.cpp \
    mainwindow.cpp \
    vimodelview.cpp \
    plotter.cpp \
    vifunctionallogic.cpp \
    vidataclas.cpp \
    vihwclass.cpp \
    ad5318components.cpp \
    ad5293.cpp
HEADERS += AD5318TestJigInterface.h \
    serialdevice.h \
    serialdevice.h \
    mutlipewavedialog.h \
    ptviinterface.h \
    autocurvefittraces.h \
    multipletraces.h \
    clipdialog.h \
    colors.h \
    qmaxbutton.h \
    visettings.h \
    selectprobe.h \
    embeddedkeys.h \
    mainwindow.h \
    vihwclass.h \
    vimodelview.h \
    plotter.h \
    vidataclas.h \
    vifunctionallogic.h \
    CalibrationInterfaces.h \
    BackPlaneInterface.h \
    ApplicationCardInterface.h \
    AppdeviceRegisterDetails.h \
    appcardfunctiontemplate.h \
    InterfaceFunctionalComponents.h \
    IPSOCCommunication.h \
    PTGPIOEventInterfaces.h \
    PTEventInterfaces.h \
    PTSPIMemoryInterface.h \
    ad5293.h \
    ad5318components.h \
    appcardcomponents.h \
    RLCInterface.h \
    PTSplashScreen.h \
    interfaceHeader.h
FORMS += mutlipewavedialog.ui \
    autocurvefittraces.ui \
    multipletraces.ui \
    clipdialog.ui \
    visettings.ui \
    selectprobe.ui \
    embeddedkeys.ui \
    mainwindow.ui
RESOURCES += fp_res.qrc \
    vi.qrc
DESTDIR = /exports/nfsroot-ccwmx51js/home/
