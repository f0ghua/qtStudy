#include "CDDDbNAME.h"
#include "CDDDbNEGRESCODEPROXIES.h"
#include "CDDDbQUAL.h"

#include "CDDDbSPECDATAOBJ.h"

namespace vector {
namespace cdd {

CDDDbSPECDATAOBJ::CDDDbSPECDATAOBJ()
{
}

CDDDbSPECDATAOBJ::~CDDDbSPECDATAOBJ()
{
}

void CDDDbSPECDATAOBJ::load(const QDomElement &element)
{
    CDDDbSPECDATAOBJImpl::load(element);
}

} // namespace cdd
} // namespace vector
