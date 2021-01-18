
#include "CDDDbQUALGENOPTIONS.h"

namespace vector {
namespace cdd {

CDDDbQUALGENOPTIONS::CDDDbQUALGENOPTIONS()
{
}

CDDDbQUALGENOPTIONS::~CDDDbQUALGENOPTIONS()
{
}

void CDDDbQUALGENOPTIONS::load(const QDomElement &element)
{
    CDDDbQUALGENOPTIONSImpl::load(element);
}

} // namespace cdd
} // namespace vector
