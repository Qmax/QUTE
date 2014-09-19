/****************************************************************************
** Meta object code from reading C++ file 'testencoder.h'
**
** Created: Mon Jun 16 17:27:27 2014
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "testencoder.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'testencoder.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TestEncoder[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x08,
      33,   12,   12,   12, 0x08,
      53,   12,   12,   12, 0x08,
      63,   12,   12,   12, 0x08,
      87,   12,   12,   12, 0x08,
     105,   12,   12,   12, 0x08,
     123,   12,   12,   12, 0x08,
     141,   12,   12,   12, 0x08,
     163,  156,   12,   12, 0x08,
     182,   12,   12,   12, 0x08,
     203,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_TestEncoder[] = {
    "TestEncoder\0\0on_pbData_clicked()\0"
    "on_pbAddr_clicked()\0readSPI()\0"
    "on_pushButton_clicked()\0on_stop_clicked()\0"
    "on_exit_clicked()\0callAddressEdit()\0"
    "callDataEdit()\0pValue\0receiveValue(uint)\0"
    "receiveValue(double)\0receiveValue(QString)\0"
};

const QMetaObject TestEncoder::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_TestEncoder,
      qt_meta_data_TestEncoder, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TestEncoder::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TestEncoder::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TestEncoder::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TestEncoder))
        return static_cast<void*>(const_cast< TestEncoder*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int TestEncoder::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_pbData_clicked(); break;
        case 1: on_pbAddr_clicked(); break;
        case 2: readSPI(); break;
        case 3: on_pushButton_clicked(); break;
        case 4: on_stop_clicked(); break;
        case 5: on_exit_clicked(); break;
        case 6: callAddressEdit(); break;
        case 7: callDataEdit(); break;
        case 8: receiveValue((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 9: receiveValue((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 10: receiveValue((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
