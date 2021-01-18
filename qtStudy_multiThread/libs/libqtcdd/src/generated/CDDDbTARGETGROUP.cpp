#include "CDDDbNAME.h"
#include "CDDDbQUAL.h"

#include "CDDDbTARGETGROUP.h"

namespace vector {
namespace cdd {

CDDDbTARGETGROUP::CDDDbTARGETGROUP()
{
}

CDDDbTARGETGROUP::~CDDDbTARGETGROUP()
{
}

void CDDDbTARGETGROUP::load(const QDomElement &element)
{
    CDDDbTARGETGROUPImpl::load(element);
}

} // namespace cdd
} // namespace vector
