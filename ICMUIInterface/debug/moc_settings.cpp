/****************************************************************************
** Meta object code from reading C++ file 'settings.h'
**
** Created: Thu Dec 4 11:56:10 2014
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
      40,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x05,
      34,    9,    9,    9, 0x05,
      56,    9,    9,    9, 0x05,
      77,    9,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
      97,    9,    9,    9, 0x08,
     125,  119,    9,    9, 0x08,
     166,  119,    9,    9, 0x08,
     203,    9,    9,    9, 0x08,
     222,    9,    9,    9, 0x08,
     240,    9,    9,    9, 0x08,
     258,    9,    9,    9, 0x08,
     298,  281,  274,    9, 0x08,
     341,    9,    9,    9, 0x08,
     369,    9,    9,    9, 0x08,
     396,    9,    9,    9, 0x08,
     414,    9,    9,    9, 0x08,
     432,    9,    9,    9, 0x08,
     458,    9,    9,    9, 0x08,
     491,  483,    9,    9, 0x08,
     515,  483,    9,    9, 0x08,
     540,  483,    9,    9, 0x08,
     567,  483,    9,    9, 0x08,
     594,  483,    9,    9, 0x08,
     619,  483,    9,    9, 0x08,
     646,  483,    9,    9, 0x08,
     673,  483,    9,    9, 0x08,
     700,  483,    9,    9, 0x08,
     727,  483,    9,    9, 0x08,
     754,    9,    9,    9, 0x08,
     778,    9,    9,    9, 0x08,
     797,    9,    9,    9, 0x08,
     818,    9,    9,    9, 0x08,
     840,    9,    9,    9, 0x08,
     863,    9,    9,    9, 0x08,
     883,    9,    9,    9, 0x08,
     901,    9,    9,    9, 0x08,
     916,    9,    9,    9, 0x08,
     936,    9,    9,    9, 0x08,
     953,    9,    9,    9, 0x08,
     966,    9,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Settings[] = {
    "Settings\0\0FrequencyChange(double)\0"
    "SrcImpChange(QString)\0OffsetChange(double)\0"
    "FeedbackChange(int)\0on_applySrc_clicked()\0"
    "index\0on_srcImpBox_10_currentIndexChanged(int)\0"
    "on_comboBox_currentIndexChanged(int)\0"
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
        case 1: SrcImpChange((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: OffsetChange((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: FeedbackChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: on_applySrc_clicked(); break;
        case 5: on_srcImpBox_10_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: on_comboBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: on_right_clicked(); break;
        case 8: on_left_clicked(); break;
        case 9: on_down_clicked(); break;
        case 10: on_up_clicked(); break;
        case 11: { double _r = validateCursorPosition((*reinterpret_cast< short(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< short(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 12: on_WriteAppCard_2_clicked(); break;
        case 13: on_ReadAppCard_2_clicked(); break;
        case 14: on_adc2_clicked(); break;
        case 15: on_adc1_clicked(); break;
        case 16: on_WriteAppCard_clicked(); break;
        case 17: on_ReadAppCard_clicked(); break;
        case 18: on_ExtInt_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 19: on_R2RMSIN_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 20: on_R2RMSGAIN_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 21: on_R2RMSCAVG_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 22: on_R1RMSIN_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 23: on_R1RMSGAIN_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 24: on_R1RMSCAVG_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 25: on_chkDivSel_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 26: on_chkPOTSel_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 27: on_chkCapSet_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 28: on_pushButton_clicked(); break;
        case 29: receiveValue((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 30: receiveValue((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 31: receiveValue((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 32: callForceVoltageEdit(); break;
        case 33: callFrequencyEdit(); break;
        case 34: callAddressEdit(); break;
        case 35: callDataEdit(); break;
        case 36: callBPAddressEdit(); break;
        case 37: callBPDataEdit(); break;
        case 38: callOffset(); break;
        case 39: callDCVoltage(); break;
        default: ;
        }
        _id -= 40;
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
void Settings::SrcImpChange(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Settings::OffsetChange(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Settings::FeedbackChange(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
