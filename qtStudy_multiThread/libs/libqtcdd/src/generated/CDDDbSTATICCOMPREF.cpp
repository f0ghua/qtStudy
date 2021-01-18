
#include "CDDDbSTATICCOMPREF.h"

namespace vector {
namespace cdd {

CDDDbSTATICCOMPREF::CDDDbSTATICCOMPREF()
{
}

CDDDbSTATICCOMPREF::~CDDDbSTATICCOMPREF()
{
}

void CDDDbSTATICCOMPREF::load(const QDomElement &element)
{
    CDDDbSTATICCOMPREFImpl::load(element);
}

} // namespace cdd
} // namespace vector
