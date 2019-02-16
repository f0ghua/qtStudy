#-------------------------------------------------
#
# Project created by QtCreator 2018-11-11T21:00:37
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = iEngineBenchMark
TEMPLATE = app

DEFINES += CRASHDUMP_DRMINGW

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    worker.cpp \
    canconnection.cpp \
    ftusbbackend.cpp \
    utils.cpp \
    settingsmanager.cpp \
    xbusframe.cpp \
    canconnfactory.cpp \
    ienginebackend.cpp \
    ienginebackendhelper.cpp

HEADERS += \
        mainwindow.h \
    worker.h \
    canconnection.h \
    canconnection_p.h \
    ftusbbackend.h \
    ftusbbackend_p.h \
    lfqueue.h \
    utils.h \
    settingsmanager.h \
    xbusframe.h \
    canconnfactory.h \
    ienginebackend.h \
    ienginebackend_p.h \
    ienginebackendhelper.h \
    ienginebackendhelper_p.h

FORMS += \
        mainwindow.ui

TOPSRCDIR   = $$PWD
TOPBUILDDIR = $$shadowed($$PWD)

DESTDIR = $$TOPBUILDDIR/output

include($${TOPSRCDIR}/libs/private/QAppLogging/QAppLogging.pri)
contains(DEFINES, CRASHDUMP_DRMINGW) {
include($${TOPSRCDIR}/libs/3rdparty/drmingw/drmingw.pri)
}

LIBFTDI = $${TOPSRCDIR}/libs/3rdparty/ftdi
INCLUDEPATH += $$LIBFTDI
LIBS += -L$$DESTDIR $${LIBFTDI}/ftd2xx.lib -lwinmm

