#include "CDDDbNAME.h"
#include "CDDDbQUAL.h"
#include "CDDDbSTRUCTURE.h"

#include "CDDDbDID.h"

namespace vector {
namespace cdd {

CDDDbDID::CDDDbDID()
{
}

CDDDbDID::~CDDDbDID()
{
}

void CDDDbDID::load(const QDomElement &element)
{
    CDDDbDIDImpl::load(element);
}

} // namespace cdd
} // namespace vector
