#include "CDDDbADDINFO.h"
#include "CDDDbTEXT.h"

#include "CDDDbTEXTMAP.h"

namespace vector {
namespace cdd {

CDDDbTEXTMAP::CDDDbTEXTMAP()
{
}

CDDDbTEXTMAP::~CDDDbTEXTMAP()
{
}

void CDDDbTEXTMAP::load(const QDomElement &element)
{
    CDDDbTEXTMAPImpl::load(element);
}

} // namespace cdd
} // namespace vector
