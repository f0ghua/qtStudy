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
	$$PWD/src/DBCHelper.cpp \
    $$PWD/src/FibexFile.cpp \
    $$PWD/src/fibex/Fibex.cpp \
    $$PWD/src/fibex/FXFibex.cpp \
    $$PWD/src/fibex/FXElements.cpp \
    $$PWD/src/fibex/FXFrameType.cpp \
    $$PWD/src/fibex/FibexTypes.cpp \
    $$PWD/src/fibex/HONameDetails.cpp \
    $$PWD/src/fibex/FXNamedElementType.cpp \
    $$PWD/src/fibex/FXRevisedElementType.cpp \
    $$PWD/src/fibex/FXPduInstances.cpp \
    $$PWD/src/fibex/FXPduInstanceType.cpp \
    $$PWD/src/fibex/FXGenericPduInstanceType.cpp \
    $$PWD/src/fibex/FXPduType.cpp \
    $$PWD/src/fibex/FXSignalInstances.cpp \
    $$PWD/src/fibex/FXSignalInstanceType.cpp \
    $$PWD/src/fibex/FXSignalRef.cpp \
    $$PWD/src/fibex/FXCommonLayoutDetails.cpp

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
    $$PWD/src/fibex/Fibex.h \
    $$PWD/src/fibex/FXFibex.h \
    $$PWD/src/fibex/FXElements.h \
    $$PWD/src/fibex/FXFrameType.h \
    $$PWD/src/fibex/FibexTypes.h \
    $$PWD/src/fibex/HONameDetails.h \
    $$PWD/src/fibex/FXNamedElementType.h \
    $$PWD/src/fibex/FXRevisedElementType.h \
    $$PWD/inc/LogDb.h \
    $$PWD/src/fibex/FXPduInstances.h \
    $$PWD/src/fibex/FXPduInstanceType.h \
    $$PWD/src/fibex/FXGenericPduInstanceType.h \
    $$PWD/src/fibex/FXPduType.h \
    $$PWD/src/fibex/FXSignalInstances.h \
    $$PWD/src/fibex/FXSignalInstanceType.h \
    $$PWD/src/fibex/FXSignalRef.h \
    $$PWD/src/fibex/FXCommonLayoutDetails.h


OTHER_FILES += \

