/****************************************************************************
** Meta object code from reading C++ file 'ptkeyknob.h'
**
** Created: Thu Dec 4 11:46:29 2014
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ptkeyknob.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ptkeyknob.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PtKeyKnob[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x08,
      42,   10,   10,   10, 0x08,
      71,   10,   10,   10, 0x08,
     102,   10,   10,   10, 0x08,
     126,   10,   10,   10, 0x08,
     151,   10,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_PtKeyKnob[] = {
    "PtKeyKnob\0\0on_spinBox_3_valueChanged(int)\0"
    "on_spinBox_valueChanged(int)\0"
    "on_spinBox_2_valueChanged(int)\0"
    "on_pushButton_clicked()\0"
    "on_groupBox_24_clicked()\0changeDelay(int)\0"
};

const QMetaObject PtKeyKnob::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_PtKeyKnob,
      qt_meta_data_PtKeyKnob, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PtKeyKnob::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PtKeyKnob::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PtKeyKnob::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PtKeyKnob))
        return static_cast<void*>(const_cast< PtKeyKnob*>(this));
    return QWidget::qt_metacast(_clname);
}

int PtKeyKnob::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_spinBox_3_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: on_spinBox_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: on_spinBox_2_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: on_pushButton_clicked(); break;
        case 4: on_groupBox_24_clicked(); break;
        case 5: changeDelay((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
