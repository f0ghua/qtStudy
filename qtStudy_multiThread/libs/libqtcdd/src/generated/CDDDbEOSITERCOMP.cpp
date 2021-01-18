#include "CDDDbCONSTCOMP.h"
#include "CDDDbCONTENTCOMP.h"
#include "CDDDbDOMAINDATAPROXYCOMP.h"
#include "CDDDbMUXCOMP.h"
#include "CDDDbNAME.h"
#include "CDDDbQUAL.h"
#include "CDDDbSIMPLEPROXYCOMP.h"
#include "CDDDbSTATUSDTCPROXYCOMP.h"

#include "CDDDbEOSITERCOMP.h"

namespace vector {
namespace cdd {

CDDDbEOSITERCOMP::CDDDbEOSITERCOMP()
{
}

CDDDbEOSITERCOMP::~CDDDbEOSITERCOMP()
{
}

void CDDDbEOSITERCOMP::load(const QDomElement &element)
{
    CDDDbEOSITERCOMPImpl::load(element);
}

} // namespace cdd
} // namespace vector
