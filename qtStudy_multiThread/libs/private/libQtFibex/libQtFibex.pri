INCLUDEPATH += $$PWD/inc
INCLUDEPATH += $$PWD/src/fibex

DEFINES += SUPPORT_NETWORK_SIGNAL
QT += xml

SOURCES += \
    $$PWD/src/File.cpp\
    $$PWD/src/Fibex.cpp \
    $$PWD/src/FXFibex.cpp \
    $$PWD/src/FXElements.cpp \
    $$PWD/src/FXFrameType.cpp \
    $$PWD/src/FibexTypes.cpp \
    $$PWD/src/HONameDetails.cpp \
    $$PWD/src/FXNamedElementType.cpp \
    $$PWD/src/FXRevisedElementType.cpp \
    $$PWD/src/FXPduInstances.cpp \
    $$PWD/src/FXPduInstanceType.cpp \
    $$PWD/src/FXGenericPduInstanceType.cpp \
    $$PWD/src/FXPduType.cpp \
    $$PWD/src/FXSignalInstances.cpp \
    $$PWD/src/FXSignalInstanceType.cpp \
    $$PWD/src/FXSignalRef.cpp \
    $$PWD/src/FXCommonLayoutDetails.cpp \
    $$PWD/src/FXSignalType.cpp \
    $$PWD/src/FXSignalTypeType.cpp \
    $$PWD/src/FXProcessingInformation.cpp \
    $$PWD/src/FXCodings.cpp \
    $$PWD/src/FXCodingType.cpp \
    $$PWD/src/HOCodedType.cpp \
    $$PWD/src/FXEcuType.cpp \
    $$PWD/src/FXControllerType.cpp \
    $$PWD/src/FRControllerType.cpp \
    $$PWD/src/FRKeySlotUsage.cpp \
    $$PWD/src/FXConnectorType.cpp \
    $$PWD/src/FXEcuPortType.cpp \
    $$PWD/src/FXIncludedPduType.cpp \
    $$PWD/src/FXIncludedSignalType.cpp \
    $$PWD/src/FRConnectorType.cpp \
    $$PWD/src/HOCompuCategory.cpp \
    $$PWD/src/HOCompuMethods.cpp \
    $$PWD/src/HOScaleConstrType.cpp \
    $$PWD/src/HOCompuRationalCoeffs.cpp \
    $$PWD/src/HOCompuScale.cpp \
    $$PWD/src/HOCompInternalToPhys.cpp \
    $$PWD/src/HOCompuMethod.cpp \
    $$PWD/src/HOUnit.cpp \
    $$PWD/src/HOUnitSpec.cpp \
    $$PWD/src/FXChannelType.cpp \
    $$PWD/src/FXFrameTriggeringType.cpp \
    $$PWD/src/FXPduTriggeringType.cpp \
    $$PWD/src/FXFrameTimings.cpp \
    $$PWD/src/FXAbsolutelyScheduledTimingType.cpp \
    $$PWD/src/FXPduTimings.cpp \
    $$PWD/src/FXCyclicTimingType.cpp \
    $$PWD/src/FXEventControlledTimingType.cpp \
    $$PWD/src/FXRequestControlledTimingType.cpp \
    $$PWD/src/FXTimeRangeType.cpp \
    $$PWD/src/FXActiveConditionType.cpp \
    $$PWD/src/FXSystemTrigger.cpp \
    $$PWD/src/FXExecuteConditionType.cpp \
    $$PWD/src/FXSignalTrigger.cpp \
    $$PWD/src/FXRelativelyScheduledTimingType.cpp \
    $$PWD/src/FXIdentifier.cpp \
    $$PWD/src/FXClusterType.cpp \
    $$PWD/src/FRChannelType.cpp \
    $$PWD/src/FRClusterType.cpp \
    $$PWD/src/FBSignal.cpp \
    $$PWD/src/HOScaleConstr.cpp \
    $$PWD/src/HOCompuConst.cpp \
    $$PWD/src/FBPdu.cpp \
    $$PWD/src/FBFrame.cpp \
    $$PWD/src/FBChannel.cpp \
    $$PWD/src/FBCluster.cpp \
    $$PWD/src/FBEcu.cpp \
    $$PWD/src/FibexKey.cpp \
    $$PWD/src/FRWakeUp.cpp

HEADERS += \
    $$PWD/inc/asam_fibex_export.h \
    $$PWD/inc/File.h \
    $$PWD/inc/platform.h \
    $$PWD/inc/Fibex.h \
    $$PWD/inc/FXFibex.h \
    $$PWD/inc/FXElements.h \
    $$PWD/inc/FXFrameType.h \
    $$PWD/inc/FibexTypes.h \
    $$PWD/inc/HONameDetails.h \
    $$PWD/inc/FXNamedElementType.h \
    $$PWD/inc/FXRevisedElementType.h \
    $$PWD/inc/FXPduInstances.h \
    $$PWD/inc/FXPduInstanceType.h \
    $$PWD/inc/FXGenericPduInstanceType.h \
    $$PWD/inc/FXPduType.h \
    $$PWD/inc/FXSignalInstances.h \
    $$PWD/inc/FXSignalInstanceType.h \
    $$PWD/inc/FXSignalRef.h \
    $$PWD/inc/FXCommonLayoutDetails.h \
    $$PWD/inc/FXSignalType.h \
    $$PWD/inc/FXSignalTypeType.h \
    $$PWD/inc/FXProcessingInformation.h \
    $$PWD/inc/FXCodings.h \
    $$PWD/inc/FXCodingType.h \
    $$PWD/inc/HOCodedType.h \
    $$PWD/inc/FXEcuType.h \
    $$PWD/inc/FXControllerType.h \
    $$PWD/inc/FRControllerType.h \
    $$PWD/inc/FRKeySlotUsage.h \
    $$PWD/inc/FXConnectorType.h \
    $$PWD/inc/FXEcuPortType.h \
    $$PWD/inc/FXIncludedPduType.h \
    $$PWD/inc/FXIncludedSignalType.h \
    $$PWD/inc/FRConnectorType.h \
    $$PWD/inc/HOCompuCategory.h \
    $$PWD/inc/HOCompuMethods.h \
    $$PWD/inc/HOScaleConstrType.h \
    $$PWD/inc/HOCompuRationalCoeffs.h \
    $$PWD/inc/HOCompuScale.h \
    $$PWD/inc/HOCompInternalToPhys.h \
    $$PWD/inc/HOCompuMethod.h \
    $$PWD/inc/HOUnit.h \
    $$PWD/inc/HOUnitSpec.h \
    $$PWD/inc/FXChannelType.h \
    $$PWD/inc/FXFrameTriggeringType.h \
    $$PWD/inc/FXPduTriggeringType.h \
    $$PWD/inc/FXFrameTimings.h \
    $$PWD/inc/FXAbsolutelyScheduledTimingType.h \
    $$PWD/inc/FXPduTimings.h \
    $$PWD/inc/FXCyclicTimingType.h \
    $$PWD/inc/FXEventControlledTimingType.h \
    $$PWD/inc/FXRequestControlledTimingType.h \
    $$PWD/inc/FXTimeRangeType.h \
    $$PWD/inc/FXActiveConditionType.h \
    $$PWD/inc/FXSystemTrigger.h \
    $$PWD/inc/FXExecuteConditionType.h \
    $$PWD/inc/FXSignalTrigger.h \
    $$PWD/inc/FXRelativelyScheduledTimingType.h \
    $$PWD/inc/FXIdentifier.h \
    $$PWD/inc/FXClusterType.h \
    $$PWD/inc/FRChannelType.h \
    $$PWD/inc/FRClusterType.h \
    $$PWD/inc/FBAttribute.h \
    $$PWD/inc/FBSignal.h \
    $$PWD/inc/FBAttributeValueType.h \
    $$PWD/inc/HOScaleConstr.h \
    $$PWD/inc/HOCompuConst.h \
    $$PWD/inc/FBPdu.h \
    $$PWD/inc/FBFrame.h \
    $$PWD/inc/FBChannel.h \
    $$PWD/inc/FBCluster.h \
    $$PWD/inc/FBEcu.h \
    $$PWD/inc/FibexKey.h \
    $$PWD/inc/FRWakeUp.h \



OTHER_FILES += \

