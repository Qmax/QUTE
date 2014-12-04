/****************************************************************************
** Meta object code from reading C++ file 'daccalibration.h'
**
** Created: Tue Dec 2 11:53:41 2014
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../daccalibration.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'daccalibration.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DACCalibration[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      18,   16,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
      45,   16,   15,   15, 0x08,
      72,   15,   15,   15, 0x08,
      93,   15,   15,   15, 0x08,
     114,   15,   15,   15, 0x08,
     141,  135,   15,   15, 0x08,
     178,   15,   15,   15, 0x08,
     199,   15,   15,   15, 0x08,
     221,   15,   15,   15, 0x08,
     248,  241,   15,   15, 0x08,
     267,   15,   15,   15, 0x08,
     288,   15,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_DACCalibration[] = {
    "DACCalibration\0\0,\0GCalib2ICM(double,QString)\0"
    "ICM2GCalib(double,QString)\0"
    "on_nextBut_clicked()\0on_exitBut_clicked()\0"
    "on_saveBut_clicked()\0index\0"
    "on_comboBox_currentIndexChanged(int)\0"
    "callNoOfPointsEdit()\0callActualValueEdit()\0"
    "callRxedValueEdit()\0pValue\0"
    "receiveValue(uint)\0receiveValue(double)\0"
    "receiveValue(QString)\0"
};

const QMetaObject DACCalibration::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_DACCalibration,
      qt_meta_data_DACCalibration, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DACCalibration::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DACCalibration::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DACCalibration::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DACCalibration))
        return static_cast<void*>(const_cast< DACCalibration*>(this));
    return QWidget::qt_metacast(_clname);
}

int DACCalibration::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: GCalib2ICM((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: ICM2GCalib((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: on_nextBut_clicked(); break;
        case 3: on_exitBut_clicked(); break;
        case 4: on_saveBut_clicked(); break;
        case 5: on_comboBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: callNoOfPointsEdit(); break;
        case 7: callActualValueEdit(); break;
        case 8: callRxedValueEdit(); break;
        case 9: receiveValue((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 10: receiveValue((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 11: receiveValue((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void DACCalibration::GCalib2ICM(double _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
