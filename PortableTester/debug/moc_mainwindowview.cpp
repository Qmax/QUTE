/****************************************************************************
** Meta object code from reading C++ file 'mainwindowview.h'
**
** Created: Fri Sep 19 18:11:43 2014
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindowview.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindowview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TimerThread[] = {

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
      13,   12,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_TimerThread[] = {
    "TimerThread\0\0doWork()\0"
};

const QMetaObject TimerThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_TimerThread,
      qt_meta_data_TimerThread, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TimerThread::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TimerThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TimerThread::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TimerThread))
        return static_cast<void*>(const_cast< TimerThread*>(this));
    return QThread::qt_metacast(_clname);
}

int TimerThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: doWork(); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}
static const uint qt_meta_data_MainWindowView[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
      35,   15,   15,   15, 0x0a,
      50,   15,   15,   15, 0x0a,
      63,   15,   15,   15, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MainWindowView[] = {
    "MainWindowView\0\0buttonClicked(int)\0"
    "checkSlot(int)\0pressed(int)\0timerTimeout()\0"
};

const QMetaObject MainWindowView::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MainWindowView,
      qt_meta_data_MainWindowView, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindowView::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindowView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindowView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindowView))
        return static_cast<void*>(const_cast< MainWindowView*>(this));
    return QWidget::qt_metacast(_clname);
}

int MainWindowView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: buttonClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: checkSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: pressed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: timerTimeout(); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void MainWindowView::buttonClicked(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
