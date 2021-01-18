
#include "CDDDbLABELImpl.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbLABELImpl::CDDDbLABELImpl()
{
}

CDDDbLABELImpl::~CDDDbLABELImpl()
{
}

void CDDDbLABELImpl::load(const QDomElement &element)
{
    m_text = element.text();
}

} // namespace cdd
} // namespace vector
