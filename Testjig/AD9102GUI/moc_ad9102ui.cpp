/****************************************************************************
** Meta object code from reading C++ file 'ad9102ui.h'
**
** Created: Fri Jan 3 14:22:56 2014
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "ad9102ui.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ad9102ui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_AD9102UI[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      29,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x08,
      34,    9,    9,    9, 0x08,
      61,    9,    9,    9, 0x08,
      86,    9,    9,    9, 0x08,
     112,    9,    9,    9, 0x08,
     137,    9,    9,    9, 0x08,
     166,  160,    9,    9, 0x08,
     203,    9,    9,    9, 0x08,
     229,    9,    9,    9, 0x08,
     253,    9,    9,    9, 0x08,
     275,    9,    9,    9, 0x08,
     296,    9,    9,    9, 0x08,
     321,    9,    9,    9, 0x08,
     345,    9,    9,    9, 0x08,
     367,    9,    9,    9, 0x08,
     388,    9,    9,    9, 0x08,
     407,    9,    9,    9, 0x08,
     428,    9,    9,    9, 0x08,
     450,    9,    9,    9, 0x08,
     468,    9,    9,    9, 0x08,
     483,    9,    9,    9, 0x08,
     504,    9,    9,    9, 0x08,
     522,    9,    9,    9, 0x08,
     534,    9,    9,    9, 0x08,
     552,    9,    9,    9, 0x08,
     567,    9,    9,    9, 0x08,
     590,    9,    9,    9, 0x08,
     606,    9,    9,    9, 0x08,
     622,    9,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_AD9102UI[] = {
    "AD9102UI\0\0on_pb_TestRUN_clicked()\0"
    "on_pb_SRAMUpdate_clicked()\0"
    "on_pb_SRAMLoad_clicked()\0"
    "on_pb_SRAMWrite_clicked()\0"
    "on_pb_SRAMRead_clicked()\0"
    "on_pb_Update_clicked()\0index\0"
    "on_comboBox_currentIndexChanged(int)\0"
    "on_pb_TestWrite_clicked()\0"
    "on_pb_Trigger_clicked()\0on_pb_Reset_clicked()\0"
    "on_pb_Test_clicked()\0on_pb_AppWrite_clicked()\0"
    "on_pb_AppRead_clicked()\0on_pb_Write_clicked()\0"
    "on_pb_Read_clicked()\0receiveValue(uint)\0"
    "receiveValue(double)\0receiveValue(QString)\0"
    "callAddressEdit()\0callDataEdit()\0"
    "callAppAddressEdit()\0callAppDataEdit()\0"
    "callDelay()\0callSRAMAddress()\0"
    "callSRAMData()\0callSRAMStartAddress()\0"
    "callSRAMCount()\0callFrequency()\0"
    "callPhase()\0"
};

const QMetaObject AD9102UI::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_AD9102UI,
      qt_meta_data_AD9102UI, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &AD9102UI::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *AD9102UI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *AD9102UI::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AD9102UI))
        return static_cast<void*>(const_cast< AD9102UI*>(this));
    return QWidget::qt_metacast(_clname);
}

int AD9102UI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_pb_TestRUN_clicked(); break;
        case 1: on_pb_SRAMUpdate_clicked(); break;
        case 2: on_pb_SRAMLoad_clicked(); break;
        case 3: on_pb_SRAMWrite_clicked(); break;
        case 4: on_pb_SRAMRead_clicked(); break;
        case 5: on_pb_Update_clicked(); break;
        case 6: on_comboBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: on_pb_TestWrite_clicked(); break;
        case 8: on_pb_Trigger_clicked(); break;
        case 9: on_pb_Reset_clicked(); break;
        case 10: on_pb_Test_clicked(); break;
        case 11: on_pb_AppWrite_clicked(); break;
        case 12: on_pb_AppRead_clicked(); break;
        case 13: on_pb_Write_clicked(); break;
        case 14: on_pb_Read_clicked(); break;
        case 15: receiveValue((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 16: receiveValue((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 17: receiveValue((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 18: callAddressEdit(); break;
        case 19: callDataEdit(); break;
        case 20: callAppAddressEdit(); break;
        case 21: callAppDataEdit(); break;
        case 22: callDelay(); break;
        case 23: callSRAMAddress(); break;
        case 24: callSRAMData(); break;
        case 25: callSRAMStartAddress(); break;
        case 26: callSRAMCount(); break;
        case 27: callFrequency(); break;
        case 28: callPhase(); break;
        default: ;
        }
        _id -= 29;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
