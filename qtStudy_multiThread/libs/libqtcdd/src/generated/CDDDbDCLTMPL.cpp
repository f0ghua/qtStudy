#include "CDDDbDCLSRVTMPL.h"
#include "CDDDbDESC.h"
#include "CDDDbNAME.h"
#include "CDDDbQUAL.h"
#include "CDDDbSHPROXY.h"
#include "CDDDbSHSTATIC.h"

#include "CDDDbDCLTMPL.h"

namespace vector {
namespace cdd {

CDDDbDCLTMPL::CDDDbDCLTMPL()
{
}

CDDDbDCLTMPL::~CDDDbDCLTMPL()
{
}

void CDDDbDCLTMPL::load(const QDomElement &element)
{
    CDDDbDCLTMPLImpl::load(element);
}

} // namespace cdd
} // namespace vector
