/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Tue Apr 8 15:04:31 2014
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      27,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      25,   11,   11,   11, 0x08,
      47,   11,   11,   11, 0x08,
      68,   11,   11,   11, 0x08,
      87,   11,   11,   11, 0x08,
     108,   11,   11,   11, 0x08,
     136,   11,   11,   11, 0x08,
     165,   11,   11,   11, 0x08,
     193,   11,   11,   11, 0x08,
     217,   11,   11,   11, 0x08,
     241,   11,   11,   11, 0x08,
     274,   11,   11,   11, 0x08,
     307,   11,   11,   11, 0x08,
     339,   11,   11,   11, 0x08,
     372,   11,   11,   11, 0x08,
     404,   11,   11,   11, 0x08,
     439,  422,   11,   11, 0x08,
     501,  492,   11,   11, 0x08,
     539,  492,   11,   11, 0x08,
     576,  492,   11,   11, 0x08,
     616,  609,   11,   11, 0x08,
     661,  609,   11,   11, 0x08,
     704,   11,   11,   11, 0x08,
     724,   11,   11,   11, 0x08,
     744,   11,   11,   11, 0x08,
     767,   11,   11,   11, 0x08,
     790,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0clicked(int)\0on_butRIGHT_clicked()\0"
    "on_butDOWN_clicked()\0on_butUP_clicked()\0"
    "on_butLEFT_clicked()\0on_butOffset_plus_clicked()\0"
    "on_butOffset_minus_clicked()\0"
    "on_butOffset_zero_clicked()\0"
    "on_pushButton_clicked()\0on_butRUNSTOP_clicked()\0"
    "changeChannel1Widget(BASEWIDGET)\0"
    "changeChannel2Widget(BASEWIDGET)\0"
    "changeTriggerWidget(BASEWIDGET)\0"
    "changeTimeBaseWidget(BASEWIDGET)\0"
    "changeCursorsWidget(BASEWIDGET)\0"
    "doNavigation(int)\0pLstOdd,pLstEven\0"
    "doIntPlot(QList<unsigned char>,QList<unsigned char>)\0"
    "position\0on_timebaseDialWheel_sliderMoved(int)\0"
    "on_VoltageDialWheel_sliderMoved(int)\0"
    "on_triggerWheel_sliderMoved(int)\0"
    "pValue\0on_dblHorizontalTrigger_valueChanged(double)\0"
    "on_dblVerticalTrigger_valueChanged(double)\0"
    "incrementTimeDial()\0decrementTimeDial()\0"
    "incrementVoltageDial()\0decrementVoltageDial()\0"
    "checkTimeDial()\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: clicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: on_butRIGHT_clicked(); break;
        case 2: on_butDOWN_clicked(); break;
        case 3: on_butUP_clicked(); break;
        case 4: on_butLEFT_clicked(); break;
        case 5: on_butOffset_plus_clicked(); break;
        case 6: on_butOffset_minus_clicked(); break;
        case 7: on_butOffset_zero_clicked(); break;
        case 8: on_pushButton_clicked(); break;
        case 9: on_butRUNSTOP_clicked(); break;
        case 10: changeChannel1Widget((*reinterpret_cast< BASEWIDGET(*)>(_a[1]))); break;
        case 11: changeChannel2Widget((*reinterpret_cast< BASEWIDGET(*)>(_a[1]))); break;
        case 12: changeTriggerWidget((*reinterpret_cast< BASEWIDGET(*)>(_a[1]))); break;
        case 13: changeTimeBaseWidget((*reinterpret_cast< BASEWIDGET(*)>(_a[1]))); break;
        case 14: changeCursorsWidget((*reinterpret_cast< BASEWIDGET(*)>(_a[1]))); break;
        case 15: doNavigation((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: doIntPlot((*reinterpret_cast< QList<unsigned char>(*)>(_a[1])),(*reinterpret_cast< QList<unsigned char>(*)>(_a[2]))); break;
        case 17: on_timebaseDialWheel_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 18: on_VoltageDialWheel_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 19: on_triggerWheel_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 20: on_dblHorizontalTrigger_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 21: on_dblVerticalTrigger_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 22: incrementTimeDial(); break;
        case 23: decrementTimeDial(); break;
        case 24: incrementVoltageDial(); break;
        case 25: decrementVoltageDial(); break;
        case 26: checkTimeDial(); break;
        default: ;
        }
        _id -= 27;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::clicked(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
static const uint qt_meta_data_ChannelItemWidget[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      19,   18,   18,   18, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_ChannelItemWidget[] = {
    "ChannelItemWidget\0\0clicked(BASEWIDGET)\0"
};

const QMetaObject ChannelItemWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ChannelItemWidget,
      qt_meta_data_ChannelItemWidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ChannelItemWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ChannelItemWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ChannelItemWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ChannelItemWidget))
        return static_cast<void*>(const_cast< ChannelItemWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int ChannelItemWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: clicked((*reinterpret_cast< BASEWIDGET(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void ChannelItemWidget::clicked(BASEWIDGET _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
