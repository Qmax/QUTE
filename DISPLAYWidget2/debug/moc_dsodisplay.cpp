/****************************************************************************
** Meta object code from reading C++ file 'dsodisplay.h'
**
** Created: Tue Sep 30 17:19:21 2014
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../dsodisplay.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dsodisplay.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DSODisplay[] = {

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

static const char qt_meta_stringdata_DSODisplay[] = {
    "DSODisplay\0"
};

const QMetaObject DSODisplay::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_DSODisplay,
      qt_meta_data_DSODisplay, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DSODisplay::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DSODisplay::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DSODisplay::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DSODisplay))
        return static_cast<void*>(const_cast< DSODisplay*>(this));
    return QWidget::qt_metacast(_clname);
}

int DSODisplay::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_DSODisplayInterface[] = {

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

static const char qt_meta_stringdata_DSODisplayInterface[] = {
    "DSODisplayInterface\0"
};

const QMetaObject DSODisplayInterface::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_DSODisplayInterface,
      qt_meta_data_DSODisplayInterface, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DSODisplayInterface::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DSODisplayInterface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DSODisplayInterface::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DSODisplayInterface))
        return static_cast<void*>(const_cast< DSODisplayInterface*>(this));
    if (!strcmp(_clname, "DisplayWidgetInterface"))
        return static_cast< DisplayWidgetInterface*>(const_cast< DSODisplayInterface*>(this));
    if (!strcmp(_clname, "pt.displaywidgetInterface/1.0.0.1"))
        return static_cast< DisplayWidgetInterface*>(const_cast< DSODisplayInterface*>(this));
    return QObject::qt_metacast(_clname);
}

int DSODisplayInterface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
