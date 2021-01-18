
#include "CDDDbCOMPANYImpl.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbCOMPANYImpl::CDDDbCOMPANYImpl()
{
}

CDDDbCOMPANYImpl::~CDDDbCOMPANYImpl()
{
}

void CDDDbCOMPANYImpl::load(const QDomElement &element)
{
    m_text = element.text();
}

} // namespace cdd
} // namespace vector
