
#include "CDDDbCOMPANY.h"

namespace vector {
namespace cdd {

CDDDbCOMPANY::CDDDbCOMPANY()
{
}

CDDDbCOMPANY::~CDDDbCOMPANY()
{
}

void CDDDbCOMPANY::load(const QDomElement &element)
{
    CDDDbCOMPANYImpl::load(element);
}

} // namespace cdd
} // namespace vector
