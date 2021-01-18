
#include "CDDDbDTIDImpl.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbDTIDImpl::CDDDbDTIDImpl()
{
}

CDDDbDTIDImpl::~CDDDbDTIDImpl()
{
}

void CDDDbDTIDImpl::load(const QDomElement &element)
{
    m_text = element.text();
}

} // namespace cdd
} // namespace vector
