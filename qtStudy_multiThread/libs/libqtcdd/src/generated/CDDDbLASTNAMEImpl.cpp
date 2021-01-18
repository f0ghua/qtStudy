
#include "CDDDbLASTNAMEImpl.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbLASTNAMEImpl::CDDDbLASTNAMEImpl()
{
}

CDDDbLASTNAMEImpl::~CDDDbLASTNAMEImpl()
{
}

void CDDDbLASTNAMEImpl::load(const QDomElement &element)
{
    m_text = element.text();
}

} // namespace cdd
} // namespace vector
