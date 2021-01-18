#include "CDDDbLABEL.h"
#include "CDDDbMOD.h"
#include "CDDDbREASON.h"

#include "CDDDbHISTITEM.h"

namespace vector {
namespace cdd {

CDDDbHISTITEM::CDDDbHISTITEM()
{
}

CDDDbHISTITEM::~CDDDbHISTITEM()
{
}

void CDDDbHISTITEM::load(const QDomElement &element)
{
    CDDDbHISTITEMImpl::load(element);
}

} // namespace cdd
} // namespace vector
