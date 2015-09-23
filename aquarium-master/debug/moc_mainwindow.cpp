/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[25];
    char stringdata[280];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 19),
QT_MOC_LITERAL(2, 31, 0),
QT_MOC_LITERAL(3, 32, 4),
QT_MOC_LITERAL(4, 37, 10),
QT_MOC_LITERAL(5, 48, 2),
QT_MOC_LITERAL(6, 51, 14),
QT_MOC_LITERAL(7, 66, 17),
QT_MOC_LITERAL(8, 84, 17),
QT_MOC_LITERAL(9, 102, 20),
QT_MOC_LITERAL(10, 123, 8),
QT_MOC_LITERAL(11, 132, 5),
QT_MOC_LITERAL(12, 138, 8),
QT_MOC_LITERAL(13, 147, 5),
QT_MOC_LITERAL(14, 153, 10),
QT_MOC_LITERAL(15, 164, 7),
QT_MOC_LITERAL(16, 172, 10),
QT_MOC_LITERAL(17, 183, 7),
QT_MOC_LITERAL(18, 191, 15),
QT_MOC_LITERAL(19, 207, 7),
QT_MOC_LITERAL(20, 215, 15),
QT_MOC_LITERAL(21, 231, 7),
QT_MOC_LITERAL(22, 239, 8),
QT_MOC_LITERAL(23, 248, 15),
QT_MOC_LITERAL(24, 264, 15)
    },
    "MainWindow\0afficherTemperature\0\0temp\0"
    "afficherPh\0ph\0changeButtonPh\0"
    "changeButtonLight\0changeButtonPh_ph\0"
    "changeButtonLight_ph\0getPhMax\0phmax\0"
    "getPhMin\0phmin\0getTempMax\0tempMax\0"
    "getTempMin\0tempMin\0afficherTempMin\0"
    "tempmin\0afficherTempMax\0tempmax\0"
    "getEmail\0getNotification\0updateGraphOnUI"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   89,    2, 0x08 /* Private */,
       4,    1,   92,    2, 0x08 /* Private */,
       6,    0,   95,    2, 0x08 /* Private */,
       7,    0,   96,    2, 0x08 /* Private */,
       8,    0,   97,    2, 0x08 /* Private */,
       9,    0,   98,    2, 0x08 /* Private */,
      10,    1,   99,    2, 0x08 /* Private */,
      12,    1,  102,    2, 0x08 /* Private */,
      14,    1,  105,    2, 0x08 /* Private */,
      16,    1,  108,    2, 0x08 /* Private */,
      18,    1,  111,    2, 0x08 /* Private */,
      20,    1,  114,    2, 0x08 /* Private */,
      22,    0,  117,    2, 0x08 /* Private */,
      23,    0,  118,    2, 0x08 /* Private */,
      24,    0,  119,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   11,
    QMetaType::Void, QMetaType::Double,   13,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void, QMetaType::Int,   17,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void, QMetaType::Int,   21,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->afficherTemperature((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->afficherPh((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->changeButtonPh(); break;
        case 3: _t->changeButtonLight(); break;
        case 4: _t->changeButtonPh_ph(); break;
        case 5: _t->changeButtonLight_ph(); break;
        case 6: _t->getPhMax((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 7: _t->getPhMin((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 8: _t->getTempMax((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->getTempMin((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->afficherTempMin((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->afficherTempMax((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->getEmail(); break;
        case 13: _t->getNotification(); break;
        case 14: _t->updateGraphOnUI(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
