#include "CDDDbNEGRESCODE.h"

#include "CDDDbNEGRESCODES.h"

namespace vector {
namespace cdd {

CDDDbNEGRESCODES::CDDDbNEGRESCODES()
{
}

CDDDbNEGRESCODES::~CDDDbNEGRESCODES()
{
}

void CDDDbNEGRESCODES::load(const QDomElement &element)
{
    CDDDbNEGRESCODESImpl::load(element);
}

} // namespace cdd
} // namespace vector
