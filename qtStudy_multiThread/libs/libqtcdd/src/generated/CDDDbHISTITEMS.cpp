#include "CDDDbHISTITEM.h"

#include "CDDDbHISTITEMS.h"

namespace vector {
namespace cdd {

CDDDbHISTITEMS::CDDDbHISTITEMS()
{
}

CDDDbHISTITEMS::~CDDDbHISTITEMS()
{
}

void CDDDbHISTITEMS::load(const QDomElement &element)
{
    CDDDbHISTITEMSImpl::load(element);
}

} // namespace cdd
} // namespace vector
