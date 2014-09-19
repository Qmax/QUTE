/****************************************************************************
** Meta object code from reading C++ file 'dmm.h'
**
** Created: Mon Aug 27 17:40:46 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "dmm.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dmm.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DMM[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       5,    4,    4,    4, 0x08,
      29,    4,    4,    4, 0x08,
      48,    4,    4,    4, 0x08,
      69,    4,    4,    4, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_DMM[] = {
    "DMM\0\0on_pushButton_clicked()\0"
    "buttonPressed(int)\0on_exitBut_clicked()\0"
    "onMeasure()\0"
};

const QMetaObject DMM::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_DMM,
      qt_meta_data_DMM, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DMM::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DMM::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DMM::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DMM))
        return static_cast<void*>(const_cast< DMM*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int DMM::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_pushButton_clicked(); break;
        case 1: buttonPressed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: on_exitBut_clicked(); break;
        case 3: onMeasure(); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
