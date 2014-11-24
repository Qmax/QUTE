/****************************************************************************
** Meta object code from reading C++ file 'testspi.h'
**
** Created: Sun Nov 23 18:06:46 2014
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../testspi.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'testspi.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_testSPI[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      31,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      17,    9,    8,    8, 0x08,
      46,    9,    8,    8, 0x08,
      77,    8,    8,    8, 0x08,
     107,  101,    8,    8, 0x08,
     145,  101,    8,    8, 0x08,
     186,    8,    8,    8, 0x08,
     214,  208,    8,    8, 0x08,
     252,  101,    8,    8, 0x08,
     287,    8,    8,    8, 0x08,
     308,    8,    8,    8, 0x08,
     327,  101,    8,    8, 0x08,
     365,    8,    8,    8, 0x08,
     387,    8,    8,    8, 0x08,
     408,  101,    8,    8, 0x08,
     447,  101,    8,    8, 0x08,
     486,    8,    8,    8, 0x08,
     504,  101,    8,    8, 0x08,
     542,  101,    8,    8, 0x08,
     586,    8,    8,    8, 0x08,
     607,    8,    8,    8, 0x08,
     626,    8,    8,    8, 0x08,
     647,    8,    8,    8, 0x08,
     669,    8,    8,    8, 0x08,
     687,    8,    8,    8, 0x08,
     702,    8,    8,    8, 0x08,
     723,    8,    8,    8, 0x08,
     741,    8,    8,    8, 0x08,
     760,    8,    8,    8, 0x08,
     779,    8,    8,    8, 0x08,
     797,    8,    8,    8, 0x08,
     811,    8,    8,    8, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_testSPI[] = {
    "testSPI\0\0checked\0on_radioButton_clicked(bool)\0"
    "on_radioButton_2_clicked(bool)\0"
    "on_pushButton_clicked()\0index\0"
    "on_SelectADC_currentIndexChanged(int)\0"
    "on_testFileLoad_currentIndexChanged(int)\0"
    "on_testFile_clicked()\0value\0"
    "on_horizontalSlider_valueChanged(int)\0"
    "on_DCVolt_currentIndexChanged(int)\0"
    "on_ReadAll_clicked()\0on_Reset_clicked()\0"
    "on_SelectApp_currentIndexChanged(int)\0"
    "on_AppWrite_clicked()\0on_AppRead_clicked()\0"
    "on_SelectPart_currentIndexChanged(int)\0"
    "on_SelectMode_currentIndexChanged(int)\0"
    "on_Exit_clicked()\0"
    "on_SelectSPI_currentIndexChanged(int)\0"
    "on_SelectOperation_currentIndexChanged(int)\0"
    "on_Execute_clicked()\0receiveValue(uint)\0"
    "receiveValue(double)\0receiveValue(QString)\0"
    "callAddressEdit()\0callDataEdit()\0"
    "callAppAddressEdit()\0callAppDataEdit()\0"
    "callMaskDataEdit()\0callSPIClockEdit()\0"
    "callDMMAddrEdit()\0callAvgEdit()\0"
    "ADCRead()\0"
};

const QMetaObject testSPI::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_testSPI,
      qt_meta_data_testSPI, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &testSPI::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *testSPI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *testSPI::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_testSPI))
        return static_cast<void*>(const_cast< testSPI*>(this));
    return QWidget::qt_metacast(_clname);
}

int testSPI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_radioButton_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: on_radioButton_2_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: on_pushButton_clicked(); break;
        case 3: on_SelectADC_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: on_testFileLoad_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: on_testFile_clicked(); break;
        case 6: on_horizontalSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: on_DCVolt_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: on_ReadAll_clicked(); break;
        case 9: on_Reset_clicked(); break;
        case 10: on_SelectApp_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: on_AppWrite_clicked(); break;
        case 12: on_AppRead_clicked(); break;
        case 13: on_SelectPart_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: on_SelectMode_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: on_Exit_clicked(); break;
        case 16: on_SelectSPI_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: on_SelectOperation_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 18: on_Execute_clicked(); break;
        case 19: receiveValue((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 20: receiveValue((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 21: receiveValue((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 22: callAddressEdit(); break;
        case 23: callDataEdit(); break;
        case 24: callAppAddressEdit(); break;
        case 25: callAppDataEdit(); break;
        case 26: callMaskDataEdit(); break;
        case 27: callSPIClockEdit(); break;
        case 28: callDMMAddrEdit(); break;
        case 29: callAvgEdit(); break;
        case 30: ADCRead(); break;
        default: ;
        }
        _id -= 31;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
