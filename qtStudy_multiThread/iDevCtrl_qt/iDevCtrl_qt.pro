#-------------------------------------------------
#
# Project created by QtCreator 2018-08-03T09:42:12
#
#-------------------------------------------------

include(../../env.pri)
include(iDevCtrl_qt.pri)

QT       += serialbus serialbus-private

QT       -= gui

TARGET = $$LIBIDEVCTRL
TEMPLATE = lib

DEFINES += IDEVCTRLIB_LIBRARY

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

QMAKE_CXXFLAGS_WARN_ON += -Wno-unused-parameter -Wno-unused-variable

SOURCES += \
    jydevice.cpp \
    ngidevice.cpp \
    xmodbusaudpclient.cpp \
    xmodbusclient_p.cpp \
    xmodbustcpclient.cpp \
    itechdevice.cpp \
    icsvfile.cpp \
    xmodbusmtcpclient.cpp \
    xmodbusmudpclient.cpp


HEADERS += \
    jydevice.h \
    ngidevice.h \
    xmodbusaudpclient.h \
    xmodbusaudpclient_p.h \
    xmodbustcpclient.h \
    xmodbustcpclient_p.h \
    idevctrl_global.h \
    itechdevice.h \
    icsvfile.h \
    xmodbusmtcpclient.h \
    xmodbusmtcpclient_p.h \
    itechdevice_p.h \
    xmodbusmudpclient.h \
    xmodbusmudpclient_p.h

INCLUDEPATH += $$LIBQSLOGPATH
LIBS += -L$$DESTDIR -l$$LIBQSLOG

unix {
    target.path = /usr/lib
    INSTALLS += target
}

include(../../share/share.pri)
