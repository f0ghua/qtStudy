
#include "CDDDbSHORTNAMEImpl.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbSHORTNAMEImpl::CDDDbSHORTNAMEImpl()
{
}

CDDDbSHORTNAMEImpl::~CDDDbSHORTNAMEImpl()
{
}

void CDDDbSHORTNAMEImpl::load(const QDomElement &element)
{
    m_text = element.text();
}

} // namespace cdd
} // namespace vector
