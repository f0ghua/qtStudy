
#include "CDDDbFCImpl.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbFCImpl::CDDDbFCImpl()
{
}

CDDDbFCImpl::~CDDDbFCImpl()
{
}

void CDDDbFCImpl::load(const QDomElement &element)
{
    m_b = element.attribute("b");
    m_fs = element.attribute("fs");

    m_text = element.text();
}

} // namespace cdd
} // namespace vector
