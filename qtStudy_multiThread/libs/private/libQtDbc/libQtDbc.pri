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
    $$PWD/src/fibex/FXCommonLayoutDetails.cpp \
    $$PWD/src/fibex/FXSignalType.cpp \
    $$PWD/src/fibex/FXSignalTypeType.cpp \
    $$PWD/src/fibex/FXProcessingInformation.cpp \
    $$PWD/src/fibex/FXCodings.cpp \
    $$PWD/src/fibex/FXCodingType.cpp \
    $$PWD/src/fibex/HOCodedType.cpp \
    $$PWD/src/fibex/FXEcuType.cpp \
    $$PWD/src/fibex/FXControllerType.cpp \
    $$PWD/src/fibex/FRControllerType.cpp \
    $$PWD/src/fibex/FRKeySlotUsage.cpp \
    $$PWD/src/fibex/FXConnectorType.cpp \
    $$PWD/src/fibex/FXEcuPortType.cpp \
    $$PWD/src/fibex/FXIncludedPduType.cpp \
    $$PWD/src/fibex/FXIncludedSignalType.cpp \
    $$PWD/src/fibex/FRConnectorType.cpp \
    $$PWD/src/fibex/HOCompuCategory.cpp \
    $$PWD/src/fibex/HOCompuMethods.cpp \
    $$PWD/src/fibex/HOScaleConstrType.cpp \
    $$PWD/src/fibex/HOCompuRationalCoeffs.cpp \
    $$PWD/src/fibex/HOCompuScale.cpp \
    $$PWD/src/fibex/HOCompInternalToPhys.cpp \
    $$PWD/src/fibex/HOCompuMethod.cpp \
    $$PWD/src/fibex/HOUnit.cpp \
    $$PWD/src/fibex/HOUnitSpec.cpp \
    $$PWD/src/fibex/FXChannelType.cpp \
    $$PWD/src/fibex/FXFrameTriggeringType.cpp \
    $$PWD/src/fibex/FXPduTriggeringType.cpp \
    $$PWD/src/fibex/FXFrameTimings.cpp \
    $$PWD/src/fibex/FXAbsolutelyScheduledTimingType.cpp \
    $$PWD/src/fibex/FXPduTimings.cpp \
    $$PWD/src/fibex/FXCyclicTimingType.cpp \
    $$PWD/src/fibex/FXEventControlledTimingType.cpp \
    $$PWD/src/fibex/FXRequestControlledTimingType.cpp \
    $$PWD/src/fibex/FXTimeRangeType.cpp \
    $$PWD/src/fibex/FXActiveConditionType.cpp \
    $$PWD/src/fibex/FXSystemTrigger.cpp \
    $$PWD/src/fibex/FXExecuteConditionType.cpp \
    $$PWD/src/fibex/FXSignalTrigger.cpp \
    $$PWD/src/fibex/FXRelativelyScheduledTimingType.cpp \
    $$PWD/src/fibex/FXIdentifier.cpp \
    $$PWD/src/fibex/FXClusterType.cpp \
    $$PWD/src/fibex/FRChannelType.cpp \
    $$PWD/src/fibex/FRClusterType.cpp \
    $$PWD/src/fibex/FBSignal.cpp \
    $$PWD/src/fibex/HOScaleConstr.cpp

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
    $$PWD/src/fibex/FXCommonLayoutDetails.h \
    $$PWD/src/fibex/FXSignalType.h \
    $$PWD/src/fibex/FXSignalTypeType.h \
    $$PWD/src/fibex/FXProcessingInformation.h \
    $$PWD/src/fibex/FXCodings.h \
    $$PWD/src/fibex/FXCodingType.h \
    $$PWD/src/fibex/HOCodedType.h \
    $$PWD/src/fibex/FXEcuType.h \
    $$PWD/src/fibex/FXControllerType.h \
    $$PWD/src/fibex/FRControllerType.h \
    $$PWD/src/fibex/FRKeySlotUsage.h \
    $$PWD/src/fibex/FXConnectorType.h \
    $$PWD/src/fibex/FXEcuPortType.h \
    $$PWD/src/fibex/FXIncludedPduType.h \
    $$PWD/src/fibex/FXIncludedSignalType.h \
    $$PWD/src/fibex/FRConnectorType.h \
    $$PWD/src/fibex/HOCompuCategory.h \
    $$PWD/src/fibex/HOCompuMethods.h \
    $$PWD/src/fibex/HOScaleConstrType.h \
    $$PWD/src/fibex/HOCompuRationalCoeffs.h \
    $$PWD/src/fibex/HOCompuScale.h \
    $$PWD/src/fibex/HOCompInternalToPhys.h \
    $$PWD/src/fibex/HOCompuMethod.h \
    $$PWD/src/fibex/HOUnit.h \
    $$PWD/src/fibex/HOUnitSpec.h \
    $$PWD/src/fibex/FXChannelType.h \
    $$PWD/src/fibex/FXFrameTriggeringType.h \
    $$PWD/src/fibex/FXPduTriggeringType.h \
    $$PWD/src/fibex/FXFrameTimings.h \
    $$PWD/src/fibex/FXAbsolutelyScheduledTimingType.h \
    $$PWD/src/fibex/FXPduTimings.h \
    $$PWD/src/fibex/FXCyclicTimingType.h \
    $$PWD/src/fibex/FXEventControlledTimingType.h \
    $$PWD/src/fibex/FXRequestControlledTimingType.h \
    $$PWD/src/fibex/FXTimeRangeType.h \
    $$PWD/src/fibex/FXActiveConditionType.h \
    $$PWD/src/fibex/FXSystemTrigger.h \
    $$PWD/src/fibex/FXExecuteConditionType.h \
    $$PWD/src/fibex/FXSignalTrigger.h \
    $$PWD/src/fibex/FXRelativelyScheduledTimingType.h \
    $$PWD/src/fibex/FXIdentifier.h \
    $$PWD/src/fibex/FXClusterType.h \
    $$PWD/src/fibex/FRChannelType.h \
    $$PWD/src/fibex/FRClusterType.h \
    $$PWD/src/fibex/FBAttribute.h \
    $$PWD/src/fibex/FBSignal.h \
    $$PWD/src/fibex/FBAttributeValueType.h \
    $$PWD/src/fibex/HOScaleConstr.h


OTHER_FILES += \

