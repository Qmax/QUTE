/***********************************************************
***************Created by Ravivarman.R,Qmax*****************
***********************************************************/
/****************************************************************************
** Meta object code from reading C++ file 'hy3131calibration.h'
**
** Created: Mon Mar 24 17:51:37 2014
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "hy3131calibration.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'hy3131calibration.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_HY3131Calibration[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      21,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      27,   19,   18,   18, 0x08,
      60,   19,   18,   18, 0x08,
      92,   18,   18,   18, 0x08,
     112,   18,   18,   18, 0x08,
     132,   19,   18,   18, 0x08,
     164,   18,   18,   18, 0x08,
     187,   18,   18,   18, 0x08,
     210,   18,   18,   18, 0x08,
     231,   18,   18,   18, 0x08,
     264,   18,   18,   18, 0x08,
     290,   18,   18,   18, 0x08,
     316,   18,   18,   18, 0x08,
     348,  342,   18,   18, 0x08,
     385,  342,   18,   18, 0x08,
     426,   18,   18,   18, 0x08,
     447,   18,   18,   18, 0x08,
     457,   18,   18,   18, 0x08,
     476,   18,   18,   18, 0x08,
     497,   18,   18,   18, 0x08,
     519,   18,   18,   18, 0x08,
     536,   18,   18,   18, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_HY3131Calibration[] = {
    "HY3131Calibration\0\0checked\0"
    "on_CompCalibration_clicked(bool)\0"
    "on_IndCalibration_clicked(bool)\0"
    "on_KClear_clicked()\0on_KReset_clicked()\0"
    "on_selectKeithley_clicked(bool)\0"
    "on_pbStopMax_clicked()\0on_pbStopMin_clicked()\0"
    "on_saveBut_clicked()\0"
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
        case 0: on_CompCalibration_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: on_IndCalibration_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: on_KClear_clicked(); break;
        case 3: on_KReset_clicked(); break;
        case 4: on_selectKeithley_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: on_pbStopMax_clicked(); break;
        case 6: on_pbStopMin_clicked(); break;
        case 7: on_saveBut_clicked(); break;
        case 8: on_pbMeasureCalibrated_clicked(); break;
        case 9: on_calibrateBut_clicked(); break;
        case 10: on_pbMeasureMax_clicked(); break;
        case 11: on_pbMeasureMin_clicked(); break;
        case 12: on_cmbRange_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: on_cmbComponent_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: on_exitBut_clicked(); break;
        case 15: ADCRead(); break;
        case 16: receiveValue((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 17: receiveValue((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 18: receiveValue((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 19: callOffsetEdit(); break;
        case 20: callMaxEdit(); break;
        default: ;
        }
        _id -= 21;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
