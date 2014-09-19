/****************************************************************************
** Meta object code from reading C++ file 'adccalibration.h'
**
** Created: Wed Sep 25 16:59:36 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../adccalibration.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'adccalibration.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DACCalibration[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      22,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      24,   16,   15,   15, 0x08,
      54,   16,   15,   15, 0x08,
      82,   16,   15,   15, 0x08,
     112,   16,   15,   15, 0x08,
     140,   15,   15,   15, 0x08,
     161,   16,   15,   15, 0x08,
     186,   16,   15,   15, 0x08,
     222,  216,   15,   15, 0x08,
     261,  216,   15,   15, 0x08,
     300,   15,   15,   15, 0x08,
     324,  216,   15,   15, 0x08,
     361,   15,   15,   15, 0x08,
     382,   15,   15,   15, 0x08,
     404,   15,   15,   15, 0x08,
     425,   15,   15,   15, 0x08,
     446,   15,   15,   15, 0x08,
     467,   15,   15,   15, 0x08,
     490,   15,   15,   15, 0x08,
     519,  512,   15,   15, 0x08,
     538,   15,   15,   15, 0x08,
     559,   15,   15,   15, 0x08,
     581,   15,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_DACCalibration[] = {
    "DACCalibration\0\0checked\0"
    "on_Calibrated_4_clicked(bool)\0"
    "on_checkBox_2_clicked(bool)\0"
    "on_Calibrated_3_clicked(bool)\0"
    "on_Calibrated_clicked(bool)\0"
    "on_stopBut_clicked()\0on_loopbck_clicked(bool)\0"
    "on_Calibrated_2_clicked(bool)\0index\0"
    "on_comboBox_3_currentIndexChanged(int)\0"
    "on_comboBox_2_currentIndexChanged(int)\0"
    "on_driveBut_2_clicked()\0"
    "on_comboBox_currentIndexChanged(int)\0"
    "on_nextBut_clicked()\0on_driveBut_clicked()\0"
    "on_saveBut_clicked()\0on_exitBut_clicked()\0"
    "callNoOfPointsEdit()\0callDriveVoltageEdit()\0"
    "callTestVoltageEdit()\0pValue\0"
    "receiveValue(uint)\0receiveValue(double)\0"
    "receiveValue(QString)\0LoopDrive()\0"
};

const QMetaObject DACCalibration::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_DACCalibration,
      qt_meta_data_DACCalibration, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DACCalibration::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DACCalibration::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DACCalibration::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DACCalibration))
        return static_cast<void*>(const_cast< DACCalibration*>(this));
    return QWidget::qt_metacast(_clname);
}

int DACCalibration::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_Calibrated_4_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: on_checkBox_2_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: on_Calibrated_3_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: on_Calibrated_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: on_stopBut_clicked(); break;
        case 5: on_loopbck_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: on_Calibrated_2_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: on_comboBox_3_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: on_comboBox_2_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: on_driveBut_2_clicked(); break;
        case 10: on_comboBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: on_nextBut_clicked(); break;
        case 12: on_driveBut_clicked(); break;
        case 13: on_saveBut_clicked(); break;
        case 14: on_exitBut_clicked(); break;
        case 15: callNoOfPointsEdit(); break;
        case 16: callDriveVoltageEdit(); break;
        case 17: callTestVoltageEdit(); break;
        case 18: receiveValue((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 19: receiveValue((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 20: receiveValue((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 21: LoopDrive(); break;
        default: ;
        }
        _id -= 22;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
