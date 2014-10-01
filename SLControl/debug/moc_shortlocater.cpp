/****************************************************************************
** Meta object code from reading C++ file 'shortlocater.h'
**
** Created: Wed Oct 1 17:44:29 2014
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
      41,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x0a,
      24,   13,   13,   13, 0x0a,
      39,   13,   13,   13, 0x08,
      72,   13,   13,   13, 0x08,
      95,   13,   13,   13, 0x08,
     114,   13,   13,   13, 0x08,
     134,   13,   13,   13, 0x08,
     162,  154,   13,   13, 0x08,
     188,   13,   13,   13, 0x08,
     207,   13,   13,   13, 0x08,
     225,   13,   13,   13, 0x08,
     243,   13,   13,   13, 0x08,
     259,   13,   13,   13, 0x08,
     278,   13,   13,   13, 0x08,
     299,   13,   13,   13, 0x08,
     321,   13,   13,   13, 0x08,
     337,   13,   13,   13, 0x08,
     358,  154,   13,   13, 0x08,
     391,   13,   13,   13, 0x08,
     413,   13,   13,   13, 0x08,
     435,   13,   13,   13, 0x08,
     461,   13,   13,   13, 0x08,
     480,   13,   13,   13, 0x08,
     504,   13,   13,   13, 0x08,
     528,   13,   13,   13, 0x08,
     546,   13,   13,   13, 0x08,
     569,   13,   13,   13, 0x08,
     587,   13,   13,   13, 0x08,
     607,   13,   13,   13, 0x08,
     625,   13,   13,   13, 0x08,
     645,   13,   13,   13, 0x08,
     663,   13,   13,   13, 0x08,
     686,   13,   13,   13, 0x08,
     706,   13,   13,   13, 0x08,
     727,   13,   13,   13, 0x08,
     753,   13,   13,   13, 0x08,
     777,   13,   13,   13, 0x08,
     803,   13,   13,   13, 0x08,
     829,   13,   13,   13, 0x08,
     853,   13,   13,   13, 0x08,
     865,   13,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ShortLocater[] = {
    "ShortLocater\0\0Measure()\0Configure(int)\0"
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
        case 2: on_SpinSamples_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: on_selectApp_clicked(); break;
        case 4: on_graph_clicked(); break;
        case 5: on_newLib_clicked(); break;
        case 6: on_oldLib_clicked(); break;
        case 7: on_checkBox_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: on_right_clicked(); break;
        case 9: on_left_clicked(); break;
        case 10: on_down_clicked(); break;
        case 11: on_up_clicked(); break;
        case 12: receiveValue((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 13: receiveValue((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 14: receiveValue((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 15: DACFValueEdit(); break;
        case 16: on_butZoom_clicked(); break;
        case 17: on_openShortEnable_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 18: on_External_clicked(); break;
        case 19: on_Internal_clicked(); break;
        case 20: on_pushButton_2_clicked(); break;
        case 21: on_HAADC_clicked(); break;
        case 22: on_haadcClose_clicked(); break;
        case 23: on_pushButton_clicked(); break;
        case 24: on_hold_clicked(); break;
        case 25: on_microOhms_clicked(); break;
        case 26: on_Null_clicked(); break;
        case 27: on_offset_clicked(); break;
        case 28: on_Auto_clicked(); break;
        case 29: on_buzzer_clicked(); break;
        case 30: on_exit_clicked(); break;
        case 31: on_r200mEBut_clicked(); break;
        case 32: on_r2EBut_clicked(); break;
        case 33: on_r200But_clicked(); break;
        case 34: on_ShortCalib_2_clicked(); break;
        case 35: on_ShortCalib_clicked(); break;
        case 36: on_pushButton_5_clicked(); break;
        case 37: on_pushButton_3_clicked(); break;
        case 38: on_printImage_clicked(); break;
        case 39: startStop(); break;
        case 40: Exit(); break;
        default: ;
        }
        _id -= 41;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
