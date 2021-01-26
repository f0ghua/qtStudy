#include "CDDDbTUV.h"

#include "CDDDbSHORTCUTNAME.h"

namespace vector {
namespace cdd {

CDDDbSHORTCUTNAME::CDDDbSHORTCUTNAME()
    : CDDDbNAME()
{
}

CDDDbSHORTCUTNAME::~CDDDbSHORTCUTNAME()
{
}

void CDDDbSHORTCUTNAME::load(const QDomElement &element)
{
    CDDDbNAME::load(element);
}

} // namespace cdd
} // namespace vector
