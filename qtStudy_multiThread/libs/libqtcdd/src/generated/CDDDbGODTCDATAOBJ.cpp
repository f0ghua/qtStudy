#include "CDDDbNAME.h"
#include "CDDDbQUAL.h"
#include "CDDDbTEXTTBL.h"

#include "CDDDbGODTCDATAOBJ.h"

namespace vector {
namespace cdd {

CDDDbGODTCDATAOBJ::CDDDbGODTCDATAOBJ()
{
}

CDDDbGODTCDATAOBJ::~CDDDbGODTCDATAOBJ()
{
}

void CDDDbGODTCDATAOBJ::load(const QDomElement &element)
{
    CDDDbGODTCDATAOBJImpl::load(element);
}

} // namespace cdd
} // namespace vector
