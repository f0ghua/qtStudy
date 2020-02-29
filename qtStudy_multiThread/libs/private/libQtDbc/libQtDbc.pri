INCLUDEPATH += $$PWD/inc
INCLUDEPATH += $$PWD/src/fibex

DEFINES += SUPPORT_NETWORK_SIGNAL
QT += xml

SOURCES += \
    $$PWD/src/DbcHandle.cpp\
    $$PWD/src/File.cpp\
    $$PWD/src/Network.cpp \
    $$PWD/src/Node.cpp \
    $$PWD/src/Message.cpp \
    $$PWD/src/Signal.cpp \
    $$PWD/src/AttributeDefinition.cpp \
    $$PWD/src/Attribute.cpp \
    $$PWD/src/SignalGroup.cpp \
    $$PWD/src/Utility.cpp \
    $$PWD/src/DBCHelper.cpp

HEADERS += \
    $$PWD/inc/DbcHandle.h\
    $$PWD/inc/libqtdbc_global.h\
    $$PWD/inc/Attribute.h \
    $$PWD/inc/AttributeDefinition.h \
    $$PWD/inc/AttributeValueType.h \
    $$PWD/inc/BitTiming.h \
    $$PWD/inc/ByteOrder.h \
    $$PWD/inc/DbcHandle.h \
    $$PWD/inc/EnvironmentVariable.h \
    $$PWD/inc/ExtendedMultiplexor.h \
    $$PWD/inc/File.h \
    $$PWD/inc/Message.h \
    $$PWD/inc/Network.h \
    $$PWD/inc/Node.h \
    $$PWD/inc/platform.h \
    $$PWD/inc/SignalDbc.h \
    $$PWD/inc/SignalGroup.h \
    $$PWD/inc/Status.h \
    $$PWD/inc/Utility.h \
    $$PWD/inc/ValueDescriptions.h \
    $$PWD/inc/ValueTable.h \
    $$PWD/inc/ValueType.h \
    $$PWD/inc/vector_dbc_export.h \
    $$PWD/inc/DBCHelper.h \
    $$PWD/inc/LogDb.h


OTHER_FILES += \

