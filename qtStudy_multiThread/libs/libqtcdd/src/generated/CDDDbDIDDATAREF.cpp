#include "CDDDbNAME.h"
#include "CDDDbQUAL.h"

#include "CDDDbDIDDATAREF.h"

namespace vector {
namespace cdd {

CDDDbDIDDATAREF::CDDDbDIDDATAREF()
{
}

CDDDbDIDDATAREF::~CDDDbDIDDATAREF()
{
}

void CDDDbDIDDATAREF::load(const QDomElement &element)
{
    CDDDbDIDDATAREFImpl::load(element);
}

} // namespace cdd
} // namespace vector
