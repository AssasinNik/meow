/****************************************************************************
** Meta object code from reading C++ file 'change_theme.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../project/change_theme.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'change_theme.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_change_theme_t {
    QByteArrayData data[19];
    char stringdata0[259];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_change_theme_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_change_theme_t qt_meta_stringdata_change_theme = {
    {
QT_MOC_LITERAL(0, 0, 12), // "change_theme"
QT_MOC_LITERAL(1, 13, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 23), // "on_pushButton_3_clicked"
QT_MOC_LITERAL(4, 62, 23), // "on_pushButton_4_clicked"
QT_MOC_LITERAL(5, 86, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(6, 108, 32), // "on_horizontalSlider_valueChanged"
QT_MOC_LITERAL(7, 141, 5), // "value"
QT_MOC_LITERAL(8, 147, 25), // "on_lineEdit_6_textChanged"
QT_MOC_LITERAL(9, 173, 4), // "text"
QT_MOC_LITERAL(10, 178, 7), // "setData"
QT_MOC_LITERAL(11, 186, 11), // "projectName"
QT_MOC_LITERAL(12, 198, 7), // "funding"
QT_MOC_LITERAL(13, 206, 9), // "startDate"
QT_MOC_LITERAL(14, 216, 7), // "endDate"
QT_MOC_LITERAL(15, 224, 11), // "information"
QT_MOC_LITERAL(16, 236, 5), // "stage"
QT_MOC_LITERAL(17, 242, 8), // "students"
QT_MOC_LITERAL(18, 251, 7) // "leaders"

    },
    "change_theme\0on_pushButton_2_clicked\0"
    "\0on_pushButton_3_clicked\0"
    "on_pushButton_4_clicked\0on_pushButton_clicked\0"
    "on_horizontalSlider_valueChanged\0value\0"
    "on_lineEdit_6_textChanged\0text\0setData\0"
    "projectName\0funding\0startDate\0endDate\0"
    "information\0stage\0students\0leaders"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_change_theme[] = {

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
       6,    1,   53,    2, 0x08 /* Private */,
       8,    1,   56,    2, 0x08 /* Private */,
      10,    8,   59,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,   11,   12,   13,   14,   15,   16,   17,   18,

       0        // eod
};

void change_theme::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<change_theme *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButton_2_clicked(); break;
        case 1: _t->on_pushButton_3_clicked(); break;
        case 2: _t->on_pushButton_4_clicked(); break;
        case 3: _t->on_pushButton_clicked(); break;
        case 4: _t->on_horizontalSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_lineEdit_6_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->setData((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4])),(*reinterpret_cast< const QString(*)>(_a[5])),(*reinterpret_cast< const QString(*)>(_a[6])),(*reinterpret_cast< const QString(*)>(_a[7])),(*reinterpret_cast< const QString(*)>(_a[8]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject change_theme::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_change_theme.data,
    qt_meta_data_change_theme,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *change_theme::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *change_theme::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_change_theme.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int change_theme::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
