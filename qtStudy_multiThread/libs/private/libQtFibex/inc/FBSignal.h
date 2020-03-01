#pragma once

#include "platform.h"
#include "asam_fibex_export.h"

#include "FibexTypes.h"
#include "FBAttribute.h"

#include <QDebug>

namespace ASAM {
namespace FIBEX {

class FXSignalType;
typedef FibexTypes::FXBitCountingPolicy ByteOrder;
typedef FibexTypes::HOBaseDataType CodedType;
typedef FibexTypes::FXTypeTypeSt SignalType;
// @todo fibex textable item should mapping to a range
typedef QMap<double, QString> ValueDescriptions;

class ASAM_FIBEX_EXPORT FBSignal
{
public:
    FBSignal();

    QString name() const;
    bool getDefaultValue(double &v) const;

    const FXSignalType *m_fxSignal = nullptr;
    quint32 *m_signalUpdateBitPosition = nullptr;
    SignalType *m_signalType = nullptr;

    /** Multiplexed Signal (m) */
    bool m_isMultiplexedSignal; // m

    /** Multiplexer Switch Value */
    unsigned int m_multiplexerSwitchValue;

    /** Multiplexor Switch (M) */
    bool m_isMultiplexorSwitch; // M

    /** Start Bit */
    unsigned int m_startBit;

    /** Bit Size */
    unsigned int m_bitSize;

    /** Byte Order */
    bool m_isBigEndian;

    /** Value Type */
    CodedType m_codedType;

    /** Factor */
    double m_factor;

    /** Offset */
    double m_offset;

    /** Minimun Physical Value (or 0 if auto calculated) */
    double m_minimumPhysicalValue;

    /** Maximum Physical Value (or 0 if auto calculated) */
    double m_maximumPhysicalValue;

    /** Unit */
    QString m_unit;

    /** Receivers */
    QStringList m_receivers;

    /** Signal Extended Value Type (SIG_VALTYPE, obsolete) */
    enum class ExtendedValueType : char {
        Undefined = ' ',
        Integer = '0',
        Float = '1',
        Double = '2'
    };

    /** Signal Extended Value Type (SIG_VALTYPE, obsolete) */
    ExtendedValueType m_extendedValueType;

    /** Value Descriptions (VAL) */
    ValueDescriptions m_valueDescriptions;

    /** Signal Type Refs (SGTYPE, obsolete) */
    QString m_type;

    /** Comment (CM) */
    QString m_comment;

    /** Attribute Values (BA) */
    QMap<QString, FBAttribute> m_attributeValues;

    /** Extended Multiplexors (SG_MUL_VAL) */
    //QList<ExtendedMultiplexor> extendedMultiplexors;

    //Message *parentMessage;

    /**
     * @brief Convert from Raw to Physical Value
     * @param[in] rawValue Raw Value
     * @return Raw Value
     *
     * Converts a value from raw to physical representation.
     */
    double rawToPhysicalValue(double rawValue) const;

    /**
     * @brief Convert from Physical to Raw Value
     * @param[in] physicalValue Physical Value
     * @return Physical Value
     *
     * Converts a value from physical to raw representation.
     */
    double physicalToRawValue(double physicalValue) const;

    /**
     * @brief Decodes/Extracts a signal from the message data
     * @param[in] data Data
     * @return Raw signal value
     *
     * Decodes/Extracts a signal from the message data.
     *
     * @note Multiplexors are not taken into account.
     */
    uint64_t decode(const uint8_t *msgData) const;

    /**
     * @brief Encodes a signal into the message data
     * @param[inout] data Data
     * @param[in] rawValue Raw signal value
     *
     * Encode a signal into the message data.
     *
     * @note Multiplexors are not taken into account.
     */
    void encode(uint8_t *msgData, uint64_t rawValue) const;

    bool processAsText(const uint8_t *msgData, QString &outString) const;
    bool processAsInt(const uint8_t *msgData, int32_t &outValue) const;
    bool processAsDouble(const uint8_t *msgData, double &outValue) const;
	double minimumRawValue() const;
	double maximumRawValue() const;
    double minimumPhyValue(bool isOutputDirectly = false) const;
    double maximumPhyValue(bool isOutputDirectly = false) const;
	
    void encodePhy(uint8_t *msgData, double phyValue) const;
    double decodePhy(const uint8_t *msgData) const;
};

QDebug inline operator<<(QDebug d, const FBSignal &s)
{
    double v;

    QDebugStateSaver saver(d);
    d.nospace().noquote() << "FBSignal: ("
      << "name:" << s.name() << ","
      << "ftr:" << s.m_factor << ","
      << "off:" << s.m_offset << ","
      << "ct:" << (int)s.m_codedType << ","
      << "st:" << (s.m_signalType?(QString::number((int)*s.m_signalType)):"N/A") << ","
      << "min:" << s.m_minimumPhysicalValue << ","
      << "max:" << s.m_maximumPhysicalValue << ","
      << "sb:" << s.m_startBit << ","
      << "sz:" << s.m_bitSize << ","
      << "big:" << s.m_isBigEndian << ","
      << "upb:" << (s.m_signalUpdateBitPosition?(QString::number(*s.m_signalUpdateBitPosition)):"N/A") << ","
      << "def:" << ((s.getDefaultValue(v))?(QString::number(v)):"N/A") << ","
      << "unit:" << s.m_unit << ","
      << "txt:" << s.m_valueDescriptions
      << ")";

    return d;
}

}
}