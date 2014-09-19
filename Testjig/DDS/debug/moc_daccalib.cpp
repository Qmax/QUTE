/****************************************************************************
** Meta object code from reading C++ file 'daccalib.h'
**
** Created: Wed May 22 11:30:46 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../daccalib.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'daccalib.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DACCALIB[] = {

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
      10,    9,    9,    9, 0x08,
      36,    9,    9,    9, 0x08,
      57,    9,    9,    9, 0x08,
      80,    9,    9,    9, 0x08,
     109,  102,    9,    9, 0x08,
     128,    9,    9,    9, 0x08,
     149,    9,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_DACCALIB[] = {
    "DACCALIB\0\0on_pushButton_4_clicked()\0"
    "callNoOfPointsEdit()\0callDriveVoltageEdit()\0"
    "callRxedVoltageEdit()\0pValue\0"
    "receiveValue(uint)\0receiveValue(double)\0"
    "receiveValue(QString)\0"
};

const QMetaObject DACCALIB::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_DACCALIB,
      qt_meta_data_DACCALIB, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DACCALIB::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DACCALIB::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DACCALIB::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DACCALIB))
        return static_cast<void*>(const_cast< DACCALIB*>(this));
    return QDialog::qt_metacast(_clname);
}

int DACCALIB::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_pushButton_4_clicked(); break;
        case 1: callNoOfPointsEdit(); break;
        case 2: callDriveVoltageEdit(); break;
        case 3: callRxedVoltageEdit(); break;
        case 4: receiveValue((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 5: receiveValue((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: receiveValue((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
