/****************************************************************************
** Meta object code from reading C++ file 'gpioeventinterface.h'
**
** Created: Sat Oct 25 19:02:23 2014
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../gpioeventinterface.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gpioeventinterface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GpioEventInterface[] = {

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

static const char qt_meta_stringdata_GpioEventInterface[] = {
    "GpioEventInterface\0"
};

const QMetaObject GpioEventInterface::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_GpioEventInterface,
      qt_meta_data_GpioEventInterface, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GpioEventInterface::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GpioEventInterface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GpioEventInterface::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GpioEventInterface))
        return static_cast<void*>(const_cast< GpioEventInterface*>(this));
    if (!strcmp(_clname, "PTGPIOEventInterface"))
        return static_cast< PTGPIOEventInterface*>(const_cast< GpioEventInterface*>(this));
    if (!strcmp(_clname, "pt.PTEventInterface/1.0.0.1"))
        return static_cast< PTGPIOEventInterface*>(const_cast< GpioEventInterface*>(this));
    return QObject::qt_metacast(_clname);
}

int GpioEventInterface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_GPIOEvent[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      13,   11,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
      64,   10,   10,   10, 0x08,
      78,   10,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_GPIOEvent[] = {
    "GPIOEvent\0\0,\0"
    "postAPP(QList<unsigned char>,QList<unsigned char>)\0"
    "readKbdData()\0readMouseData()\0"
};

const QMetaObject GPIOEvent::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_GPIOEvent,
      qt_meta_data_GPIOEvent, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GPIOEvent::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GPIOEvent::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GPIOEvent::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GPIOEvent))
        return static_cast<void*>(const_cast< GPIOEvent*>(this));
    if (!strcmp(_clname, "QWSKeyboardHandler"))
        return static_cast< QWSKeyboardHandler*>(const_cast< GPIOEvent*>(this));
    return QWidget::qt_metacast(_clname);
}

int GPIOEvent::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: postAPP((*reinterpret_cast< QList<unsigned char>(*)>(_a[1])),(*reinterpret_cast< QList<unsigned char>(*)>(_a[2]))); break;
        case 1: readKbdData(); break;
        case 2: readMouseData(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void GPIOEvent::postAPP(QList<unsigned char> _t1, QList<unsigned char> _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
