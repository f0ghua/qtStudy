#include "CDDDbAUTHOR.h"

#include "CDDDbAUTHORS.h"

namespace vector {
namespace cdd {

CDDDbAUTHORS::CDDDbAUTHORS()
{
}

CDDDbAUTHORS::~CDDDbAUTHORS()
{
}

void CDDDbAUTHORS::load(const QDomElement &element)
{
    CDDDbAUTHORSImpl::load(element);
}

} // namespace cdd
} // namespace vector
