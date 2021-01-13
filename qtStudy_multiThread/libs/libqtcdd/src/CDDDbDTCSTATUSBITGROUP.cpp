
#include "CDDDbDTCSTATUSBITGROUP.h"

#include <QDomElement>

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
    m_conv = element.attribute("conv");
    m_dtref = element.attribute("dtref");

}

} // namespace cdd
} // namespace vector
