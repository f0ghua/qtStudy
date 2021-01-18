
#include "CDDDbENUM.h"

namespace vector {
namespace cdd {

CDDDbENUM::CDDDbENUM()
{
}

CDDDbENUM::~CDDDbENUM()
{
}

void CDDDbENUM::load(const QDomElement &element)
{
    CDDDbENUMImpl::load(element);
}

} // namespace cdd
} // namespace vector
