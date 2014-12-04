/****************************************************************************
** Meta object code from reading C++ file 'daccalibration.h'
**
** Created: Wed Dec 3 10:40:14 2014
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
      20,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x08,
      38,   15,   15,   15, 0x08,
      61,   15,   15,   15, 0x08,
      89,   81,   15,   15, 0x08,
     117,   15,   15,   15, 0x08,
     147,  141,   15,   15, 0x08,
     184,   15,   15,   15, 0x08,
     205,   15,   15,   15, 0x08,
     227,   15,   15,   15, 0x08,
     248,   15,   15,   15, 0x08,
     269,   15,   15,   15, 0x08,
     290,   15,   15,   15, 0x08,
     313,   15,   15,   15, 0x08,
     335,   15,   15,   15, 0x08,
     358,   15,   15,   15, 0x08,
     381,   15,   15,   15, 0x08,
     410,  403,   15,   15, 0x08,
     429,   15,   15,   15, 0x08,
     450,   15,   15,   15, 0x08,
     472,   15,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_DACCalibration[] = {
    "DACCalibration\0\0on_drive1mA_clicked()\0"
    "on_drive10mA_clicked()\0on_saveSl_clicked()\0"
    "checked\0on_Calibrated_clicked(bool)\0"
    "on_driveBut_2_clicked()\0index\0"
    "on_comboBox_currentIndexChanged(int)\0"
    "on_nextBut_clicked()\0on_driveBut_clicked()\0"
    "on_saveBut_clicked()\0on_exitBut_clicked()\0"
    "callNoOfPointsEdit()\0callDriveCurrentEdit()\0"
    "callRxedCurrentEdit()\0callRxedCurrentEdit2()\0"
    "callRxedCurrentEdit3()\0callTestCurrentEdit()\0"
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
        case 0: on_drive1mA_clicked(); break;
        case 1: on_drive10mA_clicked(); break;
        case 2: on_saveSl_clicked(); break;
        case 3: on_Calibrated_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: on_driveBut_2_clicked(); break;
        case 5: on_comboBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: on_nextBut_clicked(); break;
        case 7: on_driveBut_clicked(); break;
        case 8: on_saveBut_clicked(); break;
        case 9: on_exitBut_clicked(); break;
        case 10: callNoOfPointsEdit(); break;
        case 11: callDriveCurrentEdit(); break;
        case 12: callRxedCurrentEdit(); break;
        case 13: callRxedCurrentEdit2(); break;
        case 14: callRxedCurrentEdit3(); break;
        case 15: callTestCurrentEdit(); break;
        case 16: receiveValue((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 17: receiveValue((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 18: receiveValue((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 19: LoopDrive(); break;
        default: ;
        }
        _id -= 20;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
