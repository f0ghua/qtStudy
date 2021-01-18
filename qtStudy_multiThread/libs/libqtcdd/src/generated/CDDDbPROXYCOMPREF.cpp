
#include "CDDDbPROXYCOMPREF.h"

namespace vector {
namespace cdd {

CDDDbPROXYCOMPREF::CDDDbPROXYCOMPREF()
{
}

CDDDbPROXYCOMPREF::~CDDDbPROXYCOMPREF()
{
}

void CDDDbPROXYCOMPREF::load(const QDomElement &element)
{
    CDDDbPROXYCOMPREFImpl::load(element);
}

} // namespace cdd
} // namespace vector
