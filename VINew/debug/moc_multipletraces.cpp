/****************************************************************************
** Meta object code from reading C++ file 'multipletraces.h'
**
** Created: Fri Sep 19 18:15:10 2014
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../multipletraces.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'multipletraces.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MultipleTraces[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x08,
      37,   15,   15,   15, 0x08,
      46,   15,   15,   15, 0x08,
      59,   15,   15,   15, 0x08,
      72,   15,   15,   15, 0x08,
      87,   15,   15,   15, 0x08,
     102,   15,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MultipleTraces[] = {
    "MultipleTraces\0\0on_objSave_clicked()\0"
    "onNext()\0onPrevious()\0closeAppMT()\0"
    "onPassTraces()\0onFailTraces()\0"
    "onAllTraces()\0"
};

const QMetaObject MultipleTraces::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MultipleTraces,
      qt_meta_data_MultipleTraces, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MultipleTraces::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MultipleTraces::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MultipleTraces::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MultipleTraces))
        return static_cast<void*>(const_cast< MultipleTraces*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MultipleTraces::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_objSave_clicked(); break;
        case 1: onNext(); break;
        case 2: onPrevious(); break;
        case 3: closeAppMT(); break;
        case 4: onPassTraces(); break;
        case 5: onFailTraces(); break;
        case 6: onAllTraces(); break;
        default: ;
        }
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE