
#include "CDDDbCOMMONSTRING.h"

namespace vector {
namespace cdd {

CDDDbCOMMONSTRING::CDDDbCOMMONSTRING()
{
}

CDDDbCOMMONSTRING::~CDDDbCOMMONSTRING()
{
}

void CDDDbCOMMONSTRING::load(const QDomElement &element)
{
    CDDDbCOMMONSTRINGImpl::load(element);
}

} // namespace cdd
} // namespace vector
