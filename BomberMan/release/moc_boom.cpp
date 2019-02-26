/****************************************************************************
** Meta object code from reading C++ file 'boom.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../boom.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'boom.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Boom_t {
    QByteArrayData data[9];
    char stringdata0[49];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Boom_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Boom_t qt_meta_stringdata_Boom = {
    {
QT_MOC_LITERAL(0, 0, 4), // "Boom"
QT_MOC_LITERAL(1, 5, 8), // "OpenFire"
QT_MOC_LITERAL(2, 14, 0), // ""
QT_MOC_LITERAL(3, 15, 1), // "x"
QT_MOC_LITERAL(4, 17, 1), // "y"
QT_MOC_LITERAL(5, 19, 8), // "StopFire"
QT_MOC_LITERAL(6, 28, 4), // "over"
QT_MOC_LITERAL(7, 33, 5), // "over1"
QT_MOC_LITERAL(8, 39, 9) // "StartBoom"

    },
    "Boom\0OpenFire\0\0x\0y\0StopFire\0over\0over1\0"
    "StartBoom"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Boom[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   39,    2, 0x06 /* Public */,
       5,    2,   44,    2, 0x06 /* Public */,
       6,    0,   49,    2, 0x06 /* Public */,
       7,    0,   50,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   51,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void Boom::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Boom *_t = static_cast<Boom *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->OpenFire((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->StopFire((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->over(); break;
        case 3: _t->over1(); break;
        case 4: _t->StartBoom(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Boom::*_t)(int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Boom::OpenFire)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Boom::*_t)(int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Boom::StopFire)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Boom::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Boom::over)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (Boom::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Boom::over1)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject Boom::staticMetaObject = {
    { &QLabel::staticMetaObject, qt_meta_stringdata_Boom.data,
      qt_meta_data_Boom,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Boom::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Boom::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Boom.stringdata0))
        return static_cast<void*>(const_cast< Boom*>(this));
    return QLabel::qt_metacast(_clname);
}

int Boom::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLabel::qt_metacall(_c, _id, _a);
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
void Boom::OpenFire(int _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Boom::StopFire(int _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Boom::over()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void Boom::over1()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
