#-------------------------------------------------
#
# Project created by QtCreator 2018-11-11T21:00:37
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qtStudy_multiThread
TEMPLATE = app

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
        gaugecar.cpp \
        gaugespeed.cpp \
        main.cpp \
        mainwindow.cpp \
        worker.cpp

HEADERS += \
        gaugecar.h \
        gaugespeed.h \
        mainwindow.h \
        worker.h

FORMS += \
        mainwindow.ui

TOPSRCDIR   = $$PWD
TOPBUILDDIR = $$shadowed($$PWD)

#include($${TOPSRCDIR}/libs/private/QAppLogging/QAppLogging.pri)

Qt += concurrent
DEFINES += LOG4QT_STATIC
LOG4QT_VERSION_MAJOR = 1
LOG4QT_VERSION_MINOR = 0
LOG4QT_VERSION_RELEASE = 0
LOG4QT_VERSION_PATCH = 0
LOG4QT_VERSION = '\\"$${LOG4QT_VERSION_MAJOR}.$${LOG4QT_VERSION_MINOR}.$${LOG4QT_VERSION_RELEASE}\\"'
DEFINES += LOG4QT_VERSION_STR=\"$${LOG4QT_VERSION}\"
#DEFINES += LOG4QT_VERSION=$${LOG4QT_VERSION}
DEFINES += LOG4QT_VERSION_MAJOR=$${LOG4QT_VERSION_MAJOR}
DEFINES += LOG4QT_VERSION_MINOR=$${LOG4QT_VERSION_MINOR}
DEFINES += LOG4QT_VERSION_PATCH=$${LOG4QT_VERSION_PATCH}

include($${TOPSRCDIR}/libs/Log4Qt/src/log4qt/log4qt.pri)
INCLUDEPATH += $${TOPSRCDIR}/libs/Log4Qt/src
INCLUDEPATH += $${TOPSRCDIR}/libs/Log4Qt/src/log4qt

RESOURCES += \
    app.qrc
