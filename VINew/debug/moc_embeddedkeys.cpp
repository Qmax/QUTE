/****************************************************************************
** Meta object code from reading C++ file 'embeddedkeys.h'
**
** Created: Mon Nov 24 17:15:45 2014
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../embeddedkeys.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'embeddedkeys.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_EmbeddedKeys[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x08,
      36,   13,   13,   13, 0x08,
      59,   13,   13,   13, 0x08,
      80,   13,   13,   13, 0x08,
     102,   13,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_EmbeddedKeys[] = {
    "EmbeddedKeys\0\0on_butRigth_clicked()\0"
    "on_butMiddle_clicked()\0on_butLeft_clicked()\0"
    "on_butClose_clicked()\0"
    "on_cmbCombinationKeys_currentIndexChanged(QString)\0"
};

const QMetaObject EmbeddedKeys::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_EmbeddedKeys,
      qt_meta_data_EmbeddedKeys, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &EmbeddedKeys::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *EmbeddedKeys::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *EmbeddedKeys::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_EmbeddedKeys))
        return static_cast<void*>(const_cast< EmbeddedKeys*>(this));
    if (!strcmp(_clname, "IVIObserver"))
        return static_cast< IVIObserver*>(const_cast< EmbeddedKeys*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int EmbeddedKeys::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_butRigth_clicked(); break;
        case 1: on_butMiddle_clicked(); break;
        case 2: on_butLeft_clicked(); break;
        case 3: on_butClose_clicked(); break;
        case 4: on_cmbCombinationKeys_currentIndexChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
