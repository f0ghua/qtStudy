
#include "CDDDbDIAGINSTREF.h"

namespace vector {
namespace cdd {

CDDDbDIAGINSTREF::CDDDbDIAGINSTREF()
{
}

CDDDbDIAGINSTREF::~CDDDbDIAGINSTREF()
{
}

void CDDDbDIAGINSTREF::load(const QDomElement &element)
{
    CDDDbDIAGINSTREFImpl::load(element);
}

} // namespace cdd
} // namespace vector
