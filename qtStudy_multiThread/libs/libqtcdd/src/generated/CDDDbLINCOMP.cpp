#include "CDDDbCOMP.h"
#include "CDDDbCVALUETYPE.h"
#include "CDDDbEXCL.h"
#include "CDDDbNAME.h"
#include "CDDDbPVALUETYPE.h"
#include "CDDDbQUAL.h"

#include "CDDDbLINCOMP.h"

namespace vector {
namespace cdd {

CDDDbLINCOMP::CDDDbLINCOMP()
{
}

CDDDbLINCOMP::~CDDDbLINCOMP()
{
}

void CDDDbLINCOMP::load(const QDomElement &element)
{
    CDDDbLINCOMPImpl::load(element);
}

} // namespace cdd
} // namespace vector
