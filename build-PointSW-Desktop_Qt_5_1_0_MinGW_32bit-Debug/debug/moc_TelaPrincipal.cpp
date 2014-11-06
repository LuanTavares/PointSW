/****************************************************************************
** Meta object code from reading C++ file 'TelaPrincipal.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../PointSW/TelaPrincipal.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TelaPrincipal.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_TelaPrincipal_t {
    QByteArrayData data[11];
    char stringdata[183];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_TelaPrincipal_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_TelaPrincipal_t qt_meta_stringdata_TelaPrincipal = {
    {
QT_MOC_LITERAL(0, 0, 13),
QT_MOC_LITERAL(1, 14, 18),
QT_MOC_LITERAL(2, 33, 0),
QT_MOC_LITERAL(3, 34, 21),
QT_MOC_LITERAL(4, 56, 20),
QT_MOC_LITERAL(5, 77, 20),
QT_MOC_LITERAL(6, 98, 5),
QT_MOC_LITERAL(7, 104, 23),
QT_MOC_LITERAL(8, 128, 20),
QT_MOC_LITERAL(9, 149, 7),
QT_MOC_LITERAL(10, 157, 24)
    },
    "TelaPrincipal\0startaTempoDeSetup\0\0"
    "startaTempoDeProducao\0carrgaFilaDeProducao\0"
    "atualizaTempoDeSetup\0tempo\0"
    "atualizaTempoDeProducao\0selecionaPortaSerial\0"
    "leDados\0procuraParadasSemMotivos\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TelaPrincipal[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x0a,
       3,    0,   55,    2, 0x0a,
       4,    0,   56,    2, 0x0a,
       5,    1,   57,    2, 0x0a,
       7,    1,   60,    2, 0x0a,
       8,    0,   63,    2, 0x0a,
       9,    0,   64,    2, 0x0a,
      10,    0,   65,    2, 0x0a,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QTime,    6,
    QMetaType::Void, QMetaType::QTime,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void TelaPrincipal::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TelaPrincipal *_t = static_cast<TelaPrincipal *>(_o);
        switch (_id) {
        case 0: _t->startaTempoDeSetup(); break;
        case 1: _t->startaTempoDeProducao(); break;
        case 2: _t->carrgaFilaDeProducao(); break;
        case 3: _t->atualizaTempoDeSetup((*reinterpret_cast< QTime(*)>(_a[1]))); break;
        case 4: _t->atualizaTempoDeProducao((*reinterpret_cast< QTime(*)>(_a[1]))); break;
        case 5: _t->selecionaPortaSerial(); break;
        case 6: _t->leDados(); break;
        case 7: _t->procuraParadasSemMotivos(); break;
        default: ;
        }
    }
}

const QMetaObject TelaPrincipal::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_TelaPrincipal.data,
      qt_meta_data_TelaPrincipal,  qt_static_metacall, 0, 0}
};


const QMetaObject *TelaPrincipal::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TelaPrincipal::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TelaPrincipal.stringdata))
        return static_cast<void*>(const_cast< TelaPrincipal*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int TelaPrincipal::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
