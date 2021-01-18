
#include "CDDDbVCKMGR.h"

namespace vector {
namespace cdd {

CDDDbVCKMGR::CDDDbVCKMGR()
{
}

CDDDbVCKMGR::~CDDDbVCKMGR()
{
}

void CDDDbVCKMGR::load(const QDomElement &element)
{
    CDDDbVCKMGRImpl::load(element);
}

} // namespace cdd
} // namespace vector
