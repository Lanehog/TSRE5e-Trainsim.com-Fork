/****************************************************************************
** Meta object code from reading C++ file 'ShapeViewerNavigatorWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "ShapeViewerNavigatorWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ShapeViewerNavigatorWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ShapeViewerNavigatorWidget_t {
    QByteArrayData data[11];
    char stringdata0[157];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ShapeViewerNavigatorWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ShapeViewerNavigatorWidget_t qt_meta_stringdata_ShapeViewerNavigatorWidget = {
    {
QT_MOC_LITERAL(0, 0, 26), // "ShapeViewerNavigatorWidget"
QT_MOC_LITERAL(1, 27, 24), // "contentHierarchySelected"
QT_MOC_LITERAL(2, 52, 0), // ""
QT_MOC_LITERAL(3, 53, 16), // "dirFilesSelected"
QT_MOC_LITERAL(4, 70, 17), // "fileItemsSelected"
QT_MOC_LITERAL(5, 88, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(6, 105, 4), // "item"
QT_MOC_LITERAL(7, 110, 6), // "column"
QT_MOC_LITERAL(8, 117, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(9, 134, 18), // "searchFilesEnabled"
QT_MOC_LITERAL(10, 153, 3) // "val"

    },
    "ShapeViewerNavigatorWidget\0"
    "contentHierarchySelected\0\0dirFilesSelected\0"
    "fileItemsSelected\0QTreeWidgetItem*\0"
    "item\0column\0QListWidgetItem*\0"
    "searchFilesEnabled\0val"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ShapeViewerNavigatorWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       3,    1,   42,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    2,   45,    2, 0x0a /* Public */,
       3,    1,   50,    2, 0x0a /* Public */,
       9,    1,   53,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5, QMetaType::Int,    6,    7,
    QMetaType::Void, 0x80000000 | 8,    6,
    QMetaType::Void, QMetaType::QString,   10,

       0        // eod
};

void ShapeViewerNavigatorWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ShapeViewerNavigatorWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->contentHierarchySelected((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->dirFilesSelected((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->fileItemsSelected((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->dirFilesSelected((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 4: _t->searchFilesEnabled((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ShapeViewerNavigatorWidget::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ShapeViewerNavigatorWidget::contentHierarchySelected)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ShapeViewerNavigatorWidget::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ShapeViewerNavigatorWidget::dirFilesSelected)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ShapeViewerNavigatorWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_ShapeViewerNavigatorWidget.data,
    qt_meta_data_ShapeViewerNavigatorWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ShapeViewerNavigatorWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ShapeViewerNavigatorWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ShapeViewerNavigatorWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ShapeViewerNavigatorWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void ShapeViewerNavigatorWidget::contentHierarchySelected(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ShapeViewerNavigatorWidget::dirFilesSelected(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
