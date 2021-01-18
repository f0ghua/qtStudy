#include "CDDDbNAME.h"
#include "CDDDbQUAL.h"

#include "CDDDbSGNDEF.h"

namespace vector {
namespace cdd {

CDDDbSGNDEF::CDDDbSGNDEF()
{
}

CDDDbSGNDEF::~CDDDbSGNDEF()
{
}

void CDDDbSGNDEF::load(const QDomElement &element)
{
    CDDDbSGNDEFImpl::load(element);
}

} // namespace cdd
} // namespace vector
