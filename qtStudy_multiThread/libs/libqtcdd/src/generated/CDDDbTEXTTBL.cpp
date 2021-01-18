#include "CDDDbCVALUETYPE.h"
#include "CDDDbDESC.h"
#include "CDDDbENUM.h"
#include "CDDDbEXCL.h"
#include "CDDDbNAME.h"
#include "CDDDbPVALUETYPE.h"
#include "CDDDbQUAL.h"
#include "CDDDbTEXTMAP.h"

#include "CDDDbTEXTTBL.h"

namespace vector {
namespace cdd {

CDDDbTEXTTBL::CDDDbTEXTTBL()
{
}

CDDDbTEXTTBL::~CDDDbTEXTTBL()
{
}

void CDDDbTEXTTBL::load(const QDomElement &element)
{
    CDDDbTEXTTBLImpl::load(element);
}

} // namespace cdd
} // namespace vector
