/****************************************************************************
** Meta object code from reading C++ file 'ptpsoctestjiginterface.h'
**
** Created: Sun Sep 1 13:09:26 2013
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
      33,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      24,   23,   23,   23, 0x08,
      37,   23,   23,   23, 0x08,
      49,   23,   23,   23, 0x08,
      62,   23,   23,   23, 0x08,
      75,   23,   23,   23, 0x08,
      89,   23,   23,   23, 0x08,
     103,   23,   23,   23, 0x08,
     116,   23,   23,   23, 0x08,
     131,   23,   23,   23, 0x08,
     151,   23,   23,   23, 0x08,
     166,   23,   23,   23, 0x08,
     189,   23,   23,   23, 0x08,
     206,   23,   23,   23, 0x08,
     219,   23,   23,   23, 0x08,
     231,   23,   23,   23, 0x08,
     243,   23,   23,   23, 0x08,
     256,   23,   23,   23, 0x08,
     275,   23,   23,   23, 0x08,
     294,   23,   23,   23, 0x08,
     317,   23,   23,   23, 0x08,
     335,   23,   23,   23, 0x08,
     361,   23,   23,   23, 0x08,
     382,   23,   23,   23, 0x08,
     403,   23,   23,   23, 0x08,
     418,   23,   23,   23, 0x08,
     437,   23,   23,   23, 0x08,
     455,   23,   23,   23, 0x08,
     474,   23,   23,   23, 0x08,
     488,   23,   23,   23, 0x08,
     510,   23,   23,   23, 0x08,
     526,   23,   23,   23, 0x08,
     545,   23,   23,   23, 0x08,
     566,   23,   23,   23, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_PTPSoCTestJigInterface[] = {
    "PTPSoCTestJigInterface\0\0TestButton()\0"
    "SwitchMux()\0ReadCodeID()\0ReadRelays()\0"
    "ResetRelays()\0SendCommand()\0Multimeter()\0"
    "Oscilloscope()\0FunctionGenerator()\0"
    "ShortLocator()\0InCircuitMeasurement()\0"
    "VoltageCurrent()\0Voltage(int)\0R2Wire(int)\0"
    "R4Wire(int)\0Current(int)\0Oscilloscope1(int)\0"
    "Oscilloscope2(int)\0FunctionGenerater(int)\0"
    "ShortLocater(int)\0InCircuitMeasureMent(int)\0"
    "VoltageCurrent1(int)\0VoltageCurrent2(int)\0"
    "MuxInputs(int)\0callMuxTestInput()\0"
    "callMuxRefInput()\0callCommandInput()\0"
    "EmbeddedKey()\0CommandSelection(int)\0"
    "psocError(bool)\0receiveValue(uint)\0"
    "receiveValue(double)\0receiveValue(QString)\0"
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
        case 0: TestButton(); break;
        case 1: SwitchMux(); break;
        case 2: ReadCodeID(); break;
        case 3: ReadRelays(); break;
        case 4: ResetRelays(); break;
        case 5: SendCommand(); break;
        case 6: Multimeter(); break;
        case 7: Oscilloscope(); break;
        case 8: FunctionGenerator(); break;
        case 9: ShortLocator(); break;
        case 10: InCircuitMeasurement(); break;
        case 11: VoltageCurrent(); break;
        case 12: Voltage((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: R2Wire((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: R4Wire((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: Current((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: Oscilloscope1((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: Oscilloscope2((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 18: FunctionGenerater((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 19: ShortLocater((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 20: InCircuitMeasureMent((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 21: VoltageCurrent1((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 22: VoltageCurrent2((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 23: MuxInputs((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 24: callMuxTestInput(); break;
        case 25: callMuxRefInput(); break;
        case 26: callCommandInput(); break;
        case 27: EmbeddedKey(); break;
        case 28: CommandSelection((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 29: psocError((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 30: receiveValue((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 31: receiveValue((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 32: receiveValue((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 33;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
