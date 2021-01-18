#include "CDDDbNAME.h"
#include "CDDDbQUAL.h"

#include "CDDDbSTATUSDTCPROXYCOMP.h"

namespace vector {
namespace cdd {

CDDDbSTATUSDTCPROXYCOMP::CDDDbSTATUSDTCPROXYCOMP()
{
}

CDDDbSTATUSDTCPROXYCOMP::~CDDDbSTATUSDTCPROXYCOMP()
{
}

void CDDDbSTATUSDTCPROXYCOMP::load(const QDomElement &element)
{
    CDDDbSTATUSDTCPROXYCOMPImpl::load(element);
}

} // namespace cdd
} // namespace vector
