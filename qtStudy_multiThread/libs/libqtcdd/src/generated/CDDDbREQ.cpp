#include "CDDDbCONSTCOMP.h"
#include "CDDDbCONTENTCOMP.h"
#include "CDDDbDOMAINDATAPROXYCOMP.h"
#include "CDDDbEOSITERCOMP.h"
#include "CDDDbGROUPOFDTCPROXYCOMP.h"
#include "CDDDbMUXCOMP.h"
#include "CDDDbNAME.h"
#include "CDDDbQUAL.h"
#include "CDDDbSIMPLEPROXYCOMP.h"
#include "CDDDbSTATICCOMP.h"
#include "CDDDbSTATUSDTCPROXYCOMP.h"

#include "CDDDbREQ.h"

namespace vector {
namespace cdd {

CDDDbREQ::CDDDbREQ()
{
}

CDDDbREQ::~CDDDbREQ()
{
}

void CDDDbREQ::load(const QDomElement &element)
{
    CDDDbREQImpl::load(element);
}

} // namespace cdd
} // namespace vector
