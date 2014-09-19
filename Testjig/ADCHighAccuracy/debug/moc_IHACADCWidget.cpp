/****************************************************************************
** Meta object code from reading C++ file 'IHACADCWidget.h'
**
** Created: Wed Aug 27 11:00:44 2014
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../IHACADCWidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'IHACADCWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_IHACADCWidget[] = {

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

static const char qt_meta_stringdata_IHACADCWidget[] = {
    "IHACADCWidget\0"
};

const QMetaObject IHACADCWidget::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_IHACADCWidget,
      qt_meta_data_IHACADCWidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &IHACADCWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *IHACADCWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *IHACADCWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_IHACADCWidget))
        return static_cast<void*>(const_cast< IHACADCWidget*>(this));
    if (!strcmp(_clname, "IHACADCTestJigInterface"))
        return static_cast< IHACADCTestJigInterface*>(const_cast< IHACADCWidget*>(this));
    if (!strcmp(_clname, "pt.HACADCTestJigInterface/1.0.0.1"))
        return static_cast< IHACADCTestJigInterface*>(const_cast< IHACADCWidget*>(this));
    return QObject::qt_metacast(_clname);
}

int IHACADCWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
