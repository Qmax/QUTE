/****************************************************************************
** Meta object code from reading C++ file 'digrapher.h'
**
** Created: Tue Sep 9 19:09:01 2014
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "digrapher.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'digrapher.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DIGrapher[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x08,
      31,   10,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_DIGrapher[] = {
    "DIGrapher\0\0on_ZoomIn_clicked()\0"
    "on_ZoomOut_clicked()\0"
};

const QMetaObject DIGrapher::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_DIGrapher,
      qt_meta_data_DIGrapher, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DIGrapher::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DIGrapher::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DIGrapher::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DIGrapher))
        return static_cast<void*>(const_cast< DIGrapher*>(this));
    return QWidget::qt_metacast(_clname);
}

int DIGrapher::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_ZoomIn_clicked(); break;
        case 1: on_ZoomOut_clicked(); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
