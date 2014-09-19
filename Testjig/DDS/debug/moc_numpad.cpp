/****************************************************************************
** Meta object code from reading C++ file 'numpad.h'
**
** Created: Wed May 22 15:28:34 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../numpad.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'numpad.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_numpad[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
       8,    7,    7,    7, 0x05,

 // slots: signature, parameters, type, tag, flags
      30,    7,    7,    7, 0x0a,
      44,    7,    7,    7, 0x08,
      55,    7,    7,    7, 0x08,
      66,    7,    7,    7, 0x08,
      77,    7,    7,    7, 0x08,
      88,    7,    7,    7, 0x08,
      99,    7,    7,    7, 0x08,
     110,    7,    7,    7, 0x08,
     121,    7,    7,    7, 0x08,
     132,    7,    7,    7, 0x08,
     143,    7,    7,    7, 0x08,
     154,    7,    7,    7, 0x08,
     169,    7,    7,    7, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_numpad[] = {
    "numpad\0\0value_changed(double)\0"
    "clear_value()\0append_0()\0append_1()\0"
    "append_2()\0append_3()\0append_4()\0"
    "append_5()\0append_6()\0append_7()\0"
    "append_8()\0append_9()\0append_point()\0"
    "toggle_plus_minus()\0"
};

const QMetaObject numpad::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_numpad,
      qt_meta_data_numpad, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &numpad::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *numpad::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *numpad::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_numpad))
        return static_cast<void*>(const_cast< numpad*>(this));
    return QWidget::qt_metacast(_clname);
}

int numpad::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: value_changed((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 1: clear_value(); break;
        case 2: append_0(); break;
        case 3: append_1(); break;
        case 4: append_2(); break;
        case 5: append_3(); break;
        case 6: append_4(); break;
        case 7: append_5(); break;
        case 8: append_6(); break;
        case 9: append_7(); break;
        case 10: append_8(); break;
        case 11: append_9(); break;
        case 12: append_point(); break;
        case 13: toggle_plus_minus(); break;
        default: ;
        }
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void numpad::value_changed(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
