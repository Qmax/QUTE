/****************************************************************************
** Meta object code from reading C++ file 'myLineEdit.h'
**
** Created: Mon Sep 1 11:58:23 2014
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../myLineEdit.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'myLineEdit.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MyLineEdit[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      21,   12,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      36,   11,   11,   11, 0x0a,
      50,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MyLineEdit[] = {
    "MyLineEdit\0\0hasFocus\0focussed(bool)\0"
    "changeLabel()\0checkFocus()\0"
};

const QMetaObject MyLineEdit::staticMetaObject = {
    { &QLineEdit::staticMetaObject, qt_meta_stringdata_MyLineEdit,
      qt_meta_data_MyLineEdit, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MyLineEdit::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MyLineEdit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MyLineEdit::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MyLineEdit))
        return static_cast<void*>(const_cast< MyLineEdit*>(this));
    return QLineEdit::qt_metacast(_clname);
}

int MyLineEdit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLineEdit::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: focussed((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: changeLabel(); break;
        case 2: checkFocus(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void MyLineEdit::focussed(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
