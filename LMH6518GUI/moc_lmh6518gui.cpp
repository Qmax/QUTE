/****************************************************************************
** Meta object code from reading C++ file 'lmh6518gui.h'
**
** Created: Thu Aug 8 11:03:14 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "lmh6518gui.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'lmh6518gui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_LMH6518GUI[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      36,   30,   11,   11, 0x08,
      72,   11,   11,   11, 0x08,
      91,   30,   11,   11, 0x08,
     126,   30,   11,   11, 0x08,
     165,   30,   11,   11, 0x08,
     209,  203,   11,   11, 0x08,
     241,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_LMH6518GUI[] = {
    "LMH6518GUI\0\0on_Read_clicked()\0index\0"
    "on_Voltage_currentIndexChanged(int)\0"
    "on_Write_clicked()\0"
    "on_Filter_currentIndexChanged(int)\0"
    "on_PreAmpGain_currentIndexChanged(int)\0"
    "on_PowerMode_currentIndexChanged(int)\0"
    "value\0on_Attenuater_valueChanged(int)\0"
    "on_Exit_clicked()\0"
};

const QMetaObject LMH6518GUI::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_LMH6518GUI,
      qt_meta_data_LMH6518GUI, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &LMH6518GUI::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *LMH6518GUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *LMH6518GUI::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LMH6518GUI))
        return static_cast<void*>(const_cast< LMH6518GUI*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int LMH6518GUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_Read_clicked(); break;
        case 1: on_Voltage_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: on_Write_clicked(); break;
        case 3: on_Filter_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: on_PreAmpGain_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: on_PowerMode_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: on_Attenuater_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: on_Exit_clicked(); break;
        default: ;
        }
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
