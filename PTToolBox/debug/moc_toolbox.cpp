/****************************************************************************
** Meta object code from reading C++ file 'toolbox.h'
**
** Created: Wed Dec 3 18:22:54 2014
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../toolbox.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'toolbox.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ToolBox[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x08,
      34,    8,    8,    8, 0x08,
      69,   55,    8,    8, 0x08,
     108,    8,    8,    8, 0x08,
     133,    8,    8,    8, 0x08,
     160,    8,    8,    8, 0x08,
     185,    8,    8,    8, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ToolBox[] = {
    "ToolBox\0\0on_pb_curEnDis_clicked()\0"
    "on_pb_exit_clicked()\0name,password\0"
    "slotAcceptUserLogin(QString&,QString&)\0"
    "on_pb_datetime_clicked()\0"
    "on_pb_touchcalib_clicked()\0"
    "on_pb_selftest_clicked()\0"
    "on_pb_testjig_clicked()\0"
};

const QMetaObject ToolBox::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ToolBox,
      qt_meta_data_ToolBox, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ToolBox::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ToolBox::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ToolBox::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ToolBox))
        return static_cast<void*>(const_cast< ToolBox*>(this));
    return QWidget::qt_metacast(_clname);
}

int ToolBox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_pb_curEnDis_clicked(); break;
        case 1: on_pb_exit_clicked(); break;
        case 2: slotAcceptUserLogin((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 3: on_pb_datetime_clicked(); break;
        case 4: on_pb_touchcalib_clicked(); break;
        case 5: on_pb_selftest_clicked(); break;
        case 6: on_pb_testjig_clicked(); break;
        default: ;
        }
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
