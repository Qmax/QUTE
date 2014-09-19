/****************************************************************************
** Meta object code from reading C++ file 'ptpsoctestjiginterface2.h'
**
** Created: Thu Aug 14 14:50:31 2014
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ptpsoctestjiginterface2.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ptpsoctestjiginterface2.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PTPSoCTestJigInterface2[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      37,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      25,   24,   24,   24, 0x08,
      48,   24,   24,   24, 0x08,
      80,   74,   24,   24, 0x08,
     120,   24,   24,   24, 0x08,
     137,   24,   24,   24, 0x08,
     150,   24,   24,   24, 0x08,
     162,   24,   24,   24, 0x08,
     175,   24,   24,   24, 0x08,
     188,   24,   24,   24, 0x08,
     202,   24,   24,   24, 0x08,
     216,   24,   24,   24, 0x08,
     229,   24,   24,   24, 0x08,
     244,   24,   24,   24, 0x08,
     264,   24,   24,   24, 0x08,
     279,   24,   24,   24, 0x08,
     302,   24,   24,   24, 0x08,
     319,   24,   24,   24, 0x08,
     332,   24,   24,   24, 0x08,
     344,   24,   24,   24, 0x08,
     356,   24,   24,   24, 0x08,
     369,   24,   24,   24, 0x08,
     388,   24,   24,   24, 0x08,
     407,   24,   24,   24, 0x08,
     430,   24,   24,   24, 0x08,
     448,   24,   24,   24, 0x08,
     474,   24,   24,   24, 0x08,
     495,   24,   24,   24, 0x08,
     516,   24,   24,   24, 0x08,
     531,   24,   24,   24, 0x08,
     550,   24,   24,   24, 0x08,
     568,   24,   24,   24, 0x08,
     587,   24,   24,   24, 0x08,
     601,   24,   24,   24, 0x08,
     623,   24,   24,   24, 0x08,
     639,   24,   24,   24, 0x08,
     658,   24,   24,   24, 0x08,
     679,   24,   24,   24, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_PTPSoCTestJigInterface2[] = {
    "PTPSoCTestJigInterface2\0\0"
    "on_switchFLY_clicked()\0on_switchSRCIMP_clicked()\0"
    "index\0on_comboBox_10_currentIndexChanged(int)\0"
    "EnDisSRCIM(bool)\0TestButton()\0SwitchMux()\0"
    "ReadCodeID()\0ReadRelays()\0ResetRelays()\0"
    "SendCommand()\0Multimeter()\0Oscilloscope()\0"
    "FunctionGenerator()\0ShortLocator()\0"
    "InCircuitMeasurement()\0VoltageCurrent()\0"
    "Voltage(int)\0R2Wire(int)\0R4Wire(int)\0"
    "Current(int)\0Oscilloscope1(int)\0"
    "Oscilloscope2(int)\0FunctionGenerater(int)\0"
    "ShortLocater(int)\0InCircuitMeasureMent(int)\0"
    "VoltageCurrent1(int)\0VoltageCurrent2(int)\0"
    "MuxInputs(int)\0callMuxTestInput()\0"
    "callMuxRefInput()\0callCommandInput()\0"
    "EmbeddedKey()\0CommandSelection(int)\0"
    "psocError(bool)\0receiveValue(uint)\0"
    "receiveValue(double)\0receiveValue(QString)\0"
};

const QMetaObject PTPSoCTestJigInterface2::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_PTPSoCTestJigInterface2,
      qt_meta_data_PTPSoCTestJigInterface2, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PTPSoCTestJigInterface2::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PTPSoCTestJigInterface2::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PTPSoCTestJigInterface2::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PTPSoCTestJigInterface2))
        return static_cast<void*>(const_cast< PTPSoCTestJigInterface2*>(this));
    return QWidget::qt_metacast(_clname);
}

int PTPSoCTestJigInterface2::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_switchFLY_clicked(); break;
        case 1: on_switchSRCIMP_clicked(); break;
        case 2: on_comboBox_10_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: EnDisSRCIM((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: TestButton(); break;
        case 5: SwitchMux(); break;
        case 6: ReadCodeID(); break;
        case 7: ReadRelays(); break;
        case 8: ResetRelays(); break;
        case 9: SendCommand(); break;
        case 10: Multimeter(); break;
        case 11: Oscilloscope(); break;
        case 12: FunctionGenerator(); break;
        case 13: ShortLocator(); break;
        case 14: InCircuitMeasurement(); break;
        case 15: VoltageCurrent(); break;
        case 16: Voltage((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: R2Wire((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 18: R4Wire((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 19: Current((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 20: Oscilloscope1((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 21: Oscilloscope2((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 22: FunctionGenerater((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 23: ShortLocater((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 24: InCircuitMeasureMent((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 25: VoltageCurrent1((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 26: VoltageCurrent2((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 27: MuxInputs((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 28: callMuxTestInput(); break;
        case 29: callMuxRefInput(); break;
        case 30: callCommandInput(); break;
        case 31: EmbeddedKey(); break;
        case 32: CommandSelection((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 33: psocError((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 34: receiveValue((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 35: receiveValue((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 36: receiveValue((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 37;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
