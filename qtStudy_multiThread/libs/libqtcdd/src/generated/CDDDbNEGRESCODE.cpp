#include "CDDDbNAME.h"
#include "CDDDbQUAL.h"

#include "CDDDbNEGRESCODE.h"

namespace vector {
namespace cdd {

CDDDbNEGRESCODE::CDDDbNEGRESCODE()
{
}

CDDDbNEGRESCODE::~CDDDbNEGRESCODE()
{
}

void CDDDbNEGRESCODE::load(const QDomElement &element)
{
    CDDDbNEGRESCODEImpl::load(element);
}

} // namespace cdd
} // namespace vector
