#include "CDDDbDESC.h"
#include "CDDDbNAME.h"
#include "CDDDbQUAL.h"

#include "CDDDbSTATICCOMP.h"

namespace vector {
namespace cdd {

CDDDbSTATICCOMP::CDDDbSTATICCOMP()
{
}

CDDDbSTATICCOMP::~CDDDbSTATICCOMP()
{
}

void CDDDbSTATICCOMP::load(const QDomElement &element)
{
    CDDDbSTATICCOMPImpl::load(element);
}

} // namespace cdd
} // namespace vector
