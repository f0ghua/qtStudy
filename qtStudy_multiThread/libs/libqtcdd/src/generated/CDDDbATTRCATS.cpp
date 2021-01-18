#include "CDDDbATTRCAT.h"

#include "CDDDbATTRCATS.h"

namespace vector {
namespace cdd {

CDDDbATTRCATS::CDDDbATTRCATS()
{
}

CDDDbATTRCATS::~CDDDbATTRCATS()
{
}

void CDDDbATTRCATS::load(const QDomElement &element)
{
    CDDDbATTRCATSImpl::load(element);
}

} // namespace cdd
} // namespace vector
