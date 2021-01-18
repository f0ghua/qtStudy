#include "CDDDbNAME.h"
#include "CDDDbQUAL.h"

#include "CDDDbJOBCNR.h"

namespace vector {
namespace cdd {

CDDDbJOBCNR::CDDDbJOBCNR()
{
}

CDDDbJOBCNR::~CDDDbJOBCNR()
{
}

void CDDDbJOBCNR::load(const QDomElement &element)
{
    CDDDbJOBCNRImpl::load(element);
}

} // namespace cdd
} // namespace vector
