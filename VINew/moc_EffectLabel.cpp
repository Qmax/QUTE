/****************************************************************************
** Meta object code from reading C++ file 'EffectLabel.h'
**
** Created: Wed Oct 30 10:37:19 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "EffectLabel.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'EffectLabel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_EffectLabel[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       1,   14, // properties
       1,   17, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
      19,   12, 0x0009510b,

 // enums: name, flags, count, data
      12, 0x0,    3,   21,

 // enum data: key, value
      26, uint(EffectLabel::Plain),
      32, uint(EffectLabel::Sunken),
      39, uint(EffectLabel::Raised),

       0        // eod
};

static const char qt_meta_stringdata_EffectLabel[] = {
    "EffectLabel\0Effect\0effect\0Plain\0Sunken\0"
    "Raised\0"
};

const QMetaObject EffectLabel::staticMetaObject = {
    { &QLabel::staticMetaObject, qt_meta_stringdata_EffectLabel,
      qt_meta_data_EffectLabel, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &EffectLabel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *EffectLabel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *EffectLabel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_EffectLabel))
        return static_cast<void*>(const_cast< EffectLabel*>(this));
    return QLabel::qt_metacast(_clname);
}

int EffectLabel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLabel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
     if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< Effect*>(_v) = effect(); break;
        }
        _id -= 1;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setEffect(*reinterpret_cast< Effect*>(_v)); break;
        }
        _id -= 1;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_END_MOC_NAMESPACE
