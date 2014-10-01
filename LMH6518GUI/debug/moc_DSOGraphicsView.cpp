/****************************************************************************
** Meta object code from reading C++ file 'DSOGraphicsView.h'
**
** Created: Tue Sep 30 16:46:12 2014
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../DSOGraphicsView.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DSOGraphicsView.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DSOXYGridView[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_DSOXYGridView[] = {
    "DSOXYGridView\0"
};

const QMetaObject DSOXYGridView::staticMetaObject = {
    { &QGraphicsView::staticMetaObject, qt_meta_stringdata_DSOXYGridView,
      qt_meta_data_DSOXYGridView, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DSOXYGridView::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DSOXYGridView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DSOXYGridView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DSOXYGridView))
        return static_cast<void*>(const_cast< DSOXYGridView*>(this));
    return QGraphicsView::qt_metacast(_clname);
}

int DSOXYGridView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_DSOChannelDataView[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_DSOChannelDataView[] = {
    "DSOChannelDataView\0"
};

const QMetaObject DSOChannelDataView::staticMetaObject = {
    { &QGraphicsView::staticMetaObject, qt_meta_stringdata_DSOChannelDataView,
      qt_meta_data_DSOChannelDataView, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DSOChannelDataView::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DSOChannelDataView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DSOChannelDataView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DSOChannelDataView))
        return static_cast<void*>(const_cast< DSOChannelDataView*>(this));
    return QGraphicsView::qt_metacast(_clname);
}

int DSOChannelDataView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
