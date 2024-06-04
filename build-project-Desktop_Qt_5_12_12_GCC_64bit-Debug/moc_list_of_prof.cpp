/****************************************************************************
** Meta object code from reading C++ file 'list_of_prof.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../project/list_of_prof.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'list_of_prof.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_list_of_prof_t {
    QByteArrayData data[12];
    char stringdata0[174];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_list_of_prof_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_list_of_prof_t qt_meta_stringdata_list_of_prof = {
    {
QT_MOC_LITERAL(0, 0, 12), // "list_of_prof"
QT_MOC_LITERAL(1, 13, 23), // "on_pushButton_4_clicked"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 23), // "on_pushButton_3_clicked"
QT_MOC_LITERAL(4, 62, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(5, 86, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(6, 108, 19), // "customMenuRequested"
QT_MOC_LITERAL(7, 128, 3), // "pos"
QT_MOC_LITERAL(8, 132, 10), // "editRecord"
QT_MOC_LITERAL(9, 143, 11), // "QModelIndex"
QT_MOC_LITERAL(10, 155, 5), // "index"
QT_MOC_LITERAL(11, 161, 12) // "deleteRecord"

    },
    "list_of_prof\0on_pushButton_4_clicked\0"
    "\0on_pushButton_3_clicked\0"
    "on_pushButton_2_clicked\0on_pushButton_clicked\0"
    "customMenuRequested\0pos\0editRecord\0"
    "QModelIndex\0index\0deleteRecord"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_list_of_prof[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08 /* Private */,
       3,    0,   50,    2, 0x08 /* Private */,
       4,    0,   51,    2, 0x08 /* Private */,
       5,    0,   52,    2, 0x08 /* Private */,
       6,    1,   53,    2, 0x0a /* Public */,
       8,    1,   56,    2, 0x0a /* Public */,
      11,    1,   59,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,    7,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 9,   10,

       0        // eod
};

void list_of_prof::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<list_of_prof *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButton_4_clicked(); break;
        case 1: _t->on_pushButton_3_clicked(); break;
        case 2: _t->on_pushButton_2_clicked(); break;
        case 3: _t->on_pushButton_clicked(); break;
        case 4: _t->customMenuRequested((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 5: _t->editRecord((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 6: _t->deleteRecord((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject list_of_prof::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_list_of_prof.data,
    qt_meta_data_list_of_prof,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *list_of_prof::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *list_of_prof::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_list_of_prof.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int list_of_prof::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
