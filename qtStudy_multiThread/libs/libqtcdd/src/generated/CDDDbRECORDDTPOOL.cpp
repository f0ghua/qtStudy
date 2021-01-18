#include "CDDDbRECORDDT.h"

#include "CDDDbRECORDDTPOOL.h"

namespace vector {
namespace cdd {

CDDDbRECORDDTPOOL::CDDDbRECORDDTPOOL()
{
}

CDDDbRECORDDTPOOL::~CDDDbRECORDDTPOOL()
{
}

void CDDDbRECORDDTPOOL::load(const QDomElement &element)
{
    CDDDbRECORDDTPOOLImpl::load(element);
}

} // namespace cdd
} // namespace vector
