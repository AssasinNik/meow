/****************************************************************************
** Meta object code from reading C++ file 'list_of_themes.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../project/list_of_themes.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'list_of_themes.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_List_of_themes_t {
    QByteArrayData data[12];
    char stringdata0[164];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_List_of_themes_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_List_of_themes_t qt_meta_stringdata_List_of_themes = {
    {
QT_MOC_LITERAL(0, 0, 14), // "List_of_themes"
QT_MOC_LITERAL(1, 15, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 23), // "on_pushButton_3_clicked"
QT_MOC_LITERAL(4, 64, 23), // "on_pushButton_4_clicked"
QT_MOC_LITERAL(5, 88, 19), // "customMenuRequested"
QT_MOC_LITERAL(6, 108, 3), // "pos"
QT_MOC_LITERAL(7, 112, 10), // "editRecord"
QT_MOC_LITERAL(8, 123, 11), // "QModelIndex"
QT_MOC_LITERAL(9, 135, 5), // "index"
QT_MOC_LITERAL(10, 141, 9), // "addRecord"
QT_MOC_LITERAL(11, 151, 12) // "deleteRecord"

    },
    "List_of_themes\0on_pushButton_2_clicked\0"
    "\0on_pushButton_3_clicked\0"
    "on_pushButton_4_clicked\0customMenuRequested\0"
    "pos\0editRecord\0QModelIndex\0index\0"
    "addRecord\0deleteRecord"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_List_of_themes[] = {

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
       5,    1,   52,    2, 0x0a /* Public */,
       7,    1,   55,    2, 0x0a /* Public */,
      10,    1,   58,    2, 0x0a /* Public */,
      11,    1,   61,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,    6,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 8,    9,

       0        // eod
};

void List_of_themes::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<List_of_themes *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButton_2_clicked(); break;
        case 1: _t->on_pushButton_3_clicked(); break;
        case 2: _t->on_pushButton_4_clicked(); break;
        case 3: _t->customMenuRequested((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 4: _t->editRecord((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 5: _t->addRecord((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 6: _t->deleteRecord((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject List_of_themes::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_List_of_themes.data,
    qt_meta_data_List_of_themes,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *List_of_themes::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *List_of_themes::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_List_of_themes.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int List_of_themes::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
