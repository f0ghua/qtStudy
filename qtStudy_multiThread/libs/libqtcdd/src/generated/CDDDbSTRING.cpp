#include "CDDDbTUV.h"

#include "CDDDbSTRING.h"

namespace vector {
namespace cdd {

CDDDbSTRING::CDDDbSTRING()
    : CDDDbNAME()
{
}

CDDDbSTRING::~CDDDbSTRING()
{
}

void CDDDbSTRING::load(const QDomElement &element)
{
    CDDDbNAME::load(element);
}

} // namespace cdd
} // namespace vector
