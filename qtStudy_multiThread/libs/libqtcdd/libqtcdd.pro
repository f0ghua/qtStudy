include(../../../appskeleton.pri)

TEMPLATE = lib
CONFIG += libqtcdd-buildlib

include(libqtcdd.pri)

TARGET = $$LIB_NAME

#CONFIG += debug_and_release build_all
CONFIG += skip_target_version_ext
