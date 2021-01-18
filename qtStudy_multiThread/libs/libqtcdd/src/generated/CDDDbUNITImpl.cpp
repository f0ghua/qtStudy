
#include "CDDDbUNITImpl.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbUNITImpl::CDDDbUNITImpl()
{
}

CDDDbUNITImpl::~CDDDbUNITImpl()
{
}

void CDDDbUNITImpl::load(const QDomElement &element)
{
    m_text = element.text();
}

} // namespace cdd
} // namespace vector
