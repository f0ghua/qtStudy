
#include "CDDDbSPECOWNER.h"

namespace vector {
namespace cdd {

CDDDbSPECOWNER::CDDDbSPECOWNER()
{
}

CDDDbSPECOWNER::~CDDDbSPECOWNER()
{
}

void CDDDbSPECOWNER::load(const QDomElement &element)
{
    CDDDbSPECOWNERImpl::load(element);
}

} // namespace cdd
} // namespace vector
