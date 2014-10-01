/****************************************************************************
** Meta object code from reading C++ file 'IPTFGApp.h'
**
** Created: Wed Oct 1 21:12:36 2014
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../IPTFGApp.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'IPTFGApp.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_IPTFGApp[] = {

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

static const char qt_meta_stringdata_IPTFGApp[] = {
    "IPTFGApp\0"
};

const QMetaObject IPTFGApp::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_IPTFGApp,
      qt_meta_data_IPTFGApp, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &IPTFGApp::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *IPTFGApp::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *IPTFGApp::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_IPTFGApp))
        return static_cast<void*>(const_cast< IPTFGApp*>(this));
    if (!strcmp(_clname, "IPTFGAppInterface"))
        return static_cast< IPTFGAppInterface*>(const_cast< IPTFGApp*>(this));
    if (!strcmp(_clname, "pt.PTFGAppInterface/1.0.0.1"))
        return static_cast< IPTFGAppInterface*>(const_cast< IPTFGApp*>(this));
    return QObject::qt_metacast(_clname);
}

int IPTFGApp::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
