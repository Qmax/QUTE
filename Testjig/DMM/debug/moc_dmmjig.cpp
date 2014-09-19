/****************************************************************************
** Meta object code from reading C++ file 'dmmjig.h'
**
** Created: Thu Aug 14 18:16:45 2014
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../dmmjig.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dmmjig.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DMMJig[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      26,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      16,    8,    7,    7, 0x08,
      44,    8,    7,    7, 0x08,
      78,   72,    7,    7, 0x08,
     116,    7,    7,    7, 0x08,
     138,    7,    7,    7, 0x08,
     159,    7,    7,    7, 0x08,
     185,    7,    7,    7, 0x08,
     209,    8,    7,    7, 0x08,
     240,    8,    7,    7, 0x08,
     271,    8,    7,    7, 0x08,
     302,    8,    7,    7, 0x08,
     333,    8,    7,    7, 0x08,
     364,    8,    7,    7, 0x08,
     393,   72,    7,    7, 0x08,
     436,   72,    7,    7, 0x08,
     479,   72,    7,    7, 0x08,
     520,   72,    7,    7, 0x08,
     562,    7,    7,    7, 0x08,
     581,    7,    7,    7, 0x08,
     602,    7,    7,    7, 0x08,
     624,    7,    7,    7, 0x08,
     642,    7,    7,    7, 0x08,
     657,    7,    7,    7, 0x08,
     675,    7,    7,    7, 0x08,
     698,    7,    7,    7, 0x08,
     715,    7,    7,    7, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_DMMJig[] = {
    "DMMJig\0\0checked\0on_checkBox_3_clicked(bool)\0"
    "on_checkBox_2_clicked(bool)\0index\0"
    "on_cmbOffset_currentIndexChanged(int)\0"
    "on_butWrite_clicked()\0on_butRead_clicked()\0"
    "on_pushButton_2_clicked()\0"
    "on_pushButton_clicked()\0"
    "on_radioButton_6_clicked(bool)\0"
    "on_radioButton_4_clicked(bool)\0"
    "on_radioButton_5_clicked(bool)\0"
    "on_radioButton_3_clicked(bool)\0"
    "on_radioButton_2_clicked(bool)\0"
    "on_radioButton_clicked(bool)\0"
    "on_cmbImpedance_3_currentIndexChanged(int)\0"
    "on_cmbImpedance_2_currentIndexChanged(int)\0"
    "on_cmbImpedance_currentIndexChanged(int)\0"
    "on_cmbDrvVoltage_currentIndexChanged(int)\0"
    "receiveValue(uint)\0receiveValue(double)\0"
    "receiveValue(QString)\0callAddressEdit()\0"
    "callDataEdit()\0callSamplesEdit()\0"
    "callForceCurrentEdit()\0callDACVoltage()\0"
    "LoopDrive()\0"
};

const QMetaObject DMMJig::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_DMMJig,
      qt_meta_data_DMMJig, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DMMJig::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DMMJig::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DMMJig::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DMMJig))
        return static_cast<void*>(const_cast< DMMJig*>(this));
    return QWidget::qt_metacast(_clname);
}

int DMMJig::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_checkBox_3_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: on_checkBox_2_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: on_cmbOffset_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: on_butWrite_clicked(); break;
        case 4: on_butRead_clicked(); break;
        case 5: on_pushButton_2_clicked(); break;
        case 6: on_pushButton_clicked(); break;
        case 7: on_radioButton_6_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: on_radioButton_4_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: on_radioButton_5_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: on_radioButton_3_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: on_radioButton_2_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: on_radioButton_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: on_cmbImpedance_3_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: on_cmbImpedance_2_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: on_cmbImpedance_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: on_cmbDrvVoltage_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: receiveValue((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 18: receiveValue((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 19: receiveValue((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 20: callAddressEdit(); break;
        case 21: callDataEdit(); break;
        case 22: callSamplesEdit(); break;
        case 23: callForceCurrentEdit(); break;
        case 24: callDACVoltage(); break;
        case 25: LoopDrive(); break;
        default: ;
        }
        _id -= 26;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
