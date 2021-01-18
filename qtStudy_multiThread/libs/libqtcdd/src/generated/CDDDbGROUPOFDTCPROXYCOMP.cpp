#include "CDDDbNAME.h"
#include "CDDDbQUAL.h"

#include "CDDDbGROUPOFDTCPROXYCOMP.h"

namespace vector {
namespace cdd {

CDDDbGROUPOFDTCPROXYCOMP::CDDDbGROUPOFDTCPROXYCOMP()
{
}

CDDDbGROUPOFDTCPROXYCOMP::~CDDDbGROUPOFDTCPROXYCOMP()
{
}

void CDDDbGROUPOFDTCPROXYCOMP::load(const QDomElement &element)
{
    CDDDbGROUPOFDTCPROXYCOMPImpl::load(element);
}

} // namespace cdd
} // namespace vector
