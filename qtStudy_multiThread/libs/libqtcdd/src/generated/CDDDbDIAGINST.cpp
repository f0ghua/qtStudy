#include "CDDDbDESC.h"
#include "CDDDbNAME.h"
#include "CDDDbQUAL.h"
#include "CDDDbSERVICE.h"
#include "CDDDbSIMPLECOMPCONT.h"
#include "CDDDbSTATICVALUE.h"

#include "CDDDbDIAGINST.h"

namespace vector {
namespace cdd {

CDDDbDIAGINST::CDDDbDIAGINST()
{
}

CDDDbDIAGINST::~CDDDbDIAGINST()
{
}

void CDDDbDIAGINST::load(const QDomElement &element)
{
    CDDDbDIAGINSTImpl::load(element);
}

} // namespace cdd
} // namespace vector
