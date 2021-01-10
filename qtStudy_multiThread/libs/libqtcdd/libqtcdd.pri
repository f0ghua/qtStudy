# A. build library
# - Add directory to SUBDIRS
#
# B. use library
# - include <libName>.pri
#

QT += xml

LIB_SRCPATH     = $$PWD
PROJECT_LIBDIR = $$DESTDIR
PROJECT_BINDIR = $$DESTDIR

LIB_NAME = $$qtLibraryTarget(libqtcdd)

!libqtdbc-buildlib{
    LIBS +=  -L$$PROJECT_LIBDIR -l$$LIB_NAME
}else{
    INCLUDEPATH += $$LIB_SRCPATH
    INCLUDEPATH += $$LIB_SRCPATH/inc
    INCLUDEPATH += $$LIB_SRCPATH/src
    DEPENDPATH  += $$LIB_SRCPATH

    win32 {
        QMAKE_CXXFLAGS += -march=i686
    }
    
    !contains(DEFINES, LIB_STATIC) {
        DEFINES += LIB_LIBRARY
        DEFINES += QLIBFIBEX_LIBRARY
    }

    LIB_VERSION_MAJOR   = 1
    LIB_VERSION_MINOR   = 0
    LIB_VERSION_RELEASE = 0
    LIB_VERSION_PATCH   = 0

    LIB_VERSION = '\\"$${LIB_VERSION_MAJOR}.$${LIB_VERSION_MINOR}.$${LIB_VERSION_RELEASE}\\"'
    DEFINES += LIB_VERSION_STR=\"$${LIB_VERSION}\"
    DEFINES += LIB_VERSION_MAJOR=$${LIB_VERSION_MAJOR}
    DEFINES += LIB_VERSION_MINOR=$${LIB_VERSION_MINOR}
    DEFINES += LIB_VERSION_PATCH=$${LIB_VERSION_PATCH}

    SOURCES += \

    HEADERS += \

}

HEADERS += \
    $$PWD/src/CDDDatabase.h \
    $$PWD/src/CDDDbCANdela.h \
    $$PWD/src/CDDDbECUDoc.h \
    $$PWD/src/CDDExport.h \
    $$PWD/src/CDDFile.h \
    $$PWD/src/CDDLog.h \
    $$PWD/src/CDDTypes.h

SOURCES += \
    $$PWD/src/CDDDatabase.cpp \
    $$PWD/src/CDDDbCANdela.cpp \
    $$PWD/src/CDDDbECUDoc.cpp \
    $$PWD/src/CDDFile.cpp
