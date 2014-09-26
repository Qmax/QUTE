/****************************************************************************
** Meta object code from reading C++ file 'ptapplicationcardplugin.h'
**
** Created: Fri Sep 26 18:07:21 2014
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ptapplicationcardplugin.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ptapplicationcardplugin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PTApplicationCardPlugin[] = {

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

static const char qt_meta_stringdata_PTApplicationCardPlugin[] = {
    "PTApplicationCardPlugin\0"
};

const QMetaObject PTApplicationCardPlugin::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_PTApplicationCardPlugin,
      qt_meta_data_PTApplicationCardPlugin, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PTApplicationCardPlugin::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PTApplicationCardPlugin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PTApplicationCardPlugin::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PTApplicationCardPlugin))
        return static_cast<void*>(const_cast< PTApplicationCardPlugin*>(this));
    if (!strcmp(_clname, "IApplicationCardInterface"))
        return static_cast< IApplicationCardInterface*>(const_cast< PTApplicationCardPlugin*>(this));
    if (!strcmp(_clname, "pt.ApplicationCardInterface/1.0.0.1"))
        return static_cast< IApplicationCardInterface*>(const_cast< PTApplicationCardPlugin*>(this));
    return QObject::qt_metacast(_clname);
}

int PTApplicationCardPlugin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
