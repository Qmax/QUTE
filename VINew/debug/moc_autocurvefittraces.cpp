/****************************************************************************
** Meta object code from reading C++ file 'autocurvefittraces.h'
**
** Created: Thu Oct 16 17:39:23 2014
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../autocurvefittraces.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'autocurvefittraces.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_AutoCurveFitTraces[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      20,   19,   19,   19, 0x08,
      39,   19,   19,   19, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_AutoCurveFitTraces[] = {
    "AutoCurveFitTraces\0\0on_print_clicked()\0"
    "closeApp()\0"
};

const QMetaObject AutoCurveFitTraces::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_AutoCurveFitTraces,
      qt_meta_data_AutoCurveFitTraces, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &AutoCurveFitTraces::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *AutoCurveFitTraces::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *AutoCurveFitTraces::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AutoCurveFitTraces))
        return static_cast<void*>(const_cast< AutoCurveFitTraces*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int AutoCurveFitTraces::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_print_clicked(); break;
        case 1: closeApp(); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
