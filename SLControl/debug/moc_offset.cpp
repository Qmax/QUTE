/****************************************************************************
** Meta object code from reading C++ file 'offset.h'
**
** Created: Mon Dec 1 17:31:59 2014
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../offset.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'offset.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_offset[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       8,    7,    7,    7, 0x08,
      32,    7,    7,    7, 0x08,
      47,    7,    7,    7, 0x08,
      66,    7,    7,    7, 0x08,
      87,    7,    7,    7, 0x08,
     109,    7,    7,    7, 0x08,
     128,    7,    7,    7, 0x08,
     145,    7,    7,    7, 0x08,
     165,    7,    7,    7, 0x08,
     184,    7,    7,    7, 0x08,
     203,    7,    7,    7, 0x08,
     220,    7,    7,    7, 0x08,
     240,    7,    7,    7, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_offset[] = {
    "offset\0\0on_pushButton_clicked()\0"
    "callDACFEdit()\0receiveValue(uint)\0"
    "receiveValue(double)\0receiveValue(QString)\0"
    "on_Gdown_clicked()\0on_Gup_clicked()\0"
    "on_Gright_clicked()\0on_Gleft_clicked()\0"
    "on_Fdown_clicked()\0on_Fup_clicked()\0"
    "on_Fright_clicked()\0on_Fleft_clicked()\0"
};

const QMetaObject offset::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_offset,
      qt_meta_data_offset, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &offset::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *offset::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *offset::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_offset))
        return static_cast<void*>(const_cast< offset*>(this));
    return QWidget::qt_metacast(_clname);
}

int offset::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_pushButton_clicked(); break;
        case 1: callDACFEdit(); break;
        case 2: receiveValue((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 3: receiveValue((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: receiveValue((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: on_Gdown_clicked(); break;
        case 6: on_Gup_clicked(); break;
        case 7: on_Gright_clicked(); break;
        case 8: on_Gleft_clicked(); break;
        case 9: on_Fdown_clicked(); break;
        case 10: on_Fup_clicked(); break;
        case 11: on_Fright_clicked(); break;
        case 12: on_Fleft_clicked(); break;
        default: ;
        }
        _id -= 13;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
