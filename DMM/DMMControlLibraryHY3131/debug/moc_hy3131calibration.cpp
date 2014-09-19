/****************************************************************************
** Meta object code from reading C++ file 'hy3131calibration.h'
**
** Created: Fri Sep 12 12:07:06 2014
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../hy3131calibration.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'hy3131calibration.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_HY3131Calibration[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      19,   18,   18,   18, 0x08,
      42,   18,   18,   18, 0x08,
      65,   18,   18,   18, 0x08,
      86,   18,   18,   18, 0x08,
     119,   18,   18,   18, 0x08,
     145,   18,   18,   18, 0x08,
     171,   18,   18,   18, 0x08,
     203,  197,   18,   18, 0x08,
     240,  197,   18,   18, 0x08,
     281,   18,   18,   18, 0x08,
     302,   18,   18,   18, 0x08,
     312,   18,   18,   18, 0x08,
     331,   18,   18,   18, 0x08,
     352,   18,   18,   18, 0x08,
     374,   18,   18,   18, 0x08,
     391,   18,   18,   18, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_HY3131Calibration[] = {
    "HY3131Calibration\0\0on_pbStopMax_clicked()\0"
    "on_pbStopMin_clicked()\0on_saveBut_clicked()\0"
    "on_pbMeasureCalibrated_clicked()\0"
    "on_calibrateBut_clicked()\0"
    "on_pbMeasureMax_clicked()\0"
    "on_pbMeasureMin_clicked()\0index\0"
    "on_cmbRange_currentIndexChanged(int)\0"
    "on_cmbComponent_currentIndexChanged(int)\0"
    "on_exitBut_clicked()\0ADCRead()\0"
    "receiveValue(uint)\0receiveValue(double)\0"
    "receiveValue(QString)\0callOffsetEdit()\0"
    "callMaxEdit()\0"
};

const QMetaObject HY3131Calibration::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_HY3131Calibration,
      qt_meta_data_HY3131Calibration, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &HY3131Calibration::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *HY3131Calibration::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *HY3131Calibration::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_HY3131Calibration))
        return static_cast<void*>(const_cast< HY3131Calibration*>(this));
    return QDialog::qt_metacast(_clname);
}

int HY3131Calibration::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_pbStopMax_clicked(); break;
        case 1: on_pbStopMin_clicked(); break;
        case 2: on_saveBut_clicked(); break;
        case 3: on_pbMeasureCalibrated_clicked(); break;
        case 4: on_calibrateBut_clicked(); break;
        case 5: on_pbMeasureMax_clicked(); break;
        case 6: on_pbMeasureMin_clicked(); break;
        case 7: on_cmbRange_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: on_cmbComponent_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: on_exitBut_clicked(); break;
        case 10: ADCRead(); break;
        case 11: receiveValue((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 12: receiveValue((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 13: receiveValue((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 14: callOffsetEdit(); break;
        case 15: callMaxEdit(); break;
        default: ;
        }
        _id -= 16;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
