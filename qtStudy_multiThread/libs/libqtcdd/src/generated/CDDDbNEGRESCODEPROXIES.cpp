#include "CDDDbNEGRESCODEPROXY.h"

#include "CDDDbNEGRESCODEPROXIES.h"

namespace vector {
namespace cdd {

CDDDbNEGRESCODEPROXIES::CDDDbNEGRESCODEPROXIES()
{
}

CDDDbNEGRESCODEPROXIES::~CDDDbNEGRESCODEPROXIES()
{
}

void CDDDbNEGRESCODEPROXIES::load(const QDomElement &element)
{
    CDDDbNEGRESCODEPROXIESImpl::load(element);
}

} // namespace cdd
} // namespace vector
