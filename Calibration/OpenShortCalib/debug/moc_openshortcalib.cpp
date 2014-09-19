/****************************************************************************
** Meta object code from reading C++ file 'openshortcalib.h'
**
** Created: Wed Sep 25 17:13:02 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../openshortcalib.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'openshortcalib.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_OpenShortCalib[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x08,
      38,   15,   15,   15, 0x08,
      59,   15,   15,   15, 0x08,
      85,   15,   15,   15, 0x08,
     110,   15,   15,   15, 0x08,
     131,   15,   15,   15, 0x08,
     151,   15,   15,   15, 0x08,
     175,   15,   15,   15, 0x08,
     198,   15,   15,   15, 0x08,
     223,   15,   15,   15, 0x08,
     243,   15,   15,   15, 0x08,
     272,  266,   15,   15, 0x08,
     310,  266,   15,   15, 0x08,
     348,  266,   15,   15, 0x08,
     394,  386,   15,   15, 0x08,
     425,  386,   15,   15, 0x08,
     450,  386,   15,   15, 0x08,
     476,  386,   15,   15, 0x08,
     501,  266,   15,   15, 0x08,
     539,   15,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_OpenShortCalib[] = {
    "OpenShortCalib\0\0on_pbClose_released()\0"
    "on_pbClose_pressed()\0on_pbCalibrate_released()\0"
    "on_pbCalibrate_pressed()\0on_pbStop_released()\0"
    "on_pbStop_pressed()\0on_pbMeasure_released()\0"
    "on_pbMeasure_pressed()\0on_pbCalibrate_clicked()\0"
    "on_pbStop_clicked()\0on_pbMeasure_clicked()\0"
    "index\0on_cmbRRange_currentIndexChanged(int)\0"
    "on_cmbLRange_currentIndexChanged(int)\0"
    "on_cmbCRange_currentIndexChanged(int)\0"
    "checked\0on_chkCalibrated_clicked(bool)\0"
    "on_chkLoad_clicked(bool)\0"
    "on_chkShort_clicked(bool)\0"
    "on_chkOpen_clicked(bool)\0"
    "on_cmbCompnt_currentIndexChanged(int)\0"
    "on_pbClose_clicked()\0"
};

const QMetaObject OpenShortCalib::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_OpenShortCalib,
      qt_meta_data_OpenShortCalib, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &OpenShortCalib::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *OpenShortCalib::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *OpenShortCalib::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_OpenShortCalib))
        return static_cast<void*>(const_cast< OpenShortCalib*>(this));
    return QWidget::qt_metacast(_clname);
}

int OpenShortCalib::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_pbClose_released(); break;
        case 1: on_pbClose_pressed(); break;
        case 2: on_pbCalibrate_released(); break;
        case 3: on_pbCalibrate_pressed(); break;
        case 4: on_pbStop_released(); break;
        case 5: on_pbStop_pressed(); break;
        case 6: on_pbMeasure_released(); break;
        case 7: on_pbMeasure_pressed(); break;
        case 8: on_pbCalibrate_clicked(); break;
        case 9: on_pbStop_clicked(); break;
        case 10: on_pbMeasure_clicked(); break;
        case 11: on_cmbRRange_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: on_cmbLRange_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: on_cmbCRange_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: on_chkCalibrated_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 15: on_chkLoad_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 16: on_chkShort_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 17: on_chkOpen_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 18: on_cmbCompnt_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 19: on_pbClose_clicked(); break;
        default: ;
        }
        _id -= 20;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
