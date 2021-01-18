
#include "CDDDbENUMRECORDITEM.h"

namespace vector {
namespace cdd {

CDDDbENUMRECORDITEM::CDDDbENUMRECORDITEM()
{
}

CDDDbENUMRECORDITEM::~CDDDbENUMRECORDITEM()
{
}

void CDDDbENUMRECORDITEM::load(const QDomElement &element)
{
    CDDDbENUMRECORDITEMImpl::load(element);
}

} // namespace cdd
} // namespace vector
