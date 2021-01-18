
#include "CDDDbQUALImpl.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbQUALImpl::CDDDbQUALImpl()
{
}

CDDDbQUALImpl::~CDDDbQUALImpl()
{
}

void CDDDbQUALImpl::load(const QDomElement &element)
{
    m_text = element.text();
}

} // namespace cdd
} // namespace vector
