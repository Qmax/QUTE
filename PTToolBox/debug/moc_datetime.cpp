/****************************************************************************
** Meta object code from reading C++ file 'datetime.h'
**
** Created: Wed Dec 3 18:22:57 2014
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../datetime.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'datetime.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DateTime[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x08,
      37,   32,    9,    9, 0x08,
      80,    9,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_DateTime[] = {
    "DateTime\0\0on_pb_Apply_clicked()\0date\0"
    "on_dateTimeEdit_dateTimeChanged(QDateTime)\0"
    "on_pb_exit_clicked()\0"
};

const QMetaObject DateTime::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_DateTime,
      qt_meta_data_DateTime, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DateTime::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DateTime::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DateTime::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DateTime))
        return static_cast<void*>(const_cast< DateTime*>(this));
    return QWidget::qt_metacast(_clname);
}

int DateTime::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_pb_Apply_clicked(); break;
        case 1: on_dateTimeEdit_dateTimeChanged((*reinterpret_cast< QDateTime(*)>(_a[1]))); break;
        case 2: on_pb_exit_clicked(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
