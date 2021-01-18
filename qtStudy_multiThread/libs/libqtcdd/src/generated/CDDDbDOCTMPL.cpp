#include "CDDDbLABEL.h"
#include "CDDDbNAME.h"
#include "CDDDbQUAL.h"

#include "CDDDbDOCTMPL.h"

namespace vector {
namespace cdd {

CDDDbDOCTMPL::CDDDbDOCTMPL()
{
}

CDDDbDOCTMPL::~CDDDbDOCTMPL()
{
}

void CDDDbDOCTMPL::load(const QDomElement &element)
{
    CDDDbDOCTMPLImpl::load(element);
}

} // namespace cdd
} // namespace vector
