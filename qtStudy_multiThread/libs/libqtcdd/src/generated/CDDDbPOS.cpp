#include "CDDDbCONSTCOMP.h"
#include "CDDDbCONTENTCOMP.h"
#include "CDDDbEOSITERCOMP.h"
#include "CDDDbNAME.h"
#include "CDDDbNUMITERCOMP.h"
#include "CDDDbQUAL.h"
#include "CDDDbSIMPLEPROXYCOMP.h"
#include "CDDDbSTATICCOMP.h"
#include "CDDDbSTATUSDTCPROXYCOMP.h"

#include "CDDDbPOS.h"

namespace vector {
namespace cdd {

CDDDbPOS::CDDDbPOS()
{
}

CDDDbPOS::~CDDDbPOS()
{
}

void CDDDbPOS::load(const QDomElement &element)
{
    CDDDbPOSImpl::load(element);
}

} // namespace cdd
} // namespace vector
