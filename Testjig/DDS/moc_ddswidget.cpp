/****************************************************************************
** Meta object code from reading C++ file 'ddswidget.h'
**
** Created: Wed Jul 3 11:17:31 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "ddswidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ddswidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DDSWidget[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      33,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      17,   11,   10,   10, 0x08,
      56,   11,   10,   10, 0x08,
     103,   95,   10,   10, 0x08,
     130,   10,   10,   10, 0x08,
     153,   10,   10,   10, 0x08,
     177,   95,   10,   10, 0x08,
     203,   95,   10,   10, 0x08,
     237,   95,   10,   10, 0x08,
     267,   10,   10,   10, 0x08,
     290,   95,   10,   10, 0x08,
     315,   11,   10,   10, 0x08,
     352,   11,   10,   10, 0x08,
     394,   10,   10,   10, 0x08,
     416,   10,   10,   10, 0x08,
     437,   10,   10,   10, 0x08,
     463,   10,   10,   10, 0x08,
     485,   10,   10,   10, 0x08,
     506,   10,   10,   10, 0x08,
     524,   10,   10,   10, 0x08,
     539,   10,   10,   10, 0x08,
     553,   10,   10,   10, 0x08,
     566,   10,   10,   10, 0x08,
     588,   10,   10,   10, 0x08,
     606,   10,   10,   10, 0x08,
     625,   10,   10,   10, 0x08,
     643,   10,   10,   10, 0x08,
     657,   10,   10,   10, 0x08,
     671,   10,   10,   10, 0x08,
     686,   10,   10,   10, 0x08,
     714,  707,   10,   10, 0x08,
     733,   10,   10,   10, 0x08,
     754,   10,   10,   10, 0x08,
     776,   10,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_DDSWidget[] = {
    "DDSWidget\0\0index\0"
    "on_comboBox_3_currentIndexChanged(int)\0"
    "on_comboBox_2_currentIndexChanged(int)\0"
    "checked\0on_countLoop_clicked(bool)\0"
    "on_countLoop_clicked()\0on_pushButton_clicked()\0"
    "on_checkBox_clicked(bool)\0"
    "on_bkpanelSelection_clicked(bool)\0"
    "on_appSelection_clicked(bool)\0"
    "on_butUpdate_clicked()\0on_chkLoop_clicked(bool)\0"
    "on_comboBox_currentIndexChanged(int)\0"
    "on_cmbVoltRanges_currentIndexChanged(int)\0"
    "on_butDrive_clicked()\0on_butStop_clicked()\0"
    "on_butCalculate_clicked()\0"
    "on_butWrite_clicked()\0on_butRead_clicked()\0"
    "callAddressEdit()\0callDataEdit()\0"
    "callBTUEdit()\0callBDEdit()\0"
    "callOPFrequencyEdit()\0callOPPhaseEdit()\0"
    "callSTARTDLYEdit()\0callSTOPDLYEdit()\0"
    "callWDPEdit()\0callDPCEdit()\0callDDSCycle()\0"
    "callDDSVoltageEdit()\0pValue\0"
    "receiveValue(uint)\0receiveValue(double)\0"
    "receiveValue(QString)\0LoopDrive()\0"
};

const QMetaObject DDSWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_DDSWidget,
      qt_meta_data_DDSWidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DDSWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DDSWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DDSWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DDSWidget))
        return static_cast<void*>(const_cast< DDSWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int DDSWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_comboBox_3_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: on_comboBox_2_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: on_countLoop_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: on_countLoop_clicked(); break;
        case 4: on_pushButton_clicked(); break;
        case 5: on_checkBox_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: on_bkpanelSelection_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: on_appSelection_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: on_butUpdate_clicked(); break;
        case 9: on_chkLoop_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: on_comboBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: on_cmbVoltRanges_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: on_butDrive_clicked(); break;
        case 13: on_butStop_clicked(); break;
        case 14: on_butCalculate_clicked(); break;
        case 15: on_butWrite_clicked(); break;
        case 16: on_butRead_clicked(); break;
        case 17: callAddressEdit(); break;
        case 18: callDataEdit(); break;
        case 19: callBTUEdit(); break;
        case 20: callBDEdit(); break;
        case 21: callOPFrequencyEdit(); break;
        case 22: callOPPhaseEdit(); break;
        case 23: callSTARTDLYEdit(); break;
        case 24: callSTOPDLYEdit(); break;
        case 25: callWDPEdit(); break;
        case 26: callDPCEdit(); break;
        case 27: callDDSCycle(); break;
        case 28: callDDSVoltageEdit(); break;
        case 29: receiveValue((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 30: receiveValue((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 31: receiveValue((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 32: LoopDrive(); break;
        default: ;
        }
        _id -= 33;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
