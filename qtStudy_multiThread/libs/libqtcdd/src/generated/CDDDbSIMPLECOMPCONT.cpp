#include "CDDDbDATAOBJ.h"
#include "CDDDbDIDDATAREF.h"
#include "CDDDbGODTCDATAOBJ.h"
#include "CDDDbRECORDDATAOBJ.h"
#include "CDDDbSPECDATAOBJ.h"
#include "CDDDbSTRUCT.h"

#include "CDDDbSIMPLECOMPCONT.h"

namespace vector {
namespace cdd {

CDDDbSIMPLECOMPCONT::CDDDbSIMPLECOMPCONT()
{
}

CDDDbSIMPLECOMPCONT::~CDDDbSIMPLECOMPCONT()
{
}

void CDDDbSIMPLECOMPCONT::load(const QDomElement &element)
{
    CDDDbSIMPLECOMPCONTImpl::load(element);
}

} // namespace cdd
} // namespace vector
