/****************************************************************************
** Meta object code from reading C++ file 'offsetwindow.h'
**
** Created: Tue Sep 30 16:46:17 2014
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../offsetwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'offsetwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_OffsetWindow[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      16,   14,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
      54,   47,   13,   13, 0x08,
      89,   13,   13,   13, 0x08,
     111,   13,   13,   13, 0x08,
     133,   13,   13,   13, 0x08,
     155,   13,   13,   13, 0x08,
     177,   13,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_OffsetWindow[] = {
    "OffsetWindow\0\0,\0passDACValue(short int,double)\0"
    "pValue\0on_dblDACSpin_valueChanged(double)\0"
    "on_m_rbDACA_clicked()\0on_m_rbDACB_clicked()\0"
    "on_m_rbDACC_clicked()\0on_m_rbDACD_clicked()\0"
    "on_m_rbDACE_clicked()\0"
};

const QMetaObject OffsetWindow::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_OffsetWindow,
      qt_meta_data_OffsetWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &OffsetWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *OffsetWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *OffsetWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_OffsetWindow))
        return static_cast<void*>(const_cast< OffsetWindow*>(this));
    return QWidget::qt_metacast(_clname);
}

int OffsetWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: passDACValue((*reinterpret_cast< short int(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 1: on_dblDACSpin_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: on_m_rbDACA_clicked(); break;
        case 3: on_m_rbDACB_clicked(); break;
        case 4: on_m_rbDACC_clicked(); break;
        case 5: on_m_rbDACD_clicked(); break;
        case 6: on_m_rbDACE_clicked(); break;
        default: ;
        }
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void OffsetWindow::passDACValue(short int _t1, double _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
