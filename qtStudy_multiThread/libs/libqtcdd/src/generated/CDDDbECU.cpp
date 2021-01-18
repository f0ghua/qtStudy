#include "CDDDbCSTR.h"
#include "CDDDbDESC.h"
#include "CDDDbENUM.h"
#include "CDDDbFAULTMEMORY.h"
#include "CDDDbNAME.h"
#include "CDDDbQUAL.h"
#include "CDDDbUNS.h"
#include "CDDDbVAR.h"

#include "CDDDbECU.h"

namespace vector {
namespace cdd {

CDDDbECU::CDDDbECU()
{
}

CDDDbECU::~CDDDbECU()
{
}

void CDDDbECU::load(const QDomElement &element)
{
    CDDDbECUImpl::load(element);
}

} // namespace cdd
} // namespace vector
