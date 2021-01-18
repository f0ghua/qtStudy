#include "CDDDbDESC.h"
#include "CDDDbDIAGINST.h"
#include "CDDDbDIAGINSTREF.h"
#include "CDDDbNAME.h"
#include "CDDDbQUAL.h"

#include "CDDDbDIAGCLASS.h"

namespace vector {
namespace cdd {

CDDDbDIAGCLASS::CDDDbDIAGCLASS()
{
}

CDDDbDIAGCLASS::~CDDDbDIAGCLASS()
{
}

void CDDDbDIAGCLASS::load(const QDomElement &element)
{
    CDDDbDIAGCLASSImpl::load(element);
}

} // namespace cdd
} // namespace vector
