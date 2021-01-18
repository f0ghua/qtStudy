
#include "CDDDbLASTNAME.h"

namespace vector {
namespace cdd {

CDDDbLASTNAME::CDDDbLASTNAME()
{
}

CDDDbLASTNAME::~CDDDbLASTNAME()
{
}

void CDDDbLASTNAME::load(const QDomElement &element)
{
    CDDDbLASTNAMEImpl::load(element);
}

} // namespace cdd
} // namespace vector
