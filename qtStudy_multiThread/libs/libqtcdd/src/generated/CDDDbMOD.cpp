
#include "CDDDbMOD.h"

namespace vector {
namespace cdd {

CDDDbMOD::CDDDbMOD()
{
}

CDDDbMOD::~CDDDbMOD()
{
}

void CDDDbMOD::load(const QDomElement &element)
{
    CDDDbMODImpl::load(element);
}

} // namespace cdd
} // namespace vector
