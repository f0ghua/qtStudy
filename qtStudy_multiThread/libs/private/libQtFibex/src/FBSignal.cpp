#include "FXSignalType.h"
#include "FBSignal.h"
//#include "Utility.h"
//using Vector::DBC::Utility;

#include <QtMath>



namespace ASAM {
namespace FIBEX {

FBSignal::FBSignal()
    : m_isMultiplexedSignal(false)
    , m_multiplexerSwitchValue(0)
    , m_isMultiplexorSwitch(false)

    /* position */
    , m_startBit(0)
    , m_bitSize(0)
    , m_isBigEndian(true)
    , m_codedType(CodedType::A_UINT64)

    /* raw/physical conversion */
    , m_factor(0.0)
    , m_offset(0.0)
    , m_minimumPhysicalValue(0.0)
    , m_maximumPhysicalValue(0.0)

    /* unit */
    , m_unit("Unitless")

    /* receivers */
    , m_receivers()

    /* value type and description */
    , m_extendedValueType(FBSignal::ExtendedValueType::Undefined)
    //valueDescriptions(),
    , m_type()

    /* comments and attributes */
    , m_comment()
    , m_attributeValues()

    /* extended multiplexors */
    //extendedMultiplexors()
{
    /* nothing to do here */
}

QString FBSignal::name() const
{
    return m_fxSignal?m_fxSignal->m_shortName:QString();
}

bool FBSignal::getDefaultValue(double &v) const
{
    if (m_fxSignal && m_fxSignal->m_defaultValue) {
        v = *m_fxSignal->m_defaultValue;
        return true;
    }
    return false;
}

#if 0
/*
 The way that the DBC file format works is kind of weird... For intel format signals you count up
from the start bit to the end bit which is (startbit + signallength - 1). At each point
bits are numbered in a sawtooth manner. What that means is that the very first bit is 0 and you count up
from there all of the way to 63 with each byte being 8 bits so bit 0 is the lowest bit in the first byte
and 8 is the lowest bit in the next byte up. The whole thing looks like this:
                 Bits
      7  6  5  4  3  2  1  0

  0   7  6  5  4  3  2  1  0
b 1   15 14 13 12 11 10 9  8
y 2   23 22 21 20 19 18 17 16
t 3   31 30 29 28 27 26 25 24
e 4   39 38 37 36 35 34 33 32
s 5   47 46 45 44 43 42 41 40
  6   55 54 53 52 51 50 49 48
  7   63 62 61 60 59 58 57 56

  For intel format you start at the start bit and keep counting up. If you have a signal size of 8
  and start at bit 12 then the bits are 12, 13, 14, 15, 16, 17, 18, 19 which spans across two bytes.
  In this format each bit is worth twice as much as the last and you just keep counting up.
  Bit 12 is worth 1, 13 is worth 2, 14 is worth 4, etc all of the way to bit 19 is worth 128.

  Motorola format turns most everything on its head. You count backward from the start bit but
  only within the current byte. If you are about to exit the current byte you go one higher and then keep
  going backward as before. Using the same example as for intel, start bit of 12 and a signal length of 8.
  So, the bits are 12, 11, 10, 9, 8, 23, 22, 21. Yes, that's confusing. They now go in reverse value order too.
  Bit 12 is worth 128, 11 is worth 64, etc until bit 21 is worth 1.
*/
bool FBSignal::processAsText(const uint8_t *msgData, QString &outString) const
{
    int64_t result = 0;
    bool isSigned = false;
    double endResult;

    if (valueType == ValueType::String)
    {
        QString buildString;
        int startByte = startBit / 8;
        int bytes = bitSize / 8;
        for (int x = 0; x < bytes; x++) buildString.append(msgData[startByte + x]);
        outString = buildString;
        return true;
    }

    //if this is a multiplexed signal then we have to see if it is even found in the current message
    if (multiplexedSignal)
    {
        if (parentMessage->multiplexorSignal != NULL)
        {
           int val;
           if (!parentMessage->multiplexorSignal->processAsInt(msgData, val)) return false;
           if (val != (int32_t)multiplexerSwitchValue) return false; //signal not found in this message
        }
        else return false;
    }

    if (valueType == ValueType::Signed) isSigned = true;
    if (valueType == ValueType::Signed || valueType == ValueType::Unsigned)
    {
        result = Utility::processIntegerSignal(msgData, startBit, bitSize, byteOrder, isSigned);
        endResult = ((double)result * factor) + offset;
        result = (int64_t)endResult;
    }
    else if (valueType == ValueType::SPFloat)
    {
        //The theory here is that we force the integer signal code to treat this as
        //a 32 bit unsigned integer. This integer is then cast into a float in such a way
        //that the bytes that make up the integer are instead treated as having made up
        //a 32 bit single precision float. That's evil incarnate but it is very fast and small
        //in terms of new code.
        result = Utility::processIntegerSignal(msgData, startBit, 32, byteOrder, false);
        endResult = (*((float *)(&result)) * factor) + offset;
    }
    else //double precision float
    {
        //like the above, this is rotten and evil and wrong in so many ways. Force
        //calculation of a 64 bit integer and then cast it into a double.
        result = Utility::processIntegerSignal(msgData, 0, 64, byteOrder, false);
        endResult = (*((double *)(&result)) * factor) + offset;
    }

    QString outputString;

    outputString = name + ": ";

    if (valueDescriptions.count() > 0) //if this is a value list type then look it up and display the proper string
    {
        auto it = valueDescriptions.find(result);
        if ((it != valueDescriptions.end()) && (it.key() == result))
        {
            outputString += it.value();
        }
    }
    else //otherwise display the actual number and unit (if it exists)
    {
       outputString += QString::number(endResult) + unit;
    }

    outString = outputString;
    return true;
}

//Works quite a bit like the above version but this one is cut down and only will return int32_t which is perfect for
//uses like calculating a multiplexor value or if you know you are going to get an integer returned
//from a signal and you want to use it as-is and not have to convert back from a string. Use with caution though
//as this basically assumes the signal is an integer.
//The call syntax is different from the more generic processSignal. Instead of returning the value we return
//true or false to show whether the function succeeded. The variable to fill out is passed by reference.
bool FBSignal::processAsInt(const uint8_t *msgData, int32_t &outValue) const
{
    int32_t result = 0;
    bool isSigned = false;

    if (valueType == ValueType::String ||
        valueType == ValueType::SPFloat  ||
        valueType == ValueType::DPFloat)
    {
        return false;
    }

    //if this is a multiplexed signal then we have to see if it is even found in the current message
    if (multiplexedSignal)
    {
        if (parentMessage->multiplexorSignal != NULL)
        {
           int val;
           if (!parentMessage->multiplexorSignal->processAsInt(msgData, val)) return false;
           if (val != (int32_t)multiplexerSwitchValue) return false; //signal not found in this message
        }
        else return false;
    }

    if (valueType == ValueType::Signed) isSigned = true;
    result = Utility::processIntegerSignal(msgData, startBit, bitSize, byteOrder, isSigned);

    double endResult = ((double)result * factor) + offset;
    result = (int32_t)endResult;

    outValue = result;
    return true;
}

//Another cut down version that will only return double precision data. This can be used on any of the types
//except STRING. Useful for when you know you'll need floating point data and don't want to incur a conversion
//back and forth to double or float. Such a use is the graphing window.
//Similar syntax to processSignalInt but with double instead.
bool FBSignal::processAsDouble(const uint8_t *msgData, double &outValue) const
{
    int64_t result = 0;
    bool isSigned = false;
    double endResult;

    if (valueType == ValueType::String)
    {
        return false;
    }

    //if this is a multiplexed signal then we have to see if it is even found in the current message
    if (multiplexedSignal)
    {
        if (parentMessage->multiplexorSignal != NULL)
        {
           int val;
           if (!parentMessage->multiplexorSignal->processAsInt(msgData, val)) return false;
           if (val != (int32_t)multiplexerSwitchValue) return false; //signal not found in this message
        }
        else return false;
    }

    if (valueType == ValueType::Signed) isSigned = true;
    if (valueType == ValueType::Signed || valueType == ValueType::Unsigned)
    {
        result = Utility::processIntegerSignal(msgData, startBit, bitSize, byteOrder, isSigned);
        endResult = ((double)result * factor) + offset;
        result = (int64_t)endResult;
    }
    /*TODO: It should be noted that the below floating point has not even been tested. For shame! Test it!*/
    else if (valueType == ValueType::SPFloat)
    {
        //The theory here is that we force the integer signal code to treat this as
        //a 32 bit unsigned integer. This integer is then cast into a float in such a way
        //that the bytes that make up the integer are instead treated as having made up
        //a 32 bit single precision float. That's evil incarnate but it is very fast and small
        //in terms of new code.
        result = Utility::processIntegerSignal(msgData, startBit, 32, byteOrder, false);
        endResult = (*((float *)(&result)) * factor) + offset;
    }
    else //double precision float
    {
        //like the above, this is rotten and evil and wrong in so many ways. Force
        //calculation of a 64 bit integer and then cast it into a double.
        result = Utility::processIntegerSignal(msgData, 0, 64, byteOrder, false);
        endResult = (*((double *)(&result)) * factor) + offset;
    }

    outValue = endResult;
    return true;
}
#endif

double FBSignal::rawToPhysicalValue(double rawValue) const
{
    /* physicalValue = rawValue * factor + offset */
    return rawValue * m_factor + m_offset;
}

double FBSignal::physicalToRawValue(double physicalValue) const
{
    /* safety check */
    if (m_factor == 0)
        return 0;

    /* rawValue = (physicalValue - offset) / factor */
    return (physicalValue - m_offset) / m_factor;
}

inline bool isValueTypeSigned(CodedType t)
{
    return ((t == CodedType::A_INT8)
            || (t == CodedType::A_INT16)
            || (t == CodedType::A_INT32)
            || (t == CodedType::A_INT64));
}

double FBSignal::minimumPhyValue(bool isOutputDirectly) const
{
    if ((m_minimumPhysicalValue) || (isOutputDirectly))
        return m_minimumPhysicalValue;
	else
		return rawToPhysicalValue(minimumRawValue());
}

double FBSignal::maximumPhyValue(bool isOutputDirectly) const
{
    if ((m_maximumPhysicalValue) || (isOutputDirectly))
        return m_maximumPhysicalValue;
	else
		return rawToPhysicalValue(maximumRawValue());
}

double FBSignal::minimumRawValue() const
{
    /* calculate minimum raw value */
    double minimumRawValue = 0.0;
	
    switch (m_codedType) {
        case CodedType::A_UINT8:
        case CodedType::A_UINT16:
        case CodedType::A_UINT32:
        case CodedType::A_UINT64:
            minimumRawValue = 0.0;
            break;
        case CodedType::A_INT8:
        case CodedType::A_INT16:
        case CodedType::A_INT32:
        case CodedType::A_INT64:
            minimumRawValue = -(2<<(m_bitSize-2));
            break;
        case CodedType::A_FLOAT32:
        	minimumRawValue = 3.4e-38;
        	break;

        case CodedType::A_FLOAT64:
        	minimumRawValue = 1.7e-308;
        	break;

		default:
			break;
    }
	
    return minimumRawValue;
}

double FBSignal::maximumRawValue() const
{
    /* calculate maximum raw value */
    double maximumRawValue = 0.0;
	
    switch (m_codedType) {
        case CodedType::A_UINT8:
        case CodedType::A_UINT16:
        case CodedType::A_UINT32:
        case CodedType::A_UINT64:
            maximumRawValue = (m_bitSize<1)?0:(2<<(m_bitSize-1))-1;
            break;
        case CodedType::A_INT8:
        case CodedType::A_INT16:
        case CodedType::A_INT32:
        case CodedType::A_INT64:
            maximumRawValue = (m_bitSize<2)?0:(2<<(m_bitSize-2))-1;
            break;
        case CodedType::A_FLOAT32:
        	maximumRawValue = 3.4e38;
        	break;

        case CodedType::A_FLOAT64:
        	maximumRawValue = 1.7e308;
        	break;

		default:
			break;
    }
    return maximumRawValue;
}

uint64_t FBSignal::decode(const uint8_t *msgData) const
{
    std::uint64_t retVal = 0;
    unsigned int size = m_bitSize;

    /* copy bits */
    if (m_isBigEndian) {
        /* start with MSB */
        unsigned int srcBit = m_startBit;
        unsigned int dstBit = size - 1;
        while(size > 0) {
            /* copy bit */
            if (msgData[srcBit/8] & (1<<(srcBit%8))) {
                retVal |= (1ULL<<dstBit);
            }

            /* calculate next position */
            if ((srcBit % 8) == 0) {
                srcBit += 15;
            } else {
                --srcBit;
            }
            --dstBit;
            --size;
        }
    } else {
        /* start with LSB */
        unsigned int srcBit = m_startBit;
        unsigned int dstBit = 0;
        while(size > 0) {
            /* copy bit */
            if (msgData[srcBit/8] & (1<<(srcBit%8))) {
                retVal |= (1ULL<<dstBit);
            }

            /* calculate next position */
            ++srcBit;
            ++dstBit;
            --size;
        }
    }

    /* if signed, then fill all bits above MSB with 1 */
    if (isValueTypeSigned(m_codedType)) {
        uint64_t msb = (retVal >> (size - 1)) & 1;
        if (msb) {
            for (unsigned int i = size; i < 8*sizeof(retVal); ++i) {
                retVal |= (1ULL<<i);
            }
        }
    }

    return retVal;
}

void FBSignal::encode(uint8_t *msgData, uint64_t rawValue) const
{
    unsigned int size = m_bitSize;

    /* copy bits */
    if (m_isBigEndian) {
        /* start with MSB */
        unsigned int srcBit = m_startBit;
        unsigned int dstBit = size - 1;
        while(size > 0) {
            /* copy bit */
            if (rawValue & (1ULL<<dstBit)) {
                msgData[srcBit/8] |= (1<<(srcBit%8));
            } else {
                msgData[srcBit/8] &= ~(1<<(srcBit%8));
            }

            /* calculate next position */
            if ((srcBit % 8) == 0) {
                srcBit += 15;
            } else {
                --srcBit;
            }
            --dstBit;
            --size;
        }
    } else {
        /* start with LSB */
        unsigned int srcBit = m_startBit;
        unsigned int dstBit = 0;
        while(size > 0) {
            /* copy bit */
            if (rawValue & (1ULL<<dstBit)) {
                msgData[srcBit/8] |= (1<<(srcBit%8));
            } else {
                msgData[srcBit/8] &= ~(1<<(srcBit%8));
            }

            /* calculate next position */
            ++srcBit;
            ++dstBit;
            --size;
        }
    }
}

void FBSignal::encodePhy(uint8_t *msgData, double phyValue) const
{
    double rowDoubleValue = physicalToRawValue(phyValue);
    quint64 rawValue = static_cast<quint64>(llround(rowDoubleValue));
    encode(msgData, rawValue);
}

double FBSignal::decodePhy(const uint8_t *msgData) const
{
    uint64_t rawValue = decode(msgData);
    double phyValue = rawToPhysicalValue(rawValue);

    return phyValue;
}

} // FIBEX
} // ASAM
