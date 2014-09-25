/****************************************************************************
** Meta object code from reading C++ file 'wavedata.h'
**
** Created: Thu Sep 25 16:59:00 2014
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../wavedata.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'wavedata.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_WaveData[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x05,
      27,    9,    9,    9, 0x05,
      46,    9,    9,    9, 0x05,
      64,    9,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
      83,    9,    9,    9, 0x08,
     106,    9,    9,    9, 0x08,
     125,    9,    9,    9, 0x08,
     144,    9,    9,    9, 0x08,
     165,    9,    9,    9, 0x08,
     187,    9,    9,    9, 0x08,
     205,    9,    9,    9, 0x08,
     225,    9,    9,    9, 0x08,
     244,    9,    9,    9, 0x08,
     264,    9,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_WaveData[] = {
    "WaveData\0\0SendSamples(int)\0"
    "SendStartTick(int)\0SendStopTick(int)\0"
    "SendDutyCycle(int)\0on_pb_Cancel_clicked()\0"
    "on_pb_Ok_clicked()\0receiveValue(uint)\0"
    "receiveValue(double)\0receiveValue(QString)\0"
    "callSamplesEdit()\0callStartTickEdit()\0"
    "callStopTickEdit()\0callDutyCylceEdit()\0"
    "RxTotalSamples(int)\0"
};

const QMetaObject WaveData::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_WaveData,
      qt_meta_data_WaveData, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &WaveData::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *WaveData::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *WaveData::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_WaveData))
        return static_cast<void*>(const_cast< WaveData*>(this));
    return QDialog::qt_metacast(_clname);
}

int WaveData::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: SendSamples((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: SendStartTick((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: SendStopTick((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: SendDutyCycle((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: on_pb_Cancel_clicked(); break;
        case 5: on_pb_Ok_clicked(); break;
        case 6: receiveValue((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 7: receiveValue((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 8: receiveValue((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: callSamplesEdit(); break;
        case 10: callStartTickEdit(); break;
        case 11: callStopTickEdit(); break;
        case 12: callDutyCylceEdit(); break;
        case 13: RxTotalSamples((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void WaveData::SendSamples(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void WaveData::SendStartTick(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void WaveData::SendStopTick(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void WaveData::SendDutyCycle(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
