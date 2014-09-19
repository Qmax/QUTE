/****************************************************************************
** Meta object code from reading C++ file 'QDigitalClock.h'
**
** Created: Fri Sep 5 13:06:07 2014
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../QDigitalClock.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QDigitalClock.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QDigitalClock[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x0a,
      36,   14,   14,   14, 0x0a,
      55,   14,   14,   14, 0x0a,
      72,   14,   14,   14, 0x0a,
     100,   14,   14,   14, 0x0a,
     117,   14,   14,   14, 0x0a,
     131,   14,   14,   14, 0x0a,
     147,   14,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_QDigitalClock[] = {
    "QDigitalClock\0\0SetTextColor(QColor)\0"
    "SetFormat(QString)\0SetInterval(int)\0"
    "SetAlignment(Qt::Alignment)\0"
    "ResetTextColor()\0ResetFormat()\0"
    "ResetInterval()\0ResetAlignment()\0"
};

const QMetaObject QDigitalClock::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_QDigitalClock,
      qt_meta_data_QDigitalClock, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QDigitalClock::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QDigitalClock::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QDigitalClock::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QDigitalClock))
        return static_cast<void*>(const_cast< QDigitalClock*>(this));
    return QWidget::qt_metacast(_clname);
}

int QDigitalClock::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: SetTextColor((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 1: SetFormat((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: SetInterval((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: SetAlignment((*reinterpret_cast< Qt::Alignment(*)>(_a[1]))); break;
        case 4: ResetTextColor(); break;
        case 5: ResetFormat(); break;
        case 6: ResetInterval(); break;
        case 7: ResetAlignment(); break;
        default: ;
        }
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
