/****************************************************************************
** Meta object code from reading C++ file 'numberpanel.h'
**
** Created: Mon Sep 1 11:58:19 2014
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../numberpanel.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'numberpanel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_NumberPanel[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x05,
      28,   12,   12,   12, 0x05,
      46,   12,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      65,   12,   12,   12, 0x0a,
      84,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_NumberPanel[] = {
    "NumberPanel\0\0passText(uint)\0"
    "passText1(double)\0passText2(QString)\0"
    "buttonPressed(int)\0on_numEdit_textChanged(QString)\0"
};

const QMetaObject NumberPanel::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_NumberPanel,
      qt_meta_data_NumberPanel, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &NumberPanel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *NumberPanel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *NumberPanel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_NumberPanel))
        return static_cast<void*>(const_cast< NumberPanel*>(this));
    return QWidget::qt_metacast(_clname);
}

int NumberPanel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: passText((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 1: passText1((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: passText2((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: buttonPressed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: on_numEdit_textChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void NumberPanel::passText(unsigned int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void NumberPanel::passText1(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void NumberPanel::passText2(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
