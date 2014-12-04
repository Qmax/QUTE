/****************************************************************************
** Meta object code from reading C++ file 'dmm.h'
**
** Created: Thu Dec 4 17:06:19 2014
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../dmm.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dmm.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QmaxPushButton[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
      30,   15,   15,   15, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_QmaxPushButton[] = {
    "QmaxPushButton\0\0CClicked(int)\0pass()\0"
};

const QMetaObject QmaxPushButton::staticMetaObject = {
    { &QPushButton::staticMetaObject, qt_meta_stringdata_QmaxPushButton,
      qt_meta_data_QmaxPushButton, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QmaxPushButton::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QmaxPushButton::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QmaxPushButton::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QmaxPushButton))
        return static_cast<void*>(const_cast< QmaxPushButton*>(this));
    return QPushButton::qt_metacast(_clname);
}

int QmaxPushButton::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPushButton::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: CClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: pass(); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void QmaxPushButton::CClicked(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
static const uint qt_meta_data_DMM[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      32,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
       7,    5,    4,    4, 0x05,
      34,    5,    4,    4, 0x05,

 // slots: signature, parameters, type, tag, flags
      63,    4,    4,    4, 0x08,
      89,    4,    4,    4, 0x08,
     113,    4,    4,    4, 0x08,
     137,    4,    4,    4, 0x08,
     156,    4,    4,    4, 0x08,
     180,    4,    4,    4, 0x08,
     207,    4,    4,    4, 0x08,
     231,    4,    4,    4, 0x08,
     258,    4,    4,    4, 0x08,
     285,    4,    4,    4, 0x08,
     312,    4,    4,    4, 0x08,
     336,    4,    4,    4, 0x08,
     354,    4,    4,    4, 0x08,
     376,    4,    4,    4, 0x08,
     398,    4,    4,    4, 0x08,
     421,    4,    4,    4, 0x08,
     439,    4,    4,    4, 0x08,
     462,    4,    4,    4, 0x08,
     486,    4,    4,    4, 0x08,
     503,    4,    4,    4, 0x08,
     523,    4,    4,    4, 0x08,
     540,    4,    4,    4, 0x08,
     557,    4,    4,    4, 0x08,
     574,    4,    4,    4, 0x08,
     591,    4,    4,    4, 0x08,
     609,    4,    4,    4, 0x08,
     627,    4,    4,    4, 0x08,
     657,    4,    4,    4, 0x08,
     676,    4,    4,    4, 0x08,
     688,    5,    4,    4, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_DMM[] = {
    "DMM\0\0,\0DMM2GCalib(double,QString)\0"
    "DMM2AccuCalc(double,QString)\0"
    "on_pushButton_2_clicked()\0"
    "on_ohmMeter_3_clicked()\0on_ohmMeter_2_clicked()\0"
    "on_Diode_clicked()\0on_Continuity_clicked()\0"
    "on_pushButton_15_clicked()\0"
    "on_haadcClose_clicked()\0"
    "on_pushButton_13_clicked()\0"
    "on_pushButton_16_clicked()\0"
    "on_pushButton_14_clicked()\0"
    "on_pushButton_clicked()\0on_Null_clicked()\0"
    "on_ohmMeter_clicked()\0on_ampMeter_clicked()\0"
    "on_voltMeter_clicked()\0on_exit_clicked()\0"
    "on_leftArrow_clicked()\0on_rightArrow_clicked()\0"
    "on_r2w_clicked()\0on_manual_clicked()\0"
    "on_idc_clicked()\0on_iac_clicked()\0"
    "on_vac_clicked()\0on_vdc_clicked()\0"
    "on_hold_clicked()\0on_Auto_clicked()\0"
    "on_calibrateDisplay_clicked()\0"
    "buttonPressed(int)\0onMeasure()\0"
    "GCalib2DMM(double,QString)\0"
};

const QMetaObject DMM::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_DMM,
      qt_meta_data_DMM, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DMM::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DMM::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DMM::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DMM))
        return static_cast<void*>(const_cast< DMM*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int DMM::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: DMM2GCalib((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: DMM2AccuCalc((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: on_pushButton_2_clicked(); break;
        case 3: on_ohmMeter_3_clicked(); break;
        case 4: on_ohmMeter_2_clicked(); break;
        case 5: on_Diode_clicked(); break;
        case 6: on_Continuity_clicked(); break;
        case 7: on_pushButton_15_clicked(); break;
        case 8: on_haadcClose_clicked(); break;
        case 9: on_pushButton_13_clicked(); break;
        case 10: on_pushButton_16_clicked(); break;
        case 11: on_pushButton_14_clicked(); break;
        case 12: on_pushButton_clicked(); break;
        case 13: on_Null_clicked(); break;
        case 14: on_ohmMeter_clicked(); break;
        case 15: on_ampMeter_clicked(); break;
        case 16: on_voltMeter_clicked(); break;
        case 17: on_exit_clicked(); break;
        case 18: on_leftArrow_clicked(); break;
        case 19: on_rightArrow_clicked(); break;
        case 20: on_r2w_clicked(); break;
        case 21: on_manual_clicked(); break;
        case 22: on_idc_clicked(); break;
        case 23: on_iac_clicked(); break;
        case 24: on_vac_clicked(); break;
        case 25: on_vdc_clicked(); break;
        case 26: on_hold_clicked(); break;
        case 27: on_Auto_clicked(); break;
        case 28: on_calibrateDisplay_clicked(); break;
        case 29: buttonPressed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 30: onMeasure(); break;
        case 31: GCalib2DMM((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
        _id -= 32;
    }
    return _id;
}

// SIGNAL 0
void DMM::DMM2GCalib(double _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DMM::DMM2AccuCalc(double _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
