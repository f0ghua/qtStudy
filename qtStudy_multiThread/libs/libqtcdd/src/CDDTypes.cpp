#include "CDDTypes.h"

namespace vector {
namespace cdd {

template<>
EnumParser<CDDUnsignedDataFormat>::EnumParser()
{
    enumMap["dec"]                      = CDDUnsignedDataFormat::eDEC;
    enumMap["hex"]                      = CDDUnsignedDataFormat::eHEX;
}

template<>
EnumParser<CDDServiceClass>::EnumParser()
{
    enumMap["ses"]                      = CDDServiceClass::eSESSIONS;
    enumMap["fun"]                      = CDDServiceClass::eFUNCTION;
    enumMap["sec"]                      = CDDServiceClass::eSECURITYACCESS;
    enumMap["com"]                      = CDDServiceClass::eCOMMUNICATION;
    enumMap["tpr"]                      = CDDServiceClass::eTESTERPRESENT;
    enumMap["act"]                      = CDDServiceClass::eLINKCONTROL;
    enumMap["idn"]                      = CDDServiceClass::eECU_IDENTIFICATION;
    enumMap["vcd"]                      = CDDServiceClass::eVARIANT_CODING;
    enumMap["std"]                      = CDDServiceClass::eSTORED_DATA;
    enumMap["ctl"]                      = CDDServiceClass::eIOCONTROL;
    enumMap["rtn"]                      = CDDServiceClass::eROUTINE_CONTROL;
    enumMap["mem"]                      = CDDServiceClass::eMEMORY;
    enumMap["ftm"]                      = CDDServiceClass::eFAULTMEMORY;
    enumMap["flashjob"]                 = CDDServiceClass::eFLASH_JOBS;
    enumMap["job"]                      = CDDServiceClass::eGENERIC_JOBS;
}

} // namespace cdd
} // namespace vector
