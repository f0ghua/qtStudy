#include "CDDDbDATAOBJ.h"

#include "CDDDbSTRUCTURE.h"

namespace vector {
namespace cdd {

CDDDbSTRUCTURE::CDDDbSTRUCTURE()
{
}

CDDDbSTRUCTURE::~CDDDbSTRUCTURE()
{
}

void CDDDbSTRUCTURE::load(const QDomElement &element)
{
    CDDDbSTRUCTUREImpl::load(element);
}

} // namespace cdd
} // namespace vector
