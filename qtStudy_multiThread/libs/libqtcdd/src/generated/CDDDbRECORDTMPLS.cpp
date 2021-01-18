#include "CDDDbRECORDTMPL.h"

#include "CDDDbRECORDTMPLS.h"

namespace vector {
namespace cdd {

CDDDbRECORDTMPLS::CDDDbRECORDTMPLS()
{
}

CDDDbRECORDTMPLS::~CDDDbRECORDTMPLS()
{
}

void CDDDbRECORDTMPLS::load(const QDomElement &element)
{
    CDDDbRECORDTMPLSImpl::load(element);
}

} // namespace cdd
} // namespace vector
