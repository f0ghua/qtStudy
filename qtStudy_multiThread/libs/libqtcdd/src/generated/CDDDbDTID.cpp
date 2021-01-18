
#include "CDDDbDTID.h"

namespace vector {
namespace cdd {

CDDDbDTID::CDDDbDTID()
{
}

CDDDbDTID::~CDDDbDTID()
{
}

void CDDDbDTID::load(const QDomElement &element)
{
    CDDDbDTIDImpl::load(element);
}

} // namespace cdd
} // namespace vector
