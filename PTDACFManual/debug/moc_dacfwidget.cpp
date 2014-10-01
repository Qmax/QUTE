/****************************************************************************
** Meta object code from reading C++ file 'dacfwidget.h'
**
** Created: Tue Sep 30 15:52:56 2014
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../dacfwidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dacfwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DACFWidget[] = {

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
      12,   11,   11,   11, 0x08,
      33,   11,   11,   11, 0x08,
      54,   11,   11,   11, 0x08,
      79,   72,   11,   11, 0x08,
      98,   11,   11,   11, 0x08,
     119,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_DACFWidget[] = {
    "DACFWidget\0\0on_butExit_clicked()\0"
    "on_butSave_clicked()\0callOffsetValue()\0"
    "pValue\0receiveValue(uint)\0"
    "receiveValue(double)\0receiveValue(QString)\0"
};

const QMetaObject DACFWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_DACFWidget,
      qt_meta_data_DACFWidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DACFWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DACFWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DACFWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DACFWidget))
        return static_cast<void*>(const_cast< DACFWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int DACFWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_butExit_clicked(); break;
        case 1: on_butSave_clicked(); break;
        case 2: callOffsetValue(); break;
        case 3: receiveValue((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 4: receiveValue((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: receiveValue((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
