/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Wed Aug 6 17:40:34 2014
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      28,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      42,   11,   11,   11, 0x08,
      70,   11,   11,   11, 0x08,
     107,   11,   11,   11, 0x08,
     139,   11,   11,   11, 0x08,
     167,   11,   11,   11, 0x08,
     198,   11,   11,   11, 0x08,
     225,   11,   11,   11, 0x08,
     255,   11,   11,   11, 0x08,
     285,   11,   11,   11, 0x08,
     313,   11,   11,   11, 0x08,
     351,  339,   11,   11, 0x08,
     406,  396,   11,   11, 0x08,
     473,  461,   11,   11, 0x08,
     526,   11,   11,   11, 0x08,
     545,   11,   11,   11, 0x08,
     558,   11,   11,   11, 0x08,
     571,   11,   11,   11, 0x08,
     588,   11,   11,   11, 0x08,
     603,   11,   11,   11, 0x08,
     620,   11,   11,   11, 0x08,
     639,   11,   11,   11, 0x08,
     658,   11,   11,   11, 0x08,
     674,   11,   11,   11, 0x08,
     696,   11,   11,   11, 0x08,
     718,  714,   11,   11, 0x08,
     745,   11,   11,   11, 0x08,
     768,  758,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0on_actionZoom_Out_triggered()\0"
    "on_actionZoomin_triggered()\0"
    "on_actionRemove_Selected_triggered()\0"
    "on_actionRemove_All_triggered()\0"
    "on_actionRandom_triggered()\0"
    "on_actionMerge_All_triggered()\0"
    "on_actionPulse_triggered()\0"
    "on_actionSAwtooth_triggered()\0"
    "on_actionTriangle_triggered()\0"
    "on_actionSquare_triggered()\0"
    "on_actionSine_triggered()\0event,title\0"
    "titleDoubleClick(QMouseEvent*,QCPPlotTitle*)\0"
    "axis,part\0"
    "axisLabelDoubleClick(QCPAxis*,QCPAxis::SelectablePart)\0"
    "legend,item\0"
    "legendDoubleClick(QCPLegend*,QCPAbstractLegendItem*)\0"
    "selectionChanged()\0mousePress()\0"
    "mouseWheel()\0addRandomGraph()\0"
    "addSineGraph()\0addSquareGraph()\0"
    "addTriangleGraph()\0addSawtoothGraph()\0"
    "addPulseGraph()\0removeSelectedGraph()\0"
    "removeAllGraphs()\0pos\0contextMenuRequest(QPoint)\0"
    "moveLegend()\0plottable\0"
    "graphClicked(QCPAbstractPlottable*)\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_actionZoom_Out_triggered(); break;
        case 1: on_actionZoomin_triggered(); break;
        case 2: on_actionRemove_Selected_triggered(); break;
        case 3: on_actionRemove_All_triggered(); break;
        case 4: on_actionRandom_triggered(); break;
        case 5: on_actionMerge_All_triggered(); break;
        case 6: on_actionPulse_triggered(); break;
        case 7: on_actionSAwtooth_triggered(); break;
        case 8: on_actionTriangle_triggered(); break;
        case 9: on_actionSquare_triggered(); break;
        case 10: on_actionSine_triggered(); break;
        case 11: titleDoubleClick((*reinterpret_cast< QMouseEvent*(*)>(_a[1])),(*reinterpret_cast< QCPPlotTitle*(*)>(_a[2]))); break;
        case 12: axisLabelDoubleClick((*reinterpret_cast< QCPAxis*(*)>(_a[1])),(*reinterpret_cast< QCPAxis::SelectablePart(*)>(_a[2]))); break;
        case 13: legendDoubleClick((*reinterpret_cast< QCPLegend*(*)>(_a[1])),(*reinterpret_cast< QCPAbstractLegendItem*(*)>(_a[2]))); break;
        case 14: selectionChanged(); break;
        case 15: mousePress(); break;
        case 16: mouseWheel(); break;
        case 17: addRandomGraph(); break;
        case 18: addSineGraph(); break;
        case 19: addSquareGraph(); break;
        case 20: addTriangleGraph(); break;
        case 21: addSawtoothGraph(); break;
        case 22: addPulseGraph(); break;
        case 23: removeSelectedGraph(); break;
        case 24: removeAllGraphs(); break;
        case 25: contextMenuRequest((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 26: moveLegend(); break;
        case 27: graphClicked((*reinterpret_cast< QCPAbstractPlottable*(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 28;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
