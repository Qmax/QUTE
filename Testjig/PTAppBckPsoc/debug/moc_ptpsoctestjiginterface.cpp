/****************************************************************************
** Meta object code from reading C++ file 'ptpsoctestjiginterface.h'
**
** Created: Sat Nov 1 10:47:50 2014
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ptpsoctestjiginterface.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ptpsoctestjiginterface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PTPSoCTestJigInterface[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      30,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      24,   23,   23,   23, 0x08,
      48,   23,   23,   23, 0x08,
      71,   23,   23,   23, 0x08,
      97,   23,   23,   23, 0x08,
     127,  121,   23,   23, 0x08,
     167,   23,   23,   23, 0x08,
     193,   23,   23,   23, 0x08,
     219,   23,   23,   23, 0x08,
     245,   23,   23,   23, 0x08,
     271,   23,   23,   23, 0x08,
     297,   23,   23,   23, 0x08,
     323,   23,   23,   23, 0x08,
     347,   23,   23,   23, 0x08,
     373,   23,   23,   23, 0x08,
     398,   23,   23,   23, 0x08,
     411,   23,   23,   23, 0x08,
     425,   23,   23,   23, 0x08,
     439,   23,   23,   23, 0x08,
     458,   23,   23,   23, 0x08,
     472,   23,   23,   23, 0x08,
     486,   23,   23,   23, 0x08,
     500,   23,   23,   23, 0x08,
     514,   23,   23,   23, 0x08,
     528,   23,   23,   23, 0x08,
     542,   23,   23,   23, 0x08,
     557,   23,   23,   23, 0x08,
     579,   23,   23,   23, 0x08,
     595,   23,   23,   23, 0x08,
     614,   23,   23,   23, 0x08,
     635,   23,   23,   23, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_PTPSoCTestJigInterface[] = {
    "PTPSoCTestJigInterface\0\0on_pbGenWrite_clicked()\0"
    "on_pbGenRead_clicked()\0on_pushButton_7_clicked()\0"
    "on_topRelay24_clicked()\0index\0"
    "on_comboBox_13_currentIndexChanged(int)\0"
    "on_pushButton_6_clicked()\0"
    "on_pushButton_4_clicked()\0"
    "on_pushButton_3_clicked()\0"
    "on_pushButton_8_clicked()\0"
    "on_pushButton_9_clicked()\0"
    "on_pushButton_2_clicked()\0"
    "on_pushButton_clicked()\0"
    "on_pushButton_5_clicked()\0"
    "on_butSeqWrite_clicked()\0ReadRelays()\0"
    "ResetRelays()\0SendCommand()\0"
    "callCommandInput()\0callAppAddr()\0"
    "callAppData()\0callBckAddr()\0callBckData()\0"
    "callGenData()\0callGenAddr()\0callBaseAddr()\0"
    "CommandSelection(int)\0psocError(bool)\0"
    "receiveValue(uint)\0receiveValue(double)\0"
    "receiveValue(QString)\0"
};

const QMetaObject PTPSoCTestJigInterface::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_PTPSoCTestJigInterface,
      qt_meta_data_PTPSoCTestJigInterface, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PTPSoCTestJigInterface::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PTPSoCTestJigInterface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PTPSoCTestJigInterface::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PTPSoCTestJigInterface))
        return static_cast<void*>(const_cast< PTPSoCTestJigInterface*>(this));
    return QWidget::qt_metacast(_clname);
}

int PTPSoCTestJigInterface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_pbGenWrite_clicked(); break;
        case 1: on_pbGenRead_clicked(); break;
        case 2: on_pushButton_7_clicked(); break;
        case 3: on_topRelay24_clicked(); break;
        case 4: on_comboBox_13_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: on_pushButton_6_clicked(); break;
        case 6: on_pushButton_4_clicked(); break;
        case 7: on_pushButton_3_clicked(); break;
        case 8: on_pushButton_8_clicked(); break;
        case 9: on_pushButton_9_clicked(); break;
        case 10: on_pushButton_2_clicked(); break;
        case 11: on_pushButton_clicked(); break;
        case 12: on_pushButton_5_clicked(); break;
        case 13: on_butSeqWrite_clicked(); break;
        case 14: ReadRelays(); break;
        case 15: ResetRelays(); break;
        case 16: SendCommand(); break;
        case 17: callCommandInput(); break;
        case 18: callAppAddr(); break;
        case 19: callAppData(); break;
        case 20: callBckAddr(); break;
        case 21: callBckData(); break;
        case 22: callGenData(); break;
        case 23: callGenAddr(); break;
        case 24: callBaseAddr(); break;
        case 25: CommandSelection((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 26: psocError((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 27: receiveValue((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 28: receiveValue((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 29: receiveValue((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 30;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
