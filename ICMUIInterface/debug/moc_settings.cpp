/****************************************************************************
** Meta object code from reading C++ file 'settings.h'
**
** Created: Mon Sep 29 16:21:01 2014
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../settings.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'settings.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Settings[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      37,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x05,
      34,    9,    9,    9, 0x05,
      55,    9,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
      81,   75,    9,    9, 0x08,
     118,    9,    9,    9, 0x08,
     137,    9,    9,    9, 0x08,
     155,    9,    9,    9, 0x08,
     173,    9,    9,    9, 0x08,
     213,  196,  189,    9, 0x08,
     256,    9,    9,    9, 0x08,
     284,    9,    9,    9, 0x08,
     311,    9,    9,    9, 0x08,
     329,    9,    9,    9, 0x08,
     347,    9,    9,    9, 0x08,
     373,    9,    9,    9, 0x08,
     406,  398,    9,    9, 0x08,
     430,  398,    9,    9, 0x08,
     455,  398,    9,    9, 0x08,
     482,  398,    9,    9, 0x08,
     509,  398,    9,    9, 0x08,
     534,  398,    9,    9, 0x08,
     561,  398,    9,    9, 0x08,
     588,  398,    9,    9, 0x08,
     615,  398,    9,    9, 0x08,
     642,  398,    9,    9, 0x08,
     669,    9,    9,    9, 0x08,
     693,    9,    9,    9, 0x08,
     712,    9,    9,    9, 0x08,
     733,    9,    9,    9, 0x08,
     755,    9,    9,    9, 0x08,
     778,    9,    9,    9, 0x08,
     798,    9,    9,    9, 0x08,
     816,    9,    9,    9, 0x08,
     831,    9,    9,    9, 0x08,
     851,    9,    9,    9, 0x08,
     868,    9,    9,    9, 0x08,
     881,    9,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Settings[] = {
    "Settings\0\0FrequencyChange(double)\0"
    "OffsetChange(double)\0FeedbackChange(int)\0"
    "index\0on_comboBox_currentIndexChanged(int)\0"
    "on_right_clicked()\0on_left_clicked()\0"
    "on_down_clicked()\0on_up_clicked()\0"
    "double\0pos,value,incDec\0"
    "validateCursorPosition(short,double,short)\0"
    "on_WriteAppCard_2_clicked()\0"
    "on_ReadAppCard_2_clicked()\0on_adc2_clicked()\0"
    "on_adc1_clicked()\0on_WriteAppCard_clicked()\0"
    "on_ReadAppCard_clicked()\0checked\0"
    "on_ExtInt_clicked(bool)\0"
    "on_R2RMSIN_clicked(bool)\0"
    "on_R2RMSGAIN_clicked(bool)\0"
    "on_R2RMSCAVG_clicked(bool)\0"
    "on_R1RMSIN_clicked(bool)\0"
    "on_R1RMSGAIN_clicked(bool)\0"
    "on_R1RMSCAVG_clicked(bool)\0"
    "on_chkDivSel_clicked(bool)\0"
    "on_chkPOTSel_clicked(bool)\0"
    "on_chkCapSet_clicked(bool)\0"
    "on_pushButton_clicked()\0receiveValue(uint)\0"
    "receiveValue(double)\0receiveValue(QString)\0"
    "callForceVoltageEdit()\0callFrequencyEdit()\0"
    "callAddressEdit()\0callDataEdit()\0"
    "callBPAddressEdit()\0callBPDataEdit()\0"
    "callOffset()\0callDCVoltage()\0"
};

const QMetaObject Settings::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Settings,
      qt_meta_data_Settings, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Settings::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Settings::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Settings::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Settings))
        return static_cast<void*>(const_cast< Settings*>(this));
    return QWidget::qt_metacast(_clname);
}

int Settings::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: FrequencyChange((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 1: OffsetChange((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: FeedbackChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: on_comboBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: on_right_clicked(); break;
        case 5: on_left_clicked(); break;
        case 6: on_down_clicked(); break;
        case 7: on_up_clicked(); break;
        case 8: { double _r = validateCursorPosition((*reinterpret_cast< short(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< short(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 9: on_WriteAppCard_2_clicked(); break;
        case 10: on_ReadAppCard_2_clicked(); break;
        case 11: on_adc2_clicked(); break;
        case 12: on_adc1_clicked(); break;
        case 13: on_WriteAppCard_clicked(); break;
        case 14: on_ReadAppCard_clicked(); break;
        case 15: on_ExtInt_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 16: on_R2RMSIN_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 17: on_R2RMSGAIN_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 18: on_R2RMSCAVG_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 19: on_R1RMSIN_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 20: on_R1RMSGAIN_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 21: on_R1RMSCAVG_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 22: on_chkDivSel_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 23: on_chkPOTSel_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 24: on_chkCapSet_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 25: on_pushButton_clicked(); break;
        case 26: receiveValue((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 27: receiveValue((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 28: receiveValue((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 29: callForceVoltageEdit(); break;
        case 30: callFrequencyEdit(); break;
        case 31: callAddressEdit(); break;
        case 32: callDataEdit(); break;
        case 33: callBPAddressEdit(); break;
        case 34: callBPDataEdit(); break;
        case 35: callOffset(); break;
        case 36: callDCVoltage(); break;
        default: ;
        }
        _id -= 37;
    }
    return _id;
}

// SIGNAL 0
void Settings::FrequencyChange(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Settings::OffsetChange(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Settings::FeedbackChange(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
