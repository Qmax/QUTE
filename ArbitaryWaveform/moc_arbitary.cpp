/****************************************************************************
** Meta object code from reading C++ file 'arbitary.h'
**
** Created: Thu Aug 1 12:15:33 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "arbitary.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'arbitary.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Arbitary[] = {

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
      10,    9,    9,    9, 0x08,
      37,    9,    9,    9, 0x08,
      75,    9,    9,    9, 0x08,
     119,  113,    9,    9, 0x08,
     160,    9,    9,    9, 0x08,
     185,    9,    9,    9, 0x08,
     201,    9,    9,    9, 0x08,
     223,    9,    9,    9, 0x08,
     241,    9,    9,    9, 0x08,
     261,    9,    9,    9, 0x08,
     279,  113,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Arbitary[] = {
    "Arbitary\0\0on_userDefined_2_clicked()\0"
    "on_spinAmplitude_valueChanged(double)\0"
    "on_spinFrequency_valueChanged(double)\0"
    "index\0on_cmbFrequency_currentIndexChanged(int)\0"
    "on_userDefined_clicked()\0on_dc_clicked()\0"
    "on_triangle_clicked()\0on_ramp_clicked()\0"
    "on_square_clicked()\0on_sine_clicked()\0"
    "on_cmbAmplitude_currentIndexChanged(int)\0"
};

const QMetaObject Arbitary::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Arbitary,
      qt_meta_data_Arbitary, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Arbitary::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Arbitary::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Arbitary::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Arbitary))
        return static_cast<void*>(const_cast< Arbitary*>(this));
    return QWidget::qt_metacast(_clname);
}

int Arbitary::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_userDefined_2_clicked(); break;
        case 1: on_spinAmplitude_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: on_spinFrequency_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: on_cmbFrequency_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: on_userDefined_clicked(); break;
        case 5: on_dc_clicked(); break;
        case 6: on_triangle_clicked(); break;
        case 7: on_ramp_clicked(); break;
        case 8: on_square_clicked(); break;
        case 9: on_sine_clicked(); break;
        case 10: on_cmbAmplitude_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
