#include "CDDDbCOMMONSTRING.h"

#include "CDDDbCSTR.h"

namespace vector {
namespace cdd {

CDDDbCSTR::CDDDbCSTR()
{
}

CDDDbCSTR::~CDDDbCSTR()
{
}

void CDDDbCSTR::load(const QDomElement &element)
{
    CDDDbCSTRImpl::load(element);
}

} // namespace cdd
} // namespace vector
