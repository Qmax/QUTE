/****************************************************************************
** Meta object code from reading C++ file 'mutlipewavedialog.h'
**
** Created: Fri Nov 14 17:59:02 2014
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mutlipewavedialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mutlipewavedialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MutlipeWaveDialog[] = {

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
      19,   18,   18,   18, 0x08,
      28,   18,   18,   18, 0x08,
      41,   18,   18,   18, 0x08,
      52,   18,   18,   18, 0x08,
      67,   18,   18,   18, 0x08,
      82,   18,   18,   18, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MutlipeWaveDialog[] = {
    "MutlipeWaveDialog\0\0onNext()\0onPrevious()\0"
    "closeApp()\0onPassTraces()\0onFailTraces()\0"
    "onAllTraces()\0"
};

const QMetaObject MutlipeWaveDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_MutlipeWaveDialog,
      qt_meta_data_MutlipeWaveDialog, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MutlipeWaveDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MutlipeWaveDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MutlipeWaveDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MutlipeWaveDialog))
        return static_cast<void*>(const_cast< MutlipeWaveDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int MutlipeWaveDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: onNext(); break;
        case 1: onPrevious(); break;
        case 2: closeApp(); break;
        case 3: onPassTraces(); break;
        case 4: onFailTraces(); break;
        case 5: onAllTraces(); break;
        default: ;
        }
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
