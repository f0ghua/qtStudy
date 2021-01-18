
#include "CDDDbJOBCNRREF.h"

namespace vector {
namespace cdd {

CDDDbJOBCNRREF::CDDDbJOBCNRREF()
{
}

CDDDbJOBCNRREF::~CDDDbJOBCNRREF()
{
}

void CDDDbJOBCNRREF::load(const QDomElement &element)
{
    CDDDbJOBCNRREFImpl::load(element);
}

} // namespace cdd
} // namespace vector
