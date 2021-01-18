#include "CDDDbTEXT.h"

#include "CDDDbTRRECORDITEM.h"

namespace vector {
namespace cdd {

CDDDbTRRECORDITEM::CDDDbTRRECORDITEM()
{
}

CDDDbTRRECORDITEM::~CDDDbTRRECORDITEM()
{
}

void CDDDbTRRECORDITEM::load(const QDomElement &element)
{
    CDDDbTRRECORDITEMImpl::load(element);
}

} // namespace cdd
} // namespace vector
