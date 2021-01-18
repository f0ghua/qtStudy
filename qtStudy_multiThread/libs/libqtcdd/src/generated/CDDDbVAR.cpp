#include "CDDDbDIAGCLASS.h"
#include "CDDDbDIAGINST.h"
#include "CDDDbDIAGINSTREF.h"
#include "CDDDbDIDREFS.h"
#include "CDDDbJOBCNR.h"
#include "CDDDbJOBCNRREF.h"
#include "CDDDbNAME.h"
#include "CDDDbQUAL.h"

#include "CDDDbVAR.h"

namespace vector {
namespace cdd {

CDDDbVAR::CDDDbVAR()
{
}

CDDDbVAR::~CDDDbVAR()
{
}

void CDDDbVAR::load(const QDomElement &element)
{
    CDDDbVARImpl::load(element);
}

} // namespace cdd
} // namespace vector
