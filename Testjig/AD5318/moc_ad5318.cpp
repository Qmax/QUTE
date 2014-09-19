/****************************************************************************
** Meta object code from reading C++ file 'ad5318.h'
**
** Created: Mon May 27 11:29:28 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "ad5318.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ad5318.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_AD5318[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       8,    7,    7,    7, 0x08,
      29,    7,    7,    7, 0x08,
      50,    7,    7,    7, 0x08,
      71,    7,    7,    7, 0x08,
      92,    7,    7,    7, 0x08,
     113,    7,    7,    7, 0x08,
     134,    7,    7,    7, 0x08,
     155,    7,    7,    7, 0x08,
     176,    7,    7,    7, 0x08,
     202,    7,    7,    7, 0x08,
     224,    7,    7,    7, 0x08,
     245,    7,    7,    7, 0x08,
     263,    7,    7,    7, 0x08,
     278,    7,    7,    7, 0x08,
     306,  299,    7,    7, 0x08,
     325,    7,    7,    7, 0x08,
     346,    7,    7,    7, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_AD5318[] = {
    "AD5318\0\0on_chkDACH_clicked()\0"
    "on_chkDACG_clicked()\0on_chkDACF_clicked()\0"
    "on_chkDACE_clicked()\0on_chkDACD_clicked()\0"
    "on_chkDACC_clicked()\0on_chkDACB_clicked()\0"
    "on_chkDACA_clicked()\0on_butUpdateDAC_clicked()\0"
    "on_butWrite_clicked()\0on_butRead_clicked()\0"
    "callAddressEdit()\0callDataEdit()\0"
    "callDACVoltageEdit()\0pValue\0"
    "receiveValue(uint)\0receiveValue(double)\0"
    "receiveValue(QString)\0"
};

const QMetaObject AD5318::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_AD5318,
      qt_meta_data_AD5318, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &AD5318::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *AD5318::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *AD5318::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AD5318))
        return static_cast<void*>(const_cast< AD5318*>(this));
    return QWidget::qt_metacast(_clname);
}

int AD5318::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_chkDACH_clicked(); break;
        case 1: on_chkDACG_clicked(); break;
        case 2: on_chkDACF_clicked(); break;
        case 3: on_chkDACE_clicked(); break;
        case 4: on_chkDACD_clicked(); break;
        case 5: on_chkDACC_clicked(); break;
        case 6: on_chkDACB_clicked(); break;
        case 7: on_chkDACA_clicked(); break;
        case 8: on_butUpdateDAC_clicked(); break;
        case 9: on_butWrite_clicked(); break;
        case 10: on_butRead_clicked(); break;
        case 11: callAddressEdit(); break;
        case 12: callDataEdit(); break;
        case 13: callDACVoltageEdit(); break;
        case 14: receiveValue((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 15: receiveValue((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 16: receiveValue((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 17;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
