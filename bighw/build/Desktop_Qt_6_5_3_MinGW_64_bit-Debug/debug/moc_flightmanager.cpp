/****************************************************************************
** Meta object code from reading C++ file 'flightmanager.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../flightmanager.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'flightmanager.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSFlightManagerENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSFlightManagerENDCLASS = QtMocHelpers::stringData(
    "FlightManager",
    "addFlight",
    "",
    "searchOrders",
    "onExitButtonClicked",
    "showSearchWindow",
    "hideSearchWindow",
    "jumpSearch",
    "jumpSearch2"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSFlightManagerENDCLASS_t {
    uint offsetsAndSizes[18];
    char stringdata0[14];
    char stringdata1[10];
    char stringdata2[1];
    char stringdata3[13];
    char stringdata4[20];
    char stringdata5[17];
    char stringdata6[17];
    char stringdata7[11];
    char stringdata8[12];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSFlightManagerENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSFlightManagerENDCLASS_t qt_meta_stringdata_CLASSFlightManagerENDCLASS = {
    {
        QT_MOC_LITERAL(0, 13),  // "FlightManager"
        QT_MOC_LITERAL(14, 9),  // "addFlight"
        QT_MOC_LITERAL(24, 0),  // ""
        QT_MOC_LITERAL(25, 12),  // "searchOrders"
        QT_MOC_LITERAL(38, 19),  // "onExitButtonClicked"
        QT_MOC_LITERAL(58, 16),  // "showSearchWindow"
        QT_MOC_LITERAL(75, 16),  // "hideSearchWindow"
        QT_MOC_LITERAL(92, 10),  // "jumpSearch"
        QT_MOC_LITERAL(103, 11)   // "jumpSearch2"
    },
    "FlightManager",
    "addFlight",
    "",
    "searchOrders",
    "onExitButtonClicked",
    "showSearchWindow",
    "hideSearchWindow",
    "jumpSearch",
    "jumpSearch2"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSFlightManagerENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   56,    2, 0x0a,    1 /* Public */,
       3,    0,   57,    2, 0x0a,    2 /* Public */,
       4,    0,   58,    2, 0x0a,    3 /* Public */,
       5,    0,   59,    2, 0x0a,    4 /* Public */,
       6,    0,   60,    2, 0x0a,    5 /* Public */,
       7,    0,   61,    2, 0x0a,    6 /* Public */,
       8,    0,   62,    2, 0x0a,    7 /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject FlightManager::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSFlightManagerENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSFlightManagerENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSFlightManagerENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<FlightManager, std::true_type>,
        // method 'addFlight'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'searchOrders'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onExitButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'showSearchWindow'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'hideSearchWindow'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'jumpSearch'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'jumpSearch2'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void FlightManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FlightManager *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->addFlight(); break;
        case 1: _t->searchOrders(); break;
        case 2: _t->onExitButtonClicked(); break;
        case 3: _t->showSearchWindow(); break;
        case 4: _t->hideSearchWindow(); break;
        case 5: _t->jumpSearch(); break;
        case 6: _t->jumpSearch2(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *FlightManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FlightManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSFlightManagerENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int FlightManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
