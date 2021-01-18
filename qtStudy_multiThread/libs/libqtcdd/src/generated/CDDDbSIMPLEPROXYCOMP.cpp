#include "CDDDbDESC.h"
#include "CDDDbNAME.h"
#include "CDDDbQUAL.h"

#include "CDDDbSIMPLEPROXYCOMP.h"

namespace vector {
namespace cdd {

CDDDbSIMPLEPROXYCOMP::CDDDbSIMPLEPROXYCOMP()
{
}

CDDDbSIMPLEPROXYCOMP::~CDDDbSIMPLEPROXYCOMP()
{
}

void CDDDbSIMPLEPROXYCOMP::load(const QDomElement &element)
{
    CDDDbSIMPLEPROXYCOMPImpl::load(element);
}

} // namespace cdd
} // namespace vector
