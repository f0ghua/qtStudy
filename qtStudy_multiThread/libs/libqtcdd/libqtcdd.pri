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
    $$PWD/src/CDDDbAttrCat.h \
    $$PWD/src/CDDDbAttrCatRefType.h \
    $$PWD/src/CDDDbAttrCats.h \
    $$PWD/src/CDDDbCstrDef.h \
    $$PWD/src/CDDDbDefAtts.h \
    $$PWD/src/CDDDbDesc.h \
    $$PWD/src/CDDDbECU.h \
    $$PWD/src/CDDDbECUAtts.h \
    $$PWD/src/CDDDbECUDoc.h \
    $$PWD/src/CDDDbEnumDef.h \
    $$PWD/src/CDDDbEtag.h \
    $$PWD/src/CDDDbIdElementType.h \
    $$PWD/src/CDDDbName.h \
    $$PWD/src/CDDDbNamedElementType.h \
    $$PWD/src/CDDDbOidElementType.h \
    $$PWD/src/CDDDbQual.h \
    $$PWD/src/CDDDbStrDef.h \
    $$PWD/src/CDDDbTemplate.h \
    $$PWD/src/CDDDbTuv.h \
    $$PWD/src/CDDDbTuvedType.h \
    $$PWD/src/CDDDbUnsDef.h \
    $$PWD/src/CDDExport.h \
    $$PWD/src/CDDFile.h \
    $$PWD/src/CDDLog.h \
    $$PWD/src/CDDTypes.h

SOURCES += \
    $$PWD/src/CDDDatabase.cpp \
    $$PWD/src/CDDDbAttrCat.cpp \
    $$PWD/src/CDDDbAttrCatRefType.cpp \
    $$PWD/src/CDDDbAttrCats.cpp \
    $$PWD/src/CDDDbCstrDef.cpp \
    $$PWD/src/CDDDbDefAtts.cpp \
    $$PWD/src/CDDDbDesc.cpp \
    $$PWD/src/CDDDbECU.cpp \
    $$PWD/src/CDDDbECUAtts.cpp \
    $$PWD/src/CDDDbECUDoc.cpp \
    $$PWD/src/CDDDbEnumDef.cpp \
    $$PWD/src/CDDDbEtag.cpp \
    $$PWD/src/CDDDbIdElementType.cpp \
    $$PWD/src/CDDDbName.cpp \
    $$PWD/src/CDDDbNamedElementType.cpp \
    $$PWD/src/CDDDbOidElementType.cpp \
    $$PWD/src/CDDDbQual.cpp \
    $$PWD/src/CDDDbStrDef.cpp \
    $$PWD/src/CDDDbTemplate.cpp \
    $$PWD/src/CDDDbTuv.cpp \
    $$PWD/src/CDDDbTuvedType.cpp \
    $$PWD/src/CDDDbUnsDef.cpp \
    $$PWD/src/CDDFile.cpp \
    $$PWD/src/CDDTypes.cpp
