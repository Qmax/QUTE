/****************************************************************************
** Meta object code from reading C++ file 'documentwidget.h'
**
** Created: Sat May 18 17:00:29 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../documentwidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'documentwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DocumentWidget[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      28,   16,   15,   15, 0x05,
      50,   45,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
      79,   45,   72,   15, 0x0a,
     104,   45,   72,   15, 0x0a,
     142,  133,  128,   15, 0x0a,
     168,  163,   15,   15, 0x0a,
     181,   15,   15,   15, 0x2a,
     197,  191,   15,   15, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_DocumentWidget[] = {
    "DocumentWidget\0\0currentPage\0"
    "pageChanged(int)\0text\0textSelected(QString)\0"
    "QRectF\0searchBackwards(QString)\0"
    "searchForwards(QString)\0bool\0filePath\0"
    "setDocument(QString)\0page\0setPage(int)\0"
    "setPage()\0scale\0setScale(qreal)\0"
};

const QMetaObject DocumentWidget::staticMetaObject = {
    { &QLabel::staticMetaObject, qt_meta_stringdata_DocumentWidget,
      qt_meta_data_DocumentWidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DocumentWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DocumentWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DocumentWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DocumentWidget))
        return static_cast<void*>(const_cast< DocumentWidget*>(this));
    return QLabel::qt_metacast(_clname);
}

int DocumentWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLabel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: pageChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: textSelected((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: { QRectF _r = searchBackwards((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QRectF*>(_a[0]) = _r; }  break;
        case 3: { QRectF _r = searchForwards((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QRectF*>(_a[0]) = _r; }  break;
        case 4: { bool _r = setDocument((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 5: setPage((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: setPage(); break;
        case 7: setScale((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void DocumentWidget::pageChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DocumentWidget::textSelected(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
