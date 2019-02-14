#include(../../../../appenv.pri)
#CONFIG += qtsingleapplication-uselib

#exists(config.pri):infile(config.pri, SOLUTIONS_LIBRARY, yes): CONFIG += qtsingleapplication-uselib

TEMPLATE += fakelib
greaterThan(QT_MAJOR_VERSION, 5)|\
  if(equals(QT_MAJOR_VERSION, 5):greaterThan(QT_MINOR_VERSION, 4))|\
  if(equals(QT_MAJOR_VERSION, 5):equals(QT_MINOR_VERSION, 4):greaterThan(QT_PATCH_VERSION, 1)) {
    QTSINGLEAPPLICATION_LIBNAME = $$qt5LibraryTarget(QtSolutions_SingleApplication-head)
} else {
    QTSINGLEAPPLICATION_LIBNAME = $$qtLibraryTarget(QtSolutions_SingleApplication-head)
}
TEMPLATE -= fakelib

#QTSINGLEAPPLICATION_LIBDIR = $$PWD/lib
QTSINGLEAPPLICATION_LIBDIR = $$TOPBUILDDIR/output
unix:qtsingleapplication-uselib:!qtsingleapplication-buildlib:QMAKE_RPATHDIR += $$QTSINGLEAPPLICATION_LIBDIR
