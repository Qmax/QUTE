/****************************************************************************
** Meta object code from reading C++ file 'widget.h'
**
** Created: Mon Jun 3 12:02:30 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../widget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Widget[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      31,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       8,    7,    7,    7, 0x08,
      27,    7,    7,    7, 0x08,
      48,    7,    7,    7, 0x08,
      70,    7,    7,    7, 0x08,
      88,    7,    7,    7, 0x08,
     103,    7,    7,    7, 0x08,
     126,    7,    7,    7, 0x08,
     146,    7,    7,    7, 0x08,
     171,    7,    7,    7, 0x08,
     192,    7,    7,    7, 0x08,
     214,    7,    7,    7, 0x08,
     237,    7,    7,    7, 0x08,
     260,    7,    7,    7, 0x08,
     283,    7,    7,    7, 0x08,
     309,    7,    7,    7, 0x08,
     335,    7,    7,    7, 0x08,
     364,    7,    7,    7, 0x08,
     387,    7,    7,    7, 0x08,
     411,    7,    7,    7, 0x08,
     432,    7,    7,    7, 0x08,
     456,    7,    7,    7, 0x08,
     466,    7,    7,    7, 0x08,
     486,    7,    7,    7, 0x08,
     512,  506,    7,    7, 0x08,
     554,  506,    7,    7, 0x08,
     596,  506,    7,    7, 0x08,
     638,  506,    7,    7, 0x08,
     678,    7,    7,    7, 0x08,
     705,    7,    7,    7, 0x08,
     733,    7,    7,    7, 0x08,
     760,    7,    7,    7, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Widget[] = {
    "Widget\0\0receiveValue(uint)\0"
    "receiveValue(double)\0receiveValue(QString)\0"
    "callAddressEdit()\0callDataEdit()\0"
    "callForceVoltageEdit()\0callFrequencyEdit()\0"
    "callAverageSamplesEdit()\0on_butRead_clicked()\0"
    "on_butWrite_clicked()\0on_chkCapSet_clicked()\0"
    "on_chkPOTSel_clicked()\0on_chkDivSel_clicked()\0"
    "on_chkReceiver1_clicked()\0"
    "on_chkReceiver2_clicked()\0"
    "on_optDifferential_clicked()\0"
    "on_optPseudo_clicked()\0on_butMeasure_clicked()\0"
    "on_butStop_clicked()\0on_butDCDrive_clicked()\0"
    "readADC()\0on_chkP1V_clicked()\0"
    "on_chkP2V_clicked()\0index\0"
    "on_cmbResistance_currentIndexChanged(int)\0"
    "on_cmbCapcitance_currentIndexChanged(int)\0"
    "on_cmbInductance_currentIndexChanged(int)\0"
    "on_cmbICMRange_currentIndexChanged(int)\0"
    "on_optResistance_clicked()\0"
    "on_optCapacitance_clicked()\0"
    "on_optInductance_clicked()\0"
    "on_chkDDSFreq_clicked()\0"
};

const QMetaObject Widget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Widget,
      qt_meta_data_Widget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Widget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Widget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Widget))
        return static_cast<void*>(const_cast< Widget*>(this));
    return QWidget::qt_metacast(_clname);
}

int Widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: receiveValue((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 1: receiveValue((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: receiveValue((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: callAddressEdit(); break;
        case 4: callDataEdit(); break;
        case 5: callForceVoltageEdit(); break;
        case 6: callFrequencyEdit(); break;
        case 7: callAverageSamplesEdit(); break;
        case 8: on_butRead_clicked(); break;
        case 9: on_butWrite_clicked(); break;
        case 10: on_chkCapSet_clicked(); break;
        case 11: on_chkPOTSel_clicked(); break;
        case 12: on_chkDivSel_clicked(); break;
        case 13: on_chkReceiver1_clicked(); break;
        case 14: on_chkReceiver2_clicked(); break;
        case 15: on_optDifferential_clicked(); break;
        case 16: on_optPseudo_clicked(); break;
        case 17: on_butMeasure_clicked(); break;
        case 18: on_butStop_clicked(); break;
        case 19: on_butDCDrive_clicked(); break;
        case 20: readADC(); break;
        case 21: on_chkP1V_clicked(); break;
        case 22: on_chkP2V_clicked(); break;
        case 23: on_cmbResistance_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 24: on_cmbCapcitance_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 25: on_cmbInductance_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 26: on_cmbICMRange_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 27: on_optResistance_clicked(); break;
        case 28: on_optCapacitance_clicked(); break;
        case 29: on_optInductance_clicked(); break;
        case 30: on_chkDDSFreq_clicked(); break;
        default: ;
        }
        _id -= 31;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
