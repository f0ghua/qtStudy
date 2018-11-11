QT       	+= serialbus serialbus-private
INCLUDEPATH     += $$PWD
IDEVCTRLDIR     = $$PWD

SOURCES += \
    $$IDEVCTRLDIR/jydevice.cpp \
    $$IDEVCTRLDIR/ngidevice.cpp \
    $$IDEVCTRLDIR/xmodbusaudpclient.cpp \
    $$IDEVCTRLDIR/xmodbusclient_p.cpp \
    $$IDEVCTRLDIR/xmodbustcpclient.cpp \
    $$IDEVCTRLDIR/itechdevice.cpp \
    $$IDEVCTRLDIR/xmodbusmtcpclient.cpp \
    $$IDEVCTRLDIR/xmodbusmudpclient.cpp

HEADERS += \
    $$IDEVCTRLDIR/jydevice.h \
    $$IDEVCTRLDIR/ngidevice.h \
    $$IDEVCTRLDIR/xmodbusaudpclient.h \
    $$IDEVCTRLDIR/xmodbusaudpclient_p.h \
    $$IDEVCTRLDIR/xmodbustcpclient.h \
    $$IDEVCTRLDIR/xmodbustcpclient_p.h \
    $$IDEVCTRLDIR/idevctrl_global.h \
    $$IDEVCTRLDIR/itechdevice.h \
    $$IDEVCTRLDIR/xmodbusmtcpclient.h \
    $$IDEVCTRLDIR/xmodbusmtcpclient_p.h \
    $$IDEVCTRLDIR/itechdevice_p.h \
    $$IDEVCTRLDIR/xmodbusmudpclient.h \
    $$IDEVCTRLDIR/xmodbusmudpclient_p.h
