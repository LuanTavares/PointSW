/****************************************************************************
** Meta object code from reading C++ file 'TelaDeProducao.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../PointSW/TelaDeProducao.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TelaDeProducao.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_TelaDeProducao_t {
    QByteArrayData data[7];
    char stringdata[87];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_TelaDeProducao_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_TelaDeProducao_t qt_meta_stringdata_TelaDeProducao = {
    {
QT_MOC_LITERAL(0, 0, 14),
QT_MOC_LITERAL(1, 15, 21),
QT_MOC_LITERAL(2, 37, 0),
QT_MOC_LITERAL(3, 38, 5),
QT_MOC_LITERAL(4, 44, 13),
QT_MOC_LITERAL(5, 58, 12),
QT_MOC_LITERAL(6, 71, 14)
    },
    "TelaDeProducao\0atualizaTelaPrincipal\0"
    "\0tempo\0gravaProducao\0atualizaTela\0"
    "acabouProducao\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TelaDeProducao[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       4,    0,   37,    2, 0x0a,
       5,    0,   38,    2, 0x0a,
       6,    0,   39,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, QMetaType::QTime,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void TelaDeProducao::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TelaDeProducao *_t = static_cast<TelaDeProducao *>(_o);
        switch (_id) {
        case 0: _t->atualizaTelaPrincipal((*reinterpret_cast< QTime(*)>(_a[1]))); break;
        case 1: _t->gravaProducao(); break;
        case 2: _t->atualizaTela(); break;
        case 3: _t->acabouProducao(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (TelaDeProducao::*_t)(QTime );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TelaDeProducao::atualizaTelaPrincipal)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject TelaDeProducao::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_TelaDeProducao.data,
      qt_meta_data_TelaDeProducao,  qt_static_metacall, 0, 0}
};


const QMetaObject *TelaDeProducao::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TelaDeProducao::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TelaDeProducao.stringdata))
        return static_cast<void*>(const_cast< TelaDeProducao*>(this));
    return QWidget::qt_metacast(_clname);
}

int TelaDeProducao::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void TelaDeProducao::atualizaTelaPrincipal(QTime _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
