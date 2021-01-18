#include "CDDDbCASE.h"
#include "CDDDbCVALUETYPE.h"
#include "CDDDbNAME.h"
#include "CDDDbPVALUETYPE.h"
#include "CDDDbQUAL.h"
#include "CDDDbSTRUCTURE.h"

#include "CDDDbMUXDT.h"

namespace vector {
namespace cdd {

CDDDbMUXDT::CDDDbMUXDT()
{
}

CDDDbMUXDT::~CDDDbMUXDT()
{
}

void CDDDbMUXDT::load(const QDomElement &element)
{
    CDDDbMUXDTImpl::load(element);
}

} // namespace cdd
} // namespace vector
