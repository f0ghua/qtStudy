#include "CDDTypes.h"

namespace vector {
namespace cdd {

template<>
EnumParser<CDDUnsignedDataFormat>::EnumParser()
{
    enumMap["dec"]                      = CDDUnsignedDataFormat::eDEC;
    enumMap["hex"]                      = CDDUnsignedDataFormat::eHEX;
}


} // namespace cdd
} // namespace vector
