#include "CDDDbDTCSTATUSBITGROUP.h"

#include "CDDDbDTCSTATUSMASK.h"

namespace vector {
namespace cdd {

CDDDbDTCSTATUSMASK::CDDDbDTCSTATUSMASK()
{
}

CDDDbDTCSTATUSMASK::~CDDDbDTCSTATUSMASK()
{
}

void CDDDbDTCSTATUSMASK::load(const QDomElement &element)
{
    CDDDbDTCSTATUSMASKImpl::load(element);
}

} // namespace cdd
} // namespace vector
