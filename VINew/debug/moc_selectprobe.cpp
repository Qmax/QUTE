/****************************************************************************
** Meta object code from reading C++ file 'selectprobe.h'
**
** Created: Sat Oct 25 11:52:33 2014
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../selectprobe.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'selectprobe.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SelectProbe[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x05,
      22,   12,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      37,   12,   12,   12, 0x0a,
      51,   12,   12,   12, 0x08,
      70,   12,   12,   12, 0x08,
      95,   12,   12,   12, 0x08,
     119,   12,   12,   12, 0x08,
     142,   12,   12,   12, 0x08,
     169,   12,   12,   12, 0x08,
     196,   12,   12,   12, 0x08,
     223,   12,   12,   12, 0x08,
     245,   12,   12,   12, 0x08,
     265,   12,   12,   12, 0x08,
     298,   12,   12,   12, 0x08,
     318,   12,   12,   12, 0x08,
     346,  339,   12,   12, 0x08,
     365,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SelectProbe[] = {
    "SelectProbe\0\0closed()\0dialogClosed()\0"
    "closeWindow()\0on_butOK_clicked()\0"
    "on_butAdvSetup_clicked()\0"
    "on_optAverage_clicked()\0on_optLinear_clicked()\0"
    "on_optResistance_clicked()\0"
    "on_optCapcitance_clicked()\0"
    "on_optInductance_clicked()\0"
    "on_optDiode_clicked()\0on_optAll_clicked()\0"
    "selectPacakage(QListWidgetItem*)\0"
    "callThresHoldEdit()\0receiveValue(double)\0"
    "pValue\0receiveValue(uint)\0"
    "on_chkCommonGnd_clicked()\0"
};

const QMetaObject SelectProbe::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_SelectProbe,
      qt_meta_data_SelectProbe, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SelectProbe::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SelectProbe::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SelectProbe::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SelectProbe))
        return static_cast<void*>(const_cast< SelectProbe*>(this));
    if (!strcmp(_clname, "IVIObserver"))
        return static_cast< IVIObserver*>(const_cast< SelectProbe*>(this));
    return QDialog::qt_metacast(_clname);
}

int SelectProbe::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: closed(); break;
        case 1: dialogClosed(); break;
        case 2: closeWindow(); break;
        case 3: on_butOK_clicked(); break;
        case 4: on_butAdvSetup_clicked(); break;
        case 5: on_optAverage_clicked(); break;
        case 6: on_optLinear_clicked(); break;
        case 7: on_optResistance_clicked(); break;
        case 8: on_optCapcitance_clicked(); break;
        case 9: on_optInductance_clicked(); break;
        case 10: on_optDiode_clicked(); break;
        case 11: on_optAll_clicked(); break;
        case 12: selectPacakage((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 13: callThresHoldEdit(); break;
        case 14: receiveValue((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 15: receiveValue((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 16: on_chkCommonGnd_clicked(); break;
        default: ;
        }
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void SelectProbe::closed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void SelectProbe::dialogClosed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
