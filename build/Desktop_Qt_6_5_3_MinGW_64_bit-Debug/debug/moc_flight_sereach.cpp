/****************************************************************************
** Meta object code from reading C++ file 'flight_sereach.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../flight_sereach.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'flight_sereach.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSFlight_sereachENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSFlight_sereachENDCLASS = QtMocHelpers::stringData(
    "Flight_sereach",
    "on_pushButton_clicked",
    "",
    "sortTimeEarly",
    "sortTimeLate",
    "sortPriceLow",
    "sortPriceHigh",
    "onRowButtonClicked",
    "row"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSFlight_sereachENDCLASS_t {
    uint offsetsAndSizes[18];
    char stringdata0[15];
    char stringdata1[22];
    char stringdata2[1];
    char stringdata3[14];
    char stringdata4[13];
    char stringdata5[13];
    char stringdata6[14];
    char stringdata7[19];
    char stringdata8[4];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSFlight_sereachENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSFlight_sereachENDCLASS_t qt_meta_stringdata_CLASSFlight_sereachENDCLASS = {
    {
        QT_MOC_LITERAL(0, 14),  // "Flight_sereach"
        QT_MOC_LITERAL(15, 21),  // "on_pushButton_clicked"
        QT_MOC_LITERAL(37, 0),  // ""
        QT_MOC_LITERAL(38, 13),  // "sortTimeEarly"
        QT_MOC_LITERAL(52, 12),  // "sortTimeLate"
        QT_MOC_LITERAL(65, 12),  // "sortPriceLow"
        QT_MOC_LITERAL(78, 13),  // "sortPriceHigh"
        QT_MOC_LITERAL(92, 18),  // "onRowButtonClicked"
        QT_MOC_LITERAL(111, 3)   // "row"
    },
    "Flight_sereach",
    "on_pushButton_clicked",
    "",
    "sortTimeEarly",
    "sortTimeLate",
    "sortPriceLow",
    "sortPriceHigh",
    "onRowButtonClicked",
    "row"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSFlight_sereachENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   50,    2, 0x08,    1 /* Private */,
       3,    0,   51,    2, 0x08,    2 /* Private */,
       4,    0,   52,    2, 0x08,    3 /* Private */,
       5,    0,   53,    2, 0x08,    4 /* Private */,
       6,    0,   54,    2, 0x08,    5 /* Private */,
       7,    1,   55,    2, 0x08,    6 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,

       0        // eod
};

Q_CONSTINIT const QMetaObject Flight_sereach::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSFlight_sereachENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSFlight_sereachENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSFlight_sereachENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Flight_sereach, std::true_type>,
        // method 'on_pushButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sortTimeEarly'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sortTimeLate'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sortPriceLow'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sortPriceHigh'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onRowButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>
    >,
    nullptr
} };

void Flight_sereach::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Flight_sereach *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_pushButton_clicked(); break;
        case 1: _t->sortTimeEarly(); break;
        case 2: _t->sortTimeLate(); break;
        case 3: _t->sortPriceLow(); break;
        case 4: _t->sortPriceHigh(); break;
        case 5: _t->onRowButtonClicked((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject *Flight_sereach::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Flight_sereach::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSFlight_sereachENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Flight_sereach::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
