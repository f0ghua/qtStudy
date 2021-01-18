
#include "CDDDbDTCSTATUSBITGROUPImpl.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbDTCSTATUSBITGROUPImpl::CDDDbDTCSTATUSBITGROUPImpl()
{
}

CDDDbDTCSTATUSBITGROUPImpl::~CDDDbDTCSTATUSBITGROUPImpl()
{
}

void CDDDbDTCSTATUSBITGROUPImpl::load(const QDomElement &element)
{
    m_conv = element.attribute("conv");
    m_dtref = element.attribute("dtref");

}

} // namespace cdd
} // namespace vector
