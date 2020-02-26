#pragma once

#include "platform.h"
#include "vector_dbc_export.h"

#include "FibexTypes.h"
#include "FBAttribute.h"

namespace ASAM {
namespace FIBEX {

typedef FibexTypes::FXBitCountingPolicy ByteOrder;
typedef FibexTypes::HOBaseDataType ValueType;
// @todo fibex textable item should mapping to a range
typedef QMap<double, QString> ValueDescriptions;

class VECTOR_DBC_EXPORT FBSignal : public QObject
{
public:
    FBSignal(QObject *parent);

    /** Name */
    QString m_name;

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
    ValueType m_valueType;

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

}
}
