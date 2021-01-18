
#include "CDDDbDIDREF.h"

namespace vector {
namespace cdd {

CDDDbDIDREF::CDDDbDIDREF()
{
}

CDDDbDIDREF::~CDDDbDIDREF()
{
}

void CDDDbDIDREF::load(const QDomElement &element)
{
    CDDDbDIDREFImpl::load(element);
}

} // namespace cdd
} // namespace vector
