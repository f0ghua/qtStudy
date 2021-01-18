#include "CDDDbTUV.h"

#include "CDDDbDESC.h"

namespace vector {
namespace cdd {

CDDDbDESC::CDDDbDESC()
{
}

CDDDbDESC::~CDDDbDESC()
{
}

void CDDDbDESC::load(const QDomElement &element)
{
    CDDDbDESCImpl::load(element);
}

} // namespace cdd
} // namespace vector
