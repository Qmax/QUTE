/****************************************************************************
** Meta object code from reading C++ file 'fg.h'
**
** Created: Thu Sep 25 16:31:18 2014
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../fg.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QmaxLineEdit[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      23,   14,   13,   13, 0x05,
      41,   38,   13,   13, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_QmaxLineEdit[] = {
    "QmaxLineEdit\0\0hasFocus\0focussed(bool)\0"
    "no\0focussed(int)\0"
};

const QMetaObject QmaxLineEdit::staticMetaObject = {
    { &QLineEdit::staticMetaObject, qt_meta_stringdata_QmaxLineEdit,
      qt_meta_data_QmaxLineEdit, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QmaxLineEdit::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QmaxLineEdit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QmaxLineEdit::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QmaxLineEdit))
        return static_cast<void*>(const_cast< QmaxLineEdit*>(this));
    return QLineEdit::qt_metacast(_clname);
}

int QmaxLineEdit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLineEdit::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: focussed((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: focussed((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void QmaxLineEdit::focussed(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QmaxLineEdit::focussed(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
static const uint qt_meta_data_QmaxLabel[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      17,   11,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_QmaxLabel[] = {
    "QmaxLabel\0\0state\0setlabelFocus(bool)\0"
};

const QMetaObject QmaxLabel::staticMetaObject = {
    { &QLabel::staticMetaObject, qt_meta_stringdata_QmaxLabel,
      qt_meta_data_QmaxLabel, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QmaxLabel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QmaxLabel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QmaxLabel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QmaxLabel))
        return static_cast<void*>(const_cast< QmaxLabel*>(this));
    return QLabel::qt_metacast(_clname);
}

int QmaxLabel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLabel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: setlabelFocus((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}
static const uint qt_meta_data_FG[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      25,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      11,    4,    3,    3, 0x0a,
      32,    4,    3,    3, 0x0a,
      54,    4,    3,    3, 0x0a,
      84,   73,    3,    3, 0x0a,
     107,    3,    3,    3, 0x0a,
     114,    3,    3,    3, 0x0a,
     121,    3,    3,    3, 0x08,
     147,  141,    3,    3, 0x08,
     183,    3,    3,    3, 0x08,
     206,    3,    3,    3, 0x08,
     230,    3,    3,    3, 0x08,
     254,    3,    3,    3, 0x08,
     275,    3,    3,    3, 0x08,
     297,    3,    3,    3, 0x08,
     315,    3,    3,    3, 0x08,
     334,    3,    3,    3, 0x08,
     355,    3,    3,    3, 0x08,
     375,    3,    3,    3, 0x08,
     395,    3,    3,    3, 0x08,
     415,    3,    3,    3, 0x08,
     435,    3,    3,    3, 0x08,
     455,    3,    3,    3, 0x08,
     480,    3,    3,    3, 0x08,
     501,    3,    3,    3, 0x08,
     524,    3,    3,    3, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_FG[] = {
    "FG\0\0pValue\0receiveValue(double)\0"
    "receiveValue(QString)\0receiveValue(uint)\0"
    "leFocussed\0callLineEditInput(int)\0"
    "Beep()\0Mute()\0on_AWGBox_clicked()\0"
    "index\0on_modeBox_currentIndexChanged(int)\0"
    "on_calibrate_clicked()\0on_appBckPSoC_clicked()\0"
    "on_fineCoarse_clicked()\0on_leftBut_clicked()\0"
    "on_rightBut_clicked()\0on_exit_clicked()\0"
    "on_upBut_clicked()\0on_downBut_clicked()\0"
    "on_EXTBut_clicked()\0on_INTBut_clicked()\0"
    "on_MANBut_clicked()\0on_RUNBut_clicked()\0"
    "on_hiZBut_clicked()\0on_triangleBut_clicked()\0"
    "on_rampBut_clicked()\0on_squareBut_clicked()\0"
    "on_sineBut_clicked()\0"
};

const QMetaObject FG::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_FG,
      qt_meta_data_FG, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &FG::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *FG::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *FG::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FG))
        return static_cast<void*>(const_cast< FG*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int FG::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: receiveValue((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 1: receiveValue((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: receiveValue((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 3: callLineEditInput((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: Beep(); break;
        case 5: Mute(); break;
        case 6: on_AWGBox_clicked(); break;
        case 7: on_modeBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: on_calibrate_clicked(); break;
        case 9: on_appBckPSoC_clicked(); break;
        case 10: on_fineCoarse_clicked(); break;
        case 11: on_leftBut_clicked(); break;
        case 12: on_rightBut_clicked(); break;
        case 13: on_exit_clicked(); break;
        case 14: on_upBut_clicked(); break;
        case 15: on_downBut_clicked(); break;
        case 16: on_EXTBut_clicked(); break;
        case 17: on_INTBut_clicked(); break;
        case 18: on_MANBut_clicked(); break;
        case 19: on_RUNBut_clicked(); break;
        case 20: on_hiZBut_clicked(); break;
        case 21: on_triangleBut_clicked(); break;
        case 22: on_rampBut_clicked(); break;
        case 23: on_squareBut_clicked(); break;
        case 24: on_sineBut_clicked(); break;
        default: ;
        }
        _id -= 25;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
