QT       += core gui
QT       += core gui sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    admin_denglu.cpp \
    admin_panel.cpp \
    admin_search.cpp \
    buy.cpp \
    databasemanager.cpp \
    denglu.cpp \
    flight_search.cpp \
    gaiqian.cpp \
    info_edit.cpp \
    main.cpp \
    mainwindow.cpp \
    opendatabase.cpp \
    order.cpp \
    special_search.cpp \
    user.cpp \
    user_panel.cpp \
    widget.cpp \
    zhuce.cpp

HEADERS += \
    ../../ADMIN/头文件/ADD.h \
    ../../ADMIN/头文件/Search.h \
    ../../ADMIN/头文件/mainwindow.h \
    Search.h \
    admin_denglu.h \
    admin_panel.h \
    admin_search.h \
    buy.h \
    databasemanager.h \
    denglu.h \
    flight.h \
    flight_add.h \
    flight_search.h \
    gaiqian.h \
    global.h \
    info_edit.h \
    mainwindow.h \
    opendatabase.h \
    order.h \
    special_search.h \
    user.h \
    user_panel.h \
    widget.h \
    zhuce.h

FORMS += \
    Search.ui \
    admin_denglu.ui \
    admin_search.ui \
    buy.ui \
    databasemanager.ui \
    denglu.ui \
    flight_add.ui \
    flight_search.ui \
    gaiqian.ui \
    info_edit.ui \
    mainwindow.ui \
    special_search.ui \
    user_panel.ui \
    widget.ui \
    zhuce.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    src.qrc \
    src.qrc

SUBDIRS += \
    userPanel.pro

DISTFILES += \
    bighw.pro.user \
    bighw.pro.user.bf60372 \
    userPanel.pro.user
