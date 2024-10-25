/****************************************************************************
** Meta object code from reading C++ file 'openglviewer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../viewer/openglviewer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'openglviewer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_OpenGLViewer_t {
    QByteArrayData data[26];
    char stringdata0[399];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_OpenGLViewer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_OpenGLViewer_t qt_meta_stringdata_OpenGLViewer = {
    {
QT_MOC_LITERAL(0, 0, 12), // "OpenGLViewer"
QT_MOC_LITERAL(1, 13, 17), // "changeColorSignal"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 18), // "rotateModelSignalX"
QT_MOC_LITERAL(4, 51, 5), // "angle"
QT_MOC_LITERAL(5, 57, 18), // "rotateModelSignalY"
QT_MOC_LITERAL(6, 76, 18), // "rotateModelSignalZ"
QT_MOC_LITERAL(7, 95, 17), // "scaleModelSignalX"
QT_MOC_LITERAL(8, 113, 9), // "direction"
QT_MOC_LITERAL(9, 123, 17), // "scaleModelSignalY"
QT_MOC_LITERAL(10, 141, 17), // "scaleModelSignalZ"
QT_MOC_LITERAL(11, 159, 22), // "translateModeleSignalX"
QT_MOC_LITERAL(12, 182, 22), // "translateModeleSignalY"
QT_MOC_LITERAL(13, 205, 22), // "translateModeleSignalZ"
QT_MOC_LITERAL(14, 228, 14), // "dataProcessing"
QT_MOC_LITERAL(15, 243, 21), // "changeBackgroundColor"
QT_MOC_LITERAL(16, 265, 12), // "rotateModelX"
QT_MOC_LITERAL(17, 278, 12), // "rotateModelY"
QT_MOC_LITERAL(18, 291, 12), // "rotateModelZ"
QT_MOC_LITERAL(19, 304, 11), // "scaleModelX"
QT_MOC_LITERAL(20, 316, 11), // "scaleModelY"
QT_MOC_LITERAL(21, 328, 11), // "scaleModelZ"
QT_MOC_LITERAL(22, 340, 16), // "translateModeleX"
QT_MOC_LITERAL(23, 357, 16), // "translateModeleY"
QT_MOC_LITERAL(24, 374, 16), // "translateModeleZ"
QT_MOC_LITERAL(25, 391, 7) // "setProj"

    },
    "OpenGLViewer\0changeColorSignal\0\0"
    "rotateModelSignalX\0angle\0rotateModelSignalY\0"
    "rotateModelSignalZ\0scaleModelSignalX\0"
    "direction\0scaleModelSignalY\0"
    "scaleModelSignalZ\0translateModeleSignalX\0"
    "translateModeleSignalY\0translateModeleSignalZ\0"
    "dataProcessing\0changeBackgroundColor\0"
    "rotateModelX\0rotateModelY\0rotateModelZ\0"
    "scaleModelX\0scaleModelY\0scaleModelZ\0"
    "translateModeleX\0translateModeleY\0"
    "translateModeleZ\0setProj"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_OpenGLViewer[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      22,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  124,    2, 0x06 /* Public */,
       3,    1,  125,    2, 0x06 /* Public */,
       5,    1,  128,    2, 0x06 /* Public */,
       6,    1,  131,    2, 0x06 /* Public */,
       7,    1,  134,    2, 0x06 /* Public */,
       9,    1,  137,    2, 0x06 /* Public */,
      10,    1,  140,    2, 0x06 /* Public */,
      11,    1,  143,    2, 0x06 /* Public */,
      12,    1,  146,    2, 0x06 /* Public */,
      13,    1,  149,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      14,    0,  152,    2, 0x08 /* Private */,
      15,    0,  153,    2, 0x08 /* Private */,
      16,    1,  154,    2, 0x08 /* Private */,
      17,    1,  157,    2, 0x08 /* Private */,
      18,    1,  160,    2, 0x08 /* Private */,
      19,    1,  163,    2, 0x08 /* Private */,
      20,    1,  166,    2, 0x08 /* Private */,
      21,    1,  169,    2, 0x08 /* Private */,
      22,    1,  172,    2, 0x08 /* Private */,
      23,    1,  175,    2, 0x08 /* Private */,
      24,    1,  178,    2, 0x08 /* Private */,
      25,    0,  181,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Float,    4,
    QMetaType::Void, QMetaType::Float,    4,
    QMetaType::Void, QMetaType::Float,    4,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,    8,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Float,    4,
    QMetaType::Void, QMetaType::Float,    4,
    QMetaType::Void, QMetaType::Float,    4,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,

       0        // eod
};

void OpenGLViewer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<OpenGLViewer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->changeColorSignal(); break;
        case 1: _t->rotateModelSignalX((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 2: _t->rotateModelSignalY((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 3: _t->rotateModelSignalZ((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 4: _t->scaleModelSignalX((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->scaleModelSignalY((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->scaleModelSignalZ((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->translateModeleSignalX((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->translateModeleSignalY((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->translateModeleSignalZ((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->dataProcessing(); break;
        case 11: _t->changeBackgroundColor(); break;
        case 12: _t->rotateModelX((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 13: _t->rotateModelY((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 14: _t->rotateModelZ((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 15: _t->scaleModelX((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->scaleModelY((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: _t->scaleModelZ((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 18: _t->translateModeleX((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 19: _t->translateModeleY((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 20: _t->translateModeleZ((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 21: _t->setProj(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (OpenGLViewer::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&OpenGLViewer::changeColorSignal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (OpenGLViewer::*)(float );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&OpenGLViewer::rotateModelSignalX)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (OpenGLViewer::*)(float );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&OpenGLViewer::rotateModelSignalY)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (OpenGLViewer::*)(float );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&OpenGLViewer::rotateModelSignalZ)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (OpenGLViewer::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&OpenGLViewer::scaleModelSignalX)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (OpenGLViewer::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&OpenGLViewer::scaleModelSignalY)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (OpenGLViewer::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&OpenGLViewer::scaleModelSignalZ)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (OpenGLViewer::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&OpenGLViewer::translateModeleSignalX)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (OpenGLViewer::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&OpenGLViewer::translateModeleSignalY)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (OpenGLViewer::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&OpenGLViewer::translateModeleSignalZ)) {
                *result = 9;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject OpenGLViewer::staticMetaObject = { {
    QMetaObject::SuperData::link<QOpenGLWidget::staticMetaObject>(),
    qt_meta_stringdata_OpenGLViewer.data,
    qt_meta_data_OpenGLViewer,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *OpenGLViewer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *OpenGLViewer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_OpenGLViewer.stringdata0))
        return static_cast<void*>(this);
    return QOpenGLWidget::qt_metacast(_clname);
}

int OpenGLViewer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QOpenGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 22)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 22;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 22)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 22;
    }
    return _id;
}

// SIGNAL 0
void OpenGLViewer::changeColorSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void OpenGLViewer::rotateModelSignalX(float _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void OpenGLViewer::rotateModelSignalY(float _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void OpenGLViewer::rotateModelSignalZ(float _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void OpenGLViewer::scaleModelSignalX(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void OpenGLViewer::scaleModelSignalY(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void OpenGLViewer::scaleModelSignalZ(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void OpenGLViewer::translateModeleSignalX(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void OpenGLViewer::translateModeleSignalY(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void OpenGLViewer::translateModeleSignalZ(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
