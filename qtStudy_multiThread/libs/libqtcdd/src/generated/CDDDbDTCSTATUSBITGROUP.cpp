
#include "CDDDbDTCSTATUSBITGROUP.h"

namespace vector {
namespace cdd {

CDDDbDTCSTATUSBITGROUP::CDDDbDTCSTATUSBITGROUP()
{
}

CDDDbDTCSTATUSBITGROUP::~CDDDbDTCSTATUSBITGROUP()
{
}

void CDDDbDTCSTATUSBITGROUP::load(const QDomElement &element)
{
    CDDDbDTCSTATUSBITGROUPImpl::load(element);
}

} // namespace cdd
} // namespace vector
