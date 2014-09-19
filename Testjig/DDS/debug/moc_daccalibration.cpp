/****************************************************************************
** Meta object code from reading C++ file 'daccalibration.h'
**
** Created: Sat Sep 6 10:53:39 2014
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../daccalibration.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'daccalibration.h' doesn't include <QObject>."
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
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x08,
      46,   40,   15,   15, 0x08,
      83,   15,   15,   15, 0x08,
     104,   15,   15,   15, 0x08,
     126,   15,   15,   15, 0x08,
     147,   15,   15,   15, 0x08,
     168,   15,   15,   15, 0x08,
     189,   15,   15,   15, 0x08,
     212,   15,   15,   15, 0x08,
     234,   15,   15,   15, 0x08,
     263,  256,   15,   15, 0x08,
     282,   15,   15,   15, 0x08,
     303,   15,   15,   15, 0x08,
     325,   15,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_DACCalibration[] = {
    "DACCalibration\0\0on_driveBut_2_clicked()\0"
    "index\0on_comboBox_currentIndexChanged(int)\0"
    "on_nextBut_clicked()\0on_driveBut_clicked()\0"
    "on_saveBut_clicked()\0on_exitBut_clicked()\0"
    "callNoOfPointsEdit()\0callDriveVoltageEdit()\0"
    "callRxedVoltageEdit()\0callTestVoltageEdit()\0"
    "pValue\0receiveValue(uint)\0"
    "receiveValue(double)\0receiveValue(QString)\0"
    "LoopDrive()\0"
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
        case 0: on_driveBut_2_clicked(); break;
        case 1: on_comboBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: on_nextBut_clicked(); break;
        case 3: on_driveBut_clicked(); break;
        case 4: on_saveBut_clicked(); break;
        case 5: on_exitBut_clicked(); break;
        case 6: callNoOfPointsEdit(); break;
        case 7: callDriveVoltageEdit(); break;
        case 8: callRxedVoltageEdit(); break;
        case 9: callTestVoltageEdit(); break;
        case 10: receiveValue((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 11: receiveValue((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 12: receiveValue((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 13: LoopDrive(); break;
        default: ;
        }
        _id -= 14;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
