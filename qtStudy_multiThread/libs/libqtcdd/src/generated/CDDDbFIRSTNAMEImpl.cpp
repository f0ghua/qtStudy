
#include "CDDDbFIRSTNAMEImpl.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbFIRSTNAMEImpl::CDDDbFIRSTNAMEImpl()
{
}

CDDDbFIRSTNAMEImpl::~CDDDbFIRSTNAMEImpl()
{
}

void CDDDbFIRSTNAMEImpl::load(const QDomElement &element)
{
    m_text = element.text();
}

} // namespace cdd
} // namespace vector
