/****************************************************************************
** Meta object code from reading C++ file 'flashMemory.h'
**
** Created: Wed Dec 3 10:53:14 2014
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../flashMemory.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'flashMemory.h' doesn't include <QObject>."
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
      32,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,    8,    7,    7, 0x08,
      54,    7,    7,    7, 0x08,
      76,    7,    7,    7, 0x08,
      97,    7,    7,    7, 0x08,
     122,    7,    7,    7, 0x08,
     148,    7,    7,    7, 0x08,
     173,    7,    7,    7, 0x08,
     198,    7,    7,    7, 0x08,
     221,    7,    7,    7, 0x08,
     243,    7,    7,    7, 0x08,
     262,    7,    7,    7, 0x08,
     283,    7,    7,    7, 0x08,
     305,    7,    7,    7, 0x08,
     325,    7,    7,    7, 0x08,
     344,    7,    7,    7, 0x08,
     362,    7,    7,    7, 0x08,
     381,    7,    7,    7, 0x08,
     401,    7,    7,    7, 0x08,
     421,    7,    7,    7, 0x08,
     438,  436,    7,    7, 0x08,
     463,    7,    7,    7, 0x08,
     492,    7,    7,    7, 0x08,
     512,    7,    7,    7, 0x08,
     532,    7,    7,    7, 0x08,
     554,    7,    7,    7, 0x08,
     581,    7,    7,    7, 0x08,
     603,    7,    7,    7, 0x08,
     625,    7,    7,    7, 0x08,
     647,    7,    7,    7, 0x08,
     669,    7,    7,    7, 0x08,
     692,    7,    7,    7, 0x08,
     714,    7,    7,    7, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Widget[] = {
    "Widget\0\0index\0on_cmbHWSelect_currentIndexChanged(int)\0"
    "on_butWrite_clicked()\0on_butRead_clicked()\0"
    "on_butReadSave_clicked()\0"
    "on_butPageErase_clicked()\0"
    "on_butSaveFile_clicked()\0"
    "on_butLoadFile_clicked()\0"
    "on_butCODEID_clicked()\0on_butErase_clicked()\0"
    "receiveValue(uint)\0receiveValue(double)\0"
    "receiveValue(QString)\0callstAddressEdit()\0"
    "callAddrCoutEdit()\0callEndAddrEdit()\0"
    "callIndexLocEdit()\0callPageEraseEdit()\0"
    "callDataCountEdit()\0callDataEdit()\0,\0"
    "setAddressIndex(int,int)\0"
    "on_optSystemMemory_clicked()\0"
    "on_optDDR_clicked()\0on_optRAM_clicked()\0"
    "on_optFlash_clicked()\0on_optReceiveRAM_clicked()\0"
    "on_optSlot0_clicked()\0on_optSlot1_clicked()\0"
    "on_optSlot2_clicked()\0on_optSlot3_clicked()\0"
    "on_chkSingle_clicked()\0on_optZeros_clicked()\0"
    "on_optFFs_clicked()\0"
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
        case 0: on_cmbHWSelect_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: on_butWrite_clicked(); break;
        case 2: on_butRead_clicked(); break;
        case 3: on_butReadSave_clicked(); break;
        case 4: on_butPageErase_clicked(); break;
        case 5: on_butSaveFile_clicked(); break;
        case 6: on_butLoadFile_clicked(); break;
        case 7: on_butCODEID_clicked(); break;
        case 8: on_butErase_clicked(); break;
        case 9: receiveValue((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 10: receiveValue((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 11: receiveValue((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 12: callstAddressEdit(); break;
        case 13: callAddrCoutEdit(); break;
        case 14: callEndAddrEdit(); break;
        case 15: callIndexLocEdit(); break;
        case 16: callPageEraseEdit(); break;
        case 17: callDataCountEdit(); break;
        case 18: callDataEdit(); break;
        case 19: setAddressIndex((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 20: on_optSystemMemory_clicked(); break;
        case 21: on_optDDR_clicked(); break;
        case 22: on_optRAM_clicked(); break;
        case 23: on_optFlash_clicked(); break;
        case 24: on_optReceiveRAM_clicked(); break;
        case 25: on_optSlot0_clicked(); break;
        case 26: on_optSlot1_clicked(); break;
        case 27: on_optSlot2_clicked(); break;
        case 28: on_optSlot3_clicked(); break;
        case 29: on_chkSingle_clicked(); break;
        case 30: on_optZeros_clicked(); break;
        case 31: on_optFFs_clicked(); break;
        default: ;
        }
        _id -= 32;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
