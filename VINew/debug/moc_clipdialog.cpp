/****************************************************************************
** Meta object code from reading C++ file 'clipdialog.h'
**
** Created: Tue Sep 2 15:52:22 2014
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../clipdialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'clipdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ClipDialog[] = {

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
      12,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      21,   11,   11,   11, 0x08,
      51,   11,   11,   11, 0x08,
      86,   79,   11,   11, 0x08,
     105,   11,   11,   11, 0x08,
     126,   11,   11,   11, 0x08,
     141,   11,   11,   11, 0x08,
     162,   11,   11,   11, 0x08,
     182,   11,   11,   11, 0x08,
     204,   11,   11,   11, 0x08,
     223,   11,   11,   11, 0x08,
     247,   11,   11,   11, 0x08,
     270,   11,   11,   11, 0x08,
     297,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ClipDialog[] = {
    "ClipDialog\0\0closed()\0on_objFixedOption_2_clicked()\0"
    "on_objFixedOption_clicked()\0pValue\0"
    "receiveValue(uint)\0receiveValue(double)\0"
    "callPinsEdit()\0callRefChannelEdit()\0"
    "callThresHoldEdit()\0on_butClose_clicked()\0"
    "on_butOK_clicked()\0on_optAverage_clicked()\0"
    "on_optLinear_clicked()\0"
    "on_chkStoponFail_clicked()\0"
    "selectClip(QListWidgetItem*)\0"
};

const QMetaObject ClipDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ClipDialog,
      qt_meta_data_ClipDialog, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ClipDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ClipDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ClipDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ClipDialog))
        return static_cast<void*>(const_cast< ClipDialog*>(this));
    if (!strcmp(_clname, "IVIObserver"))
        return static_cast< IVIObserver*>(const_cast< ClipDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int ClipDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: closed(); break;
        case 1: on_objFixedOption_2_clicked(); break;
        case 2: on_objFixedOption_clicked(); break;
        case 3: receiveValue((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 4: receiveValue((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: callPinsEdit(); break;
        case 6: callRefChannelEdit(); break;
        case 7: callThresHoldEdit(); break;
        case 8: on_butClose_clicked(); break;
        case 9: on_butOK_clicked(); break;
        case 10: on_optAverage_clicked(); break;
        case 11: on_optLinear_clicked(); break;
        case 12: on_chkStoponFail_clicked(); break;
        case 13: selectClip((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void ClipDialog::closed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
