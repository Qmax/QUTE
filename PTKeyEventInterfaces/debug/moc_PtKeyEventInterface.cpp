/****************************************************************************
** Meta object code from reading C++ file 'PtKeyEventInterface.h'
**
** Created: Mon Sep 1 11:56:49 2014
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../PtKeyEventInterface.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PtKeyEventInterface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PTKeyEvent[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_PTKeyEvent[] = {
    "PTKeyEvent\0\0readKbdData()\0"
};

const QMetaObject PTKeyEvent::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_PTKeyEvent,
      qt_meta_data_PTKeyEvent, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PTKeyEvent::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PTKeyEvent::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PTKeyEvent::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PTKeyEvent))
        return static_cast<void*>(const_cast< PTKeyEvent*>(this));
    if (!strcmp(_clname, "QWSKeyboardHandler"))
        return static_cast< QWSKeyboardHandler*>(const_cast< PTKeyEvent*>(this));
    return QWidget::qt_metacast(_clname);
}

int PTKeyEvent::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: readKbdData(); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}
static const uint qt_meta_data_PTKeyEventInterface[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_PTKeyEventInterface[] = {
    "PTKeyEventInterface\0"
};

const QMetaObject PTKeyEventInterface::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_PTKeyEventInterface,
      qt_meta_data_PTKeyEventInterface, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PTKeyEventInterface::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PTKeyEventInterface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PTKeyEventInterface::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PTKeyEventInterface))
        return static_cast<void*>(const_cast< PTKeyEventInterface*>(this));
    if (!strcmp(_clname, "PTEventInterface"))
        return static_cast< PTEventInterface*>(const_cast< PTKeyEventInterface*>(this));
    if (!strcmp(_clname, "pt.PTKEYEventInterface/1.0.0.1"))
        return static_cast< PTEventInterface*>(const_cast< PTKeyEventInterface*>(this));
    return QObject::qt_metacast(_clname);
}

int PTKeyEventInterface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
