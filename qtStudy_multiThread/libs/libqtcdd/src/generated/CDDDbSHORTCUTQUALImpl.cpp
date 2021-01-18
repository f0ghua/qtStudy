
#include "CDDDbSHORTCUTQUALImpl.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbSHORTCUTQUALImpl::CDDDbSHORTCUTQUALImpl()
{
}

CDDDbSHORTCUTQUALImpl::~CDDDbSHORTCUTQUALImpl()
{
}

void CDDDbSHORTCUTQUALImpl::load(const QDomElement &element)
{
    m_text = element.text();
}

} // namespace cdd
} // namespace vector
