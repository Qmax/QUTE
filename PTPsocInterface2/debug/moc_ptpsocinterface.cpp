/****************************************************************************
** Meta object code from reading C++ file 'ptpsocinterface.h'
**
** Created: Wed Nov 13 18:55:31 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ptpsocinterface.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ptpsocinterface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Seriallib[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_Seriallib[] = {
    "Seriallib\0\0Error(bool)\0"
};

const QMetaObject Seriallib::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Seriallib,
      qt_meta_data_Seriallib, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Seriallib::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Seriallib::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Seriallib::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Seriallib))
        return static_cast<void*>(const_cast< Seriallib*>(this));
    return QObject::qt_metacast(_clname);
}

int Seriallib::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: Error((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void Seriallib::Error(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
static const uint qt_meta_data_PTPsocInterface[] = {

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

static const char qt_meta_stringdata_PTPsocInterface[] = {
    "PTPsocInterface\0"
};

const QMetaObject PTPsocInterface::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_PTPsocInterface,
      qt_meta_data_PTPsocInterface, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PTPsocInterface::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PTPsocInterface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PTPsocInterface::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PTPsocInterface))
        return static_cast<void*>(const_cast< PTPsocInterface*>(this));
    if (!strcmp(_clname, "IPSOCCOMMUNICATION"))
        return static_cast< IPSOCCOMMUNICATION*>(const_cast< PTPsocInterface*>(this));
    if (!strcmp(_clname, "pt.PSoCInterface/1.0.0.1"))
        return static_cast< IPSOCCOMMUNICATION*>(const_cast< PTPsocInterface*>(this));
    return QObject::qt_metacast(_clname);
}

int PTPsocInterface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
