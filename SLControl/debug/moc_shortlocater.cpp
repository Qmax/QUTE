/****************************************************************************
** Meta object code from reading C++ file 'shortlocater.h'
**
** Created: Tue Dec 2 09:57:23 2014
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../shortlocater.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'shortlocater.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ShortLocater[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      46,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x0a,
      24,   13,   13,   13, 0x0a,
      39,   13,   13,   13, 0x08,
      58,   13,   13,   13, 0x08,
      80,   13,   13,   13, 0x08,
     102,   13,   13,   13, 0x08,
     121,   13,   13,   13, 0x08,
     142,   13,   13,   13, 0x08,
     175,   13,   13,   13, 0x08,
     198,   13,   13,   13, 0x08,
     217,   13,   13,   13, 0x08,
     237,   13,   13,   13, 0x08,
     265,  257,   13,   13, 0x08,
     291,   13,   13,   13, 0x08,
     310,   13,   13,   13, 0x08,
     328,   13,   13,   13, 0x08,
     346,   13,   13,   13, 0x08,
     362,   13,   13,   13, 0x08,
     381,   13,   13,   13, 0x08,
     402,   13,   13,   13, 0x08,
     424,   13,   13,   13, 0x08,
     440,   13,   13,   13, 0x08,
     461,  257,   13,   13, 0x08,
     494,   13,   13,   13, 0x08,
     516,   13,   13,   13, 0x08,
     538,   13,   13,   13, 0x08,
     564,   13,   13,   13, 0x08,
     583,   13,   13,   13, 0x08,
     607,   13,   13,   13, 0x08,
     631,   13,   13,   13, 0x08,
     649,   13,   13,   13, 0x08,
     672,   13,   13,   13, 0x08,
     690,   13,   13,   13, 0x08,
     710,   13,   13,   13, 0x08,
     728,   13,   13,   13, 0x08,
     748,   13,   13,   13, 0x08,
     766,   13,   13,   13, 0x08,
     789,   13,   13,   13, 0x08,
     809,   13,   13,   13, 0x08,
     830,   13,   13,   13, 0x08,
     856,   13,   13,   13, 0x08,
     880,   13,   13,   13, 0x08,
     906,   13,   13,   13, 0x08,
     932,   13,   13,   13, 0x08,
     956,   13,   13,   13, 0x08,
     968,   13,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ShortLocater[] = {
    "ShortLocater\0\0Measure()\0Configure(int)\0"
    "shortCalibration()\0on_settings_clicked()\0"
    "on_but200mE_clicked()\0on_but2E_clicked()\0"
    "on_but200E_clicked()\0"
    "on_SpinSamples_valueChanged(int)\0"
    "on_selectApp_clicked()\0on_graph_clicked()\0"
    "on_newLib_clicked()\0on_oldLib_clicked()\0"
    "checked\0on_checkBox_clicked(bool)\0"
    "on_right_clicked()\0on_left_clicked()\0"
    "on_down_clicked()\0on_up_clicked()\0"
    "receiveValue(uint)\0receiveValue(double)\0"
    "receiveValue(QString)\0DACFValueEdit()\0"
    "on_butZoom_clicked()\0"
    "on_openShortEnable_clicked(bool)\0"
    "on_External_clicked()\0on_Internal_clicked()\0"
    "on_pushButton_2_clicked()\0on_HAADC_clicked()\0"
    "on_haadcClose_clicked()\0on_pushButton_clicked()\0"
    "on_hold_clicked()\0on_microOhms_clicked()\0"
    "on_Null_clicked()\0on_offset_clicked()\0"
    "on_Auto_clicked()\0on_buzzer_clicked()\0"
    "on_exit_clicked()\0on_r200mEBut_clicked()\0"
    "on_r2EBut_clicked()\0on_r200But_clicked()\0"
    "on_ShortCalib_2_clicked()\0"
    "on_ShortCalib_clicked()\0"
    "on_pushButton_5_clicked()\0"
    "on_pushButton_3_clicked()\0"
    "on_printImage_clicked()\0startStop()\0"
    "Exit()\0"
};

const QMetaObject ShortLocater::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ShortLocater,
      qt_meta_data_ShortLocater, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ShortLocater::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ShortLocater::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ShortLocater::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ShortLocater))
        return static_cast<void*>(const_cast< ShortLocater*>(this));
    return QWidget::qt_metacast(_clname);
}

int ShortLocater::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: Measure(); break;
        case 1: Configure((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: shortCalibration(); break;
        case 3: on_settings_clicked(); break;
        case 4: on_but200mE_clicked(); break;
        case 5: on_but2E_clicked(); break;
        case 6: on_but200E_clicked(); break;
        case 7: on_SpinSamples_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: on_selectApp_clicked(); break;
        case 9: on_graph_clicked(); break;
        case 10: on_newLib_clicked(); break;
        case 11: on_oldLib_clicked(); break;
        case 12: on_checkBox_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: on_right_clicked(); break;
        case 14: on_left_clicked(); break;
        case 15: on_down_clicked(); break;
        case 16: on_up_clicked(); break;
        case 17: receiveValue((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 18: receiveValue((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 19: receiveValue((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 20: DACFValueEdit(); break;
        case 21: on_butZoom_clicked(); break;
        case 22: on_openShortEnable_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 23: on_External_clicked(); break;
        case 24: on_Internal_clicked(); break;
        case 25: on_pushButton_2_clicked(); break;
        case 26: on_HAADC_clicked(); break;
        case 27: on_haadcClose_clicked(); break;
        case 28: on_pushButton_clicked(); break;
        case 29: on_hold_clicked(); break;
        case 30: on_microOhms_clicked(); break;
        case 31: on_Null_clicked(); break;
        case 32: on_offset_clicked(); break;
        case 33: on_Auto_clicked(); break;
        case 34: on_buzzer_clicked(); break;
        case 35: on_exit_clicked(); break;
        case 36: on_r200mEBut_clicked(); break;
        case 37: on_r2EBut_clicked(); break;
        case 38: on_r200But_clicked(); break;
        case 39: on_ShortCalib_2_clicked(); break;
        case 40: on_ShortCalib_clicked(); break;
        case 41: on_pushButton_5_clicked(); break;
        case 42: on_pushButton_3_clicked(); break;
        case 43: on_printImage_clicked(); break;
        case 44: startStop(); break;
        case 45: Exit(); break;
        default: ;
        }
        _id -= 46;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
