#include "CDDDbNAME.h"
#include "CDDDbQUAL.h"
#include "CDDDbSIMPLEPROXYCOMP.h"

#include "CDDDbNUMITERCOMP.h"

namespace vector {
namespace cdd {

CDDDbNUMITERCOMP::CDDDbNUMITERCOMP()
{
}

CDDDbNUMITERCOMP::~CDDDbNUMITERCOMP()
{
}

void CDDDbNUMITERCOMP::load(const QDomElement &element)
{
    CDDDbNUMITERCOMPImpl::load(element);
}

} // namespace cdd
} // namespace vector
