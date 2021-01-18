#include "CDDDbDESC.h"
#include "CDDDbNAME.h"
#include "CDDDbQUAL.h"

#include "CDDDbSTATE.h"

namespace vector {
namespace cdd {

CDDDbSTATE::CDDDbSTATE()
{
}

CDDDbSTATE::~CDDDbSTATE()
{
}

void CDDDbSTATE::load(const QDomElement &element)
{
    CDDDbSTATEImpl::load(element);
}

} // namespace cdd
} // namespace vector
